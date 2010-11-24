/**
 * mini-HOWTO :
 * 0) see where are MMU tables, and its size
 *  In the file *.map, look for ".MMU_tables", the address is given
 *  at the same line and looks like 0xa001f000. The size is given at
 *  the end of the same line.
 * 1) get a memory dump file from this address
 *  Use BDI JTAG probe via telnet and type :
 *  dump <address> <size> <file_name>
 *  Choose the file name you want. Note that this require that
 *  you have a properly configured TFTP server and BDI's configuration
 *  point on it.
 * 2) launch decoder like this :
 *  ./decode_mmu_structs <number of processes> <number of page tables in a set> <base MMU tables address> < mmu_dump_file
 *  where :
 *   - number of processes is : number of tasks + number of ISRs (cat 2.) + 1
 *   - number of page tables in a set : in the file *.map look for MMU_page_table_count, the address given before the name gives the value required here
 *   - base MMU table address : same address as given for the dump (in hexadecimal)
 *  do not forget to give the file via stdin using the "<" operator at the end of command line
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * type must be 1. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int unused1 : 2;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int unused2 : 1;
  unsigned int coarse_page_table_table_address : 22;
} MMU_coarse_page_table_descriptor;

/**
 * type must be 2. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int must_be_zero1 : 1;
  unsigned int access_permission : 2;
  unsigned int must_be_zero2 : 8;
  unsigned int section_base_address : 12;
} MMU_section_descriptor;

/**
 * type must be 3. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int unused : 2;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int must_be_zero : 3;
  unsigned int fine_page_table_base_address : 20;
} MMU_fine_page_table_descriptor;

typedef union {
  unsigned int raw;
  MMU_coarse_page_table_descriptor coarse;
  MMU_section_descriptor section;
  MMU_fine_page_table_descriptor fine;
} MMU_first_level_descriptor;

typedef MMU_first_level_descriptor MMU_translation_table[4096];

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission_0 : 2;
  unsigned int access_permission_1 : 2;
  unsigned int access_permission_2 : 2;
  unsigned int access_permission_3 : 2;
  unsigned int unused : 4;
  unsigned int page_base_address : 16;
} MMU_large_page_descriptor;

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission_0 : 2;
  unsigned int access_permission_1 : 2;
  unsigned int access_permission_2 : 2;
  unsigned int access_permission_3 : 2;
  unsigned int page_base_address : 20;
} MMU_small_page_descriptor;

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission : 2;
  unsigned int unused : 4;
  unsigned int page_base_address : 22;
} MMU_tiny_page_descriptor;

typedef union {
  unsigned int raw;
  MMU_large_page_descriptor large_page;
  MMU_small_page_descriptor small_page;
  MMU_tiny_page_descriptor tiny_page;
} MMU_second_level_descriptor;

typedef MMU_second_level_descriptor MMU_coarse_page_table[256];

typedef MMU_second_level_descriptor MMU_fine_page_table[1024];

#define AP_DECODE_STRING(AP) ((AP) == 1 ? "system only" : (AP) == 2 ? "read only" : (AP) == 3 ? "read/write" : "error")

unsigned char *MMU_data_buffer;
unsigned int MMU_data_base_address;
int number_of_processes;
int number_of_page_tables;

unsigned int get_page_table_address (int process, int page_table_number)
{
  unsigned int ttables_size;
  unsigned int page_table_offset;

  ttables_size = number_of_processes * 4096 * 4;
  page_table_offset = 4 * 1024 * (process * number_of_page_tables + page_table_number);

  return MMU_data_base_address + ttables_size + page_table_offset;
}

#define PAGE_START(index) (0xA0000000 + (page_table_number << 20) + (index << 10))
#define PAGE_END(index) (0xA0000000 + (page_table_number << 20) + ((index + 1) << 10))

void decode_page_table (int process, int page_table_number)
{
  MMU_second_level_descriptor *page_table;
  MMU_second_level_descriptor previous_entry;
  unsigned int ttables_size;
  unsigned int page_table_offset;
  unsigned int i;
  unsigned int area_start, area_end;
  unsigned int area_size;

  ttables_size = number_of_processes * 4096 * 4;
  page_table_offset = 4 * 1024 * (process * number_of_page_tables + page_table_number);
  page_table = (MMU_second_level_descriptor *)(MMU_data_buffer + ttables_size + page_table_offset);

  area_start = PAGE_START (0);
  area_end = PAGE_END(0);
  area_size = 1024;
  previous_entry = page_table[0];

  for (i = 1 ; i < 1023 ; i++)
  {
    if ((previous_entry.tiny_page.type == page_table[i].tiny_page.type) &&
        (previous_entry.tiny_page.access_permission == page_table[i].tiny_page.access_permission))
    {
      area_end = PAGE_END(i);
      area_size += 1024;
    }
    else
    {
      switch (previous_entry.tiny_page.type)
      {
        case 3:
          printf ("  [%4d KiB] 0x%08X -> 0x%08X : area with rights %s\n", area_size >> 10, area_start, area_end - 1, 
             AP_DECODE_STRING (previous_entry.tiny_page.access_permission));
          break;
        case 0:
          printf ("  [%4d KiB] 0x%08X -> 0x%08X : memory hole\n", area_size >> 10, area_start, area_end - 1);
          break;
        default:
          printf ("  error : page type = %d (related to memory area 0x%08X -> 0x%08X, page entry address : 0x%08X)\n", previous_entry.tiny_page.type, 
             area_start, area_end - 1,
             get_page_table_address (process, page_table_number) + 4 * (i - 1));
          exit (1);
      }
      /* restart new area */
      area_start = PAGE_START(i);
      area_end = PAGE_END(i);
      area_size = 1024;
    }
    previous_entry = page_table[i];
  }
  area_end = PAGE_END(1023);
  area_size += 1024;
  switch (previous_entry.tiny_page.type)
  {
    case 3:
      printf ("  [%-4d KiB] 0x%08X -> 0x%08X : area with rights %s\n", area_size >> 10, area_start, area_end - 1, 
        AP_DECODE_STRING (previous_entry.tiny_page.access_permission));
      break;
    case 0:
      printf ("  [%-4d KiB] 0x%08X -> 0x%08X : memory hole\n", area_size >> 10, area_start, area_end - 1);
      break;
    default:
      printf ("  error : page type = %d (related to memory area 0x%08X -> 0x%08X, page entry address : 0x%08X)\n", previous_entry.tiny_page.type, 
         area_start, area_end - 1,
         get_page_table_address (process, page_table_number) + 4 * (i - 1));
      exit (1);
  }
}

