/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
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
#include "Pacemaker_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "echo_params.h"
#include "echo_params_private.h"

/* Named constants for Chart: '<S7>/Chart' */
#define Pacemaker_IN_AOO_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_AOO_Pacing        ((uint8_T)2U)

/* Named constants for Chart: '<S8>/Chart' */
#define Pacemaker_IN_C22_CHARGE        ((uint8_T)1U)
#define Pacemaker_IN_C22_DISCHARGE     ((uint8_T)2U)

/* Named constants for Chart: '<S9>/Chart' */
#define Pacemaker_IN_VVI_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_VVI_Pacing        ((uint8_T)2U)
#define Pacemaker_IN_VVI_Sensing       ((uint8_T)3U)

/* Named constants for Chart: '<S10>/Chart' */
#define Pacemaker_IN_AAI_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_AAI_Pacing        ((uint8_T)2U)
#define Pacemaker_IN_AAI_Sensing       ((uint8_T)3U)

/* Named constants for Chart: '<S4>/Chart' */
#define Pacemaker_IN_DEFAULT           ((uint8_T)1U)
#define Pacemaker_IN_ECHO_PARAMETERS   ((uint8_T)2U)
#define Pacemaker_IN_SET_PARAMS        ((uint8_T)3U)
#define Pacemaker_IN_STANDBY           ((uint8_T)4U)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
static RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Forward declaration for local functions */
static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Pacemaker_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Pacemaker_M->Timing.TaskCounters.TID[1])++;
  if ((Pacemaker_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Pacemaker_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pacemaker_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Pacemaker_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Pacemaker_B.SCIModuleLoc, false, 10U,
    Pacemaker_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Pacemaker_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Pacemaker_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void Pacemaker_step0(void)             /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Pacemaker_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  uint8_T status;
  boolean_T rtb_AMP_CMP_DETECT_0;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Pacemaker_DW.obj_j.SampleTime != Pacemaker_P.SerialReceive_SampleTime) {
    Pacemaker_DW.obj_j.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Pacemaker_DW.obj_j.MW_SCIHANDLE,
    &Pacemaker_B.RxDataLocChar[0], 34U);
  memcpy((void *)&Pacemaker_B.RxData[0], (void *)&Pacemaker_B.RxDataLocChar[0],
         (uint32_T)((size_t)34 * sizeof(uint8_T)));

  /* Chart: '<S4>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Pacemaker_DW.is_active_c5_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c5_Pacemaker = 1U;
    Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_DEFAULT;
    Pacemaker_B.LRL = 60U;
    Pacemaker_B.URL = 120U;
    Pacemaker_B.VENT_AMP_c = 3.5F;
    Pacemaker_B.VENT_PW_j = 1.0F;
    Pacemaker_B.VENT_SENSITIVITY_f = 2.0F;
    Pacemaker_B.VRP_g = 320U;
    Pacemaker_B.ATR_AMP_g = 3.5F;
    Pacemaker_B.ATR_PW_k = 1.0F;
    Pacemaker_B.ATR_SENSITIVITY_o = 2.0F;
    Pacemaker_B.ARP_d = 250U;
    Pacemaker_B.PVARP_m = 1U;
    Pacemaker_B.MODE = 4U;
  } else {
    switch (Pacemaker_DW.is_c5_Pacemaker) {
     case Pacemaker_IN_DEFAULT:
      Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_STANDBY;
      break;

     case Pacemaker_IN_ECHO_PARAMETERS:
      Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_STANDBY;
      break;

     case Pacemaker_IN_SET_PARAMS:
      Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_ECHO_PARAMETERS;
      echo_params();
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (Pacemaker_B.RxData[0] == 16) {
          Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_SET_PARAMS;
          Pacemaker_B.LRL = Pacemaker_B.RxData[1];
          Pacemaker_B.URL = Pacemaker_B.RxData[2];
          memcpy((void *)&Pacemaker_B.VENT_AMP_c, (void *)&Pacemaker_B.RxData[3],
                 (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VENT_PW_j, (void *)&Pacemaker_B.RxData[7],
                 (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VENT_SENSITIVITY_f, (void *)
                 &Pacemaker_B.RxData[11], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VRP_g, (void *)&Pacemaker_B.RxData[15],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&Pacemaker_B.ATR_AMP_g, (void *)&Pacemaker_B.RxData[17],
                 (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.ATR_PW_k, (void *)&Pacemaker_B.RxData[21],
                 (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.ATR_SENSITIVITY_o, (void *)
                 &Pacemaker_B.RxData[25], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.ARP_d, (void *)&Pacemaker_B.RxData[29],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&Pacemaker_B.PVARP_m, (void *)&Pacemaker_B.RxData[31],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          Pacemaker_B.MODE = Pacemaker_B.RxData[33];
        } else {
          Pacemaker_DW.is_c5_Pacemaker = Pacemaker_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference1' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* RelationalOperator: '<S5>/Equal4' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  if (Pacemaker_B.MODE == Pacemaker_P.Constant3_Value) {
    /* Chart: '<S8>/Chart' incorporates:
     *  DataTypeConversion: '<S3>/Cast To Double'
     *  DataTypeConversion: '<S3>/Cast To Double7'
     *  DataTypeConversion: '<S3>/Cast To Double8'
     */
    if (Pacemaker_DW.temporalCounter_i1_b < MAX_uint32_T) {
      Pacemaker_DW.temporalCounter_i1_b++;
    }

    if (Pacemaker_DW.is_active_c3_Pacemaker == 0U) {
      Pacemaker_DW.is_active_c3_Pacemaker = 1U;
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_C22_CHARGE;
      Pacemaker_DW.temporalCounter_i1_b = 0U;

      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = false;

      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = false;
      Pacemaker_B.PACING_REF_PWM_na = Pacemaker_B.VENT_AMP_c / 5.0 * 100.0;

      /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
       *  DataTypeConversion: '<S3>/Cast To Double7'
       */
      Pacemaker_B.PACE_CHARGE_CTRL = true;

      /* Merge: '<S2>/PACE_GND_CTRL' */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = false;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = true;
    } else if (Pacemaker_DW.is_c3_Pacemaker == Pacemaker_IN_C22_CHARGE) {
      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = false;

      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = false;

      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
      Pacemaker_B.PACE_CHARGE_CTRL = true;

      /* Merge: '<S2>/PACE_GND_CTRL' */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = false;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = true;
      if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_b * 100) >=
          (uint32_T)ceil(60000.0 / (real_T)Pacemaker_B.LRL -
                         Pacemaker_B.VENT_PW_j)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_C22_DISCHARGE;
        Pacemaker_DW.temporalCounter_i1_b = 0U;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = false;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = false;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = true;
      }
    } else {
      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
      /* case IN_C22_DISCHARGE: */
      Pacemaker_B.PACE_CHARGE_CTRL = false;

      /* Merge: '<S2>/PACE_GND_CTRL' */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = false;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = false;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = false;

      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = true;
      if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_b * 100) >=
          (uint32_T)ceil(Pacemaker_B.VENT_PW_j)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_C22_CHARGE;
        Pacemaker_DW.temporalCounter_i1_b = 0U;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.PACING_REF_PWM_na = Pacemaker_B.VENT_AMP_c / 5.0 * 100.0;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
         *  DataTypeConversion: '<S3>/Cast To Double7'
         */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = true;
      }
    }

    /* End of Chart: '<S8>/Chart' */

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S8>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_na;
  }

  /* End of RelationalOperator: '<S5>/Equal4' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference1' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S5>/Equal2' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if (Pacemaker_B.MODE == Pacemaker_P.Constant1_Value) {
    /* Chart: '<S7>/Chart' incorporates:
     *  DataTypeConversion: '<S3>/Cast To Double'
     *  DataTypeConversion: '<S3>/Cast To Double3'
     *  DataTypeConversion: '<S3>/Cast To Double4'
     */
    if (Pacemaker_DW.temporalCounter_i1_a < MAX_uint32_T) {
      Pacemaker_DW.temporalCounter_i1_a++;
    }

    if (Pacemaker_DW.is_active_c1_Pacemaker == 0U) {
      Pacemaker_DW.is_active_c1_Pacemaker = 1U;
      Pacemaker_DW.is_c1_Pacemaker = Pacemaker_IN_AOO_Charging_C22;
      Pacemaker_DW.temporalCounter_i1_a = 0U;

      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = false;

      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = false;

      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
      Pacemaker_B.PACE_CHARGE_CTRL = true;
      Pacemaker_B.PACING_REF_PWM_k = Pacemaker_B.ATR_AMP_g * 20.0;

      /* Merge: '<S2>/PACE_GND_CTRL' incorporates:
       *  DataTypeConversion: '<S3>/Cast To Double3'
       */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = false;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = true;
    } else if (Pacemaker_DW.is_c1_Pacemaker == Pacemaker_IN_AOO_Charging_C22) {
      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = false;

      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = false;

      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
      Pacemaker_B.PACE_CHARGE_CTRL = true;

      /* Merge: '<S2>/PACE_GND_CTRL' */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = false;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = true;
      if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_a * 100) >=
          (uint32_T)ceil(60000.0 / (real_T)Pacemaker_B.LRL -
                         Pacemaker_B.ATR_PW_k)) {
        Pacemaker_DW.is_c1_Pacemaker = Pacemaker_IN_AOO_Pacing;
        Pacemaker_DW.temporalCounter_i1_a = 0U;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = false;

        /* Merge: '<S2>/ATR_GND_CTRL' */
        Pacemaker_B.ATR_GND_CTRL = false;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = true;
      }
    } else {
      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
      /* case IN_AOO_Pacing: */
      Pacemaker_B.PACE_CHARGE_CTRL = false;

      /* Merge: '<S2>/PACE_GND_CTRL' */
      Pacemaker_B.PACE_GND_CTRL = true;

      /* Merge: '<S2>/VENT_PACE_CTRL' */
      Pacemaker_B.VENT_PACE_CTRL = false;

      /* Merge: '<S2>/VENT_GND_CTRL' */
      Pacemaker_B.VENT_GND_CTRL = false;

      /* Merge: '<S2>/ATR_GND_CTRL' */
      Pacemaker_B.ATR_GND_CTRL = false;

      /* Merge: '<S2>/ATR_PACE_CTRL' */
      Pacemaker_B.ATR_PACE_CTRL = true;
      if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_a * 100) >=
          (uint32_T)ceil(Pacemaker_B.ATR_PW_k)) {
        Pacemaker_DW.is_c1_Pacemaker = Pacemaker_IN_AOO_Charging_C22;
        Pacemaker_DW.temporalCounter_i1_a = 0U;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = false;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;
        Pacemaker_B.PACING_REF_PWM_k = Pacemaker_B.ATR_AMP_g * 20.0;

        /* Merge: '<S2>/ATR_GND_CTRL' incorporates:
         *  DataTypeConversion: '<S3>/Cast To Double3'
         */
        Pacemaker_B.ATR_GND_CTRL = true;
      }
    }

    /* End of Chart: '<S7>/Chart' */

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S7>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_k;
  }

  /* End of RelationalOperator: '<S5>/Equal2' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference' */

  /* MATLABSystem: '<S3>/Digital Read1' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.DigitalRead1_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
  }

  rtb_AMP_CMP_DETECT_0 = MW_digitalIO_read(Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference3' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* RelationalOperator: '<S5>/Equal3' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  if (Pacemaker_B.MODE == Pacemaker_P.Constant2_Value) {
    /* Chart: '<S10>/Chart' incorporates:
     *  DataTypeConversion: '<S3>/Cast To Double'
     *  DataTypeConversion: '<S3>/Cast To Double2'
     *  DataTypeConversion: '<S3>/Cast To Double3'
     *  DataTypeConversion: '<S3>/Cast To Double4'
     *  DataTypeConversion: '<S3>/Cast To Double5'
     *  MATLABSystem: '<S3>/Digital Read1'
     */
    if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
      Pacemaker_DW.temporalCounter_i1++;
    }

    if (Pacemaker_DW.is_active_c4_Pacemaker == 0U) {
      Pacemaker_DW.is_active_c4_Pacemaker = 1U;
      Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
      Pacemaker_DW.temporalCounter_i1 = 0U;
      Pacemaker_B.VENT_PACE_CTRL_k = false;
      Pacemaker_B.ATR_PACE_CTRL_j = false;
      Pacemaker_B.PACE_CHARGE_CTRL_j = true;
      Pacemaker_B.PACING_REF_PWM_n = Pacemaker_B.ATR_AMP_g * 20.0;
      Pacemaker_B.PACE_GND_CTRL_f = true;
      Pacemaker_B.VENT_GND_CTRL_i = false;
      Pacemaker_B.ATR_GND_CTRL_g = true;
    } else {
      switch (Pacemaker_DW.is_c4_Pacemaker) {
       case Pacemaker_IN_AAI_Charging_C22:
        Pacemaker_B.VENT_PACE_CTRL_k = false;
        Pacemaker_B.ATR_PACE_CTRL_j = false;
        Pacemaker_B.PACE_CHARGE_CTRL_j = true;
        Pacemaker_B.PACE_GND_CTRL_f = true;
        Pacemaker_B.VENT_GND_CTRL_i = false;
        Pacemaker_B.ATR_GND_CTRL_g = true;
        if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1 * 100) >=
            Pacemaker_B.ARP_d) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Sensing;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.FRONTEND_CTRL_p = true;
          Pacemaker_B.ATR_CMP_REF_PWM = Pacemaker_B.ATR_SENSITIVITY_o * 30.0;
        }
        break;

       case Pacemaker_IN_AAI_Pacing:
        Pacemaker_B.PACE_CHARGE_CTRL_j = false;
        Pacemaker_B.PACE_GND_CTRL_f = true;
        Pacemaker_B.VENT_PACE_CTRL_k = false;
        Pacemaker_B.VENT_GND_CTRL_i = false;
        Pacemaker_B.ATR_GND_CTRL_g = false;
        Pacemaker_B.ATR_PACE_CTRL_j = true;
        if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1 * 100) >=
            (uint32_T)ceil(Pacemaker_B.ATR_PW_k)) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.ATR_PACE_CTRL_j = false;
          Pacemaker_B.PACE_CHARGE_CTRL_j = true;
          Pacemaker_B.PACING_REF_PWM_n = Pacemaker_B.ATR_AMP_g * 20.0;
          Pacemaker_B.ATR_GND_CTRL_g = true;
        }
        break;

       default:
        /* case IN_AAI_Sensing: */
        Pacemaker_B.FRONTEND_CTRL_p = true;
        if (rtb_AMP_CMP_DETECT_0) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.VENT_PACE_CTRL_k = false;
          Pacemaker_B.ATR_PACE_CTRL_j = false;
          Pacemaker_B.PACE_CHARGE_CTRL_j = true;
          Pacemaker_B.PACING_REF_PWM_n = Pacemaker_B.ATR_AMP_g * 20.0;
          Pacemaker_B.PACE_GND_CTRL_f = true;
          Pacemaker_B.VENT_GND_CTRL_i = false;
          Pacemaker_B.ATR_GND_CTRL_g = true;
        } else if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1 * 100) >=
                   (uint32_T)ceil((60000.0 / (real_T)Pacemaker_B.LRL - (real_T)
                     Pacemaker_B.ARP_d) - Pacemaker_B.ATR_PW_k)) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Pacing;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.PACE_CHARGE_CTRL_j = false;
          Pacemaker_B.PACE_GND_CTRL_f = true;
          Pacemaker_B.VENT_PACE_CTRL_k = false;
          Pacemaker_B.VENT_GND_CTRL_i = false;
          Pacemaker_B.ATR_GND_CTRL_g = false;
          Pacemaker_B.ATR_PACE_CTRL_j = true;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/Chart' */

    /* Merge: '<S2>/ATR_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/ATR_GND_CTRL'
     */
    Pacemaker_B.ATR_GND_CTRL = Pacemaker_B.ATR_GND_CTRL_g;

    /* Merge: '<S2>/ATR_PACE_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/ATR_PACE_CTRL'
     */
    Pacemaker_B.ATR_PACE_CTRL = Pacemaker_B.ATR_PACE_CTRL_j;

    /* Merge: '<S2>/FRONTEND_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/FRONTEND_CTRL'
     */
    Pacemaker_B.FRONTEND_CTRL = Pacemaker_B.FRONTEND_CTRL_p;

    /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/PACE_CHARGE_CTRL'
     */
    Pacemaker_B.PACE_CHARGE_CTRL = Pacemaker_B.PACE_CHARGE_CTRL_j;

    /* Merge: '<S2>/PACE_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/PACE_GND_CTRL'
     */
    Pacemaker_B.PACE_GND_CTRL = Pacemaker_B.PACE_GND_CTRL_f;

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S10>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_n;

    /* Merge: '<S2>/VENT_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/VENT_GND_CTRL'
     */
    Pacemaker_B.VENT_GND_CTRL = Pacemaker_B.VENT_GND_CTRL_i;

    /* Merge: '<S2>/VENT_PACE_CTRL' incorporates:
     *  SignalConversion generated from: '<S10>/VENT_PACE_CTRL'
     */
    Pacemaker_B.VENT_PACE_CTRL = Pacemaker_B.VENT_PACE_CTRL_k;
  }

  /* End of RelationalOperator: '<S5>/Equal3' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference3' */

  /* MATLABSystem: '<S3>/Digital Read' */
  if (Pacemaker_DW.obj_i.SampleTime != Pacemaker_P.DigitalRead_SampleTime) {
    Pacemaker_DW.obj_i.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
  }

  rtb_AMP_CMP_DETECT_0 = MW_digitalIO_read
    (Pacemaker_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference2' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* RelationalOperator: '<S5>/Equal5' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  if (Pacemaker_B.MODE == Pacemaker_P.Constant4_Value) {
    /* Chart: '<S9>/Chart' incorporates:
     *  DataTypeConversion: '<S3>/Cast To Double'
     *  DataTypeConversion: '<S3>/Cast To Double10'
     *  DataTypeConversion: '<S3>/Cast To Double7'
     *  DataTypeConversion: '<S3>/Cast To Double8'
     *  DataTypeConversion: '<S3>/Cast To Double9'
     *  MATLABSystem: '<S3>/Digital Read'
     */
    if (Pacemaker_DW.temporalCounter_i1_f < MAX_uint32_T) {
      Pacemaker_DW.temporalCounter_i1_f++;
    }

    if (Pacemaker_DW.is_active_c2_Pacemaker == 0U) {
      Pacemaker_DW.is_active_c2_Pacemaker = 1U;
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
      Pacemaker_DW.temporalCounter_i1_f = 0U;
      Pacemaker_B.ATR_PACE_CTRL_i = false;
      Pacemaker_B.VENT_PACE_CTRL_m = false;
      Pacemaker_B.PACING_REF_PWM_l = Pacemaker_B.VENT_AMP_c * 20.0;
      Pacemaker_B.PACE_CHARGE_CTRL_h = true;
      Pacemaker_B.PACE_GND_CTRL_j = true;
      Pacemaker_B.ATR_GND_CTRL_i = false;
      Pacemaker_B.VENT_GND_CTRL_n = true;
    } else {
      switch (Pacemaker_DW.is_c2_Pacemaker) {
       case Pacemaker_IN_VVI_Charging_C22:
        Pacemaker_B.ATR_PACE_CTRL_i = false;
        Pacemaker_B.VENT_PACE_CTRL_m = false;
        Pacemaker_B.PACE_CHARGE_CTRL_h = true;
        Pacemaker_B.PACE_GND_CTRL_j = true;
        Pacemaker_B.ATR_GND_CTRL_i = false;
        Pacemaker_B.VENT_GND_CTRL_n = true;
        if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_f * 100) >=
            Pacemaker_B.VRP_g) {
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Sensing;
          Pacemaker_DW.temporalCounter_i1_f = 0U;
          Pacemaker_B.FRONTEND_CTRL_i = true;
          Pacemaker_B.VENT_CMP_REF_PWM = Pacemaker_B.VENT_SENSITIVITY_f * 30.0;
        }
        break;

       case Pacemaker_IN_VVI_Pacing:
        Pacemaker_B.PACE_CHARGE_CTRL_h = false;
        Pacemaker_B.PACE_GND_CTRL_j = true;
        Pacemaker_B.ATR_PACE_CTRL_i = false;
        Pacemaker_B.ATR_GND_CTRL_i = false;
        Pacemaker_B.VENT_GND_CTRL_n = false;
        Pacemaker_B.VENT_PACE_CTRL_m = true;
        if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_f * 100) >=
            (uint32_T)ceil(Pacemaker_B.VENT_PW_j)) {
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
          Pacemaker_DW.temporalCounter_i1_f = 0U;
          Pacemaker_B.VENT_PACE_CTRL_m = false;
          Pacemaker_B.PACING_REF_PWM_l = Pacemaker_B.VENT_AMP_c * 20.0;
          Pacemaker_B.PACE_CHARGE_CTRL_h = true;
          Pacemaker_B.VENT_GND_CTRL_n = true;
        }
        break;

       default:
        /* case IN_VVI_Sensing: */
        Pacemaker_B.FRONTEND_CTRL_i = true;
        if ((uint32_T)((int32_T)Pacemaker_DW.temporalCounter_i1_f * 100) >=
            (uint32_T)ceil((60000.0 / (real_T)Pacemaker_B.LRL - (real_T)
                            Pacemaker_B.VRP_g) - Pacemaker_B.VENT_PW_j)) {
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Pacing;
          Pacemaker_DW.temporalCounter_i1_f = 0U;
          Pacemaker_B.PACE_CHARGE_CTRL_h = false;
          Pacemaker_B.PACE_GND_CTRL_j = true;
          Pacemaker_B.ATR_PACE_CTRL_i = false;
          Pacemaker_B.ATR_GND_CTRL_i = false;
          Pacemaker_B.VENT_GND_CTRL_n = false;
          Pacemaker_B.VENT_PACE_CTRL_m = true;
        } else if (rtb_AMP_CMP_DETECT_0) {
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
          Pacemaker_DW.temporalCounter_i1_f = 0U;
          Pacemaker_B.ATR_PACE_CTRL_i = false;
          Pacemaker_B.VENT_PACE_CTRL_m = false;
          Pacemaker_B.PACING_REF_PWM_l = Pacemaker_B.VENT_AMP_c * 20.0;
          Pacemaker_B.PACE_CHARGE_CTRL_h = true;
          Pacemaker_B.PACE_GND_CTRL_j = true;
          Pacemaker_B.ATR_GND_CTRL_i = false;
          Pacemaker_B.VENT_GND_CTRL_n = true;
        }
        break;
      }
    }

    /* End of Chart: '<S9>/Chart' */

    /* Merge: '<S2>/ATR_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/ATR_GND_CTRL'
     */
    Pacemaker_B.ATR_GND_CTRL = Pacemaker_B.ATR_GND_CTRL_i;

    /* Merge: '<S2>/ATR_PACE_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/ATR_PACE_CTRL'
     */
    Pacemaker_B.ATR_PACE_CTRL = Pacemaker_B.ATR_PACE_CTRL_i;

    /* Merge: '<S2>/FRONTEND_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/FRONTEND_CTRL'
     */
    Pacemaker_B.FRONTEND_CTRL = Pacemaker_B.FRONTEND_CTRL_i;

    /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/PACE_CHARGE_CTRL'
     */
    Pacemaker_B.PACE_CHARGE_CTRL = Pacemaker_B.PACE_CHARGE_CTRL_h;

    /* Merge: '<S2>/PACE_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/PACE_GND_CTRL'
     */
    Pacemaker_B.PACE_GND_CTRL = Pacemaker_B.PACE_GND_CTRL_j;

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S9>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_l;

    /* Merge: '<S2>/VENT_GND_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/VENT_GND_CTRL'
     */
    Pacemaker_B.VENT_GND_CTRL = Pacemaker_B.VENT_GND_CTRL_n;

    /* Merge: '<S2>/VENT_PACE_CTRL' incorporates:
     *  SignalConversion generated from: '<S9>/VENT_PACE_CTRL'
     */
    Pacemaker_B.VENT_PACE_CTRL = Pacemaker_B.VENT_PACE_CTRL_m;
  }

  /* End of RelationalOperator: '<S5>/Equal5' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference2' */

  /* MATLABSystem: '<S6>/Digital Write' */
  MW_digitalIO_write(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write2' */
  MW_digitalIO_write(Pacemaker_DW.obj_jz.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write3' */
  MW_digitalIO_write(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write4' */
  MW_digitalIO_write(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write5' */
  MW_digitalIO_write(Pacemaker_DW.obj_j3.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write6' */
  MW_digitalIO_write(Pacemaker_DW.obj_jl.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S6>/PWM Output' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_p.MW_PWM_HANDLE,
                      Pacemaker_B.PACING_REF_PWM);

  /* MATLABSystem: '<S6>/PWM Output1' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_dp.MW_PWM_HANDLE,
                      Pacemaker_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S6>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_f.MW_PWM_HANDLE,
                      Pacemaker_B.VENT_CMP_REF_PWM);
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Pacemaker_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Pacemaker_step0();
    break;

   case 1 :
    Pacemaker_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_0;
    freedomk64f_PWMOutput_Pacemak_T *obj_1;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    echo_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

    /* SystemInitialize for Merge: '<S2>/ATR_GND_CTRL' */
    Pacemaker_B.ATR_GND_CTRL = Pacemaker_P.ATR_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/ATR_PACE_CTRL' */
    Pacemaker_B.ATR_PACE_CTRL = Pacemaker_P.ATR_PACE_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/FRONTEND_CTRL' */
    Pacemaker_B.FRONTEND_CTRL = Pacemaker_P.FRONTEND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/PACE_CHARGE_CTRL' */
    Pacemaker_B.PACE_CHARGE_CTRL = Pacemaker_P.PACE_CHARGE_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/PACE_GND_CTRL' */
    Pacemaker_B.PACE_GND_CTRL = Pacemaker_P.PACE_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/PACING_REF_PWM' */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_P.PACING_REF_PWM_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/VENT_GND_CTRL' */
    Pacemaker_B.VENT_GND_CTRL = Pacemaker_P.VENT_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/VENT_PACE_CTRL' */
    Pacemaker_B.VENT_PACE_CTRL = Pacemaker_P.VENT_PACE_CTRL_InitialOutput;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Pacemaker_DW.obj_j.isInitialized = 0;
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_j.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
    Pacemaker_SystemCore_setup_j(&Pacemaker_DW.obj_j);

    /* Start for MATLABSystem: '<S3>/Digital Read1' */
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj.isInitialized = 0;
    Pacemaker_DW.obj.SampleTime = -1.0;
    Pacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
    obj = &Pacemaker_DW.obj;
    Pacemaker_DW.obj.isSetupComplete = false;
    Pacemaker_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Read' */
    Pacemaker_DW.obj_i.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_i.isInitialized = 0;
    Pacemaker_DW.obj_i.SampleTime = -1.0;
    Pacemaker_DW.obj_i.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_i.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
    obj = &Pacemaker_DW.obj_i;
    Pacemaker_DW.obj_i.isSetupComplete = false;
    Pacemaker_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write1' */
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_d.isInitialized = 0;
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_d;
    Pacemaker_DW.obj_d.isSetupComplete = false;
    Pacemaker_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write2' */
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_jz.isInitialized = 0;
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_jz;
    Pacemaker_DW.obj_jz.isSetupComplete = false;
    Pacemaker_DW.obj_jz.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_jz.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write3' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_b.isInitialized = 0;
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isSetupComplete = false;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write4' */
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_h.isInitialized = 0;
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_h;
    Pacemaker_DW.obj_h.isSetupComplete = false;
    Pacemaker_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write5' */
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j3.isInitialized = 0;
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_j3;
    Pacemaker_DW.obj_j3.isSetupComplete = false;
    Pacemaker_DW.obj_j3.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_j3.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write6' */
    Pacemaker_DW.obj_jl.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_jl.isInitialized = 0;
    Pacemaker_DW.obj_jl.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_jl;
    Pacemaker_DW.obj_jl.isSetupComplete = false;
    Pacemaker_DW.obj_jl.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_jl.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
    Pacemaker_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output1' */
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_dp.isInitialized = 0;
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_dp;
    Pacemaker_DW.obj_dp.isSetupComplete = false;
    Pacemaker_DW.obj_dp.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
    Pacemaker_DW.obj_dp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output2' */
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_f.isInitialized = 0;
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_f;
    Pacemaker_DW.obj_f.isSetupComplete = false;
    Pacemaker_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
    Pacemaker_DW.obj_f.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Pacemaker_DW.obj_j.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_j.isInitialized == 1) &&
        Pacemaker_DW.obj_j.isSetupComplete) {
      MW_SCI_Close(Pacemaker_DW.obj_j.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  echo_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read1' */
  if (!Pacemaker_DW.obj.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj.isInitialized == 1) &&
        Pacemaker_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read' */
  if (!Pacemaker_DW.obj_i.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_i.isInitialized == 1) &&
        Pacemaker_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Pacemaker_DW.obj_e.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_e.isInitialized == 1) &&
        Pacemaker_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write1' */
  if (!Pacemaker_DW.obj_d.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_d.isInitialized == 1) &&
        Pacemaker_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write2' */
  if (!Pacemaker_DW.obj_jz.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_jz.isInitialized == 1) &&
        Pacemaker_DW.obj_jz.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_jz.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write3' */
  if (!Pacemaker_DW.obj_b.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_b.isInitialized == 1) &&
        Pacemaker_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write4' */
  if (!Pacemaker_DW.obj_h.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_h.isInitialized == 1) &&
        Pacemaker_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write5' */
  if (!Pacemaker_DW.obj_j3.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_j3.isInitialized == 1) &&
        Pacemaker_DW.obj_j3.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_j3.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write6' */
  if (!Pacemaker_DW.obj_jl.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_jl.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_jl.isInitialized == 1) &&
        Pacemaker_DW.obj_jl.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_jl.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output' */
  if (!Pacemaker_DW.obj_p.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_p.isInitialized == 1) &&
        Pacemaker_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output1' */
  if (!Pacemaker_DW.obj_dp.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_dp.isInitialized == 1) &&
        Pacemaker_DW.obj_dp.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output2' */
  if (!Pacemaker_DW.obj_f.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_f.isInitialized == 1) &&
        Pacemaker_DW.obj_f.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
