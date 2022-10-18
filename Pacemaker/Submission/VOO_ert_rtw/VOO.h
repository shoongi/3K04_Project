/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOO.h
 *
 * Code generated for Simulink model 'VOO'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 18 02:28:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VOO_h_
#define RTW_HEADER_VOO_h_
#ifndef VOO_COMMON_INCLUDES_
#define VOO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* VOO_COMMON_INCLUDES_ */

#include "VOO_types.h"
#include <stddef.h>

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
} B_VOO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_VOO_T obj;  /* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_VOO_T obj_l;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_VOO_T obj_k;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_VOO_T obj_l0;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_VOO_T obj_n;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_VOO_T obj_i;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_VOO_T obj_m;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_VOO_T obj_g;   /* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_VOO;            /* '<Root>/Chart' */
  uint8_T is_c3_VOO;                   /* '<Root>/Chart' */
} DW_VOO_T;

/* Parameters (default storage) */
struct P_VOO_T_ {
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/LRL'
                                        */
  real_T PW_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/PW'
                                        */
  real_T Amplitude_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Amplitude'
                                        */
  real_T URL_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/URL'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VOO_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_VOO_T VOO_P;

/* Block signals (default storage) */
extern B_VOO_T VOO_B;

/* Block states (default storage) */
extern DW_VOO_T VOO_DW;

/* Model entry point functions */
extern void VOO_initialize(void);
extern void VOO_step(void);
extern void VOO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VOO_T *const VOO_M;

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
 * '<Root>' : 'VOO'
 * '<S1>'   : 'VOO/Chart'
 */
#endif                                 /* RTW_HEADER_VOO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
