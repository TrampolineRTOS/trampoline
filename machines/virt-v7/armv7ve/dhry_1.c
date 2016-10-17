/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *
 *  Version:    C, Version 2.1
 *
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Updated By: Anup Patel (anup@brainfault.org) for portablity.
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#include "dhry.h"
#include "dhry_port.h"

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];


#ifndef REG
        Boolean Reg = FALSE;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = TRUE;
#endif

TimeStamp  Begin_Time,
           End_Time,
           User_Time;
long       Microseconds,
           Dhrystones_Per_Second;

/* end of variables for time measurement */

/* forward declaration necessary */
void Proc_1 (REG Rec_Pointer Ptr_Val_Par);
void Proc_2 (One_Fifty   *Int_Par_Ref);
void Proc_3 (Rec_Pointer *Ptr_Ref_Par);
void Proc_4 ();
void Proc_5 ();
void Proc_6 (Enumeration  Enum_Val_Par, Enumeration *Enum_Ref_Par);
void Proc_7 (One_Fifty Int_1_Par_Val, One_Fifty Int_2_Par_Val, One_Fifty *Int_Par_Ref);
void Proc_8 (Arr_1_Dim Arr_1_Par_Ref, Arr_2_Dim Arr_2_Par_Ref, int Int_1_Par_Val, int Int_2_Par_Val);
Enumeration Func_1 (Capital_Letter Ch_1_Par_Val, Capital_Letter Ch_2_Par_Val);
Boolean Func_2 (Str_30 Str_1_Par_Ref, Str_30 Str_2_Par_Ref);


void dhry_main (int iterations)
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */
  Number_Of_Runs = iterations;
  Next_Ptr_Glob = (Rec_Pointer) dhry_malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) dhry_malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  dhry_strcpy (Ptr_Glob->variant.var_1.Str_Comp,
          "DHRYSTONE PROGRAM, SOME STRING");
  dhry_strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

  dhry_prints ("\n");
  dhry_prints ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  dhry_prints ("\n");
  if (Reg)
  {
    dhry_prints ("Program compiled with 'register' attribute\n");
    dhry_prints ("\n");
  }
  else
  {
    dhry_prints ("Program compiled without 'register' attribute\n");
    dhry_prints ("\n");
  }

  dhry_prints ("Execution starts, ");
  dhry_printi (Number_Of_Runs);
  dhry_prints (" runs through Dhrystone\n");

  /***************/
  /* Start timer */
  /***************/

  Begin_Time = dhry_timestamp();

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == TRUE */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    dhry_strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        dhry_strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = dhry_sdiv32(Int_2_Loc, Int_3_Loc);
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/

  End_Time = dhry_timestamp();

  dhry_prints ("Execution ends\n");
  dhry_prints ("\n");
  dhry_prints ("Final values of the variables used in the benchmark:\n");
  dhry_prints ("\n");
  dhry_prints ("Int_Glob:            ");
  dhry_printi (Int_Glob);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (5);
  dhry_prints ("\n");
  dhry_prints ("Bool_Glob:           ");
  dhry_printi (Bool_Glob);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (1);
  dhry_prints ("\n");
  dhry_prints ("Ch_1_Glob:           ");
  dhry_printc (Ch_1_Glob);
  dhry_prints ("\n");
  dhry_prints ("        should be:   A\n");
  dhry_prints ("Ch_2_Glob:           ");
  dhry_printc (Ch_2_Glob);
  dhry_prints ("\n");
  dhry_prints ("        should be:   B\n");
  dhry_prints ("Arr_1_Glob[8]:       ");
  dhry_printi (Arr_1_Glob[8]);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (7);
  dhry_prints ("\n");
  dhry_prints ("Arr_2_Glob[8][7]:    ");
  dhry_printi (Arr_2_Glob[8][7]);
  dhry_prints ("\n");
  dhry_prints ("        should be:   Number_Of_Runs + 10\n");
  dhry_prints ("Ptr_Glob->\n");
  dhry_prints ("  Ptr_Comp:          ");
  dhry_printi ((int) Ptr_Glob->Ptr_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   (implementation-dependent)\n");
  dhry_prints ("  Discr:             ");
  dhry_printi (Ptr_Glob->Discr);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (0);
  dhry_prints ("\n");
  dhry_prints ("  Enum_Comp:         ");
  dhry_printi (Ptr_Glob->variant.var_1.Enum_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (2);
  dhry_prints ("\n");
  dhry_prints ("  Int_Comp:          ");
  dhry_printi (Ptr_Glob->variant.var_1.Int_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (17);
  dhry_prints ("\n");
  dhry_prints ("  Str_Comp:          ");
  dhry_prints (Ptr_Glob->variant.var_1.Str_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  dhry_prints ("Next_Ptr_Glob->\n");
  dhry_prints ("  Ptr_Comp:          ");
  dhry_printi ((int) Next_Ptr_Glob->Ptr_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   (implementation-dependent), same as above\n");
  dhry_prints ("  Discr:             ");
  dhry_printi (Next_Ptr_Glob->Discr);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (0);
  dhry_prints ("\n");
  dhry_prints ("  Enum_Comp:         ");
  dhry_printi (Next_Ptr_Glob->variant.var_1.Enum_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (1);
  dhry_prints ("\n");
  dhry_prints ("  Int_Comp:          ");
  dhry_printi (Next_Ptr_Glob->variant.var_1.Int_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (18);
  dhry_prints ("\n");
  dhry_prints ("  Str_Comp:          ");
  dhry_prints (Next_Ptr_Glob->variant.var_1.Str_Comp);
  dhry_prints ("\n");
  dhry_prints ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  dhry_prints ("Int_1_Loc:           ");
  dhry_printi (Int_1_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (5);
  dhry_prints ("\n");
  dhry_prints ("Int_2_Loc:           ");
  dhry_printi (Int_2_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (13);
  dhry_prints ("\n");
  dhry_prints ("Int_3_Loc:           ");
  dhry_printi (Int_3_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (7);
  dhry_prints ("\n");
  dhry_prints ("Enum_Loc:            ");
  dhry_printi (Enum_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   ");
  dhry_printi (1);
  dhry_prints ("\n");
  dhry_prints ("Str_1_Loc:           ");
  dhry_prints (Str_1_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  dhry_prints ("Str_2_Loc:           ");
  dhry_prints (Str_2_Loc);
  dhry_prints ("\n");
  dhry_prints ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  dhry_prints ("\n");

  User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
    dhry_prints ("Measured time too small to obtain meaningful results\n");
    dhry_prints ("Please increase number of runs\n");
    dhry_prints ("\n");
  }
  else
  {
    Microseconds = dhry_to_microsecs(User_Time);
    Dhrystones_Per_Second = dhry_iter_per_sec(User_Time, Number_Of_Runs);
    dhry_prints ("Microseconds for one run through Dhrystone: ");
    dhry_printi (Microseconds);
    dhry_prints (" \n");
    dhry_prints ("Dhrystones per Second:                      ");
    dhry_printi (Dhrystones_Per_Second);
    dhry_prints (" \n");
    dhry_prints ("Dhrystones MIPS:                            ");
    dhry_printi (arm_sdiv32(Dhrystones_Per_Second, 1757));
    dhry_prints (" \n");
    dhry_prints ("\n");
  }

}


void Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


void Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* TRUE */
} /* Proc_2 */


void Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != NULL)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


void Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


void Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = FALSE;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif
