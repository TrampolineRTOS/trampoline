/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Link script                              */
/*                                                                            */
/*                                   msp430fr5994                             */
/*                                                                            */
/* <INIT_POLICY>                                                              */
/* - NO_INIT :          used for variables that are never cleared and never   */
/*                      initialized.                                          */
/* - CLEARED :          used for variables that are cleared to zero after     */
/*                      every reset.                                          */
/* - POWER_ON_CLEARED : used for variables that are cleared to zero only      */
/*                      after power on reset.                                 */
/* - INIT :             used for variables that are initialized with values   */
/*                      after every  reset.                                   */
/* - POWER_ON_INIT :    used for variables that are initialized with values   */
/*                      only after power on reset.                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Peripheral registers definition    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* ============================================================================ */
/* Copyright (c) 2019, Texas Instruments Incorporated                           */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/* This file supports MSP430FR5994 devices. */

/* 1.208 */

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/


/*****************************************************************************
 ADC12_B
*****************************************************************************/
PROVIDE(ADC12CTL0          = 0x0800);
PROVIDE(ADC12CTL0_L        = 0x0800);
PROVIDE(ADC12CTL0_H        = 0x0801);
PROVIDE(ADC12CTL1          = 0x0802);
PROVIDE(ADC12CTL1_L        = 0x0802);
PROVIDE(ADC12CTL1_H        = 0x0803);
PROVIDE(ADC12CTL2          = 0x0804);
PROVIDE(ADC12CTL2_L        = 0x0804);
PROVIDE(ADC12CTL2_H        = 0x0805);
PROVIDE(ADC12CTL3          = 0x0806);
PROVIDE(ADC12CTL3_L        = 0x0806);
PROVIDE(ADC12CTL3_H        = 0x0807);
PROVIDE(ADC12LO            = 0x0808);
PROVIDE(ADC12LO_L          = 0x0808);
PROVIDE(ADC12LO_H          = 0x0809);
PROVIDE(ADC12HI            = 0x080A);
PROVIDE(ADC12HI_L          = 0x080A);
PROVIDE(ADC12HI_H          = 0x080B);
PROVIDE(ADC12IFGR0         = 0x080C);
PROVIDE(ADC12IFGR0_L       = 0x080C);
PROVIDE(ADC12IFGR0_H       = 0x080D);
PROVIDE(ADC12IFGR1         = 0x080E);
PROVIDE(ADC12IFGR1_L       = 0x080E);
PROVIDE(ADC12IFGR1_H       = 0x080F);
PROVIDE(ADC12IFGR2         = 0x0810);
PROVIDE(ADC12IFGR2_L       = 0x0810);
PROVIDE(ADC12IFGR2_H       = 0x0811);
PROVIDE(ADC12IER0          = 0x0812);
PROVIDE(ADC12IER0_L        = 0x0812);
PROVIDE(ADC12IER0_H        = 0x0813);
PROVIDE(ADC12IER1          = 0x0814);
PROVIDE(ADC12IER1_L        = 0x0814);
PROVIDE(ADC12IER1_H        = 0x0815);
PROVIDE(ADC12IER2          = 0x0816);
PROVIDE(ADC12IER2_L        = 0x0816);
PROVIDE(ADC12IER2_H        = 0x0817);
PROVIDE(ADC12IV            = 0x0818);
PROVIDE(ADC12IV_L          = 0x0818);
PROVIDE(ADC12IV_H          = 0x0819);
PROVIDE(ADC12MCTL0         = 0x0820);
PROVIDE(ADC12MCTL0_L       = 0x0820);
PROVIDE(ADC12MCTL0_H       = 0x0821);
PROVIDE(ADC12MCTL1         = 0x0822);
PROVIDE(ADC12MCTL1_L       = 0x0822);
PROVIDE(ADC12MCTL1_H       = 0x0823);
PROVIDE(ADC12MCTL2         = 0x0824);
PROVIDE(ADC12MCTL2_L       = 0x0824);
PROVIDE(ADC12MCTL2_H       = 0x0825);
PROVIDE(ADC12MCTL3         = 0x0826);
PROVIDE(ADC12MCTL3_L       = 0x0826);
PROVIDE(ADC12MCTL3_H       = 0x0827);
PROVIDE(ADC12MCTL4         = 0x0828);
PROVIDE(ADC12MCTL4_L       = 0x0828);
PROVIDE(ADC12MCTL4_H       = 0x0829);
PROVIDE(ADC12MCTL5         = 0x082A);
PROVIDE(ADC12MCTL5_L       = 0x082A);
PROVIDE(ADC12MCTL5_H       = 0x082B);
PROVIDE(ADC12MCTL6         = 0x082C);
PROVIDE(ADC12MCTL6_L       = 0x082C);
PROVIDE(ADC12MCTL6_H       = 0x082D);
PROVIDE(ADC12MCTL7         = 0x082E);
PROVIDE(ADC12MCTL7_L       = 0x082E);
PROVIDE(ADC12MCTL7_H       = 0x082F);
PROVIDE(ADC12MCTL8         = 0x0830);
PROVIDE(ADC12MCTL8_L       = 0x0830);
PROVIDE(ADC12MCTL8_H       = 0x0831);
PROVIDE(ADC12MCTL9         = 0x0832);
PROVIDE(ADC12MCTL9_L       = 0x0832);
PROVIDE(ADC12MCTL9_H       = 0x0833);
PROVIDE(ADC12MCTL10        = 0x0834);
PROVIDE(ADC12MCTL10_L      = 0x0834);
PROVIDE(ADC12MCTL10_H      = 0x0835);
PROVIDE(ADC12MCTL11        = 0x0836);
PROVIDE(ADC12MCTL11_L      = 0x0836);
PROVIDE(ADC12MCTL11_H      = 0x0837);
PROVIDE(ADC12MCTL12        = 0x0838);
PROVIDE(ADC12MCTL12_L      = 0x0838);
PROVIDE(ADC12MCTL12_H      = 0x0839);
PROVIDE(ADC12MCTL13        = 0x083A);
PROVIDE(ADC12MCTL13_L      = 0x083A);
PROVIDE(ADC12MCTL13_H      = 0x083B);
PROVIDE(ADC12MCTL14        = 0x083C);
PROVIDE(ADC12MCTL14_L      = 0x083C);
PROVIDE(ADC12MCTL14_H      = 0x083D);
PROVIDE(ADC12MCTL15        = 0x083E);
PROVIDE(ADC12MCTL15_L      = 0x083E);
PROVIDE(ADC12MCTL15_H      = 0x083F);
PROVIDE(ADC12MCTL16        = 0x0840);
PROVIDE(ADC12MCTL16_L      = 0x0840);
PROVIDE(ADC12MCTL16_H      = 0x0841);
PROVIDE(ADC12MCTL17        = 0x0842);
PROVIDE(ADC12MCTL17_L      = 0x0842);
PROVIDE(ADC12MCTL17_H      = 0x0843);
PROVIDE(ADC12MCTL18        = 0x0844);
PROVIDE(ADC12MCTL18_L      = 0x0844);
PROVIDE(ADC12MCTL18_H      = 0x0845);
PROVIDE(ADC12MCTL19        = 0x0846);
PROVIDE(ADC12MCTL19_L      = 0x0846);
PROVIDE(ADC12MCTL19_H      = 0x0847);
PROVIDE(ADC12MCTL20        = 0x0848);
PROVIDE(ADC12MCTL20_L      = 0x0848);
PROVIDE(ADC12MCTL20_H      = 0x0849);
PROVIDE(ADC12MCTL21        = 0x084A);
PROVIDE(ADC12MCTL21_L      = 0x084A);
PROVIDE(ADC12MCTL21_H      = 0x084B);
PROVIDE(ADC12MCTL22        = 0x084C);
PROVIDE(ADC12MCTL22_L      = 0x084C);
PROVIDE(ADC12MCTL22_H      = 0x084D);
PROVIDE(ADC12MCTL23        = 0x084E);
PROVIDE(ADC12MCTL23_L      = 0x084E);
PROVIDE(ADC12MCTL23_H      = 0x084F);
PROVIDE(ADC12MCTL24        = 0x0850);
PROVIDE(ADC12MCTL24_L      = 0x0850);
PROVIDE(ADC12MCTL24_H      = 0x0851);
PROVIDE(ADC12MCTL25        = 0x0852);
PROVIDE(ADC12MCTL25_L      = 0x0852);
PROVIDE(ADC12MCTL25_H      = 0x0853);
PROVIDE(ADC12MCTL26        = 0x0854);
PROVIDE(ADC12MCTL26_L      = 0x0854);
PROVIDE(ADC12MCTL26_H      = 0x0855);
PROVIDE(ADC12MCTL27        = 0x0856);
PROVIDE(ADC12MCTL27_L      = 0x0856);
PROVIDE(ADC12MCTL27_H      = 0x0857);
PROVIDE(ADC12MCTL28        = 0x0858);
PROVIDE(ADC12MCTL28_L      = 0x0858);
PROVIDE(ADC12MCTL28_H      = 0x0859);
PROVIDE(ADC12MCTL29        = 0x085A);
PROVIDE(ADC12MCTL29_L      = 0x085A);
PROVIDE(ADC12MCTL29_H      = 0x085B);
PROVIDE(ADC12MCTL30        = 0x085C);
PROVIDE(ADC12MCTL30_L      = 0x085C);
PROVIDE(ADC12MCTL30_H      = 0x085D);
PROVIDE(ADC12MCTL31        = 0x085E);
PROVIDE(ADC12MCTL31_L      = 0x085E);
PROVIDE(ADC12MCTL31_H      = 0x085F);
PROVIDE(ADC12MEM0          = 0x0860);
PROVIDE(ADC12MEM0_L        = 0x0860);
PROVIDE(ADC12MEM0_H        = 0x0861);
PROVIDE(ADC12MEM1          = 0x0862);
PROVIDE(ADC12MEM1_L        = 0x0862);
PROVIDE(ADC12MEM1_H        = 0x0863);
PROVIDE(ADC12MEM2          = 0x0864);
PROVIDE(ADC12MEM2_L        = 0x0864);
PROVIDE(ADC12MEM2_H        = 0x0865);
PROVIDE(ADC12MEM3          = 0x0866);
PROVIDE(ADC12MEM3_L        = 0x0866);
PROVIDE(ADC12MEM3_H        = 0x0867);
PROVIDE(ADC12MEM4          = 0x0868);
PROVIDE(ADC12MEM4_L        = 0x0868);
PROVIDE(ADC12MEM4_H        = 0x0869);
PROVIDE(ADC12MEM5          = 0x086A);
PROVIDE(ADC12MEM5_L        = 0x086A);
PROVIDE(ADC12MEM5_H        = 0x086B);
PROVIDE(ADC12MEM6          = 0x086C);
PROVIDE(ADC12MEM6_L        = 0x086C);
PROVIDE(ADC12MEM6_H        = 0x086D);
PROVIDE(ADC12MEM7          = 0x086E);
PROVIDE(ADC12MEM7_L        = 0x086E);
PROVIDE(ADC12MEM7_H        = 0x086F);
PROVIDE(ADC12MEM8          = 0x0870);
PROVIDE(ADC12MEM8_L        = 0x0870);
PROVIDE(ADC12MEM8_H        = 0x0871);
PROVIDE(ADC12MEM9          = 0x0872);
PROVIDE(ADC12MEM9_L        = 0x0872);
PROVIDE(ADC12MEM9_H        = 0x0873);
PROVIDE(ADC12MEM10         = 0x0874);
PROVIDE(ADC12MEM10_L       = 0x0874);
PROVIDE(ADC12MEM10_H       = 0x0875);
PROVIDE(ADC12MEM11         = 0x0876);
PROVIDE(ADC12MEM11_L       = 0x0876);
PROVIDE(ADC12MEM11_H       = 0x0877);
PROVIDE(ADC12MEM12         = 0x0878);
PROVIDE(ADC12MEM12_L       = 0x0878);
PROVIDE(ADC12MEM12_H       = 0x0879);
PROVIDE(ADC12MEM13         = 0x087A);
PROVIDE(ADC12MEM13_L       = 0x087A);
PROVIDE(ADC12MEM13_H       = 0x087B);
PROVIDE(ADC12MEM14         = 0x087C);
PROVIDE(ADC12MEM14_L       = 0x087C);
PROVIDE(ADC12MEM14_H       = 0x087D);
PROVIDE(ADC12MEM15         = 0x087E);
PROVIDE(ADC12MEM15_L       = 0x087E);
PROVIDE(ADC12MEM15_H       = 0x087F);
PROVIDE(ADC12MEM16         = 0x0880);
PROVIDE(ADC12MEM16_L       = 0x0880);
PROVIDE(ADC12MEM16_H       = 0x0881);
PROVIDE(ADC12MEM17         = 0x0882);
PROVIDE(ADC12MEM17_L       = 0x0882);
PROVIDE(ADC12MEM17_H       = 0x0883);
PROVIDE(ADC12MEM18         = 0x0884);
PROVIDE(ADC12MEM18_L       = 0x0884);
PROVIDE(ADC12MEM18_H       = 0x0885);
PROVIDE(ADC12MEM19         = 0x0886);
PROVIDE(ADC12MEM19_L       = 0x0886);
PROVIDE(ADC12MEM19_H       = 0x0887);
PROVIDE(ADC12MEM20         = 0x0888);
PROVIDE(ADC12MEM20_L       = 0x0888);
PROVIDE(ADC12MEM20_H       = 0x0889);
PROVIDE(ADC12MEM21         = 0x088A);
PROVIDE(ADC12MEM21_L       = 0x088A);
PROVIDE(ADC12MEM21_H       = 0x088B);
PROVIDE(ADC12MEM22         = 0x088C);
PROVIDE(ADC12MEM22_L       = 0x088C);
PROVIDE(ADC12MEM22_H       = 0x088D);
PROVIDE(ADC12MEM23         = 0x088E);
PROVIDE(ADC12MEM23_L       = 0x088E);
PROVIDE(ADC12MEM23_H       = 0x088F);
PROVIDE(ADC12MEM24         = 0x0890);
PROVIDE(ADC12MEM24_L       = 0x0890);
PROVIDE(ADC12MEM24_H       = 0x0891);
PROVIDE(ADC12MEM25         = 0x0892);
PROVIDE(ADC12MEM25_L       = 0x0892);
PROVIDE(ADC12MEM25_H       = 0x0893);
PROVIDE(ADC12MEM26         = 0x0894);
PROVIDE(ADC12MEM26_L       = 0x0894);
PROVIDE(ADC12MEM26_H       = 0x0895);
PROVIDE(ADC12MEM27         = 0x0896);
PROVIDE(ADC12MEM27_L       = 0x0896);
PROVIDE(ADC12MEM27_H       = 0x0897);
PROVIDE(ADC12MEM28         = 0x0898);
PROVIDE(ADC12MEM28_L       = 0x0898);
PROVIDE(ADC12MEM28_H       = 0x0899);
PROVIDE(ADC12MEM29         = 0x089A);
PROVIDE(ADC12MEM29_L       = 0x089A);
PROVIDE(ADC12MEM29_H       = 0x089B);
PROVIDE(ADC12MEM30         = 0x089C);
PROVIDE(ADC12MEM30_L       = 0x089C);
PROVIDE(ADC12MEM30_H       = 0x089D);
PROVIDE(ADC12MEM31         = 0x089E);
PROVIDE(ADC12MEM31_L       = 0x089E);
PROVIDE(ADC12MEM31_H       = 0x089F);


/*****************************************************************************
 AES256
*****************************************************************************/
PROVIDE(AESACTL0           = 0x09C0);
PROVIDE(AESACTL0_L         = 0x09C0);
PROVIDE(AESACTL0_H         = 0x09C1);
PROVIDE(AESACTL1           = 0x09C2);
PROVIDE(AESACTL1_L         = 0x09C2);
PROVIDE(AESACTL1_H         = 0x09C3);
PROVIDE(AESASTAT           = 0x09C4);
PROVIDE(AESASTAT_L         = 0x09C4);
PROVIDE(AESASTAT_H         = 0x09C5);
PROVIDE(AESAKEY            = 0x09C6);
PROVIDE(AESAKEY_L          = 0x09C6);
PROVIDE(AESAKEY_H          = 0x09C7);
PROVIDE(AESADIN            = 0x09C8);
PROVIDE(AESADIN_L          = 0x09C8);
PROVIDE(AESADIN_H          = 0x09C9);
PROVIDE(AESADOUT           = 0x09CA);
PROVIDE(AESADOUT_L         = 0x09CA);
PROVIDE(AESADOUT_H         = 0x09CB);
PROVIDE(AESAXDIN           = 0x09CC);
PROVIDE(AESAXDIN_L         = 0x09CC);
PROVIDE(AESAXDIN_H         = 0x09CD);
PROVIDE(AESAXIN            = 0x09CE);
PROVIDE(AESAXIN_L          = 0x09CE);
PROVIDE(AESAXIN_H          = 0x09CF);


/*****************************************************************************
 CAPTIO0
*****************************************************************************/
PROVIDE(CAPTIO0CTL         = 0x043E);
PROVIDE(CAPTIO0CTL_L       = 0x043E);
PROVIDE(CAPTIO0CTL_H       = 0x043F);


/*****************************************************************************
 CAPTIO1
*****************************************************************************/
PROVIDE(CAPTIO1CTL         = 0x047E);
PROVIDE(CAPTIO1CTL_L       = 0x047E);
PROVIDE(CAPTIO1CTL_H       = 0x047F);


/*****************************************************************************
 COMP_E
*****************************************************************************/
PROVIDE(CECTL0             = 0x08C0);
PROVIDE(CECTL0_L           = 0x08C0);
PROVIDE(CECTL0_H           = 0x08C1);
PROVIDE(CECTL1             = 0x08C2);
PROVIDE(CECTL1_L           = 0x08C2);
PROVIDE(CECTL1_H           = 0x08C3);
PROVIDE(CECTL2             = 0x08C4);
PROVIDE(CECTL2_L           = 0x08C4);
PROVIDE(CECTL2_H           = 0x08C5);
PROVIDE(CECTL3             = 0x08C6);
PROVIDE(CECTL3_L           = 0x08C6);
PROVIDE(CECTL3_H           = 0x08C7);
PROVIDE(CEINT              = 0x08CC);
PROVIDE(CEINT_L            = 0x08CC);
PROVIDE(CEINT_H            = 0x08CD);
PROVIDE(CEIV               = 0x08CE);
PROVIDE(CEIV_L             = 0x08CE);
PROVIDE(CEIV_H             = 0x08CF);


/*****************************************************************************
 CRC
*****************************************************************************/
PROVIDE(CRCDI              = 0x0150);
PROVIDE(CRCDI_L            = 0x0150);
PROVIDE(CRCDI_H            = 0x0151);
PROVIDE(CRCDIRB            = 0x0152);
PROVIDE(CRCDIRB_L          = 0x0152);
PROVIDE(CRCDIRB_H          = 0x0153);
PROVIDE(CRCINIRES          = 0x0154);
PROVIDE(CRCINIRES_L        = 0x0154);
PROVIDE(CRCINIRES_H        = 0x0155);
PROVIDE(CRCRESR            = 0x0156);
PROVIDE(CRCRESR_L          = 0x0156);
PROVIDE(CRCRESR_H          = 0x0157);


/*****************************************************************************
 CRC32
*****************************************************************************/
PROVIDE(CRC32DIW0          = 0x0980);
PROVIDE(CRC32DIW0_L        = 0x0980);
PROVIDE(CRC32DIW0_H        = 0x0981);
PROVIDE(CRC32DIW1          = 0x0982);
PROVIDE(CRC32DIW1_L        = 0x0982);
PROVIDE(CRC32DIW1_H        = 0x0983);
PROVIDE(CRC32DIRBW1        = 0x0984);
PROVIDE(CRC32DIRBW1_L      = 0x0984);
PROVIDE(CRC32DIRBW1_H      = 0x0985);
PROVIDE(CRC32DIRBW0        = 0x0986);
PROVIDE(CRC32DIRBW0_L      = 0x0986);
PROVIDE(CRC32DIRBW0_H      = 0x0987);
PROVIDE(CRC32INIRESW0      = 0x0988);
PROVIDE(CRC32INIRESW0_L    = 0x0988);
PROVIDE(CRC32INIRESW0_H    = 0x0989);
PROVIDE(CRC32INIRESW1      = 0x098A);
PROVIDE(CRC32INIRESW1_L    = 0x098A);
PROVIDE(CRC32INIRESW1_H    = 0x098B);
PROVIDE(CRC32RESRW1        = 0x098C);
PROVIDE(CRC32RESRW1_L      = 0x098C);
PROVIDE(CRC32RESRW1_H      = 0x098D);
PROVIDE(CRC32RESRW0        = 0x098E);
PROVIDE(CRC32RESRW0_L      = 0x098E);
PROVIDE(CRC32RESRW0_H      = 0x098F);
PROVIDE(CRC16DIW0          = 0x0990);
PROVIDE(CRC16DIW0_L        = 0x0990);
PROVIDE(CRC16DIW0_H        = 0x0991);
PROVIDE(CRC16DIRBW0        = 0x0996);
PROVIDE(CRC16DIRBW0_L      = 0x0996);
PROVIDE(CRC16DIRBW0_H      = 0x0997);
PROVIDE(CRC16INIRESW0      = 0x0998);
PROVIDE(CRC16INIRESW0_L    = 0x0998);
PROVIDE(CRC16INIRESW0_H    = 0x0999);
PROVIDE(CRC16RESRW0        = 0x099E);
PROVIDE(CRC16RESRW0_L      = 0x099E);
PROVIDE(CRC16RESRW0_H      = 0x099F);


