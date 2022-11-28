/*
 * AAI.c
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

#include "AAI.h"
#include "rtwtypes.h"
#include "AAI_types.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Chart' */
#define AAI_IN_AAI_Charging_C22        ((uint8_T)1U)
#define AAI_IN_AAI_Pacing              ((uint8_T)2U)
#define AAI_IN_AAI_Sensing             ((uint8_T)3U)
#define AAI_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Block signals (default storage) */
B_AAI_T AAI_B;

/* Block states (default storage) */
DW_AAI_T AAI_DW;

/* Real-time model */
static RT_MODEL_AAI_T AAI_M_;
RT_MODEL_AAI_T *const AAI_M = &AAI_M_;

/* Model step function */
void AAI_step(void)
{
  boolean_T rtb_DigitalRead_0;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (AAI_DW.obj.SampleTime != AAI_P.DigitalRead_SampleTime) {
    AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read(AAI_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Amplitude'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/LRL'
   *  Constant: '<Root>/PW'
   *  MATLABSystem: '<Root>/Digital Read'
   */
  if (AAI_DW.temporalCounter_i1 < MAX_uint32_T) {
    AAI_DW.temporalCounter_i1++;
  }

  if (AAI_DW.is_active_c3_AAI == 0U) {
    AAI_DW.is_active_c3_AAI = 1U;
    AAI_DW.is_c3_AAI = AAI_IN_AAI_Charging_C22;
    AAI_DW.temporalCounter_i1 = 0U;
    AAI_B.VENT_PACE_CTRL = false;
    AAI_B.ATR_PACE_CTRL = false;
    AAI_B.PACE_CHARGE_CTRL = true;
    AAI_B.PACING_REF_PWM = AAI_P.Amplitude_Value * 20.0;
    AAI_B.PACE_GND_CTRL = true;
    AAI_B.VENT_GND_CTRL = false;
    AAI_B.ATR_GND_CTRL = true;
  } else {
    switch (AAI_DW.is_c3_AAI) {
     case AAI_IN_AAI_Charging_C22:
      AAI_B.VENT_PACE_CTRL = false;
      AAI_B.ATR_PACE_CTRL = false;
      AAI_B.PACE_CHARGE_CTRL = true;
      AAI_B.PACE_GND_CTRL = true;
      AAI_B.VENT_GND_CTRL = false;
      AAI_B.ATR_GND_CTRL = true;
      if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.Constant2_Value)) {
        AAI_DW.is_c3_AAI = AAI_IN_AAI_Sensing;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_B.FRONTEND_CTRL = true;
        AAI_B.ATR_CMP_REF_PWM = AAI_P.Constant_Value * 30.0;
      }
      break;

     case AAI_IN_AAI_Pacing:
      AAI_B.PACE_CHARGE_CTRL = false;
      AAI_B.PACE_GND_CTRL = true;
      AAI_B.VENT_PACE_CTRL = false;
      AAI_B.VENT_GND_CTRL = false;
      AAI_B.ATR_GND_CTRL = false;
      AAI_B.ATR_PACE_CTRL = true;
      if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil(AAI_P.PW_Value)) {
        AAI_DW.is_c3_AAI = AAI_IN_AAI_Charging_C22;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_B.ATR_PACE_CTRL = false;
        AAI_B.PACE_CHARGE_CTRL = true;
        AAI_B.PACING_REF_PWM = AAI_P.Amplitude_Value * 20.0;
        AAI_B.ATR_GND_CTRL = true;
      }
      break;

     default:
      /* case IN_AAI_Sensing: */
      AAI_B.FRONTEND_CTRL = true;
      if (rtb_DigitalRead_0) {
        AAI_DW.is_c3_AAI = AAI_IN_AAI_Charging_C22;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_B.VENT_PACE_CTRL = false;
        AAI_B.ATR_PACE_CTRL = false;
        AAI_B.PACE_CHARGE_CTRL = true;
        AAI_B.PACING_REF_PWM = AAI_P.Amplitude_Value * 20.0;
        AAI_B.PACE_GND_CTRL = true;
        AAI_B.VENT_GND_CTRL = false;
        AAI_B.ATR_GND_CTRL = true;
      } else if (AAI_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                   AAI_P.LRL_Value - AAI_P.Constant2_Value) - AAI_P.PW_Value)) {
        AAI_DW.is_c3_AAI = AAI_IN_AAI_Pacing;
        AAI_DW.temporalCounter_i1 = 0U;
        AAI_B.PACE_CHARGE_CTRL = false;
        AAI_B.PACE_GND_CTRL = true;
        AAI_B.VENT_PACE_CTRL = false;
        AAI_B.VENT_GND_CTRL = false;
        AAI_B.ATR_GND_CTRL = false;
        AAI_B.ATR_PACE_CTRL = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AAI_DW.obj_lh.MW_DIGITALIO_HANDLE, AAI_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AAI_DW.obj_ib.MW_DIGITALIO_HANDLE, AAI_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(AAI_DW.obj_i.MW_DIGITALIO_HANDLE, AAI_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(AAI_DW.obj_n.MW_DIGITALIO_HANDLE, AAI_B.VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AAI_DW.obj_j.MW_DIGITALIO_HANDLE, AAI_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(AAI_DW.obj_m.MW_DIGITALIO_HANDLE, AAI_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(AAI_DW.obj_l.MW_DIGITALIO_HANDLE, AAI_B.FRONTEND_CTRL);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_k.MW_PWM_HANDLE, AAI_B.PACING_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(AAI_DW.obj_jv.MW_PWM_HANDLE, AAI_B.ATR_CMP_REF_PWM);
}

/* Model initialize function */
void AAI_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(AAI_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &AAI_B), 0,
                sizeof(B_AAI_T));

  /* states (dwork) */
  (void) memset((void *)&AAI_DW, 0,
                sizeof(DW_AAI_T));

  {
    freedomk64f_DigitalRead_AAI_T *obj;
    freedomk64f_DigitalWrite_AAI_T *obj_0;
    freedomk64f_PWMOutput_AAI_T *obj_1;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    AAI_DW.obj.matlabCodegenIsDeleted = true;
    AAI_DW.obj.isInitialized = 0;
    AAI_DW.obj.SampleTime = -1.0;
    AAI_DW.obj.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_g = true;
    AAI_DW.obj.SampleTime = AAI_P.DigitalRead_SampleTime;
    obj = &AAI_DW.obj;
    AAI_DW.obj.isSetupComplete = false;
    AAI_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    AAI_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    AAI_DW.obj_lh.matlabCodegenIsDeleted = true;
    AAI_DW.obj_lh.isInitialized = 0;
    AAI_DW.obj_lh.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_bs = true;
    obj_0 = &AAI_DW.obj_lh;
    AAI_DW.obj_lh.isSetupComplete = false;
    AAI_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AAI_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    AAI_DW.obj_ib.matlabCodegenIsDeleted = true;
    AAI_DW.obj_ib.isInitialized = 0;
    AAI_DW.obj_ib.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_h = true;
    obj_0 = &AAI_DW.obj_ib;
    AAI_DW.obj_ib.isSetupComplete = false;
    AAI_DW.obj_ib.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AAI_DW.obj_ib.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    AAI_DW.obj_i.matlabCodegenIsDeleted = true;
    AAI_DW.obj_i.isInitialized = 0;
    AAI_DW.obj_i.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_b = true;
    obj_0 = &AAI_DW.obj_i;
    AAI_DW.obj_i.isSetupComplete = false;
    AAI_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AAI_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    AAI_DW.obj_n.matlabCodegenIsDeleted = true;
    AAI_DW.obj_n.isInitialized = 0;
    AAI_DW.obj_n.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_jg = true;
    obj_0 = &AAI_DW.obj_n;
    AAI_DW.obj_n.isSetupComplete = false;
    AAI_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AAI_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    AAI_DW.obj_j.matlabCodegenIsDeleted = true;
    AAI_DW.obj_j.isInitialized = 0;
    AAI_DW.obj_j.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_j = true;
    obj_0 = &AAI_DW.obj_j;
    AAI_DW.obj_j.isSetupComplete = false;
    AAI_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AAI_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    AAI_DW.obj_m.matlabCodegenIsDeleted = true;
    AAI_DW.obj_m.isInitialized = 0;
    AAI_DW.obj_m.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_d = true;
    obj_0 = &AAI_DW.obj_m;
    AAI_DW.obj_m.isSetupComplete = false;
    AAI_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AAI_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    AAI_DW.obj_l.matlabCodegenIsDeleted = true;
    AAI_DW.obj_l.isInitialized = 0;
    AAI_DW.obj_l.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_f = true;
    obj_0 = &AAI_DW.obj_l;
    AAI_DW.obj_l.isSetupComplete = false;
    AAI_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AAI_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    AAI_DW.obj_k.matlabCodegenIsDeleted = true;
    AAI_DW.obj_k.isInitialized = 0;
    AAI_DW.obj_k.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty_n = true;
    obj_1 = &AAI_DW.obj_k;
    AAI_DW.obj_k.isSetupComplete = false;
    AAI_DW.obj_k.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(AAI_DW.obj_k.MW_PWM_HANDLE);
    AAI_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    AAI_DW.obj_jv.matlabCodegenIsDeleted = true;
    AAI_DW.obj_jv.isInitialized = 0;
    AAI_DW.obj_jv.matlabCodegenIsDeleted = false;
    AAI_DW.objisempty = true;
    obj_1 = &AAI_DW.obj_jv;
    AAI_DW.obj_jv.isSetupComplete = false;
    AAI_DW.obj_jv.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(AAI_DW.obj_jv.MW_PWM_HANDLE);
    AAI_DW.obj_jv.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/Chart' */
  AAI_DW.temporalCounter_i1 = 0U;
  AAI_DW.is_active_c3_AAI = 0U;
  AAI_DW.is_c3_AAI = AAI_IN_NO_ACTIVE_CHILD;
  AAI_B.ATR_GND_CTRL = false;
  AAI_B.ATR_PACE_CTRL = false;
  AAI_B.PACE_CHARGE_CTRL = false;
  AAI_B.VENT_GND_CTRL = false;
  AAI_B.VENT_PACE_CTRL = false;
  AAI_B.PACE_GND_CTRL = false;
  AAI_B.PACING_REF_PWM = 0.0;
  AAI_B.FRONTEND_CTRL = false;
  AAI_B.ATR_CMP_REF_PWM = 0.0;
}

/* Model terminate function */
void AAI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!AAI_DW.obj.matlabCodegenIsDeleted) {
    AAI_DW.obj.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj.isInitialized == 1) && AAI_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AAI_DW.obj_lh.matlabCodegenIsDeleted) {
    AAI_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_lh.isInitialized == 1) && AAI_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AAI_DW.obj_ib.matlabCodegenIsDeleted) {
    AAI_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_ib.isInitialized == 1) && AAI_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!AAI_DW.obj_i.matlabCodegenIsDeleted) {
    AAI_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_i.isInitialized == 1) && AAI_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!AAI_DW.obj_n.matlabCodegenIsDeleted) {
    AAI_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_n.isInitialized == 1) && AAI_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AAI_DW.obj_j.matlabCodegenIsDeleted) {
    AAI_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_j.isInitialized == 1) && AAI_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!AAI_DW.obj_m.matlabCodegenIsDeleted) {
    AAI_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_m.isInitialized == 1) && AAI_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!AAI_DW.obj_l.matlabCodegenIsDeleted) {
    AAI_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_l.isInitialized == 1) && AAI_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AAI_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!AAI_DW.obj_k.matlabCodegenIsDeleted) {
    AAI_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_k.isInitialized == 1) && AAI_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!AAI_DW.obj_jv.matlabCodegenIsDeleted) {
    AAI_DW.obj_jv.matlabCodegenIsDeleted = true;
    if ((AAI_DW.obj_jv.isInitialized == 1) && AAI_DW.obj_jv.isSetupComplete) {
      MW_PWM_Stop(AAI_DW.obj_jv.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_DW.obj_jv.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */
}
