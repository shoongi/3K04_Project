/*
 * AOO.c
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

#include "AOO.h"
#include "rtwtypes.h"
#include "AOO_types.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Chart' */
#define AOO_IN_AOO_Charging_C22        ((uint8_T)1U)
#define AOO_IN_AOO_Pacing              ((uint8_T)2U)
#define AOO_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Block signals (default storage) */
B_AOO_T AOO_B;

/* Block states (default storage) */
DW_AOO_T AOO_DW;

/* Real-time model */
static RT_MODEL_AOO_T AOO_M_;
RT_MODEL_AOO_T *const AOO_M = &AOO_M_;

/* Model step function */
void AOO_step(void)
{
  boolean_T rtb_ATR_GND_CTRL;
  boolean_T rtb_ATR_PACE_CTRL;
  boolean_T rtb_PACE_CHARGE_CTRL;

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Amplitdue'
   *  Constant: '<Root>/LRL'
   *  Constant: '<Root>/PW'
   */
  if (AOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    AOO_DW.temporalCounter_i1++;
  }

  if (AOO_DW.is_active_c3_AOO == 0U) {
    AOO_DW.is_active_c3_AOO = 1U;
    AOO_DW.is_c3_AOO = AOO_IN_AOO_Charging_C22;
    AOO_DW.temporalCounter_i1 = 0U;
    rtb_ATR_PACE_CTRL = false;
    rtb_PACE_CHARGE_CTRL = true;
    AOO_B.PACING_REF_PWM = AOO_P.Amplitdue_Value * 20.0;
    rtb_ATR_GND_CTRL = true;
  } else if (AOO_DW.is_c3_AOO == AOO_IN_AOO_Charging_C22) {
    rtb_ATR_PACE_CTRL = false;
    rtb_PACE_CHARGE_CTRL = true;
    rtb_ATR_GND_CTRL = true;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 / AOO_P.LRL_Value -
         AOO_P.PW_Value)) {
      AOO_DW.is_c3_AOO = AOO_IN_AOO_Pacing;
      AOO_DW.temporalCounter_i1 = 0U;
      rtb_PACE_CHARGE_CTRL = false;
      rtb_ATR_GND_CTRL = false;
      rtb_ATR_PACE_CTRL = true;
    }
  } else {
    /* case IN_AOO_Pacing: */
    rtb_PACE_CHARGE_CTRL = false;
    rtb_ATR_GND_CTRL = false;
    rtb_ATR_PACE_CTRL = true;
    if (AOO_DW.temporalCounter_i1 >= (uint32_T)ceil(AOO_P.PW_Value)) {
      AOO_DW.is_c3_AOO = AOO_IN_AOO_Charging_C22;
      AOO_DW.temporalCounter_i1 = 0U;
      rtb_ATR_PACE_CTRL = false;
      rtb_PACE_CHARGE_CTRL = true;
      AOO_B.PACING_REF_PWM = AOO_P.Amplitdue_Value * 20.0;
      rtb_ATR_GND_CTRL = true;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AOO_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(AOO_DW.obj_ib.MW_DIGITALIO_HANDLE, rtb_ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(AOO_DW.obj_i.MW_DIGITALIO_HANDLE, rtb_ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(AOO_DW.obj_n.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(AOO_DW.obj_j.MW_DIGITALIO_HANDLE, true);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(AOO_DW.obj_m.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(AOO_DW.obj_k.MW_PWM_HANDLE, AOO_B.PACING_REF_PWM);

  /* MATLABSystem: '<Root>/Digital Write7' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_digitalIO_write(AOO_DW.obj.MW_DIGITALIO_HANDLE, AOO_P.Constant_Value);
}

/* Model initialize function */
void AOO_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(AOO_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &AOO_B), 0,
                sizeof(B_AOO_T));

  /* states (dwork) */
  (void) memset((void *)&AOO_DW, 0,
                sizeof(DW_AOO_T));

  {
    freedomk64f_DigitalWrite_AOO_T *obj;
    freedomk64f_PWMOutput_AOO_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    AOO_DW.obj_l.matlabCodegenIsDeleted = true;
    AOO_DW.obj_l.isInitialized = 0;
    AOO_DW.obj_l.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_bs = true;
    obj = &AOO_DW.obj_l;
    AOO_DW.obj_l.isSetupComplete = false;
    AOO_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AOO_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    AOO_DW.obj_ib.matlabCodegenIsDeleted = true;
    AOO_DW.obj_ib.isInitialized = 0;
    AOO_DW.obj_ib.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_h = true;
    obj = &AOO_DW.obj_ib;
    AOO_DW.obj_ib.isSetupComplete = false;
    AOO_DW.obj_ib.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AOO_DW.obj_ib.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    AOO_DW.obj_i.matlabCodegenIsDeleted = true;
    AOO_DW.obj_i.isInitialized = 0;
    AOO_DW.obj_i.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_b = true;
    obj = &AOO_DW.obj_i;
    AOO_DW.obj_i.isSetupComplete = false;
    AOO_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AOO_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    AOO_DW.obj_n.matlabCodegenIsDeleted = true;
    AOO_DW.obj_n.isInitialized = 0;
    AOO_DW.obj_n.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_jg = true;
    obj = &AOO_DW.obj_n;
    AOO_DW.obj_n.isSetupComplete = false;
    AOO_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AOO_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    AOO_DW.obj_j.matlabCodegenIsDeleted = true;
    AOO_DW.obj_j.isInitialized = 0;
    AOO_DW.obj_j.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_j = true;
    obj = &AOO_DW.obj_j;
    AOO_DW.obj_j.isSetupComplete = false;
    AOO_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AOO_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    AOO_DW.obj_m.matlabCodegenIsDeleted = true;
    AOO_DW.obj_m.isInitialized = 0;
    AOO_DW.obj_m.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_dr = true;
    obj = &AOO_DW.obj_m;
    AOO_DW.obj_m.isSetupComplete = false;
    AOO_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AOO_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    AOO_DW.obj_k.matlabCodegenIsDeleted = true;
    AOO_DW.obj_k.isInitialized = 0;
    AOO_DW.obj_k.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty = true;
    obj_0 = &AOO_DW.obj_k;
    AOO_DW.obj_k.isSetupComplete = false;
    AOO_DW.obj_k.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(AOO_DW.obj_k.MW_PWM_HANDLE);
    AOO_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    AOO_DW.obj.matlabCodegenIsDeleted = true;
    AOO_DW.obj.isInitialized = 0;
    AOO_DW.obj.matlabCodegenIsDeleted = false;
    AOO_DW.objisempty_d = true;
    obj = &AOO_DW.obj;
    AOO_DW.obj.isSetupComplete = false;
    AOO_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    AOO_DW.obj.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/Chart' */
  AOO_DW.temporalCounter_i1 = 0U;
  AOO_DW.is_active_c3_AOO = 0U;
  AOO_DW.is_c3_AOO = AOO_IN_NO_ACTIVE_CHILD;
  AOO_B.PACING_REF_PWM = 0.0;
}

/* Model terminate function */
void AOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AOO_DW.obj_l.matlabCodegenIsDeleted) {
    AOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_l.isInitialized == 1) && AOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AOO_DW.obj_ib.matlabCodegenIsDeleted) {
    AOO_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_ib.isInitialized == 1) && AOO_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!AOO_DW.obj_i.matlabCodegenIsDeleted) {
    AOO_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_i.isInitialized == 1) && AOO_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!AOO_DW.obj_n.matlabCodegenIsDeleted) {
    AOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_n.isInitialized == 1) && AOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!AOO_DW.obj_j.matlabCodegenIsDeleted) {
    AOO_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_j.isInitialized == 1) && AOO_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!AOO_DW.obj_m.matlabCodegenIsDeleted) {
    AOO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_m.isInitialized == 1) && AOO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!AOO_DW.obj_k.matlabCodegenIsDeleted) {
    AOO_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj_k.isInitialized == 1) && AOO_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(AOO_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(AOO_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!AOO_DW.obj.matlabCodegenIsDeleted) {
    AOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((AOO_DW.obj.isInitialized == 1) && AOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(AOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */
}