/*****************************************************************************
 CS
*****************************************************************************/
PROVIDE(CSCTL0             = 0x0160);
PROVIDE(CSCTL0_L           = 0x0160);
PROVIDE(CSCTL0_H           = 0x0161);
PROVIDE(CSCTL1             = 0x0162);
PROVIDE(CSCTL1_L           = 0x0162);
PROVIDE(CSCTL1_H           = 0x0163);
PROVIDE(CSCTL2             = 0x0164);
PROVIDE(CSCTL2_L           = 0x0164);
PROVIDE(CSCTL2_H           = 0x0165);
PROVIDE(CSCTL3             = 0x0166);
PROVIDE(CSCTL3_L           = 0x0166);
PROVIDE(CSCTL3_H           = 0x0167);
PROVIDE(CSCTL4             = 0x0168);
PROVIDE(CSCTL4_L           = 0x0168);
PROVIDE(CSCTL4_H           = 0x0169);
PROVIDE(CSCTL5             = 0x016A);
PROVIDE(CSCTL5_L           = 0x016A);
PROVIDE(CSCTL5_H           = 0x016B);
PROVIDE(CSCTL6             = 0x016C);
PROVIDE(CSCTL6_L           = 0x016C);
PROVIDE(CSCTL6_H           = 0x016D);


/*****************************************************************************
 DIO
*****************************************************************************/
PROVIDE(PAIN               = 0x0200);
PROVIDE(PAIN_L             = 0x0200);
PROVIDE(PAIN_H             = 0x0201);
PROVIDE(PAOUT              = 0x0202);
PROVIDE(PAOUT_L            = 0x0202);
PROVIDE(PAOUT_H            = 0x0203);
PROVIDE(PADIR              = 0x0204);
PROVIDE(PADIR_L            = 0x0204);
PROVIDE(PADIR_H            = 0x0205);
PROVIDE(PAREN              = 0x0206);
PROVIDE(PAREN_L            = 0x0206);
PROVIDE(PAREN_H            = 0x0207);
PROVIDE(PASEL0             = 0x020A);
PROVIDE(PASEL0_L           = 0x020A);
PROVIDE(PASEL0_H           = 0x020B);
PROVIDE(PASEL1             = 0x020C);
PROVIDE(PASEL1_L           = 0x020C);
PROVIDE(PASEL1_H           = 0x020D);
PROVIDE(P1IV               = 0x020E);
PROVIDE(P1IV_L             = 0x020E);
PROVIDE(P1IV_H             = 0x020F);
PROVIDE(PASELC             = 0x0216);
PROVIDE(PASELC_L           = 0x0216);
PROVIDE(PASELC_H           = 0x0217);
PROVIDE(PAIES              = 0x0218);
PROVIDE(PAIES_L            = 0x0218);
PROVIDE(PAIES_H            = 0x0219);
PROVIDE(PAIE               = 0x021A);
PROVIDE(PAIE_L             = 0x021A);
PROVIDE(PAIE_H             = 0x021B);
PROVIDE(PAIFG              = 0x021C);
PROVIDE(PAIFG_L            = 0x021C);
PROVIDE(PAIFG_H            = 0x021D);
PROVIDE(P2IV               = 0x021E);
PROVIDE(P2IV_L             = 0x021E);
PROVIDE(P2IV_H             = 0x021F);
PROVIDE(PBIN               = 0x0220);
PROVIDE(PBIN_L             = 0x0220);
PROVIDE(PBIN_H             = 0x0221);
PROVIDE(PBOUT              = 0x0222);
PROVIDE(PBOUT_L            = 0x0222);
PROVIDE(PBOUT_H            = 0x0223);
PROVIDE(PBDIR              = 0x0224);
PROVIDE(PBDIR_L            = 0x0224);
PROVIDE(PBDIR_H            = 0x0225);
PROVIDE(PBREN              = 0x0226);
PROVIDE(PBREN_L            = 0x0226);
PROVIDE(PBREN_H            = 0x0227);
PROVIDE(PBSEL0             = 0x022A);
PROVIDE(PBSEL0_L           = 0x022A);
PROVIDE(PBSEL0_H           = 0x022B);
PROVIDE(PBSEL1             = 0x022C);
PROVIDE(PBSEL1_L           = 0x022C);
PROVIDE(PBSEL1_H           = 0x022D);
PROVIDE(P3IV               = 0x022E);
PROVIDE(P3IV_L             = 0x022E);
PROVIDE(P3IV_H             = 0x022F);
PROVIDE(PBSELC             = 0x0236);
PROVIDE(PBSELC_L           = 0x0236);
PROVIDE(PBSELC_H           = 0x0237);
PROVIDE(PBIES              = 0x0238);
PROVIDE(PBIES_L            = 0x0238);
PROVIDE(PBIES_H            = 0x0239);
PROVIDE(PBIE               = 0x023A);
PROVIDE(PBIE_L             = 0x023A);
PROVIDE(PBIE_H             = 0x023B);
PROVIDE(PBIFG              = 0x023C);
PROVIDE(PBIFG_L            = 0x023C);
PROVIDE(PBIFG_H            = 0x023D);
PROVIDE(P4IV               = 0x023E);
PROVIDE(P4IV_L             = 0x023E);
PROVIDE(P4IV_H             = 0x023F);
PROVIDE(PCIN               = 0x0240);
PROVIDE(PCIN_L             = 0x0240);
PROVIDE(PCIN_H             = 0x0241);
PROVIDE(PCOUT              = 0x0242);
PROVIDE(PCOUT_L            = 0x0242);
PROVIDE(PCOUT_H            = 0x0243);
PROVIDE(PCDIR              = 0x0244);
PROVIDE(PCDIR_L            = 0x0244);
PROVIDE(PCDIR_H            = 0x0245);
PROVIDE(PCREN              = 0x0246);
PROVIDE(PCREN_L            = 0x0246);
PROVIDE(PCREN_H            = 0x0247);
PROVIDE(PCSEL0             = 0x024A);
PROVIDE(PCSEL0_L           = 0x024A);
PROVIDE(PCSEL0_H           = 0x024B);
PROVIDE(PCSEL1             = 0x024C);
PROVIDE(PCSEL1_L           = 0x024C);
PROVIDE(PCSEL1_H           = 0x024D);
PROVIDE(P5IV               = 0x024E);
PROVIDE(P5IV_L             = 0x024E);
PROVIDE(P5IV_H             = 0x024F);
PROVIDE(PCSELC             = 0x0256);
PROVIDE(PCSELC_L           = 0x0256);
PROVIDE(PCSELC_H           = 0x0257);
PROVIDE(PCIES              = 0x0258);
PROVIDE(PCIES_L            = 0x0258);
PROVIDE(PCIES_H            = 0x0259);
PROVIDE(PCIE               = 0x025A);
PROVIDE(PCIE_L             = 0x025A);
PROVIDE(PCIE_H             = 0x025B);
PROVIDE(PCIFG              = 0x025C);
PROVIDE(PCIFG_L            = 0x025C);
PROVIDE(PCIFG_H            = 0x025D);
PROVIDE(P6IV               = 0x025E);
PROVIDE(P6IV_L             = 0x025E);
PROVIDE(P6IV_H             = 0x025F);
PROVIDE(PDIN               = 0x0260);
PROVIDE(PDIN_L             = 0x0260);
PROVIDE(PDIN_H             = 0x0261);
PROVIDE(PDOUT              = 0x0262);
PROVIDE(PDOUT_L            = 0x0262);
PROVIDE(PDOUT_H            = 0x0263);
PROVIDE(PDDIR              = 0x0264);
PROVIDE(PDDIR_L            = 0x0264);
PROVIDE(PDDIR_H            = 0x0265);
PROVIDE(PDREN              = 0x0266);
PROVIDE(PDREN_L            = 0x0266);
PROVIDE(PDREN_H            = 0x0267);
PROVIDE(PDSEL0             = 0x026A);
PROVIDE(PDSEL0_L           = 0x026A);
PROVIDE(PDSEL0_H           = 0x026B);
PROVIDE(PDSEL1             = 0x026C);
PROVIDE(PDSEL1_L           = 0x026C);
PROVIDE(PDSEL1_H           = 0x026D);
PROVIDE(P7IV               = 0x026E);
PROVIDE(P7IV_L             = 0x026E);
PROVIDE(P7IV_H             = 0x026F);
PROVIDE(PDSELC             = 0x0276);
PROVIDE(PDSELC_L           = 0x0276);
PROVIDE(PDSELC_H           = 0x0277);
PROVIDE(PDIES              = 0x0278);
PROVIDE(PDIES_L            = 0x0278);
PROVIDE(PDIES_H            = 0x0279);
PROVIDE(PDIE               = 0x027A);
PROVIDE(PDIE_L             = 0x027A);
PROVIDE(PDIE_H             = 0x027B);
PROVIDE(PDIFG              = 0x027C);
PROVIDE(PDIFG_L            = 0x027C);
PROVIDE(PDIFG_H            = 0x027D);
PROVIDE(P8IV               = 0x027E);
PROVIDE(P8IV_L             = 0x027E);
PROVIDE(P8IV_H             = 0x027F);
PROVIDE(PJIN               = 0x0320);
PROVIDE(PJIN_L             = 0x0320);
PROVIDE(PJIN_H             = 0x0321);
PROVIDE(PJOUT              = 0x0322);
PROVIDE(PJOUT_L            = 0x0322);
PROVIDE(PJOUT_H            = 0x0323);
PROVIDE(PJDIR              = 0x0324);
PROVIDE(PJDIR_L            = 0x0324);
PROVIDE(PJDIR_H            = 0x0325);
PROVIDE(PJREN              = 0x0326);
PROVIDE(PJREN_L            = 0x0326);
PROVIDE(PJREN_H            = 0x0327);
PROVIDE(PJSEL0             = 0x032A);
PROVIDE(PJSEL0_L           = 0x032A);
PROVIDE(PJSEL0_H           = 0x032B);
PROVIDE(PJSEL1             = 0x032C);
PROVIDE(PJSEL1_L           = 0x032C);
PROVIDE(PJSEL1_H           = 0x032D);
PROVIDE(PJSELC             = 0x0336);
PROVIDE(PJSELC_L           = 0x0336);
PROVIDE(PJSELC_H           = 0x0337);
PROVIDE(P1IN               = 0x0200);

PROVIDE(P2IN               = 0x0201);

PROVIDE(P2OUT              = 0x0203);

PROVIDE(P1OUT              = 0x0202);

PROVIDE(P1DIR              = 0x0204);

PROVIDE(P2DIR              = 0x0205);

PROVIDE(P1REN              = 0x0206);

PROVIDE(P2REN              = 0x0207);

PROVIDE(P1SEL0             = 0x020A);

PROVIDE(P2SEL0             = 0x020B);

PROVIDE(P1SEL1             = 0x020C);

PROVIDE(P2SEL1             = 0x020D);

PROVIDE(P1SELC             = 0x0216);

PROVIDE(P2SELC             = 0x0217);

PROVIDE(P1IES              = 0x0218);

PROVIDE(P2IES              = 0x0219);

PROVIDE(P1IE               = 0x021A);

PROVIDE(P2IE               = 0x021B);

PROVIDE(P1IFG              = 0x021C);

PROVIDE(P2IFG              = 0x021D);

PROVIDE(P3IN               = 0x0220);

PROVIDE(P4IN               = 0x0221);

PROVIDE(P3OUT              = 0x0222);

PROVIDE(P4OUT              = 0x0223);

PROVIDE(P3DIR              = 0x0224);

PROVIDE(P4DIR              = 0x0225);

PROVIDE(P3REN              = 0x0226);

PROVIDE(P4REN              = 0x0227);

PROVIDE(P4SEL0             = 0x022B);

PROVIDE(P3SEL0             = 0x022A);

PROVIDE(P3SEL1             = 0x022C);

PROVIDE(P4SEL1             = 0x022D);

PROVIDE(P3SELC             = 0x0236);

PROVIDE(P4SELC             = 0x0237);

PROVIDE(P3IES              = 0x0238);

PROVIDE(P4IES              = 0x0239);

PROVIDE(P3IE               = 0x023A);

PROVIDE(P4IE               = 0x023B);

PROVIDE(P3IFG              = 0x023C);

PROVIDE(P4IFG              = 0x023D);

PROVIDE(P5IN               = 0x0240);

PROVIDE(P6IN               = 0x0241);

PROVIDE(P5OUT              = 0x0242);

PROVIDE(P6OUT              = 0x0243);

PROVIDE(P5DIR              = 0x0244);

PROVIDE(P6DIR              = 0x0245);

PROVIDE(P5REN              = 0x0246);

PROVIDE(P6REN              = 0x0247);

PROVIDE(P5SEL0             = 0x024A);

PROVIDE(P6SEL0             = 0x024B);

PROVIDE(P5SEL1             = 0x024C);

PROVIDE(P6SEL1             = 0x024D);

PROVIDE(P5SELC             = 0x0256);

PROVIDE(P6SELC             = 0x0257);

PROVIDE(P5IES              = 0x0258);

PROVIDE(P6IES              = 0x0259);

PROVIDE(P5IE               = 0x025A);

PROVIDE(P6IE               = 0x025B);

PROVIDE(P5IFG              = 0x025C);

PROVIDE(P6IFG              = 0x025D);

PROVIDE(P7IN               = 0x0260);

PROVIDE(P8IN               = 0x0261);

PROVIDE(P7OUT              = 0x0262);

PROVIDE(P8OUT              = 0x0263);

PROVIDE(P7DIR              = 0x0264);

PROVIDE(P8DIR              = 0x0265);

PROVIDE(P7REN              = 0x0266);

PROVIDE(P8REN              = 0x0267);

PROVIDE(P7SEL0             = 0x026A);

PROVIDE(P8SEL0             = 0x026B);

PROVIDE(P7SEL1             = 0x026C);

PROVIDE(P8SEL1             = 0x026D);

PROVIDE(P7SELC             = 0x0276);

PROVIDE(P8SELC             = 0x0277);

PROVIDE(P7IES              = 0x0278);

PROVIDE(P8IES              = 0x0279);

PROVIDE(P7IE               = 0x027A);

PROVIDE(P8IE               = 0x027B);

PROVIDE(P7IFG              = 0x027C);

PROVIDE(P8IFG              = 0x027D);



/*****************************************************************************
 DMA
*****************************************************************************/
PROVIDE(DMACTL0            = 0x0500);
PROVIDE(DMACTL0_L          = 0x0500);
PROVIDE(DMACTL0_H          = 0x0501);
PROVIDE(DMACTL1            = 0x0502);
PROVIDE(DMACTL1_L          = 0x0502);
PROVIDE(DMACTL1_H          = 0x0503);
PROVIDE(DMACTL2            = 0x0504);
PROVIDE(DMACTL2_L          = 0x0504);
PROVIDE(DMACTL2_H          = 0x0505);
PROVIDE(DMACTL4            = 0x0508);
PROVIDE(DMACTL4_L          = 0x0508);
PROVIDE(DMACTL4_H          = 0x0509);
PROVIDE(DMAIV              = 0x050E);
PROVIDE(DMAIV_L            = 0x050E);
PROVIDE(DMAIV_H            = 0x050F);
PROVIDE(DMA0CTL            = 0x0510);
PROVIDE(DMA0CTL_L          = 0x0510);
PROVIDE(DMA0CTL_H          = 0x0511);
PROVIDE(DMA0SA             = 0x0512);
PROVIDE(DMA0SAL            = 0x0512);
PROVIDE(DMA0SAH            = 0x0514);

PROVIDE(DMA0DA             = 0x0516);
PROVIDE(DMA0DAL            = 0x0516);
PROVIDE(DMA0DAH            = 0x0518);

PROVIDE(DMA0SZ             = 0x051A);
PROVIDE(DMA0SZ_L           = 0x051A);
PROVIDE(DMA0SZ_H           = 0x051B);
PROVIDE(DMA1CTL            = 0x0520);
PROVIDE(DMA1CTL_L          = 0x0520);
PROVIDE(DMA1CTL_H          = 0x0521);
PROVIDE(DMA1SA             = 0x0522);
PROVIDE(DMA1SAL            = 0x0522);
PROVIDE(DMA1SAH            = 0x0524);

PROVIDE(DMA1DA             = 0x0526);
PROVIDE(DMA1DAL            = 0x0526);
PROVIDE(DMA1DAH            = 0x0528);

PROVIDE(DMA1SZ             = 0x052A);
PROVIDE(DMA1SZ_L           = 0x052A);
PROVIDE(DMA1SZ_H           = 0x052B);
PROVIDE(DMA2CTL            = 0x0530);
PROVIDE(DMA2CTL_L          = 0x0530);
PROVIDE(DMA2CTL_H          = 0x0531);
PROVIDE(DMA2SA             = 0x0532);
PROVIDE(DMA2SAL            = 0x0532);
PROVIDE(DMA2SAH            = 0x0534);

PROVIDE(DMA2DA             = 0x0536);
PROVIDE(DMA2DAL            = 0x0536);
PROVIDE(DMA2DAH            = 0x0538);

PROVIDE(DMA2SZ             = 0x053A);
PROVIDE(DMA2SZ_L           = 0x053A);
PROVIDE(DMA2SZ_H           = 0x053B);
PROVIDE(DMA3CTL            = 0x0540);
PROVIDE(DMA3CTL_L          = 0x0540);
PROVIDE(DMA3CTL_H          = 0x0541);
PROVIDE(DMA3SA             = 0x0542);
PROVIDE(DMA3SAL            = 0x0542);
PROVIDE(DMA3SAH            = 0x0544);

PROVIDE(DMA3DA             = 0x0546);
PROVIDE(DMA3DAL            = 0x0546);
PROVIDE(DMA3DAH            = 0x0548);

PROVIDE(DMA3SZ             = 0x054A);
PROVIDE(DMA3SZ_L           = 0x054A);
PROVIDE(DMA3SZ_H           = 0x054B);
PROVIDE(DMA4CTL            = 0x0550);
PROVIDE(DMA4CTL_L          = 0x0550);
PROVIDE(DMA4CTL_H          = 0x0551);
PROVIDE(DMA4SA             = 0x0552);
PROVIDE(DMA4SAL            = 0x0552);
PROVIDE(DMA4SAH            = 0x0554);

PROVIDE(DMA4DA             = 0x0556);
PROVIDE(DMA4DAL            = 0x0556);
PROVIDE(DMA4DAH            = 0x0558);

PROVIDE(DMA4SZ             = 0x055A);
PROVIDE(DMA4SZ_L           = 0x055A);
PROVIDE(DMA4SZ_H           = 0x055B);
PROVIDE(DMA5CTL            = 0x0560);
PROVIDE(DMA5CTL_L          = 0x0560);
PROVIDE(DMA5CTL_H          = 0x0561);
PROVIDE(DMA5SA             = 0x0562);
PROVIDE(DMA5SAL            = 0x0562);
PROVIDE(DMA5SAH            = 0x0564);

PROVIDE(DMA5DA             = 0x0566);
PROVIDE(DMA5DAL            = 0x0566);
PROVIDE(DMA5DAH            = 0x0568);

PROVIDE(DMA5SZ             = 0x056A);
PROVIDE(DMA5SZ_L           = 0x056A);
PROVIDE(DMA5SZ_H           = 0x056B);


/*****************************************************************************
 FRCTL_A
*****************************************************************************/
PROVIDE(FRCTL0             = 0x0140);
PROVIDE(FRCTL0_L           = 0x0140);
PROVIDE(FRCTL0_H           = 0x0141);
PROVIDE(GCCTL0             = 0x0144);
PROVIDE(GCCTL0_L           = 0x0144);
PROVIDE(GCCTL0_H           = 0x0145);
PROVIDE(GCCTL1             = 0x0146);
PROVIDE(GCCTL1_L           = 0x0146);
PROVIDE(GCCTL1_H           = 0x0147);


/*****************************************************************************
 LEA
*****************************************************************************/
PROVIDE(LEACAP             = 0x0A80);
PROVIDE(LEACAPL            = 0x0A80);
PROVIDE(LEACAPH            = 0x0A82);

PROVIDE(LEACNF0            = 0x0A84);
PROVIDE(LEACNF0L           = 0x0A84);
PROVIDE(LEACNF0H           = 0x0A86);

PROVIDE(LEACNF1            = 0x0A88);
PROVIDE(LEACNF1L           = 0x0A88);
PROVIDE(LEACNF1H           = 0x0A8A);

PROVIDE(LEACNF2            = 0x0A8C);
PROVIDE(LEACNF2L           = 0x0A8C);
PROVIDE(LEACNF2H           = 0x0A8E);

PROVIDE(LEAMB              = 0x0A90);
PROVIDE(LEAMBL             = 0x0A90);
PROVIDE(LEAMBH             = 0x0A92);

PROVIDE(LEAMT              = 0x0A94);
PROVIDE(LEAMTL             = 0x0A94);
PROVIDE(LEAMTH             = 0x0A96);

PROVIDE(LEACMA             = 0x0A98);
PROVIDE(LEACMAL            = 0x0A98);
PROVIDE(LEACMAH            = 0x0A9A);

PROVIDE(LEACMCTL           = 0x0A9C);
PROVIDE(LEACMCTLL          = 0x0A9C);
PROVIDE(LEACMCTLH          = 0x0A9E);

PROVIDE(LEACMDSTAT         = 0x0AA8);
PROVIDE(LEACMDSTATL        = 0x0AA8);
PROVIDE(LEACMDSTATH        = 0x0AAA);

PROVIDE(LEAS1STAT          = 0x0AAC);
PROVIDE(LEAS1STATL         = 0x0AAC);
PROVIDE(LEAS1STATH         = 0x0AAE);

PROVIDE(LEAS0STAT          = 0x0AB0);
PROVIDE(LEAS0STATL         = 0x0AB0);
PROVIDE(LEAS0STATH         = 0x0AB2);

PROVIDE(LEADSTSTAT         = 0x0AB4);
PROVIDE(LEADSTSTATL        = 0x0AB4);
PROVIDE(LEADSTSTATH        = 0x0AB6);

PROVIDE(LEAPMCTL           = 0x0AC0);
PROVIDE(LEAPMCTLL          = 0x0AC0);
PROVIDE(LEAPMCTLH          = 0x0AC2);