#define SECTION_START(index) ((index) << 20)
#define SECTION_END(index) (((index) + 1) << 20)

#define PAGE_INDEX(address) (((address) >> 20) - 0xA00)

void decode_mem_conf (int process)
{
  int i;
  MMU_first_level_descriptor *ttable;
  MMU_first_level_descriptor previous_section;
  unsigned int area_start, area_end;
  unsigned int area_size;
  unsigned int expected_pt_addr, read_pt_addr;
  unsigned int current_page_index;

  ttable = (MMU_first_level_descriptor*)(MMU_data_buffer + process * 4096 * 4);
  area_start = SECTION_START (0);
  area_end = SECTION_END (0);
  area_size = 1024 * 1024;
  previous_section = ttable[0];
  for (i = 1 ; i < 4095 ; i++)
  {
    if ((previous_section.section.type == ttable[i].section.type))
    {
      area_end = SECTION_END(i);
      area_size += 1024 * 1024;
    }
    else
    {
      /* show previous area */
      switch (previous_section.section.type)
      {
        case 0:
          printf ("[%4d MiB] 0x%08X -> 0x%08X : memory hole\n", area_size >> 20, area_start, area_end - 1);
          break;
        case 1:
          printf ("[%4d MiB] 0x%08X -> 0x%08X : ERROR : coarse page table\n", area_size >> 20, area_start, area_end - 1);
          break;
        case 2:
          printf ("[%4d MiB] 0x%08X -> 0x%08X : section with rights %s\n", area_size >> 20, area_start, area_end - 1, 
             AP_DECODE_STRING (previous_section.section.access_permission));
          break;
        case 3:
          expected_pt_addr = get_page_table_address (process, (i - 1) - 0xA00);
          read_pt_addr = previous_section.fine.fine_page_table_base_address << 12;
          if (expected_pt_addr != read_pt_addr)
          {
            printf ("translation table does not give the right page table address (related memory area is 0x%08X -> 0x%08X)\n", area_start, area_end - 1);
            printf ("expected 0x%08X, read 0x%08X\n", expected_pt_addr, read_pt_addr);
            exit (1);
          }
          current_page_index = PAGE_INDEX(area_start);
          do
          {
            printf (" ** page table @0x%08X\n", get_page_table_address (process, current_page_index));
            decode_page_table (process, current_page_index);
            current_page_index++;
          }
          while (current_page_index < PAGE_INDEX (area_end));
        break;
        default:
          printf ("error : section type is invalid : type = %d, indice = %d\n", previous_section.section.type, i);
          exit (1);
      }
      /* jump to next area */
      area_start = SECTION_START(i);
      area_end = SECTION_END(i);
      area_size = 1024 * 1024;
    }
    previous_section = ttable[i];
  }
  area_end = SECTION_END(4095);
  area_size += 1024 * 1024;
  switch (previous_section.section.type)
  {
    case 0:
      printf ("[%04d MiB] 0x%08X -> 0x%08X : memory hole\n", area_size >> 20, area_start, area_end - 1);
      break;
    case 1:
      printf ("[%04d MiB] 0x%08X -> 0x%08X : ERROR : coarse page table\n", area_size >> 20, area_start, area_end - 1);
      break;
    case 2:
      printf ("[%04d MiB] 0x%08X -> 0x%08X : section with rights %s\n", area_size >> 20, area_start, area_end - 1, 
         AP_DECODE_STRING (previous_section.section.access_permission));
     break;
     case 3:
       if (get_page_table_address (process, i - 0xA00) != (ttable[i].fine.fine_page_table_base_address << 12))
       {
         printf ("translation table does not give the right page table address (related memory area is 0x%08X -> 0x%08X)\n", area_start, area_end - 1);
         printf ("expected 0x%08X, read 0x%08X\n", get_page_table_address (process, i - 0xA00), ttable[i].fine.fine_page_table_base_address << 12);
         exit (1);
       }
       current_page_index = PAGE_INDEX(area_start);
       do
       {
         decode_page_table (process, current_page_index);
         current_page_index++;
       }
       while (current_page_index < PAGE_INDEX (area_end));
      break;
      default:
        printf ("error : section type is invalid : type = %d, indice = %d\n", previous_section.section.type, i);
        exit (1);
    }
}

