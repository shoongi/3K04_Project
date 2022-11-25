/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: serial_test.c
 *
 * Code generated for Simulink model 'serial_test'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 21 16:28:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "serial_test.h"
#include "serial_test_types.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Block signals (default storage) */
B_serial_test_T serial_test_B;

/* Block states (default storage) */
DW_serial_test_T serial_test_DW;

/* Real-time model */
static RT_MODEL_serial_test_T serial_test_M_;
RT_MODEL_serial_test_T *const serial_test_M = &serial_test_M_;

/* Forward declaration for local functions */
static void serial_test_SystemCore_setup(freedomk64f_SCIRead_serial_te_T *obj);
static void serial_test_SystemCore_setup(freedomk64f_SCIRead_serial_te_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T SCIModuleLoc;
  uint32_T TxPinLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void serial_test_step(void)
{
  uint8_T RxDataLocChar[5];

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (serial_test_DW.obj.SampleTime != serial_test_P.SerialReceive_SampleTime) {
    serial_test_DW.obj.SampleTime = serial_test_P.SerialReceive_SampleTime;
  }

  MW_SCI_Receive(serial_test_DW.obj.MW_SCIHANDLE, &RxDataLocChar[0], 5U);
  memcpy((void *)&serial_test_B.SerialReceive_o1[0], (void *)&RxDataLocChar[0],
         (uint32_T)((size_t)5 * sizeof(uint8_T)));

  /* End of MATLABSystem: '<Root>/Serial Receive' */

  /* S-Function (byte2any): '<Root>/Byte Unpack' */

  /* Unpack: <Root>/Byte Unpack */
  (void) memcpy(&serial_test_B.ByteUnpack_o1, &serial_test_B.SerialReceive_o1[0],
                4);
  (void) memcpy(&serial_test_B.ByteUnpack_o2, &serial_test_B.SerialReceive_o1[4],
                1);
}

/* Model initialize function */
void serial_test_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  serial_test_DW.obj.isInitialized = 0;
  serial_test_DW.obj.matlabCodegenIsDeleted = false;
  serial_test_DW.obj.SampleTime = serial_test_P.SerialReceive_SampleTime;
  serial_test_SystemCore_setup(&serial_test_DW.obj);
}

/* Model terminate function */
void serial_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!serial_test_DW.obj.matlabCodegenIsDeleted) {
    serial_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((serial_test_DW.obj.isInitialized == 1) &&
        serial_test_DW.obj.isSetupComplete) {
      MW_SCI_Close(serial_test_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
