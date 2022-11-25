/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccelerometerTest_private.h
 *
 * Code generated for Simulink model 'AccelerometerTest'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 21 16:00:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AccelerometerTest_private_h_
#define RTW_HEADER_AccelerometerTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "AccelerometerTest.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void AccelerometerTest_x_Init(DW_x_AccelerometerTest_T *localDW);
extern void AccelerometerTest_x(real_T rtu_0, B_x_AccelerometerTest_T *localB,
  DW_x_AccelerometerTest_T *localDW);
extern void AccelerometerTest_x_Term(DW_x_AccelerometerTest_T *localDW);

#endif                             /* RTW_HEADER_AccelerometerTest_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
