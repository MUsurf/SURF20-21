/*
 * cCode.c
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "cCode".
 *
 * Model version              : 1.83
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Nov 30 15:58:01 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "cCode.h"
#include "cCode_private.h"

/* Block signals (default storage) */
B_cCode_T cCode_B;

/* Continuous states */
X_cCode_T cCode_X;

/* Block states (default storage) */
DW_cCode_T cCode_DW;

/* Real-time model */
static RT_MODEL_cCode_T cCode_M_;
RT_MODEL_cCode_T *const cCode_M = &cCode_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  cCode_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  cCode_step();
  cCode_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  cCode_step();
  cCode_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void cCode_step(void)
{
  real_T Bias;
  int_T idx;
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* set solver stop time */
    if (!(cCode_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&cCode_M->solverInfo, ((cCode_M->Timing.clockTickH0
        + 1) * cCode_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&cCode_M->solverInfo, ((cCode_M->Timing.clockTick0 +
        1) * cCode_M->Timing.stepSize0 + cCode_M->Timing.clockTickH0 *
        cCode_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(cCode_M)) {
    cCode_M->Timing.t[0] = rtsiGetT(&cCode_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(cCode_M)) {
    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<Root>/Depth'
     *  Constant: '<Root>/IMU Depth'
     *  Constant: '<Root>/IMU Pitch'
     *  Constant: '<Root>/IMU Roll'
     *  Constant: '<Root>/IMU Yaw'
     *  Constant: '<Root>/Pitch'
     *  Constant: '<Root>/Roll'
     *  Constant: '<Root>/Yaw'
     */
    cCode_B.Sum[0] = cCode_P.Pitch_Value - cCode_P.IMUPitch_Value;
    cCode_B.Sum[1] = cCode_P.Roll_Value - cCode_P.IMURoll_Value;
    cCode_B.Sum[2] = cCode_P.Yaw_Value - cCode_P.IMUYaw_Value;
    cCode_B.Sum[3] = cCode_P.Depth_Value - cCode_P.IMUDepth_Value;

    /* Abs: '<S11>/Abs' */
    cCode_B.Abs = fabs(cCode_B.Sum[0]);

    /* RelationalOperator: '<S11>/Relational Operator' incorporates:
     *  Constant: '<S11>/Constant'
     */
    cCode_B.RelationalOperator = (cCode_B.Abs <= cCode_P.Constant_Value);

    /* Switch: '<S11>/Switch' */
    if (cCode_B.RelationalOperator) {
      /* Switch: '<S11>/Switch' */
      cCode_B.Switch = cCode_B.Sum[0];
    } else {
      /* Abs: '<S14>/Abs1' */
      cCode_B.Abs1_a = fabs(cCode_B.Sum[0]);

      /* Product: '<S14>/Divide' */
      cCode_B.Divide_bs = cCode_B.Sum[0] / cCode_B.Abs1_a;

      /* Product: '<S11>/Product' incorporates:
       *  Constant: '<S11>/Constant2'
       */
      cCode_B.Product_f = cCode_B.Divide_bs * cCode_P.Constant2_Value;

      /* Sum: '<S11>/Sum1' */
      cCode_B.Sum1_g = cCode_B.Sum[0] - cCode_B.Product_f;

      /* Switch: '<S11>/Switch' */
      cCode_B.Switch = cCode_B.Sum1_g;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Product: '<S5>/Divide' incorporates:
     *  Constant: '<S5>/Constant'
     */
    cCode_B.Divide = cCode_B.Switch / cCode_P.Constant_Value_b;

    /* Gain: '<S53>/Proportional Gain' */
    cCode_B.ProportionalGain = cCode_P.PIDController_P * cCode_B.Divide;

    /* Gain: '<S42>/Derivative Gain' */
    cCode_B.DerivativeGain = cCode_P.PIDController_D * cCode_B.Divide;

    /* Abs: '<S12>/Abs' */
    cCode_B.Abs_a = fabs(cCode_B.Sum[1]);

    /* RelationalOperator: '<S12>/Relational Operator' incorporates:
     *  Constant: '<S12>/Constant'
     */
    cCode_B.RelationalOperator_m = (cCode_B.Abs_a <= cCode_P.Constant_Value_p);

    /* Switch: '<S12>/Switch' */
    if (cCode_B.RelationalOperator_m) {
      /* Switch: '<S12>/Switch' */
      cCode_B.Switch_k = cCode_B.Sum[1];
    } else {
      /* Abs: '<S15>/Abs1' */
      cCode_B.Abs1_p = fabs(cCode_B.Sum[1]);

      /* Product: '<S15>/Divide' */
      cCode_B.Divide_c = cCode_B.Sum[1] / cCode_B.Abs1_p;

      /* Product: '<S12>/Product' incorporates:
       *  Constant: '<S12>/Constant2'
       */
      cCode_B.Product_b = cCode_B.Divide_c * cCode_P.Constant2_Value_c;

      /* Sum: '<S12>/Sum1' */
      cCode_B.Sum1_b = cCode_B.Sum[1] - cCode_B.Product_b;

      /* Switch: '<S12>/Switch' */
      cCode_B.Switch_k = cCode_B.Sum1_b;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Product: '<S5>/Divide1' incorporates:
     *  Constant: '<S5>/Constant'
     */
    cCode_B.Divide1 = cCode_B.Switch_k / cCode_P.Constant_Value_b;

    /* Gain: '<S101>/Proportional Gain' */
    cCode_B.ProportionalGain_o = cCode_P.PIDController1_P * cCode_B.Divide1;

    /* Gain: '<S90>/Derivative Gain' */
    cCode_B.DerivativeGain_f = cCode_P.PIDController1_D * cCode_B.Divide1;
  }

  /* Integrator: '<S43>/Filter' */
  cCode_B.Filter = cCode_X.Filter_CSTATE;

  /* Sum: '<S43>/SumD' */
  cCode_B.SumD = cCode_B.DerivativeGain - cCode_B.Filter;

  /* Gain: '<S51>/Filter Coefficient' */
  cCode_B.FilterCoefficient = cCode_P.PIDController_N * cCode_B.SumD;

  /* Sum: '<S57>/Sum' */
  cCode_B.Sum_n = cCode_B.ProportionalGain + cCode_B.FilterCoefficient;

  /* Integrator: '<S91>/Filter' */
  cCode_B.Filter_h = cCode_X.Filter_CSTATE_m;

  /* Sum: '<S91>/SumD' */
  cCode_B.SumD_a = cCode_B.DerivativeGain_f - cCode_B.Filter_h;

  /* Gain: '<S99>/Filter Coefficient' */
  cCode_B.FilterCoefficient_f = cCode_P.PIDController1_N * cCode_B.SumD_a;

  /* Sum: '<S105>/Sum' */
  cCode_B.Sum_a = cCode_B.ProportionalGain_o + cCode_B.FilterCoefficient_f;

  /* Sum: '<S210>/Sum1' */
  cCode_B.Sum1 = cCode_B.Sum_n + cCode_B.Sum_a;

  /* Math: '<S209>/Magnitude Squared'
   *
   * About '<S209>/Magnitude Squared':
   *  Operator: magnitude^2
   */
  Bias = cCode_B.Sum_n;

  /* Math: '<S209>/Magnitude Squared'
   *
   * About '<S209>/Magnitude Squared':
   *  Operator: magnitude^2
   */
  cCode_B.MagnitudeSquared = Bias * Bias;

  /* Math: '<S209>/Magnitude Squared1'
   *
   * About '<S209>/Magnitude Squared1':
   *  Operator: magnitude^2
   */
  Bias = cCode_B.Sum_a;

  /* Math: '<S209>/Magnitude Squared1'
   *
   * About '<S209>/Magnitude Squared1':
   *  Operator: magnitude^2
   */
  cCode_B.MagnitudeSquared1 = Bias * Bias;

  /* Sum: '<S209>/Sum2' */
  cCode_B.Sum2 = cCode_B.MagnitudeSquared + cCode_B.MagnitudeSquared1;

  /* Sum: '<S209>/Sum1' incorporates:
   *  Constant: '<S209>/Constant'
   */
  cCode_B.Sum1_l = cCode_B.Sum2 + cCode_P.Constant_Value_d;

  /* Sqrt: '<S209>/Reciprocal Sqrt' */
  Bias = cCode_B.Sum1_l;
  if (Bias > 0.0) {
    if (rtIsInf(Bias)) {
      /* Sqrt: '<S209>/Reciprocal Sqrt' */
      cCode_B.ReciprocalSqrt = 0.0;
    } else {
      /* Sqrt: '<S209>/Reciprocal Sqrt' */
      cCode_B.ReciprocalSqrt = 1.0 / sqrt(Bias);
    }
  } else if (Bias == 0.0) {
    /* Sqrt: '<S209>/Reciprocal Sqrt' */
    cCode_B.ReciprocalSqrt = (rtInf);
  } else {
    /* Sqrt: '<S209>/Reciprocal Sqrt' */
    cCode_B.ReciprocalSqrt = (rtNaN);
  }

  /* End of Sqrt: '<S209>/Reciprocal Sqrt' */
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* Gain: '<S197>/Proportional Gain' */
    cCode_B.ProportionalGain_e = cCode_P.PIDController3_P * cCode_B.Sum[3];

    /* Gain: '<S186>/Derivative Gain' */
    cCode_B.DerivativeGain_d = cCode_P.PIDController3_D * cCode_B.Sum[3];
  }

  /* Integrator: '<S187>/Filter' */
  cCode_B.Filter_e = cCode_X.Filter_CSTATE_l;

  /* Sum: '<S187>/SumD' */
  cCode_B.SumD_m = cCode_B.DerivativeGain_d - cCode_B.Filter_e;

  /* Gain: '<S195>/Filter Coefficient' */
  cCode_B.FilterCoefficient_i = cCode_P.PIDController3_N * cCode_B.SumD_m;

  /* Sum: '<S201>/Sum' */
  cCode_B.Sum_n4 = cCode_B.ProportionalGain_e + cCode_B.FilterCoefficient_i;

  /* Math: '<S209>/Magnitude Squared2'
   *
   * About '<S209>/Magnitude Squared2':
   *  Operator: magnitude^2
   */
  Bias = cCode_B.Sum_n4;

  /* Math: '<S209>/Magnitude Squared2'
   *
   * About '<S209>/Magnitude Squared2':
   *  Operator: magnitude^2
   */
  cCode_B.MagnitudeSquared2 = Bias * Bias;

  /* Switch: '<S209>/Switch' */
  if (cCode_B.MagnitudeSquared2 > cCode_P.Switch_Threshold) {
    /* Abs: '<S211>/Abs1' */
    cCode_B.Abs1 = fabs(cCode_B.Sum_n4);

    /* Product: '<S211>/Divide' */
    cCode_B.Divide_b = cCode_B.Sum_n4 / cCode_B.Abs1;

    /* Switch: '<S209>/Switch' */
    cCode_B.Switch_f = cCode_B.Divide_b;
  } else {
    /* Switch: '<S209>/Switch' */
    cCode_B.Switch_f = cCode_B.Sum_n4;
  }

  /* End of Switch: '<S209>/Switch' */

  /* Product: '<S209>/Product' */
  cCode_B.Product = cCode_B.ReciprocalSqrt * cCode_B.Switch_f;

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   */
  cCode_B.Product_c = cCode_B.Product * cCode_P.Constant_Value_k;

  /* Sum: '<S10>/Sum4' */
  cCode_B.Sum4 = cCode_B.Sum1 + cCode_B.Product_c;

  /* Gain: '<S10>/Gain' */
  cCode_B.Gain = cCode_P.Gain_Gain * cCode_B.Sum4;

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  cCode_B.Product_a = cCode_B.Gain * cCode_P.Constant1_Value;

  /* Switch: '<S1>/Switch' */
  if (cCode_B.Product_a > cCode_P.Switch_Threshold_p) {
    /* Polyval: '<S1>/Positive Force Function' */
    cCode_B.PositiveForceFunction_f = cCode_P.PositiveForceFunction_Coefs[0];

    /* Polyval: '<S1>/Positive Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S1>/Positive Force Function' */
      cCode_B.PositiveForceFunction_f = cCode_B.PositiveForceFunction_f *
        cCode_B.Product_a + cCode_P.PositiveForceFunction_Coefs[idx + 1];
    }

    /* Switch: '<S1>/Switch' */
    cCode_B.Switch_e = cCode_B.PositiveForceFunction_f;
  } else {
    /* Polyval: '<S1>/Negative Force Function' */
    cCode_B.NegativeForceFunction_k = cCode_P.NegativeForceFunction_Coefs[0];

    /* Polyval: '<S1>/Negative Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S1>/Negative Force Function' */
      cCode_B.NegativeForceFunction_k = cCode_B.NegativeForceFunction_k *
        cCode_B.Product_a + cCode_P.NegativeForceFunction_Coefs[idx + 1];
    }

    /* Switch: '<S1>/Switch' */
    cCode_B.Switch_e = cCode_B.NegativeForceFunction_k;
  }

  /* End of Switch: '<S1>/Switch' */
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* ToWorkspace: '<Root>/To Workspace4' */
    if (rtmIsMajorTimeStep(cCode_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (cCode_DW.ToWorkspace4_PWORK.LoggedData),
                      &cCode_B.Switch_e, 0);
    }
  }

  /* Sum: '<S210>/Sum2' */
  cCode_B.Sum2_o = cCode_B.Sum_n - cCode_B.Sum_a;

  /* Sum: '<S10>/Sum1' */
  cCode_B.Sum1_i = cCode_B.Sum2_o + cCode_B.Product_c;

  /* Gain: '<S10>/Gain1' */
  cCode_B.Gain1 = cCode_P.Gain1_Gain * cCode_B.Sum1_i;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  cCode_B.Product_o = cCode_B.Gain1 * cCode_P.Constant1_Value_h;

  /* Switch: '<S2>/Switch' */
  if (cCode_B.Product_o > cCode_P.Switch_Threshold_c) {
    /* Polyval: '<S2>/Positive Force Function' */
    cCode_B.PositiveForceFunction_e = cCode_P.PositiveForceFunction_Coefs_k[0];

    /* Polyval: '<S2>/Positive Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S2>/Positive Force Function' */
      cCode_B.PositiveForceFunction_e = cCode_B.PositiveForceFunction_e *
        cCode_B.Product_o + cCode_P.PositiveForceFunction_Coefs_k[idx + 1];
    }

    /* Switch: '<S2>/Switch' */
    cCode_B.Switch_p = cCode_B.PositiveForceFunction_e;
  } else {
    /* Polyval: '<S2>/Negative Force Function' */
    cCode_B.NegativeForceFunction_li = cCode_P.NegativeForceFunction_Coefs_g[0];

    /* Polyval: '<S2>/Negative Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S2>/Negative Force Function' */
      cCode_B.NegativeForceFunction_li = cCode_B.NegativeForceFunction_li *
        cCode_B.Product_o + cCode_P.NegativeForceFunction_Coefs_g[idx + 1];
    }

    /* Switch: '<S2>/Switch' */
    cCode_B.Switch_p = cCode_B.NegativeForceFunction_li;
  }

  /* End of Switch: '<S2>/Switch' */
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* ToWorkspace: '<Root>/To Workspace5' */
    if (rtmIsMajorTimeStep(cCode_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (cCode_DW.ToWorkspace5_PWORK.LoggedData),
                      &cCode_B.Switch_p, 0);
    }
  }

  /* Sum: '<S210>/Sum3' */
  cCode_B.Sum3 = cCode_B.Sum_a - cCode_B.Sum_n;

  /* Sum: '<S10>/Sum2' */
  cCode_B.Sum2_i = cCode_B.Sum3 + cCode_B.Product_c;

  /* Gain: '<S10>/Gain2' */
  cCode_B.Gain2 = cCode_P.Gain2_Gain * cCode_B.Sum2_i;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  cCode_B.Product_d = cCode_B.Gain2 * cCode_P.Constant1_Value_i;

  /* Switch: '<S3>/Switch' */
  if (cCode_B.Product_d > cCode_P.Switch_Threshold_n) {
    /* Polyval: '<S3>/Positive Force Function' */
    cCode_B.PositiveForceFunction_g = cCode_P.PositiveForceFunction_Coefs_h[0];

    /* Polyval: '<S3>/Positive Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S3>/Positive Force Function' */
      cCode_B.PositiveForceFunction_g = cCode_B.PositiveForceFunction_g *
        cCode_B.Product_d + cCode_P.PositiveForceFunction_Coefs_h[idx + 1];
    }

    /* Switch: '<S3>/Switch' */
    cCode_B.Switch_n = cCode_B.PositiveForceFunction_g;
  } else {
    /* Polyval: '<S3>/Negative Force Function' */
    cCode_B.NegativeForceFunction_l = cCode_P.NegativeForceFunction_Coefs_e[0];

    /* Polyval: '<S3>/Negative Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S3>/Negative Force Function' */
      cCode_B.NegativeForceFunction_l = cCode_B.NegativeForceFunction_l *
        cCode_B.Product_d + cCode_P.NegativeForceFunction_Coefs_e[idx + 1];
    }

    /* Switch: '<S3>/Switch' */
    cCode_B.Switch_n = cCode_B.NegativeForceFunction_l;
  }

  /* End of Switch: '<S3>/Switch' */
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* ToWorkspace: '<Root>/To Workspace6' */
    if (rtmIsMajorTimeStep(cCode_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (cCode_DW.ToWorkspace6_PWORK.LoggedData),
                      &cCode_B.Switch_n, 0);
    }
  }

  /* Sum: '<S210>/Sum4' */
  cCode_B.Sum4_k = (0.0 - cCode_B.Sum_n) - cCode_B.Sum_a;

  /* Sum: '<S10>/Sum3' */
  cCode_B.Sum3_h = cCode_B.Sum4_k + cCode_B.Product_c;

  /* Gain: '<S10>/Gain3' */
  cCode_B.Gain3 = cCode_P.Gain3_Gain * cCode_B.Sum3_h;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  cCode_B.Product_n = cCode_B.Gain3 * cCode_P.Constant1_Value_c;

  /* Switch: '<S4>/Switch' */
  if (cCode_B.Product_n > cCode_P.Switch_Threshold_m) {
    /* Polyval: '<S4>/Positive Force Function' */
    cCode_B.PositiveForceFunction = cCode_P.PositiveForceFunction_Coefs_m[0];

    /* Polyval: '<S4>/Positive Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S4>/Positive Force Function' */
      cCode_B.PositiveForceFunction = cCode_B.PositiveForceFunction *
        cCode_B.Product_n + cCode_P.PositiveForceFunction_Coefs_m[idx + 1];
    }

    /* Switch: '<S4>/Switch' */
    cCode_B.Switch_b = cCode_B.PositiveForceFunction;
  } else {
    /* Polyval: '<S4>/Negative Force Function' */
    cCode_B.NegativeForceFunction = cCode_P.NegativeForceFunction_Coefs_j[0];

    /* Polyval: '<S4>/Negative Force Function' */
    for (idx = 0; idx < 5; idx++) {
      /* Polyval: '<S4>/Negative Force Function' */
      cCode_B.NegativeForceFunction = cCode_B.NegativeForceFunction *
        cCode_B.Product_n + cCode_P.NegativeForceFunction_Coefs_j[idx + 1];
    }

    /* Switch: '<S4>/Switch' */
    cCode_B.Switch_b = cCode_B.NegativeForceFunction;
  }

  /* End of Switch: '<S4>/Switch' */
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* ToWorkspace: '<Root>/To Workspace7' */
    if (rtmIsMajorTimeStep(cCode_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (cCode_DW.ToWorkspace7_PWORK.LoggedData),
                      &cCode_B.Switch_b, 0);
    }

    /* Abs: '<S13>/Abs' */
    cCode_B.Abs_m = fabs(cCode_B.Sum[2]);

    /* RelationalOperator: '<S13>/Relational Operator' incorporates:
     *  Constant: '<S13>/Constant'
     */
    cCode_B.RelationalOperator_p = (cCode_B.Abs_m <= cCode_P.Constant_Value_c);

    /* Switch: '<S13>/Switch' */
    if (cCode_B.RelationalOperator_p) {
      /* Switch: '<S13>/Switch' */
      cCode_B.Switch_d = cCode_B.Sum[2];
    } else {
      /* Abs: '<S16>/Abs1' */
      cCode_B.Abs1_f = fabs(cCode_B.Sum[2]);

      /* Product: '<S16>/Divide' */
      cCode_B.Divide_d = cCode_B.Sum[2] / cCode_B.Abs1_f;

      /* Product: '<S13>/Product' incorporates:
       *  Constant: '<S13>/Constant2'
       */
      cCode_B.Product_c0 = cCode_B.Divide_d * cCode_P.Constant2_Value_c1;

      /* Sum: '<S13>/Sum1' */
      cCode_B.Sum1_d = cCode_B.Sum[2] - cCode_B.Product_c0;

      /* Switch: '<S13>/Switch' */
      cCode_B.Switch_d = cCode_B.Sum1_d;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Product: '<S5>/Divide2' incorporates:
     *  Constant: '<S5>/Constant'
     */
    cCode_B.Divide2 = cCode_B.Switch_d / cCode_P.Constant_Value_b;

    /* Gain: '<S138>/Derivative Gain' */
    cCode_B.DerivativeGain_i = cCode_P.PIDController2_D * cCode_B.Divide2;
  }

  /* Integrator: '<S139>/Filter' */
  cCode_B.Filter_p = cCode_X.Filter_CSTATE_a;

  /* Sum: '<S139>/SumD' */
  cCode_B.SumD_d = cCode_B.DerivativeGain_i - cCode_B.Filter_p;

  /* Gain: '<S147>/Filter Coefficient' */
  cCode_B.FilterCoefficient_ff = cCode_P.PIDController2_N * cCode_B.SumD_d;
  if (rtmIsMajorTimeStep(cCode_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(cCode_M->rtwLogInfo, (cCode_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(cCode_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(cCode_M)!=-1) &&
          !((rtmGetTFinal(cCode_M)-(((cCode_M->Timing.clockTick1+
               cCode_M->Timing.clockTickH1* 4294967296.0)) * 0.2)) >
            (((cCode_M->Timing.clockTick1+cCode_M->Timing.clockTickH1*
               4294967296.0)) * 0.2) * (DBL_EPSILON))) {
        rtmSetErrorStatus(cCode_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&cCode_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++cCode_M->Timing.clockTick0)) {
      ++cCode_M->Timing.clockTickH0;
    }

    cCode_M->Timing.t[0] = rtsiGetSolverStopTime(&cCode_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      cCode_M->Timing.clockTick1++;
      if (!cCode_M->Timing.clockTick1) {
        cCode_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void cCode_derivatives(void)
{
  XDot_cCode_T *_rtXdot;
  _rtXdot = ((XDot_cCode_T *) cCode_M->derivs);

  /* Derivatives for Integrator: '<S43>/Filter' */
  _rtXdot->Filter_CSTATE = cCode_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S91>/Filter' */
  _rtXdot->Filter_CSTATE_m = cCode_B.FilterCoefficient_f;

  /* Derivatives for Integrator: '<S187>/Filter' */
  _rtXdot->Filter_CSTATE_l = cCode_B.FilterCoefficient_i;

  /* Derivatives for Integrator: '<S139>/Filter' */
  _rtXdot->Filter_CSTATE_a = cCode_B.FilterCoefficient_ff;
}

/* Model initialize function */
void cCode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)cCode_M, 0,
                sizeof(RT_MODEL_cCode_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&cCode_M->solverInfo, &cCode_M->Timing.simTimeStep);
    rtsiSetTPtr(&cCode_M->solverInfo, &rtmGetTPtr(cCode_M));
    rtsiSetStepSizePtr(&cCode_M->solverInfo, &cCode_M->Timing.stepSize0);
    rtsiSetdXPtr(&cCode_M->solverInfo, &cCode_M->derivs);
    rtsiSetContStatesPtr(&cCode_M->solverInfo, (real_T **) &cCode_M->contStates);
    rtsiSetNumContStatesPtr(&cCode_M->solverInfo, &cCode_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&cCode_M->solverInfo,
      &cCode_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&cCode_M->solverInfo,
      &cCode_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&cCode_M->solverInfo,
      &cCode_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&cCode_M->solverInfo, (&rtmGetErrorStatus(cCode_M)));
    rtsiSetRTModelPtr(&cCode_M->solverInfo, cCode_M);
  }

  rtsiSetSimTimeStep(&cCode_M->solverInfo, MAJOR_TIME_STEP);
  cCode_M->intgData.y = cCode_M->odeY;
  cCode_M->intgData.f[0] = cCode_M->odeF[0];
  cCode_M->intgData.f[1] = cCode_M->odeF[1];
  cCode_M->intgData.f[2] = cCode_M->odeF[2];
  cCode_M->contStates = ((X_cCode_T *) &cCode_X);
  rtsiSetSolverData(&cCode_M->solverInfo, (void *)&cCode_M->intgData);
  rtsiSetSolverName(&cCode_M->solverInfo,"ode3");
  rtmSetTPtr(cCode_M, &cCode_M->Timing.tArray[0]);
  rtmSetTFinal(cCode_M, -1);
  cCode_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    cCode_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(cCode_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(cCode_M->rtwLogInfo, (NULL));
    rtliSetLogT(cCode_M->rtwLogInfo, "tout");
    rtliSetLogX(cCode_M->rtwLogInfo, "");
    rtliSetLogXFinal(cCode_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(cCode_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(cCode_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(cCode_M->rtwLogInfo, 0);
    rtliSetLogDecimation(cCode_M->rtwLogInfo, 1);
    rtliSetLogY(cCode_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(cCode_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(cCode_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &cCode_B), 0,
                sizeof(B_cCode_T));

  /* states (continuous) */
  {
    (void) memset((void *)&cCode_X, 0,
                  sizeof(X_cCode_T));
  }

  /* states (dwork) */
  (void) memset((void *)&cCode_DW, 0,
                sizeof(DW_cCode_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(cCode_M->rtwLogInfo, 0.0, rtmGetTFinal
    (cCode_M), cCode_M->Timing.stepSize0, (&rtmGetErrorStatus(cCode_M)));

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace4' */
  {
    int_T dimensions[1] = { 1 };

    cCode_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
      cCode_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(cCode_M),
      cCode_M->Timing.stepSize0,
      (&rtmGetErrorStatus(cCode_M)),
      "PWM_TR",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      1,
      1,
      0.2,
      1);
    if (cCode_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace5' */
  {
    int_T dimensions[1] = { 1 };

    cCode_DW.ToWorkspace5_PWORK.LoggedData = rt_CreateLogVar(
      cCode_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(cCode_M),
      cCode_M->Timing.stepSize0,
      (&rtmGetErrorStatus(cCode_M)),
      "PWM_TL",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      1,
      1,
      0.2,
      1);
    if (cCode_DW.ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace6' */
  {
    int_T dimensions[1] = { 1 };

    cCode_DW.ToWorkspace6_PWORK.LoggedData = rt_CreateLogVar(
      cCode_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(cCode_M),
      cCode_M->Timing.stepSize0,
      (&rtmGetErrorStatus(cCode_M)),
      "PWM_BR",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      1,
      1,
      0.2,
      1);
    if (cCode_DW.ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace7' */
  {
    int_T dimensions[1] = { 1 };

    cCode_DW.ToWorkspace7_PWORK.LoggedData = rt_CreateLogVar(
      cCode_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(cCode_M),
      cCode_M->Timing.stepSize0,
      (&rtmGetErrorStatus(cCode_M)),
      "PWM_BL",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      1,
      1,
      0.2,
      1);
    if (cCode_DW.ToWorkspace7_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S43>/Filter' */
  cCode_X.Filter_CSTATE = cCode_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S91>/Filter' */
  cCode_X.Filter_CSTATE_m = cCode_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S187>/Filter' */
  cCode_X.Filter_CSTATE_l = cCode_P.PIDController3_InitialCondition;

  /* InitializeConditions for Integrator: '<S139>/Filter' */
  cCode_X.Filter_CSTATE_a = cCode_P.PIDController2_InitialCondition;
}

/* Model terminate function */
void cCode_terminate(void)
{
  /* (no terminate code required) */
}
