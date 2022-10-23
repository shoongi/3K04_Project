/*
 * AOO.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AOO".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Oct 22 23:08:00 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AOO_h_
#define RTW_HEADER_AOO_h_
#ifndef AOO_COMMON_INCLUDES_
#define AOO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* AOO_COMMON_INCLUDES_ */

#include "AOO_types.h"
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
} B_AOO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_AOO_T obj;  /* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_AOO_T obj_m;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_AOO_T obj_j;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_AOO_T obj_n;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_AOO_T obj_i;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_AOO_T obj_ib;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_AOO_T obj_l;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_AOO_T obj_k;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_AOO;            /* '<Root>/Chart' */
  uint8_T is_c3_AOO;                   /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<Root>/PWM Output' */
  boolean_T objisempty_d;              /* '<Root>/Digital Write7' */
  boolean_T objisempty_dr;             /* '<Root>/Digital Write5' */
  boolean_T objisempty_j;              /* '<Root>/Digital Write4' */
  boolean_T objisempty_jg;             /* '<Root>/Digital Write3' */
  boolean_T objisempty_b;              /* '<Root>/Digital Write2' */
  boolean_T objisempty_h;              /* '<Root>/Digital Write1' */
  boolean_T objisempty_bs;             /* '<Root>/Digital Write' */
} DW_AOO_T;

/* Parameters (default storage) */
struct P_AOO_T_ {
  real_T PW_Value;                     /* Expression: 0.5
                                        * Referenced by: '<Root>/PW'
                                        */
  real_T Amplitdue_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Amplitdue'
                                        */
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/LRL'
                                        */
  boolean_T Constant_Value;            /* Expression: true
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AOO_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_AOO_T AOO_P;

/* Block signals (default storage) */
extern B_AOO_T AOO_B;

/* Block states (default storage) */
extern DW_AOO_T AOO_DW;

/* Model entry point functions */
extern void AOO_initialize(void);
extern void AOO_step(void);
extern void AOO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AOO_T *const AOO_M;

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
 * '<Root>' : 'AOO'
 * '<S1>'   : 'AOO/Chart'
 */
#endif                                 /* RTW_HEADER_AOO_h_ */
