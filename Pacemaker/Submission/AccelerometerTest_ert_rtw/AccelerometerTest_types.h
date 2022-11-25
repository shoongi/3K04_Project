/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AccelerometerTest_types.h
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

#ifndef RTW_HEADER_AccelerometerTest_types_h_
#define RTW_HEADER_AccelerometerTest_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
#ifndef struct_tag_sdXjxHyaQeSPr4KK3M1T9G
#define struct_tag_sdXjxHyaQeSPr4KK3M1T9G

struct tag_sdXjxHyaQeSPr4KK3M1T9G
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[2499];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_sdXjxHyaQeSPr4KK3M1T9G */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_sdXjxHyaQeSPr4KK3M1T9G g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_AccelerometerTest_T
#define typedef_cell_wrap_AccelerometerTest_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_AccelerometerTest_T;

#endif                               /* typedef_cell_wrap_AccelerometerTest_T */

#ifndef struct_tag_aO8JRigj3bZXEaeloWpKkH
#define struct_tag_aO8JRigj3bZXEaeloWpKkH

struct tag_aO8JRigj3bZXEaeloWpKkH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_AccelerometerTest_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_aO8JRigj3bZXEaeloWpKkH */

#ifndef typedef_dsp_simulink_MovingAverage_Ac_T
#define typedef_dsp_simulink_MovingAverage_Ac_T

typedef struct tag_aO8JRigj3bZXEaeloWpKkH dsp_simulink_MovingAverage_Ac_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_Ac_T */

/* Custom Type definition for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
#include "MW_SVD.h"
#include "MW_I2C.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_c_freedomk64f_Hardware_Accele_T
#define typedef_c_freedomk64f_Hardware_Accele_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB c_freedomk64f_Hardware_Accele_T;

#endif                             /* typedef_c_freedomk64f_Hardware_Accele_T */

#ifndef struct_tag_O0UAiliRyLLAe38ibfdAhE
#define struct_tag_O0UAiliRyLLAe38ibfdAhE

struct tag_O0UAiliRyLLAe38ibfdAhE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_freedomk64f_Hardware_Accele_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_O0UAiliRyLLAe38ibfdAhE */

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_O0UAiliRyLLAe38ibfdAhE b_freedomk64f_I2CMasterWrite__T;

#endif                             /* typedef_b_freedomk64f_I2CMasterWrite__T */

#ifndef struct_tag_v5Zyp5raUQrCF4f9Ln2EwE
#define struct_tag_v5Zyp5raUQrCF4f9Ln2EwE

struct tag_v5Zyp5raUQrCF4f9Ln2EwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /* struct_tag_v5Zyp5raUQrCF4f9Ln2EwE */

#ifndef typedef_freedomk64f_fxos8700_Accelero_T
#define typedef_freedomk64f_fxos8700_Accelero_T

typedef struct tag_v5Zyp5raUQrCF4f9Ln2EwE freedomk64f_fxos8700_Accelero_T;

#endif                             /* typedef_freedomk64f_fxos8700_Accelero_T */

#ifndef struct_tag_paOZQoRbx29KAFiAT01zxC
#define struct_tag_paOZQoRbx29KAFiAT01zxC

struct tag_paOZQoRbx29KAFiAT01zxC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[499];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_paOZQoRbx29KAFiAT01zxC */

#ifndef typedef_g_dsp_internal_SlidingWindo_g_T
#define typedef_g_dsp_internal_SlidingWindo_g_T

typedef struct tag_paOZQoRbx29KAFiAT01zxC g_dsp_internal_SlidingWindo_g_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindo_g_T */

#ifndef struct_tag_rJ88SXGVQhQW3SJwFUkouE
#define struct_tag_rJ88SXGVQhQW3SJwFUkouE

struct tag_rJ88SXGVQhQW3SJwFUkouE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_AccelerometerTest_T inputVarSize;
  g_dsp_internal_SlidingWindo_g_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindo_g_T _pobj0;
};

#endif                                 /* struct_tag_rJ88SXGVQhQW3SJwFUkouE */

#ifndef typedef_dsp_simulink_MovingAverage_g_T
#define typedef_dsp_simulink_MovingAverage_g_T

typedef struct tag_rJ88SXGVQhQW3SJwFUkouE dsp_simulink_MovingAverage_g_T;

#endif                              /* typedef_dsp_simulink_MovingAverage_g_T */

/* Parameters (default storage) */
typedef struct P_AccelerometerTest_T_ P_AccelerometerTest_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AccelerometerTest_T RT_MODEL_AccelerometerTest_T;

#endif                               /* RTW_HEADER_AccelerometerTest_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
