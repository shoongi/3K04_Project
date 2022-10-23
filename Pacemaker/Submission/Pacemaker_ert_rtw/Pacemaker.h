/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 5.33
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 22 21:42:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#ifndef Pacemaker_COMMON_INCLUDES_
#define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"
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
  real_T PACING_REF_PWM;               /* '<S2>/PACING_REF_PWM' */
  real_T PACING_REF_PWM_n;             /* '<S7>/Chart' */
  real_T PACING_REF_PWM_k;             /* '<S6>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S2>/PACE_CHARGE_CTRL' */
  boolean_T VENT_GND_CTRL;             /* '<S2>/VENT_GND_CTRL' */
  boolean_T VENT_PACE_CTRL;            /* '<S2>/VENT_PACE_CTRL' */
  boolean_T PACE_GND_CTRL;             /* '<S2>/PACE_GND_CTRL' */
  boolean_T ATR_GND_CTRL;              /* '<S2>/ATR_GND_CTRL' */
  boolean_T ATR_PACE_CTRL;             /* '<S2>/ATR_PACE_CTRL' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_Pace_T obj; /* '<S5>/Digital Write5' */
  freedomk64f_DigitalWrite_Pace_T obj_h;/* '<S5>/Digital Write4' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S5>/Digital Write3' */
  freedomk64f_DigitalWrite_Pace_T obj_j;/* '<S5>/Digital Write2' */
  freedomk64f_DigitalWrite_Pace_T obj_d;/* '<S5>/Digital Write1' */
  freedomk64f_DigitalWrite_Pace_T obj_e;/* '<S5>/Digital Write' */
  freedomk64f_PWMOutput_Pacemak_T obj_p;/* '<S5>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<S7>/Chart' */
  uint32_T temporalCounter_i1_a;       /* '<S6>/Chart' */
  uint8_T is_active_c3_Pacemaker;      /* '<S7>/Chart' */
  uint8_T is_c3_Pacemaker;             /* '<S7>/Chart' */
  uint8_T is_active_c1_Pacemaker;      /* '<S6>/Chart' */
  uint8_T is_c1_Pacemaker;             /* '<S6>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  Pacemaker_Mode ModeSelect_Value;     /* Mask Parameter: ModeSelect_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
  Pacemaker_Mode ModeSelect4_Value;    /* Mask Parameter: ModeSelect4_Value
                                        * Referenced by: '<S22>/Constant'
                                        */
  Pacemaker_Mode ModeSelect2_Value;    /* Mask Parameter: ModeSelect2_Value
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<S3>/LRL'
                                        */
  real_T URL_Value;                    /* Expression: 1
                                        * Referenced by: '<S3>/URL'
                                        */
  real_T VENT_AMP_Value;               /* Expression: 3
                                        * Referenced by: '<S3>/VENT_AMP'
                                        */
  real_T VENT_PW_Value;                /* Expression: 1
                                        * Referenced by: '<S3>/VENT_PW'
                                        */
  real_T ATR_AMP_Value;                /* Expression: 1
                                        * Referenced by: '<S3>/ATR_AMP'
                                        */
  real_T ATR_PW_Value;                 /* Expression: 3
                                        * Referenced by: '<S3>/ATR_PW'
                                        */
  real_T PACING_REF_PWM_InitialOutput;
                             /* Computed Parameter: PACING_REF_PWM_InitialOutput
                              * Referenced by: '<S2>/PACING_REF_PWM'
                              */
  boolean_T PACE_CHARGE_CTRL_InitialOutput;
                           /* Computed Parameter: PACE_CHARGE_CTRL_InitialOutput
                            * Referenced by: '<S2>/PACE_CHARGE_CTRL'
                            */
  boolean_T VENT_GND_CTRL_InitialOutput;
                              /* Computed Parameter: VENT_GND_CTRL_InitialOutput
                               * Referenced by: '<S2>/VENT_GND_CTRL'
                               */
  boolean_T VENT_PACE_CTRL_InitialOutput;
                             /* Computed Parameter: VENT_PACE_CTRL_InitialOutput
                              * Referenced by: '<S2>/VENT_PACE_CTRL'
                              */
  boolean_T PACE_GND_CTRL_InitialOutput;
                              /* Computed Parameter: PACE_GND_CTRL_InitialOutput
                               * Referenced by: '<S2>/PACE_GND_CTRL'
                               */
  boolean_T ATR_GND_CTRL_InitialOutput;
                               /* Computed Parameter: ATR_GND_CTRL_InitialOutput
                                * Referenced by: '<S2>/ATR_GND_CTRL'
                                */
  boolean_T ATR_PACE_CTRL_InitialOutput;
                              /* Computed Parameter: ATR_PACE_CTRL_InitialOutput
                               * Referenced by: '<S2>/ATR_PACE_CTRL'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Pacemaker_T Pacemaker_P;

/* Block signals (default storage) */
extern B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
extern DW_Pacemaker_T Pacemaker_DW;

