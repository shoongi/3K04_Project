/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOO.c
 *
 * Code generated for Simulink model 'VOO'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 22 21:45:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VOO.h"
#include "rtwtypes.h"
#include <math.h>
#include "VOO_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define VOO_IN_C22_CHARGE              ((uint8_T)1U)
#define VOO_IN_C22_DISCHARGE           ((uint8_T)2U)

/* Block signals (default storage) */
B_VOO_T VOO_B;

/* Block states (default storage) */
DW_VOO_T VOO_DW;

/* Real-time model */
static RT_MODEL_VOO_T VOO_M_;
RT_MODEL_VOO_T *const VOO_M = &VOO_M_;

/* Model step function */
void VOO_step(void)
{
  boolean_T rtb_PACE_CHARGE_CTRL;
  boolean_T rtb_VENT_GND_CTRL;
  boolean_T rtb_VENT_PACE_CTRL;

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Amplitude'
   *  Constant: '<Root>/LRL'
   *  Constant: '<Root>/PW'
   */
  if (VOO_DW.temporalCounter_i1 < MAX_uint32_T) {
    VOO_DW.temporalCounter_i1++;
  }

  if (VOO_DW.is_active_c3_VOO == 0U) {
    VOO_DW.is_active_c3_VOO = 1U;
    VOO_DW.is_c3_VOO = VOO_IN_C22_CHARGE;
    VOO_DW.temporalCounter_i1 = 0U;
    rtb_VENT_PACE_CTRL = false;
    VOO_B.PACING_REF_PWM = VOO_P.Amplitude_Value / 5.0 * 100.0;
    rtb_PACE_CHARGE_CTRL = true;
    rtb_VENT_GND_CTRL = true;
  } else if (VOO_DW.is_c3_VOO == VOO_IN_C22_CHARGE) {
    rtb_VENT_PACE_CTRL = false;
    rtb_PACE_CHARGE_CTRL = true;
    rtb_VENT_GND_CTRL = true;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 / VOO_P.LRL_Value -
         VOO_P.PW_Value)) {
      VOO_DW.is_c3_VOO = VOO_IN_C22_DISCHARGE;
      VOO_DW.temporalCounter_i1 = 0U;
      rtb_PACE_CHARGE_CTRL = false;
      rtb_VENT_GND_CTRL = false;
      rtb_VENT_PACE_CTRL = true;
    }
  } else {
    /* case IN_C22_DISCHARGE: */
    rtb_PACE_CHARGE_CTRL = false;
    rtb_VENT_GND_CTRL = false;
    rtb_VENT_PACE_CTRL = true;
    if (VOO_DW.temporalCounter_i1 >= (uint32_T)ceil(VOO_P.PW_Value)) {
      VOO_DW.is_c3_VOO = VOO_IN_C22_CHARGE;
      VOO_DW.temporalCounter_i1 = 0U;
      rtb_VENT_PACE_CTRL = false;
      VOO_B.PACING_REF_PWM = VOO_P.Amplitude_Value / 5.0 * 100.0;
      rtb_PACE_CHARGE_CTRL = true;
      rtb_VENT_GND_CTRL = true;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(VOO_DW.obj_m.MW_DIGITALIO_HANDLE, rtb_PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VOO_DW.obj_i.MW_DIGITALIO_HANDLE, rtb_VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VOO_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_VENT_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(VOO_DW.obj_l.MW_DIGITALIO_HANDLE, true);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VOO_DW.obj_k.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(VOO_DW.obj.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(VOO_DW.obj_g.MW_PWM_HANDLE, VOO_B.PACING_REF_PWM);
}

/* Model initialize function */
void VOO_initialize(void)
{
  {
    freedomk64f_DigitalWrite_VOO_T *obj;
    freedomk64f_PWMOutput_VOO_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    VOO_DW.obj_m.matlabCodegenIsDeleted = true;
    VOO_DW.obj_m.isInitialized = 0;
    VOO_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_m;
    VOO_DW.obj_m.isSetupComplete = false;
    VOO_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VOO_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    VOO_DW.obj_i.matlabCodegenIsDeleted = true;
    VOO_DW.obj_i.isInitialized = 0;
    VOO_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_i;
    VOO_DW.obj_i.isSetupComplete = false;
    VOO_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VOO_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    VOO_DW.obj_n.matlabCodegenIsDeleted = true;
    VOO_DW.obj_n.isInitialized = 0;
    VOO_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_n;
    VOO_DW.obj_n.isSetupComplete = false;
    VOO_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VOO_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    VOO_DW.obj_l.matlabCodegenIsDeleted = true;
    VOO_DW.obj_l.isInitialized = 0;
    VOO_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_l;
    VOO_DW.obj_l.isSetupComplete = false;
    VOO_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VOO_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    VOO_DW.obj_k.matlabCodegenIsDeleted = true;
    VOO_DW.obj_k.isInitialized = 0;
    VOO_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj_k;
    VOO_DW.obj_k.isSetupComplete = false;
    VOO_DW.obj_k.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VOO_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    VOO_DW.obj.matlabCodegenIsDeleted = true;
    VOO_DW.obj.isInitialized = 0;
    VOO_DW.obj.matlabCodegenIsDeleted = false;
    obj = &VOO_DW.obj;
    VOO_DW.obj.isSetupComplete = false;
    VOO_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VOO_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    VOO_DW.obj_g.matlabCodegenIsDeleted = true;
    VOO_DW.obj_g.isInitialized = 0;
    VOO_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &VOO_DW.obj_g;
    VOO_DW.obj_g.isSetupComplete = false;
    VOO_DW.obj_g.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(VOO_DW.obj_g.MW_PWM_HANDLE);
    VOO_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void VOO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VOO_DW.obj_m.matlabCodegenIsDeleted) {
    VOO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_m.isInitialized == 1) && VOO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VOO_DW.obj_i.matlabCodegenIsDeleted) {
    VOO_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_i.isInitialized == 1) && VOO_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VOO_DW.obj_n.matlabCodegenIsDeleted) {
    VOO_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_n.isInitialized == 1) && VOO_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!VOO_DW.obj_l.matlabCodegenIsDeleted) {
    VOO_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_l.isInitialized == 1) && VOO_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VOO_DW.obj_k.matlabCodegenIsDeleted) {
    VOO_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_k.isInitialized == 1) && VOO_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!VOO_DW.obj.matlabCodegenIsDeleted) {
    VOO_DW.obj.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj.isInitialized == 1) && VOO_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VOO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!VOO_DW.obj_g.matlabCodegenIsDeleted) {
    VOO_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((VOO_DW.obj_g.isInitialized == 1) && VOO_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(VOO_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(VOO_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
