/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
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
#include "rtwtypes.h"
#include <math.h>
#include "Pacemaker_types.h"

/* Named constants for Chart: '<S6>/Chart' */
#define Pacemaker_IN_AOO_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_AOO_Pacing        ((uint8_T)2U)

/* Named constants for Chart: '<S7>/Chart' */
#define Pacemaker_IN_C22_CHARGE        ((uint8_T)1U)
#define Pacemaker_IN_C22_DISCHARGE     ((uint8_T)2U)

/* Named constants for Chart: '<S8>/Chart' */
#define Pacemaker_IN_VVI_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_VVI_Pacing        ((uint8_T)2U)
#define Pacemaker_IN_VVI_Sensing       ((uint8_T)3U)

/* Named constants for Chart: '<S9>/Chart' */
#define Pacemaker_IN_AAI_Charging_C22  ((uint8_T)1U)
#define Pacemaker_IN_AAI_Pacing        ((uint8_T)2U)
#define Pacemaker_IN_AAI_Sensing       ((uint8_T)3U)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
static RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Model step function */
void Pacemaker_step(void)
{
  boolean_T rtb_AMP_CMP_DETECT_0;

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S4>/Equal4' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S26>/Constant'
   */
  if (Pacemaker_P.ModeSelect_Value == Pacemaker_P.ModeSelect4_Value) {
    /* Chart: '<S7>/Chart' incorporates:
     *  Constant: '<S3>/LRL'
     *  Constant: '<S3>/VENT_AMP'
     *  Constant: '<S3>/VENT_PW'
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
      Pacemaker_B.PACING_REF_PWM_n = Pacemaker_P.VENT_AMP_Value / 5.0 * 100.0;

      /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
       *  Constant: '<S3>/VENT_AMP'
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
      if (Pacemaker_DW.temporalCounter_i1_b >= (uint32_T)ceil(60000.0 /
           Pacemaker_P.LRL_Value - Pacemaker_P.VENT_PW_Value)) {
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
      if (Pacemaker_DW.temporalCounter_i1_b >= (uint32_T)ceil
          (Pacemaker_P.VENT_PW_Value)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_C22_CHARGE;
        Pacemaker_DW.temporalCounter_i1_b = 0U;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.PACING_REF_PWM_n = Pacemaker_P.VENT_AMP_Value / 5.0 * 100.0;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' incorporates:
         *  Constant: '<S3>/VENT_AMP'
         */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = true;
      }
    }

    /* End of Chart: '<S7>/Chart' */

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S7>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_n;
  }

  /* End of RelationalOperator: '<S4>/Equal4' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference1' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem Reference' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* RelationalOperator: '<S4>/Equal2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S24>/Constant'
   */
  if (Pacemaker_P.ModeSelect_Value == Pacemaker_P.ModeSelect2_Value) {
    /* Chart: '<S6>/Chart' incorporates:
     *  Constant: '<S3>/ATR_AMP'
     *  Constant: '<S3>/ATR_PW'
     *  Constant: '<S3>/LRL'
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
      Pacemaker_B.PACING_REF_PWM_k = Pacemaker_P.ATR_AMP_Value * 20.0;

      /* Merge: '<S2>/PACE_GND_CTRL' incorporates:
       *  Constant: '<S3>/ATR_AMP'
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
      if (Pacemaker_DW.temporalCounter_i1_a >= (uint32_T)ceil(60000.0 /
           Pacemaker_P.LRL_Value - Pacemaker_P.ATR_PW_Value)) {
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
      if (Pacemaker_DW.temporalCounter_i1_a >= (uint32_T)ceil
          (Pacemaker_P.ATR_PW_Value)) {
        Pacemaker_DW.is_c1_Pacemaker = Pacemaker_IN_AOO_Charging_C22;
        Pacemaker_DW.temporalCounter_i1_a = 0U;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = false;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;
        Pacemaker_B.PACING_REF_PWM_k = Pacemaker_P.ATR_AMP_Value * 20.0;

        /* Merge: '<S2>/ATR_GND_CTRL' incorporates:
         *  Constant: '<S3>/ATR_AMP'
         */
        Pacemaker_B.ATR_GND_CTRL = true;
      }
    }

    /* End of Chart: '<S6>/Chart' */

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  SignalConversion generated from: '<S6>/PACING_REF_PWM'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_B.PACING_REF_PWM_k;
  }

  /* End of RelationalOperator: '<S4>/Equal2' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem Reference' */

  /* MATLABSystem: '<S3>/Digital Read1' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.DigitalRead1_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
  }

  rtb_AMP_CMP_DETECT_0 = MW_digitalIO_read(Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<S9>/Chart' incorporates:
   *  Constant: '<S3>/ARP'
   *  Constant: '<S3>/ATR_PW'
   *  Constant: '<S3>/ATR_SENSITIVITY'
   *  Constant: '<S3>/LRL'
   *  MATLABSystem: '<S3>/Digital Read1'
   */
  if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  if (Pacemaker_DW.is_active_c4_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c4_Pacemaker = 1U;
    Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
    Pacemaker_DW.temporalCounter_i1 = 0U;

    /* Merge: '<S2>/VENT_PACE_CTRL' */
    Pacemaker_B.VENT_PACE_CTRL = false;

    /* Merge: '<S2>/ATR_PACE_CTRL' */
    Pacemaker_B.ATR_PACE_CTRL = false;

    /* Merge: '<S2>/PACE_CHARGE_CTRL' */
    Pacemaker_B.PACE_CHARGE_CTRL = true;

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  Constant: '<S3>/ATR_AMP'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_P.ATR_AMP_Value * 20.0;

    /* Merge: '<S2>/PACE_GND_CTRL' */
    Pacemaker_B.PACE_GND_CTRL = true;

    /* Merge: '<S2>/VENT_GND_CTRL' */
    Pacemaker_B.VENT_GND_CTRL = false;

    /* Merge: '<S2>/ATR_GND_CTRL' */
    Pacemaker_B.ATR_GND_CTRL = true;
  } else {
    switch (Pacemaker_DW.is_c4_Pacemaker) {
     case Pacemaker_IN_AAI_Charging_C22:
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
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_P.ARP_Value)) {
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Sensing;
        Pacemaker_DW.temporalCounter_i1 = 0U;

        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = true;
        Pacemaker_B.ATR_CMP_REF_PWM = Pacemaker_P.ATR_SENSITIVITY_Value * 30.0;
      }
      break;

     case Pacemaker_IN_AAI_Pacing:
      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
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
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_P.ATR_PW_Value)) {
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
        Pacemaker_DW.temporalCounter_i1 = 0U;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = false;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/PACING_REF_PWM' incorporates:
         *  Constant: '<S3>/ATR_AMP'
         */
        Pacemaker_B.PACING_REF_PWM = Pacemaker_P.ATR_AMP_Value * 20.0;

        /* Merge: '<S2>/ATR_GND_CTRL' */
        Pacemaker_B.ATR_GND_CTRL = true;
      }
      break;

     default:
      /* case IN_AAI_Sensing: */
      if (rtb_AMP_CMP_DETECT_0) {
        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Charging_C22;
        Pacemaker_DW.temporalCounter_i1 = 0U;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = false;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = false;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/PACING_REF_PWM' incorporates:
         *  Constant: '<S3>/ATR_AMP'
         */
        Pacemaker_B.PACING_REF_PWM = Pacemaker_P.ATR_AMP_Value * 20.0;

        /* Merge: '<S2>/PACE_GND_CTRL' */
        Pacemaker_B.PACE_GND_CTRL = true;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = false;

        /* Merge: '<S2>/ATR_GND_CTRL' */
        Pacemaker_B.ATR_GND_CTRL = true;
      } else if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
                  Pacemaker_P.LRL_Value - Pacemaker_P.ARP_Value)) {
        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_AAI_Pacing;
        Pacemaker_DW.temporalCounter_i1 = 0U;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
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
      }
      break;
    }
  }

  /* End of Chart: '<S9>/Chart' */

  /* MATLABSystem: '<S3>/Digital Read' */
  if (Pacemaker_DW.obj_i.SampleTime != Pacemaker_P.DigitalRead_SampleTime) {
    Pacemaker_DW.obj_i.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
  }

  rtb_AMP_CMP_DETECT_0 = MW_digitalIO_read
    (Pacemaker_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* Chart: '<S8>/Chart' incorporates:
   *  Constant: '<S3>/LRL'
   *  Constant: '<S3>/VENT_PW'
   *  Constant: '<S3>/VENT_SENSITIVITY'
   *  Constant: '<S3>/VRP'
   *  MATLABSystem: '<S3>/Digital Read'
   */
  if (Pacemaker_DW.temporalCounter_i1_f < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1_f++;
  }

  if (Pacemaker_DW.is_active_c2_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c2_Pacemaker = 1U;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
    Pacemaker_DW.temporalCounter_i1_f = 0U;

    /* Merge: '<S2>/ATR_PACE_CTRL' */
    Pacemaker_B.ATR_PACE_CTRL = false;

    /* Merge: '<S2>/VENT_PACE_CTRL' */
    Pacemaker_B.VENT_PACE_CTRL = false;

    /* Merge: '<S2>/PACING_REF_PWM' incorporates:
     *  Constant: '<S3>/VENT_AMP'
     */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_P.VENT_AMP_Value * 20.0;

    /* Merge: '<S2>/PACE_CHARGE_CTRL' */
    Pacemaker_B.PACE_CHARGE_CTRL = true;

    /* Merge: '<S2>/PACE_GND_CTRL' */
    Pacemaker_B.PACE_GND_CTRL = true;

    /* Merge: '<S2>/ATR_GND_CTRL' */
    Pacemaker_B.ATR_GND_CTRL = false;

    /* Merge: '<S2>/VENT_GND_CTRL' */
    Pacemaker_B.VENT_GND_CTRL = true;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_VVI_Charging_C22:
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
      if (Pacemaker_DW.temporalCounter_i1_f >= (uint32_T)ceil
          (Pacemaker_P.VRP_Value)) {
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Sensing;
        Pacemaker_DW.temporalCounter_i1_f = 0U;

        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = true;
        Pacemaker_B.VENT_CMP_REF_PWM = Pacemaker_P.VENT_SENSITIVITY_Value * 30.0;
      }
      break;

     case Pacemaker_IN_VVI_Pacing:
      /* Merge: '<S2>/PACE_CHARGE_CTRL' */
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
      if (Pacemaker_DW.temporalCounter_i1_f >= (uint32_T)ceil
          (Pacemaker_P.VENT_PW_Value)) {
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
        Pacemaker_DW.temporalCounter_i1_f = 0U;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = false;

        /* Merge: '<S2>/PACING_REF_PWM' incorporates:
         *  Constant: '<S3>/VENT_AMP'
         */
        Pacemaker_B.PACING_REF_PWM = Pacemaker_P.VENT_AMP_Value * 20.0;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = true;
      }
      break;

     default:
      /* case IN_VVI_Sensing: */
      if (Pacemaker_DW.temporalCounter_i1_f >= (uint32_T)ceil(60000.0 /
           Pacemaker_P.LRL_Value - Pacemaker_P.VRP_Value)) {
        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Pacing;
        Pacemaker_DW.temporalCounter_i1_f = 0U;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
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
      } else if (rtb_AMP_CMP_DETECT_0) {
        /* Merge: '<S2>/FRONTEND_CTRL' */
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_VVI_Charging_C22;
        Pacemaker_DW.temporalCounter_i1_f = 0U;

        /* Merge: '<S2>/ATR_PACE_CTRL' */
        Pacemaker_B.ATR_PACE_CTRL = false;

        /* Merge: '<S2>/VENT_PACE_CTRL' */
        Pacemaker_B.VENT_PACE_CTRL = false;

        /* Merge: '<S2>/PACING_REF_PWM' incorporates:
         *  Constant: '<S3>/VENT_AMP'
         */
        Pacemaker_B.PACING_REF_PWM = Pacemaker_P.VENT_AMP_Value * 20.0;

        /* Merge: '<S2>/PACE_CHARGE_CTRL' */
        Pacemaker_B.PACE_CHARGE_CTRL = true;

        /* Merge: '<S2>/PACE_GND_CTRL' */
        Pacemaker_B.PACE_GND_CTRL = true;

        /* Merge: '<S2>/ATR_GND_CTRL' */
        Pacemaker_B.ATR_GND_CTRL = false;

        /* Merge: '<S2>/VENT_GND_CTRL' */
        Pacemaker_B.VENT_GND_CTRL = true;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/Chart' */

  /* MATLABSystem: '<S5>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_f.MW_PWM_HANDLE,
                      Pacemaker_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/PWM Output1' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_dp.MW_PWM_HANDLE,
                      Pacemaker_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Digital Write' */
  MW_digitalIO_write(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write2' */
  MW_digitalIO_write(Pacemaker_DW.obj_jz.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write3' */
  MW_digitalIO_write(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write4' */
  MW_digitalIO_write(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write5' */
  MW_digitalIO_write(Pacemaker_DW.obj_j3.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write6' */
  MW_digitalIO_write(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S5>/PWM Output' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_p.MW_PWM_HANDLE,
                      Pacemaker_B.PACING_REF_PWM);
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_1;
    freedomk64f_PWMOutput_Pacemak_T *obj_0;

    /* SystemInitialize for Merge: '<S2>/PACE_CHARGE_CTRL' */
    Pacemaker_B.PACE_CHARGE_CTRL = Pacemaker_P.PACE_CHARGE_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/VENT_GND_CTRL' */
    Pacemaker_B.VENT_GND_CTRL = Pacemaker_P.VENT_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/VENT_PACE_CTRL' */
    Pacemaker_B.VENT_PACE_CTRL = Pacemaker_P.VENT_PACE_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/PACE_GND_CTRL' */
    Pacemaker_B.PACE_GND_CTRL = Pacemaker_P.PACE_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/ATR_GND_CTRL' */
    Pacemaker_B.ATR_GND_CTRL = Pacemaker_P.ATR_GND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/ATR_PACE_CTRL' */
    Pacemaker_B.ATR_PACE_CTRL = Pacemaker_P.ATR_PACE_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/FRONTEND_CTRL' */
    Pacemaker_B.FRONTEND_CTRL = Pacemaker_P.FRONTEND_CTRL_InitialOutput;

    /* SystemInitialize for Merge: '<S2>/PACING_REF_PWM' */
    Pacemaker_B.PACING_REF_PWM = Pacemaker_P.PACING_REF_PWM_InitialOutput;

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

    /* Start for MATLABSystem: '<S5>/PWM Output2' */
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_f.isInitialized = 0;
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_f;
    Pacemaker_DW.obj_f.isSetupComplete = false;
    Pacemaker_DW.obj_f.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
    Pacemaker_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output1' */
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_dp.isInitialized = 0;
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_dp;
    Pacemaker_DW.obj_dp.isSetupComplete = false;
    Pacemaker_DW.obj_dp.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
    Pacemaker_DW.obj_dp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_d.isInitialized = 0;
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_d;
    Pacemaker_DW.obj_d.isSetupComplete = false;
    Pacemaker_DW.obj_d.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write2' */
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_jz.isInitialized = 0;
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_jz;
    Pacemaker_DW.obj_jz.isSetupComplete = false;
    Pacemaker_DW.obj_jz.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_jz.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write3' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_b.isInitialized = 0;
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isSetupComplete = false;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write4' */
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_h.isInitialized = 0;
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_h;
    Pacemaker_DW.obj_h.isSetupComplete = false;
    Pacemaker_DW.obj_h.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write5' */
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j3.isInitialized = 0;
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_j3;
    Pacemaker_DW.obj_j3.isSetupComplete = false;
    Pacemaker_DW.obj_j3.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_j3.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write6' */
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j.isInitialized = 0;
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_j;
    Pacemaker_DW.obj_j.isSetupComplete = false;
    Pacemaker_DW.obj_j.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
    Pacemaker_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
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

  /* Terminate for MATLABSystem: '<S5>/PWM Output2' */
  if (!Pacemaker_DW.obj_f.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_f.isInitialized == 1) &&
        Pacemaker_DW.obj_f.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_f.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output1' */
  if (!Pacemaker_DW.obj_dp.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_dp.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_dp.isInitialized == 1) &&
        Pacemaker_DW.obj_dp.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_dp.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!Pacemaker_DW.obj_e.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_e.isInitialized == 1) &&
        Pacemaker_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  if (!Pacemaker_DW.obj_d.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_d.isInitialized == 1) &&
        Pacemaker_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write2' */
  if (!Pacemaker_DW.obj_jz.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_jz.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_jz.isInitialized == 1) &&
        Pacemaker_DW.obj_jz.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_jz.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write3' */
  if (!Pacemaker_DW.obj_b.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_b.isInitialized == 1) &&
        Pacemaker_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write4' */
  if (!Pacemaker_DW.obj_h.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_h.isInitialized == 1) &&
        Pacemaker_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write5' */
  if (!Pacemaker_DW.obj_j3.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_j3.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_j3.isInitialized == 1) &&
        Pacemaker_DW.obj_j3.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_j3.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write6' */
  if (!Pacemaker_DW.obj_j.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_j.isInitialized == 1) &&
        Pacemaker_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output' */
  if (!Pacemaker_DW.obj_p.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_p.isInitialized == 1) &&
        Pacemaker_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
