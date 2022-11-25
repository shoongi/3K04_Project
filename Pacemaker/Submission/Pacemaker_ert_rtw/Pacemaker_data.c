/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
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

#include "Pacemaker.h"

/* Block parameters (default storage) */
P_Pacemaker_T Pacemaker_P = {
  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read1'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Serial Receive'
   */
  0.1,

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
  false,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S5>/Constant3'
   */
  4U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S5>/Constant1'
   */
  2U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S5>/Constant2'
   */
  3U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S5>/Constant4'
   */
  5U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
