/*
 * AAI.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AAI".
 *
 * Model version              : 1.18
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 25 18:48:44 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AAI_h_
#define RTW_HEADER_AAI_h_
#ifndef AAI_COMMON_INCLUDES_
#define AAI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* AAI_COMMON_INCLUDES_ */

#include "AAI_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/Chart' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/Chart' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/Chart' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/Chart' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/Chart' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/Chart' */
} B_AAI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_AAI_T obj;   /* '<Root>/Digital Read' */
  freedomk64f_DigitalWrite_AAI_T obj_l;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_AAI_T obj_m;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_AAI_T obj_j;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_AAI_T obj_n;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_AAI_T obj_i;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_AAI_T obj_ib;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_AAI_T obj_lh;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_AAI_T obj_jv;  /* '<Root>/PWM Output1' */
  freedomk64f_PWMOutput_AAI_T obj_k;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_AAI;            /* '<Root>/Chart' */
  uint8_T is_c3_AAI;                   /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<Root>/PWM Output1' */
  boolean_T objisempty_n;              /* '<Root>/PWM Output' */
  boolean_T objisempty_f;              /* '<Root>/Digital Write6' */
  boolean_T objisempty_d;              /* '<Root>/Digital Write5' */
  boolean_T objisempty_j;              /* '<Root>/Digital Write4' */
  boolean_T objisempty_jg;             /* '<Root>/Digital Write3' */
  boolean_T objisempty_b;              /* '<Root>/Digital Write2' */
  boolean_T objisempty_h;              /* '<Root>/Digital Write1' */
  boolean_T objisempty_bs;             /* '<Root>/Digital Write' */
  boolean_T objisempty_g;              /* '<Root>/Digital Read' */
} DW_AAI_T;

/* Parameters (default storage) */
struct P_AAI_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T PW_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/PW'
                                        */
  real_T Amplitude_Value;              /* Expression: 3.5
                                        * Referenced by: '<Root>/Amplitude'
                                        */
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/LRL'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 250
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AAI_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_AAI_T AAI_P;

/* Block signals (default storage) */
extern B_AAI_T AAI_B;

/* Block states (default storage) */
extern DW_AAI_T AAI_DW;

/* Model entry point functions */
extern void AAI_initialize(void);
extern void AAI_step(void);
extern void AAI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AAI_T *const AAI_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AAI'
 * '<S1>'   : 'AAI/Chart'
 */
#endif                                 /* RTW_HEADER_AAI_h_ */