PROVIDE(LEAPMDST           = 0x0AC4);
PROVIDE(LEAPMDSTL          = 0x0AC4);
PROVIDE(LEAPMDSTH          = 0x0AC6);

PROVIDE(LEAPMS1            = 0x0AC8);
PROVIDE(LEAPMS1L           = 0x0AC8);
PROVIDE(LEAPMS1H           = 0x0ACA);

PROVIDE(LEAPMS0            = 0x0ACC);
PROVIDE(LEAPMS0L           = 0x0ACC);
PROVIDE(LEAPMS0H           = 0x0ACE);

PROVIDE(LEAPMCB            = 0x0AD0);
PROVIDE(LEAPMCBL           = 0x0AD0);
PROVIDE(LEAPMCBH           = 0x0AD2);

PROVIDE(LEAIFGSET          = 0x0AF0);
PROVIDE(LEAIFGSETL         = 0x0AF0);
PROVIDE(LEAIFGSETH         = 0x0AF2);

PROVIDE(LEAIE              = 0x0AF4);
PROVIDE(LEAIEL             = 0x0AF4);
PROVIDE(LEAIEH             = 0x0AF6);

PROVIDE(LEAIFG             = 0x0AF8);
PROVIDE(LEAIFGL            = 0x0AF8);
PROVIDE(LEAIFGH            = 0x0AFA);

PROVIDE(LEAIV              = 0x0AFC);
PROVIDE(LEAIVL             = 0x0AFC);
PROVIDE(LEAIVH             = 0x0AFE);



/*****************************************************************************
 MPU
*****************************************************************************/
PROVIDE(MPUCTL0            = 0x05A0);
PROVIDE(MPUCTL0_L          = 0x05A0);
PROVIDE(MPUCTL0_H          = 0x05A1);
PROVIDE(MPUCTL1            = 0x05A2);
PROVIDE(MPUCTL1_L          = 0x05A2);
PROVIDE(MPUCTL1_H          = 0x05A3);
PROVIDE(MPUSEGB2           = 0x05A4);
PROVIDE(MPUSEGB2_L         = 0x05A4);
PROVIDE(MPUSEGB2_H         = 0x05A5);
PROVIDE(MPUSEGB1           = 0x05A6);
PROVIDE(MPUSEGB1_L         = 0x05A6);
PROVIDE(MPUSEGB1_H         = 0x05A7);
PROVIDE(MPUSAM             = 0x05A8);
PROVIDE(MPUSAM_L           = 0x05A8);
PROVIDE(MPUSAM_H           = 0x05A9);
PROVIDE(MPUIPC0            = 0x05AA);
PROVIDE(MPUIPC0_L          = 0x05AA);
PROVIDE(MPUIPC0_H          = 0x05AB);
PROVIDE(MPUIPSEGB2         = 0x05AC);
PROVIDE(MPUIPSEGB2_L       = 0x05AC);
PROVIDE(MPUIPSEGB2_H       = 0x05AD);
PROVIDE(MPUIPSEGB1         = 0x05AE);
PROVIDE(MPUIPSEGB1_L       = 0x05AE);
PROVIDE(MPUIPSEGB1_H       = 0x05AF);


/*****************************************************************************
 MPY32
*****************************************************************************/
PROVIDE(MPY                = 0x04C0);
PROVIDE(MPY_L              = 0x04C0);
PROVIDE(MPY_H              = 0x04C1);
PROVIDE(MPYS               = 0x04C2);
PROVIDE(MPYS_L             = 0x04C2);
PROVIDE(MPYS_H             = 0x04C3);
PROVIDE(MAC                = 0x04C4);
PROVIDE(MAC_L              = 0x04C4);
PROVIDE(MAC_H              = 0x04C5);
PROVIDE(MACS               = 0x04C6);
PROVIDE(MACS_L             = 0x04C6);
PROVIDE(MACS_H             = 0x04C7);
PROVIDE(OP2                = 0x04C8);
PROVIDE(OP2_L              = 0x04C8);
PROVIDE(OP2_H              = 0x04C9);
PROVIDE(RESLO              = 0x04CA);
PROVIDE(RESLO_L            = 0x04CA);
PROVIDE(RESLO_H            = 0x04CB);
PROVIDE(RESHI              = 0x04CC);
PROVIDE(RESHI_L            = 0x04CC);
PROVIDE(RESHI_H            = 0x04CD);
PROVIDE(SUMEXT             = 0x04CE);
PROVIDE(SUMEXT_L           = 0x04CE);
PROVIDE(SUMEXT_H           = 0x04CF);
PROVIDE(MPY32L             = 0x04D0);
PROVIDE(MPY32L_L           = 0x04D0);
PROVIDE(MPY32L_H           = 0x04D1);
PROVIDE(MPY32H             = 0x04D2);
PROVIDE(MPY32H_L           = 0x04D2);
PROVIDE(MPY32H_H           = 0x04D3);
PROVIDE(MPYS32L            = 0x04D4);
PROVIDE(MPYS32L_L          = 0x04D4);
PROVIDE(MPYS32L_H          = 0x04D5);
PROVIDE(MPYS32H            = 0x04D6);
PROVIDE(MPYS32H_L          = 0x04D6);
PROVIDE(MPYS32H_H          = 0x04D7);
PROVIDE(MAC32L             = 0x04D8);
PROVIDE(MAC32L_L           = 0x04D8);
PROVIDE(MAC32L_H           = 0x04D9);
PROVIDE(MAC32H             = 0x04DA);
PROVIDE(MAC32H_L           = 0x04DA);
PROVIDE(MAC32H_H           = 0x04DB);
PROVIDE(MACS32L            = 0x04DC);
PROVIDE(MACS32L_L          = 0x04DC);
PROVIDE(MACS32L_H          = 0x04DD);
PROVIDE(MACS32H            = 0x04DE);
PROVIDE(MACS32H_L          = 0x04DE);
PROVIDE(MACS32H_H          = 0x04DF);
PROVIDE(OP2L               = 0x04E0);
PROVIDE(OP2L_L             = 0x04E0);
PROVIDE(OP2L_H             = 0x04E1);
PROVIDE(OP2H               = 0x04E2);
PROVIDE(OP2H_L             = 0x04E2);
PROVIDE(OP2H_H             = 0x04E3);
PROVIDE(RES0               = 0x04E4);
PROVIDE(RES0_L             = 0x04E4);
PROVIDE(RES0_H             = 0x04E5);
PROVIDE(RES1               = 0x04E6);
PROVIDE(RES1_L             = 0x04E6);
PROVIDE(RES1_H             = 0x04E7);
PROVIDE(RES2               = 0x04E8);
PROVIDE(RES2_L             = 0x04E8);
PROVIDE(RES2_H             = 0x04E9);
PROVIDE(RES3               = 0x04EA);
PROVIDE(RES3_L             = 0x04EA);
PROVIDE(RES3_H             = 0x04EB);
PROVIDE(MPY32CTL0          = 0x04EC);
PROVIDE(MPY32CTL0_L        = 0x04EC);
PROVIDE(MPY32CTL0_H        = 0x04ED);


/*****************************************************************************
 PMM
*****************************************************************************/
PROVIDE(PMMCTL0            = 0x0120);
PROVIDE(PMMCTL0_L          = 0x0120);
PROVIDE(PMMCTL0_H          = 0x0121);
PROVIDE(PMMIFG             = 0x012A);
PROVIDE(PMMIFG_L           = 0x012A);
PROVIDE(PMMIFG_H           = 0x012B);
PROVIDE(PM5CTL0            = 0x0130);
PROVIDE(PM5CTL0_L          = 0x0130);
PROVIDE(PM5CTL0_H          = 0x0131);


/*****************************************************************************
 RAMCTL
*****************************************************************************/
PROVIDE(RCCTL0             = 0x0158);
PROVIDE(RCCTL0_L           = 0x0158);
PROVIDE(RCCTL0_H           = 0x0159);


/*****************************************************************************
 REF_A
*****************************************************************************/
PROVIDE(REFCTL0            = 0x01B0);
PROVIDE(REFCTL0_L          = 0x01B0);
PROVIDE(REFCTL0_H          = 0x01B1);


/*****************************************************************************
 RTC_C
*****************************************************************************/
PROVIDE(RTCCTL0            = 0x04A0);
PROVIDE(RTCCTL0_L          = 0x04A0);
PROVIDE(RTCCTL0_H          = 0x04A1);
PROVIDE(RTCCTL13           = 0x04A2);
PROVIDE(RTCCTL13_L         = 0x04A2);
PROVIDE(RTCCTL13_H         = 0x04A3);
PROVIDE(RTCOCAL            = 0x04A4);
PROVIDE(RTCOCAL_L          = 0x04A4);
PROVIDE(RTCOCAL_H          = 0x04A5);
PROVIDE(RTCTCMP            = 0x04A6);
PROVIDE(RTCTCMP_L          = 0x04A6);
PROVIDE(RTCTCMP_H          = 0x04A7);
PROVIDE(RTCPS0CTL          = 0x04A8);
PROVIDE(RTCPS0CTL_L        = 0x04A8);
PROVIDE(RTCPS0CTL_H        = 0x04A9);
PROVIDE(RTCPS1CTL          = 0x04AA);
PROVIDE(RTCPS1CTL_L        = 0x04AA);
PROVIDE(RTCPS1CTL_H        = 0x04AB);
PROVIDE(RTCPS              = 0x04AC);
PROVIDE(RTCPS_L            = 0x04AC);
PROVIDE(RTCPS_H            = 0x04AD);
PROVIDE(RTCIV              = 0x04AE);
PROVIDE(RTCIV_L            = 0x04AE);
PROVIDE(RTCIV_H            = 0x04AF);
PROVIDE(RTCTIM0            = 0x04B0);
PROVIDE(RTCTIM0_L          = 0x04B0);
PROVIDE(RTCTIM0_H          = 0x04B1);
PROVIDE(RTCCNT12           = 0x04B0);
PROVIDE(RTCCNT12_L         = 0x04B0);
PROVIDE(RTCCNT12_H         = 0x04B1);
PROVIDE(RTCTIM1            = 0x04B2);
PROVIDE(RTCTIM1_L          = 0x04B2);
PROVIDE(RTCTIM1_H          = 0x04B3);
PROVIDE(RTCCNT34           = 0x04B2);
PROVIDE(RTCCNT34_L         = 0x04B2);
PROVIDE(RTCCNT34_H         = 0x04B3);
PROVIDE(RTCDATE            = 0x04B4);
PROVIDE(RTCDATE_L          = 0x04B4);
PROVIDE(RTCDATE_H          = 0x04B5);
PROVIDE(RTCYEAR            = 0x04B6);
PROVIDE(RTCYEAR_L          = 0x04B6);
PROVIDE(RTCYEAR_H          = 0x04B7);
PROVIDE(RTCAMINHR          = 0x04B8);
PROVIDE(RTCAMINHR_L        = 0x04B8);
PROVIDE(RTCAMINHR_H        = 0x04B9);
PROVIDE(RTCADOWDAY         = 0x04BA);
PROVIDE(RTCADOWDAY_L       = 0x04BA);
PROVIDE(RTCADOWDAY_H       = 0x04BB);
PROVIDE(BIN2BCD            = 0x04BC);
PROVIDE(BIN2BCD_L          = 0x04BC);
PROVIDE(BIN2BCD_H          = 0x04BD);
PROVIDE(BCD2BIN            = 0x04BE);
PROVIDE(BCD2BIN_L          = 0x04BE);
PROVIDE(BCD2BIN_H          = 0x04BF);
PROVIDE(RT0PS              = 0x04AC);

PROVIDE(RT1PS              = 0x04AD);

PROVIDE(RTCCNT1            = 0x04B0);

PROVIDE(RTCCNT2            = 0x04B1);

PROVIDE(RTCCNT3            = 0x04B2);

PROVIDE(RTCCNT4            = 0x04B3);



/*****************************************************************************
 SFR
*****************************************************************************/
PROVIDE(SFRIE1             = 0x0100);
PROVIDE(SFRIE1_L           = 0x0100);
PROVIDE(SFRIE1_H           = 0x0101);
PROVIDE(SFRIFG1            = 0x0102);
PROVIDE(SFRIFG1_L          = 0x0102);
PROVIDE(SFRIFG1_H          = 0x0103);
PROVIDE(SFRRPCR            = 0x0104);
PROVIDE(SFRRPCR_L          = 0x0104);
PROVIDE(SFRRPCR_H          = 0x0105);


/*****************************************************************************
 SYS
*****************************************************************************/
PROVIDE(SYSCTL             = 0x0180);
PROVIDE(SYSCTL_L           = 0x0180);
PROVIDE(SYSCTL_H           = 0x0181);
PROVIDE(SYSJMBC            = 0x0186);
PROVIDE(SYSJMBC_L          = 0x0186);
PROVIDE(SYSJMBC_H          = 0x0187);
PROVIDE(SYSJMBI0           = 0x0188);
PROVIDE(SYSJMBI0_L         = 0x0188);
PROVIDE(SYSJMBI0_H         = 0x0189);
PROVIDE(SYSJMBI1           = 0x018A);
PROVIDE(SYSJMBI1_L         = 0x018A);
PROVIDE(SYSJMBI1_H         = 0x018B);
PROVIDE(SYSJMBO0           = 0x018C);
PROVIDE(SYSJMBO0_L         = 0x018C);
PROVIDE(SYSJMBO0_H         = 0x018D);
PROVIDE(SYSJMBO1           = 0x018E);
PROVIDE(SYSJMBO1_L         = 0x018E);
PROVIDE(SYSJMBO1_H         = 0x018F);
PROVIDE(SYSUNIV            = 0x019A);
PROVIDE(SYSUNIV_L          = 0x019A);
PROVIDE(SYSUNIV_H          = 0x019B);
PROVIDE(SYSSNIV            = 0x019C);
PROVIDE(SYSSNIV_L          = 0x019C);
PROVIDE(SYSSNIV_H          = 0x019D);
PROVIDE(SYSRSTIV           = 0x019E);
PROVIDE(SYSRSTIV_L         = 0x019E);
PROVIDE(SYSRSTIV_H         = 0x019F);


/*****************************************************************************
 TA0
*****************************************************************************/
PROVIDE(TA0CTL             = 0x0340);
PROVIDE(TA0CTL_L           = 0x0340);
PROVIDE(TA0CTL_H           = 0x0341);
PROVIDE(TA0CCTL0           = 0x0342);
PROVIDE(TA0CCTL0_L         = 0x0342);
PROVIDE(TA0CCTL0_H         = 0x0343);
PROVIDE(TA0CCTL1           = 0x0344);
PROVIDE(TA0CCTL1_L         = 0x0344);
PROVIDE(TA0CCTL1_H         = 0x0345);
PROVIDE(TA0CCTL2           = 0x0346);
PROVIDE(TA0CCTL2_L         = 0x0346);
PROVIDE(TA0CCTL2_H         = 0x0347);
PROVIDE(TA0R               = 0x0350);
PROVIDE(TA0R_L             = 0x0350);
PROVIDE(TA0R_H             = 0x0351);
PROVIDE(TA0CCR0            = 0x0352);
PROVIDE(TA0CCR0_L          = 0x0352);
PROVIDE(TA0CCR0_H          = 0x0353);
PROVIDE(TA0CCR1            = 0x0354);
PROVIDE(TA0CCR1_L          = 0x0354);
PROVIDE(TA0CCR1_H          = 0x0355);
PROVIDE(TA0CCR2            = 0x0356);
PROVIDE(TA0CCR2_L          = 0x0356);
PROVIDE(TA0CCR2_H          = 0x0357);
PROVIDE(TA0EX0             = 0x0360);
PROVIDE(TA0EX0_L           = 0x0360);
PROVIDE(TA0EX0_H           = 0x0361);
PROVIDE(TA0IV              = 0x036E);
PROVIDE(TA0IV_L            = 0x036E);
PROVIDE(TA0IV_H            = 0x036F);


/*****************************************************************************
 TA1
*****************************************************************************/
PROVIDE(TA1CTL             = 0x0380);
PROVIDE(TA1CTL_L           = 0x0380);
PROVIDE(TA1CTL_H           = 0x0381);
PROVIDE(TA1CCTL0           = 0x0382);
PROVIDE(TA1CCTL0_L         = 0x0382);
PROVIDE(TA1CCTL0_H         = 0x0383);
PROVIDE(TA1CCTL1           = 0x0384);
PROVIDE(TA1CCTL1_L         = 0x0384);
PROVIDE(TA1CCTL1_H         = 0x0385);
PROVIDE(TA1CCTL2           = 0x0386);
PROVIDE(TA1CCTL2_L         = 0x0386);
PROVIDE(TA1CCTL2_H         = 0x0387);
PROVIDE(TA1R               = 0x0390);
PROVIDE(TA1R_L             = 0x0390);
PROVIDE(TA1R_H             = 0x0391);
PROVIDE(TA1CCR0            = 0x0392);
PROVIDE(TA1CCR0_L          = 0x0392);
PROVIDE(TA1CCR0_H          = 0x0393);
PROVIDE(TA1CCR1            = 0x0394);
PROVIDE(TA1CCR1_L          = 0x0394);
PROVIDE(TA1CCR1_H          = 0x0395);
PROVIDE(TA1CCR2            = 0x0396);
PROVIDE(TA1CCR2_L          = 0x0396);
PROVIDE(TA1CCR2_H          = 0x0397);
PROVIDE(TA1EX0             = 0x03A0);
PROVIDE(TA1EX0_L           = 0x03A0);
PROVIDE(TA1EX0_H           = 0x03A1);
PROVIDE(TA1IV              = 0x03AE);
PROVIDE(TA1IV_L            = 0x03AE);
PROVIDE(TA1IV_H            = 0x03AF);


/*****************************************************************************
 TA2
*****************************************************************************/
PROVIDE(TA2CTL             = 0x0400);
PROVIDE(TA2CTL_L           = 0x0400);
PROVIDE(TA2CTL_H           = 0x0401);
PROVIDE(TA2CCTL0           = 0x0402);
PROVIDE(TA2CCTL0_L         = 0x0402);
PROVIDE(TA2CCTL0_H         = 0x0403);
PROVIDE(TA2CCTL1           = 0x0404);
PROVIDE(TA2CCTL1_L         = 0x0404);
PROVIDE(TA2CCTL1_H         = 0x0405);
PROVIDE(TA2R               = 0x0410);
PROVIDE(TA2R_L             = 0x0410);
PROVIDE(TA2R_H             = 0x0411);
PROVIDE(TA2CCR0            = 0x0412);
PROVIDE(TA2CCR0_L          = 0x0412);
PROVIDE(TA2CCR0_H          = 0x0413);
PROVIDE(TA2CCR1            = 0x0414);
PROVIDE(TA2CCR1_L          = 0x0414);
PROVIDE(TA2CCR1_H          = 0x0415);
PROVIDE(TA2EX0             = 0x0420);
PROVIDE(TA2EX0_L           = 0x0420);
PROVIDE(TA2EX0_H           = 0x0421);
PROVIDE(TA2IV              = 0x042E);
PROVIDE(TA2IV_L            = 0x042E);
PROVIDE(TA2IV_H            = 0x042F);


/*****************************************************************************
 TA3
*****************************************************************************/
PROVIDE(TA3CTL             = 0x0440);
PROVIDE(TA3CTL_L           = 0x0440);
PROVIDE(TA3CTL_H           = 0x0441);
PROVIDE(TA3CCTL0           = 0x0442);
PROVIDE(TA3CCTL0_L         = 0x0442);
PROVIDE(TA3CCTL0_H         = 0x0443);
PROVIDE(TA3CCTL1           = 0x0444);
PROVIDE(TA3CCTL1_L         = 0x0444);
PROVIDE(TA3CCTL1_H         = 0x0445);
PROVIDE(TA3R               = 0x0450);
PROVIDE(TA3R_L             = 0x0450);
PROVIDE(TA3R_H             = 0x0451);
PROVIDE(TA3CCR0            = 0x0452);
PROVIDE(TA3CCR0_L          = 0x0452);
PROVIDE(TA3CCR0_H          = 0x0453);
PROVIDE(TA3CCR1            = 0x0454);
PROVIDE(TA3CCR1_L          = 0x0454);
PROVIDE(TA3CCR1_H          = 0x0455);
PROVIDE(TA3EX0             = 0x0460);
PROVIDE(TA3EX0_L           = 0x0460);
PROVIDE(TA3EX0_H           = 0x0461);
PROVIDE(TA3IV              = 0x046E);
PROVIDE(TA3IV_L            = 0x046E);
PROVIDE(TA3IV_H            = 0x046F);


/*****************************************************************************
 TA4
*****************************************************************************/
PROVIDE(TA4CTL             = 0x07C0);
PROVIDE(TA4CTL_L           = 0x07C0);
PROVIDE(TA4CTL_H           = 0x07C1);
PROVIDE(TA4CCTL0           = 0x07C2);
PROVIDE(TA4CCTL0_L         = 0x07C2);
PROVIDE(TA4CCTL0_H         = 0x07C3);
PROVIDE(TA4CCTL1           = 0x07C4);
PROVIDE(TA4CCTL1_L         = 0x07C4);
PROVIDE(TA4CCTL1_H         = 0x07C5);
PROVIDE(TA4CCTL2           = 0x07C6);
PROVIDE(TA4CCTL2_L         = 0x07C6);
PROVIDE(TA4CCTL2_H         = 0x07C7);
PROVIDE(TA4R               = 0x07D0);
PROVIDE(TA4R_L             = 0x07D0);
PROVIDE(TA4R_H             = 0x07D1);
PROVIDE(TA4CCR0            = 0x07D2);
PROVIDE(TA4CCR0_L          = 0x07D2);
PROVIDE(TA4CCR0_H          = 0x07D3);
PROVIDE(TA4CCR1            = 0x07D4);
PROVIDE(TA4CCR1_L          = 0x07D4);
PROVIDE(TA4CCR1_H          = 0x07D5);
PROVIDE(TA4CCR2            = 0x07D6);
PROVIDE(TA4CCR2_L          = 0x07D6);
PROVIDE(TA4CCR2_H          = 0x07D7);
PROVIDE(TA4EX0             = 0x07E0);
PROVIDE(TA4EX0_L           = 0x07E0);
PROVIDE(TA4EX0_H           = 0x07E1);
PROVIDE(TA4IV              = 0x07EE);
PROVIDE(TA4IV_L            = 0x07EE);
PROVIDE(TA4IV_H            = 0x07EF);


