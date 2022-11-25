/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
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

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#ifndef Pacemaker_COMMON_INCLUDES_
#define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_SCI.h"
#include "MW_PWM.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"
#include <stddef.h>
#include "echo_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[34];
  uint8_T RxDataLocChar[34];
  uint8_T TxDataLocChar[33];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  real_T PACING_REF_PWM;               /* '<S2>/PACING_REF_PWM' */
  real_T PACING_REF_PWM_n;             /* '<S10>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<S10>/Chart' */
  real_T PACING_REF_PWM_l;             /* '<S9>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<S9>/Chart' */
  real_T PACING_REF_PWM_na;            /* '<S8>/Chart' */
  real_T PACING_REF_PWM_k;             /* '<S7>/Chart' */
  real32_T ATR_AMP;
  real32_T ATR_PW;
  real32_T ATR_SENSITIVITY;
  real32_T VENT_AMP;
  real32_T VENT_PW;
  real32_T VENT_SENSITIVITY;
  real32_T ATR_AMP_g;                  /* '<S4>/Chart' */
  real32_T ATR_PW_k;                   /* '<S4>/Chart' */
  real32_T ATR_SENSITIVITY_o;          /* '<S4>/Chart' */
  real32_T VENT_AMP_c;                 /* '<S4>/Chart' */
  real32_T VENT_PW_j;                  /* '<S4>/Chart' */
  real32_T VENT_SENSITIVITY_f;         /* '<S4>/Chart' */
  uint16_T VRP;
  uint16_T ARP;
  uint16_T PVARP;
  uint16_T ARP_d;                      /* '<S4>/Chart' */
  uint16_T PVARP_m;                    /* '<S4>/Chart' */
  uint16_T VRP_g;                      /* '<S4>/Chart' */
  uint8_T BytePack[4];                 /* '<S1>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S1>/Byte Pack1' */
  uint8_T BytePack2[4];                /* '<S1>/Byte Pack2' */
  uint8_T BytePack3[2];                /* '<S1>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S1>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S1>/Byte Pack5' */
  uint8_T BytePack6[4];                /* '<S1>/Byte Pack6' */
  uint8_T BytePack7[2];                /* '<S1>/Byte Pack7' */
  uint8_T BytePack8[2];                /* '<S1>/Byte Pack8' */
  uint8_T LRL;                         /* '<S4>/Chart' */
  uint8_T URL;                         /* '<S4>/Chart' */
  uint8_T MODE;                        /* '<S4>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S2>/PACE_CHARGE_CTRL' */
  boolean_T VENT_GND_CTRL;             /* '<S2>/VENT_GND_CTRL' */
  boolean_T VENT_PACE_CTRL;            /* '<S2>/VENT_PACE_CTRL' */
  boolean_T PACE_GND_CTRL;             /* '<S2>/PACE_GND_CTRL' */
  boolean_T ATR_GND_CTRL;              /* '<S2>/ATR_GND_CTRL' */
  boolean_T ATR_PACE_CTRL;             /* '<S2>/ATR_PACE_CTRL' */
  boolean_T FRONTEND_CTRL;             /* '<S2>/FRONTEND_CTRL' */
  boolean_T ATR_GND_CTRL_g;            /* '<S10>/Chart' */
  boolean_T ATR_PACE_CTRL_j;           /* '<S10>/Chart' */
  boolean_T PACE_CHARGE_CTRL_j;        /* '<S10>/Chart' */
  boolean_T VENT_GND_CTRL_i;           /* '<S10>/Chart' */
  boolean_T VENT_PACE_CTRL_k;          /* '<S10>/Chart' */
  boolean_T PACE_GND_CTRL_f;           /* '<S10>/Chart' */
  boolean_T FRONTEND_CTRL_p;           /* '<S10>/Chart' */
  boolean_T PACE_CHARGE_CTRL_h;        /* '<S9>/Chart' */
  boolean_T VENT_PACE_CTRL_m;          /* '<S9>/Chart' */
  boolean_T VENT_GND_CTRL_n;           /* '<S9>/Chart' */
  boolean_T PACE_GND_CTRL_j;           /* '<S9>/Chart' */
  boolean_T ATR_GND_CTRL_i;            /* '<S9>/Chart' */
  boolean_T ATR_PACE_CTRL_i;           /* '<S9>/Chart' */
  boolean_T FRONTEND_CTRL_i;           /* '<S9>/Chart' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Pacem_T obj; /* '<S3>/Digital Read1' */
  freedomk64f_DigitalRead_Pacem_T obj_i;/* '<S3>/Digital Read' */
  freedomk64f_SCIRead_Pacemaker_T obj_j;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Pacemake_T obj_n;/* '<S1>/Serial Transmit' */
  freedomk64f_DigitalWrite_Pace_T obj_jl;/* '<S6>/Digital Write6' */
  freedomk64f_DigitalWrite_Pace_T obj_j3;/* '<S6>/Digital Write5' */
  freedomk64f_DigitalWrite_Pace_T obj_h;/* '<S6>/Digital Write4' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S6>/Digital Write3' */
  freedomk64f_DigitalWrite_Pace_T obj_jz;/* '<S6>/Digital Write2' */
  freedomk64f_DigitalWrite_Pace_T obj_d;/* '<S6>/Digital Write1' */
  freedomk64f_DigitalWrite_Pace_T obj_e;/* '<S6>/Digital Write' */
  freedomk64f_PWMOutput_Pacemak_T obj_f;/* '<S6>/PWM Output2' */
  freedomk64f_PWMOutput_Pacemak_T obj_dp;/* '<S6>/PWM Output1' */
  freedomk64f_PWMOutput_Pacemak_T obj_p;/* '<S6>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<S10>/Chart' */
  uint32_T temporalCounter_i1_f;       /* '<S9>/Chart' */
  uint32_T temporalCounter_i1_b;       /* '<S8>/Chart' */
  uint32_T temporalCounter_i1_a;       /* '<S7>/Chart' */
  uint8_T is_active_c5_Pacemaker;      /* '<S4>/Chart' */
  uint8_T is_c5_Pacemaker;             /* '<S4>/Chart' */
  uint8_T is_active_c4_Pacemaker;      /* '<S10>/Chart' */
  uint8_T is_c4_Pacemaker;             /* '<S10>/Chart' */
  uint8_T is_active_c2_Pacemaker;      /* '<S9>/Chart' */
  uint8_T is_c2_Pacemaker;             /* '<S9>/Chart' */
  uint8_T is_active_c3_Pacemaker;      /* '<S8>/Chart' */
  uint8_T is_c3_Pacemaker;             /* '<S8>/Chart' */
  uint8_T is_active_c1_Pacemaker;      /* '<S7>/Chart' */
  uint8_T is_c1_Pacemaker;             /* '<S7>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Serial Receive'
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
  boolean_T FRONTEND_CTRL_InitialOutput;
                              /* Computed Parameter: FRONTEND_CTRL_InitialOutput
                               * Referenced by: '<S2>/FRONTEND_CTRL'
                               */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S5>/Constant3'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S5>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S5>/Constant2'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S5>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Pacemaker_T Pacemaker_P;

