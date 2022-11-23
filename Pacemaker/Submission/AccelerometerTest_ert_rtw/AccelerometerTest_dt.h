/*
 * AccelerometerTest_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AccelerometerTest".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Mon Nov 21 16:00:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(freedomk64f_fxos8700_Accelero_T),
  sizeof(dsp_simulink_MovingAverage_g_T),
  sizeof(dsp_simulink_MovingAverage_Ac_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "freedomk64f_fxos8700_Accelero_T",
  "dsp_simulink_MovingAverage_g_T",
  "dsp_simulink_MovingAverage_Ac_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AccelerometerTest_B.MovingAverage), 0, 0, 1 },

  { (char_T *)(&AccelerometerTest_B.z.x), 0, 0, 1 },

  { (char_T *)(&AccelerometerTest_B.y.x), 0, 0, 1 },

  { (char_T *)(&AccelerometerTest_B.x.x), 0, 0, 1 }
  ,

  { (char_T *)(&AccelerometerTest_DW.obj), 16, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.obj_g), 15, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.UD_DSTATE), 0, 0, 3 },

  { (char_T *)(&AccelerometerTest_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.z.obj), 17, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.z.objisempty), 8, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.y.obj), 17, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.y.objisempty), 8, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.x.obj), 17, 0, 1 },

  { (char_T *)(&AccelerometerTest_DW.x.objisempty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AccelerometerTest_P.DiscreteDerivative_ICPrevScaled), 0, 0, 7 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] AccelerometerTest_dt.h */