/*****************************************************************************
 TB0
*****************************************************************************/
PROVIDE(TB0CTL             = 0x03C0);
PROVIDE(TB0CTL_L           = 0x03C0);
PROVIDE(TB0CTL_H           = 0x03C1);
PROVIDE(TB0CCTL0           = 0x03C2);
PROVIDE(TB0CCTL0_L         = 0x03C2);
PROVIDE(TB0CCTL0_H         = 0x03C3);
PROVIDE(TB0CCTL1           = 0x03C4);
PROVIDE(TB0CCTL1_L         = 0x03C4);
PROVIDE(TB0CCTL1_H         = 0x03C5);
PROVIDE(TB0CCTL2           = 0x03C6);
PROVIDE(TB0CCTL2_L         = 0x03C6);
PROVIDE(TB0CCTL2_H         = 0x03C7);
PROVIDE(TB0CCTL3           = 0x03C8);
PROVIDE(TB0CCTL3_L         = 0x03C8);
PROVIDE(TB0CCTL3_H         = 0x03C9);
PROVIDE(TB0CCTL4           = 0x03CA);
PROVIDE(TB0CCTL4_L         = 0x03CA);
PROVIDE(TB0CCTL4_H         = 0x03CB);
PROVIDE(TB0CCTL5           = 0x03CC);
PROVIDE(TB0CCTL5_L         = 0x03CC);
PROVIDE(TB0CCTL5_H         = 0x03CD);
PROVIDE(TB0CCTL6           = 0x03CE);
PROVIDE(TB0CCTL6_L         = 0x03CE);
PROVIDE(TB0CCTL6_H         = 0x03CF);
PROVIDE(TB0R               = 0x03D0);
PROVIDE(TB0R_L             = 0x03D0);
PROVIDE(TB0R_H             = 0x03D1);
PROVIDE(TB0CCR0            = 0x03D2);
PROVIDE(TB0CCR0_L          = 0x03D2);
PROVIDE(TB0CCR0_H          = 0x03D3);
PROVIDE(TB0CCR1            = 0x03D4);
PROVIDE(TB0CCR1_L          = 0x03D4);
PROVIDE(TB0CCR1_H          = 0x03D5);
PROVIDE(TB0CCR2            = 0x03D6);
PROVIDE(TB0CCR2_L          = 0x03D6);
PROVIDE(TB0CCR2_H          = 0x03D7);
PROVIDE(TB0CCR3            = 0x03D8);
PROVIDE(TB0CCR3_L          = 0x03D8);
PROVIDE(TB0CCR3_H          = 0x03D9);
PROVIDE(TB0CCR4            = 0x03DA);
PROVIDE(TB0CCR4_L          = 0x03DA);
PROVIDE(TB0CCR4_H          = 0x03DB);
PROVIDE(TB0CCR5            = 0x03DC);
PROVIDE(TB0CCR5_L          = 0x03DC);
PROVIDE(TB0CCR5_H          = 0x03DD);
PROVIDE(TB0CCR6            = 0x03DE);
PROVIDE(TB0CCR6_L          = 0x03DE);
PROVIDE(TB0CCR6_H          = 0x03DF);
PROVIDE(TB0EX0             = 0x03E0);
PROVIDE(TB0EX0_L           = 0x03E0);
PROVIDE(TB0EX0_H           = 0x03E1);
PROVIDE(TB0IV              = 0x03EE);
PROVIDE(TB0IV_L            = 0x03EE);
PROVIDE(TB0IV_H            = 0x03EF);


/*****************************************************************************
 WDT_A
*****************************************************************************/
PROVIDE(WDTCTL             = 0x015C);
PROVIDE(WDTCTL_L           = 0x015C);
PROVIDE(WDTCTL_H           = 0x015D);


/*****************************************************************************
 eUSCI_A0
*****************************************************************************/
PROVIDE(UCA0CTLW0          = 0x05C0);
PROVIDE(UCA0CTLW0_L        = 0x05C0);
PROVIDE(UCA0CTLW0_H        = 0x05C1);
PROVIDE(UCA0CTLW1          = 0x05C2);
PROVIDE(UCA0CTLW1_L        = 0x05C2);
PROVIDE(UCA0CTLW1_H        = 0x05C3);
PROVIDE(UCA0BRW            = 0x05C6);
PROVIDE(UCA0BRW_L          = 0x05C6);
PROVIDE(UCA0BRW_H          = 0x05C7);
PROVIDE(UCA0MCTLW          = 0x05C8);
PROVIDE(UCA0MCTLW_L        = 0x05C8);
PROVIDE(UCA0MCTLW_H        = 0x05C9);
PROVIDE(UCA0STATW          = 0x05CA);
PROVIDE(UCA0STATW_L        = 0x05CA);
PROVIDE(UCA0STATW_H        = 0x05CB);
PROVIDE(UCA0RXBUF          = 0x05CC);
PROVIDE(UCA0RXBUF_L        = 0x05CC);
PROVIDE(UCA0RXBUF_H        = 0x05CD);
PROVIDE(UCA0TXBUF          = 0x05CE);
PROVIDE(UCA0TXBUF_L        = 0x05CE);
PROVIDE(UCA0TXBUF_H        = 0x05CF);
PROVIDE(UCA0ABCTL          = 0x05D0);
PROVIDE(UCA0ABCTL_L        = 0x05D0);
PROVIDE(UCA0ABCTL_H        = 0x05D1);
PROVIDE(UCA0IRCTL          = 0x05D2);
PROVIDE(UCA0IRCTL_L        = 0x05D2);
PROVIDE(UCA0IRCTL_H        = 0x05D3);
PROVIDE(UCA0IE             = 0x05DA);
PROVIDE(UCA0IE_L           = 0x05DA);
PROVIDE(UCA0IE_H           = 0x05DB);
PROVIDE(UCA0IFG            = 0x05DC);
PROVIDE(UCA0IFG_L          = 0x05DC);
PROVIDE(UCA0IFG_H          = 0x05DD);
PROVIDE(UCA0IV             = 0x05DE);
PROVIDE(UCA0IV_L           = 0x05DE);
PROVIDE(UCA0IV_H           = 0x05DF);


/*****************************************************************************
 eUSCI_A1
*****************************************************************************/
PROVIDE(UCA1CTLW0          = 0x05E0);
PROVIDE(UCA1CTLW0_L        = 0x05E0);
PROVIDE(UCA1CTLW0_H        = 0x05E1);
PROVIDE(UCA1CTLW1          = 0x05E2);
PROVIDE(UCA1CTLW1_L        = 0x05E2);
PROVIDE(UCA1CTLW1_H        = 0x05E3);
PROVIDE(UCA1BRW            = 0x05E6);
PROVIDE(UCA1BRW_L          = 0x05E6);
PROVIDE(UCA1BRW_H          = 0x05E7);
PROVIDE(UCA1MCTLW          = 0x05E8);
PROVIDE(UCA1MCTLW_L        = 0x05E8);
PROVIDE(UCA1MCTLW_H        = 0x05E9);
PROVIDE(UCA1STATW          = 0x05EA);
PROVIDE(UCA1STATW_L        = 0x05EA);
PROVIDE(UCA1STATW_H        = 0x05EB);
PROVIDE(UCA1RXBUF          = 0x05EC);
PROVIDE(UCA1RXBUF_L        = 0x05EC);
PROVIDE(UCA1RXBUF_H        = 0x05ED);
PROVIDE(UCA1TXBUF          = 0x05EE);
PROVIDE(UCA1TXBUF_L        = 0x05EE);
PROVIDE(UCA1TXBUF_H        = 0x05EF);
PROVIDE(UCA1ABCTL          = 0x05F0);
PROVIDE(UCA1ABCTL_L        = 0x05F0);
PROVIDE(UCA1ABCTL_H        = 0x05F1);
PROVIDE(UCA1IRCTL          = 0x05F2);
PROVIDE(UCA1IRCTL_L        = 0x05F2);
PROVIDE(UCA1IRCTL_H        = 0x05F3);
PROVIDE(UCA1IE             = 0x05FA);
PROVIDE(UCA1IE_L           = 0x05FA);
PROVIDE(UCA1IE_H           = 0x05FB);
PROVIDE(UCA1IFG            = 0x05FC);
PROVIDE(UCA1IFG_L          = 0x05FC);
PROVIDE(UCA1IFG_H          = 0x05FD);
PROVIDE(UCA1IV             = 0x05FE);
PROVIDE(UCA1IV_L           = 0x05FE);
PROVIDE(UCA1IV_H           = 0x05FF);


/*****************************************************************************
 eUSCI_A2
*****************************************************************************/
PROVIDE(UCA2CTLW0          = 0x0600);
PROVIDE(UCA2CTLW0_L        = 0x0600);
PROVIDE(UCA2CTLW0_H        = 0x0601);
PROVIDE(UCA2CTLW1          = 0x0602);
PROVIDE(UCA2CTLW1_L        = 0x0602);
PROVIDE(UCA2CTLW1_H        = 0x0603);
PROVIDE(UCA2BRW            = 0x0606);
PROVIDE(UCA2BRW_L          = 0x0606);
PROVIDE(UCA2BRW_H          = 0x0607);
PROVIDE(UCA2MCTLW          = 0x0608);
PROVIDE(UCA2MCTLW_L        = 0x0608);
PROVIDE(UCA2MCTLW_H        = 0x0609);
PROVIDE(UCA2STATW          = 0x060A);
PROVIDE(UCA2STATW_L        = 0x060A);
PROVIDE(UCA2STATW_H        = 0x060B);
PROVIDE(UCA2RXBUF          = 0x060C);
PROVIDE(UCA2RXBUF_L        = 0x060C);
PROVIDE(UCA2RXBUF_H        = 0x060D);
PROVIDE(UCA2TXBUF          = 0x060E);
PROVIDE(UCA2TXBUF_L        = 0x060E);
PROVIDE(UCA2TXBUF_H        = 0x060F);
PROVIDE(UCA2ABCTL          = 0x0610);
PROVIDE(UCA2ABCTL_L        = 0x0610);
PROVIDE(UCA2ABCTL_H        = 0x0611);
PROVIDE(UCA2IRCTL          = 0x0612);
PROVIDE(UCA2IRCTL_L        = 0x0612);
PROVIDE(UCA2IRCTL_H        = 0x0613);
PROVIDE(UCA2IE             = 0x061A);
PROVIDE(UCA2IE_L           = 0x061A);
PROVIDE(UCA2IE_H           = 0x061B);
PROVIDE(UCA2IFG            = 0x061C);
PROVIDE(UCA2IFG_L          = 0x061C);
PROVIDE(UCA2IFG_H          = 0x061D);
PROVIDE(UCA2IV             = 0x061E);
PROVIDE(UCA2IV_L           = 0x061E);
PROVIDE(UCA2IV_H           = 0x061F);


/*****************************************************************************
 eUSCI_A3
*****************************************************************************/
PROVIDE(UCA3CTLW0          = 0x0620);
PROVIDE(UCA3CTLW0_L        = 0x0620);
PROVIDE(UCA3CTLW0_H        = 0x0621);
PROVIDE(UCA3CTLW1          = 0x0622);
PROVIDE(UCA3CTLW1_L        = 0x0622);
PROVIDE(UCA3CTLW1_H        = 0x0623);
PROVIDE(UCA3BRW            = 0x0626);
PROVIDE(UCA3BRW_L          = 0x0626);
PROVIDE(UCA3BRW_H          = 0x0627);
PROVIDE(UCA3MCTLW          = 0x0628);
PROVIDE(UCA3MCTLW_L        = 0x0628);
PROVIDE(UCA3MCTLW_H        = 0x0629);
PROVIDE(UCA3STATW          = 0x062A);
PROVIDE(UCA3STATW_L        = 0x062A);
PROVIDE(UCA3STATW_H        = 0x062B);
PROVIDE(UCA3RXBUF          = 0x062C);
PROVIDE(UCA3RXBUF_L        = 0x062C);
PROVIDE(UCA3RXBUF_H        = 0x062D);
PROVIDE(UCA3TXBUF          = 0x062E);
PROVIDE(UCA3TXBUF_L        = 0x062E);
PROVIDE(UCA3TXBUF_H        = 0x062F);
PROVIDE(UCA3ABCTL          = 0x0630);
PROVIDE(UCA3ABCTL_L        = 0x0630);
PROVIDE(UCA3ABCTL_H        = 0x0631);
PROVIDE(UCA3IRCTL          = 0x0632);
PROVIDE(UCA3IRCTL_L        = 0x0632);
PROVIDE(UCA3IRCTL_H        = 0x0633);
PROVIDE(UCA3IE             = 0x063A);
PROVIDE(UCA3IE_L           = 0x063A);
PROVIDE(UCA3IE_H           = 0x063B);
PROVIDE(UCA3IFG            = 0x063C);
PROVIDE(UCA3IFG_L          = 0x063C);
PROVIDE(UCA3IFG_H          = 0x063D);
PROVIDE(UCA3IV             = 0x063E);
PROVIDE(UCA3IV_L           = 0x063E);
PROVIDE(UCA3IV_H           = 0x063F);


/*****************************************************************************
 eUSCI_B0
*****************************************************************************/
PROVIDE(UCB0CTLW0          = 0x0640);
PROVIDE(UCB0CTLW0_L        = 0x0640);
PROVIDE(UCB0CTLW0_H        = 0x0641);
PROVIDE(UCB0CTLW1          = 0x0642);
PROVIDE(UCB0CTLW1_L        = 0x0642);
PROVIDE(UCB0CTLW1_H        = 0x0643);
PROVIDE(UCB0BRW            = 0x0646);
PROVIDE(UCB0BRW_L          = 0x0646);
PROVIDE(UCB0BRW_H          = 0x0647);
PROVIDE(UCB0STATW          = 0x0648);
PROVIDE(UCB0STATW_L        = 0x0648);
PROVIDE(UCB0STATW_H        = 0x0649);
PROVIDE(UCB0TBCNT          = 0x064A);
PROVIDE(UCB0TBCNT_L        = 0x064A);
PROVIDE(UCB0TBCNT_H        = 0x064B);
PROVIDE(UCB0RXBUF          = 0x064C);
PROVIDE(UCB0RXBUF_L        = 0x064C);
PROVIDE(UCB0RXBUF_H        = 0x064D);
PROVIDE(UCB0TXBUF          = 0x064E);
PROVIDE(UCB0TXBUF_L        = 0x064E);
PROVIDE(UCB0TXBUF_H        = 0x064F);
PROVIDE(UCB0I2COA0         = 0x0654);
PROVIDE(UCB0I2COA0_L       = 0x0654);
PROVIDE(UCB0I2COA0_H       = 0x0655);
PROVIDE(UCB0I2COA1         = 0x0656);
PROVIDE(UCB0I2COA1_L       = 0x0656);
PROVIDE(UCB0I2COA1_H       = 0x0657);
PROVIDE(UCB0I2COA2         = 0x0658);
PROVIDE(UCB0I2COA2_L       = 0x0658);
PROVIDE(UCB0I2COA2_H       = 0x0659);
PROVIDE(UCB0I2COA3         = 0x065A);
PROVIDE(UCB0I2COA3_L       = 0x065A);
PROVIDE(UCB0I2COA3_H       = 0x065B);
PROVIDE(UCB0ADDRX          = 0x065C);
PROVIDE(UCB0ADDRX_L        = 0x065C);
PROVIDE(UCB0ADDRX_H        = 0x065D);
PROVIDE(UCB0ADDMASK        = 0x065E);
PROVIDE(UCB0ADDMASK_L      = 0x065E);
PROVIDE(UCB0ADDMASK_H      = 0x065F);
PROVIDE(UCB0I2CSA          = 0x0660);
PROVIDE(UCB0I2CSA_L        = 0x0660);
PROVIDE(UCB0I2CSA_H        = 0x0661);
PROVIDE(UCB0IE             = 0x066A);
PROVIDE(UCB0IE_L           = 0x066A);
PROVIDE(UCB0IE_H           = 0x066B);
PROVIDE(UCB0IFG            = 0x066C);
PROVIDE(UCB0IFG_L          = 0x066C);
PROVIDE(UCB0IFG_H          = 0x066D);
PROVIDE(UCB0IV             = 0x066E);
PROVIDE(UCB0IV_L           = 0x066E);
PROVIDE(UCB0IV_H           = 0x066F);


/*****************************************************************************
 eUSCI_B1
*****************************************************************************/
PROVIDE(UCB1CTLW0          = 0x0680);
PROVIDE(UCB1CTLW0_L        = 0x0680);
PROVIDE(UCB1CTLW0_H        = 0x0681);
PROVIDE(UCB1CTLW1          = 0x0682);
PROVIDE(UCB1CTLW1_L        = 0x0682);
PROVIDE(UCB1CTLW1_H        = 0x0683);
PROVIDE(UCB1BRW            = 0x0686);
PROVIDE(UCB1BRW_L          = 0x0686);
PROVIDE(UCB1BRW_H          = 0x0687);
PROVIDE(UCB1STATW          = 0x0688);
PROVIDE(UCB1STATW_L        = 0x0688);
PROVIDE(UCB1STATW_H        = 0x0689);
PROVIDE(UCB1TBCNT          = 0x068A);
PROVIDE(UCB1TBCNT_L        = 0x068A);
PROVIDE(UCB1TBCNT_H        = 0x068B);
PROVIDE(UCB1RXBUF          = 0x068C);
PROVIDE(UCB1RXBUF_L        = 0x068C);
PROVIDE(UCB1RXBUF_H        = 0x068D);
PROVIDE(UCB1TXBUF          = 0x068E);
PROVIDE(UCB1TXBUF_L        = 0x068E);
PROVIDE(UCB1TXBUF_H        = 0x068F);
PROVIDE(UCB1I2COA0         = 0x0694);
PROVIDE(UCB1I2COA0_L       = 0x0694);
PROVIDE(UCB1I2COA0_H       = 0x0695);
PROVIDE(UCB1I2COA1         = 0x0696);
PROVIDE(UCB1I2COA1_L       = 0x0696);
PROVIDE(UCB1I2COA1_H       = 0x0697);
PROVIDE(UCB1I2COA2         = 0x0698);
PROVIDE(UCB1I2COA2_L       = 0x0698);
PROVIDE(UCB1I2COA2_H       = 0x0699);
PROVIDE(UCB1I2COA3         = 0x069A);
PROVIDE(UCB1I2COA3_L       = 0x069A);
PROVIDE(UCB1I2COA3_H       = 0x069B);
PROVIDE(UCB1ADDRX          = 0x069C);
PROVIDE(UCB1ADDRX_L        = 0x069C);
PROVIDE(UCB1ADDRX_H        = 0x069D);
PROVIDE(UCB1ADDMASK        = 0x069E);
PROVIDE(UCB1ADDMASK_L      = 0x069E);
PROVIDE(UCB1ADDMASK_H      = 0x069F);
PROVIDE(UCB1I2CSA          = 0x06A0);
PROVIDE(UCB1I2CSA_L        = 0x06A0);
PROVIDE(UCB1I2CSA_H        = 0x06A1);
PROVIDE(UCB1IE             = 0x06AA);
PROVIDE(UCB1IE_L           = 0x06AA);
PROVIDE(UCB1IE_H           = 0x06AB);
PROVIDE(UCB1IFG            = 0x06AC);
PROVIDE(UCB1IFG_L          = 0x06AC);
PROVIDE(UCB1IFG_H          = 0x06AD);
PROVIDE(UCB1IV             = 0x06AE);
PROVIDE(UCB1IV_L           = 0x06AE);
PROVIDE(UCB1IV_H           = 0x06AF);


/*****************************************************************************
 eUSCI_B2
*****************************************************************************/
PROVIDE(UCB2CTLW0          = 0x06C0);
PROVIDE(UCB2CTLW0_L        = 0x06C0);
PROVIDE(UCB2CTLW0_H        = 0x06C1);
PROVIDE(UCB2CTLW1          = 0x06C2);
PROVIDE(UCB2CTLW1_L        = 0x06C2);
PROVIDE(UCB2CTLW1_H        = 0x06C3);
PROVIDE(UCB2BRW            = 0x06C6);
PROVIDE(UCB2BRW_L          = 0x06C6);
PROVIDE(UCB2BRW_H          = 0x06C7);
PROVIDE(UCB2STATW          = 0x06C8);
PROVIDE(UCB2STATW_L        = 0x06C8);
PROVIDE(UCB2STATW_H        = 0x06C9);
PROVIDE(UCB2TBCNT          = 0x06CA);
PROVIDE(UCB2TBCNT_L        = 0x06CA);
PROVIDE(UCB2TBCNT_H        = 0x06CB);
PROVIDE(UCB2RXBUF          = 0x06CC);
PROVIDE(UCB2RXBUF_L        = 0x06CC);
PROVIDE(UCB2RXBUF_H        = 0x06CD);
PROVIDE(UCB2TXBUF          = 0x06CE);
PROVIDE(UCB2TXBUF_L        = 0x06CE);
PROVIDE(UCB2TXBUF_H        = 0x06CF);
PROVIDE(UCB2I2COA0         = 0x06D4);
PROVIDE(UCB2I2COA0_L       = 0x06D4);
PROVIDE(UCB2I2COA0_H       = 0x06D5);
PROVIDE(UCB2I2COA1         = 0x06D6);
PROVIDE(UCB2I2COA1_L       = 0x06D6);
PROVIDE(UCB2I2COA1_H       = 0x06D7);
PROVIDE(UCB2I2COA2         = 0x06D8);
PROVIDE(UCB2I2COA2_L       = 0x06D8);
PROVIDE(UCB2I2COA2_H       = 0x06D9);
PROVIDE(UCB2I2COA3         = 0x06DA);
PROVIDE(UCB2I2COA3_L       = 0x06DA);
PROVIDE(UCB2I2COA3_H       = 0x06DB);
PROVIDE(UCB2ADDRX          = 0x06DC);
PROVIDE(UCB2ADDRX_L        = 0x06DC);
PROVIDE(UCB2ADDRX_H        = 0x06DD);
PROVIDE(UCB2ADDMASK        = 0x06DE);
PROVIDE(UCB2ADDMASK_L      = 0x06DE);
PROVIDE(UCB2ADDMASK_H      = 0x06DF);
PROVIDE(UCB2I2CSA          = 0x06E0);
PROVIDE(UCB2I2CSA_L        = 0x06E0);
PROVIDE(UCB2I2CSA_H        = 0x06E1);
PROVIDE(UCB2IE             = 0x06EA);
PROVIDE(UCB2IE_L           = 0x06EA);
PROVIDE(UCB2IE_H           = 0x06EB);
PROVIDE(UCB2IFG            = 0x06EC);
PROVIDE(UCB2IFG_L          = 0x06EC);
PROVIDE(UCB2IFG_H          = 0x06ED);
PROVIDE(UCB2IV             = 0x06EE);
PROVIDE(UCB2IV_L           = 0x06EE);
PROVIDE(UCB2IV_H           = 0x06EF);


