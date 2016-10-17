#ifndef _FDT_H
#define _FDT_H

#ifndef __ASSEMBLY__

struct fdt_header {
	u32 magic;			 /* magic word FDT_MAGIC */
	u32 totalsize;		 /* total size of DT block */
	u32 off_dt_struct;		 /* offset to structure */
	u32 off_dt_strings;	 /* offset to strings */
	u32 off_mem_rsvmap;	 /* offset to memory reserve map */
	u32 version;		 /* format version */
	u32 last_comp_version;	 /* last compatible version */

	/* version 2 fields below */
	u32 boot_cpuid_phys;	 /* Which physical CPU id we're
					    booting on */
	/* version 3 fields below */
	u32 size_dt_strings;	 /* size of the strings block */

	/* version 17 fields below */
	u32 size_dt_struct;	 /* size of the structure block */
};

struct fdt_reserve_entry {
	u64 address;
	u64 size;
};

struct fdt_node_header {
	u32 tag;
	char name[0];
};

struct fdt_property {
	u32 tag;
	u32 len;
	u32 nameoff;
	char data[0];
};

#endif /* !__ASSEMBLY */

#define FDT_MAGIC	0xd00dfeed	/* 4: version, 4: total size */
#define FDT_TAGSIZE	sizeof(u32)

#define FDT_BEGIN_NODE	0x1		/* Start node: full name */
#define FDT_END_NODE	0x2		/* End node */
#define FDT_PROP	0x3		/* Property: name off,
					   size, content */
#define FDT_NOP		0x4		/* nop */
#define FDT_END		0x9

#define FDT_V1_SIZE	(7*sizeof(u32))
#define FDT_V2_SIZE	(FDT_V1_SIZE + sizeof(u32))
#define FDT_V3_SIZE	(FDT_V2_SIZE + sizeof(u32))
#define FDT_V16_SIZE	FDT_V3_SIZE
#define FDT_V17_SIZE	(FDT_V16_SIZE + sizeof(u32))

/* adding a ramdisk needs 0x44 bytes in version 2008.10 */
#define FDT_RAMDISK_OVERHEAD	0x80
#endif /* _FDT_H */
