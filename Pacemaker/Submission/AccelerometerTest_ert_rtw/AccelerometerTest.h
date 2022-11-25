/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccelerometerTest.h
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

#ifndef RTW_HEADER_AccelerometerTest_h_
#define RTW_HEADER_AccelerometerTest_h_
#ifndef AccelerometerTest_COMMON_INCLUDES_
#define AccelerometerTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#endif                                 /* AccelerometerTest_COMMON_INCLUDES_ */

#include "AccelerometerTest_types.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<Root>/x' */
typedef struct {
  real_T csumrev[2499];
  real_T x;                            /* '<Root>/x' */
} B_x_AccelerometerTest_T;

/* Block states (default storage) for system '<Root>/x' */
typedef struct {
  dsp_simulink_MovingAverage_Ac_T obj; /* '<Root>/x' */
  boolean_T objisempty;                /* '<Root>/x' */
} DW_x_AccelerometerTest_T;

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[499];
  real_T FXOS87006AxesSensor[3];       /* '<Root>/FXOS8700 6-Axes Sensor' */
  real_T MovingAverage;                /* '<Root>/Moving Average' */
  real_T cumRevIndex;
  real_T csum;
  real_T modValueRev;
  real_T z_m;
  real_T TSamp;                        /* '<S1>/TSamp' */
  real_T TSamp_n;                      /* '<S2>/TSamp' */
  real_T TSamp_e;                      /* '<S3>/TSamp' */
  real_T Add;                          /* '<Root>/Add' */
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  B_x_AccelerometerTest_T z;           /* '<Root>/x' */
  B_x_AccelerometerTest_T y;           /* '<Root>/x' */
  B_x_AccelerometerTest_T x;           /* '<Root>/x' */
} B_AccelerometerTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_g_T obj;  /* '<Root>/Moving Average' */
  freedomk64f_fxos8700_Accelero_T obj_g;/* '<Root>/FXOS8700 6-Axes Sensor' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T UD_DSTATE_g;                  /* '<S2>/UD' */
  real_T UD_DSTATE_g1;                 /* '<S3>/UD' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  DW_x_AccelerometerTest_T z;          /* '<Root>/x' */
  DW_x_AccelerometerTest_T y;          /* '<Root>/x' */
  DW_x_AccelerometerTest_T x;          /* '<Root>/x' */
} DW_AccelerometerTest_T;

/* Parameters (default storage) */
struct P_AccelerometerTest_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S2>/UD'
                               */
  real_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S3>/UD'
                               */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<Root>/FXOS8700 6-Axes Sensor'
                                         */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T TSamp_WtEt_me;                /* Computed Parameter: TSamp_WtEt_me
                                        * Referenced by: '<S3>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AccelerometerTest_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_AccelerometerTest_T AccelerometerTest_P;

/* Block signals (default storage) */
extern B_AccelerometerTest_T AccelerometerTest_B;

/* Block states (default storage) */
extern DW_AccelerometerTest_T AccelerometerTest_DW;

/* Model entry point functions */
extern void AccelerometerTest_initialize(void);
extern void AccelerometerTest_step(void);
extern void AccelerometerTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AccelerometerTest_T *const AccelerometerTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 */

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
 * '<Root>' : 'AccelerometerTest'
 * '<S1>'   : 'AccelerometerTest/Discrete Derivative'
 * '<S2>'   : 'AccelerometerTest/Discrete Derivative1'
 * '<S3>'   : 'AccelerometerTest/Discrete Derivative2'
 */
#endif                                 /* RTW_HEADER_AccelerometerTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