/*****************************************************************************
 eUSCI_B3
*****************************************************************************/
PROVIDE(UCB3CTLW0          = 0x0700);
PROVIDE(UCB3CTLW0_L        = 0x0700);
PROVIDE(UCB3CTLW0_H        = 0x0701);
PROVIDE(UCB3CTLW1          = 0x0702);
PROVIDE(UCB3CTLW1_L        = 0x0702);
PROVIDE(UCB3CTLW1_H        = 0x0703);
PROVIDE(UCB3BRW            = 0x0706);
PROVIDE(UCB3BRW_L          = 0x0706);
PROVIDE(UCB3BRW_H          = 0x0707);
PROVIDE(UCB3STATW          = 0x0708);
PROVIDE(UCB3STATW_L        = 0x0708);
PROVIDE(UCB3STATW_H        = 0x0709);
PROVIDE(UCB3TBCNT          = 0x070A);
PROVIDE(UCB3TBCNT_L        = 0x070A);
PROVIDE(UCB3TBCNT_H        = 0x070B);
PROVIDE(UCB3RXBUF          = 0x070C);
PROVIDE(UCB3RXBUF_L        = 0x070C);
PROVIDE(UCB3RXBUF_H        = 0x070D);
PROVIDE(UCB3TXBUF          = 0x070E);
PROVIDE(UCB3TXBUF_L        = 0x070E);
PROVIDE(UCB3TXBUF_H        = 0x070F);
PROVIDE(UCB3I2COA0         = 0x0714);
PROVIDE(UCB3I2COA0_L       = 0x0714);
PROVIDE(UCB3I2COA0_H       = 0x0715);
PROVIDE(UCB3I2COA1         = 0x0716);
PROVIDE(UCB3I2COA1_L       = 0x0716);
PROVIDE(UCB3I2COA1_H       = 0x0717);
PROVIDE(UCB3I2COA2         = 0x0718);
PROVIDE(UCB3I2COA2_L       = 0x0718);
PROVIDE(UCB3I2COA2_H       = 0x0719);
PROVIDE(UCB3I2COA3         = 0x071A);
PROVIDE(UCB3I2COA3_L       = 0x071A);
PROVIDE(UCB3I2COA3_H       = 0x071B);
PROVIDE(UCB3ADDRX          = 0x071C);
PROVIDE(UCB3ADDRX_L        = 0x071C);
PROVIDE(UCB3ADDRX_H        = 0x071D);
PROVIDE(UCB3ADDMASK        = 0x071E);
PROVIDE(UCB3ADDMASK_L      = 0x071E);
PROVIDE(UCB3ADDMASK_H      = 0x071F);
PROVIDE(UCB3I2CSA          = 0x0720);
PROVIDE(UCB3I2CSA_L        = 0x0720);
PROVIDE(UCB3I2CSA_H        = 0x0721);
PROVIDE(UCB3IE             = 0x072A);
PROVIDE(UCB3IE_L           = 0x072A);
PROVIDE(UCB3IE_H           = 0x072B);
PROVIDE(UCB3IFG            = 0x072C);
PROVIDE(UCB3IFG_L          = 0x072C);
PROVIDE(UCB3IFG_H          = 0x072D);
PROVIDE(UCB3IV             = 0x072E);
PROVIDE(UCB3IV_L           = 0x072E);
PROVIDE(UCB3IV_H           = 0x072F);

/************************************************************
* End of Modules
************************************************************/

/* ============================================================================ */
/* Copyright (c) 2016, Texas Instruments Incorporated                           */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/* This file supports MSP430FR5994 devices. */

/* Version: 1.192    (Beta-Build-Tag: #0049) */

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/


/*****************************************************************************
 ADC12_B
*****************************************************************************/
__ADC12CTL0          = 0x0800;
__ADC12CTL0_L        = 0x0800;
__ADC12CTL0_H        = 0x0801;
__ADC12CTL1          = 0x0802;
__ADC12CTL1_L        = 0x0802;
__ADC12CTL1_H        = 0x0803;
__ADC12CTL2          = 0x0804;
__ADC12CTL2_L        = 0x0804;
__ADC12CTL2_H        = 0x0805;
__ADC12CTL3          = 0x0806;
__ADC12CTL3_L        = 0x0806;
__ADC12CTL3_H        = 0x0807;
__ADC12LO            = 0x0808;
__ADC12LO_L          = 0x0808;
__ADC12LO_H          = 0x0809;
__ADC12HI            = 0x080A;
__ADC12HI_L          = 0x080A;
__ADC12HI_H          = 0x080B;
__ADC12IFGR0         = 0x080C;
__ADC12IFGR0_L       = 0x080C;
__ADC12IFGR0_H       = 0x080D;
__ADC12IFGR1         = 0x080E;
__ADC12IFGR1_L       = 0x080E;
__ADC12IFGR1_H       = 0x080F;
__ADC12IFGR2         = 0x0810;
__ADC12IFGR2_L       = 0x0810;
__ADC12IFGR2_H       = 0x0811;
__ADC12IER0          = 0x0812;
__ADC12IER0_L        = 0x0812;
__ADC12IER0_H        = 0x0813;
__ADC12IER1          = 0x0814;
__ADC12IER1_L        = 0x0814;
__ADC12IER1_H        = 0x0815;
__ADC12IER2          = 0x0816;
__ADC12IER2_L        = 0x0816;
__ADC12IER2_H        = 0x0817;
__ADC12IV            = 0x0818;
__ADC12IV_L          = 0x0818;
__ADC12IV_H          = 0x0819;
__ADC12MCTL0         = 0x0820;
__ADC12MCTL0_L       = 0x0820;
__ADC12MCTL0_H       = 0x0821;
__ADC12MCTL1         = 0x0822;
__ADC12MCTL1_L       = 0x0822;
__ADC12MCTL1_H       = 0x0823;
__ADC12MCTL2         = 0x0824;
__ADC12MCTL2_L       = 0x0824;
__ADC12MCTL2_H       = 0x0825;
__ADC12MCTL3         = 0x0826;
__ADC12MCTL3_L       = 0x0826;
__ADC12MCTL3_H       = 0x0827;
__ADC12MCTL4         = 0x0828;
__ADC12MCTL4_L       = 0x0828;
__ADC12MCTL4_H       = 0x0829;
__ADC12MCTL5         = 0x082A;
__ADC12MCTL5_L       = 0x082A;
__ADC12MCTL5_H       = 0x082B;
__ADC12MCTL6         = 0x082C;
__ADC12MCTL6_L       = 0x082C;
__ADC12MCTL6_H       = 0x082D;
__ADC12MCTL7         = 0x082E;
__ADC12MCTL7_L       = 0x082E;
__ADC12MCTL7_H       = 0x082F;
__ADC12MCTL8         = 0x0830;
__ADC12MCTL8_L       = 0x0830;
__ADC12MCTL8_H       = 0x0831;
__ADC12MCTL9         = 0x0832;
__ADC12MCTL9_L       = 0x0832;
__ADC12MCTL9_H       = 0x0833;
__ADC12MCTL10        = 0x0834;
__ADC12MCTL10_L      = 0x0834;
__ADC12MCTL10_H      = 0x0835;
__ADC12MCTL11        = 0x0836;
__ADC12MCTL11_L      = 0x0836;
__ADC12MCTL11_H      = 0x0837;
__ADC12MCTL12        = 0x0838;
__ADC12MCTL12_L      = 0x0838;
__ADC12MCTL12_H      = 0x0839;
__ADC12MCTL13        = 0x083A;
__ADC12MCTL13_L      = 0x083A;
__ADC12MCTL13_H      = 0x083B;
__ADC12MCTL14        = 0x083C;
__ADC12MCTL14_L      = 0x083C;
__ADC12MCTL14_H      = 0x083D;
__ADC12MCTL15        = 0x083E;
__ADC12MCTL15_L      = 0x083E;
__ADC12MCTL15_H      = 0x083F;
__ADC12MCTL16        = 0x0840;
__ADC12MCTL16_L      = 0x0840;
__ADC12MCTL16_H      = 0x0841;
__ADC12MCTL17        = 0x0842;
__ADC12MCTL17_L      = 0x0842;
__ADC12MCTL17_H      = 0x0843;
__ADC12MCTL18        = 0x0844;
__ADC12MCTL18_L      = 0x0844;
__ADC12MCTL18_H      = 0x0845;
__ADC12MCTL19        = 0x0846;
__ADC12MCTL19_L      = 0x0846;
__ADC12MCTL19_H      = 0x0847;
__ADC12MCTL20        = 0x0848;
__ADC12MCTL20_L      = 0x0848;
__ADC12MCTL20_H      = 0x0849;
__ADC12MCTL21        = 0x084A;
__ADC12MCTL21_L      = 0x084A;
__ADC12MCTL21_H      = 0x084B;
__ADC12MCTL22        = 0x084C;
__ADC12MCTL22_L      = 0x084C;
__ADC12MCTL22_H      = 0x084D;
__ADC12MCTL23        = 0x084E;
__ADC12MCTL23_L      = 0x084E;
__ADC12MCTL23_H      = 0x084F;
__ADC12MCTL24        = 0x0850;
__ADC12MCTL24_L      = 0x0850;
__ADC12MCTL24_H      = 0x0851;
__ADC12MCTL25        = 0x0852;
__ADC12MCTL25_L      = 0x0852;
__ADC12MCTL25_H      = 0x0853;
__ADC12MCTL26        = 0x0854;
__ADC12MCTL26_L      = 0x0854;
__ADC12MCTL26_H      = 0x0855;
__ADC12MCTL27        = 0x0856;
__ADC12MCTL27_L      = 0x0856;
__ADC12MCTL27_H      = 0x0857;
__ADC12MCTL28        = 0x0858;
__ADC12MCTL28_L      = 0x0858;
__ADC12MCTL28_H      = 0x0859;
__ADC12MCTL29        = 0x085A;
__ADC12MCTL29_L      = 0x085A;
__ADC12MCTL29_H      = 0x085B;
__ADC12MCTL30        = 0x085C;
__ADC12MCTL30_L      = 0x085C;
__ADC12MCTL30_H      = 0x085D;
__ADC12MCTL31        = 0x085E;
__ADC12MCTL31_L      = 0x085E;
__ADC12MCTL31_H      = 0x085F;
__ADC12MEM0          = 0x0860;
__ADC12MEM0_L        = 0x0860;
__ADC12MEM0_H        = 0x0861;
__ADC12MEM1          = 0x0862;
__ADC12MEM1_L        = 0x0862;
__ADC12MEM1_H        = 0x0863;
__ADC12MEM2          = 0x0864;
__ADC12MEM2_L        = 0x0864;
__ADC12MEM2_H        = 0x0865;
__ADC12MEM3          = 0x0866;
__ADC12MEM3_L        = 0x0866;
__ADC12MEM3_H        = 0x0867;
__ADC12MEM4          = 0x0868;
__ADC12MEM4_L        = 0x0868;
__ADC12MEM4_H        = 0x0869;
__ADC12MEM5          = 0x086A;
__ADC12MEM5_L        = 0x086A;
__ADC12MEM5_H        = 0x086B;
__ADC12MEM6          = 0x086C;
__ADC12MEM6_L        = 0x086C;
__ADC12MEM6_H        = 0x086D;
__ADC12MEM7          = 0x086E;
__ADC12MEM7_L        = 0x086E;
__ADC12MEM7_H        = 0x086F;
__ADC12MEM8          = 0x0870;
__ADC12MEM8_L        = 0x0870;
__ADC12MEM8_H        = 0x0871;
__ADC12MEM9          = 0x0872;
__ADC12MEM9_L        = 0x0872;
__ADC12MEM9_H        = 0x0873;
__ADC12MEM10         = 0x0874;
__ADC12MEM10_L       = 0x0874;
__ADC12MEM10_H       = 0x0875;
__ADC12MEM11         = 0x0876;
__ADC12MEM11_L       = 0x0876;
__ADC12MEM11_H       = 0x0877;
__ADC12MEM12         = 0x0878;
__ADC12MEM12_L       = 0x0878;
__ADC12MEM12_H       = 0x0879;
__ADC12MEM13         = 0x087A;
__ADC12MEM13_L       = 0x087A;
__ADC12MEM13_H       = 0x087B;
__ADC12MEM14         = 0x087C;
__ADC12MEM14_L       = 0x087C;
__ADC12MEM14_H       = 0x087D;
__ADC12MEM15         = 0x087E;
__ADC12MEM15_L       = 0x087E;
__ADC12MEM15_H       = 0x087F;
__ADC12MEM16         = 0x0880;
__ADC12MEM16_L       = 0x0880;
__ADC12MEM16_H       = 0x0881;
__ADC12MEM17         = 0x0882;
__ADC12MEM17_L       = 0x0882;
__ADC12MEM17_H       = 0x0883;
__ADC12MEM18         = 0x0884;
__ADC12MEM18_L       = 0x0884;
__ADC12MEM18_H       = 0x0885;
__ADC12MEM19         = 0x0886;
__ADC12MEM19_L       = 0x0886;
__ADC12MEM19_H       = 0x0887;
__ADC12MEM20         = 0x0888;
__ADC12MEM20_L       = 0x0888;
__ADC12MEM20_H       = 0x0889;
__ADC12MEM21         = 0x088A;
__ADC12MEM21_L       = 0x088A;
__ADC12MEM21_H       = 0x088B;
__ADC12MEM22         = 0x088C;
__ADC12MEM22_L       = 0x088C;
__ADC12MEM22_H       = 0x088D;
__ADC12MEM23         = 0x088E;
__ADC12MEM23_L       = 0x088E;
__ADC12MEM23_H       = 0x088F;
__ADC12MEM24         = 0x0890;
__ADC12MEM24_L       = 0x0890;
__ADC12MEM24_H       = 0x0891;
__ADC12MEM25         = 0x0892;
__ADC12MEM25_L       = 0x0892;
__ADC12MEM25_H       = 0x0893;
__ADC12MEM26         = 0x0894;
__ADC12MEM26_L       = 0x0894;
__ADC12MEM26_H       = 0x0895;
__ADC12MEM27         = 0x0896;
__ADC12MEM27_L       = 0x0896;
__ADC12MEM27_H       = 0x0897;
__ADC12MEM28         = 0x0898;
__ADC12MEM28_L       = 0x0898;
__ADC12MEM28_H       = 0x0899;
__ADC12MEM29         = 0x089A;
__ADC12MEM29_L       = 0x089A;
__ADC12MEM29_H       = 0x089B;
__ADC12MEM30         = 0x089C;
__ADC12MEM30_L       = 0x089C;
__ADC12MEM30_H       = 0x089D;
__ADC12MEM31         = 0x089E;
__ADC12MEM31_L       = 0x089E;
__ADC12MEM31_H       = 0x089F;


/*****************************************************************************
 AES256
*****************************************************************************/
__AESACTL0           = 0x09C0;
__AESACTL0_L         = 0x09C0;
__AESACTL0_H         = 0x09C1;
__AESACTL1           = 0x09C2;
__AESACTL1_L         = 0x09C2;
__AESACTL1_H         = 0x09C3;
__AESASTAT           = 0x09C4;
__AESASTAT_L         = 0x09C4;
__AESASTAT_H         = 0x09C5;
__AESAKEY            = 0x09C6;
__AESAKEY_L          = 0x09C6;
__AESAKEY_H          = 0x09C7;
__AESADIN            = 0x09C8;
__AESADIN_L          = 0x09C8;
__AESADIN_H          = 0x09C9;
__AESADOUT           = 0x09CA;
__AESADOUT_L         = 0x09CA;
__AESADOUT_H         = 0x09CB;
__AESAXDIN           = 0x09CC;
__AESAXDIN_L         = 0x09CC;
__AESAXDIN_H         = 0x09CD;
__AESAXIN            = 0x09CE;
__AESAXIN_L          = 0x09CE;
__AESAXIN_H          = 0x09CF;


/*****************************************************************************
 CAPTIO0
*****************************************************************************/
__CAPTIO0CTL         = 0x043E;
__CAPTIO0CTL_L       = 0x043E;
__CAPTIO0CTL_H       = 0x043F;


/*****************************************************************************
 CAPTIO1
*****************************************************************************/
__CAPTIO1CTL         = 0x047E;
__CAPTIO1CTL_L       = 0x047E;
__CAPTIO1CTL_H       = 0x047F;


/*****************************************************************************
 COMP_E
*****************************************************************************/
__CECTL0             = 0x08C0;
__CECTL0_L           = 0x08C0;
__CECTL0_H           = 0x08C1;
__CECTL1             = 0x08C2;
__CECTL1_L           = 0x08C2;
__CECTL1_H           = 0x08C3;
__CECTL2             = 0x08C4;
__CECTL2_L           = 0x08C4;
__CECTL2_H           = 0x08C5;
__CECTL3             = 0x08C6;
__CECTL3_L           = 0x08C6;
__CECTL3_H           = 0x08C7;
__CEINT              = 0x08CC;
__CEINT_L            = 0x08CC;
__CEINT_H            = 0x08CD;
__CEIV               = 0x08CE;
__CEIV_L             = 0x08CE;
__CEIV_H             = 0x08CF;


/*****************************************************************************
 CRC
*****************************************************************************/
__CRCDI              = 0x0150;
__CRCDI_L            = 0x0150;
__CRCDI_H            = 0x0151;
__CRCDIRB            = 0x0152;
__CRCDIRB_L          = 0x0152;
__CRCDIRB_H          = 0x0153;
__CRCINIRES          = 0x0154;
__CRCINIRES_L        = 0x0154;
__CRCINIRES_H        = 0x0155;
__CRCRESR            = 0x0156;
__CRCRESR_L          = 0x0156;
__CRCRESR_H          = 0x0157;


/*****************************************************************************
 CRC32
*****************************************************************************/
__CRC32DIW0          = 0x0980;
__CRC32DIW0_L        = 0x0980;
__CRC32DIW0_H        = 0x0981;
__CRC32DIW1          = 0x0982;
__CRC32DIW1_L        = 0x0982;
__CRC32DIW1_H        = 0x0983;
__CRC32DIRBW1        = 0x0984;
__CRC32DIRBW1_L      = 0x0984;
__CRC32DIRBW1_H      = 0x0985;
__CRC32DIRBW0        = 0x0986;
__CRC32DIRBW0_L      = 0x0986;
__CRC32DIRBW0_H      = 0x0987;
__CRC32INIRESW0      = 0x0988;
__CRC32INIRESW0_L    = 0x0988;
__CRC32INIRESW0_H    = 0x0989;
__CRC32INIRESW1      = 0x098A;
__CRC32INIRESW1_L    = 0x098A;
__CRC32INIRESW1_H    = 0x098B;
__CRC32RESRW1        = 0x098C;
__CRC32RESRW1_L      = 0x098C;
__CRC32RESRW1_H      = 0x098D;
__CRC32RESRW0        = 0x098E;
__CRC32RESRW0_L      = 0x098E;
__CRC32RESRW0_H      = 0x098F;
__CRC16DIW0          = 0x0990;
__CRC16DIW0_L        = 0x0990;
__CRC16DIW0_H        = 0x0991;
__CRC16DIRBW0        = 0x0996;
__CRC16DIRBW0_L      = 0x0996;
__CRC16DIRBW0_H      = 0x0997;
__CRC16INIRESW0      = 0x0998;
__CRC16INIRESW0_L    = 0x0998;
__CRC16INIRESW0_H    = 0x0999;
__CRC16RESRW0        = 0x099E;
__CRC16RESRW0_L      = 0x099E;
__CRC16RESRW0_H      = 0x099F;


/*****************************************************************************
 CS
*****************************************************************************/
__CSCTL0             = 0x0160;
__CSCTL0_L           = 0x0160;
__CSCTL0_H           = 0x0161;
__CSCTL1             = 0x0162;
__CSCTL1_L           = 0x0162;
__CSCTL1_H           = 0x0163;
__CSCTL2             = 0x0164;
__CSCTL2_L           = 0x0164;
__CSCTL2_H           = 0x0165;
__CSCTL3             = 0x0166;
__CSCTL3_L           = 0x0166;
__CSCTL3_H           = 0x0167;
__CSCTL4             = 0x0168;
__CSCTL4_L           = 0x0168;
__CSCTL4_H           = 0x0169;
__CSCTL5             = 0x016A;
__CSCTL5_L           = 0x016A;
__CSCTL5_H           = 0x016B;
__CSCTL6             = 0x016C;
__CSCTL6_L           = 0x016C;
__CSCTL6_H           = 0x016D;


