/*=============================================================================
**                             AYRTON TECHNOLOGY
**                      Proprietary - Copyright (C) 2007
**-----------------------------------------------------------------------------
** Customer          : Internal
** Project           : O4A (06-01-BEE-055)
**-----------------------------------------------------------------------------
** Supported MCUs    : Freescale MC9S12XEP100
**-----------------------------------------------------------------------------
** File name         : tpl_machine_HCS12X_asm.c
**
** Module name       : tpl_machine_HCS12X
**
**
** Summary: functions of the OS specifics for the MCU S12X that can only be 
**          implemented in assembly
**              .
**             / \     works only in near context,   
**            / | \    because parameters are not passed in the same way in far context 
**           /__o__\   
**
**= History ===================================================================
** 00.01  J.Monsimier	04/11/07 
** - creation
** 00.02  J.Monsimier 05/21/07
** - modifications for the S12X MCU, 
**    the S12X is different from the S12 by the size of the CCR register
=============================================================================*/

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "tpl_machine.h"

/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                             */
/******************************************************************************/

/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"

#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
    __asm PSHY              ;/* save the current registers on stack */            
    __asm PSHX              ;                                                    
    __asm PSHD              ;                                                    
    __asm PSHCW             ;/* different from s12, CCR is 2 bytes */
    __asm LEAS  10,SP       ;/*replace SP   */
    __asm PULX              ;
    __asm LEAS  -6,SP       ;
    __asm LEAS  -6,SP       ;
    __asm CPX   #0          ;/* if(old_context*  == NULL) */                      
    __asm BEQ   nosave      ;/* do not save the old_context */
    __asm LDX   0,X         ;/* charge X avec l'adresse pointé par X+0, soit charge x avec old_context->ic */                                                                                                                           
    __asm PULY              ;/* pull the CCR in Y */                              
    __asm STY   2,X+        ;/* copy the CCR in old_context */                    
    __asm PULY              ;/* pull D in Y */                                    
    __asm STY   2,X+        ;/* copy D in old_context */                          
    __asm PULY              ;/* pull X in Y */                                    
    __asm STY   2,X+        ;/* copy X in old_context */                          
    __asm PULY              ;/* pull Y in Y */                                    
    __asm STY   2,X+        ;/* copy Y in old_context */                                                           
    __asm TFR   Y,D         ;/* copy Y in D (save new_context*) */
    __asm PULY              ;/* pull the return PC */
    __asm STY   3,X+        ;/* save the return PC in old_context */
    __asm TFR   SP,Y        ;
    __asm STY   2,X+        ;/* save the SP in old_context */
    __asm nosave:           ;/* here we go, the old context is saved */
    __asm TFR   D,X         ;/* copy D in Y (new_context*) */                                                     
    __asm LDX   0,X         ;                        
    __asm LEAX  11,X        ;/* point to the SP field in new_context struct */    
    __asm LDY   3,X-        ;/* copy the SP in the old_context */                      
    __asm TYS               ;/* adjust the SP from the new_context */             
    __asm LDY   2,X-        ;/* copy PC in Y */                                  
    __asm PSHY              ;/* push pC */                                       
    __asm LDY   2,X-        ;/* copy Y register in Y */                           
    __asm PSHY              ;/* push Y */                                         
    __asm LDY   2,X-        ;/* copy X register in Y */                           
    __asm PSHY              ;/* push X */                                         
    __asm LDY   2,X-        ;/* copy D register in Y */                           
    __asm PSHY              ;/* push D */                                         
    __asm LDY   0,X         ;/* copy CCR in Y */                                   
    __asm PSHY              ;/* push CCR */                                        
    __asm RTI               ;/* pull all register and PC, return */                 
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context from It
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"

#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context)
{
    __asm LEAS  2,SP        ;
    __asm PULX              ;/* get the old_context* */
    __asm CPX   #0          ;/* if(old_context*  == NULL) */                      
    __asm BEQ   nosave      ;/* don t save the old_context */
    __asm LDX   0,X         ;/* charge X avec l'adresse pointé par X+0, soit charge x avec old_context->ic */                                                                                                                           
    __asm LEAS  13,SP       ;/* replace the SP just after the interrupt instruction*/ 
    __asm PSHD              ;/* save D register (new_context*) */
    __asm LEAS  2,SP        ;
    __asm PULY              ;/* pull the CCR in A */                              
    __asm STY   2,X+        ;/* copy the CCR in old_context */                    
    __asm PULY              ;/* pull D in Y */                                    
    __asm STY   2,X+        ;/* copy D in old_context */                          
    __asm PULY              ;/* pull X in Y */                                    
    __asm STY   2,X+        ;/* copy X in old_context */                          
    __asm PULY              ;/* pull Y in Y */                                    
    __asm STY   2,X+        ;/* copy Y in old_context */                                                           
    __asm TFR   Y,D         ;/* copy Y in D (save new_context*) */
    __asm PULY              ;/* pull the return PC */
    __asm STY   3,X+        ;/* save the return PC in old_context */
    __asm TFR   SP,Y        ;
    __asm STY   2,X+        ;/* save the SP in old_context */
    __asm nosave:           ;/* here we go, the old context is saved */
    __asm LEAS  -6,SP       ;
    __asm LEAS  -6,SP       ;
    __asm PULX              ;
    __asm LEAS  6,SP        ;                                     
    __asm LDX   0,X         ;                        
    __asm LEAX  11,X        ;/* point to the SP field in new_context struct */    
    __asm LDY   3,X-        ;/* copy the SP in the old_context */                      
    __asm TYS               ;/* adjust the SP from the new_context */             
    __asm LDY   2,X-        ;/* copy PC in Y */                                  
    __asm PSHY              ;/* push pC */                                       
    __asm LDY   2,X-        ;/* copy Y register in Y */                           
    __asm PSHY              ;/* push Y */                                         
    __asm LDY   2,X-        ;/* copy X register in Y */                           
    __asm PSHY              ;/* push X */                                         
    __asm LDY   2,X-        ;/* copy D register in Y */                           
    __asm PSHY              ;/* push D */                                         
    __asm LDY   0,X         ;/* copy CCR in Y */ 
    __asm BSET  0,Y+,$10    ;/* set the I bit in the CCR to keep the interrupts disabled*/                                  
    __asm PSHY              ;/* push CCR */                                        
    __asm RTI               ;/* pull all register and PC, return */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_sleep(void)
** Description: wait when there is no task to be executed
** Parameter : None
** Return value: None
** Remarks: 
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
void tpl_sleep(void)
{
  while(1);
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/*******************************************************************************
** Function name: tpl_shutdown(void)
** Description: last function executed when leaving OS, disable interrupts and wait
** Parameter : None
** Return value: None
** Remarks: 
*******************************************************************************/  
#define OS_START_SEC_CODE
#include "Memmap.h"
void tpl_shutdown(void)
{
  __asm SEI                   ;/* set the I bit of CCR, inhibits interrupts */
  __asm shutdown_loop:        ;/* go in an infinit loop */
  __asm BRA shutdown_loop
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_get_task_lock(void)
** Description: inhibits interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
void tpl_get_task_lock(void)
{  
  __asm SEI     ;/* set the I bit of CCR, inhibits interrupts */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_release_task_lock(void)
** Description: re-allows interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
void tpl_release_task_lock(void)
{ 
  __asm CLI     ;/* clear the I bit of CCR, re-allows interrupts */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"
              