/* Block signals (default storage) */
extern B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
extern DW_Pacemaker_T Pacemaker_DW;

/* External function called from main */
extern void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Pacemaker_initialize(void);
extern void Pacemaker_step0(void);
extern void Pacemaker_step1(void);
extern void Pacemaker_step(int_T tid);
extern void Pacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_T *const Pacemaker_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/ACT_THRESHOLD' : Unused code path elimination
 * Block '<S3>/ATR_DURATION' : Unused code path elimination
 * Block '<S3>/ATR_FALLBACK_MODE' : Unused code path elimination
 * Block '<S3>/ATR_FALLBACK_TIME' : Unused code path elimination
 * Block '<S3>/Cast To Double6' : Unused code path elimination
 * Block '<S3>/DYN_AV_DELAY' : Unused code path elimination
 * Block '<S3>/FIXED_AV_DELAY' : Unused code path elimination
 * Block '<S3>/HYSTERESIS' : Unused code path elimination
 * Block '<S3>/MAX_SENSE_RATE' : Unused code path elimination
 * Block '<S3>/PVARP_EXTENSION' : Unused code path elimination
 * Block '<S3>/RATE_SMOOTH' : Unused code path elimination
 * Block '<S3>/REACT_TIME' : Unused code path elimination
 * Block '<S3>/RECOVERY_TIME' : Unused code path elimination
 * Block '<S3>/RESPONSE_FACTOR' : Unused code path elimination
 * Block '<S3>/SENSE_AV_DELAY_OFFSET' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/Constant10' : Unused code path elimination
 * Block '<S5>/Constant11' : Unused code path elimination
 * Block '<S5>/Constant12' : Unused code path elimination
 * Block '<S5>/Constant13' : Unused code path elimination
 * Block '<S5>/Constant14' : Unused code path elimination
 * Block '<S5>/Constant15' : Unused code path elimination
 * Block '<S5>/Constant16' : Unused code path elimination
 * Block '<S5>/Constant17' : Unused code path elimination
 * Block '<S5>/Constant5' : Unused code path elimination
 * Block '<S5>/Constant6' : Unused code path elimination
 * Block '<S5>/Constant7' : Unused code path elimination
 * Block '<S5>/Constant8' : Unused code path elimination
 * Block '<S5>/Constant9' : Unused code path elimination
 * Block '<S5>/Equal' : Unused code path elimination
 * Block '<S5>/Equal1' : Unused code path elimination
 * Block '<S5>/Equal10' : Unused code path elimination
 * Block '<S5>/Equal11' : Unused code path elimination
 * Block '<S5>/Equal12' : Unused code path elimination
 * Block '<S5>/Equal13' : Unused code path elimination
 * Block '<S5>/Equal14' : Unused code path elimination
 * Block '<S5>/Equal15' : Unused code path elimination
 * Block '<S5>/Equal16' : Unused code path elimination
 * Block '<S5>/Equal17' : Unused code path elimination
 * Block '<S5>/Equal6' : Unused code path elimination
 * Block '<S5>/Equal7' : Unused code path elimination
 * Block '<S5>/Equal8' : Unused code path elimination
 * Block '<S5>/Equal9' : Unused code path elimination
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
 * '<S1>'   : 'Pacemaker/Function-Call Subsystem'
 * '<S2>'   : 'Pacemaker/Modes'
 * '<S3>'   : 'Pacemaker/Parameter Definitions'
 * '<S4>'   : 'Pacemaker/Subsystem'
 * '<S5>'   : 'Pacemaker/Subsystem Reference'
 * '<S6>'   : 'Pacemaker/Subsystem Reference1'
 * '<S7>'   : 'Pacemaker/Modes/Subsystem Reference'
 * '<S8>'   : 'Pacemaker/Modes/Subsystem Reference1'
 * '<S9>'   : 'Pacemaker/Modes/Subsystem Reference2'
 * '<S10>'  : 'Pacemaker/Modes/Subsystem Reference3'
 * '<S11>'  : 'Pacemaker/Modes/Subsystem Reference/Chart'
 * '<S12>'  : 'Pacemaker/Modes/Subsystem Reference1/Chart'
 * '<S13>'  : 'Pacemaker/Modes/Subsystem Reference2/Chart'
 * '<S14>'  : 'Pacemaker/Modes/Subsystem Reference3/Chart'
 * '<S15>'  : 'Pacemaker/Subsystem/Chart'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