/* Model entry point functions */
extern void Pacemaker_initialize(void);
extern void Pacemaker_step(void);
extern void Pacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_T *const Pacemaker_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/ACT_THRESHOLD' : Unused code path elimination
 * Block '<S3>/ARP' : Unused code path elimination
 * Block '<S3>/ATR_DURATION' : Unused code path elimination
 * Block '<S3>/ATR_FALLBACK_MODE' : Unused code path elimination
 * Block '<S3>/ATR_FALLBACK_TIME' : Unused code path elimination
 * Block '<S3>/ATR_SENSITIVITY' : Unused code path elimination
 * Block '<S3>/DYN_AV_DELAY' : Unused code path elimination
 * Block '<S3>/FIXED_AV_DELAY' : Unused code path elimination
 * Block '<S3>/HYSTERESIS' : Unused code path elimination
 * Block '<S3>/MAX_SENSE_RATE' : Unused code path elimination
 * Block '<S3>/PVARP' : Unused code path elimination
 * Block '<S3>/PVARP_EXTENSION' : Unused code path elimination
 * Block '<S3>/RATE_SMOOTH' : Unused code path elimination
 * Block '<S3>/REACT_TIME' : Unused code path elimination
 * Block '<S3>/RECOVERY_TIME' : Unused code path elimination
 * Block '<S3>/RESPONSE_FACTOR' : Unused code path elimination
 * Block '<S3>/SENSE_AV_DELAY_OFFSET' : Unused code path elimination
 * Block '<S3>/VENT_SENSITIVITY' : Unused code path elimination
 * Block '<S3>/VRP' : Unused code path elimination
 * Block '<S4>/Equal' : Unused code path elimination
 * Block '<S4>/Equal1' : Unused code path elimination
 * Block '<S4>/Equal10' : Unused code path elimination
 * Block '<S4>/Equal11' : Unused code path elimination
 * Block '<S4>/Equal12' : Unused code path elimination
 * Block '<S4>/Equal13' : Unused code path elimination
 * Block '<S4>/Equal14' : Unused code path elimination
 * Block '<S4>/Equal15' : Unused code path elimination
 * Block '<S4>/Equal16' : Unused code path elimination
 * Block '<S4>/Equal17' : Unused code path elimination
 * Block '<S4>/Equal3' : Unused code path elimination
 * Block '<S4>/Equal5' : Unused code path elimination
 * Block '<S4>/Equal6' : Unused code path elimination
 * Block '<S4>/Equal7' : Unused code path elimination
 * Block '<S4>/Equal8' : Unused code path elimination
 * Block '<S4>/Equal9' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S21>/Constant' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S24>/Constant' : Unused code path elimination
 * Block '<S25>/Constant' : Unused code path elimination
 * Block '<S26>/Constant' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
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
 * '<Root>' : 'Pacemaker'
 * '<S1>'   : 'Pacemaker/Mode Select'
 * '<S2>'   : 'Pacemaker/Modes'
 * '<S3>'   : 'Pacemaker/Parameter Definitions'
 * '<S4>'   : 'Pacemaker/Subsystem Reference'
 * '<S5>'   : 'Pacemaker/Subsystem Reference1'
 * '<S6>'   : 'Pacemaker/Modes/Subsystem Reference'
 * '<S7>'   : 'Pacemaker/Modes/Subsystem Reference1'
 * '<S8>'   : 'Pacemaker/Modes/Subsystem Reference/Chart'
 * '<S9>'   : 'Pacemaker/Modes/Subsystem Reference1/Chart'
 * '<S10>'  : 'Pacemaker/Subsystem Reference/Mode Select'
 * '<S11>'  : 'Pacemaker/Subsystem Reference/Mode Select1'
 * '<S12>'  : 'Pacemaker/Subsystem Reference/Mode Select10'
 * '<S13>'  : 'Pacemaker/Subsystem Reference/Mode Select11'
 * '<S14>'  : 'Pacemaker/Subsystem Reference/Mode Select12'
 * '<S15>'  : 'Pacemaker/Subsystem Reference/Mode Select13'
 * '<S16>'  : 'Pacemaker/Subsystem Reference/Mode Select14'
 * '<S17>'  : 'Pacemaker/Subsystem Reference/Mode Select15'
 * '<S18>'  : 'Pacemaker/Subsystem Reference/Mode Select16'
 * '<S19>'  : 'Pacemaker/Subsystem Reference/Mode Select17'
 * '<S20>'  : 'Pacemaker/Subsystem Reference/Mode Select2'
 * '<S21>'  : 'Pacemaker/Subsystem Reference/Mode Select3'
 * '<S22>'  : 'Pacemaker/Subsystem Reference/Mode Select4'
 * '<S23>'  : 'Pacemaker/Subsystem Reference/Mode Select5'
 * '<S24>'  : 'Pacemaker/Subsystem Reference/Mode Select6'
 * '<S25>'  : 'Pacemaker/Subsystem Reference/Mode Select7'
 * '<S26>'  : 'Pacemaker/Subsystem Reference/Mode Select8'
 * '<S27>'  : 'Pacemaker/Subsystem Reference/Mode Select9'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
