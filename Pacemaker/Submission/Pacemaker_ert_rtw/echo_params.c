/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_params.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 5.70
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 25 14:58:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker_types.h"
#include "echo_params_private.h"
#include "Pacemaker.h"
#include "echo_params.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Pacemaker_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj);
static void Pacemaker_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params_Init(void)
{
  /* Start for MATLABSystem: '<S1>/Serial Transmit' */
  Pacemaker_DW.obj_n.isInitialized = 0;
  Pacemaker_DW.obj_n.matlabCodegenIsDeleted = false;
  Pacemaker_SystemCore_setup(&Pacemaker_DW.obj_n);
}

/* Output and update for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params(void)
{
  uint8_T rtb_TmpSignalConversionAtSerial[33];
  uint8_T status;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.VRP = Pacemaker_B.VRP_g;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.ARP = Pacemaker_B.ARP_d;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.ATR_AMP = Pacemaker_B.ATR_AMP_g;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.ATR_PW = Pacemaker_B.ATR_PW_k;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.ATR_SENSITIVITY = Pacemaker_B.ATR_SENSITIVITY_o;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.PVARP = Pacemaker_B.PVARP_m;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.VENT_AMP = Pacemaker_B.VENT_AMP_c;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.VENT_PW = Pacemaker_B.VENT_PW_j;

  /* SignalConversion generated from: '<S1>/params' */
  Pacemaker_B.VENT_SENSITIVITY = Pacemaker_B.VENT_SENSITIVITY_f;

  /* S-Function (any2byte): '<S1>/Byte Pack' */

  /* Pack: <S1>/Byte Pack */
  (void) memcpy(&Pacemaker_B.BytePack[0], &Pacemaker_B.VENT_AMP,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack1' */

  /* Pack: <S1>/Byte Pack1 */
  (void) memcpy(&Pacemaker_B.BytePack1[0], &Pacemaker_B.VENT_PW,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack2' */

  /* Pack: <S1>/Byte Pack2 */
  (void) memcpy(&Pacemaker_B.BytePack2[0], &Pacemaker_B.VENT_SENSITIVITY,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack3' */

  /* Pack: <S1>/Byte Pack3 */
  (void) memcpy(&Pacemaker_B.BytePack3[0], &Pacemaker_B.VRP,
                2);

  /* S-Function (any2byte): '<S1>/Byte Pack4' */

  /* Pack: <S1>/Byte Pack4 */
  (void) memcpy(&Pacemaker_B.BytePack4[0], &Pacemaker_B.ATR_AMP,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack5' */

  /* Pack: <S1>/Byte Pack5 */
  (void) memcpy(&Pacemaker_B.BytePack5[0], &Pacemaker_B.ATR_PW,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack6' */

  /* Pack: <S1>/Byte Pack6 */
  (void) memcpy(&Pacemaker_B.BytePack6[0], &Pacemaker_B.ATR_SENSITIVITY,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack7' */

  /* Pack: <S1>/Byte Pack7 */
  (void) memcpy(&Pacemaker_B.BytePack7[0], &Pacemaker_B.ARP,
                2);

  /* S-Function (any2byte): '<S1>/Byte Pack8' */

  /* Pack: <S1>/Byte Pack8 */
  (void) memcpy(&Pacemaker_B.BytePack8[0], &Pacemaker_B.PVARP,
                2);

  /* SignalConversion generated from: '<S1>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S1>/Inport'
   *  SignalConversion generated from: '<S1>/params'
   */
  rtb_TmpSignalConversionAtSerial[0] = Pacemaker_B.LRL;
  rtb_TmpSignalConversionAtSerial[1] = Pacemaker_B.URL;
  rtb_TmpSignalConversionAtSerial[2] = Pacemaker_B.BytePack[0];
  rtb_TmpSignalConversionAtSerial[6] = Pacemaker_B.BytePack1[0];
  rtb_TmpSignalConversionAtSerial[10] = Pacemaker_B.BytePack2[0];
  rtb_TmpSignalConversionAtSerial[3] = Pacemaker_B.BytePack[1];
  rtb_TmpSignalConversionAtSerial[7] = Pacemaker_B.BytePack1[1];
  rtb_TmpSignalConversionAtSerial[11] = Pacemaker_B.BytePack2[1];
  rtb_TmpSignalConversionAtSerial[4] = Pacemaker_B.BytePack[2];
  rtb_TmpSignalConversionAtSerial[8] = Pacemaker_B.BytePack1[2];
  rtb_TmpSignalConversionAtSerial[12] = Pacemaker_B.BytePack2[2];
  rtb_TmpSignalConversionAtSerial[5] = Pacemaker_B.BytePack[3];
  rtb_TmpSignalConversionAtSerial[9] = Pacemaker_B.BytePack1[3];
  rtb_TmpSignalConversionAtSerial[13] = Pacemaker_B.BytePack2[3];
  rtb_TmpSignalConversionAtSerial[14] = Pacemaker_B.BytePack3[0];
  rtb_TmpSignalConversionAtSerial[15] = Pacemaker_B.BytePack3[1];
  rtb_TmpSignalConversionAtSerial[16] = Pacemaker_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[20] = Pacemaker_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[24] = Pacemaker_B.BytePack6[0];
  rtb_TmpSignalConversionAtSerial[17] = Pacemaker_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[21] = Pacemaker_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[25] = Pacemaker_B.BytePack6[1];
  rtb_TmpSignalConversionAtSerial[18] = Pacemaker_B.BytePack4[2];
  rtb_TmpSignalConversionAtSerial[22] = Pacemaker_B.BytePack5[2];
  rtb_TmpSignalConversionAtSerial[26] = Pacemaker_B.BytePack6[2];
  rtb_TmpSignalConversionAtSerial[19] = Pacemaker_B.BytePack4[3];
  rtb_TmpSignalConversionAtSerial[23] = Pacemaker_B.BytePack5[3];
  rtb_TmpSignalConversionAtSerial[27] = Pacemaker_B.BytePack6[3];
  rtb_TmpSignalConversionAtSerial[28] = Pacemaker_B.BytePack7[0];
  rtb_TmpSignalConversionAtSerial[30] = Pacemaker_B.BytePack8[0];
  rtb_TmpSignalConversionAtSerial[29] = Pacemaker_B.BytePack7[1];
  rtb_TmpSignalConversionAtSerial[31] = Pacemaker_B.BytePack8[1];
  rtb_TmpSignalConversionAtSerial[32] = Pacemaker_B.MODE;

  /* MATLABSystem: '<S1>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Pacemaker_B.TxDataLocChar[0], (void *)
           &rtb_TmpSignalConversionAtSerial[0], (uint32_T)((size_t)33 * sizeof
            (uint8_T)));
    status = MW_SCI_Transmit(Pacemaker_DW.obj_n.MW_SCIHANDLE,
      &Pacemaker_B.TxDataLocChar[0], 33U);
  }

  /* End of MATLABSystem: '<S1>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Transmit' */
  if (!Pacemaker_DW.obj_n.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_n.isInitialized == 1) &&
        Pacemaker_DW.obj_n.isSetupComplete) {
      MW_SCI_Close(Pacemaker_DW.obj_n.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