/*****************************************************************************
 DIO
*****************************************************************************/
__PAIN               = 0x0200;
__PAIN_L             = 0x0200;
__PAIN_H             = 0x0201;
__PAOUT              = 0x0202;
__PAOUT_L            = 0x0202;
__PAOUT_H            = 0x0203;
__PADIR              = 0x0204;
__PADIR_L            = 0x0204;
__PADIR_H            = 0x0205;
__PAREN              = 0x0206;
__PAREN_L            = 0x0206;
__PAREN_H            = 0x0207;
__PASEL0             = 0x020A;
__PASEL0_L           = 0x020A;
__PASEL0_H           = 0x020B;
__PASEL1             = 0x020C;
__PASEL1_L           = 0x020C;
__PASEL1_H           = 0x020D;
__P1IV               = 0x020E;
__P1IV_L             = 0x020E;
__P1IV_H             = 0x020F;
__PASELC             = 0x0216;
__PASELC_L           = 0x0216;
__PASELC_H           = 0x0217;
__PAIES              = 0x0218;
__PAIES_L            = 0x0218;
__PAIES_H            = 0x0219;
__PAIE               = 0x021A;
__PAIE_L             = 0x021A;
__PAIE_H             = 0x021B;
__PAIFG              = 0x021C;
__PAIFG_L            = 0x021C;
__PAIFG_H            = 0x021D;
__P2IV               = 0x021E;
__P2IV_L             = 0x021E;
__P2IV_H             = 0x021F;
__PBIN               = 0x0220;
__PBIN_L             = 0x0220;
__PBIN_H             = 0x0221;
__PBOUT              = 0x0222;
__PBOUT_L            = 0x0222;
__PBOUT_H            = 0x0223;
__PBDIR              = 0x0224;
__PBDIR_L            = 0x0224;
__PBDIR_H            = 0x0225;
__PBREN              = 0x0226;
__PBREN_L            = 0x0226;
__PBREN_H            = 0x0227;
__PBSEL0             = 0x022A;
__PBSEL0_L           = 0x022A;
__PBSEL0_H           = 0x022B;
__PBSEL1             = 0x022C;
__PBSEL1_L           = 0x022C;
__PBSEL1_H           = 0x022D;
__P3IV               = 0x022E;
__P3IV_L             = 0x022E;
__P3IV_H             = 0x022F;
__PBSELC             = 0x0236;
__PBSELC_L           = 0x0236;
__PBSELC_H           = 0x0237;
__PBIES              = 0x0238;
__PBIES_L            = 0x0238;
__PBIES_H            = 0x0239;
__PBIE               = 0x023A;
__PBIE_L             = 0x023A;
__PBIE_H             = 0x023B;
__PBIFG              = 0x023C;
__PBIFG_L            = 0x023C;
__PBIFG_H            = 0x023D;
__P4IV               = 0x023E;
__P4IV_L             = 0x023E;
__P4IV_H             = 0x023F;
__PCIN               = 0x0240;
__PCIN_L             = 0x0240;
__PCIN_H             = 0x0241;
__PCOUT              = 0x0242;
__PCOUT_L            = 0x0242;
__PCOUT_H            = 0x0243;
__PCDIR              = 0x0244;
__PCDIR_L            = 0x0244;
__PCDIR_H            = 0x0245;
__PCREN              = 0x0246;
__PCREN_L            = 0x0246;
__PCREN_H            = 0x0247;
__PCSEL0             = 0x024A;
__PCSEL0_L           = 0x024A;
__PCSEL0_H           = 0x024B;
__PCSEL1             = 0x024C;
__PCSEL1_L           = 0x024C;
__PCSEL1_H           = 0x024D;
__P5IV               = 0x024E;
__P5IV_L             = 0x024E;
__P5IV_H             = 0x024F;
__PCSELC             = 0x0256;
__PCSELC_L           = 0x0256;
__PCSELC_H           = 0x0257;
__PCIES              = 0x0258;
__PCIES_L            = 0x0258;
__PCIES_H            = 0x0259;
__PCIE               = 0x025A;
__PCIE_L             = 0x025A;
__PCIE_H             = 0x025B;
__PCIFG              = 0x025C;
__PCIFG_L            = 0x025C;
__PCIFG_H            = 0x025D;
__P6IV               = 0x025E;
__P6IV_L             = 0x025E;
__P6IV_H             = 0x025F;
__PDIN               = 0x0260;
__PDIN_L             = 0x0260;
__PDIN_H             = 0x0261;
__PDOUT              = 0x0262;
__PDOUT_L            = 0x0262;
__PDOUT_H            = 0x0263;
__PDDIR              = 0x0264;
__PDDIR_L            = 0x0264;
__PDDIR_H            = 0x0265;
__PDREN              = 0x0266;
__PDREN_L            = 0x0266;
__PDREN_H            = 0x0267;
__PDSEL0             = 0x026A;
__PDSEL0_L           = 0x026A;
__PDSEL0_H           = 0x026B;
__PDSEL1             = 0x026C;
__PDSEL1_L           = 0x026C;
__PDSEL1_H           = 0x026D;
__P7IV               = 0x026E;
__P7IV_L             = 0x026E;
__P7IV_H             = 0x026F;
__PDSELC             = 0x0276;
__PDSELC_L           = 0x0276;
__PDSELC_H           = 0x0277;
__PDIES              = 0x0278;
__PDIES_L            = 0x0278;
__PDIES_H            = 0x0279;
__PDIE               = 0x027A;
__PDIE_L             = 0x027A;
__PDIE_H             = 0x027B;
__PDIFG              = 0x027C;
__PDIFG_L            = 0x027C;
__PDIFG_H            = 0x027D;
__P8IV               = 0x027E;
__P8IV_L             = 0x027E;
__P8IV_H             = 0x027F;
__PJIN               = 0x0320;
__PJIN_L             = 0x0320;
__PJIN_H             = 0x0321;
__PJOUT              = 0x0322;
__PJOUT_L            = 0x0322;
__PJOUT_H            = 0x0323;
__PJDIR              = 0x0324;
__PJDIR_L            = 0x0324;
__PJDIR_H            = 0x0325;
__PJREN              = 0x0326;
__PJREN_L            = 0x0326;
__PJREN_H            = 0x0327;
__PJSEL0             = 0x032A;
__PJSEL0_L           = 0x032A;
__PJSEL0_H           = 0x032B;
__PJSEL1             = 0x032C;
__PJSEL1_L           = 0x032C;
__PJSEL1_H           = 0x032D;
__PJSELC             = 0x0336;
__PJSELC_L           = 0x0336;
__PJSELC_H           = 0x0337;
__P1IN               = 0x0200;

__P2IN               = 0x0201;

__P2OUT              = 0x0203;

__P1OUT              = 0x0202;

__P1DIR              = 0x0204;

__P2DIR              = 0x0205;

__P1REN              = 0x0206;

__P2REN              = 0x0207;

__P1SEL0             = 0x020A;

__P2SEL0             = 0x020B;

__P1SEL1             = 0x020C;

__P2SEL1             = 0x020D;

__P1SELC             = 0x0216;

__P2SELC             = 0x0217;

__P1IES              = 0x0218;

__P2IES              = 0x0219;

__P1IE               = 0x021A;

__P2IE               = 0x021B;

__P1IFG              = 0x021C;

__P2IFG              = 0x021D;

__P3IN               = 0x0220;

__P4IN               = 0x0221;

__P3OUT              = 0x0222;

__P4OUT              = 0x0223;

__P3DIR              = 0x0224;

__P4DIR              = 0x0225;

__P3REN              = 0x0226;

__P4REN              = 0x0227;

__P4SEL0             = 0x022B;

__P3SEL0             = 0x022A;

__P3SEL1             = 0x022C;

__P4SEL1             = 0x022D;

__P3SELC             = 0x0236;

__P4SELC             = 0x0237;

__P3IES              = 0x0238;

__P4IES              = 0x0239;

__P3IE               = 0x023A;

__P4IE               = 0x023B;

__P3IFG              = 0x023C;

__P4IFG              = 0x023D;

__P5IN               = 0x0240;

__P6IN               = 0x0241;

__P5OUT              = 0x0242;

__P6OUT              = 0x0243;

__P5DIR              = 0x0244;

__P6DIR              = 0x0245;

__P5REN              = 0x0246;

__P6REN              = 0x0247;

__P5SEL0             = 0x024A;

__P6SEL0             = 0x024B;

__P5SEL1             = 0x024C;

__P6SEL1             = 0x024D;

__P5SELC             = 0x0256;

__P6SELC             = 0x0257;

__P5IES              = 0x0258;

__P6IES              = 0x0259;

__P5IE               = 0x025A;

__P6IE               = 0x025B;

__P5IFG              = 0x025C;

__P6IFG              = 0x025D;

__P7IN               = 0x0260;

__P8IN               = 0x0261;

__P7OUT              = 0x0262;

__P8OUT              = 0x0263;

__P7DIR              = 0x0264;

__P8DIR              = 0x0265;

__P7REN              = 0x0266;

__P8REN              = 0x0267;

__P7SEL0             = 0x026A;

__P8SEL0             = 0x026B;

__P7SEL1             = 0x026C;

__P8SEL1             = 0x026D;

__P7SELC             = 0x0276;

__P8SELC             = 0x0277;

__P7IES              = 0x0278;

__P8IES              = 0x0279;

__P7IE               = 0x027A;

__P8IE               = 0x027B;

__P7IFG              = 0x027C;

__P8IFG              = 0x027D;



/*****************************************************************************
 DMA
*****************************************************************************/
__DMACTL0            = 0x0500;
__DMACTL0_L          = 0x0500;
__DMACTL0_H          = 0x0501;
__DMACTL1            = 0x0502;
__DMACTL1_L          = 0x0502;
__DMACTL1_H          = 0x0503;
__DMACTL2            = 0x0504;
__DMACTL2_L          = 0x0504;
__DMACTL2_H          = 0x0505;
__DMACTL4            = 0x0508;
__DMACTL4_L          = 0x0508;
__DMACTL4_H          = 0x0509;
__DMAIV              = 0x050E;
__DMAIV_L            = 0x050E;
__DMAIV_H            = 0x050F;
__DMA0CTL            = 0x0510;
__DMA0CTL_L          = 0x0510;
__DMA0CTL_H          = 0x0511;
__DMA0SA             = 0x0512;
__DMA0SAL            = 0x0512;
__DMA0SAH            = 0x0514;

__DMA0DA             = 0x0516;
__DMA0DAL            = 0x0516;
__DMA0DAH            = 0x0518;

__DMA0SZ             = 0x051A;
__DMA0SZ_L           = 0x051A;
__DMA0SZ_H           = 0x051B;
__DMA1CTL            = 0x0520;
__DMA1CTL_L          = 0x0520;
__DMA1CTL_H          = 0x0521;
__DMA1SA             = 0x0522;
__DMA1SAL            = 0x0522;
__DMA1SAH            = 0x0524;

__DMA1DA             = 0x0526;
__DMA1DAL            = 0x0526;
__DMA1DAH            = 0x0528;

__DMA1SZ             = 0x052A;
__DMA1SZ_L           = 0x052A;
__DMA1SZ_H           = 0x052B;
__DMA2CTL            = 0x0530;
__DMA2CTL_L          = 0x0530;
__DMA2CTL_H          = 0x0531;
__DMA2SA             = 0x0532;
__DMA2SAL            = 0x0532;
__DMA2SAH            = 0x0534;

__DMA2DA             = 0x0536;
__DMA2DAL            = 0x0536;
__DMA2DAH            = 0x0538;

__DMA2SZ             = 0x053A;
__DMA2SZ_L           = 0x053A;
__DMA2SZ_H           = 0x053B;
__DMA3CTL            = 0x0540;
__DMA3CTL_L          = 0x0540;
__DMA3CTL_H          = 0x0541;
__DMA3SA             = 0x0542;
__DMA3SAL            = 0x0542;
__DMA3SAH            = 0x0544;

__DMA3DA             = 0x0546;
__DMA3DAL            = 0x0546;
__DMA3DAH            = 0x0548;

__DMA3SZ             = 0x054A;
__DMA3SZ_L           = 0x054A;
__DMA3SZ_H           = 0x054B;
__DMA4CTL            = 0x0550;
__DMA4CTL_L          = 0x0550;
__DMA4CTL_H          = 0x0551;
__DMA4SA             = 0x0552;
__DMA4SAL            = 0x0552;
__DMA4SAH            = 0x0554;

__DMA4DA             = 0x0556;
__DMA4DAL            = 0x0556;
__DMA4DAH            = 0x0558;

__DMA4SZ             = 0x055A;
__DMA4SZ_L           = 0x055A;
__DMA4SZ_H           = 0x055B;
__DMA5CTL            = 0x0560;
__DMA5CTL_L          = 0x0560;
__DMA5CTL_H          = 0x0561;
__DMA5SA             = 0x0562;
__DMA5SAL            = 0x0562;
__DMA5SAH            = 0x0564;

__DMA5DA             = 0x0566;
__DMA5DAL            = 0x0566;
__DMA5DAH            = 0x0568;

__DMA5SZ             = 0x056A;
__DMA5SZ_L           = 0x056A;
__DMA5SZ_H           = 0x056B;


/*****************************************************************************
 FRCTL_A
*****************************************************************************/
__FRCTL0             = 0x0140;
__FRCTL0_L           = 0x0140;
__FRCTL0_H           = 0x0141;
__GCCTL0             = 0x0144;
__GCCTL0_L           = 0x0144;
__GCCTL0_H           = 0x0145;
__GCCTL1             = 0x0146;
__GCCTL1_L           = 0x0146;
__GCCTL1_H           = 0x0147;


/*****************************************************************************
 LEA
*****************************************************************************/
__LEACAP             = 0x0A80;
__LEACAPL            = 0x0A80;
__LEACAPH            = 0x0A82;

__LEACNF0            = 0x0A84;
__LEACNF0L           = 0x0A84;
__LEACNF0H           = 0x0A86;

__LEACNF1            = 0x0A88;
__LEACNF1L           = 0x0A88;
__LEACNF1H           = 0x0A8A;

__LEACNF2            = 0x0A8C;
__LEACNF2L           = 0x0A8C;
__LEACNF2H           = 0x0A8E;

__LEAMB              = 0x0A90;
__LEAMBL             = 0x0A90;
__LEAMBH             = 0x0A92;

__LEAMT              = 0x0A94;
__LEAMTL             = 0x0A94;
__LEAMTH             = 0x0A96;

__LEACMA             = 0x0A98;
__LEACMAL            = 0x0A98;
__LEACMAH            = 0x0A9A;

__LEACMCTL           = 0x0A9C;
__LEACMCTLL          = 0x0A9C;
__LEACMCTLH          = 0x0A9E;

__LEACMDSTAT         = 0x0AA8;
__LEACMDSTATL        = 0x0AA8;
__LEACMDSTATH        = 0x0AAA;

__LEAS1STAT          = 0x0AAC;
__LEAS1STATL         = 0x0AAC;
__LEAS1STATH         = 0x0AAE;

__LEAS0STAT          = 0x0AB0;
__LEAS0STATL         = 0x0AB0;
__LEAS0STATH         = 0x0AB2;

__LEADSTSTAT         = 0x0AB4;
__LEADSTSTATL        = 0x0AB4;
__LEADSTSTATH        = 0x0AB6;

__LEAPMCTL           = 0x0AC0;
__LEAPMCTLL          = 0x0AC0;
__LEAPMCTLH          = 0x0AC2;

__LEAPMDST           = 0x0AC4;
__LEAPMDSTL          = 0x0AC4;
__LEAPMDSTH          = 0x0AC6;

__LEAPMS1            = 0x0AC8;
__LEAPMS1L           = 0x0AC8;
__LEAPMS1H           = 0x0ACA;

__LEAPMS0            = 0x0ACC;
__LEAPMS0L           = 0x0ACC;
__LEAPMS0H           = 0x0ACE;

__LEAPMCB            = 0x0AD0;
__LEAPMCBL           = 0x0AD0;
__LEAPMCBH           = 0x0AD2;

__LEAIFGSET          = 0x0AF0;
__LEAIFGSETL         = 0x0AF0;
__LEAIFGSETH         = 0x0AF2;

__LEAIE              = 0x0AF4;
__LEAIEL             = 0x0AF4;
__LEAIEH             = 0x0AF6;

__LEAIFG             = 0x0AF8;
__LEAIFGL            = 0x0AF8;
__LEAIFGH            = 0x0AFA;

__LEAIV              = 0x0AFC;
__LEAIVL             = 0x0AFC;
__LEAIVH             = 0x0AFE;



/*****************************************************************************
 MPU
*****************************************************************************/
__MPUCTL0            = 0x05A0;
__MPUCTL0_L          = 0x05A0;
__MPUCTL0_H          = 0x05A1;
__MPUCTL1            = 0x05A2;
__MPUCTL1_L          = 0x05A2;
__MPUCTL1_H          = 0x05A3;
__MPUSEGB2           = 0x05A4;
__MPUSEGB2_L         = 0x05A4;
__MPUSEGB2_H         = 0x05A5;
__MPUSEGB1           = 0x05A6;
__MPUSEGB1_L         = 0x05A6;
__MPUSEGB1_H         = 0x05A7;
__MPUSAM             = 0x05A8;
__MPUSAM_L           = 0x05A8;
__MPUSAM_H           = 0x05A9;
__MPUIPC0            = 0x05AA;
__MPUIPC0_L          = 0x05AA;
__MPUIPC0_H          = 0x05AB;
__MPUIPSEGB2         = 0x05AC;
__MPUIPSEGB2_L       = 0x05AC;
__MPUIPSEGB2_H       = 0x05AD;
__MPUIPSEGB1         = 0x05AE;
__MPUIPSEGB1_L       = 0x05AE;
__MPUIPSEGB1_H       = 0x05AF;


/*****************************************************************************
 MPY32
*****************************************************************************/
__MPY                = 0x04C0;
__MPY_L              = 0x04C0;
__MPY_H              = 0x04C1;
__MPYS               = 0x04C2;
__MPYS_L             = 0x04C2;
__MPYS_H             = 0x04C3;
__MAC                = 0x04C4;
__MAC_L              = 0x04C4;
__MAC_H              = 0x04C5;
__MACS               = 0x04C6;
__MACS_L             = 0x04C6;
__MACS_H             = 0x04C7;
__OP2                = 0x04C8;
__OP2_L              = 0x04C8;
__OP2_H              = 0x04C9;
__RESLO              = 0x04CA;
__RESLO_L            = 0x04CA;
__RESLO_H            = 0x04CB;
__RESHI              = 0x04CC;
__RESHI_L            = 0x04CC;
__RESHI_H            = 0x04CD;
__SUMEXT             = 0x04CE;
__SUMEXT_L           = 0x04CE;
__SUMEXT_H           = 0x04CF;
__MPY32L             = 0x04D0;
__MPY32L_L           = 0x04D0;
__MPY32L_H           = 0x04D1;
__MPY32H             = 0x04D2;
__MPY32H_L           = 0x04D2;
__MPY32H_H           = 0x04D3;
__MPYS32L            = 0x04D4;
__MPYS32L_L          = 0x04D4;
__MPYS32L_H          = 0x04D5;
__MPYS32H            = 0x04D6;
__MPYS32H_L          = 0x04D6;
__MPYS32H_H          = 0x04D7;
__MAC32L             = 0x04D8;
__MAC32L_L           = 0x04D8;
__MAC32L_H           = 0x04D9;
__MAC32H             = 0x04DA;
__MAC32H_L           = 0x04DA;
__MAC32H_H           = 0x04DB;
__MACS32L            = 0x04DC;
__MACS32L_L          = 0x04DC;
__MACS32L_H          = 0x04DD;
__MACS32H            = 0x04DE;
__MACS32H_L          = 0x04DE;
__MACS32H_H          = 0x04DF;
__OP2L               = 0x04E0;
__OP2L_L             = 0x04E0;
__OP2L_H             = 0x04E1;
__OP2H               = 0x04E2;
__OP2H_L             = 0x04E2;
__OP2H_H             = 0x04E3;
__RES0               = 0x04E4;
__RES0_L             = 0x04E4;
__RES0_H             = 0x04E5;
__RES1               = 0x04E6;
__RES1_L             = 0x04E6;
__RES1_H             = 0x04E7;
__RES2               = 0x04E8;
__RES2_L             = 0x04E8;
__RES2_H             = 0x04E9;
__RES3               = 0x04EA;
__RES3_L             = 0x04EA;
__RES3_H             = 0x04EB;
__MPY32CTL0          = 0x04EC;
__MPY32CTL0_L        = 0x04EC;
__MPY32CTL0_H        = 0x04ED;


/*****************************************************************************
 PMM
*****************************************************************************/
__PMMCTL0            = 0x0120;
__PMMCTL0_L          = 0x0120;
__PMMCTL0_H          = 0x0121;
__PMMIFG             = 0x012A;
__PMMIFG_L           = 0x012A;
__PMMIFG_H           = 0x012B;
__PM5CTL0            = 0x0130;
__PM5CTL0_L          = 0x0130;
__PM5CTL0_H          = 0x0131;


/*****************************************************************************
 RAMCTL
*****************************************************************************/
__RCCTL0             = 0x0158;
__RCCTL0_L           = 0x0158;
__RCCTL0_H           = 0x0159;


/*****************************************************************************
 REF_A
*****************************************************************************/
__REFCTL0            = 0x01B0;
__REFCTL0_L          = 0x01B0;
__REFCTL0_H          = 0x01B1;