int main (int argc, char**argv)
{
  int i;

  if (argc != 4)
  {
    printf ("Bad number of parameters (%d)\n", argc);
    printf ("Usage : \n");
    printf ("%s <number_of_processes> <number_of_page_tables> <base_MMU_section_address> < mmu_data_dump_file\n", argv[0]);
    exit (1);
  }

  number_of_processes = strtoll (argv[1], NULL, 10);
  number_of_page_tables = strtoll (argv[2], NULL, 10);
  MMU_data_base_address = strtoll (argv[3], NULL, 16);

  assert (number_of_processes > 1);
  assert (number_of_page_tables > 1);
  assert ((MMU_data_base_address > 0xa0000000) && (MMU_data_base_address < 0xb0000000));

  MMU_data_buffer = (unsigned char *)malloc (number_of_processes * 4 * (4096 + 1024 * number_of_page_tables));

  while (!feof(stdin))
  {
    fread (MMU_data_buffer, 4 * (4096 + 1024 * number_of_page_tables), number_of_processes, stdin);
  }
  for (i = 0 ; i < number_of_processes ; i++)
  {
    printf ("--------------------------------------------\n");
    printf ("Begin of memory protection map for process %d\n", i);
    printf (" ** translation table @0x%08X\n", MMU_data_base_address + 4096 * 4 * i);
    decode_mem_conf (i);
  }

  free (MMU_data_buffer);

  return 0;
}
