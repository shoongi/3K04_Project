/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 5.35
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 23 17:36:22 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker.h"

/* Block parameters (default storage) */
P_Pacemaker_T Pacemaker_P = {
  /* Mask Parameter: ModeSelect_Value
   * Referenced by: '<S1>/Constant'
   */
  VOO,

  /* Mask Parameter: ModeSelect4_Value
   * Referenced by: '<S26>/Constant'
   */
  VOO,

  /* Mask Parameter: ModeSelect2_Value
   * Referenced by: '<S24>/Constant'
   */
  AOO,

  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read1'
   */
  -1.0,

  /* Expression: 60
   * Referenced by: '<S3>/LRL'
   */
  60.0,

  /* Expression: 1
   * Referenced by: '<S3>/URL'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S3>/VENT_AMP'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S3>/VENT_PW'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/ATR_AMP'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S3>/ATR_PW'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S3>/ATR_SENSITIVITY'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/ARP'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/VENT_SENSITIVITY'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/VRP'
   */
  1.0,

  /* Computed Parameter: PACING_REF_PWM_InitialOutput
   * Referenced by: '<S2>/PACING_REF_PWM'
   */
  0.0,

  /* Computed Parameter: PACE_CHARGE_CTRL_InitialOutput
   * Referenced by: '<S2>/PACE_CHARGE_CTRL'
   */
  false,

  /* Computed Parameter: VENT_GND_CTRL_InitialOutput
   * Referenced by: '<S2>/VENT_GND_CTRL'
   */
  false,

  /* Computed Parameter: VENT_PACE_CTRL_InitialOutput
   * Referenced by: '<S2>/VENT_PACE_CTRL'
   */
  false,

  /* Computed Parameter: PACE_GND_CTRL_InitialOutput
   * Referenced by: '<S2>/PACE_GND_CTRL'
   */
  false,

  /* Computed Parameter: ATR_GND_CTRL_InitialOutput
   * Referenced by: '<S2>/ATR_GND_CTRL'
   */
  false,

  /* Computed Parameter: ATR_PACE_CTRL_InitialOutput
   * Referenced by: '<S2>/ATR_PACE_CTRL'
   */
  false,

  /* Computed Parameter: FRONTEND_CTRL_InitialOutput
   * Referenced by: '<S2>/FRONTEND_CTRL'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
