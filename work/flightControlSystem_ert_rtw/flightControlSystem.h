/*
 * flightControlSystem.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.469
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Jan 12 23:49:58 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rsedu_image.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S4>/Geofencing error' */
typedef struct {
  int8_T Geofencingerror_SubsysRanBC;  /* '<S4>/Geofencing error' */
} DW_Geofencingerror_flightControlSystem_T;

/* Block signals for system '<Root>/Flight Control System' */
typedef struct {
  real_T a[16];
  real_T b_a[16];
  real32_T MathFunction[9];            /* '<S239>/Math Function' */
  real32_T Reshape9to3x3columnmajor[9];
                                /* '<S331>/Reshape (9) to [3x3] column-major' */
  real32_T MathFunction_g[9];          /* '<S321>/Math Function' */
  real32_T rtb_MathFunction_m[9];
  real_T b_a_c[4];
  real_T Sum[3];                       /* '<S239>/Sum' */
  real_T Product2[3];                  /* '<S297>/Product2' */
  real_T Product3[3];                  /* '<S295>/Product3' */
  real_T DataTypeConversion2_k[3];     /* '<S240>/Data Type Conversion2' */
  real_T DataTypeConversion4[3];       /* '<S240>/Data Type Conversion4' */
  real32_T Sum1_f[6];                  /* '<S242>/Sum1' */
  real32_T fv[4];
  real32_T fv1[4];
  real32_T Switch_c[3];                /* '<S326>/Switch' */
  real32_T rtb_MathFunction_g_c[3];
  real_T DataTypeConversion3;          /* '<S239>/Data Type Conversion3' */
  real_T Reshapexhat[3];               /* '<S244>/Reshapexhat' */
  real_T w;
  real_T oa;
  real_T ob;
  real_T oc;
  real_T od;
  real_T n;
  real_T scale;
  real_T absxk;
  real_T fcn3;                         /* '<S304>/fcn3' */
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T d8;
  real_T d9;
  real_T a_tmp;
  real_T scale_b;
  real_T absxk_p;
  real_T t;
  real32_T Product[2];                 /* '<S322>/Product' */
  real32_T TmpSignalConversionAtIIRgyrozInport1[2];
  real32_T SignPreSat[2];              /* '<S190>/SignPreSat' */
  real32_T fv2[2];
  real32_T IIRgyroz_tmp[2];
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T x_c;
  real32_T y_n;
  real32_T z_p;
  real32_T p;                          /* '<S242>/LPF Fcutoff = 40Hz1' */
  real32_T q;                          /* '<S242>/LPF Fcutoff = 40Hz' */
  real32_T r;                          /* '<S313>/Subtract1' */
  real32_T FIR_IMUaccel[3];            /* '<S242>/FIR_IMUaccel' */
  real32_T CastToSingle[3];            /* '<S240>/Cast To Single' */
  real32_T DataTypeConversion2;        /* '<S239>/Data Type Conversion2' */
  real32_T DataTypeConversion;         /* '<S239>/Data Type Conversion' */
  real32_T angularvelocitycompensation[2];
                                    /* '<S320>/angular velocity compensation' */
  real32_T Reshapexhat_p[4];           /* '<S325>/Reshapexhat' */
  real32_T SimplyIntegrateVelocity[2]; /* '<S321>/SimplyIntegrateVelocity' */
  real32_T CastToSingle1[4];           /* '<S240>/Cast To Single1' */
  real32_T TmpSignalConversionAtToWorkspaceInport1[17];/* '<S1>/State Estimator' */
  real32_T DiscreteTimeIntegrator;     /* '<S7>/Discrete-Time Integrator' */
  real32_T SaturationThrust1;          /* '<S7>/SaturationThrust1' */
  real32_T Switch_refAtt;              /* '<S3>/Switch_refAtt' */
  real32_T Add;                        /* '<S3>/Add' */
  real32_T Product3_a;                 /* '<S3>/Product3' */
  real32_T Saturation[2];              /* '<S206>/Saturation' */
  real32_T Switch_refAtt1[2];          /* '<S3>/Switch_refAtt1' */
  real32_T Product_o;                  /* '<S3>/Product' */
  real32_T Product1;                   /* '<S3>/Product1' */
  real32_T Gain[3];                    /* '<S240>/Gain' */
  real32_T Product2_n[4];              /* '<S394>/Product2' */
  real32_T Product3_f[4];              /* '<S392>/Product3' */
  real32_T In1;                        /* '<S317>/In1' */
  real32_T y_b;                        /* '<S6>/MATLAB Function' */
  real32_T BufferToMakeInportVirtual_InsertedFor_X_at_inport_0;
              /* '<S238>/BufferToMakeInportVirtual_InsertedFor_X_at_inport_0' */
  real32_T BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0;
              /* '<S238>/BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0' */
  real32_T att;                        /* '<S3>/Chart' */
  real32_T z_c;                        /* '<S3>/Chart' */
  real32_T v;                          /* '<S3>/Chart' */
  real32_T px;                         /* '<S3>/Chart' */
  real32_T denAccum;
  real32_T denAccum_c;
  real32_T denAccum_f;
  real32_T scale_g;
  real32_T absxk_g;
  real32_T t_m;
  real32_T Saturation_h;               /* '<S12>/Saturation' */
  int32_T j;
  int32_T denIdx;
  int32_T cff;
  int32_T memOffset;
  boolean_T Compare;                   /* '<S247>/Compare' */
  boolean_T LogicalOperator3;          /* '<S324>/Logical Operator3' */
} B_FlightControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Flight Control System' */
typedef struct {
  real_T Delay_DSTATE[4];              /* '<S240>/Delay' */
  real_T Delay2_DSTATE;                /* '<S239>/Delay2' */
  real_T MemoryX_DSTATE[3];            /* '<S244>/MemoryX' */
  real_T DelayOneStep_DSTATE;          /* '<S227>/Delay One Step' */
  real_T sonarFilter_IIR_states[3];    /* '<S245>/sonarFilter_IIR' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S1>/To Workspace1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S3>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S239>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_k;                    /* '<S239>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S240>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S239>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;                    /* '<S240>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S242>/Scope1' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<S3>/Scope11' */

  struct {
    void *LoggedData;
  } Scope_PWORK_hp;                    /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S321>/Scope' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S3>/Scope6' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S3>/Scope5' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S3>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S3>/Scope10' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S3>/Scope7' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<S3>/Scope12' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_j;                    /* '<S3>/Scope3' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S3>/Scope8' */

  struct {
    void *LoggedData;
  } Scope_PWORK_bo;                    /* '<S239>/Scope' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S3>/Scope9' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S242>/Scope' */

  real32_T LPFFcutoff40Hz1_states;     /* '<S242>/LPF Fcutoff = 40Hz1' */
  real32_T LPFFcutoff40Hz_states;      /* '<S242>/LPF Fcutoff = 40Hz' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S242>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S242>/FIR_IMUaccel' */
  real32_T Delay1_DSTATE[2];           /* '<S6>/Delay1' */
  real32_T MemoryX_DSTATE_l[4];        /* '<S325>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S324>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S332>/UD' */
  real32_T Delay_DSTATE_o[2];          /* '<S320>/Delay' */
  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S321>/SimplyIntegrateVelocity' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_j;/* '<S12>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE[2];       /* '<S199>/Integrator' */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[2];
  /* '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  real32_T Integrator_DSTATE_a[2];     /* '<S97>/Integrator' */
  real32_T Filter_DSTATE[2];           /* '<S92>/Filter' */
  real32_T pressureFilter_IIR_states[3];/* '<S245>/pressureFilter_IIR' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S242>/FIR_IMUaccel' */
  uint32_T Output_DSTATE;              /* '<S316>/Output' */
  uint32_T Output_DSTATE_a;            /* '<S396>/Output' */
  uint32_T Output_DSTATE_a3;           /* '<S223>/Output' */
  uint32_T is_c6_flightControlSystem;  /* '<S3>/Chart' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S321>/SimplyIntegrateVelocity' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S7>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_b;/* '<S12>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S199>/Integrator' */
  int8_T Integrator_PrevResetState_p;  /* '<S97>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S92>/Filter' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S370>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S363>/MeasurementUpdate' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S313>/Triggered Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S307>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S307>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S307>/If Action Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC_m;/* '<S273>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC_p;/* '<S267>/MeasurementUpdate' */
  int8_T TriggeredSubsystem_SubsysRanBC_a;/* '<S236>/Triggered Subsystem' */
  int8_T Normalconditionandlanding_SubsysRanBC;
                                      /* '<S4>/Normal condition  and landing' */
  uint8_T icLoad;                      /* '<S244>/MemoryX' */
  uint8_T icLoad_h;                    /* '<S325>/MemoryX' */
  uint8_T is_active_c6_flightControlSystem;/* '<S3>/Chart' */
  uint8_T temporalCounter_i1;          /* '<S3>/Chart' */
  boolean_T EnabledSubsystem_MODE;     /* '<S370>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S363>/MeasurementUpdate' */
  boolean_T EnabledSubsystem_MODE_m;   /* '<S273>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE_p;  /* '<S267>/MeasurementUpdate' */
  DW_Geofencingerror_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  DW_Geofencingerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  DW_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
  DW_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S4>/Geofencing error' */
} DW_FlightControlSystem_flightControlSystem_T;

