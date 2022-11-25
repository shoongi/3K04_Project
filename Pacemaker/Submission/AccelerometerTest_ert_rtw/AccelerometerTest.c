/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccelerometerTest.c
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

#include "AccelerometerTest.h"
#include "rtwtypes.h"
#include "AccelerometerTest_types.h"
#include "AccelerometerTest_private.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"
#include "AccelerometerTest_dt.h"

/* Block signals (default storage) */
B_AccelerometerTest_T AccelerometerTest_B;

/* Block states (default storage) */
DW_AccelerometerTest_T AccelerometerTest_DW;

/* Real-time model */
static RT_MODEL_AccelerometerTest_T AccelerometerTest_M_;
RT_MODEL_AccelerometerTest_T *const AccelerometerTest_M = &AccelerometerTest_M_;

/* Forward declaration for local functions */
static int16_T Accelerometer_bitshift_anonFcn1(int16_T a1, real_T k1);
static void AccelerometerT_SystemCore_setup(freedomk64f_fxos8700_Accelero_T *obj);

/* System initialize for atomic system: */
void AccelerometerTest_x_Init(DW_x_AccelerometerTest_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *iobj_0;
  int32_T i;

  /* Start for MATLABSystem: '<Root>/x' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/x' */
  iobj_0 = localDW->obj.pStatistic;
  if (iobj_0->isInitialized == 1) {
    iobj_0->pCumSum = 0.0;
    for (i = 0; i < 2499; i++) {
      iobj_0->pCumSumRev[i] = 0.0;
    }

    iobj_0->pCumRevIndex = 1.0;
    iobj_0->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/x' */
}

/* Output and update for atomic system: */
void AccelerometerTest_x(real_T rtu_0, B_x_AccelerometerTest_T *localB,
  DW_x_AccelerometerTest_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<Root>/x' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 2499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 2499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 2499; i++) {
    localB->csumrev[i] = obj->pCumSumRev[i];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<Root>/x' */
  localB->x = 0.0;

  /* MATLABSystem: '<Root>/x' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = localB->csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  localB->csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 2499.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 2497; i >= 0; i--) {
      localB->csumrev[i] += localB->csumrev[i + 1];
    }
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<Root>/x' */
    localB->x = z / 2500.0;
  }

  obj->pCumSum = csum;
  for (i = 0; i < 2499; i++) {
    obj->pCumSumRev[i] = localB->csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

/* Termination for atomic system: */
void AccelerometerTest_x_Term(DW_x_AccelerometerTest_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<Root>/x' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/x' */
}

static int16_T Accelerometer_bitshift_anonFcn1(int16_T a1, real_T k1)
{
  int16_T varargout_1;
  if (k1 >= 0.0) {
    if (k1 <= 15.0) {
      varargout_1 = (int16_T)(a1 << (uint8_T)k1);
    } else {
      varargout_1 = 0;
    }
  } else if (k1 >= -15.0) {
    varargout_1 = (int16_T)(a1 >> (uint8_T)-k1);
  } else if (a1 < 0) {
    varargout_1 = -1;
  } else {
    varargout_1 = 0;
  }

  return varargout_1;
}

static void AccelerometerT_SystemCore_setup(freedomk64f_fxos8700_Accelero_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void AccelerometerTest_step(void)
{
  g_dsp_internal_SlidingWindo_g_T *obj;
  int32_T i;
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  if (AccelerometerTest_DW.obj_g.SampleTime !=
      AccelerometerTest_P.FXOS87006AxesSensor_SampleTime) {
    AccelerometerTest_DW.obj_g.SampleTime =
      AccelerometerTest_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(AccelerometerTest_DW.obj_g.i2cobj.MW_I2C_HANDLE,
    29U, &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(AccelerometerTest_DW.obj_g.i2cobj.MW_I2C_HANDLE, 29U,
                      &AccelerometerTest_B.output_raw[0], 6U, false, true);
    memcpy((void *)&AccelerometerTest_B.b_RegisterValue[0], (void *)
           &AccelerometerTest_B.output_raw[0], (uint32_T)((size_t)3 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&AccelerometerTest_B.b_RegisterValue[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&AccelerometerTest_B.b_RegisterValue[0], (void *)&b_x[0],
           (uint32_T)((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&AccelerometerTest_B.b_RegisterValue[1],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&AccelerometerTest_B.b_RegisterValue[1], (void *)&b_x[0],
           (uint32_T)((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&AccelerometerTest_B.b_RegisterValue[2],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&AccelerometerTest_B.b_RegisterValue[2], (void *)&b_x[0],
           (uint32_T)((size_t)1 * sizeof(int16_T)));
  } else {
    AccelerometerTest_B.b_RegisterValue[0] = 0;
    AccelerometerTest_B.b_RegisterValue[1] = 0;
    AccelerometerTest_B.b_RegisterValue[2] = 0;
  }

  /* MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  AccelerometerTest_B.FXOS87006AxesSensor[0] = (real_T)
    Accelerometer_bitshift_anonFcn1(AccelerometerTest_B.b_RegisterValue[0], -2.0)
    * 2.0 * 0.244 / 1000.0;
  AccelerometerTest_B.FXOS87006AxesSensor[1] = (real_T)
    Accelerometer_bitshift_anonFcn1(AccelerometerTest_B.b_RegisterValue[1], -2.0)
    * 2.0 * 0.244 / 1000.0;
  AccelerometerTest_B.FXOS87006AxesSensor[2] = (real_T)
    Accelerometer_bitshift_anonFcn1(AccelerometerTest_B.b_RegisterValue[2], -2.0)
    * 2.0 * 0.244 / 1000.0;
  AccelerometerTest_x(AccelerometerTest_B.FXOS87006AxesSensor[0],
                      &AccelerometerTest_B.x, &AccelerometerTest_DW.x);

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  AccelerometerTest_B.TSamp = AccelerometerTest_B.x.x *
    AccelerometerTest_P.TSamp_WtEt;
  AccelerometerTest_x(AccelerometerTest_B.FXOS87006AxesSensor[1],
                      &AccelerometerTest_B.y, &AccelerometerTest_DW.y);

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  AccelerometerTest_B.TSamp_n = AccelerometerTest_B.y.x *
    AccelerometerTest_P.TSamp_WtEt_m;
  AccelerometerTest_x(AccelerometerTest_B.FXOS87006AxesSensor[2],
                      &AccelerometerTest_B.z, &AccelerometerTest_DW.z);

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  AccelerometerTest_B.TSamp_e = AccelerometerTest_B.z.x *
    AccelerometerTest_P.TSamp_WtEt_me;

  /* Sum: '<Root>/Add' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<Root>/Abs1'
   *  Abs: '<Root>/Abs2'
   *  Sum: '<S1>/Diff'
   *  Sum: '<S2>/Diff'
   *  Sum: '<S3>/Diff'
   *  UnitDelay: '<S1>/UD'
   *  UnitDelay: '<S2>/UD'
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  AccelerometerTest_B.Add = (fabs(AccelerometerTest_B.TSamp -
    AccelerometerTest_DW.UD_DSTATE) + fabs(AccelerometerTest_B.TSamp_n -
    AccelerometerTest_DW.UD_DSTATE_g)) + fabs(AccelerometerTest_B.TSamp_e -
    AccelerometerTest_DW.UD_DSTATE_g1);

  /* MATLABSystem: '<Root>/Moving Average' */
  if (AccelerometerTest_DW.obj.TunablePropsChanged) {
    AccelerometerTest_DW.obj.TunablePropsChanged = false;
  }

  obj = AccelerometerTest_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  AccelerometerTest_B.cumRevIndex = obj->pCumRevIndex;
  AccelerometerTest_B.csum = obj->pCumSum;
  for (i = 0; i < 499; i++) {
    AccelerometerTest_B.csumrev[i] = obj->pCumSumRev[i];
  }

  AccelerometerTest_B.modValueRev = obj->pModValueRev;
  AccelerometerTest_B.z_m = 0.0;

  /* MATLABSystem: '<Root>/Moving Average' */
  AccelerometerTest_B.MovingAverage = 0.0;

  /* MATLABSystem: '<Root>/Moving Average' */
  AccelerometerTest_B.csum += AccelerometerTest_B.Add;
  if (AccelerometerTest_B.modValueRev == 0.0) {
    AccelerometerTest_B.z_m = AccelerometerTest_B.csumrev[(int32_T)
      AccelerometerTest_B.cumRevIndex - 1] + AccelerometerTest_B.csum;
  }

  AccelerometerTest_B.csumrev[(int32_T)AccelerometerTest_B.cumRevIndex - 1] =
    AccelerometerTest_B.Add;
  if (AccelerometerTest_B.cumRevIndex != 499.0) {
    AccelerometerTest_B.cumRevIndex++;
  } else {
    AccelerometerTest_B.cumRevIndex = 1.0;
    AccelerometerTest_B.csum = 0.0;
    for (i = 497; i >= 0; i--) {
      AccelerometerTest_B.csumrev[i] += AccelerometerTest_B.csumrev[i + 1];
    }
  }

  if (AccelerometerTest_B.modValueRev == 0.0) {
    /* MATLABSystem: '<Root>/Moving Average' */
    AccelerometerTest_B.MovingAverage = AccelerometerTest_B.z_m / 500.0;
  }

  obj->pCumSum = AccelerometerTest_B.csum;
  for (i = 0; i < 499; i++) {
    obj->pCumSumRev[i] = AccelerometerTest_B.csumrev[i];
  }

  obj->pCumRevIndex = AccelerometerTest_B.cumRevIndex;
  if (AccelerometerTest_B.modValueRev > 0.0) {
    obj->pModValueRev = AccelerometerTest_B.modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  AccelerometerTest_DW.UD_DSTATE = AccelerometerTest_B.TSamp;

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  AccelerometerTest_DW.UD_DSTATE_g = AccelerometerTest_B.TSamp_n;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  AccelerometerTest_DW.UD_DSTATE_g1 = AccelerometerTest_B.TSamp_e;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)AccelerometerTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(AccelerometerTest_M)!=-1) &&
        !((rtmGetTFinal(AccelerometerTest_M)-
           AccelerometerTest_M->Timing.taskTime0) >
          AccelerometerTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AccelerometerTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(AccelerometerTest_M)) {
      rtmSetErrorStatus(AccelerometerTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  AccelerometerTest_M->Timing.taskTime0 =
    ((time_T)(++AccelerometerTest_M->Timing.clockTick0)) *
    AccelerometerTest_M->Timing.stepSize0;
}

/* Model initialize function */
void AccelerometerTest_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(AccelerometerTest_M, -1);
  AccelerometerTest_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  AccelerometerTest_M->Sizes.checksums[0] = (1272979917U);
  AccelerometerTest_M->Sizes.checksums[1] = (2115288521U);
  AccelerometerTest_M->Sizes.checksums[2] = (4041701957U);
  AccelerometerTest_M->Sizes.checksums[3] = (2302739985U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    AccelerometerTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AccelerometerTest_M->extModeInfo,
      &AccelerometerTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AccelerometerTest_M->extModeInfo,
                        AccelerometerTest_M->Sizes.checksums);
    rteiSetTPtr(AccelerometerTest_M->extModeInfo, rtmGetTPtr(AccelerometerTest_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AccelerometerTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    g_dsp_internal_SlidingWindo_g_T *iobj_0;
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    AccelerometerTest_DW.UD_DSTATE =
      AccelerometerTest_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    AccelerometerTest_DW.UD_DSTATE_g =
      AccelerometerTest_P.DiscreteDerivative1_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S3>/UD'
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    AccelerometerTest_DW.UD_DSTATE_g1 =
      AccelerometerTest_P.DiscreteDerivative2_ICPrevScale;

    /* Start for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
    AccelerometerTest_DW.obj_g.isInitialized = 0;
    AccelerometerTest_DW.obj_g.i2cobj.isInitialized = 0;
    AccelerometerTest_DW.obj_g.i2cobj.matlabCodegenIsDeleted = false;
    AccelerometerTest_DW.obj_g.matlabCodegenIsDeleted = false;
    AccelerometerTest_DW.obj_g.SampleTime =
      AccelerometerTest_P.FXOS87006AxesSensor_SampleTime;
    AccelerometerT_SystemCore_setup(&AccelerometerTest_DW.obj_g);
    AccelerometerTest_x_Init(&AccelerometerTest_DW.x);
    AccelerometerTest_x_Init(&AccelerometerTest_DW.y);
    AccelerometerTest_x_Init(&AccelerometerTest_DW.z);

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    AccelerometerTest_DW.obj.matlabCodegenIsDeleted = true;
    AccelerometerTest_DW.obj.isInitialized = 0;
    AccelerometerTest_DW.obj.NumChannels = -1;
    AccelerometerTest_DW.obj.matlabCodegenIsDeleted = false;
    AccelerometerTest_DW.obj.isSetupComplete = false;
    AccelerometerTest_DW.obj.isInitialized = 1;
    AccelerometerTest_DW.obj.NumChannels = 1;
    iobj_0 = &AccelerometerTest_DW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;
    AccelerometerTest_DW.obj.pStatistic = iobj_0;
    AccelerometerTest_DW.obj.isSetupComplete = true;
    AccelerometerTest_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
    iobj_0 = AccelerometerTest_DW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 499; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
  }
}

/* Model terminate function */
void AccelerometerTest_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindo_g_T *obj_0;

  /* Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  if (!AccelerometerTest_DW.obj_g.matlabCodegenIsDeleted) {
    AccelerometerTest_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((AccelerometerTest_DW.obj_g.isInitialized == 1) &&
        AccelerometerTest_DW.obj_g.isSetupComplete) {
      MW_I2C_Close(AccelerometerTest_DW.obj_g.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &AccelerometerTest_DW.obj_g.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  AccelerometerTest_x_Term(&AccelerometerTest_DW.x);
  AccelerometerTest_x_Term(&AccelerometerTest_DW.y);
  AccelerometerTest_x_Term(&AccelerometerTest_DW.z);

  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
  if (!AccelerometerTest_DW.obj.matlabCodegenIsDeleted) {
    AccelerometerTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((AccelerometerTest_DW.obj.isInitialized == 1) &&
        AccelerometerTest_DW.obj.isSetupComplete) {
      obj_0 = AccelerometerTest_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      AccelerometerTest_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
