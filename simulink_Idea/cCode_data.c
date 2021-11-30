/*
 * cCode_data.c
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

/* Block parameters (default storage) */
P_cCode_T cCode_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S42>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S90>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController3_D
   * Referenced by: '<S186>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S138>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S43>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S91>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialCondition
   * Referenced by: '<S187>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S139>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S51>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S99>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController3_N
   * Referenced by: '<S195>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController2_N
   * Referenced by: '<S147>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S53>/Proportional Gain'
   */
  5.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S101>/Proportional Gain'
   */
  5.0,

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S197>/Proportional Gain'
   */
  5.0,

  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S1>/Positive Force Function'
   */
  { 0.2032943541, -2.8056908375, 15.2118690864, -45.2131950706, 139.5205863709,
    1530.2000934945 },

  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S1>/Negative Force Function'
   */
  { 0.8474227576, 8.8117005083, 35.8803167244, 79.5809890093, 181.956206474,
    1471.7166709989 },

  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S2>/Positive Force Function'
   */
  { 0.2032943541, -2.8056908375, 15.2118690864, -45.2131950706, 139.5205863709,
    1530.2000934945 },

  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S2>/Negative Force Function'
   */
  { 0.8474227576, 8.8117005083, 35.8803167244, 79.5809890093, 181.956206474,
    1471.7166709989 },

  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S3>/Positive Force Function'
   */
  { 0.2032943541, -2.8056908375, 15.2118690864, -45.2131950706, 139.5205863709,
    1530.2000934945 },

  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S3>/Negative Force Function'
   */
  { 0.8474227576, 8.8117005083, 35.8803167244, 79.5809890093, 181.956206474,
    1471.7166709989 },

  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S4>/Positive Force Function'
   */
  { 0.2032943541, -2.8056908375, 15.2118690864, -45.2131950706, 139.5205863709,
    1530.2000934945 },

  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S4>/Negative Force Function'
   */
  { 0.8474227576, 8.8117005083, 35.8803167244, 79.5809890093, 181.956206474,
    1471.7166709989 },

  /* Expression: 360
   * Referenced by: '<S11>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S12>/Constant2'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S13>/Constant2'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pitch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Roll'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Yaw'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Depth'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/IMU Pitch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/IMU Roll'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/IMU Yaw'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/IMU Depth'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S11>/Constant'
   */
  180.0,

  /* Expression: 180
   * Referenced by: '<S5>/Constant'
   */
  180.0,

  /* Expression: 180
   * Referenced by: '<S12>/Constant'
   */
  180.0,

  /* Expression: 1
   * Referenced by: '<S209>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S209>/Switch'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S10>/Constant'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Gain'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Gain1'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S2>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Gain2'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Gain3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S4>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S13>/Constant'
   */
  180.0
};