/*****************************************************************************
 RTC_C
*****************************************************************************/
__RTCCTL0            = 0x04A0;
__RTCCTL0_L          = 0x04A0;
__RTCCTL0_H          = 0x04A1;
__RTCCTL13           = 0x04A2;
__RTCCTL13_L         = 0x04A2;
__RTCCTL13_H         = 0x04A3;
__RTCOCAL            = 0x04A4;
__RTCOCAL_L          = 0x04A4;
__RTCOCAL_H          = 0x04A5;
__RTCTCMP            = 0x04A6;
__RTCTCMP_L          = 0x04A6;
__RTCTCMP_H          = 0x04A7;
__RTCPS0CTL          = 0x04A8;
__RTCPS0CTL_L        = 0x04A8;
__RTCPS0CTL_H        = 0x04A9;
__RTCPS1CTL          = 0x04AA;
__RTCPS1CTL_L        = 0x04AA;
__RTCPS1CTL_H        = 0x04AB;
__RTCPS              = 0x04AC;
__RTCPS_L            = 0x04AC;
__RTCPS_H            = 0x04AD;
__RTCIV              = 0x04AE;
__RTCIV_L            = 0x04AE;
__RTCIV_H            = 0x04AF;
__RTCTIM0            = 0x04B0;
__RTCTIM0_L          = 0x04B0;
__RTCTIM0_H          = 0x04B1;
__RTCCNT12           = 0x04B0;
__RTCCNT12_L         = 0x04B0;
__RTCCNT12_H         = 0x04B1;
__RTCTIM1            = 0x04B2;
__RTCTIM1_L          = 0x04B2;
__RTCTIM1_H          = 0x04B3;
__RTCCNT34           = 0x04B2;
__RTCCNT34_L         = 0x04B2;
__RTCCNT34_H         = 0x04B3;
__RTCDATE            = 0x04B4;
__RTCDATE_L          = 0x04B4;
__RTCDATE_H          = 0x04B5;
__RTCYEAR            = 0x04B6;
__RTCYEAR_L          = 0x04B6;
__RTCYEAR_H          = 0x04B7;
__RTCAMINHR          = 0x04B8;
__RTCAMINHR_L        = 0x04B8;
__RTCAMINHR_H        = 0x04B9;
__RTCADOWDAY         = 0x04BA;
__RTCADOWDAY_L       = 0x04BA;
__RTCADOWDAY_H       = 0x04BB;
__BIN2BCD            = 0x04BC;
__BIN2BCD_L          = 0x04BC;
__BIN2BCD_H          = 0x04BD;
__BCD2BIN            = 0x04BE;
__BCD2BIN_L          = 0x04BE;
__BCD2BIN_H          = 0x04BF;
__RT0PS              = 0x04AC;

__RT1PS              = 0x04AD;

__RTCCNT1            = 0x04B0;

__RTCCNT2            = 0x04B1;

__RTCCNT3            = 0x04B2;

__RTCCNT4            = 0x04B3;



/*****************************************************************************
 SFR
*****************************************************************************/
__SFRIE1             = 0x0100;
__SFRIE1_L           = 0x0100;
__SFRIE1_H           = 0x0101;
__SFRIFG1            = 0x0102;
__SFRIFG1_L          = 0x0102;
__SFRIFG1_H          = 0x0103;
__SFRRPCR            = 0x0104;
__SFRRPCR_L          = 0x0104;
__SFRRPCR_H          = 0x0105;


/*****************************************************************************
 SYS
*****************************************************************************/
__SYSCTL             = 0x0180;
__SYSCTL_L           = 0x0180;
__SYSCTL_H           = 0x0181;
__SYSJMBC            = 0x0186;
__SYSJMBC_L          = 0x0186;
__SYSJMBC_H          = 0x0187;
__SYSJMBI0           = 0x0188;
__SYSJMBI0_L         = 0x0188;
__SYSJMBI0_H         = 0x0189;
__SYSJMBI1           = 0x018A;
__SYSJMBI1_L         = 0x018A;
__SYSJMBI1_H         = 0x018B;
__SYSJMBO0           = 0x018C;
__SYSJMBO0_L         = 0x018C;
__SYSJMBO0_H         = 0x018D;
__SYSJMBO1           = 0x018E;
__SYSJMBO1_L         = 0x018E;
__SYSJMBO1_H         = 0x018F;
__SYSUNIV            = 0x019A;
__SYSUNIV_L          = 0x019A;
__SYSUNIV_H          = 0x019B;
__SYSSNIV            = 0x019C;
__SYSSNIV_L          = 0x019C;
__SYSSNIV_H          = 0x019D;
__SYSRSTIV           = 0x019E;
__SYSRSTIV_L         = 0x019E;
__SYSRSTIV_H         = 0x019F;


/*****************************************************************************
 TA0
*****************************************************************************/
__TA0CTL             = 0x0340;
__TA0CTL_L           = 0x0340;
__TA0CTL_H           = 0x0341;
__TA0CCTL0           = 0x0342;
__TA0CCTL0_L         = 0x0342;
__TA0CCTL0_H         = 0x0343;
__TA0CCTL1           = 0x0344;
__TA0CCTL1_L         = 0x0344;
__TA0CCTL1_H         = 0x0345;
__TA0CCTL2           = 0x0346;
__TA0CCTL2_L         = 0x0346;
__TA0CCTL2_H         = 0x0347;
__TA0R               = 0x0350;
__TA0R_L             = 0x0350;
__TA0R_H             = 0x0351;
__TA0CCR0            = 0x0352;
__TA0CCR0_L          = 0x0352;
__TA0CCR0_H          = 0x0353;
__TA0CCR1            = 0x0354;
__TA0CCR1_L          = 0x0354;
__TA0CCR1_H          = 0x0355;
__TA0CCR2            = 0x0356;
__TA0CCR2_L          = 0x0356;
__TA0CCR2_H          = 0x0357;
__TA0EX0             = 0x0360;
__TA0EX0_L           = 0x0360;
__TA0EX0_H           = 0x0361;
__TA0IV              = 0x036E;
__TA0IV_L            = 0x036E;
__TA0IV_H            = 0x036F;


/*****************************************************************************
 TA1
*****************************************************************************/
__TA1CTL             = 0x0380;
__TA1CTL_L           = 0x0380;
__TA1CTL_H           = 0x0381;
__TA1CCTL0           = 0x0382;
__TA1CCTL0_L         = 0x0382;
__TA1CCTL0_H         = 0x0383;
__TA1CCTL1           = 0x0384;
__TA1CCTL1_L         = 0x0384;
__TA1CCTL1_H         = 0x0385;
__TA1CCTL2           = 0x0386;
__TA1CCTL2_L         = 0x0386;
__TA1CCTL2_H         = 0x0387;
__TA1R               = 0x0390;
__TA1R_L             = 0x0390;
__TA1R_H             = 0x0391;
__TA1CCR0            = 0x0392;
__TA1CCR0_L          = 0x0392;
__TA1CCR0_H          = 0x0393;
__TA1CCR1            = 0x0394;
__TA1CCR1_L          = 0x0394;
__TA1CCR1_H          = 0x0395;
__TA1CCR2            = 0x0396;
__TA1CCR2_L          = 0x0396;
__TA1CCR2_H          = 0x0397;
__TA1EX0             = 0x03A0;
__TA1EX0_L           = 0x03A0;
__TA1EX0_H           = 0x03A1;
__TA1IV              = 0x03AE;
__TA1IV_L            = 0x03AE;
__TA1IV_H            = 0x03AF;


/*****************************************************************************
 TA2
*****************************************************************************/
__TA2CTL             = 0x0400;
__TA2CTL_L           = 0x0400;
__TA2CTL_H           = 0x0401;
__TA2CCTL0           = 0x0402;
__TA2CCTL0_L         = 0x0402;
__TA2CCTL0_H         = 0x0403;
__TA2CCTL1           = 0x0404;
__TA2CCTL1_L         = 0x0404;
__TA2CCTL1_H         = 0x0405;
__TA2R               = 0x0410;
__TA2R_L             = 0x0410;
__TA2R_H             = 0x0411;
__TA2CCR0            = 0x0412;
__TA2CCR0_L          = 0x0412;
__TA2CCR0_H          = 0x0413;
__TA2CCR1            = 0x0414;
__TA2CCR1_L          = 0x0414;
__TA2CCR1_H          = 0x0415;
__TA2EX0             = 0x0420;
__TA2EX0_L           = 0x0420;
__TA2EX0_H           = 0x0421;
__TA2IV              = 0x042E;
__TA2IV_L            = 0x042E;
__TA2IV_H            = 0x042F;


/*****************************************************************************
 TA3
*****************************************************************************/
__TA3CTL             = 0x0440;
__TA3CTL_L           = 0x0440;
__TA3CTL_H           = 0x0441;
__TA3CCTL0           = 0x0442;
__TA3CCTL0_L         = 0x0442;
__TA3CCTL0_H         = 0x0443;
__TA3CCTL1           = 0x0444;
__TA3CCTL1_L         = 0x0444;
__TA3CCTL1_H         = 0x0445;
__TA3R               = 0x0450;
__TA3R_L             = 0x0450;
__TA3R_H             = 0x0451;
__TA3CCR0            = 0x0452;
__TA3CCR0_L          = 0x0452;
__TA3CCR0_H          = 0x0453;
__TA3CCR1            = 0x0454;
__TA3CCR1_L          = 0x0454;
__TA3CCR1_H          = 0x0455;
__TA3EX0             = 0x0460;
__TA3EX0_L           = 0x0460;
__TA3EX0_H           = 0x0461;
__TA3IV              = 0x046E;
__TA3IV_L            = 0x046E;
__TA3IV_H            = 0x046F;


/*****************************************************************************
 TA4
*****************************************************************************/
__TA4CTL             = 0x07C0;
__TA4CTL_L           = 0x07C0;
__TA4CTL_H           = 0x07C1;
__TA4CCTL0           = 0x07C2;
__TA4CCTL0_L         = 0x07C2;
__TA4CCTL0_H         = 0x07C3;
__TA4CCTL1           = 0x07C4;
__TA4CCTL1_L         = 0x07C4;
__TA4CCTL1_H         = 0x07C5;
__TA4CCTL2           = 0x07C6;
__TA4CCTL2_L         = 0x07C6;
__TA4CCTL2_H         = 0x07C7;
__TA4R               = 0x07D0;
__TA4R_L             = 0x07D0;
__TA4R_H             = 0x07D1;
__TA4CCR0            = 0x07D2;
__TA4CCR0_L          = 0x07D2;
__TA4CCR0_H          = 0x07D3;
__TA4CCR1            = 0x07D4;
__TA4CCR1_L          = 0x07D4;
__TA4CCR1_H          = 0x07D5;
__TA4CCR2            = 0x07D6;
__TA4CCR2_L          = 0x07D6;
__TA4CCR2_H          = 0x07D7;
__TA4EX0             = 0x07E0;
__TA4EX0_L           = 0x07E0;
__TA4EX0_H           = 0x07E1;
__TA4IV              = 0x07EE;
__TA4IV_L            = 0x07EE;
__TA4IV_H            = 0x07EF;


/*****************************************************************************
 TB0
*****************************************************************************/
__TB0CTL             = 0x03C0;
__TB0CTL_L           = 0x03C0;
__TB0CTL_H           = 0x03C1;
__TB0CCTL0           = 0x03C2;
__TB0CCTL0_L         = 0x03C2;
__TB0CCTL0_H         = 0x03C3;
__TB0CCTL1           = 0x03C4;
__TB0CCTL1_L         = 0x03C4;
__TB0CCTL1_H         = 0x03C5;
__TB0CCTL2           = 0x03C6;
__TB0CCTL2_L         = 0x03C6;
__TB0CCTL2_H         = 0x03C7;
__TB0CCTL3           = 0x03C8;
__TB0CCTL3_L         = 0x03C8;
__TB0CCTL3_H         = 0x03C9;
__TB0CCTL4           = 0x03CA;
__TB0CCTL4_L         = 0x03CA;
__TB0CCTL4_H         = 0x03CB;
__TB0CCTL5           = 0x03CC;
__TB0CCTL5_L         = 0x03CC;
__TB0CCTL5_H         = 0x03CD;
__TB0CCTL6           = 0x03CE;
__TB0CCTL6_L         = 0x03CE;
__TB0CCTL6_H         = 0x03CF;
__TB0R               = 0x03D0;
__TB0R_L             = 0x03D0;
__TB0R_H             = 0x03D1;
__TB0CCR0            = 0x03D2;
__TB0CCR0_L          = 0x03D2;
__TB0CCR0_H          = 0x03D3;
__TB0CCR1            = 0x03D4;
__TB0CCR1_L          = 0x03D4;
__TB0CCR1_H          = 0x03D5;
__TB0CCR2            = 0x03D6;
__TB0CCR2_L          = 0x03D6;
__TB0CCR2_H          = 0x03D7;
__TB0CCR3            = 0x03D8;
__TB0CCR3_L          = 0x03D8;
__TB0CCR3_H          = 0x03D9;
__TB0CCR4            = 0x03DA;
__TB0CCR4_L          = 0x03DA;
__TB0CCR4_H          = 0x03DB;
__TB0CCR5            = 0x03DC;
__TB0CCR5_L          = 0x03DC;
__TB0CCR5_H          = 0x03DD;
__TB0CCR6            = 0x03DE;
__TB0CCR6_L          = 0x03DE;
__TB0CCR6_H          = 0x03DF;
__TB0EX0             = 0x03E0;
__TB0EX0_L           = 0x03E0;
__TB0EX0_H           = 0x03E1;
__TB0IV              = 0x03EE;
__TB0IV_L            = 0x03EE;
__TB0IV_H            = 0x03EF;


/*****************************************************************************
 WDT_A
*****************************************************************************/
__WDTCTL             = 0x015C;
__WDTCTL_L           = 0x015C;
__WDTCTL_H           = 0x015D;


/*****************************************************************************
 eUSCI_A0
*****************************************************************************/
__UCA0CTLW0          = 0x05C0;
__UCA0CTLW0_L        = 0x05C0;
__UCA0CTLW0_H        = 0x05C1;
__UCA0CTLW1          = 0x05C2;
__UCA0CTLW1_L        = 0x05C2;
__UCA0CTLW1_H        = 0x05C3;
__UCA0BRW            = 0x05C6;
__UCA0BRW_L          = 0x05C6;
__UCA0BRW_H          = 0x05C7;
__UCA0MCTLW          = 0x05C8;
__UCA0MCTLW_L        = 0x05C8;
__UCA0MCTLW_H        = 0x05C9;
__UCA0STATW          = 0x05CA;
__UCA0STATW_L        = 0x05CA;
__UCA0STATW_H        = 0x05CB;
__UCA0RXBUF          = 0x05CC;
__UCA0RXBUF_L        = 0x05CC;
__UCA0RXBUF_H        = 0x05CD;
__UCA0TXBUF          = 0x05CE;
__UCA0TXBUF_L        = 0x05CE;
__UCA0TXBUF_H        = 0x05CF;
__UCA0ABCTL          = 0x05D0;
__UCA0ABCTL_L        = 0x05D0;
__UCA0ABCTL_H        = 0x05D1;
__UCA0IRCTL          = 0x05D2;
__UCA0IRCTL_L        = 0x05D2;
__UCA0IRCTL_H        = 0x05D3;
__UCA0IE             = 0x05DA;
__UCA0IE_L           = 0x05DA;
__UCA0IE_H           = 0x05DB;
__UCA0IFG            = 0x05DC;
__UCA0IFG_L          = 0x05DC;
__UCA0IFG_H          = 0x05DD;
__UCA0IV             = 0x05DE;
__UCA0IV_L           = 0x05DE;
__UCA0IV_H           = 0x05DF;


/*****************************************************************************
 eUSCI_A1
*****************************************************************************/
__UCA1CTLW0          = 0x05E0;
__UCA1CTLW0_L        = 0x05E0;
__UCA1CTLW0_H        = 0x05E1;
__UCA1CTLW1          = 0x05E2;
__UCA1CTLW1_L        = 0x05E2;
__UCA1CTLW1_H        = 0x05E3;
__UCA1BRW            = 0x05E6;
__UCA1BRW_L          = 0x05E6;
__UCA1BRW_H          = 0x05E7;
__UCA1MCTLW          = 0x05E8;
__UCA1MCTLW_L        = 0x05E8;
__UCA1MCTLW_H        = 0x05E9;
__UCA1STATW          = 0x05EA;
__UCA1STATW_L        = 0x05EA;
__UCA1STATW_H        = 0x05EB;
__UCA1RXBUF          = 0x05EC;
__UCA1RXBUF_L        = 0x05EC;
__UCA1RXBUF_H        = 0x05ED;
__UCA1TXBUF          = 0x05EE;
__UCA1TXBUF_L        = 0x05EE;
__UCA1TXBUF_H        = 0x05EF;
__UCA1ABCTL          = 0x05F0;
__UCA1ABCTL_L        = 0x05F0;
__UCA1ABCTL_H        = 0x05F1;
__UCA1IRCTL          = 0x05F2;
__UCA1IRCTL_L        = 0x05F2;
__UCA1IRCTL_H        = 0x05F3;
__UCA1IE             = 0x05FA;
__UCA1IE_L           = 0x05FA;
__UCA1IE_H           = 0x05FB;
__UCA1IFG            = 0x05FC;
__UCA1IFG_L          = 0x05FC;
__UCA1IFG_H          = 0x05FD;
__UCA1IV             = 0x05FE;
__UCA1IV_L           = 0x05FE;
__UCA1IV_H           = 0x05FF;


/*****************************************************************************
 eUSCI_A2
*****************************************************************************/
__UCA2CTLW0          = 0x0600;
__UCA2CTLW0_L        = 0x0600;
__UCA2CTLW0_H        = 0x0601;
__UCA2CTLW1          = 0x0602;
__UCA2CTLW1_L        = 0x0602;
__UCA2CTLW1_H        = 0x0603;
__UCA2BRW            = 0x0606;
__UCA2BRW_L          = 0x0606;
__UCA2BRW_H          = 0x0607;
__UCA2MCTLW          = 0x0608;
__UCA2MCTLW_L        = 0x0608;
__UCA2MCTLW_H        = 0x0609;
__UCA2STATW          = 0x060A;
__UCA2STATW_L        = 0x060A;
__UCA2STATW_H        = 0x060B;
__UCA2RXBUF          = 0x060C;
__UCA2RXBUF_L        = 0x060C;
__UCA2RXBUF_H        = 0x060D;
__UCA2TXBUF          = 0x060E;
__UCA2TXBUF_L        = 0x060E;
__UCA2TXBUF_H        = 0x060F;
__UCA2ABCTL          = 0x0610;
__UCA2ABCTL_L        = 0x0610;
__UCA2ABCTL_H        = 0x0611;
__UCA2IRCTL          = 0x0612;
__UCA2IRCTL_L        = 0x0612;
__UCA2IRCTL_H        = 0x0613;
__UCA2IE             = 0x061A;
__UCA2IE_L           = 0x061A;
__UCA2IE_H           = 0x061B;
__UCA2IFG            = 0x061C;
__UCA2IFG_L          = 0x061C;
__UCA2IFG_H          = 0x061D;
__UCA2IV             = 0x061E;
__UCA2IV_L           = 0x061E;
__UCA2IV_H           = 0x061F;


/*****************************************************************************
 eUSCI_A3
*****************************************************************************/
__UCA3CTLW0          = 0x0620;
__UCA3CTLW0_L        = 0x0620;
__UCA3CTLW0_H        = 0x0621;
__UCA3CTLW1          = 0x0622;
__UCA3CTLW1_L        = 0x0622;
__UCA3CTLW1_H        = 0x0623;
__UCA3BRW            = 0x0626;
__UCA3BRW_L          = 0x0626;
__UCA3BRW_H          = 0x0627;
__UCA3MCTLW          = 0x0628;
__UCA3MCTLW_L        = 0x0628;
__UCA3MCTLW_H        = 0x0629;
__UCA3STATW          = 0x062A;
__UCA3STATW_L        = 0x062A;
__UCA3STATW_H        = 0x062B;
__UCA3RXBUF          = 0x062C;
__UCA3RXBUF_L        = 0x062C;
__UCA3RXBUF_H        = 0x062D;
__UCA3TXBUF          = 0x062E;
__UCA3TXBUF_L        = 0x062E;
__UCA3TXBUF_H        = 0x062F;
__UCA3ABCTL          = 0x0630;
__UCA3ABCTL_L        = 0x0630;
__UCA3ABCTL_H        = 0x0631;
__UCA3IRCTL          = 0x0632;
__UCA3IRCTL_L        = 0x0632;
__UCA3IRCTL_H        = 0x0633;
__UCA3IE             = 0x063A;
__UCA3IE_L           = 0x063A;
__UCA3IE_H           = 0x063B;
__UCA3IFG            = 0x063C;
__UCA3IFG_L          = 0x063C;
__UCA3IFG_H          = 0x063D;
__UCA3IV             = 0x063E;
__UCA3IV_L           = 0x063E;
__UCA3IV_H           = 0x063F;


/*****************************************************************************
 eUSCI_B0
*****************************************************************************/
__UCB0CTLW0          = 0x0640;
__UCB0CTLW0_L        = 0x0640;
__UCB0CTLW0_H        = 0x0641;
__UCB0CTLW1          = 0x0642;
__UCB0CTLW1_L        = 0x0642;
__UCB0CTLW1_H        = 0x0643;
__UCB0BRW            = 0x0646;
__UCB0BRW_L          = 0x0646;
__UCB0BRW_H          = 0x0647;
__UCB0STATW          = 0x0648;
__UCB0STATW_L        = 0x0648;
__UCB0STATW_H        = 0x0649;
__UCB0TBCNT          = 0x064A;
__UCB0TBCNT_L        = 0x064A;
__UCB0TBCNT_H        = 0x064B;
__UCB0RXBUF          = 0x064C;
__UCB0RXBUF_L        = 0x064C;
__UCB0RXBUF_H        = 0x064D;
__UCB0TXBUF          = 0x064E;
__UCB0TXBUF_L        = 0x064E;
__UCB0TXBUF_H        = 0x064F;
__UCB0I2COA0         = 0x0654;
__UCB0I2COA0_L       = 0x0654;
__UCB0I2COA0_H       = 0x0655;
__UCB0I2COA1         = 0x0656;
__UCB0I2COA1_L       = 0x0656;
__UCB0I2COA1_H       = 0x0657;
__UCB0I2COA2         = 0x0658;
__UCB0I2COA2_L       = 0x0658;
__UCB0I2COA2_H       = 0x0659;
__UCB0I2COA3         = 0x065A;
__UCB0I2COA3_L       = 0x065A;
__UCB0I2COA3_H       = 0x065B;
__UCB0ADDRX          = 0x065C;
__UCB0ADDRX_L        = 0x065C;
__UCB0ADDRX_H        = 0x065D;
__UCB0ADDMASK        = 0x065E;
__UCB0ADDMASK_L      = 0x065E;
__UCB0ADDMASK_H      = 0x065F;
__UCB0I2CSA          = 0x0660;
__UCB0I2CSA_L        = 0x0660;
__UCB0I2CSA_H        = 0x0661;
__UCB0IE             = 0x066A;
__UCB0IE_L           = 0x066A;
__UCB0IE_H           = 0x066B;
__UCB0IFG            = 0x066C;
__UCB0IFG_L          = 0x066C;
__UCB0IFG_H          = 0x066D;
__UCB0IV             = 0x066E;
__UCB0IV_L           = 0x066E;
__UCB0IV_H           = 0x066F;


