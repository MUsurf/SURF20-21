/*
 * cCode.h
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

#ifndef RTW_HEADER_cCode_h_
#define RTW_HEADER_cCode_h_
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef cCode_COMMON_INCLUDES_
#define cCode_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* cCode_COMMON_INCLUDES_ */

#include "cCode_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum[4];                       /* '<S5>/Sum' */
  real_T Abs;                          /* '<S11>/Abs' */
  real_T Switch;                       /* '<S11>/Switch' */
  real_T Divide;                       /* '<S5>/Divide' */
  real_T ProportionalGain;             /* '<S53>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S42>/Derivative Gain' */
  real_T Filter;                       /* '<S43>/Filter' */
  real_T SumD;                         /* '<S43>/SumD' */
  real_T FilterCoefficient;            /* '<S51>/Filter Coefficient' */
  real_T Sum_n;                        /* '<S57>/Sum' */
  real_T Abs_a;                        /* '<S12>/Abs' */
  real_T Switch_k;                     /* '<S12>/Switch' */
  real_T Divide1;                      /* '<S5>/Divide1' */
  real_T ProportionalGain_o;           /* '<S101>/Proportional Gain' */
  real_T DerivativeGain_f;             /* '<S90>/Derivative Gain' */
  real_T Filter_h;                     /* '<S91>/Filter' */
  real_T SumD_a;                       /* '<S91>/SumD' */
  real_T FilterCoefficient_f;          /* '<S99>/Filter Coefficient' */
  real_T Sum_a;                        /* '<S105>/Sum' */
  real_T Sum1;                         /* '<S210>/Sum1' */
  real_T MagnitudeSquared;             /* '<S209>/Magnitude Squared' */
  real_T MagnitudeSquared1;            /* '<S209>/Magnitude Squared1' */
  real_T Sum2;                         /* '<S209>/Sum2' */
  real_T Sum1_l;                       /* '<S209>/Sum1' */
  real_T ReciprocalSqrt;               /* '<S209>/Reciprocal Sqrt' */
  real_T ProportionalGain_e;           /* '<S197>/Proportional Gain' */
  real_T DerivativeGain_d;             /* '<S186>/Derivative Gain' */
  real_T Filter_e;                     /* '<S187>/Filter' */
  real_T SumD_m;                       /* '<S187>/SumD' */
  real_T FilterCoefficient_i;          /* '<S195>/Filter Coefficient' */
  real_T Sum_n4;                       /* '<S201>/Sum' */
  real_T MagnitudeSquared2;            /* '<S209>/Magnitude Squared2' */
  real_T Switch_f;                     /* '<S209>/Switch' */
  real_T Product;                      /* '<S209>/Product' */
  real_T Product_c;                    /* '<S10>/Product' */
  real_T Sum4;                         /* '<S10>/Sum4' */
  real_T Gain;                         /* '<S10>/Gain' */
  real_T Product_a;                    /* '<S1>/Product' */
  real_T Switch_e;                     /* '<S1>/Switch' */
  real_T Sum2_o;                       /* '<S210>/Sum2' */
  real_T Sum1_i;                       /* '<S10>/Sum1' */
  real_T Gain1;                        /* '<S10>/Gain1' */
  real_T Product_o;                    /* '<S2>/Product' */
  real_T Switch_p;                     /* '<S2>/Switch' */
  real_T Sum3;                         /* '<S210>/Sum3' */
  real_T Sum2_i;                       /* '<S10>/Sum2' */
  real_T Gain2;                        /* '<S10>/Gain2' */
  real_T Product_d;                    /* '<S3>/Product' */
  real_T Switch_n;                     /* '<S3>/Switch' */
  real_T Sum4_k;                       /* '<S210>/Sum4' */
  real_T Sum3_h;                       /* '<S10>/Sum3' */
  real_T Gain3;                        /* '<S10>/Gain3' */
  real_T Product_n;                    /* '<S4>/Product' */
  real_T Switch_b;                     /* '<S4>/Switch' */
  real_T Abs_m;                        /* '<S13>/Abs' */
  real_T Switch_d;                     /* '<S13>/Switch' */
  real_T Divide2;                      /* '<S5>/Divide2' */
  real_T DerivativeGain_i;             /* '<S138>/Derivative Gain' */
  real_T Filter_p;                     /* '<S139>/Filter' */
  real_T SumD_d;                       /* '<S139>/SumD' */
  real_T FilterCoefficient_ff;         /* '<S147>/Filter Coefficient' */
  real_T Abs1;                         /* '<S211>/Abs1' */
  real_T Divide_b;                     /* '<S211>/Divide' */
  real_T Abs1_f;                       /* '<S16>/Abs1' */
  real_T Divide_d;                     /* '<S16>/Divide' */
  real_T Product_c0;                   /* '<S13>/Product' */
  real_T Sum1_d;                       /* '<S13>/Sum1' */
  real_T Abs1_p;                       /* '<S15>/Abs1' */
  real_T Divide_c;                     /* '<S15>/Divide' */
  real_T Product_b;                    /* '<S12>/Product' */
  real_T Sum1_b;                       /* '<S12>/Sum1' */
  real_T Abs1_a;                       /* '<S14>/Abs1' */
  real_T Divide_bs;                    /* '<S14>/Divide' */
  real_T Product_f;                    /* '<S11>/Product' */
  real_T Sum1_g;                       /* '<S11>/Sum1' */
  real_T NegativeForceFunction;        /* '<S4>/Negative Force Function' */
  real_T PositiveForceFunction;        /* '<S4>/Positive Force Function' */
  real_T NegativeForceFunction_l;      /* '<S3>/Negative Force Function' */
  real_T PositiveForceFunction_g;      /* '<S3>/Positive Force Function' */
  real_T NegativeForceFunction_li;     /* '<S2>/Negative Force Function' */
  real_T PositiveForceFunction_e;      /* '<S2>/Positive Force Function' */
  real_T NegativeForceFunction_k;      /* '<S1>/Negative Force Function' */
  real_T PositiveForceFunction_f;      /* '<S1>/Positive Force Function' */
  boolean_T RelationalOperator;        /* '<S11>/Relational Operator' */
  boolean_T RelationalOperator_m;      /* '<S12>/Relational Operator' */
  boolean_T RelationalOperator_p;      /* '<S13>/Relational Operator' */
} B_cCode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<Root>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<Root>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<Root>/To Workspace6' */

  struct {
    void *LoggedData;
  } ToWorkspace7_PWORK;                /* '<Root>/To Workspace7' */
} DW_cCode_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S43>/Filter' */
  real_T Filter_CSTATE_m;              /* '<S91>/Filter' */
  real_T Filter_CSTATE_l;              /* '<S187>/Filter' */
  real_T Filter_CSTATE_a;              /* '<S139>/Filter' */
} X_cCode_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Filter_CSTATE;                /* '<S43>/Filter' */
  real_T Filter_CSTATE_m;              /* '<S91>/Filter' */
  real_T Filter_CSTATE_l;              /* '<S187>/Filter' */
  real_T Filter_CSTATE_a;              /* '<S139>/Filter' */
} XDot_cCode_T;

