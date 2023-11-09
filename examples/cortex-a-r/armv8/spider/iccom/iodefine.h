/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* http://www.renesas.com/disclaimer                                          */
/*                                                                            */
/* Device     : RH/RH850G4MH2.0/R8A779F0                                      */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of I/O Register                                    */
/* History    : E0.50b [Device File version]                                  */
/* Options    : -df=C:\S4\Alpha-1\CS+forCCE8.07.00c_R-CarS4\CS+\CC\Device_Cus */
/*              tom\RH850\Devicefile\DR8A779F0.DVF -o=C:\S4\Alpha-1\sample\sa */
/*              mple\iodefine.h -def=off -f                                   */
/* Date       : 2021/10/25                                                    */
/* Version    : V1.14.00.01  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R8A779F0IODEFINE_HEADER__
#define __R8A779F0IODEFINE_HEADER__

struct __tag5473
{                                                          /* Module           */
    unsigned long  MFISLCKR0;                              /* MFISLCKR0        */
    unsigned long  MFISLCKR1;                              /* MFISLCKR1        */
    unsigned long  MFISLCKR2;                              /* MFISLCKR2        */
    unsigned long  MFISLCKR3;                              /* MFISLCKR3        */
    unsigned long  MFISLCKR4;                              /* MFISLCKR4        */
    unsigned long  MFISLCKR5;                              /* MFISLCKR5        */
    unsigned long  MFISLCKR6;                              /* MFISLCKR6        */
    unsigned long  MFISLCKR7;                              /* MFISLCKR7        */
    unsigned char  dummy15[480];                           /* Reserved         */
    unsigned long  MFIEDCSIDADDR;                          /* MFIEDCSIDADDR    */
    unsigned long  MFIEDCSIDWDATA;                         /* MFIEDCSIDWDATA   */
    unsigned char  dummy16[824];                           /* Reserved         */
    unsigned long  MFISOFTMDR;                             /* MFISOFTMDR       */
    unsigned long  MFISBTSTSR;                             /* MFISBTSTSR       */
    unsigned char  dummy17[284];                           /* Reserved         */
    unsigned long  MFISLCKR8;                              /* MFISLCKR8        */
    unsigned long  MFISLCKR9;                              /* MFISLCKR9        */
    unsigned long  MFISLCKR10;                             /* MFISLCKR10       */
    unsigned long  MFISLCKR11;                             /* MFISLCKR11       */
    unsigned long  MFISLCKR12;                             /* MFISLCKR12       */
    unsigned long  MFISLCKR13;                             /* MFISLCKR13       */
    unsigned long  MFISLCKR14;                             /* MFISLCKR14       */
    unsigned long  MFISLCKR15;                             /* MFISLCKR15       */
    unsigned long  MFISLCKR16;                             /* MFISLCKR16       */
    unsigned long  MFISLCKR17;                             /* MFISLCKR17       */
    unsigned long  MFISLCKR18;                             /* MFISLCKR18       */
    unsigned long  MFISLCKR19;                             /* MFISLCKR19       */
    unsigned long  MFISLCKR20;                             /* MFISLCKR20       */
    unsigned long  MFISLCKR21;                             /* MFISLCKR21       */
    unsigned long  MFISLCKR22;                             /* MFISLCKR22       */
    unsigned long  MFISLCKR23;                             /* MFISLCKR23       */
    unsigned long  MFISLCKR24;                             /* MFISLCKR24       */
    unsigned long  MFISLCKR25;                             /* MFISLCKR25       */
    unsigned long  MFISLCKR26;                             /* MFISLCKR26       */
    unsigned long  MFISLCKR27;                             /* MFISLCKR27       */
    unsigned long  MFISLCKR28;                             /* MFISLCKR28       */
    unsigned long  MFISLCKR29;                             /* MFISLCKR29       */
    unsigned long  MFISLCKR30;                             /* MFISLCKR30       */
    unsigned long  MFISLCKR31;                             /* MFISLCKR31       */
    unsigned long  MFISLCKR32;                             /* MFISLCKR32       */
    unsigned long  MFISLCKR33;                             /* MFISLCKR33       */
    unsigned long  MFISLCKR34;                             /* MFISLCKR34       */
    unsigned long  MFISLCKR35;                             /* MFISLCKR35       */
    unsigned long  MFISLCKR36;                             /* MFISLCKR36       */
    unsigned long  MFISLCKR37;                             /* MFISLCKR37       */
    unsigned long  MFISLCKR38;                             /* MFISLCKR38       */
    unsigned long  MFISLCKR39;                             /* MFISLCKR39       */
    unsigned long  MFISLCKR40;                             /* MFISLCKR40       */
    unsigned long  MFISLCKR41;                             /* MFISLCKR41       */
    unsigned long  MFISLCKR42;                             /* MFISLCKR42       */
    unsigned long  MFISLCKR43;                             /* MFISLCKR43       */
    unsigned long  MFISLCKR44;                             /* MFISLCKR44       */
    unsigned long  MFISLCKR45;                             /* MFISLCKR45       */
    unsigned long  MFISLCKR46;                             /* MFISLCKR46       */
    unsigned long  MFISLCKR47;                             /* MFISLCKR47       */
    unsigned long  MFISLCKR48;                             /* MFISLCKR48       */
    unsigned long  MFISLCKR49;                             /* MFISLCKR49       */
    unsigned long  MFISLCKR50;                             /* MFISLCKR50       */
    unsigned long  MFISLCKR51;                             /* MFISLCKR51       */
    unsigned long  MFISLCKR52;                             /* MFISLCKR52       */
    unsigned long  MFISLCKR53;                             /* MFISLCKR53       */
    unsigned long  MFISLCKR54;                             /* MFISLCKR54       */
    unsigned long  MFISLCKR55;                             /* MFISLCKR55       */
    unsigned long  MFISLCKR56;                             /* MFISLCKR56       */
    unsigned long  MFISLCKR57;                             /* MFISLCKR57       */
    unsigned long  MFISLCKR58;                             /* MFISLCKR58       */
    unsigned long  MFISLCKR59;                             /* MFISLCKR59       */
    unsigned long  MFISLCKR60;                             /* MFISLCKR60       */
    unsigned long  MFISLCKR61;                             /* MFISLCKR61       */
    unsigned long  MFISLCKR62;                             /* MFISLCKR62       */
    unsigned long  MFISLCKR63;                             /* MFISLCKR63       */
    unsigned char  dummy18[180];                           /* Reserved         */
    unsigned long  MFISCMPERRSTSR;                         /* MFISCMPERRSTSR   */
    unsigned char  dummy19[68];                            /* Reserved         */
    unsigned long  MFISWPCNTR;                             /* MFISWPCNTR       */
    unsigned long  MFISWACNTR;                             /* MFISWACNTR       */
    unsigned char  dummy20[60];                            /* Reserved         */
    unsigned long  MFIERRINJ;                              /* MFIERRINJ        */
    unsigned char  dummy21[2744];                          /* Reserved         */
    unsigned long  MFISARIICR0;                            /* MFISARIICR0      */
    unsigned char  dummy22[60];                            /* Reserved         */
    unsigned long  MFISARIMBR0;                            /* MFISARIMBR0      */
    unsigned char  dummy23[60];                            /* Reserved         */
    unsigned long  MFISAM0IICR0;                           /* MFISAM0IICR0     */
    unsigned char  dummy24[60];                            /* Reserved         */
    unsigned long  MFISAM0IMBR0;                           /* MFISAM0IMBR0     */
    unsigned char  dummy25[188];                           /* Reserved         */
    unsigned long  MFISAM1IICR0;                           /* MFISAM1IICR0     */
    unsigned char  dummy26[60];                            /* Reserved         */
    unsigned long  MFISAM1IMBR0;                           /* MFISAM1IMBR0     */
    unsigned char  dummy27[3652];                          /* Reserved         */
    unsigned long  MFISARIICR1;                            /* MFISARIICR1      */
    unsigned char  dummy28[56];                            /* Reserved         */
    unsigned long  MFISARIMBR1;                            /* MFISARIMBR1      */
    unsigned char  dummy29[64];                            /* Reserved         */
    unsigned long  MFISAM0IICR1;                           /* MFISAM0IICR1     */
    unsigned char  dummy30[56];                            /* Reserved         */
    unsigned long  MFISAM0IMBR1;                           /* MFISAM0IMBR1     */
    unsigned char  dummy31[192];                           /* Reserved         */
    unsigned long  MFISAM1IICR1;                           /* MFISAM1IICR1     */
    unsigned char  dummy32[56];                            /* Reserved         */
    unsigned long  MFISAM1IMBR1;                           /* MFISAM1IMBR1     */
    unsigned char  dummy33[3656];                          /* Reserved         */
    unsigned long  MFISARIICR2;                            /* MFISARIICR2      */
    unsigned char  dummy34[52];                            /* Reserved         */
    unsigned long  MFISARIMBR2;                            /* MFISARIMBR2      */
    unsigned char  dummy35[68];                            /* Reserved         */
    unsigned long  MFISAM0IICR2;                           /* MFISAM0IICR2     */
    unsigned char  dummy36[52];                            /* Reserved         */
    unsigned long  MFISAM0IMBR2;                           /* MFISAM0IMBR2     */
    unsigned char  dummy37[196];                           /* Reserved         */
    unsigned long  MFISAM1IICR2;                           /* MFISAM1IICR2     */
    unsigned char  dummy38[52];                            /* Reserved         */
    unsigned long  MFISAM1IMBR2;                           /* MFISAM1IMBR2     */
    unsigned char  dummy39[3660];                          /* Reserved         */
    unsigned long  MFISARIICR3;                            /* MFISARIICR3      */
    unsigned char  dummy40[48];                            /* Reserved         */
    unsigned long  MFISARIMBR3;                            /* MFISARIMBR3      */
    unsigned char  dummy41[72];                            /* Reserved         */
    unsigned long  MFISAM0IICR3;                           /* MFISAM0IICR3     */
    unsigned char  dummy42[48];                            /* Reserved         */
    unsigned long  MFISAM0IMBR3;                           /* MFISAM0IMBR3     */
    unsigned char  dummy43[200];                           /* Reserved         */
    unsigned long  MFISAM1IICR3;                           /* MFISAM1IICR3     */
    unsigned char  dummy44[48];                            /* Reserved         */
    unsigned long  MFISAM1IMBR3;                           /* MFISAM1IMBR3     */
    unsigned char  dummy45[3664];                          /* Reserved         */
    unsigned long  MFISARIICR4;                            /* MFISARIICR4      */
    unsigned char  dummy46[44];                            /* Reserved         */
    unsigned long  MFISARIMBR4;                            /* MFISARIMBR4      */
    unsigned char  dummy47[76];                            /* Reserved         */
    unsigned long  MFISAM0IICR4;                           /* MFISAM0IICR4     */
    unsigned char  dummy48[44];                            /* Reserved         */
    unsigned long  MFISAM0IMBR4;                           /* MFISAM0IMBR4     */
    unsigned char  dummy49[204];                           /* Reserved         */
    unsigned long  MFISAM1IICR4;                           /* MFISAM1IICR4     */
    unsigned char  dummy50[44];                            /* Reserved         */
    unsigned long  MFISAM1IMBR4;                           /* MFISAM1IMBR4     */
    unsigned char  dummy51[3668];                          /* Reserved         */
    unsigned long  MFISARIICR5;                            /* MFISARIICR5      */
    unsigned char  dummy52[40];                            /* Reserved         */
    unsigned long  MFISARIMBR5;                            /* MFISARIMBR5      */
    unsigned char  dummy53[80];                            /* Reserved         */
    unsigned long  MFISAM0IICR5;                           /* MFISAM0IICR5     */
    unsigned char  dummy54[40];                            /* Reserved         */
    unsigned long  MFISAM0IMBR5;                           /* MFISAM0IMBR5     */
    unsigned char  dummy55[208];                           /* Reserved         */
    unsigned long  MFISAM1IICR5;                           /* MFISAM1IICR5     */
    unsigned char  dummy56[40];                            /* Reserved         */
    unsigned long  MFISAM1IMBR5;                           /* MFISAM1IMBR5     */
    unsigned char  dummy57[3672];                          /* Reserved         */
    unsigned long  MFISARIICR6;                            /* MFISARIICR6      */
    unsigned char  dummy58[36];                            /* Reserved         */
    unsigned long  MFISARIMBR6;                            /* MFISARIMBR6      */
    unsigned char  dummy59[84];                            /* Reserved         */
    unsigned long  MFISAM0IICR6;                           /* MFISAM0IICR6     */
    unsigned char  dummy60[36];                            /* Reserved         */
    unsigned long  MFISAM0IMBR6;                           /* MFISAM0IMBR6     */
    unsigned char  dummy61[212];                           /* Reserved         */
    unsigned long  MFISAM1IICR6;                           /* MFISAM1IICR6     */
    unsigned char  dummy62[36];                            /* Reserved         */
    unsigned long  MFISAM1IMBR6;                           /* MFISAM1IMBR6     */
    unsigned char  dummy63[3676];                          /* Reserved         */
    unsigned long  MFISARIICR7;                            /* MFISARIICR7      */
    unsigned char  dummy64[32];                            /* Reserved         */
    unsigned long  MFISARIMBR7;                            /* MFISARIMBR7      */
    unsigned char  dummy65[88];                            /* Reserved         */
    unsigned long  MFISAM0IICR7;                           /* MFISAM0IICR7     */
    unsigned char  dummy66[32];                            /* Reserved         */
    unsigned long  MFISAM0IMBR7;                           /* MFISAM0IMBR7     */
    unsigned char  dummy67[216];                           /* Reserved         */
    unsigned long  MFISAM1IICR7;                           /* MFISAM1IICR7     */
    unsigned char  dummy68[32];                            /* Reserved         */
    unsigned long  MFISAM1IMBR7;                           /* MFISAM1IMBR7     */
    unsigned char  dummy69[3620];                          /* Reserved         */
    unsigned long  MFISAREICR0;                            /* MFISAREICR0      */
    unsigned char  dummy70[4];                             /* Reserved         */
    unsigned long  MFISAREICR1;                            /* MFISAREICR1      */
    unsigned char  dummy71[4];                             /* Reserved         */
    unsigned long  MFISAREICR2;                            /* MFISAREICR2      */
    unsigned char  dummy72[4];                             /* Reserved         */
    unsigned long  MFISAREICR3;                            /* MFISAREICR3      */
    unsigned char  dummy73[4];                             /* Reserved         */
    unsigned long  MFISAREICR4;                            /* MFISAREICR4      */
    unsigned char  dummy74[4];                             /* Reserved         */
    unsigned long  MFISAREICR5;                            /* MFISAREICR5      */
    unsigned char  dummy75[4];                             /* Reserved         */
    unsigned long  MFISAREICR6;                            /* MFISAREICR6      */
    unsigned char  dummy76[4];                             /* Reserved         */
    unsigned long  MFISAREICR7;                            /* MFISAREICR7      */
    unsigned char  dummy77[32];                            /* Reserved         */
    unsigned long  MFISAREMBR0;                            /* MFISAREMBR0      */
    unsigned long  MFISAREMBR1;                            /* MFISAREMBR1      */
    unsigned long  MFISAREMBR2;                            /* MFISAREMBR2      */
    unsigned long  MFISAREMBR3;                            /* MFISAREMBR3      */
    unsigned long  MFISAREMBR4;                            /* MFISAREMBR4      */
    unsigned long  MFISAREMBR5;                            /* MFISAREMBR5      */
    unsigned long  MFISAREMBR6;                            /* MFISAREMBR6      */
    unsigned long  MFISAREMBR7;                            /* MFISAREMBR7      */
    unsigned char  dummy78[132];                           /* Reserved         */
    unsigned long  MFISRM0EICR0;                           /* MFISRM0EICR0     */
    unsigned char  dummy79[88];                            /* Reserved         */
    unsigned long  MFISRM0EMBR0;                           /* MFISRM0EMBR0     */
    unsigned char  dummy80[160];                           /* Reserved         */
    unsigned long  MFISRM1EICR0;                           /* MFISRM1EICR0     */
    unsigned char  dummy81[88];                            /* Reserved         */
    unsigned long  MFISRM1EMBR0;                           /* MFISRM1EMBR0     */
    unsigned char  dummy82[3616];                          /* Reserved         */
    unsigned long  MFISAM0EICR0;                           /* MFISAM0EICR0     */
    unsigned char  dummy83[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR1;                           /* MFISAM0EICR1     */
    unsigned char  dummy84[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR2;                           /* MFISAM0EICR2     */
    unsigned char  dummy85[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR3;                           /* MFISAM0EICR3     */
    unsigned char  dummy86[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR4;                           /* MFISAM0EICR4     */
    unsigned char  dummy87[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR5;                           /* MFISAM0EICR5     */
    unsigned char  dummy88[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR6;                           /* MFISAM0EICR6     */
    unsigned char  dummy89[4];                             /* Reserved         */
    unsigned long  MFISAM0EICR7;                           /* MFISAM0EICR7     */
    unsigned char  dummy90[32];                            /* Reserved         */
    unsigned long  MFISAM0EMBR0;                           /* MFISAM0EMBR0     */
    unsigned long  MFISAM0EMBR1;                           /* MFISAM0EMBR1     */
    unsigned long  MFISAM0EMBR2;                           /* MFISAM0EMBR2     */
    unsigned long  MFISAM0EMBR3;                           /* MFISAM0EMBR3     */
    unsigned long  MFISAM0EMBR4;                           /* MFISAM0EMBR4     */
    unsigned long  MFISAM0EMBR5;                           /* MFISAM0EMBR5     */
    unsigned long  MFISAM0EMBR6;                           /* MFISAM0EMBR6     */
    unsigned long  MFISAM0EMBR7;                           /* MFISAM0EMBR7     */
    unsigned long  MFISRM0IICR0;                           /* MFISRM0IICR0     */
    unsigned char  dummy91[60];                            /* Reserved         */
    unsigned long  MFISRM0IMBR0;                           /* MFISRM0IMBR0     */
    unsigned char  dummy92[3904];                          /* Reserved         */
    unsigned long  MFISAM1EICR0;                           /* MFISAM1EICR0     */
    unsigned char  dummy93[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR1;                           /* MFISAM1EICR1     */
    unsigned char  dummy94[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR2;                           /* MFISAM1EICR2     */
    unsigned char  dummy95[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR3;                           /* MFISAM1EICR3     */
    unsigned char  dummy96[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR4;                           /* MFISAM1EICR4     */
    unsigned char  dummy97[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR5;                           /* MFISAM1EICR5     */
    unsigned char  dummy98[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR6;                           /* MFISAM1EICR6     */
    unsigned char  dummy99[4];                             /* Reserved         */
    unsigned long  MFISAM1EICR7;                           /* MFISAM1EICR7     */
    unsigned char  dummy100[32];                           /* Reserved         */
    unsigned long  MFISAM1EMBR0;                           /* MFISAM1EMBR0     */
    unsigned long  MFISAM1EMBR1;                           /* MFISAM1EMBR1     */
    unsigned long  MFISAM1EMBR2;                           /* MFISAM1EMBR2     */
    unsigned long  MFISAM1EMBR3;                           /* MFISAM1EMBR3     */
    unsigned long  MFISAM1EMBR4;                           /* MFISAM1EMBR4     */
    unsigned long  MFISAM1EMBR5;                           /* MFISAM1EMBR5     */
    unsigned long  MFISAM1EMBR6;                           /* MFISAM1EMBR6     */
    unsigned long  MFISAM1EMBR7;                           /* MFISAM1EMBR7     */
    unsigned long  MFISRM1IICR0;                           /* MFISRM1IICR0     */
    unsigned char  dummy101[60];                           /* Reserved         */
    unsigned long  MFISRM1IMBR0;                           /* MFISRM1IMBR0     */
};

#define MFIS0     (*(volatile struct __tag5473 *)0xE62600C0) /* MFIS0 */

#endif