/*****************************************************************************
 eUSCI_B1
*****************************************************************************/
__UCB1CTLW0          = 0x0680;
__UCB1CTLW0_L        = 0x0680;
__UCB1CTLW0_H        = 0x0681;
__UCB1CTLW1          = 0x0682;
__UCB1CTLW1_L        = 0x0682;
__UCB1CTLW1_H        = 0x0683;
__UCB1BRW            = 0x0686;
__UCB1BRW_L          = 0x0686;
__UCB1BRW_H          = 0x0687;
__UCB1STATW          = 0x0688;
__UCB1STATW_L        = 0x0688;
__UCB1STATW_H        = 0x0689;
__UCB1TBCNT          = 0x068A;
__UCB1TBCNT_L        = 0x068A;
__UCB1TBCNT_H        = 0x068B;
__UCB1RXBUF          = 0x068C;
__UCB1RXBUF_L        = 0x068C;
__UCB1RXBUF_H        = 0x068D;
__UCB1TXBUF          = 0x068E;
__UCB1TXBUF_L        = 0x068E;
__UCB1TXBUF_H        = 0x068F;
__UCB1I2COA0         = 0x0694;
__UCB1I2COA0_L       = 0x0694;
__UCB1I2COA0_H       = 0x0695;
__UCB1I2COA1         = 0x0696;
__UCB1I2COA1_L       = 0x0696;
__UCB1I2COA1_H       = 0x0697;
__UCB1I2COA2         = 0x0698;
__UCB1I2COA2_L       = 0x0698;
__UCB1I2COA2_H       = 0x0699;
__UCB1I2COA3         = 0x069A;
__UCB1I2COA3_L       = 0x069A;
__UCB1I2COA3_H       = 0x069B;
__UCB1ADDRX          = 0x069C;
__UCB1ADDRX_L        = 0x069C;
__UCB1ADDRX_H        = 0x069D;
__UCB1ADDMASK        = 0x069E;
__UCB1ADDMASK_L      = 0x069E;
__UCB1ADDMASK_H      = 0x069F;
__UCB1I2CSA          = 0x06A0;
__UCB1I2CSA_L        = 0x06A0;
__UCB1I2CSA_H        = 0x06A1;
__UCB1IE             = 0x06AA;
__UCB1IE_L           = 0x06AA;
__UCB1IE_H           = 0x06AB;
__UCB1IFG            = 0x06AC;
__UCB1IFG_L          = 0x06AC;
__UCB1IFG_H          = 0x06AD;
__UCB1IV             = 0x06AE;
__UCB1IV_L           = 0x06AE;
__UCB1IV_H           = 0x06AF;


/*****************************************************************************
 eUSCI_B2
*****************************************************************************/
__UCB2CTLW0          = 0x06C0;
__UCB2CTLW0_L        = 0x06C0;
__UCB2CTLW0_H        = 0x06C1;
__UCB2CTLW1          = 0x06C2;
__UCB2CTLW1_L        = 0x06C2;
__UCB2CTLW1_H        = 0x06C3;
__UCB2BRW            = 0x06C6;
__UCB2BRW_L          = 0x06C6;
__UCB2BRW_H          = 0x06C7;
__UCB2STATW          = 0x06C8;
__UCB2STATW_L        = 0x06C8;
__UCB2STATW_H        = 0x06C9;
__UCB2TBCNT          = 0x06CA;
__UCB2TBCNT_L        = 0x06CA;
__UCB2TBCNT_H        = 0x06CB;
__UCB2RXBUF          = 0x06CC;
__UCB2RXBUF_L        = 0x06CC;
__UCB2RXBUF_H        = 0x06CD;
__UCB2TXBUF          = 0x06CE;
__UCB2TXBUF_L        = 0x06CE;
__UCB2TXBUF_H        = 0x06CF;
__UCB2I2COA0         = 0x06D4;
__UCB2I2COA0_L       = 0x06D4;
__UCB2I2COA0_H       = 0x06D5;
__UCB2I2COA1         = 0x06D6;
__UCB2I2COA1_L       = 0x06D6;
__UCB2I2COA1_H       = 0x06D7;
__UCB2I2COA2         = 0x06D8;
__UCB2I2COA2_L       = 0x06D8;
__UCB2I2COA2_H       = 0x06D9;
__UCB2I2COA3         = 0x06DA;
__UCB2I2COA3_L       = 0x06DA;
__UCB2I2COA3_H       = 0x06DB;
__UCB2ADDRX          = 0x06DC;
__UCB2ADDRX_L        = 0x06DC;
__UCB2ADDRX_H        = 0x06DD;
__UCB2ADDMASK        = 0x06DE;
__UCB2ADDMASK_L      = 0x06DE;
__UCB2ADDMASK_H      = 0x06DF;
__UCB2I2CSA          = 0x06E0;
__UCB2I2CSA_L        = 0x06E0;
__UCB2I2CSA_H        = 0x06E1;
__UCB2IE             = 0x06EA;
__UCB2IE_L           = 0x06EA;
__UCB2IE_H           = 0x06EB;
__UCB2IFG            = 0x06EC;
__UCB2IFG_L          = 0x06EC;
__UCB2IFG_H          = 0x06ED;
__UCB2IV             = 0x06EE;
__UCB2IV_L           = 0x06EE;
__UCB2IV_H           = 0x06EF;


/*****************************************************************************
 eUSCI_B3
*****************************************************************************/
__UCB3CTLW0          = 0x0700;
__UCB3CTLW0_L        = 0x0700;
__UCB3CTLW0_H        = 0x0701;
__UCB3CTLW1          = 0x0702;
__UCB3CTLW1_L        = 0x0702;
__UCB3CTLW1_H        = 0x0703;
__UCB3BRW            = 0x0706;
__UCB3BRW_L          = 0x0706;
__UCB3BRW_H          = 0x0707;
__UCB3STATW          = 0x0708;
__UCB3STATW_L        = 0x0708;
__UCB3STATW_H        = 0x0709;
__UCB3TBCNT          = 0x070A;
__UCB3TBCNT_L        = 0x070A;
__UCB3TBCNT_H        = 0x070B;
__UCB3RXBUF          = 0x070C;
__UCB3RXBUF_L        = 0x070C;
__UCB3RXBUF_H        = 0x070D;
__UCB3TXBUF          = 0x070E;
__UCB3TXBUF_L        = 0x070E;
__UCB3TXBUF_H        = 0x070F;
__UCB3I2COA0         = 0x0714;
__UCB3I2COA0_L       = 0x0714;
__UCB3I2COA0_H       = 0x0715;
__UCB3I2COA1         = 0x0716;
__UCB3I2COA1_L       = 0x0716;
__UCB3I2COA1_H       = 0x0717;
__UCB3I2COA2         = 0x0718;
__UCB3I2COA2_L       = 0x0718;
__UCB3I2COA2_H       = 0x0719;
__UCB3I2COA3         = 0x071A;
__UCB3I2COA3_L       = 0x071A;
__UCB3I2COA3_H       = 0x071B;
__UCB3ADDRX          = 0x071C;
__UCB3ADDRX_L        = 0x071C;
__UCB3ADDRX_H        = 0x071D;
__UCB3ADDMASK        = 0x071E;
__UCB3ADDMASK_L      = 0x071E;
__UCB3ADDMASK_H      = 0x071F;
__UCB3I2CSA          = 0x0720;
__UCB3I2CSA_L        = 0x0720;
__UCB3I2CSA_H        = 0x0721;
__UCB3IE             = 0x072A;
__UCB3IE_L           = 0x072A;
__UCB3IE_H           = 0x072B;
__UCB3IFG            = 0x072C;
__UCB3IFG_L          = 0x072C;
__UCB3IFG_H          = 0x072D;
__UCB3IV             = 0x072E;
__UCB3IV_L           = 0x072E;
__UCB3IV_H           = 0x072F;

/************************************************************
* End of Modules
************************************************************/


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Configuration                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

ENTRY(tpl_reset_handler)

/* Highest address of the user mode stack */
_estack = 0x3C00;    /* end of 8K RAM */

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0;      /* required amount of heap  */
_Min_Stack_Size = 0x100; /* required amount of stack */

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Memory                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Specify the memory areas for msp430fr5994
 * basic first version:
 * - upper FRAM bank 0x10000 (208kb) not configured
 */

MEMORY
{
  VECTOR (rx) : ORIGIN = 0x0FFB4, LENGTH = 0x4C   /* ends at 0x10000, 76 bytes - 38 vectors */
  FRAM (rx)  : ORIGIN = 0x04000, LENGTH = 0xBF80 /* ends at 0xff80. size is 47,875k */

  RAM (xrw)   : ORIGIN = 0x01C00, LENGTH = 4096 /* size is [4k - 8k] */
  LEA_RAM (xrw)  : ORIGIN = 11263, LENGTH = 4096 /* size is [0k - 4k] */

}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                ISR Vectors                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  .isr_vector : {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* vector table */
    . = ALIGN(4);
  } >VECTOR
}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                    Code                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*
 * Sections for Non Volatile variables. They should be inserted
 * at the beginning of the FRAM, so that the MPU is easier to configure.
 */
SECTIONS {
  .NVdata ORIGIN(FRAM) : AT ( __nvdata_load_start) {
    . = ALIGN(4);
    __nvdata_start = .; /* create a global symbol at non volatile data start */
    *(.osVar_NON_VOLATILE_32BIT)
    *(.osVar_NON_VOLATILE_16BIT)
    *(.osVar_NON_VOLATILE_8BIT)
    *(.osVar_NON_VOLATILE_BOOLEAN)
    *(.osVar_NON_VOLATILE_UNSPECIFIED)

    /* --- Non volatile variables section of Task fft */
    *(.Task_fft_SEC_VAR_NON_VOLATILE_32BIT )
    *(.Task_fft_SEC_VAR_NON_VOLATILE_16BIT )
    *(.Task_fft_SEC_VAR_NON_VOLATILE_8BIT )
    *(.Task_fft_SEC_VAR_NON_VOLATILE_BOOLEAN )
    *(.Task_fft_SEC_VAR_NON_VOLATILE_UNSPECIFIED )


    . = ALIGN(2);
    __nvdata_end = .;        /* define a global symbol at non volatile data end */
    __nvdata_size = SIZEOF(.NVdata); /* define a global symbol at non volatile data end */
  } >FRAM

  .NVdataInit : {
    . = ALIGN(1024);         /* MSP430 MPU minimal segment size */
    TPL_MPU_B1_BOUNDARY = .; /* useful for MPU initialization - start of code */
    __nvdata_load_start = .;
    . += SIZEOF(.NVdata);    /* reserve space for NVdata init values*/
 __nvdata_load_end = .;
  } >FRAM
}

/* init section for msp430. 
 * execution starts at the beginning of the fram. */
SECTIONS {
 /* we make sure that both 
  * - VMA (virtual memory address) and 
  * - LMA (load memory address) 
  * are the same */
  .textInit __nvdata_load_end : AT(__nvdata_load_end) {
    KEEP(*(.init)) /* start here after reset */
  } > FRAM
}

/*
 * code and const of the operating system (Trampoline).
 * this section is not accessible from an untrusted process
 */
SECTIONS {
  . = ALIGN(4);
  /* --- code of OS --- */
  ostext : {
    *(.SC_handler)
    *(.EI_handler)
    *(.osCode)
    *(.osApiCode)  /* API functions */
    *(.appCommonCode)
  } >FRAM
  . = ALIGN(4);
  /* --- const of OS --- */
  osconst : {
    *(.osConst)
    *(.osApiConst) /* API constants */
  } >FRAM
}

/*
 * code and const of the processes of the applications ]
 */
SECTIONS {
  . = ALIGN(4);
  apptext : {
    __PROGCONST_SECTION_START = .;
    __SEG_START_APP_CODE_CONST_RGN = .;
  . = ALIGN(4);
  /* --- Sections for application code --- */

  /* --- Sections for code of tasks and ISR --- */
    *(.Task_fftCode)

  } >FRAM
  . = ALIGN(4);
  appconst : {
  /* --- Sections for application const --- */
    *(.rodata)     /* litteral strings (constants, strings, etc.) */
    *(.rodata*)    /* litteral strings (constants, strings, etc.) */

  } >FRAM
}

/*
 * Sections for const of tasks and ISR
 */
SECTIONS {
  . = ALIGN(4);
  procconst : {
      *(.Task_fft_SEC_CONST_32BIT)
      *(.Task_fft_SEC_CALIB_32BIT)
      *(.Task_fft_SEC_CARTO_32BIT)
      *(.Task_fft_SEC_CONFIG_DATA_32BIT)
      *(.Task_fft_SEC_CONST_16BIT)
      *(.Task_fft_SEC_CALIB_16BIT)
      *(.Task_fft_SEC_CARTO_16BIT)
      *(.Task_fft_SEC_CONFIG_DATA_16BIT)
      *(.Task_fft_SEC_CONST_8BIT)
      *(.Task_fft_SEC_CALIB_8BIT)
      *(.Task_fft_SEC_CARTO_8BIT)
      *(.Task_fft_SEC_CONFIG_DATA_8BIT)
      *(.Task_fft_SEC_CONST_BOOLEAN)
      *(.Task_fft_SEC_CALIB_BOOLEAN)
      *(.Task_fft_SEC_CARTO_BOOLEAN)
      *(.Task_fft_SEC_CONFIG_DATA_BOOLEAN)
      *(.Task_fft_SEC_CONST_UNSPECIFIED)
      *(.Task_fft_SEC_CALIB_UNSPECIFIED)
      *(.Task_fft_SEC_CARTO_UNSPECIFIED)
      *(.Task_fft_SEC_CONFIG_DATA_UNSPECIFIED)
    
    . = ALIGN(4);
    __SEG_STOP_APP_CODE_CONST_RGN = . - 1;
    __PROGCONST_SECTION_STOP = . - 1;
  } >FRAM
}

  /* remaining .text (ie no section given) */
SECTIONS {
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
 *(.eh_frame)

    /* Constructors sections (list of pointers)
     * from https://gcc.gnu.org/onlinedocs/gccint/Initialization.html 
  * set in .text section to be effectively loaded in flash
     **/
    PROVIDE_HIDDEN (__ctors_start = .);
    KEEP (*(.ctors*))
    KEEP (*(SORT(.ctors.*)))
    PROVIDE_HIDDEN (__ctors_end = .);

    /* Destructors sections (list of pointers)
     * from https://gcc.gnu.org/onlinedocs/gccint/Initialization.html 
  * set in .text section to be effectively loaded in flash
     **/
    PROVIDE_HIDDEN (__dtors_start = .);
    KEEP (*(.dtors*))
    KEEP (*(SORT(.dtors.*)))
    PROVIDE_HIDDEN (__dtors_end = .);

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
    _exit = .;
  } >FRAM
}

/* used by the startup to initialize data */
SECTIONS {
  _sramStartAddress = .;
  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data : AT ( __data_load_start )
  {
    . = ALIGN(4);
    __data_start = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    *(.osVar)
    *(.osVar_POWER_ON_INIT_32BIT)
    *(.osVar_FAST_32BIT)
    *(.osVar_32BIT)
    *(.osVar_POWER_ON_INIT_16BIT)
    *(.osVar_FAST_16BIT)
    *(.osVar_16BIT)
    *(.osVar_POWER_ON_INIT_8BIT)
    *(.osVar_FAST_8BIT)
    *(.osVar_8BIT)
    *(.osVar_POWER_ON_INIT_BOOLEAN)
    *(.osVar_FAST_BOOLEAN)
    *(.osVar_BOOLEAN)
    *(.osVar_POWER_ON_INIT_UNSPECIFIED)
    *(.osVar_FAST_UNSPECIFIED)
    *(.osVar_UNSPECIFIED)

/* Initialized variables section of Task fft */
    *(.Task_fft_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.Task_fft_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.Task_fft_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.Task_fft_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.Task_fft_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)

    . = ALIGN(4);
    __data_end = .;        /* define a global symbol at data end */
    __data_size = SIZEOF(.data);
  } >RAM

  .dataInit : {
 . = ALIGN(16);
    __data_load_start = .;
 /* reserve space for data init value */
    . += SIZEOF(.data);
  } >FRAM
}

SECTIONS {
.data_lea : {

/* Initialized LEA variables section of Task fft */
	 *(.Task_fft_SEC_LEA_VAR_LEA_32BIT)
	 *(.Task_fft_SEC_LEA_VAR_LEA_16BIT)
	 *(.Task_fft_SEC_LEA_VAR_LEA_8BIT)
	 *(.Task_fft_SEC_LEA_VAR_LEA_BOOLEAN)
	 *(.Task_fft_SEC_LEA_VAR_LEA_UNSPECIFIED)

	. = ALIGN(4);
   } > LEA_RAM
}

  /*
   * private data of processes
   */
SECTIONS {
  .Task_fft_SEC_VAR : {
    /* . = ALIGN(__SEG_ALIGN_Task_fft_VAR_RGN); TODO check alignment*/
    __SEG_START_Task_fft_VAR_RGN = .;
  /* --- Initialized variables section of Task fft */
    *(.Task_fft_SEC_VAR_NOINIT_32BIT)
    *(.Task_fft_SEC_VAR_FAST_32BIT)
    *(.Task_fft_SEC_VAR_32BIT)
    *(.Task_fft_SEC_VAR_NOINIT_16BIT)
    *(.Task_fft_SEC_VAR_FAST_16BIT)
    *(.Task_fft_SEC_VAR_16BIT)
    *(.Task_fft_SEC_VAR_NOINIT_8BIT)
    *(.Task_fft_SEC_VAR_FAST_8BIT)
    *(.Task_fft_SEC_VAR_8BIT)
    *(.Task_fft_SEC_VAR_NOINIT_BOOLEAN)
    *(.Task_fft_SEC_VAR_FAST_BOOLEAN)
    *(.Task_fft_SEC_VAR_BOOLEAN)
    *(.Task_fft_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.Task_fft_SEC_VAR_FAST_UNSPECIFIED)
    *(.Task_fft_SEC_VAR_UNSPECIFIED)
     __SEG_END_Task_fft_VAR_RGN = .;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 4K ? 4K : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 1K ? 1K : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 512 ? 512 : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 256 ? 256 : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 128 ? 128 : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 64 ? 64 : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_SIZE_Task_fft_VAR_RGN = (__SEG_END_Task_fft_VAR_RGN - __SEG_START_Task_fft_VAR_RGN) < 32 ? 32 : __SEG_SIZE_Task_fft_VAR_RGN;
     __SEG_ALIGN_Task_fft_VAR_RGN = __SEG_SIZE_Task_fft_VAR_RGN;
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                Stack of processes                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  /* --- Section of stack of Task fft  */
  .Task_fft_SEC_STACK : {
    /* . = ALIGN(__SEG_ALIGN_Task_fft_STACK_RGN); TODO: check alignment */
    __SEG_START_Task_fft_STACK_RGN = .;
    *(.Task_fftStack)
    . = ALIGN(4);
    __SEG_END_Task_fft_STACK_RGN = .;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 4K ? 4K : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 1K ? 1K : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 512 ? 512 : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 256 ? 256 : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 128 ? 128 : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 64 ? 64 : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_SIZE_Task_fft_STACK_RGN = (__SEG_END_Task_fft_STACK_RGN - __SEG_START_Task_fft_STACK_RGN) < 32 ? 32 : __SEG_SIZE_Task_fft_STACK_RGN;
    __SEG_ALIGN_Task_fft_STACK_RGN = __SEG_SIZE_Task_fft_STACK_RGN;
  } >RAM

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                OS application data                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  /*
   * os application data
   */
   appvars : {
 
  } >RAM
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                          OS unitialized data (useful?)                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
SECTIONS {
  . = ALIGN(4);
  .osVarNoInit :
  {
    *(.osVar_NOINIT_32BIT)
    *(.osVar_NOINIT_16BIT)
    *(.osVar_NOINIT_8BIT)
    *(.osVar_NOINIT_BOOLEAN)
    *(.osVar_NOINIT_UNSPECIFIED)
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                          Data (initialized data)                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                          BSS (uninitialized data)                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                    Heap                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

  /* _user_heap_stack section, used to check that there is enough RAM left */
SECTIONS {
  ._user_heap_stack :
  {
    . = ALIGN(4);
    __heap_start__ = . ;
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(4);
  } >RAM
}



  /* Remove information from the standard libraries */
SECTIONS {
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }
}

SECTIONS {
  __tpl_end_of_checkpointing_zone = .;
  .osVarKernStack :
  {
    . = ALIGN(2);
    __os_kern_stack_start = .;	/* OS kernel stack symbol start */
    *(.osVarKernStack)	        /* OS Kernel stack */
    __os_kern_stack_end   = .;  /* OS kernel stack symbol start */
  } >RAM
}

/* vim:ft=ld
 */