/* State disabled  */
typedef struct {
  boolean_T Filter_CSTATE;             /* '<S43>/Filter' */
  boolean_T Filter_CSTATE_m;           /* '<S91>/Filter' */
  boolean_T Filter_CSTATE_l;           /* '<S187>/Filter' */
  boolean_T Filter_CSTATE_a;           /* '<S139>/Filter' */
} XDis_cCode_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_cCode_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S42>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S90>/Derivative Gain'
                                        */
  real_T PIDController3_D;             /* Mask Parameter: PIDController3_D
                                        * Referenced by: '<S186>/Derivative Gain'
                                        */
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S138>/Derivative Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S43>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S91>/Filter'
                               */
  real_T PIDController3_InitialCondition;
                              /* Mask Parameter: PIDController3_InitialCondition
                               * Referenced by: '<S187>/Filter'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S139>/Filter'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S51>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S99>/Filter Coefficient'
                                        */
  real_T PIDController3_N;             /* Mask Parameter: PIDController3_N
                                        * Referenced by: '<S195>/Filter Coefficient'
                                        */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S147>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S53>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S101>/Proportional Gain'
                                        */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S197>/Proportional Gain'
                                        */
  real_T PositiveForceFunction_Coefs[6];
  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S1>/Positive Force Function'
   */
  real_T NegativeForceFunction_Coefs[6];
  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S1>/Negative Force Function'
   */
  real_T PositiveForceFunction_Coefs_k[6];
  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S2>/Positive Force Function'
   */
  real_T NegativeForceFunction_Coefs_g[6];
  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S2>/Negative Force Function'
   */
  real_T PositiveForceFunction_Coefs_h[6];
  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S3>/Positive Force Function'
   */
  real_T NegativeForceFunction_Coefs_e[6];
  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S3>/Negative Force Function'
   */
  real_T PositiveForceFunction_Coefs_m[6];
  /* Expression: [0.2032943541, -2.8056908375, +15.2118690864, -45.2131950706, +139.5205863709, +1530.2000934945]
   * Referenced by: '<S4>/Positive Force Function'
   */
  real_T NegativeForceFunction_Coefs_j[6];
  /* Expression: [0.8474227576, +8.8117005083, +35.8803167244, +79.5809890093, +181.956206474, +1471.7166709989]
   * Referenced by: '<S4>/Negative Force Function'
   */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant2_Value_c;            /* Expression: 360
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant2_Value_c1;           /* Expression: 360
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Pitch_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/Pitch'
                                        */
  real_T Roll_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Roll'
                                        */
  real_T Yaw_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/Yaw'
                                        */
  real_T Depth_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/Depth'
                                        */
  real_T IMUPitch_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/IMU Pitch'
                                        */
  real_T IMURoll_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/IMU Roll'
                                        */
  real_T IMUYaw_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/IMU Yaw'
                                        */
  real_T IMUDepth_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/IMU Depth'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 180
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 180
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S209>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S209>/Switch'
                                        */
  real_T Constant_Value_k;             /* Expression: -1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 2
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Constant1_Value_c;            /* Expression: 2
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant_Value_c;             /* Expression: 180
                                        * Referenced by: '<S13>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_cCode_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_cCode_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_cCode_T cCode_P;

/* Block signals (default storage) */
extern B_cCode_T cCode_B;

/* Continuous states (default storage) */
extern X_cCode_T cCode_X;

/* Block states (default storage) */
extern DW_cCode_T cCode_DW;

/* Model entry point functions */
extern void cCode_initialize(void);
extern void cCode_step(void);
extern void cCode_terminate(void);

/* Real-time Model object */
extern RT_MODEL_cCode_T *const cCode_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S149>/Proportional Gain' : Unused code path elimination
 * Block '<S153>/Sum' : Unused code path elimination
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
 * '<Root>' : 'cCode'
 * '<S1>'   : 'cCode/ '
 * '<S2>'   : 'cCode/ 1'
 * '<S3>'   : 'cCode/ 2'
 * '<S4>'   : 'cCode/ 3'
 * '<S5>'   : 'cCode/Absolute Errors'
 * '<S6>'   : 'cCode/PID Controller'
 * '<S7>'   : 'cCode/PID Controller1'
 * '<S8>'   : 'cCode/PID Controller2'
 * '<S9>'   : 'cCode/PID Controller3'
 * '<S10>'  : 'cCode/Subsystem'
 * '<S11>'  : 'cCode/Absolute Errors/Absolute Error'
 * '<S12>'  : 'cCode/Absolute Errors/Absolute Error1'
 * '<S13>'  : 'cCode/Absolute Errors/Absolute Error2'
 * '<S14>'  : 'cCode/Absolute Errors/Absolute Error/Signum'
 * '<S15>'  : 'cCode/Absolute Errors/Absolute Error1/Signum'
 * '<S16>'  : 'cCode/Absolute Errors/Absolute Error2/Signum'
 * '<S17>'  : 'cCode/PID Controller/Anti-windup'
 * '<S18>'  : 'cCode/PID Controller/D Gain'
 * '<S19>'  : 'cCode/PID Controller/Filter'
 * '<S20>'  : 'cCode/PID Controller/Filter ICs'
 * '<S21>'  : 'cCode/PID Controller/I Gain'
 * '<S22>'  : 'cCode/PID Controller/Ideal P Gain'
 * '<S23>'  : 'cCode/PID Controller/Ideal P Gain Fdbk'
 * '<S24>'  : 'cCode/PID Controller/Integrator'
 * '<S25>'  : 'cCode/PID Controller/Integrator ICs'
 * '<S26>'  : 'cCode/PID Controller/N Copy'
 * '<S27>'  : 'cCode/PID Controller/N Gain'
 * '<S28>'  : 'cCode/PID Controller/P Copy'
 * '<S29>'  : 'cCode/PID Controller/Parallel P Gain'
 * '<S30>'  : 'cCode/PID Controller/Reset Signal'
 * '<S31>'  : 'cCode/PID Controller/Saturation'
 * '<S32>'  : 'cCode/PID Controller/Saturation Fdbk'
 * '<S33>'  : 'cCode/PID Controller/Sum'
 * '<S34>'  : 'cCode/PID Controller/Sum Fdbk'
 * '<S35>'  : 'cCode/PID Controller/Tracking Mode'
 * '<S36>'  : 'cCode/PID Controller/Tracking Mode Sum'
 * '<S37>'  : 'cCode/PID Controller/Tsamp - Integral'
 * '<S38>'  : 'cCode/PID Controller/Tsamp - Ngain'
 * '<S39>'  : 'cCode/PID Controller/postSat Signal'
 * '<S40>'  : 'cCode/PID Controller/preSat Signal'
 * '<S41>'  : 'cCode/PID Controller/Anti-windup/Disabled'
 * '<S42>'  : 'cCode/PID Controller/D Gain/Internal Parameters'
 * '<S43>'  : 'cCode/PID Controller/Filter/Cont. Filter'
 * '<S44>'  : 'cCode/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'cCode/PID Controller/I Gain/Disabled'
 * '<S46>'  : 'cCode/PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'cCode/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'cCode/PID Controller/Integrator/Disabled'
 * '<S49>'  : 'cCode/PID Controller/Integrator ICs/Disabled'
 * '<S50>'  : 'cCode/PID Controller/N Copy/Disabled'
 * '<S51>'  : 'cCode/PID Controller/N Gain/Internal Parameters'
 * '<S52>'  : 'cCode/PID Controller/P Copy/Disabled'
 * '<S53>'  : 'cCode/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S54>'  : 'cCode/PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'cCode/PID Controller/Saturation/Passthrough'
 * '<S56>'  : 'cCode/PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'cCode/PID Controller/Sum/Sum_PD'
 * '<S58>'  : 'cCode/PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'cCode/PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'cCode/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'cCode/PID Controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S62>'  : 'cCode/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'cCode/PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'cCode/PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'cCode/PID Controller1/Anti-windup'
 * '<S66>'  : 'cCode/PID Controller1/D Gain'
 * '<S67>'  : 'cCode/PID Controller1/Filter'
 * '<S68>'  : 'cCode/PID Controller1/Filter ICs'
 * '<S69>'  : 'cCode/PID Controller1/I Gain'
 * '<S70>'  : 'cCode/PID Controller1/Ideal P Gain'
 * '<S71>'  : 'cCode/PID Controller1/Ideal P Gain Fdbk'
 * '<S72>'  : 'cCode/PID Controller1/Integrator'
 * '<S73>'  : 'cCode/PID Controller1/Integrator ICs'
 * '<S74>'  : 'cCode/PID Controller1/N Copy'
 * '<S75>'  : 'cCode/PID Controller1/N Gain'
 * '<S76>'  : 'cCode/PID Controller1/P Copy'
 * '<S77>'  : 'cCode/PID Controller1/Parallel P Gain'
 * '<S78>'  : 'cCode/PID Controller1/Reset Signal'
 * '<S79>'  : 'cCode/PID Controller1/Saturation'
 * '<S80>'  : 'cCode/PID Controller1/Saturation Fdbk'
 * '<S81>'  : 'cCode/PID Controller1/Sum'
 * '<S82>'  : 'cCode/PID Controller1/Sum Fdbk'
 * '<S83>'  : 'cCode/PID Controller1/Tracking Mode'
 * '<S84>'  : 'cCode/PID Controller1/Tracking Mode Sum'
 * '<S85>'  : 'cCode/PID Controller1/Tsamp - Integral'
 * '<S86>'  : 'cCode/PID Controller1/Tsamp - Ngain'
 * '<S87>'  : 'cCode/PID Controller1/postSat Signal'
 * '<S88>'  : 'cCode/PID Controller1/preSat Signal'
 * '<S89>'  : 'cCode/PID Controller1/Anti-windup/Disabled'
 * '<S90>'  : 'cCode/PID Controller1/D Gain/Internal Parameters'
 * '<S91>'  : 'cCode/PID Controller1/Filter/Cont. Filter'
 * '<S92>'  : 'cCode/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S93>'  : 'cCode/PID Controller1/I Gain/Disabled'
 * '<S94>'  : 'cCode/PID Controller1/Ideal P Gain/Passthrough'
 * '<S95>'  : 'cCode/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'cCode/PID Controller1/Integrator/Disabled'
 * '<S97>'  : 'cCode/PID Controller1/Integrator ICs/Disabled'
 * '<S98>'  : 'cCode/PID Controller1/N Copy/Disabled'
 * '<S99>'  : 'cCode/PID Controller1/N Gain/Internal Parameters'
 * '<S100>' : 'cCode/PID Controller1/P Copy/Disabled'
 * '<S101>' : 'cCode/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'cCode/PID Controller1/Reset Signal/Disabled'
 * '<S103>' : 'cCode/PID Controller1/Saturation/Passthrough'
 * '<S104>' : 'cCode/PID Controller1/Saturation Fdbk/Disabled'
 * '<S105>' : 'cCode/PID Controller1/Sum/Sum_PD'
 * '<S106>' : 'cCode/PID Controller1/Sum Fdbk/Disabled'
 * '<S107>' : 'cCode/PID Controller1/Tracking Mode/Disabled'
 * '<S108>' : 'cCode/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'cCode/PID Controller1/Tsamp - Integral/Disabled wSignal Specification'
 * '<S110>' : 'cCode/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'cCode/PID Controller1/postSat Signal/Forward_Path'
 * '<S112>' : 'cCode/PID Controller1/preSat Signal/Forward_Path'
 * '<S113>' : 'cCode/PID Controller2/Anti-windup'
 * '<S114>' : 'cCode/PID Controller2/D Gain'
 * '<S115>' : 'cCode/PID Controller2/Filter'
 * '<S116>' : 'cCode/PID Controller2/Filter ICs'
 * '<S117>' : 'cCode/PID Controller2/I Gain'
 * '<S118>' : 'cCode/PID Controller2/Ideal P Gain'
 * '<S119>' : 'cCode/PID Controller2/Ideal P Gain Fdbk'
 * '<S120>' : 'cCode/PID Controller2/Integrator'
 * '<S121>' : 'cCode/PID Controller2/Integrator ICs'
 * '<S122>' : 'cCode/PID Controller2/N Copy'
 * '<S123>' : 'cCode/PID Controller2/N Gain'
 * '<S124>' : 'cCode/PID Controller2/P Copy'
 * '<S125>' : 'cCode/PID Controller2/Parallel P Gain'
 * '<S126>' : 'cCode/PID Controller2/Reset Signal'
 * '<S127>' : 'cCode/PID Controller2/Saturation'
 * '<S128>' : 'cCode/PID Controller2/Saturation Fdbk'
 * '<S129>' : 'cCode/PID Controller2/Sum'
 * '<S130>' : 'cCode/PID Controller2/Sum Fdbk'
 * '<S131>' : 'cCode/PID Controller2/Tracking Mode'
 * '<S132>' : 'cCode/PID Controller2/Tracking Mode Sum'
 * '<S133>' : 'cCode/PID Controller2/Tsamp - Integral'
 * '<S134>' : 'cCode/PID Controller2/Tsamp - Ngain'
 * '<S135>' : 'cCode/PID Controller2/postSat Signal'
 * '<S136>' : 'cCode/PID Controller2/preSat Signal'
 * '<S137>' : 'cCode/PID Controller2/Anti-windup/Disabled'
 * '<S138>' : 'cCode/PID Controller2/D Gain/Internal Parameters'
 * '<S139>' : 'cCode/PID Controller2/Filter/Cont. Filter'
 * '<S140>' : 'cCode/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S141>' : 'cCode/PID Controller2/I Gain/Disabled'
 * '<S142>' : 'cCode/PID Controller2/Ideal P Gain/Passthrough'
 * '<S143>' : 'cCode/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S144>' : 'cCode/PID Controller2/Integrator/Disabled'
 * '<S145>' : 'cCode/PID Controller2/Integrator ICs/Disabled'
 * '<S146>' : 'cCode/PID Controller2/N Copy/Disabled'
 * '<S147>' : 'cCode/PID Controller2/N Gain/Internal Parameters'
 * '<S148>' : 'cCode/PID Controller2/P Copy/Disabled'
 * '<S149>' : 'cCode/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S150>' : 'cCode/PID Controller2/Reset Signal/Disabled'
 * '<S151>' : 'cCode/PID Controller2/Saturation/Passthrough'
 * '<S152>' : 'cCode/PID Controller2/Saturation Fdbk/Disabled'
 * '<S153>' : 'cCode/PID Controller2/Sum/Sum_PD'
 * '<S154>' : 'cCode/PID Controller2/Sum Fdbk/Disabled'
 * '<S155>' : 'cCode/PID Controller2/Tracking Mode/Disabled'
 * '<S156>' : 'cCode/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S157>' : 'cCode/PID Controller2/Tsamp - Integral/Disabled wSignal Specification'
 * '<S158>' : 'cCode/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S159>' : 'cCode/PID Controller2/postSat Signal/Forward_Path'
 * '<S160>' : 'cCode/PID Controller2/preSat Signal/Forward_Path'
 * '<S161>' : 'cCode/PID Controller3/Anti-windup'
 * '<S162>' : 'cCode/PID Controller3/D Gain'
 * '<S163>' : 'cCode/PID Controller3/Filter'
 * '<S164>' : 'cCode/PID Controller3/Filter ICs'
 * '<S165>' : 'cCode/PID Controller3/I Gain'
 * '<S166>' : 'cCode/PID Controller3/Ideal P Gain'
 * '<S167>' : 'cCode/PID Controller3/Ideal P Gain Fdbk'
 * '<S168>' : 'cCode/PID Controller3/Integrator'
 * '<S169>' : 'cCode/PID Controller3/Integrator ICs'
 * '<S170>' : 'cCode/PID Controller3/N Copy'
 * '<S171>' : 'cCode/PID Controller3/N Gain'
 * '<S172>' : 'cCode/PID Controller3/P Copy'
 * '<S173>' : 'cCode/PID Controller3/Parallel P Gain'
 * '<S174>' : 'cCode/PID Controller3/Reset Signal'
 * '<S175>' : 'cCode/PID Controller3/Saturation'
 * '<S176>' : 'cCode/PID Controller3/Saturation Fdbk'
 * '<S177>' : 'cCode/PID Controller3/Sum'
 * '<S178>' : 'cCode/PID Controller3/Sum Fdbk'
 * '<S179>' : 'cCode/PID Controller3/Tracking Mode'
 * '<S180>' : 'cCode/PID Controller3/Tracking Mode Sum'
 * '<S181>' : 'cCode/PID Controller3/Tsamp - Integral'
 * '<S182>' : 'cCode/PID Controller3/Tsamp - Ngain'
 * '<S183>' : 'cCode/PID Controller3/postSat Signal'
 * '<S184>' : 'cCode/PID Controller3/preSat Signal'
 * '<S185>' : 'cCode/PID Controller3/Anti-windup/Disabled'
 * '<S186>' : 'cCode/PID Controller3/D Gain/Internal Parameters'
 * '<S187>' : 'cCode/PID Controller3/Filter/Cont. Filter'
 * '<S188>' : 'cCode/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S189>' : 'cCode/PID Controller3/I Gain/Disabled'
 * '<S190>' : 'cCode/PID Controller3/Ideal P Gain/Passthrough'
 * '<S191>' : 'cCode/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S192>' : 'cCode/PID Controller3/Integrator/Disabled'
 * '<S193>' : 'cCode/PID Controller3/Integrator ICs/Disabled'
 * '<S194>' : 'cCode/PID Controller3/N Copy/Disabled'
 * '<S195>' : 'cCode/PID Controller3/N Gain/Internal Parameters'
 * '<S196>' : 'cCode/PID Controller3/P Copy/Disabled'
 * '<S197>' : 'cCode/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S198>' : 'cCode/PID Controller3/Reset Signal/Disabled'
 * '<S199>' : 'cCode/PID Controller3/Saturation/Passthrough'
 * '<S200>' : 'cCode/PID Controller3/Saturation Fdbk/Disabled'
 * '<S201>' : 'cCode/PID Controller3/Sum/Sum_PD'
 * '<S202>' : 'cCode/PID Controller3/Sum Fdbk/Disabled'
 * '<S203>' : 'cCode/PID Controller3/Tracking Mode/Disabled'
 * '<S204>' : 'cCode/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S205>' : 'cCode/PID Controller3/Tsamp - Integral/Disabled wSignal Specification'
 * '<S206>' : 'cCode/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S207>' : 'cCode/PID Controller3/postSat Signal/Forward_Path'
 * '<S208>' : 'cCode/PID Controller3/preSat Signal/Forward_Path'
 * '<S209>' : 'cCode/Subsystem/Depth Compensation'
 * '<S210>' : 'cCode/Subsystem/Pitch and Roll Force Porportion'
 * '<S211>' : 'cCode/Subsystem/Depth Compensation/Signum'
 */
#endif                                 /* RTW_HEADER_cCode_h_ */