/* Zero-crossing (trigger) state for system '<Root>/Flight Control System' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S313>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_k;/* '<S236>/Triggered Subsystem' */
} ZCE_FlightControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T rtb_PARROTImageConversion_o3_m[19200];
  uint8_T rtb_PARROTImageConversion_o2_c[19200];
  uint8_T rtb_PARROTImageConversion_o1_k[19200];
  B_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  parrot_ImageProcess_flightControlSystem_T obj;/* '<S2>/PARROT Image Conversion' */
  volatile real_T RateTransition_Buffer[2];/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
  DW_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} DW_flightControlSystem_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} PrevZCX_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<S4>/Geofencing error' */
struct P_Geofencingerror_flightControlSystem_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S224>/Constant'
                                        */
};

/* Parameters for system: '<Root>/Flight Control System' */
struct P_FlightControlSystem_flightControlSystem_T_ {
  real_T outlierBelowFloor_const;     /* Mask Parameter: outlierBelowFloor_const
                                       * Referenced by: '<S247>/Constant'
                                       */
  real_T ComparewithStoptime_const; /* Mask Parameter: ComparewithStoptime_const
                                     * Referenced by: '<S237>/Constant'
                                     */
  real_T Checkerrorcondition_const; /* Mask Parameter: Checkerrorcondition_const
                                     * Referenced by: '<S234>/Constant'
                                     */
  real_T u0continuousOFerrors_const;
                                   /* Mask Parameter: u0continuousOFerrors_const
                                    * Referenced by: '<S233>/Constant'
                                    */
  real_T currentEstimateVeryOffFromPressure_const;
                     /* Mask Parameter: currentEstimateVeryOffFromPressure_const
                      * Referenced by: '<S299>/Constant'
                      */
  real_T currentStateVeryOffsonarflt_const;
                            /* Mask Parameter: currentStateVeryOffsonarflt_const
                             * Referenced by: '<S300>/Constant'
                             */
  real_T outlierJump_const;            /* Mask Parameter: outlierJump_const
                                        * Referenced by: '<S301>/Constant'
                                        */
  real32_T Angularvelocitycontrolloop_D[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_D
                                  * Referenced by: '<S91>/Derivative Gain'
                                  */
  real32_T Angularvelocitycontrolloop_I[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_I
                                  * Referenced by: '<S94>/Integral Gain'
                                  */
  real32_T Velocitycontroller_I;       /* Mask Parameter: Velocitycontroller_I
                                        * Referenced by: '<S196>/Integral Gain'
                                        */
  real32_T DiscreteDerivative_ICPrevScaledInput;
                         /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                          * Referenced by: '<S332>/UD'
                          */
  real32_T Angularvelocitycontrolloop_InitialConditionForFilter;
         /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForFilter
          * Referenced by: '<S92>/Filter'
          */
  real32_T Velocitycontroller_InitialConditionForIntegrator;
             /* Mask Parameter: Velocitycontroller_InitialConditionForIntegrator
              * Referenced by: '<S199>/Integrator'
              */
  real32_T Angularvelocitycontrolloop_InitialConditionForIntegrator;
     /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForIntegrator
      * Referenced by: '<S97>/Integrator'
      */
  real32_T Positioncontroller_LowerSaturationLimit;
                      /* Mask Parameter: Positioncontroller_LowerSaturationLimit
                       * Referenced by: '<S156>/Saturation'
                       */
  real32_T Velocitycontroller_LowerSaturationLimit;
                      /* Mask Parameter: Velocitycontroller_LowerSaturationLimit
                       * Referenced by:
                       *   '<S206>/Saturation'
                       *   '<S192>/DeadZone'
                       */
  real32_T Angularvelocitycontrolloop_LowerSaturationLimit;
              /* Mask Parameter: Angularvelocitycontrolloop_LowerSaturationLimit
               * Referenced by:
               *   '<S104>/Saturation'
               *   '<S90>/DeadZone'
               */
  real32_T Angularvelocitycontrolloop_N[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_N
                                  * Referenced by: '<S100>/Filter Coefficient'
                                  */
  real32_T Positioncontroller_P;       /* Mask Parameter: Positioncontroller_P
                                        * Referenced by: '<S154>/Proportional Gain'
                                        */
  real32_T Velocitycontroller_P;       /* Mask Parameter: Velocitycontroller_P
                                        * Referenced by: '<S204>/Proportional Gain'
                                        */
  real32_T Anglecontrolloop_P;         /* Mask Parameter: Anglecontrolloop_P
                                        * Referenced by: '<S52>/Proportional Gain'
                                        */
  real32_T Angularvelocitycontrolloop_P[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_P
                                  * Referenced by: '<S102>/Proportional Gain'
                                  */
  real32_T Positioncontroller_UpperSaturationLimit;
                      /* Mask Parameter: Positioncontroller_UpperSaturationLimit
                       * Referenced by: '<S156>/Saturation'
                       */
  real32_T Velocitycontroller_UpperSaturationLimit;
                      /* Mask Parameter: Velocitycontroller_UpperSaturationLimit
                       * Referenced by:
                       *   '<S206>/Saturation'
                       *   '<S192>/DeadZone'
                       */
  real32_T Angularvelocitycontrolloop_UpperSaturationLimit;
              /* Mask Parameter: Angularvelocitycontrolloop_UpperSaturationLimit
               * Referenced by:
               *   '<S104>/Saturation'
               *   '<S90>/DeadZone'
               */
  real32_T Checkifthedroneis03maboveground_const;
                        /* Mask Parameter: Checkifthedroneis03maboveground_const
                         * Referenced by: '<S232>/Constant'
                         */
  real32_T maxp_const;                 /* Mask Parameter: maxp_const
                                        * Referenced by: '<S335>/Constant'
                                        */
  real32_T maxq_const;                 /* Mask Parameter: maxq_const
                                        * Referenced by: '<S337>/Constant'
                                        */
  real32_T maxw1_const;                /* Mask Parameter: maxw1_const
                                        * Referenced by: '<S339>/Constant'
                                        */
  real32_T maxw2_const;                /* Mask Parameter: maxw2_const
                                        * Referenced by: '<S340>/Constant'
                                        */
  real32_T maxdw1_const;               /* Mask Parameter: maxdw1_const
                                        * Referenced by: '<S333>/Constant'
                                        */
  real32_T maxdw2_const;               /* Mask Parameter: maxdw2_const
                                        * Referenced by: '<S334>/Constant'
                                        */
  real32_T maxp2_const;                /* Mask Parameter: maxp2_const
                                        * Referenced by: '<S336>/Constant'
                                        */
  real32_T maxq2_const;                /* Mask Parameter: maxq2_const
                                        * Referenced by: '<S338>/Constant'
                                        */
  real32_T maxw3_const;                /* Mask Parameter: maxw3_const
                                        * Referenced by: '<S341>/Constant'
                                        */
  real32_T maxw4_const;                /* Mask Parameter: maxw4_const
                                        * Referenced by: '<S342>/Constant'
                                        */
  real32_T minHeightforOF_const;       /* Mask Parameter: minHeightforOF_const
                                        * Referenced by: '<S343>/Constant'
                                        */
  real32_T DeactivateAccelerationIfOFisnotusedduetolowaltitude_const;
    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S327>/Constant'
     */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
   * Referenced by: '<S329>/Constant'
   */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
   * Referenced by: '<S330>/Constant'
   */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S217>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S218>/Constant'
                                      */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S219>/Constant'
                                      */
  real32_T CompareToConstant4_const; /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S221>/Constant'
                                      */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S220>/Constant'
                                      */
  real32_T CompareToConstant5_const; /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S222>/Constant'
                                      */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S231>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_m;     /* Mask Parameter: WrapToZero_Threshold_m
                                        * Referenced by: '<S398>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_i;     /* Mask Parameter: WrapToZero_Threshold_i
                                        * Referenced by: '<S319>/FixPt Switch'
                                        */
  uint32_T CompareToConstant_const_f;
                                    /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S315>/Constant'
                                     */
  uint32_T CompareToConstant_const_l;
                                    /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S395>/Constant'
                                     */
  real_T DisableOFcheck_Value;         /* Expression: 0
                                        * Referenced by: '<S227>/ Disable OF check'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S227>/ '
                                        */
  real_T xValue_Value;                 /* Expression: 0
                                        * Referenced by: '<S5>/xValue'
                                        */
  real_T yValue_Value;                 /* Expression: 0
                                        * Referenced by: '<S5>/yValue'
                                        */
  real_T zValue_Value;                 /* Expression: -1
                                        * Referenced by: '<S5>/zValue'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S295>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S297>/deltax'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S308>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S309>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S313>/Constant'
                                        */
  real_T Delay_InitialCondition[4];    /* Expression: [1 0 0 0]'
                                        * Referenced by: '<S240>/Delay'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S239>/Delay2'
                                        */
  real_T X0_Value[3];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S244>/X0'
                                        */
  real_T KalmanGainM_Value[3];         /* Expression: pInitialization.M
                                        * Referenced by: '<S248>/KalmanGainM'
                                        */
  real_T C_Value[3];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S244>/C'
                                        */
  real_T KalmanGainM_Value_l[8];       /* Expression: pInitialization.M
                                        * Referenced by: '<S344>/KalmanGainM'
                                        */
  real_T A_Value[9];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S244>/A'
                                        */
  real_T KalmanGainL_Value[8];         /* Expression: pInitialization.L
                                        * Referenced by: '<S344>/KalmanGainL'
                                        */
  real_T gravity_Value[3];             /* Expression: [0 0 -g]
                                        * Referenced by: '<S322>/gravity'
                                        */
  real_T gainaccinput1_Gain;           /* Expression: 1
                                        * Referenced by: '<S322>/gainaccinput1'
                                        */
  real_T gravity_Value_i[3];           /* Expression: [0 0 g]
                                        * Referenced by: '<S239>/gravity'
                                        */
  real_T B_Value[3];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S244>/B'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S244>/D'
                                        */
  real_T KalmanGainL_Value_b[3];       /* Expression: pInitialization.L
                                        * Referenced by: '<S248>/KalmanGainL'
                                        */
  real_T Wait3Seconds_Value;           /* Expression: 200*3
                                        * Referenced by: '<S4>/Wait  3 Seconds'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S227>/Delay One Step'
                                        */
  real_T u5meters_Value;               /* Expression: 0.5
                                        * Referenced by: '<S216>/0.5 meters'
                                        */
  real_T sonarFilter_IIR_NumCoef[4]; /* Expression: Estimator.alt.filterSonarNum
                                      * Referenced by: '<S245>/sonarFilter_IIR'
                                      */
  real_T sonarFilter_IIR_DenCoef[4]; /* Expression: Estimator.alt.filterSonarDen
                                      * Referenced by: '<S245>/sonarFilter_IIR'
                                      */
  real_T sonarFilter_IIR_InitialStates;/* Expression: 0
                                        * Referenced by: '<S245>/sonarFilter_IIR'
                                        */
  real_T SaturationSonar_LowerSat;     /* Expression: -inf
                                        * Referenced by: '<S245>/SaturationSonar'
                                        */
  real_T CovarianceZ_Value[16];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S344>/CovarianceZ'
                                        */
  real_T CovarianceZ_Value_c[9];       /* Expression: pInitialization.Z
                                        * Referenced by: '<S248>/CovarianceZ'
                                        */
  real_T P0_Value[9];                  /* Expression: pInitialization.P0
                                        * Referenced by: '<S244>/P0'
                                        */
  real_T G_Value[9];                   /* Expression: pInitialization.G
                                        * Referenced by: '<S244>/G'
                                        */
  real_T Q_Value[9];                   /* Expression: pInitialization.Q
                                        * Referenced by: '<S244>/Q'
                                        */
  real_T H_Value[3];                   /* Expression: pInitialization.H
                                        * Referenced by: '<S244>/H'
                                        */
  real_T N_Value[3];                   /* Expression: pInitialization.N
                                        * Referenced by: '<S244>/N'
                                        */
  real_T R_Value;                      /* Expression: pInitialization.R
                                        * Referenced by: '<S244>/R'
                                        */
  real32_T Pitchcorrection_Value;   /* Computed Parameter: Pitchcorrection_Value
                                     * Referenced by: '<S10>/Pitch correction'
                                     */
  real32_T zerocorrection_Value;     /* Computed Parameter: zerocorrection_Value
                                      * Referenced by: '<S10>/zero correction'
                                      */
  real32_T Gain_Gain[2];               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real32_T _Value_p;                   /* Computed Parameter: _Value_p
                                        * Referenced by: '<S216>/    '
                                        */
  real32_T X_Y0;                       /* Computed Parameter: X_Y0
                                        * Referenced by: '<S238>/X'
                                        */
  real32_T Y_Y0;                       /* Computed Parameter: Y_Y0
                                        * Referenced by: '<S238>/Y'
                                        */
  real32_T Landinglookaheaddistance_Value;
                           /* Computed Parameter: Landinglookaheaddistance_Value
                            * Referenced by: '<S236>/Landing look-ahead distance'
                            */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S313>/Gain'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S317>/Out1'
                                        */
  real32_T Lykyhatkk1_Y0_b;            /* Computed Parameter: Lykyhatkk1_Y0_b
                                        * Referenced by: '<S392>/L*(y[k]-yhat[k|k-1])'
                                        */
  real32_T deltax_Y0_h;                /* Computed Parameter: deltax_Y0_h
                                        * Referenced by: '<S394>/deltax'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S326>/Gain'
                                        */
  real32_T opticalFlowErrorCorrect_Gain;
                             /* Computed Parameter: opticalFlowErrorCorrect_Gain
                              * Referenced by: '<S326>/opticalFlowErrorCorrect'
                              */
  real32_T Constant_Value_e[3];        /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S242>/Constant'
                                        */
  real32_T Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[6];
  /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
   * Referenced by: '<S242>/Assuming that the  preflight calibration was done at level orientation'
   */
  real32_T inverseIMU_gain_Gain[6];  /* Computed Parameter: inverseIMU_gain_Gain
                                      * Referenced by: '<S242>/inverseIMU_gain'
                                      */
  real32_T LPFFcutoff40Hz1_NumCoef[2];
                                  /* Computed Parameter: LPFFcutoff40Hz1_NumCoef
                                   * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
                                   */
  real32_T LPFFcutoff40Hz1_DenCoef[2];
                                  /* Computed Parameter: LPFFcutoff40Hz1_DenCoef
                                   * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
                                   */
  real32_T LPFFcutoff40Hz1_InitialStates;
                            /* Computed Parameter: LPFFcutoff40Hz1_InitialStates
                             * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
                             */
  real32_T LPFFcutoff40Hz_NumCoef[2];
                                   /* Computed Parameter: LPFFcutoff40Hz_NumCoef
                                    * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
                                    */
  real32_T LPFFcutoff40Hz_DenCoef[2];
                                   /* Computed Parameter: LPFFcutoff40Hz_DenCoef
                                    * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
                                    */
  real32_T LPFFcutoff40Hz_InitialStates;
                             /* Computed Parameter: LPFFcutoff40Hz_InitialStates
                              * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
                              */
  real32_T IIR_IMUgyro_r_NumCoef[6];/* Computed Parameter: IIR_IMUgyro_r_NumCoef
                                     * Referenced by: '<S242>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_DenCoef[6];/* Computed Parameter: IIR_IMUgyro_r_DenCoef
                                     * Referenced by: '<S242>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_InitialStates;
                              /* Computed Parameter: IIR_IMUgyro_r_InitialStates
                               * Referenced by: '<S242>/IIR_IMUgyro_r'
                               */
  real32_T FIR_IMUaccel_InitialStates;
                               /* Computed Parameter: FIR_IMUaccel_InitialStates
                                * Referenced by: '<S242>/FIR_IMUaccel'
                                */
  real32_T FIR_IMUaccel_Coefficients[6];
                                /* Computed Parameter: FIR_IMUaccel_Coefficients
                                 * Referenced by: '<S242>/FIR_IMUaccel'
                                 */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S6>/Delay1'
                                   */
  real32_T prsToAltGain_Gain;          /* Computed Parameter: prsToAltGain_Gain
                                        * Referenced by: '<S239>/prsToAltGain'
                                        */
  real32_T X0_Value_b[4];              /* Computed Parameter: X0_Value_b
                                        * Referenced by: '<S325>/X0'
                                        */
  real32_T C_Value_n[8];               /* Computed Parameter: C_Value_n
                                        * Referenced by: '<S325>/C'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S323>/Gain1'
                                        */
  real32_T IIRgyroz_NumCoef[6];        /* Computed Parameter: IIRgyroz_NumCoef
                                        * Referenced by: '<S324>/IIRgyroz'
                                        */
  real32_T IIRgyroz_DenCoef[6];        /* Computed Parameter: IIRgyroz_DenCoef
                                        * Referenced by: '<S324>/IIRgyroz'
                                        */
  real32_T IIRgyroz_InitialStates; /* Computed Parameter: IIRgyroz_InitialStates
                                    * Referenced by: '<S324>/IIRgyroz'
                                    */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S332>/TSamp'
                                        */
  real32_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S320>/Delay'
                                  */
  real32_T SimplyIntegrateVelocity_gainval;
                          /* Computed Parameter: SimplyIntegrateVelocity_gainval
                           * Referenced by: '<S321>/SimplyIntegrateVelocity'
                           */
  real32_T SimplyIntegrateVelocity_IC;
                               /* Computed Parameter: SimplyIntegrateVelocity_IC
                                * Referenced by: '<S321>/SimplyIntegrateVelocity'
                                */
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];/* Expression: Controller.Q2Ts
                                                        * Referenced by: '<S10>/TorqueTotalThrustToThrustPerMotor'
                                                        */
  real32_T A_Value_i[16];              /* Computed Parameter: A_Value_i
                                        * Referenced by: '<S325>/A'
                                        */
  real32_T B_Value_o[8];               /* Computed Parameter: B_Value_o
                                        * Referenced by: '<S325>/B'
                                        */
  real32_T D_Value_o[4];               /* Computed Parameter: D_Value_o
                                        * Referenced by: '<S325>/D'
                                        */
  real32_T w1_Value;                   /* Computed Parameter: w1_Value
                                        * Referenced by: '<S7>/w1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S7>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T P_z1_Gain;                  /* Computed Parameter: P_z1_Gain
                                        * Referenced by: '<S7>/P_z1'
                                        */
  real32_T D_z1_Gain;                  /* Computed Parameter: D_z1_Gain
                                        * Referenced by: '<S7>/D_z1'
                                        */
  real32_T SaturationThrust1_UpperSat;
                               /* Computed Parameter: SaturationThrust1_UpperSat
                                * Referenced by: '<S7>/SaturationThrust1'
                                */
  real32_T SaturationThrust1_LowerSat;
                               /* Computed Parameter: SaturationThrust1_LowerSat
                                * Referenced by: '<S7>/SaturationThrust1'
                                */
  real32_T Switch_refAtt_Threshold;
                                  /* Computed Parameter: Switch_refAtt_Threshold
                                   * Referenced by: '<S3>/Switch_refAtt'
                                   */
  real32_T Constant_Value_ew;          /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S12>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S12>/Saturation'
                                       */
  real32_T P_yaw_Gain;                 /* Computed Parameter: P_yaw_Gain
                                        * Referenced by: '<S12>/P_yaw'
                                        */
  real32_T DiscreteTimeIntegrator_gainval_n;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                          * Referenced by: '<S12>/Discrete-Time Integrator'
                          */
  real32_T DiscreteTimeIntegrator_IC_j;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_j
                               * Referenced by: '<S12>/Discrete-Time Integrator'
                               */
  real32_T D_yaw_Gain;                 /* Computed Parameter: D_yaw_Gain
                                        * Referenced by: '<S12>/D_yaw'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S199>/Integrator'
                                        */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[2];
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
   * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[2];
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
   * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a;
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a
   * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T Switch_refAtt1_Threshold;
                                 /* Computed Parameter: Switch_refAtt1_Threshold
                                  * Referenced by: '<S3>/Switch_refAtt1'
                                  */
  real32_T Integrator_gainval_d;     /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S97>/Integrator'
                                      */
  real32_T Filter_gainval;             /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S92>/Filter'
                                        */
  real32_T ThrustToMotorCommand_Gain;
                                /* Computed Parameter: ThrustToMotorCommand_Gain
                                 * Referenced by: '<S13>/ThrustToMotorCommand'
                                 */
  real32_T Saturation5_UpperSat;       /* Expression: Vehicle.Motor.maxLimit
                                        * Referenced by: '<S13>/Saturation5'
                                        */
  real32_T Saturation5_LowerSat;       /* Expression: Vehicle.Motor.minLimit
                                        * Referenced by: '<S13>/Saturation5'
                                        */
  real32_T MotorDirections_Gain[4];  /* Computed Parameter: MotorDirections_Gain
                                      * Referenced by: '<S13>/MotorDirections'
                                      */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S240>/Gain'
                                        */
  real32_T ZeroGain_Gain;              /* Computed Parameter: ZeroGain_Gain
                                        * Referenced by: '<S88>/ZeroGain'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real32_T ZeroGain_Gain_g;            /* Computed Parameter: ZeroGain_Gain_g
                                        * Referenced by: '<S190>/ZeroGain'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S190>/Constant1'
                                        */
  real32_T I_yaw_Gain;                 /* Computed Parameter: I_yaw_Gain
                                        * Referenced by: '<S12>/I_yaw'
                                        */
  real32_T I_pr_Gain;                  /* Computed Parameter: I_pr_Gain
                                        * Referenced by: '<S7>/I_pr'
                                        */
  real32_T pressureFilter_IIR_NumCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_NumCoef
                                * Referenced by: '<S245>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_DenCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_DenCoef
                                * Referenced by: '<S245>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_InitialStates;
                         /* Computed Parameter: pressureFilter_IIR_InitialStates
                          * Referenced by: '<S245>/pressureFilter_IIR'
                          */
  real32_T Gain_Gain_ip;               /* Computed Parameter: Gain_Gain_ip
                                        * Referenced by: '<S4>/Gain'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real32_T invertzaxisGain_Gain;     /* Computed Parameter: invertzaxisGain_Gain
                                      * Referenced by: '<S239>/invertzaxisGain'
                                      */
  real32_T P0_Value_j[16];             /* Computed Parameter: P0_Value_j
                                        * Referenced by: '<S325>/P0'
                                        */
  real32_T G_Value_a[16];              /* Computed Parameter: G_Value_a
                                        * Referenced by: '<S325>/G'
                                        */
  real32_T Q_Value_i[16];              /* Computed Parameter: Q_Value_i
                                        * Referenced by: '<S325>/Q'
                                        */
  real32_T H_Value_k[8];               /* Computed Parameter: H_Value_k
                                        * Referenced by: '<S325>/H'
                                        */
  real32_T N_Value_d[8];               /* Computed Parameter: N_Value_d
                                        * Referenced by: '<S325>/N'
                                        */
  real32_T R_Value_d[4];               /* Computed Parameter: R_Value_d
                                        * Referenced by: '<S325>/R'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S240>/Constant'
                                        */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S316>/Output'
                                   */
  uint32_T Output_InitialCondition_b;
                                /* Computed Parameter: Output_InitialCondition_b
                                 * Referenced by: '<S396>/Output'
                                 */
  uint32_T Output_InitialCondition_c;
                                /* Computed Parameter: Output_InitialCondition_c
                                 * Referenced by: '<S223>/Output'
                                 */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S230>/FixPt Constant'
                                       */
  uint32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S231>/Constant'
                                        */
  uint32_T FixPtConstant_Value_d;   /* Computed Parameter: FixPtConstant_Value_d
                                     * Referenced by: '<S397>/FixPt Constant'
                                     */
  uint32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S398>/Constant'
                                        */
  uint32_T FixPtConstant_Value_k;   /* Computed Parameter: FixPtConstant_Value_k
                                     * Referenced by: '<S318>/FixPt Constant'
                                     */
  uint32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S319>/Constant'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S244>/Enable'
                                        */
  boolean_T controlModePosVsOrient_Value;
                             /* Computed Parameter: controlModePosVsOrient_Value
                              * Referenced by: '<S1>/controlModePosVsOrient'
                              */
  boolean_T SwitchControl_Value;       /* Expression: switch_mode
                                        * Referenced by: '<S114>/Switch Control'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S10>/Manual Switch'
                               */
  uint8_T Landed_Value;                /* Computed Parameter: Landed_Value
                                        * Referenced by: '<S226>/Landed'
                                        */
  uint8_T No_error_Value;              /* Computed Parameter: No_error_Value
                                        * Referenced by: '<S226>/No_error'
                                        */
  uint8_T Disabletemperaturecompensation_CurrentSetting;
            /* Computed Parameter: Disabletemperaturecompensation_CurrentSetting
             * Referenced by: '<S313>/Disable temperature compensation'
             */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S4>/Merge'
                                       */
  P_Geofencingerror_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  P_Geofencingerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  P_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
  P_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S4>/Geofencing error' */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  struct_8SSZ93PxvPkADZcA4gG8MD Sensors;/* Variable: Sensors
                                         * Referenced by:
                                         *   '<S245>/SaturationSonar'
                                         *   '<S298>/Constant'
                                         */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition'
                                          */
  P_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flightControlSystem_T flightControlSystem_P;

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_flightControlSystem_T flightControlSystem_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S13>/MotorDirections' */
extern uint8_T flag_outport;           /* '<S4>/Merge' */

/* External function called from main */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step0(void);
extern void flightControlSystem_step1(void);
extern void flightControlSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControlSystem_T *const flightControlSystem_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Flight Control System'
 * '<S2>'   : 'flightControlSystem/Image Processing System'
 * '<S3>'   : 'flightControlSystem/Flight Control System/Controller'
 * '<S4>'   : 'flightControlSystem/Flight Control System/Crash Prediction Flags'
 * '<S5>'   : 'flightControlSystem/Flight Control System/Path Planning'
 * '<S6>'   : 'flightControlSystem/Flight Control System/State Estimator'
 * '<S7>'   : 'flightControlSystem/Flight Control System/Controller/Altitude Controller'
 * '<S8>'   : 'flightControlSystem/Flight Control System/Controller/Attitude Controller'
 * '<S9>'   : 'flightControlSystem/Flight Control System/Controller/Chart'
 * '<S10>'  : 'flightControlSystem/Flight Control System/Controller/ControlMixer'
 * '<S11>'  : 'flightControlSystem/Flight Control System/Controller/Position Controller'
 * '<S12>'  : 'flightControlSystem/Flight Control System/Controller/Yaw Controller'
 * '<S13>'  : 'flightControlSystem/Flight Control System/Controller/thrustsToMotorCommands'
 * '<S14>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop'
 * '<S15>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop'
 * '<S16>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Anti-windup'
 * '<S17>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/D Gain'
 * '<S18>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Filter'
 * '<S19>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Filter ICs'
 * '<S20>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/I Gain'
 * '<S21>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain'
 * '<S22>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain Fdbk'
 * '<S23>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Integrator'
 * '<S24>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Integrator ICs'
 * '<S25>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/N Copy'
 * '<S26>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/N Gain'
 * '<S27>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/P Copy'
 * '<S28>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Parallel P Gain'
 * '<S29>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Reset Signal'
 * '<S30>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Saturation'
 * '<S31>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Saturation Fdbk'
 * '<S32>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Sum'
 * '<S33>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Sum Fdbk'
 * '<S34>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode'
 * '<S35>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode Sum'
 * '<S36>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Integral'
 * '<S37>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Ngain'
 * '<S38>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/postSat Signal'
 * '<S39>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/preSat Signal'
 * '<S40>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Anti-windup/Disabled'
 * '<S41>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/D Gain/Disabled'
 * '<S42>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Filter/Disabled'
 * '<S43>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Filter ICs/Disabled'
 * '<S44>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/I Gain/Disabled'
 * '<S45>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain/Passthrough'
 * '<S46>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Integrator/Disabled'
 * '<S48>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Integrator ICs/Disabled'
 * '<S49>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/N Gain/Disabled'
 * '<S51>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/P Copy/Disabled'
 * '<S52>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Reset Signal/Disabled'
 * '<S54>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Saturation/Passthrough'
 * '<S55>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Saturation Fdbk/Disabled'
 * '<S56>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Sum/Passthrough_P'
 * '<S57>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Sum Fdbk/Disabled'
 * '<S58>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode/Disabled'
 * '<S59>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Integral/Disabled wSignal Specification'
 * '<S61>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/postSat Signal/Forward_Path'
 * '<S63>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angle control loop/preSat Signal/Forward_Path'
 * '<S64>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup'
 * '<S65>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/D Gain'
 * '<S66>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Filter'
 * '<S67>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Filter ICs'
 * '<S68>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/I Gain'
 * '<S69>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain'
 * '<S70>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain Fdbk'
 * '<S71>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator'
 * '<S72>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator ICs'
 * '<S73>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/N Copy'
 * '<S74>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/N Gain'
 * '<S75>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/P Copy'
 * '<S76>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Parallel P Gain'
 * '<S77>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Reset Signal'
 * '<S78>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation'
 * '<S79>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation Fdbk'
 * '<S80>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Sum'
 * '<S81>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Sum Fdbk'
 * '<S82>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode'
 * '<S83>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode Sum'
 * '<S84>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Integral'
 * '<S85>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Ngain'
 * '<S86>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/postSat Signal'
 * '<S87>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/preSat Signal'
 * '<S88>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel'
 * '<S89>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S90>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S91>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/D Gain/Internal Parameters'
 * '<S92>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Filter/Disc. Forward Euler Filter'
 * '<S93>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Filter ICs/Internal IC - Filter'
 * '<S94>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/I Gain/Internal Parameters'
 * '<S95>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain/Passthrough'
 * '<S96>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain Fdbk/Disabled'
 * '<S97>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator/Discrete'
 * '<S98>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator ICs/Internal IC'
 * '<S99>'  : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/N Copy/Disabled'
 * '<S100>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/N Gain/Internal Parameters'
 * '<S101>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/P Copy/Disabled'
 * '<S102>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Parallel P Gain/Internal Parameters'
 * '<S103>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Reset Signal/External Reset'
 * '<S104>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation/Enabled'
 * '<S105>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation Fdbk/Disabled'
 * '<S106>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Sum/Sum_PID'
 * '<S107>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Sum Fdbk/Disabled'
 * '<S108>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode/Disabled'
 * '<S109>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode Sum/Passthrough'
 * '<S110>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Integral/Passthrough'
 * '<S111>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Ngain/Passthrough'
 * '<S112>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/postSat Signal/Forward_Path'
 * '<S113>' : 'flightControlSystem/Flight Control System/Controller/Attitude Controller/Angular velocity control loop/preSat Signal/Forward_Path'
 * '<S114>' : 'flightControlSystem/Flight Control System/Controller/ControlMixer/Environment Controller'
 * '<S115>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller'
 * '<S116>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position error transformation (Earth to Body frame)'
 * '<S117>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller'
 * '<S118>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Anti-windup'
 * '<S119>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/D Gain'
 * '<S120>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Filter'
 * '<S121>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Filter ICs'
 * '<S122>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/I Gain'
 * '<S123>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Ideal P Gain'
 * '<S124>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Ideal P Gain Fdbk'
 * '<S125>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Integrator'
 * '<S126>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Integrator ICs'
 * '<S127>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/N Copy'
 * '<S128>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/N Gain'
 * '<S129>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/P Copy'
 * '<S130>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Parallel P Gain'
 * '<S131>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Reset Signal'
 * '<S132>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Saturation'
 * '<S133>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Saturation Fdbk'
 * '<S134>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Sum'
 * '<S135>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Sum Fdbk'
 * '<S136>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tracking Mode'
 * '<S137>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tracking Mode Sum'
 * '<S138>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tsamp - Integral'
 * '<S139>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tsamp - Ngain'
 * '<S140>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/postSat Signal'
 * '<S141>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/preSat Signal'
 * '<S142>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Anti-windup/Disabled'
 * '<S143>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/D Gain/Disabled'
 * '<S144>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Filter/Disabled'
 * '<S145>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Filter ICs/Disabled'
 * '<S146>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/I Gain/Disabled'
 * '<S147>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Ideal P Gain/Passthrough'
 * '<S148>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Ideal P Gain Fdbk/Disabled'
 * '<S149>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Integrator/Disabled'
 * '<S150>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Integrator ICs/Disabled'
 * '<S151>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/N Copy/Disabled wSignal Specification'
 * '<S152>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/N Gain/Disabled'
 * '<S153>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/P Copy/Disabled'
 * '<S154>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Parallel P Gain/Internal Parameters'
 * '<S155>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Reset Signal/Disabled'
 * '<S156>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Saturation/Enabled'
 * '<S157>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Saturation Fdbk/Disabled'
 * '<S158>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Sum/Passthrough_P'
 * '<S159>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Sum Fdbk/Disabled'
 * '<S160>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tracking Mode/Disabled'
 * '<S161>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tracking Mode Sum/Passthrough'
 * '<S162>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S163>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/Tsamp - Ngain/Passthrough'
 * '<S164>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/postSat Signal/Forward_Path'
 * '<S165>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Position controller/preSat Signal/Forward_Path'
 * '<S166>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Anti-windup'
 * '<S167>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/D Gain'
 * '<S168>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Filter'
 * '<S169>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Filter ICs'
 * '<S170>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/I Gain'
 * '<S171>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Ideal P Gain'
 * '<S172>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Ideal P Gain Fdbk'
 * '<S173>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Integrator'
 * '<S174>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Integrator ICs'
 * '<S175>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/N Copy'
 * '<S176>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/N Gain'
 * '<S177>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/P Copy'
 * '<S178>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Parallel P Gain'
 * '<S179>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Reset Signal'
 * '<S180>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Saturation'
 * '<S181>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Saturation Fdbk'
 * '<S182>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Sum'
 * '<S183>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Sum Fdbk'
 * '<S184>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tracking Mode'
 * '<S185>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tracking Mode Sum'
 * '<S186>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tsamp - Integral'
 * '<S187>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tsamp - Ngain'
 * '<S188>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/postSat Signal'
 * '<S189>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/preSat Signal'
 * '<S190>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel'
 * '<S191>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S192>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S193>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/D Gain/Disabled'
 * '<S194>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Filter/Disabled'
 * '<S195>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Filter ICs/Disabled'
 * '<S196>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/I Gain/Internal Parameters'
 * '<S197>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Ideal P Gain/Passthrough'
 * '<S198>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Ideal P Gain Fdbk/Disabled'
 * '<S199>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Integrator/Discrete'
 * '<S200>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Integrator ICs/Internal IC'
 * '<S201>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/N Copy/Disabled wSignal Specification'
 * '<S202>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/N Gain/Disabled'
 * '<S203>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/P Copy/Disabled'
 * '<S204>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Parallel P Gain/Internal Parameters'
 * '<S205>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Reset Signal/External Reset'
 * '<S206>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Saturation/Enabled'
 * '<S207>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Saturation Fdbk/Disabled'
 * '<S208>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Sum/Sum_PI'
 * '<S209>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Sum Fdbk/Disabled'
 * '<S210>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tracking Mode/Disabled'
 * '<S211>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tracking Mode Sum/Passthrough'
 * '<S212>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tsamp - Integral/Passthrough'
 * '<S213>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/Tsamp - Ngain/Passthrough'
 * '<S214>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/postSat Signal/Forward_Path'
 * '<S215>' : 'flightControlSystem/Flight Control System/Controller/Position Controller/Velocity controller/preSat Signal/Forward_Path'
 * '<S216>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Altitude error check'
 * '<S217>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant'
 * '<S218>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant1'
 * '<S219>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant2'
 * '<S220>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant3'
 * '<S221>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant4'
 * '<S222>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Compare To Constant5'
 * '<S223>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Counter Free-Running'
 * '<S224>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Geofencing error'
 * '<S225>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/No optical flow '
 * '<S226>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Normal condition  and landing'
 * '<S227>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Optical flow error check'
 * '<S228>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Ultrasound improper'
 * '<S229>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/estimator//Optical flow error'
 * '<S230>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Counter Free-Running/Increment Real World'
 * '<S231>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Counter Free-Running/Wrap To Zero'
 * '<S232>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Normal condition  and landing/Check if the drone  is 0.3m above ground'
 * '<S233>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Optical flow error check/50 continuous  OF errors '
 * '<S234>' : 'flightControlSystem/Flight Control System/Crash Prediction Flags/Optical flow error check/Check error condition'
 * '<S235>' : 'flightControlSystem/Flight Control System/Path Planning/Landing Enable'
 * '<S236>' : 'flightControlSystem/Flight Control System/Path Planning/Landing Logic'
 * '<S237>' : 'flightControlSystem/Flight Control System/Path Planning/Landing Enable/Compare with  Stop time'
 * '<S238>' : 'flightControlSystem/Flight Control System/Path Planning/Landing Logic/Triggered Subsystem'
 * '<S239>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator'
 * '<S240>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator'
 * '<S241>' : 'flightControlSystem/Flight Control System/State Estimator/MATLAB Function'
 * '<S242>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing'
 * '<S243>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator'
 * '<S244>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1'
 * '<S245>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/OutlierHandling'
 * '<S246>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/Rotation Angles to Direction Cosine Matrix'
 * '<S247>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/outlierBelowFloor'
 * '<S248>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL'
 * '<S249>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculateYhat'
 * '<S250>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CovarianceOutputConfigurator'
 * '<S251>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionA'
 * '<S252>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionB'
 * '<S253>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionC'
 * '<S254>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionD'
 * '<S255>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionEnable'
 * '<S256>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionG'
 * '<S257>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionH'
 * '<S258>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionN'
 * '<S259>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionP'
 * '<S260>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionP0'
 * '<S261>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionQ'
 * '<S262>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionR'
 * '<S263>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionX'
 * '<S264>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionX0'
 * '<S265>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/DataTypeConversionu'
 * '<S266>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/MemoryP'
 * '<S267>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/Observer'
 * '<S268>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/ReducedQRN'
 * '<S269>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/Reshapeyhat'
 * '<S270>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/ScalarExpansionP0'
 * '<S271>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/ScalarExpansionQ'
 * '<S272>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/ScalarExpansionR'
 * '<S273>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/UseCurrentEstimator'
 * '<S274>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkA'
 * '<S275>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkB'
 * '<S276>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkC'
 * '<S277>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkD'
 * '<S278>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkEnable'
 * '<S279>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkG'
 * '<S280>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkH'
 * '<S281>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkN'
 * '<S282>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkP0'
 * '<S283>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkQ'
 * '<S284>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkR'
 * '<S285>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkReset'
 * '<S286>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checkX0'
 * '<S287>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checku'
 * '<S288>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/checky'
 * '<S289>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL/DataTypeConversionL'
 * '<S290>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL/DataTypeConversionM'
 * '<S291>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL/DataTypeConversionP'
 * '<S292>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL/DataTypeConversionZ'
 * '<S293>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculatePL/Ground'
 * '<S294>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/CalculateYhat/Ground'
 * '<S295>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/Observer/MeasurementUpdate'
 * '<S296>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/ReducedQRN/Ground'
 * '<S297>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude1/UseCurrentEstimator/Enabled Subsystem'
 * '<S298>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/OutlierHandling/check for min altitude'
 * '<S299>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/OutlierHandling/currentEstimateVeryOffFromPressure'
 * '<S300>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/OutlierHandling/currentStateVeryOffsonarflt'
 * '<S301>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/OutlierHandling/outlierJump'
 * '<S302>' : 'flightControlSystem/Flight Control System/State Estimator/Altitude Estimator/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S303>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/MATLAB Function1'
 * '<S304>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles'
 * '<S305>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Angle Calculation'
 * '<S306>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Quaternion Normalize'
 * '<S307>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
 * '<S308>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
 * '<S309>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
 * '<S310>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
 * '<S311>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S312>' : 'flightControlSystem/Flight Control System/State Estimator/Attitude Estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S313>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation'
 * '<S314>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/sensordata_group'
 * '<S315>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Compare To Constant'
 * '<S316>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running'
 * '<S317>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Triggered Subsystem'
 * '<S318>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running/Increment Real World'
 * '<S319>' : 'flightControlSystem/Flight Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running/Wrap To Zero'
 * '<S320>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity'
 * '<S321>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorXYPosition'
 * '<S322>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling'
 * '<S323>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/Angular velocity compensation for optical flow'
 * '<S324>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling'
 * '<S325>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy'
 * '<S326>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/XY velocity w//o angular velocity compensation'
 * '<S327>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
 * '<S328>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S329>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
 * '<S330>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
 * '<S331>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S332>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/DiscreteDerivative'
 * '<S333>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxdw1'
 * '<S334>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxdw2'
 * '<S335>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxp'
 * '<S336>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxp2'
 * '<S337>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxq'
 * '<S338>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxq2'
 * '<S339>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw1'
 * '<S340>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw2'
 * '<S341>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw3'
 * '<S342>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw4'
 * '<S343>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/minHeightforOF'
 * '<S344>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL'
 * '<S345>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat'
 * '<S346>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
 * '<S347>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionA'
 * '<S348>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionB'
 * '<S349>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionC'
 * '<S350>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionD'
 * '<S351>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionG'
 * '<S352>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionH'
 * '<S353>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionN'
 * '<S354>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP'
 * '<S355>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
 * '<S356>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
 * '<S357>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionR'
 * '<S358>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
 * '<S359>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX'
 * '<S360>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
 * '<S361>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionu'
 * '<S362>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/MemoryP'
 * '<S363>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Observer'
 * '<S364>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN'
 * '<S365>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Reset'
 * '<S366>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Reshapeyhat'
 * '<S367>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
 * '<S368>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
 * '<S369>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionR'
 * '<S370>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
 * '<S371>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkA'
 * '<S372>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkB'
 * '<S373>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkC'
 * '<S374>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkD'
 * '<S375>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkEnable'
 * '<S376>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkG'
 * '<S377>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkH'
 * '<S378>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkN'
 * '<S379>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkP0'
 * '<S380>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkQ'
 * '<S381>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkR'
 * '<S382>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkReset'
 * '<S383>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkX0'
 * '<S384>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checku'
 * '<S385>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checky'
 * '<S386>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
 * '<S387>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
 * '<S388>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
 * '<S389>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
 * '<S390>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
 * '<S391>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
 * '<S392>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
 * '<S393>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
 * '<S394>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
 * '<S395>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/XY velocity w//o angular velocity compensation/Compare To Constant'
 * '<S396>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/XY velocity w//o angular velocity compensation/Counter Free-Running'
 * '<S397>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/XY velocity w//o angular velocity compensation/Counter Free-Running/Increment Real World'
 * '<S398>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorVelocity/XY velocity w//o angular velocity compensation/Counter Free-Running/Wrap To Zero'
 * '<S399>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S400>' : 'flightControlSystem/Flight Control System/State Estimator/XY Position Estimator/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */
