/*
 * flightControlSystem.c
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

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"
#include "flightControlSystem_dt.h"

/* Named constants for Chart: '<S3>/Chart' */
#define flightControlSystem_IN_attitude (1U)
#define flightControlSystem_IN_attitude1 (2U)
#define flightControlSystem_IN_hover   (3U)
#define flightControlSystem_IN_init    (4U)
#define flightControlSystem_IN_init1   (5U)
#define flightControlSystem_IN_position (6U)
#define flightControlSystem_IN_velocity (7U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S13>/MotorDirections' */
uint8_T flag_outport;                  /* '<S4>/Merge' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_flightControlSystem_T flightControlSystem_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
static RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;

/* Forward declaration for local functions */
static real_T flightControlSystem_norm(const real_T x[3],
  B_FlightControlSystem_flightControlSystem_T *localB);

/* Forward declaration for local functions */
static void flightControlSystem_SystemCore_step(const uint8_T varargin_1[38400],
  uint8_T varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3
  [19200]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(flightControlSystem_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (flightControlSystem_M->Timing.TaskCounters.TID[1])++;
  if ((flightControlSystem_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    flightControlSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/Geofencing error'
 *    '<S4>/estimator//Optical flow error'
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion generated from: '<S224>/Out1' incorporates:
   *  Constant: '<S224>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Function for MATLAB Function: '<S240>/MATLAB Function1' */
static real_T flightControlSystem_norm(const real_T x[3],
  B_FlightControlSystem_flightControlSystem_T *localB)
{
  real_T y;
  localB->scale_b = 3.3121686421112381E-170;
  localB->absxk_p = fabs(x[0]);
  if (localB->absxk_p > 3.3121686421112381E-170) {
    y = 1.0;
    localB->scale_b = localB->absxk_p;
  } else {
    localB->t = localB->absxk_p / 3.3121686421112381E-170;
    y = localB->t * localB->t;
  }

  localB->absxk_p = fabs(x[1]);
  if (localB->absxk_p > localB->scale_b) {
    localB->t = localB->scale_b / localB->absxk_p;
    y = y * localB->t * localB->t + 1.0;
    localB->scale_b = localB->absxk_p;
  } else {
    localB->t = localB->absxk_p / localB->scale_b;
    y += localB->t * localB->t;
  }

  localB->absxk_p = fabs(x[2]);
  if (localB->absxk_p > localB->scale_b) {
    localB->t = localB->scale_b / localB->absxk_p;
    y = y * localB->t * localB->t + 1.0;
    localB->scale_b = localB->absxk_p;
  } else {
    localB->t = localB->absxk_p / localB->scale_b;
    y += localB->t * localB->t;
  }

  return localB->scale_b * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* System initialize for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Init(RT_MODEL_flightControlSystem_T
  * const flightControlSystem_M, B_FlightControlSystem_flightControlSystem_T
  *localB, DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP,
  ZCE_FlightControlSystem_flightControlSystem_T *localZCE)
{
  int32_T i;

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 17 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 17 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estimatedStates",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 4 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 4 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/To Workspace1";
    localDW->ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "motorCmd",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localP->LPFFcutoff40Hz1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localP->LPFFcutoff40Hz_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S242>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = localP->IIR_IMUgyro_r_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S242>/IIR_IMUgyro_r' */

  /* InitializeConditions for Sum: '<S318>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S316>/Output'
   */
  localDW->Output_DSTATE = localP->Output_InitialCondition;

  /* InitializeConditions for DiscreteFir: '<S242>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = localP->FIR_IMUaccel_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFir: '<S242>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S240>/Delay' */
  localDW->Delay_DSTATE[0] = localP->Delay_InitialCondition[0];
  localDW->Delay_DSTATE[1] = localP->Delay_InitialCondition[1];
  localDW->Delay_DSTATE[2] = localP->Delay_InitialCondition[2];
  localDW->Delay_DSTATE[3] = localP->Delay_InitialCondition[3];

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S239>/Delay2' */
  localDW->Delay2_DSTATE = localP->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S244>/MemoryX' */
  localDW->icLoad = 1U;

  /* InitializeConditions for Delay: '<S325>/MemoryX' */
  localDW->icLoad_h = 1U;

  /* InitializeConditions for Sum: '<S397>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S396>/Output'
   */
  localDW->Output_DSTATE_a = localP->Output_InitialCondition_b;

  /* InitializeConditions for DiscreteFilter: '<S324>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = localP->IIRgyroz_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S324>/IIRgyroz' */

  /* InitializeConditions for DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_j = localP->DiscreteTimeIntegrator_IC_j;
  localDW->DiscreteTimeIntegrator_PrevResetState_b = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Integrator' */
  localDW->Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Integrator' */
  localDW->Integrator_PrevResetState_p = 2;

  /* InitializeConditions for UnitDelay: '<S332>/UD' */
  localDW->UD_DSTATE[0] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S320>/Delay' */
  localDW->Delay_DSTATE_o[0] = localP->Delay_InitialCondition_n;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] =
    localP->SimplyIntegrateVelocity_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Integrator' */
  localDW->Integrator_DSTATE[0] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a;

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Integrator' */
  localDW->Integrator_DSTATE_a[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Filter' */
  localDW->Filter_DSTATE[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;

  /* InitializeConditions for UnitDelay: '<S332>/UD' */
  localDW->UD_DSTATE[1] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S320>/Delay' */
  localDW->Delay_DSTATE_o[1] = localP->Delay_InitialCondition_n;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] =
    localP->SimplyIntegrateVelocity_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Integrator' */
  localDW->Integrator_DSTATE[1] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a;

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Integrator' */
  localDW->Integrator_DSTATE_a[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Filter' */
  localDW->Filter_DSTATE[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;
  localDW->Filter_PrevResetState = 2;

  /* InitializeConditions for Sum: '<S230>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S223>/Output'
   */
  localDW->Output_DSTATE_a3 = localP->Output_InitialCondition_c;

  /* InitializeConditions for Sum: '<S227>/Add' incorporates:
   *  Delay: '<S227>/Delay One Step'
   */
  localDW->DelayOneStep_DSTATE = localP->DelayOneStep_InitialCondition;

  /* InitializeConditions for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localP->sonarFilter_IIR_InitialStates;

  /* SystemInitialize for Chart: '<S3>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c6_flightControlSystem = 0U;
  localDW->is_c6_flightControlSystem = 0U;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  flag_outport = localP->Merge_InitialOutput;

  /* SystemInitialize for Triggered SubSystem: '<S236>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S238>/X' incorporates:
   *  Outport: '<S238>/X'
   */
  localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0 = localP->X_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S238>/Y' incorporates:
   *  Outport: '<S238>/Y'
   */
  localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0 = localP->Y_Y0;
  localZCE->TriggeredSubsystem_Trig_ZCE_k = ZERO_ZCSIG;

  /* End of SystemInitialize for SubSystem: '<S236>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S267>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S295>/Product3' incorporates:
   *  Outport: '<S295>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S267>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S273>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S297>/Product2' incorporates:
   *  Outport: '<S297>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S273>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S267>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S295>/Product3' incorporates:
   *  Outport: '<S295>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[1] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S267>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S273>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S297>/Product2' incorporates:
   *  Outport: '<S297>/deltax'
   */
  localB->Product2[1] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S273>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S267>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S295>/Product3' incorporates:
   *  Outport: '<S295>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[2] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S267>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S273>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S297>/Product2' incorporates:
   *  Outport: '<S297>/deltax'
   */
  localB->Product2[2] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S273>/Enabled Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S313>/Triggered Subsystem' */
  /* SystemInitialize for Outport: '<S317>/Out1' incorporates:
   *  Inport: '<S317>/In1'
   */
  localB->In1 = localP->Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S313>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S363>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S392>/Product3' incorporates:
   *  Outport: '<S392>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_f[0] = localP->Lykyhatkk1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S363>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S370>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S394>/Product2' incorporates:
   *  Outport: '<S394>/deltax'
   */
  localB->Product2_n[0] = localP->deltax_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S370>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S363>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S392>/Product3' incorporates:
   *  Outport: '<S392>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_f[1] = localP->Lykyhatkk1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S363>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S370>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S394>/Product2' incorporates:
   *  Outport: '<S394>/deltax'
   */
  localB->Product2_n[1] = localP->deltax_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S370>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S363>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S392>/Product3' incorporates:
   *  Outport: '<S392>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_f[2] = localP->Lykyhatkk1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S363>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S370>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S394>/Product2' incorporates:
   *  Outport: '<S394>/deltax'
   */
  localB->Product2_n[2] = localP->deltax_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S370>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S363>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S392>/Product3' incorporates:
   *  Outport: '<S392>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_f[3] = localP->Lykyhatkk1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S363>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S370>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S394>/Product2' incorporates:
   *  Outport: '<S394>/deltax'
   */
  localB->Product2_n[3] = localP->deltax_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S370>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds,
  const SensorsBus *rtu_Sensors, B_FlightControlSystem_flightControlSystem_T
  *localB, DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP,
  ZCE_FlightControlSystem_flightControlSystem_T *localZCE)
{
  static const int8_T b_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f;
  real32_T rtb_FilterCoefficient_idx_0;
  real32_T rtb_IntegralGain_b_idx_1;
  real32_T rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;
  real32_T rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1;
  real32_T rtb_Saturation_idx_0;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreIntegrator_0;
  real32_T rtb_SignPreIntegrator_idx_0;
  real32_T rtb_Switch_c_tmp;
  real32_T rtb_altitude;
  real32_T rtb_sincos_o2_idx_0_tmp;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_da;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_NotEqual_idx_1;
  boolean_T rtb_NotEqual_o_idx_0;
  boolean_T rtb_NotEqual_o_idx_1;

  /* SignalConversion generated from: '<S314>/Bus Selector3' */
  localB->x = rtu_Sensors->HALSensors.HAL_acc_SI.x;

  /* SignalConversion generated from: '<S314>/Bus Selector3' */
  localB->y = rtu_Sensors->HALSensors.HAL_acc_SI.y;

  /* SignalConversion generated from: '<S314>/Bus Selector3' */
  localB->z = rtu_Sensors->HALSensors.HAL_acc_SI.z;

  /* SignalConversion generated from: '<S314>/Bus Selector4' */
  localB->x_c = rtu_Sensors->HALSensors.HAL_gyro_SI.x;

  /* SignalConversion generated from: '<S314>/Bus Selector4' */
  localB->y_n = rtu_Sensors->HALSensors.HAL_gyro_SI.y;

  /* SignalConversion generated from: '<S314>/Bus Selector4' */
  localB->z_p = rtu_Sensors->HALSensors.HAL_gyro_SI.z;

  /* Sum: '<S242>/Sum1' incorporates:
   *  Bias: '<S242>/Assuming that the  preflight calibration was done at level orientation'
   *  Constant: '<S242>/Constant'
   *  DataTypeConversion: '<S242>/Data Type Conversion'
   */
  localB->Sum1_f[0] = localB->x - (localP->Constant_Value_e[0] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[0]);
  localB->Sum1_f[1] = localB->y - (localP->Constant_Value_e[1] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[1]);
  localB->Sum1_f[2] = localB->z - (localP->Constant_Value_e[2] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[2]);
  localB->Sum1_f[3] = localB->x_c - (rtu_Sensors->SensorCalibration[3] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[3]);
  localB->Sum1_f[4] = localB->y_n - (rtu_Sensors->SensorCalibration[4] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[4]);
  localB->Sum1_f[5] = localB->z_p - (rtu_Sensors->SensorCalibration[5] +
    localP->Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[5]);
  for (localB->j = 0; localB->j < 6; localB->j++) {
    /* Gain: '<S242>/inverseIMU_gain' */
    localB->Sum1_f[localB->j] *= localP->inverseIMU_gain_Gain[localB->j];
  }

  /* DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz1' */
  localB->denAccum = (localB->Sum1_f[3] - localP->LPFFcutoff40Hz1_DenCoef[1] *
                      localDW->LPFFcutoff40Hz1_states) /
    localP->LPFFcutoff40Hz1_DenCoef[0];

  /* DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz1' */
  localB->p = localP->LPFFcutoff40Hz1_NumCoef[0] * localB->denAccum +
    localP->LPFFcutoff40Hz1_NumCoef[1] * localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz' */
  localB->denAccum_c = (localB->Sum1_f[4] - localP->LPFFcutoff40Hz_DenCoef[1] *
                        localDW->LPFFcutoff40Hz_states) /
    localP->LPFFcutoff40Hz_DenCoef[0];

  /* DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz' */
  localB->q = localP->LPFFcutoff40Hz_NumCoef[0] * localB->denAccum_c +
    localP->LPFFcutoff40Hz_NumCoef[1] * localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S242>/IIR_IMUgyro_r' */
  localB->denAccum_f = localB->Sum1_f[5];
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->denAccum_f -= localP->IIR_IMUgyro_r_DenCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  localB->denAccum_f /= localP->IIR_IMUgyro_r_DenCoef[0];
  rtb_IntegralGain_b_idx_1 = localP->IIR_IMUgyro_r_NumCoef[0] *
    localB->denAccum_f;
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    rtb_IntegralGain_b_idx_1 += localP->IIR_IMUgyro_r_NumCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  /* RelationalOperator: '<S315>/Compare' incorporates:
   *  Constant: '<S315>/Constant'
   *  UnitDelay: '<S316>/Output'
   */
  rtb_Compare = (localDW->Output_DSTATE == localP->CompareToConstant_const_f);

  /* Outputs for Triggered SubSystem: '<S313>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S317>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == 1) != (int32_T)rtb_Compare) &&
      (localZCE->TriggeredSubsystem_Trig_ZCE != 3)) {
    /* Inport: '<S317>/In1' */
    localB->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
    localDW->TriggeredSubsystem_SubsysRanBC = 4;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare;

  /* End of Outputs for SubSystem: '<S313>/Triggered Subsystem' */

  /* ManualSwitch: '<S313>/Disable temperature compensation' incorporates:
   *  Constant: '<S313>/Constant'
   *  Gain: '<S313>/Gain'
   *  Sum: '<S313>/Subtract'
   */
  if (localP->Disabletemperaturecompensation_CurrentSetting == 1) {
    localB->w = (rtu_Sensors->HALSensors.HAL_gyro_SI.temperature - localB->In1) *
      localP->Gain_Gain_i;
  } else {
    localB->w = localP->Constant_Value_k;
  }

  /* End of ManualSwitch: '<S313>/Disable temperature compensation' */

  /* Sum: '<S313>/Subtract1' incorporates:
   *  DataTypeConversion: '<S313>/Data Type Conversion1'
   *  DiscreteFilter: '<S242>/IIR_IMUgyro_r'
   */
  localB->r = rtb_IntegralGain_b_idx_1 - (real32_T)localB->w;

  /* DiscreteFir: '<S242>/FIR_IMUaccel' */
  localB->scale_g = localB->Sum1_f[0] * localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = localB->scale_g;
  localB->scale_g = localB->Sum1_f[1] * localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = localB->scale_g;
  localB->scale_g = localB->Sum1_f[2] * localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->scale_g += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = localB->scale_g;

  /* End of DiscreteFir: '<S242>/FIR_IMUaccel' */

  /* DataTypeConversion: '<S240>/Data Type Conversion2' */
  localB->DataTypeConversion2_k[0] = localB->FIR_IMUaccel[0];
  localB->DataTypeConversion2_k[1] = localB->FIR_IMUaccel[1];
  localB->DataTypeConversion2_k[2] = localB->FIR_IMUaccel[2];

  /* DataTypeConversion: '<S240>/Data Type Conversion4' */
  localB->DataTypeConversion4[0] = localB->p;
  localB->DataTypeConversion4[1] = localB->q;
  localB->DataTypeConversion4[2] = localB->r;

  /* MATLAB Function: '<S240>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S240>/Data Type Conversion2'
   *  DataTypeConversion: '<S240>/Data Type Conversion4'
   *  Delay: '<S240>/Delay'
   */
  localB->w = flightControlSystem_norm(localB->DataTypeConversion4, localB);
  if (!(localB->w == 0.0)) {
    localB->scale = cos(localB->w * 0.0025);
    localB->absxk = 2.0 / localB->w;
    localB->n = sin(localB->w * 0.0025);
    localB->oa = localB->absxk * 0.0 * localB->n;
    localB->a[0] = localB->oa;
    localB->ob = 0.5 * -(real_T)localB->p * localB->absxk * localB->n;
    localB->a[4] = localB->ob;
    localB->oc = 0.5 * -(real_T)localB->q * localB->absxk * localB->n;
    localB->a[8] = localB->oc;
    localB->od = 0.5 * -(real_T)localB->r * localB->absxk * localB->n;
    localB->a[12] = localB->od;
    localB->fcn3 = 0.5 * localB->p * localB->absxk * localB->n;
    localB->a[1] = localB->fcn3;
    localB->a[5] = localB->oa;
    localB->a_tmp = 0.5 * localB->r * localB->absxk * localB->n;
    localB->a[9] = localB->a_tmp;
    localB->a[13] = localB->oc;
    localB->oc = 0.5 * localB->q * localB->absxk * localB->n;
    localB->a[2] = localB->oc;
    localB->a[6] = localB->od;
    localB->a[10] = localB->oa;
    localB->a[14] = localB->fcn3;
    localB->a[3] = localB->a_tmp;
    localB->a[7] = localB->oc;
    localB->a[11] = localB->ob;
    localB->a[15] = localB->oa;
    for (localB->j = 0; localB->j < 16; localB->j++) {
      localB->b_a[localB->j] = (real_T)b_a[localB->j] * localB->scale +
        localB->a[localB->j];
    }

    for (localB->j = 0; localB->j < 4; localB->j++) {
      localB->scale = localB->b_a[localB->j + 12] * localDW->Delay_DSTATE[3] +
        (localB->b_a[localB->j + 8] * localDW->Delay_DSTATE[2] + (localB->
          b_a[localB->j + 4] * localDW->Delay_DSTATE[1] + localB->b_a[localB->j]
          * localDW->Delay_DSTATE[0]));
      localB->b_a_c[localB->j] = localB->scale;
    }

    localDW->Delay_DSTATE[0] = localB->b_a_c[0];
    localDW->Delay_DSTATE[1] = localB->b_a_c[1];
    localDW->Delay_DSTATE[2] = localB->b_a_c[2];
    localDW->Delay_DSTATE[3] = localB->b_a_c[3];
  }

  if ((localB->w < 1.0) && (fabs(flightControlSystem_norm
        (localB->DataTypeConversion2_k, localB) - 9.81) < 2.9)) {
    localB->n = sqrt(((localDW->Delay_DSTATE[0] * localDW->Delay_DSTATE[0] +
                       -localDW->Delay_DSTATE[1] * -localDW->Delay_DSTATE[1]) +
                      -localDW->Delay_DSTATE[2] * -localDW->Delay_DSTATE[2]) +
                     -localDW->Delay_DSTATE[3] * -localDW->Delay_DSTATE[3]);
    localB->w = localDW->Delay_DSTATE[0] / localB->n;
    localB->scale = -localDW->Delay_DSTATE[1] / localB->n;
    localB->absxk = -localDW->Delay_DSTATE[2] / localB->n;
    localB->n = -localDW->Delay_DSTATE[3] / localB->n;
    localB->oa = ((localB->w * 0.0 - -localB->scale * localB->FIR_IMUaccel[0]) -
                  -localB->absxk * localB->FIR_IMUaccel[1]) - -localB->n *
      localB->FIR_IMUaccel[2];
    localB->ob = ((localB->w * localB->FIR_IMUaccel[0] + -localB->scale * 0.0) +
                  -localB->absxk * localB->FIR_IMUaccel[2]) - -localB->n *
      localB->FIR_IMUaccel[1];
    localB->oc = ((localB->w * localB->FIR_IMUaccel[1] - -localB->scale *
                   localB->FIR_IMUaccel[2]) + -localB->absxk * 0.0) + -localB->n
      * localB->FIR_IMUaccel[0];
    localB->od = ((localB->w * localB->FIR_IMUaccel[2] + -localB->scale *
                   localB->FIR_IMUaccel[1]) - -localB->absxk *
                  localB->FIR_IMUaccel[0]) + -localB->n * 0.0;
    localB->DataTypeConversion2_k[0] = ((localB->oa * localB->scale + localB->ob
      * localB->w) + localB->oc * localB->n) - localB->od * localB->absxk;
    localB->DataTypeConversion2_k[1] = ((localB->oa * localB->absxk - localB->ob
      * localB->n) + localB->oc * localB->w) + localB->od * localB->scale;
    localB->DataTypeConversion2_k[2] = ((localB->oa * localB->n + localB->ob *
      localB->absxk) - localB->oc * localB->scale) + localB->od * localB->w;
    localB->scale = 3.3121686421112381E-170;
    localB->absxk = fabs(localB->DataTypeConversion2_k[0]);
    if (localB->absxk > 3.3121686421112381E-170) {
      localB->w = 1.0;
      localB->scale = localB->absxk;
    } else {
      localB->n = localB->absxk / 3.3121686421112381E-170;
      localB->w = localB->n * localB->n;
    }

    localB->absxk = fabs(localB->DataTypeConversion2_k[1]);
    if (localB->absxk > localB->scale) {
      localB->n = localB->scale / localB->absxk;
      localB->w = localB->w * localB->n * localB->n + 1.0;
      localB->scale = localB->absxk;
    } else {
      localB->n = localB->absxk / localB->scale;
      localB->w += localB->n * localB->n;
    }

    localB->absxk = fabs(localB->DataTypeConversion2_k[2]);
    if (localB->absxk > localB->scale) {
      localB->n = localB->scale / localB->absxk;
      localB->w = localB->w * localB->n * localB->n + 1.0;
      localB->scale = localB->absxk;
    } else {
      localB->n = localB->absxk / localB->scale;
      localB->w += localB->n * localB->n;
    }

    localB->w = localB->scale * sqrt(localB->w);
    localB->absxk = localB->DataTypeConversion2_k[0] / localB->w;
    localB->scale = 0.0 * localB->absxk;
    localB->DataTypeConversion2_k[0] = localB->absxk;
    localB->absxk = localB->DataTypeConversion2_k[1] / localB->w;
    localB->scale += 0.0 * localB->absxk;
    localB->DataTypeConversion2_k[1] = localB->absxk;
    localB->absxk = localB->DataTypeConversion2_k[2] / localB->w;
    localB->scale += -localB->absxk;
    localB->DataTypeConversion4[0] = -localB->DataTypeConversion2_k[1] -
      localB->absxk * 0.0;
    localB->DataTypeConversion4[1] = localB->absxk * 0.0 -
      (-localB->DataTypeConversion2_k[0]);
    localB->DataTypeConversion4[2] = localB->DataTypeConversion2_k[0] * 0.0 -
      localB->DataTypeConversion2_k[1] * 0.0;
    localB->w = flightControlSystem_norm(localB->DataTypeConversion4, localB);
    localB->scale = 0.002 * acos(localB->scale) / 2.0;
    localB->oa = sin(localB->scale);
    localB->scale = cos(localB->scale);
    localB->absxk = localB->DataTypeConversion4[0] / localB->w * localB->oa;
    localB->n = localB->DataTypeConversion4[1] / localB->w * localB->oa;
    localB->oa *= localB->DataTypeConversion4[2] / localB->w;
    localB->w = localDW->Delay_DSTATE[0];
    localB->ob = localDW->Delay_DSTATE[1];
    localB->oc = localDW->Delay_DSTATE[2];
    localB->od = localDW->Delay_DSTATE[3];
    localB->fcn3 = localDW->Delay_DSTATE[1];
    localB->a_tmp = localDW->Delay_DSTATE[0];
    localB->d = localDW->Delay_DSTATE[3];
    localB->d1 = localDW->Delay_DSTATE[2];
    localB->d2 = localDW->Delay_DSTATE[2];
    localB->d3 = localDW->Delay_DSTATE[3];
    localB->d4 = localDW->Delay_DSTATE[0];
    localB->d5 = localDW->Delay_DSTATE[1];
    localB->d6 = localDW->Delay_DSTATE[3];
    localB->d7 = localDW->Delay_DSTATE[2];
    localB->d8 = localDW->Delay_DSTATE[1];
    localB->d9 = localDW->Delay_DSTATE[0];
    localDW->Delay_DSTATE[0] = ((localB->scale * localB->w - localB->absxk *
      localB->ob) - localB->n * localB->oc) - localB->oa * localB->od;
    localDW->Delay_DSTATE[1] = ((localB->scale * localB->fcn3 + localB->absxk *
      localB->a_tmp) + localB->n * localB->d) - localB->oa * localB->d1;
    localDW->Delay_DSTATE[2] = ((localB->scale * localB->d2 - localB->absxk *
      localB->d3) + localB->n * localB->d4) + localB->oa * localB->d5;
    localDW->Delay_DSTATE[3] = ((localB->scale * localB->d6 + localB->absxk *
      localB->d7) - localB->n * localB->d8) + localB->oa * localB->d9;
  }

  /* End of MATLAB Function: '<S240>/MATLAB Function1' */

  /* Sqrt: '<S311>/sqrt' incorporates:
   *  Delay: '<S240>/Delay'
   *  Product: '<S312>/Product'
   *  Product: '<S312>/Product1'
   *  Product: '<S312>/Product2'
   *  Product: '<S312>/Product3'
   *  Sum: '<S312>/Sum'
   */
  localB->w = sqrt(((localDW->Delay_DSTATE[0] * localDW->Delay_DSTATE[0] +
                     localDW->Delay_DSTATE[1] * localDW->Delay_DSTATE[1]) +
                    localDW->Delay_DSTATE[2] * localDW->Delay_DSTATE[2]) +
                   localDW->Delay_DSTATE[3] * localDW->Delay_DSTATE[3]);

  /* Product: '<S306>/Product' incorporates:
   *  Delay: '<S240>/Delay'
   */
  localB->scale = localDW->Delay_DSTATE[0] / localB->w;

  /* Product: '<S306>/Product1' incorporates:
   *  Delay: '<S240>/Delay'
   */
  localB->absxk = localDW->Delay_DSTATE[1] / localB->w;

  /* Product: '<S306>/Product2' incorporates:
   *  Delay: '<S240>/Delay'
   */
  localB->n = localDW->Delay_DSTATE[2] / localB->w;

  /* Product: '<S306>/Product3' incorporates:
   *  Delay: '<S240>/Delay'
   */
  localB->w = localDW->Delay_DSTATE[3] / localB->w;

  /* Fcn: '<S304>/fcn2' incorporates:
   *  Fcn: '<S304>/fcn5'
   */
  localB->oa = localB->scale * localB->scale;
  localB->ob = localB->absxk * localB->absxk;
  localB->oc = localB->n * localB->n;
  localB->od = localB->w * localB->w;

  /* Fcn: '<S304>/fcn3' */
  localB->fcn3 = (localB->absxk * localB->w - localB->scale * localB->n) * -2.0;

  /* If: '<S307>/If' incorporates:
   *  Constant: '<S308>/Constant'
   *  Constant: '<S309>/Constant'
   */
  if (localB->fcn3 > 1.0) {
    /* Outputs for IfAction SubSystem: '<S307>/If Action Subsystem' incorporates:
     *  ActionPort: '<S308>/Action Port'
     */
    localB->fcn3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S307>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S307>/If Action Subsystem' incorporates:
     *  ActionPort: '<S308>/Action Port'
     */
    /* Update for If: '<S307>/If' incorporates:
     *  Constant: '<S308>/Constant'
     */
    srUpdateBC(localDW->IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S307>/If Action Subsystem' */
  } else if (localB->fcn3 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S307>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S309>/Action Port'
     */
    localB->fcn3 = localP->Constant_Value_n;

    /* End of Outputs for SubSystem: '<S307>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S307>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S309>/Action Port'
     */
    /* Update for If: '<S307>/If' incorporates:
     *  Constant: '<S309>/Constant'
     */
    srUpdateBC(localDW->IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S307>/If Action Subsystem1' */
  } else {
    /* Update for IfAction SubSystem: '<S307>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S310>/Action Port'
     */
    /* Update for If: '<S307>/If' */
    srUpdateBC(localDW->IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<S307>/If Action Subsystem2' */
  }

  /* End of If: '<S307>/If' */

  /* Trigonometry: '<S305>/trigFcn' */
  if (localB->fcn3 > 1.0) {
    localB->fcn3 = 1.0;
  } else {
    if (localB->fcn3 < -1.0) {
      localB->fcn3 = -1.0;
    }
  }

  /* DataTypeConversion: '<S240>/Cast To Single' incorporates:
   *  Fcn: '<S304>/fcn1'
   *  Fcn: '<S304>/fcn2'
   *  Fcn: '<S304>/fcn4'
   *  Fcn: '<S304>/fcn5'
   *  Trigonometry: '<S305>/Trigonometric Function1'
   *  Trigonometry: '<S305>/Trigonometric Function3'
   *  Trigonometry: '<S305>/trigFcn'
   */
  localB->CastToSingle[0] = (real32_T)rt_atan2d_snf((localB->absxk * localB->n +
    localB->scale * localB->w) * 2.0, ((localB->oa + localB->ob) - localB->oc) -
    localB->od);
  localB->CastToSingle[1] = (real32_T)asin(localB->fcn3);
  localB->CastToSingle[2] = (real32_T)rt_atan2d_snf((localB->n * localB->w +
    localB->scale * localB->absxk) * 2.0, ((localB->oa - localB->ob) -
    localB->oc) + localB->od);

  /* MATLAB Function: '<S6>/MATLAB Function' */
  localB->y_b = 0.0F;
  localB->scale_g = 1.29246971E-26F;
  localB->absxk_g = (real32_T)fabs(localB->FIR_IMUaccel[0]);
  if (localB->absxk_g > 1.29246971E-26F) {
    localB->t_m = 1.29246971E-26F / localB->absxk_g;
    localB->y_b = localB->y_b * localB->t_m * localB->t_m + 1.0F;
    localB->scale_g = localB->absxk_g;
  } else {
    localB->t_m = localB->absxk_g / 1.29246971E-26F;
    localB->y_b += localB->t_m * localB->t_m;
  }

  localB->absxk_g = (real32_T)fabs(localB->FIR_IMUaccel[1]);
  if (localB->absxk_g > localB->scale_g) {
    localB->t_m = localB->scale_g / localB->absxk_g;
    localB->y_b = localB->y_b * localB->t_m * localB->t_m + 1.0F;
    localB->scale_g = localB->absxk_g;
  } else {
    localB->t_m = localB->absxk_g / localB->scale_g;
    localB->y_b += localB->t_m * localB->t_m;
  }

  localB->absxk_g = (real32_T)fabs(localB->FIR_IMUaccel[2]);
  if (localB->absxk_g > localB->scale_g) {
    localB->t_m = localB->scale_g / localB->absxk_g;
    localB->y_b = localB->y_b * localB->t_m * localB->t_m + 1.0F;
    localB->scale_g = localB->absxk_g;
  } else {
    localB->t_m = localB->absxk_g / localB->scale_g;
    localB->y_b += localB->t_m * localB->t_m;
  }

  localB->y_b = localB->scale_g * (real32_T)sqrt(localB->y_b);

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* Trigonometry: '<S246>/sincos' incorporates:
   *  MATLAB Function: '<S11>/Position error transformation (Earth to Body frame)'
   *  Trigonometry: '<S328>/sincos'
   *  Trigonometry: '<S399>/sincos'
   */
  rtb_sincos_o2_idx_0_tmp = (real32_T)sin(localB->CastToSingle[0]);
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 = (real32_T)
    cos(localB->CastToSingle[0]);
  localB->t_m = (real32_T)sin(localB->CastToSingle[1]);
  localB->Saturation_h = (real32_T)cos(localB->CastToSingle[1]);
  LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f = (real32_T)
    sin(localB->CastToSingle[2]);
  rtb_Switch_c_tmp = (real32_T)cos(localB->CastToSingle[2]);

  /* Fcn: '<S246>/Fcn11' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[0] = localB->Saturation_h *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S246>/Fcn21' incorporates:
   *  Fcn: '<S246>/Fcn22'
   *  Trigonometry: '<S246>/sincos'
   */
  localB->scale_g =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->t_m;
  localB->MathFunction[1] = localB->scale_g *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 -
    rtb_Switch_c_tmp * rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S246>/Fcn31' incorporates:
   *  Fcn: '<S246>/Fcn32'
   *  Trigonometry: '<S246>/sincos'
   */
  localB->absxk_g = rtb_Switch_c_tmp * localB->t_m;
  localB->MathFunction[2] = localB->absxk_g *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S246>/Fcn12' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[3] = localB->Saturation_h * rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S246>/Fcn22' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[4] = localB->scale_g * rtb_sincos_o2_idx_0_tmp +
    rtb_Switch_c_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S246>/Fcn32' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[5] = localB->absxk_g * rtb_sincos_o2_idx_0_tmp -
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S246>/Fcn13' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[6] = -localB->t_m;

  /* Fcn: '<S246>/Fcn23' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[7] =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->Saturation_h;

  /* Fcn: '<S246>/Fcn33' incorporates:
   *  Trigonometry: '<S246>/sincos'
   */
  localB->MathFunction[8] = rtb_Switch_c_tmp * localB->Saturation_h;

  /* RelationalOperator: '<S247>/Compare' incorporates:
   *  Constant: '<S247>/Constant'
   *  Delay: '<S239>/Delay2'
   */
  localB->Compare = (localDW->Delay2_DSTATE > localP->outlierBelowFloor_const);

  /* Delay: '<S244>/MemoryX' incorporates:
   *  Constant: '<S244>/X0'
   *  DataTypeConversion: '<S244>/DataTypeConversionReset'
   *  Reshape: '<S244>/ReshapeX0'
   */
  if (localB->Compare) {
    localDW->icLoad = 1U;
  }

  if (localDW->icLoad != 0) {
    localDW->MemoryX_DSTATE[0] = localP->X0_Value[0];
    localDW->MemoryX_DSTATE[1] = localP->X0_Value[1];
    localDW->MemoryX_DSTATE[2] = localP->X0_Value[2];
  }

  /* Gain: '<S239>/prsToAltGain' incorporates:
   *  DataTypeConversion: '<S242>/Data Type Conversion'
   *  SignalConversion generated from: '<S314>/Bus Selector6'
   *  Sum: '<S242>/Sum2'
   */
  localB->scale_g = (rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
                     rtu_Sensors->SensorCalibration[6]) *
    localP->prsToAltGain_Gain;

  /* DataTypeConversion: '<S239>/Data Type Conversion3' */
  localB->DataTypeConversion3 = localB->scale_g;

  /* Outputs for Enabled SubSystem: '<S273>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S297>/Enable'
   */
  /* Constant: '<S244>/Enable' */
  if (localP->Enable_Value) {
    localDW->EnabledSubsystem_MODE_m = true;

    /* Sum: '<S297>/Add1' incorporates:
     *  Constant: '<S244>/C'
     *  Delay: '<S244>/MemoryX'
     *  Product: '<S297>/Product'
     *  Reshape: '<S244>/Reshapey'
     */
    localB->w = localB->DataTypeConversion3 - ((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localP->C_Value[2] * localDW->MemoryX_DSTATE[2]);

    /* Product: '<S297>/Product2' incorporates:
     *  Constant: '<S248>/KalmanGainM'
     *  DataTypeConversion: '<S290>/Conversion'
     */
    localB->Product2[0] = localP->KalmanGainM_Value[0] * localB->w;
    localB->Product2[1] = localP->KalmanGainM_Value[1] * localB->w;
    localB->Product2[2] = localP->KalmanGainM_Value[2] * localB->w;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC_m);
  } else {
    if (localDW->EnabledSubsystem_MODE_m) {
      /* Disable for Product: '<S297>/Product2' incorporates:
       *  Outport: '<S297>/deltax'
       */
      localB->Product2[0] = localP->deltax_Y0;
      localB->Product2[1] = localP->deltax_Y0;
      localB->Product2[2] = localP->deltax_Y0;
      localDW->EnabledSubsystem_MODE_m = false;
    }
  }

  /* End of Outputs for SubSystem: '<S273>/Enabled Subsystem' */

  /* Reshape: '<S244>/Reshapexhat' incorporates:
   *  Delay: '<S244>/MemoryX'
   *  Sum: '<S273>/Add'
   */
  localB->Reshapexhat[0] = localB->Product2[0] + localDW->MemoryX_DSTATE[0];
  localB->Reshapexhat[1] = localB->Product2[1] + localDW->MemoryX_DSTATE[1];
  localB->Reshapexhat[2] = localB->Product2[2] + localDW->MemoryX_DSTATE[2];

  /* SignalConversion generated from: '<S239>/Product1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->w = localDW->Delay1_DSTATE[0];
  localB->scale = localDW->Delay1_DSTATE[1];
  localB->absxk = localB->Reshapexhat[1];

  /* Product: '<S239>/Product1' incorporates:
   *  Math: '<S239>/Math Function'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->DataTypeConversion2_k[localB->j] = localB->MathFunction[localB->j +
      6] * localB->absxk + (localB->MathFunction[localB->j + 3] * localB->scale
      + localB->MathFunction[localB->j] * localB->w);
  }

  /* End of Product: '<S239>/Product1' */

  /* DataTypeConversion: '<S239>/Data Type Conversion2' */
  localB->DataTypeConversion2 = (real32_T)localB->DataTypeConversion2_k[2];

  /* DataTypeConversion: '<S239>/Data Type Conversion' */
  localB->DataTypeConversion = (real32_T)localB->Reshapexhat[0];

  /* Delay: '<S325>/MemoryX' incorporates:
   *  Constant: '<S325>/X0'
   *  Reshape: '<S325>/ReshapeX0'
   */
  if (localDW->icLoad_h != 0) {
    localDW->MemoryX_DSTATE_l[0] = localP->X0_Value_b[0];
    localDW->MemoryX_DSTATE_l[1] = localP->X0_Value_b[1];
    localDW->MemoryX_DSTATE_l[2] = localP->X0_Value_b[2];
    localDW->MemoryX_DSTATE_l[3] = localP->X0_Value_b[3];
  }

  /* Switch: '<S326>/Switch' incorporates:
   *  Constant: '<S395>/Constant'
   *  Gain: '<S326>/opticalFlowErrorCorrect'
   *  Product: '<S326>/ '
   *  RelationalOperator: '<S395>/Compare'
   *  UnitDelay: '<S396>/Output'
   */
  if (localDW->Output_DSTATE_a < localP->CompareToConstant_const_l) {
    localB->Switch_c[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    localB->Switch_c[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1];
    localB->Switch_c[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    /* Gain: '<S326>/Gain' */
    localB->absxk_g = localP->Gain_Gain_f * localB->DataTypeConversion;
    localB->Switch_c[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      localB->absxk_g * localP->opticalFlowErrorCorrect_Gain;
    localB->Switch_c[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      localB->absxk_g * localP->opticalFlowErrorCorrect_Gain;
    localB->Switch_c[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2] *
      localB->absxk_g * localP->opticalFlowErrorCorrect_Gain;
  }

  /* End of Switch: '<S326>/Switch' */

  /* Abs: '<S323>/Abs' */
  localB->absxk_g = (real32_T)fabs(localB->DataTypeConversion);

  /* SignalConversion generated from: '<S324>/IIRgyroz' */
  localB->TmpSignalConversionAtIIRgyrozInport1[0] = localB->p;
  localB->TmpSignalConversionAtIIRgyrozInport1[1] = localB->q;

  /* Sum: '<S320>/angular velocity compensation' incorporates:
   *  Gain: '<S323>/Gain1'
   *  Product: '<S323>/prod'
   *  SignalConversion generated from: '<S324>/IIRgyroz'
   */
  localB->angularvelocitycompensation[0] = localP->Gain1_Gain * (localB->absxk_g
    * localB->q) + localB->Switch_c[0];
  localB->angularvelocitycompensation[1] = localB->Switch_c[1] + localB->absxk_g
    * localB->p;
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* DiscreteFilter: '<S324>/IIRgyroz' */
    localB->memOffset = localB->cff * 5;
    rtb_IntegralGain_b_idx_1 = localB->
      TmpSignalConversionAtIIRgyrozInport1[localB->cff];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_IntegralGain_b_idx_1 -= localDW->IIRgyroz_states[localB->memOffset +
        localB->j] * localP->IIRgyroz_DenCoef[localB->denIdx];
      localB->denIdx++;
    }

    localB->absxk_g = rtb_IntegralGain_b_idx_1 / localP->IIRgyroz_DenCoef[0];
    rtb_IntegralGain_b_idx_1 = localP->IIRgyroz_NumCoef[0] * localB->absxk_g;
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_IntegralGain_b_idx_1 += localDW->IIRgyroz_states[localB->memOffset +
        localB->j] * localP->IIRgyroz_NumCoef[localB->denIdx];
      localB->denIdx++;
    }

    /* SampleTimeMath: '<S332>/TSamp' incorporates:
     *  DiscreteFilter: '<S324>/IIRgyroz'
     *
     * About '<S332>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_IntegralGain_b_idx_1 *= localP->TSamp_WtEt;

    /* Sum: '<S332>/Diff' incorporates:
     *  UnitDelay: '<S332>/UD'
     */
    localDW->UD_DSTATE[localB->cff] = rtb_IntegralGain_b_idx_1 -
      localDW->UD_DSTATE[localB->cff];

    /* DiscreteFilter: '<S324>/IIRgyroz' incorporates:
     *  Delay: '<S320>/Delay'
     *  Sum: '<S324>/Add'
     */
    localB->IIRgyroz_tmp[localB->cff] = localB->absxk_g;
    localB->SignPreSat[localB->cff] = localB->Switch_c[localB->cff] -
      localDW->Delay_DSTATE_o[localB->cff];

    /* SampleTimeMath: '<S332>/TSamp'
     *
     * About '<S332>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TmpSignalConversionAtIIRgyrozInport1[localB->cff] =
      rtb_IntegralGain_b_idx_1;
  }

  /* Abs: '<S324>/Abs' incorporates:
   *  Abs: '<S324>/Abs4'
   */
  localB->absxk_g = (real32_T)fabs(localB->p);

  /* Abs: '<S324>/Abs1' incorporates:
   *  Abs: '<S324>/Abs5'
   */
  rtb_IntegralGain_b_idx_1 = (real32_T)fabs(localB->q);

  /* Abs: '<S324>/Abs2' incorporates:
   *  Chart: '<S3>/Chart'
   */
  rtb_FilterCoefficient_idx_0 = (real32_T)fabs(localB->CastToSingle[1]);

  /* Abs: '<S324>/Abs3' incorporates:
   *  Chart: '<S3>/Chart'
   */
  rtb_SignPreIntegrator_idx_0 = (real32_T)fabs(localB->CastToSingle[2]);

  /* Logic: '<S324>/Logical Operator3' incorporates:
   *  Abs: '<S324>/Abs'
   *  Abs: '<S324>/Abs1'
   *  Abs: '<S324>/Abs2'
   *  Abs: '<S324>/Abs3'
   *  Abs: '<S324>/Abs6'
   *  Abs: '<S324>/Abs7'
   *  Abs: '<S324>/Abs8'
   *  Abs: '<S324>/Abs9'
   *  Constant: '<S333>/Constant'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S335>/Constant'
   *  Constant: '<S336>/Constant'
   *  Constant: '<S337>/Constant'
   *  Constant: '<S338>/Constant'
   *  Constant: '<S339>/Constant'
   *  Constant: '<S340>/Constant'
   *  Constant: '<S341>/Constant'
   *  Constant: '<S342>/Constant'
   *  Constant: '<S343>/Constant'
   *  Logic: '<S324>/Logical Operator'
   *  Logic: '<S324>/Logical Operator1'
   *  Logic: '<S324>/Logical Operator2'
   *  RelationalOperator: '<S333>/Compare'
   *  RelationalOperator: '<S334>/Compare'
   *  RelationalOperator: '<S335>/Compare'
   *  RelationalOperator: '<S336>/Compare'
   *  RelationalOperator: '<S337>/Compare'
   *  RelationalOperator: '<S338>/Compare'
   *  RelationalOperator: '<S339>/Compare'
   *  RelationalOperator: '<S340>/Compare'
   *  RelationalOperator: '<S341>/Compare'
   *  RelationalOperator: '<S342>/Compare'
   *  RelationalOperator: '<S343>/Compare'
   */
  localB->LogicalOperator3 = ((((rtb_FilterCoefficient_idx_0 <=
    localP->maxp_const) && (rtb_SignPreIntegrator_idx_0 <= localP->maxq_const) &&
    (localB->absxk_g <= localP->maxw1_const) && (rtb_IntegralGain_b_idx_1 <=
    localP->maxw2_const) && ((real32_T)fabs(localDW->UD_DSTATE[0]) <=
    localP->maxdw1_const) && ((real32_T)fabs(localDW->UD_DSTATE[1]) <=
    localP->maxdw2_const)) || ((localB->absxk_g <= localP->maxp2_const) &&
    (rtb_IntegralGain_b_idx_1 <= localP->maxq2_const))) && ((real32_T)fabs
    (localB->SignPreSat[0]) <= localP->maxw3_const) && ((real32_T)fabs
    (localB->SignPreSat[1]) <= localP->maxw4_const) &&
    (localB->DataTypeConversion <= localP->minHeightforOF_const));

  /* Outputs for Enabled SubSystem: '<S370>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S394>/Enable'
   */
  /* DataTypeConversion: '<S325>/DataTypeConversionEnable' */
  if (localB->LogicalOperator3) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S394>/Add1' incorporates:
     *  Constant: '<S325>/C'
     *  Delay: '<S325>/MemoryX'
     *  Product: '<S394>/Product'
     *  Reshape: '<S325>/Reshapey'
     */
    for (localB->j = 0; localB->j < 2; localB->j++) {
      localB->fv2[localB->j] = localB->angularvelocitycompensation[localB->j] -
        (((localP->C_Value_n[localB->j + 2] * localDW->MemoryX_DSTATE_l[1] +
           localP->C_Value_n[localB->j] * localDW->MemoryX_DSTATE_l[0]) +
          localP->C_Value_n[localB->j + 4] * localDW->MemoryX_DSTATE_l[2]) +
         localP->C_Value_n[localB->j + 6] * localDW->MemoryX_DSTATE_l[3]);
    }

    /* End of Sum: '<S394>/Add1' */
    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S394>/Product2' incorporates:
       *  Constant: '<S344>/KalmanGainM'
       *  DataTypeConversion: '<S387>/Conversion'
       */
      localB->Product2_n[localB->j] = 0.0F;
      localB->Product2_n[localB->j] += (real32_T)localP->
        KalmanGainM_Value_l[localB->j] * localB->fv2[0];
      localB->Product2_n[localB->j] += (real32_T)localP->
        KalmanGainM_Value_l[localB->j + 4] * localB->fv2[1];
    }

    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      /* Disable for Product: '<S394>/Product2' incorporates:
       *  Outport: '<S394>/deltax'
       */
      localB->Product2_n[0] = localP->deltax_Y0_h;
      localB->Product2_n[1] = localP->deltax_Y0_h;
      localB->Product2_n[2] = localP->deltax_Y0_h;
      localB->Product2_n[3] = localP->deltax_Y0_h;
      localDW->EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S370>/Enabled Subsystem' */

  /* Reshape: '<S325>/Reshapexhat' incorporates:
   *  Delay: '<S325>/MemoryX'
   *  Sum: '<S370>/Add'
   */
  localB->Reshapexhat_p[0] = localB->Product2_n[0] + localDW->MemoryX_DSTATE_l[0];
  localB->Reshapexhat_p[1] = localB->Product2_n[1] + localDW->MemoryX_DSTATE_l[1];
  localB->Reshapexhat_p[2] = localB->Product2_n[2] + localDW->MemoryX_DSTATE_l[2];
  localB->Reshapexhat_p[3] = localB->Product2_n[3] + localDW->MemoryX_DSTATE_l[3];

  /* Chart: '<S3>/Chart' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c6_flightControlSystem == 0U) {
    localDW->is_active_c6_flightControlSystem = 1U;
    localDW->is_c6_flightControlSystem = flightControlSystem_IN_init;
    localDW->temporalCounter_i1 = 0U;
    localB->att = 0.0F;
    localB->z_c = 0.0F;
    localB->v = 0.0F;
    localB->px = 0.0F;
  } else {
    switch (localDW->is_c6_flightControlSystem) {
     case flightControlSystem_IN_attitude:
      if ((rtb_FilterCoefficient_idx_0 < 0.17453292519943295) &&
          ((rtb_SignPreIntegrator_idx_0 < 0.17453292519943295) && ((real32_T)
            sqrt(localB->q * localB->q + localB->p * localB->p) < 5.0F))) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_hover;
      } else {
        localB->att = 1.0F;
        localB->z_c = 0.0F;
        localB->v = 0.0F;
        localB->px = 0.0F;
      }
      break;

     case flightControlSystem_IN_attitude1:
      if (((real32_T)fabs(localB->CastToSingle[1]) < 0.17453292519943295) &&
          (((real32_T)fabs(localB->CastToSingle[2]) < 0.17453292519943295) &&
           ((real32_T)sqrt(localB->q * localB->q + localB->p * localB->p) < 5.0F)))
      {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_hover;
      } else {
        localB->att = 1.0F;
        localB->z_c = 1.0F;
        localB->v = 0.0F;
        localB->px = 0.0F;
      }
      break;

     case flightControlSystem_IN_hover:
      if ((real32_T)fabs(localB->DataTypeConversion2) < 0.2) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_velocity;
      } else if ((!((real32_T)fabs(localB->CastToSingle[1]) <
                    0.17453292519943295)) || ((!((real32_T)fabs
                    (localB->CastToSingle[2]) < 0.17453292519943295)) ||
                  (!((real32_T)sqrt(localB->q * localB->q + localB->p *
          localB->p) < 5.0F)))) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_attitude1;
      } else {
        localB->att = 1.0F;
        localB->z_c = 1.0F;
        localB->v = 0.0F;
        localB->px = 0.0F;
      }
      break;

     case flightControlSystem_IN_init:
      if (localDW->temporalCounter_i1 >= 200U) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_init1;
        localB->att = 0.0F;
        localB->z_c = 0.0F;
        localB->v = 0.0F;
        localB->px = 0.0F;
      }
      break;

     case flightControlSystem_IN_init1:
      if (localB->y_b < 2.8302) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_attitude;
      }
      break;

     case flightControlSystem_IN_position:
      localB->att = 1.0F;
      localB->z_c = 1.0F;
      localB->v = 1.0F;
      localB->px = 1.0F;
      break;

     default:
      /* case IN_velocity: */
      if ((real32_T)sqrt(localB->Reshapexhat_p[0] * localB->Reshapexhat_p[0] +
                         localB->Reshapexhat_p[1] * localB->Reshapexhat_p[1]) <
          0.05) {
        localDW->is_c6_flightControlSystem = flightControlSystem_IN_position;
      } else {
        localB->att = 1.0F;
        localB->z_c = 1.0F;
        localB->v = 1.0F;
        localB->px = 0.0F;
      }
      break;
    }
  }

  /* DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  if ((localB->v > 0.0F) && (localDW->SimplyIntegrateVelocity_PrevResetState <=
       0)) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] =
      localP->SimplyIntegrateVelocity_IC;
    localDW->SimplyIntegrateVelocity_DSTATE[1] =
      localP->SimplyIntegrateVelocity_IC;
  }

  /* DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  localB->SimplyIntegrateVelocity[0] = localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->SimplyIntegrateVelocity[1] = localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* DataTypeConversion: '<S240>/Cast To Single1' incorporates:
   *  Delay: '<S240>/Delay'
   */
  localB->CastToSingle1[0] = (real32_T)localDW->Delay_DSTATE[0];
  localB->CastToSingle1[1] = (real32_T)localDW->Delay_DSTATE[1];
  localB->CastToSingle1[2] = (real32_T)localDW->Delay_DSTATE[2];
  localB->CastToSingle1[3] = (real32_T)localDW->Delay_DSTATE[3];

  /* SignalConversion generated from: '<S1>/To Workspace' */
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localB->SimplyIntegrateVelocity[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localB->SimplyIntegrateVelocity[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[2] =
    localB->DataTypeConversion;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] = localB->CastToSingle[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[4] = localB->CastToSingle[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] = localB->CastToSingle[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Reshapexhat_p[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Reshapexhat_p[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] =
    localB->DataTypeConversion2;
  localB->TmpSignalConversionAtToWorkspaceInport1[9] = localB->p;
  localB->TmpSignalConversionAtToWorkspaceInport1[10] = localB->q;
  localB->TmpSignalConversionAtToWorkspaceInport1[11] = localB->r;
  localB->TmpSignalConversionAtToWorkspaceInport1[12] = localB->CastToSingle1[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[13] = localB->CastToSingle1[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[14] = localB->CastToSingle1[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[15] = localB->CastToSingle1[3];
  localB->TmpSignalConversionAtToWorkspaceInport1[16] = localB->y_b;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspaceInport1[0]);
  }

  /* Math: '<S239>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MathFunction_m[3 * localB->j] = localB->MathFunction[localB->j];
    localB->rtb_MathFunction_m[3 * localB->j + 1] = localB->MathFunction
      [localB->j + 3];
    localB->rtb_MathFunction_m[3 * localB->j + 2] = localB->MathFunction
      [localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->MathFunction[localB->j] = localB->rtb_MathFunction_m[localB->j];
  }

  /* End of Math: '<S239>/Math Function' */

  /* Fcn: '<S328>/Fcn11' */
  localB->Reshape9to3x3columnmajor[0] = localB->Saturation_h *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S328>/Fcn21' incorporates:
   *  Fcn: '<S328>/Fcn22'
   */
  localB->absxk_g =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->t_m;
  localB->Reshape9to3x3columnmajor[1] = localB->absxk_g *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 -
    rtb_Switch_c_tmp * rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S328>/Fcn31' incorporates:
   *  Fcn: '<S328>/Fcn32'
   */
  rtb_IntegralGain_b_idx_1 = rtb_Switch_c_tmp * localB->t_m;
  localB->Reshape9to3x3columnmajor[2] = rtb_IntegralGain_b_idx_1 *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S328>/Fcn12' */
  localB->Reshape9to3x3columnmajor[3] = localB->Saturation_h *
    rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S328>/Fcn22' */
  localB->Reshape9to3x3columnmajor[4] = localB->absxk_g *
    rtb_sincos_o2_idx_0_tmp + rtb_Switch_c_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S328>/Fcn32' */
  localB->Reshape9to3x3columnmajor[5] = rtb_IntegralGain_b_idx_1 *
    rtb_sincos_o2_idx_0_tmp -
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S328>/Fcn13' */
  localB->Reshape9to3x3columnmajor[6] = -localB->t_m;

  /* Fcn: '<S328>/Fcn23' */
  localB->Reshape9to3x3columnmajor[7] =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->Saturation_h;

  /* Fcn: '<S328>/Fcn33' */
  localB->Reshape9to3x3columnmajor[8] = rtb_Switch_c_tmp * localB->Saturation_h;

  /* Fcn: '<S399>/Fcn11' */
  localB->MathFunction_g[0] = localB->Saturation_h *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S399>/Fcn21' incorporates:
   *  Fcn: '<S399>/Fcn22'
   */
  localB->absxk_g =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->t_m;
  localB->MathFunction_g[1] = localB->absxk_g *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 -
    rtb_Switch_c_tmp * rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S399>/Fcn31' incorporates:
   *  Fcn: '<S399>/Fcn32'
   */
  rtb_IntegralGain_b_idx_1 = rtb_Switch_c_tmp * localB->t_m;
  localB->MathFunction_g[2] = rtb_IntegralGain_b_idx_1 *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S399>/Fcn12' */
  localB->MathFunction_g[3] = localB->Saturation_h * rtb_sincos_o2_idx_0_tmp;

  /* Fcn: '<S399>/Fcn22' */
  localB->MathFunction_g[4] = localB->absxk_g * rtb_sincos_o2_idx_0_tmp +
    rtb_Switch_c_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S399>/Fcn32' */
  localB->MathFunction_g[5] = rtb_IntegralGain_b_idx_1 * rtb_sincos_o2_idx_0_tmp
    - LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Fcn: '<S399>/Fcn13' */
  localB->MathFunction_g[6] = -localB->t_m;

  /* Fcn: '<S399>/Fcn23' */
  localB->MathFunction_g[7] =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f *
    localB->Saturation_h;

  /* Fcn: '<S399>/Fcn33' */
  localB->MathFunction_g[8] = rtb_Switch_c_tmp * localB->Saturation_h;

  /* Math: '<S321>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MathFunction_m[3 * localB->j] = localB->MathFunction_g[localB->j];
    localB->rtb_MathFunction_m[3 * localB->j + 1] = localB->
      MathFunction_g[localB->j + 3];
    localB->rtb_MathFunction_m[3 * localB->j + 2] = localB->
      MathFunction_g[localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->MathFunction_g[localB->j] = localB->rtb_MathFunction_m[localB->j];
  }

  /* End of Math: '<S321>/Math Function' */

  /* RelationalOperator: '<S327>/Compare' incorporates:
   *  Constant: '<S327>/Constant'
   */
  rtb_Compare = (localB->DataTypeConversion <=
                 localP->DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S322>/Logical Operator' incorporates:
   *  Constant: '<S329>/Constant'
   *  Constant: '<S330>/Constant'
   *  RelationalOperator: '<S329>/Compare'
   *  RelationalOperator: '<S330>/Compare'
   */
  rtb_Compare_da = ((localB->Switch_c[0] !=
                     localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con)
                    || (localB->Switch_c[1] !=
                        localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));

  /* Sum: '<S322>/Add' incorporates:
   *  Constant: '<S322>/gravity'
   *  Product: '<S322>/Product1'
   *  Reshape: '<S331>/Reshape (9) to [3x3] column-major'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->DataTypeConversion2_k[localB->j] = localB->FIR_IMUaccel[localB->j] -
      ((localB->Reshape9to3x3columnmajor[localB->j + 3] * localP->gravity_Value
        [1] + localB->Reshape9to3x3columnmajor[localB->j] *
        localP->gravity_Value[0]) + localB->Reshape9to3x3columnmajor[localB->j +
       6] * localP->gravity_Value[2]);
  }

  /* End of Sum: '<S322>/Add' */

  /* Product: '<S322>/Product' incorporates:
   *  Gain: '<S322>/gainaccinput1'
   */
  localB->Product[0] = (real32_T)(localP->gainaccinput1_Gain *
    localB->DataTypeConversion2_k[0]) * (real32_T)rtb_Compare_da * (real32_T)
    rtb_Compare;
  localB->Product[1] = (real32_T)(localP->gainaccinput1_Gain *
    localB->DataTypeConversion2_k[1]) * (real32_T)rtb_Compare_da * (real32_T)
    rtb_Compare;

  /* Outputs for Enabled SubSystem: '<S363>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S392>/Enable'
   */
  /* DataTypeConversion: '<S325>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S325>/C'
   *  Delay: '<S325>/MemoryX'
   *  Product: '<S392>/C[k]*xhat[k|k-1]'
   */
  if (localB->LogicalOperator3) {
    localDW->MeasurementUpdate_MODE = true;
    for (localB->j = 0; localB->j < 2; localB->j++) {
      rtb_Saturation_idx_0 = localP->C_Value_n[localB->j + 6] *
        localDW->MemoryX_DSTATE_l[3] + (localP->C_Value_n[localB->j + 4] *
        localDW->MemoryX_DSTATE_l[2] + (localP->C_Value_n[localB->j + 2] *
        localDW->MemoryX_DSTATE_l[1] + localP->C_Value_n[localB->j] *
        localDW->MemoryX_DSTATE_l[0]));

      /* Sum: '<S392>/Sum' incorporates:
       *  Constant: '<S325>/C'
       *  Constant: '<S325>/D'
       *  Delay: '<S325>/MemoryX'
       *  Product: '<S392>/C[k]*xhat[k|k-1]'
       *  Product: '<S392>/D[k]*u[k]'
       *  Reshape: '<S325>/Reshapeu'
       *  Reshape: '<S325>/Reshapey'
       *  Sum: '<S392>/Add1'
       */
      localB->fv2[localB->j] = localB->angularvelocitycompensation[localB->j] -
        (rtb_Saturation_idx_0 + (localP->D_Value_o[localB->j + 2] *
          localB->Product[1] + localP->D_Value_o[localB->j] * localB->Product[0]));
    }

    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S392>/Product3' incorporates:
       *  Constant: '<S344>/KalmanGainL'
       *  DataTypeConversion: '<S386>/Conversion'
       */
      localB->Product3_f[localB->j] = 0.0F;
      localB->Product3_f[localB->j] += (real32_T)localP->
        KalmanGainL_Value[localB->j] * localB->fv2[0];
      localB->Product3_f[localB->j] += (real32_T)localP->
        KalmanGainL_Value[localB->j + 4] * localB->fv2[1];
    }

    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC);
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      /* Disable for Product: '<S392>/Product3' incorporates:
       *  Outport: '<S392>/L*(y[k]-yhat[k|k-1])'
       */
      localB->Product3_f[0] = localP->Lykyhatkk1_Y0_b;
      localB->Product3_f[1] = localP->Lykyhatkk1_Y0_b;
      localB->Product3_f[2] = localP->Lykyhatkk1_Y0_b;
      localB->Product3_f[3] = localP->Lykyhatkk1_Y0_b;
      localDW->MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S363>/MeasurementUpdate' */

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((localB->z_c > 0.0F) && (localDW->DiscreteTimeIntegrator_PrevResetState <=
       0)) {
    localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      localP->DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      localP->DiscreteTimeIntegrator_UpperSat;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <=
        localP->DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localB->DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;

  /* Logic: '<S235>/OR' incorporates:
   *  BusAssignment: '<S1>/Control Mode Update'
   *  Constant: '<S237>/Constant'
   *  RelationalOperator: '<S237>/Compare'
   */
  rtb_Compare = ((rtu_ReferenceValueServerCmds->time_remaining <=
                  localP->ComparewithStoptime_const) ||
                 rtu_ReferenceValueServerCmds->land_drone);

  /* Outputs for Triggered SubSystem: '<S236>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S238>/Trigger'
   */
  if (rtb_Compare && (localZCE->TriggeredSubsystem_Trig_ZCE_k != 1)) {
    /* SignalConversion generated from: '<S238>/X' */
    localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0 =
      localB->SimplyIntegrateVelocity[0];

    /* SignalConversion generated from: '<S238>/Y' */
    localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0 =
      localB->SimplyIntegrateVelocity[1];
    localDW->TriggeredSubsystem_SubsysRanBC_a = 4;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE_k = rtb_Compare;

  /* End of Outputs for SubSystem: '<S236>/Triggered Subsystem' */

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Constant: '<S236>/Landing look-ahead distance'
   *  Constant: '<S5>/xValue'
   *  Constant: '<S5>/yValue'
   *  Constant: '<S5>/zValue'
   *  Logic: '<S5>/NOT'
   *  Sum: '<S236>/Add'
   */
  if (rtb_Compare) {
    localB->w = localB->BufferToMakeInportVirtual_InsertedFor_X_at_inport_0;
    localB->scale = localB->BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0;
    localB->absxk = localB->DataTypeConversion +
      localP->Landinglookaheaddistance_Value;
  } else {
    localB->w = localP->xValue_Value;
    localB->scale = localP->yValue_Value;
    localB->absxk = localP->zValue_Value;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  localB->absxk_g = (real32_T)localB->absxk - localB->DataTypeConversion;

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/w1'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Sum: '<S7>/Sum1'
   */
  rtb_Saturation_idx_0 = ((localP->P_z1_Gain * localB->absxk_g +
    localB->DiscreteTimeIntegrator) - localP->D_z1_Gain *
    localB->DataTypeConversion2) + localP->w1_Value;

  /* Saturate: '<S7>/SaturationThrust1' */
  if (rtb_Saturation_idx_0 > localP->SaturationThrust1_UpperSat) {
    /* Saturate: '<S7>/SaturationThrust1' */
    localB->SaturationThrust1 = localP->SaturationThrust1_UpperSat;
  } else if (rtb_Saturation_idx_0 < localP->SaturationThrust1_LowerSat) {
    /* Saturate: '<S7>/SaturationThrust1' */
    localB->SaturationThrust1 = localP->SaturationThrust1_LowerSat;
  } else {
    /* Saturate: '<S7>/SaturationThrust1' */
    localB->SaturationThrust1 = rtb_Saturation_idx_0;
  }

  /* End of Saturate: '<S7>/SaturationThrust1' */

  /* Switch: '<S3>/Switch_refAtt' */
  if (localB->z_c > localP->Switch_refAtt_Threshold) {
    /* Switch: '<S3>/Switch_refAtt' */
    localB->Switch_refAtt = localB->SaturationThrust1;
  } else {
    /* Switch: '<S3>/Switch_refAtt' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    localB->Switch_refAtt = localP->Constant4_Value;
  }

  /* End of Switch: '<S3>/Switch_refAtt' */

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<S3>/Product2'
   */
  localB->Add = localB->att * localB->Switch_refAtt + localP->Constant_Value_ew;

  /* Sum: '<S12>/Sum1' incorporates:
   *  BusAssignment: '<S1>/Control Mode Update'
   */
  localB->Saturation_h = rtu_ReferenceValueServerCmds->orient_ref[0] -
    localB->CastToSingle[0];

  /* Saturate: '<S12>/Saturation' */
  if (localB->Saturation_h > localP->Saturation_UpperSat) {
    localB->Saturation_h = localP->Saturation_UpperSat;
  } else {
    if (localB->Saturation_h < localP->Saturation_LowerSat) {
      localB->Saturation_h = localP->Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if ((localB->z_c > 0.0F) && (localDW->DiscreteTimeIntegrator_PrevResetState_b <=
       0)) {
    localDW->DiscreteTimeIntegrator_DSTATE_j =
      localP->DiscreteTimeIntegrator_IC_j;
  }

  /* Product: '<S3>/Product3' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S12>/D_yaw'
   *  Gain: '<S12>/P_yaw'
   *  Sum: '<S12>/Sum2'
   */
  localB->Product3_a = ((localP->P_yaw_Gain * localB->Saturation_h +
    localDW->DiscreteTimeIntegrator_DSTATE_j) - localP->D_yaw_Gain * localB->r) *
    localB->z_c;

  /* Sum: '<S11>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  rtb_IntegralGain_b_idx_1 = (real32_T)localB->w -
    localB->SimplyIntegrateVelocity[0];
  LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f = (real32_T)
    localB->scale - localB->SimplyIntegrateVelocity[1];

  /* Saturate: '<S156>/Saturation' incorporates:
   *  Gain: '<S154>/Proportional Gain'
   *  MATLAB Function: '<S11>/Position error transformation (Earth to Body frame)'
   */
  rtb_Saturation_idx_0 =
    (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
     rtb_IntegralGain_b_idx_1 + rtb_sincos_o2_idx_0_tmp *
     LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f) *
    localP->Positioncontroller_P;
  if (rtb_Saturation_idx_0 > localP->Positioncontroller_UpperSaturationLimit) {
    rtb_Saturation_idx_0 = localP->Positioncontroller_UpperSaturationLimit;
  } else {
    if (rtb_Saturation_idx_0 < localP->Positioncontroller_LowerSaturationLimit)
    {
      rtb_Saturation_idx_0 = localP->Positioncontroller_LowerSaturationLimit;
    }
  }

  /* Sum: '<S11>/Sum19' incorporates:
   *  Gain: '<S154>/Proportional Gain'
   *  Product: '<S11>/Product'
   */
  localB->t_m = rtb_Saturation_idx_0 * localB->px - localB->Reshapexhat_p[0];

  /* Saturate: '<S156>/Saturation' incorporates:
   *  Gain: '<S154>/Proportional Gain'
   *  MATLAB Function: '<S11>/Position error transformation (Earth to Body frame)'
   */
  rtb_Saturation_idx_0 = (-rtb_sincos_o2_idx_0_tmp * rtb_IntegralGain_b_idx_1 +
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f) *
    localP->Positioncontroller_P;
  if (rtb_Saturation_idx_0 > localP->Positioncontroller_UpperSaturationLimit) {
    rtb_Saturation_idx_0 = localP->Positioncontroller_UpperSaturationLimit;
  } else {
    if (rtb_Saturation_idx_0 < localP->Positioncontroller_LowerSaturationLimit)
    {
      rtb_Saturation_idx_0 = localP->Positioncontroller_LowerSaturationLimit;
    }
  }

  /* Sum: '<S11>/Sum19' incorporates:
   *  Gain: '<S154>/Proportional Gain'
   *  Product: '<S11>/Product'
   */
  rtb_IntegralGain_b_idx_1 = rtb_Saturation_idx_0 * localB->px -
    localB->Reshapexhat_p[1];

  /* DiscreteIntegrator: '<S199>/Integrator' */
  if ((localB->v > 0.0F) && (localDW->Integrator_PrevResetState <= 0)) {
    localDW->Integrator_DSTATE[0] =
      localP->Velocitycontroller_InitialConditionForIntegrator;
    localDW->Integrator_DSTATE[1] =
      localP->Velocitycontroller_InitialConditionForIntegrator;
  }

  /* Sum: '<S208>/Sum' incorporates:
   *  DiscreteIntegrator: '<S199>/Integrator'
   *  Gain: '<S204>/Proportional Gain'
   */
  localB->SignPreSat[0] = localP->Velocitycontroller_P * localB->t_m +
    localDW->Integrator_DSTATE[0];
  localB->SignPreSat[1] = localP->Velocitycontroller_P *
    rtb_IntegralGain_b_idx_1 + localDW->Integrator_DSTATE[1];

  /* Saturate: '<S206>/Saturation' */
  if (localB->SignPreSat[0] > localP->Velocitycontroller_UpperSaturationLimit) {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[0] = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->SignPreSat[0] <
             localP->Velocitycontroller_LowerSaturationLimit) {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[0] = localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[0] = localB->SignPreSat[0];
  }

  if (localB->SignPreSat[1] > localP->Velocitycontroller_UpperSaturationLimit) {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[1] = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->SignPreSat[1] <
             localP->Velocitycontroller_LowerSaturationLimit) {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[1] = localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    /* Saturate: '<S206>/Saturation' */
    localB->Saturation[1] = localB->SignPreSat[1];
  }

  /* End of Saturate: '<S206>/Saturation' */

  /* DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  rtb_sincos_o2_idx_0_tmp = (localB->Saturation[0] -
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[1] *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0])
    / localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    rtb_sincos_o2_idx_0_tmp +
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0];
  LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f =
    rtb_sincos_o2_idx_0_tmp;
  rtb_sincos_o2_idx_0_tmp = (localB->Saturation[1] -
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[1] *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1])
    / localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];

  /* Switch: '<S3>/Switch_refAtt1' */
  if (localB->v > localP->Switch_refAtt1_Threshold) {
    /* Switch: '<S3>/Switch_refAtt1' incorporates:
     *  DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     *  Gain: '<S11>/Gain'
     */
    localB->Switch_refAtt1[0] = localP->Gain_Gain[0] *
      rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;
    localB->Switch_refAtt1[1] =
      (localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0]
       * rtb_sincos_o2_idx_0_tmp +
       localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1]
       * localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
       [1]) * localP->Gain_Gain[1];
  } else {
    /* Switch: '<S3>/Switch_refAtt1' incorporates:
     *  BusAssignment: '<S1>/Control Mode Update'
     */
    localB->Switch_refAtt1[0] = rtu_ReferenceValueServerCmds->orient_ref[1];
    localB->Switch_refAtt1[1] = rtu_ReferenceValueServerCmds->orient_ref[2];
  }

  /* End of Switch: '<S3>/Switch_refAtt1' */

  /* Sum: '<S8>/Sum1' incorporates:
   *  Gain: '<S52>/Proportional Gain'
   *  Sum: '<S8>/Sum19'
   */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 =
    (localB->Switch_refAtt1[0] - localB->CastToSingle[1]) *
    localP->Anglecontrolloop_P - localB->q;
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 =
    (localB->Switch_refAtt1[1] - localB->CastToSingle[2]) *
    localP->Anglecontrolloop_P - localB->p;

  /* DiscreteIntegrator: '<S97>/Integrator' */
  if ((localB->att > 0.0F) && (localDW->Integrator_PrevResetState_p <= 0)) {
    localDW->Integrator_DSTATE_a[0] =
      localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;
    localDW->Integrator_DSTATE_a[1] =
      localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;
  }

  /* DiscreteIntegrator: '<S92>/Filter' */
  if ((localB->att > 0.0F) && (localDW->Filter_PrevResetState <= 0)) {
    localDW->Filter_DSTATE[0] =
      localP->Angularvelocitycontrolloop_InitialConditionForFilter;
    localDW->Filter_DSTATE[1] =
      localP->Angularvelocitycontrolloop_InitialConditionForFilter;
  }

  /* Gain: '<S100>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S92>/Filter'
   *  Gain: '<S91>/Derivative Gain'
   *  Sum: '<S92>/SumD'
   */
  rtb_Switch_c_tmp = (localP->Angularvelocitycontrolloop_D[0] *
                      rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0
                      - localDW->Filter_DSTATE[0]) *
    localP->Angularvelocitycontrolloop_N[0];

  /* Sum: '<S106>/Sum' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   *  Gain: '<S102>/Proportional Gain'
   *  Gain: '<S91>/Derivative Gain'
   */
  rtb_SignPreIntegrator = (localP->Angularvelocitycontrolloop_P[0] *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
    localDW->Integrator_DSTATE_a[0]) + rtb_Switch_c_tmp;

  /* Saturate: '<S104>/Saturation' */
  if (rtb_SignPreIntegrator >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_Saturation_idx_0 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (rtb_SignPreIntegrator <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    rtb_Saturation_idx_0 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    rtb_Saturation_idx_0 = rtb_SignPreIntegrator;
  }

  /* Gain: '<S100>/Filter Coefficient' */
  rtb_FilterCoefficient_idx_0 = rtb_Switch_c_tmp;

  /* Sum: '<S106>/Sum' */
  rtb_SignPreIntegrator_idx_0 = rtb_SignPreIntegrator;

  /* Gain: '<S100>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S92>/Filter'
   *  Gain: '<S91>/Derivative Gain'
   *  Sum: '<S92>/SumD'
   */
  rtb_Switch_c_tmp = (localP->Angularvelocitycontrolloop_D[1] *
                      rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1
                      - localDW->Filter_DSTATE[1]) *
    localP->Angularvelocitycontrolloop_N[1];

  /* Sum: '<S106>/Sum' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   *  Gain: '<S102>/Proportional Gain'
   *  Gain: '<S91>/Derivative Gain'
   */
  rtb_SignPreIntegrator = (localP->Angularvelocitycontrolloop_P[1] *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 +
    localDW->Integrator_DSTATE_a[1]) + rtb_Switch_c_tmp;

  /* Product: '<S3>/Product' */
  localB->Product_o = localB->att * rtb_Saturation_idx_0;

  /* Switch: '<S114>/Environment Switch' incorporates:
   *  Constant: '<S114>/Switch Control'
   *  ManualSwitch: '<S10>/Manual Switch'
   *  Sum: '<S10>/Add'
   */
  if (localP->SwitchControl_Value) {
    rtb_altitude = localB->Product_o;
  } else {
    if (localP->ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<S10>/Manual Switch' incorporates:
       *  Constant: '<S10>/Pitch correction'
       */
      rtb_Saturation_idx_0 = localP->Pitchcorrection_Value;
    } else {
      /* ManualSwitch: '<S10>/Manual Switch' incorporates:
       *  Constant: '<S10>/zero correction'
       */
      rtb_Saturation_idx_0 = localP->zerocorrection_Value;
    }

    rtb_altitude = localB->Product_o + rtb_Saturation_idx_0;
  }

  /* End of Switch: '<S114>/Environment Switch' */

  /* Saturate: '<S104>/Saturation' */
  if (rtb_SignPreIntegrator >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_SignPreIntegrator_0 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (rtb_SignPreIntegrator <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    rtb_SignPreIntegrator_0 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    rtb_SignPreIntegrator_0 = rtb_SignPreIntegrator;
  }

  /* Product: '<S3>/Product1' */
  localB->Product1 = localB->att * rtb_SignPreIntegrator_0;

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/TorqueTotalThrustToThrustPerMotor'
   *  SignalConversion generated from: '<S10>/Product'
   */
  for (localB->j = 0; localB->j < 4; localB->j++) {
    rtb_Saturation_idx_0 = localP->
      TorqueTotalThrustToThrustPerMotor_Value[localB->j + 12] * localB->Product1
      + (localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 8] *
         rtb_altitude + (localP->TorqueTotalThrustToThrustPerMotor_Value
                         [localB->j + 4] * localB->Product3_a +
                         localP->TorqueTotalThrustToThrustPerMotor_Value
                         [localB->j] * localB->Add));
    localB->fv[localB->j] = rtb_Saturation_idx_0;
  }

  /* End of Product: '<S10>/Product' */

  /* Saturate: '<S13>/Saturation5' incorporates:
   *  Gain: '<S13>/MotorDirections'
   *  Gain: '<S13>/ThrustToMotorCommand'
   */
  rtb_Saturation_idx_0 = localP->ThrustToMotorCommand_Gain * localB->fv[0];
  if (rtb_Saturation_idx_0 > localP->Saturation5_UpperSat) {
    rtb_Saturation_idx_0 = localP->Saturation5_UpperSat;
  } else {
    if (rtb_Saturation_idx_0 < localP->Saturation5_LowerSat) {
      rtb_Saturation_idx_0 = localP->Saturation5_LowerSat;
    }
  }

  /* Gain: '<S13>/MotorDirections' */
  motors_outport[0] = localP->MotorDirections_Gain[0] * rtb_Saturation_idx_0;

  /* Saturate: '<S13>/Saturation5' incorporates:
   *  Gain: '<S13>/MotorDirections'
   *  Gain: '<S13>/ThrustToMotorCommand'
   */
  rtb_Saturation_idx_0 = localP->ThrustToMotorCommand_Gain * localB->fv[1];
  if (rtb_Saturation_idx_0 > localP->Saturation5_UpperSat) {
    rtb_Saturation_idx_0 = localP->Saturation5_UpperSat;
  } else {
    if (rtb_Saturation_idx_0 < localP->Saturation5_LowerSat) {
      rtb_Saturation_idx_0 = localP->Saturation5_LowerSat;
    }
  }

  /* Gain: '<S13>/MotorDirections' */
  motors_outport[1] = localP->MotorDirections_Gain[1] * rtb_Saturation_idx_0;

  /* Saturate: '<S13>/Saturation5' incorporates:
   *  Gain: '<S13>/MotorDirections'
   *  Gain: '<S13>/ThrustToMotorCommand'
   */
  rtb_Saturation_idx_0 = localP->ThrustToMotorCommand_Gain * localB->fv[2];
  if (rtb_Saturation_idx_0 > localP->Saturation5_UpperSat) {
    rtb_Saturation_idx_0 = localP->Saturation5_UpperSat;
  } else {
    if (rtb_Saturation_idx_0 < localP->Saturation5_LowerSat) {
      rtb_Saturation_idx_0 = localP->Saturation5_LowerSat;
    }
  }

  /* Gain: '<S13>/MotorDirections' */
  motors_outport[2] = localP->MotorDirections_Gain[2] * rtb_Saturation_idx_0;

  /* Saturate: '<S13>/Saturation5' incorporates:
   *  Gain: '<S13>/MotorDirections'
   *  Gain: '<S13>/ThrustToMotorCommand'
   */
  rtb_Saturation_idx_0 = localP->ThrustToMotorCommand_Gain * localB->fv[3];
  if (rtb_Saturation_idx_0 > localP->Saturation5_UpperSat) {
    rtb_Saturation_idx_0 = localP->Saturation5_UpperSat;
  } else {
    if (rtb_Saturation_idx_0 < localP->Saturation5_LowerSat) {
      rtb_Saturation_idx_0 = localP->Saturation5_LowerSat;
    }
  }

  /* Gain: '<S13>/MotorDirections' */
  motors_outport[3] = localP->MotorDirections_Gain[3] * rtb_Saturation_idx_0;

  /* ToWorkspace: '<S1>/To Workspace1' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace1_PWORK.LoggedData,
                          &locTime, &motors_outport[0]);
  }

  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Sum: '<S239>/Sum' incorporates:
     *  Constant: '<S239>/gravity'
     *  Math: '<S239>/Math Function'
     *  Product: '<S239>/Product'
     */
    localB->Sum[localB->j] = ((localB->MathFunction[localB->j + 3] *
      localB->FIR_IMUaccel[1] + localB->MathFunction[localB->j] *
      localB->FIR_IMUaccel[0]) + localB->MathFunction[localB->j + 6] *
      localB->FIR_IMUaccel[2]) + localP->gravity_Value_i[localB->j];
  }

  /* Outputs for Enabled SubSystem: '<S267>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S295>/Enable'
   */
  /* Constant: '<S244>/Enable' */
  if (localP->Enable_Value) {
    localDW->MeasurementUpdate_MODE_p = true;

    /* Sum: '<S295>/Sum' incorporates:
     *  Constant: '<S244>/C'
     *  Constant: '<S244>/D'
     *  Delay: '<S244>/MemoryX'
     *  Product: '<S295>/C[k]*xhat[k|k-1]'
     *  Product: '<S295>/D[k]*u[k]'
     *  Reshape: '<S244>/Reshapeu'
     *  Reshape: '<S244>/Reshapey'
     *  Sum: '<S295>/Add1'
     */
    localB->w = localB->DataTypeConversion3 - (((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localP->C_Value[2] * localDW->MemoryX_DSTATE[2]) + localP->D_Value *
      localB->Sum[2]);

    /* Product: '<S295>/Product3' incorporates:
     *  Constant: '<S248>/KalmanGainL'
     *  DataTypeConversion: '<S289>/Conversion'
     */
    localB->Product3[0] = localP->KalmanGainL_Value_b[0] * localB->w;
    localB->Product3[1] = localP->KalmanGainL_Value_b[1] * localB->w;
    localB->Product3[2] = localP->KalmanGainL_Value_b[2] * localB->w;
    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC_p);
  } else {
    if (localDW->MeasurementUpdate_MODE_p) {
      /* Disable for Product: '<S295>/Product3' incorporates:
       *  Outport: '<S295>/L*(y[k]-yhat[k|k-1])'
       */
      localB->Product3[0] = localP->Lykyhatkk1_Y0;
      localB->Product3[1] = localP->Lykyhatkk1_Y0;
      localB->Product3[2] = localP->Lykyhatkk1_Y0;
      localDW->MeasurementUpdate_MODE_p = false;
    }
  }

  /* End of Outputs for SubSystem: '<S267>/MeasurementUpdate' */
  /* Gain: '<S240>/Gain' */
  localB->Gain[0] = localP->Gain_Gain_c * localB->CastToSingle[0];
  localB->Gain[1] = localP->Gain_Gain_c * localB->CastToSingle[1];
  localB->Gain[2] = localP->Gain_Gain_c * localB->CastToSingle[2];

  /* DeadZone: '<S90>/DeadZone' incorporates:
   *  Gain: '<S88>/ZeroGain'
   */
  if (rtb_SignPreIntegrator_idx_0 >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_SignPreIntegrator_0 = rtb_SignPreIntegrator_idx_0 -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (rtb_SignPreIntegrator_idx_0 >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    rtb_SignPreIntegrator_0 = 0.0F;
  } else {
    rtb_SignPreIntegrator_0 = rtb_SignPreIntegrator_idx_0 -
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S88>/NotEqual' incorporates:
   *  Gain: '<S88>/ZeroGain'
   */
  rtb_Compare_da = (localP->ZeroGain_Gain * rtb_SignPreIntegrator_idx_0 !=
                    rtb_SignPreIntegrator_0);

  /* Signum: '<S88>/SignPreSat' */
  if (rtb_SignPreIntegrator_0 < 0.0F) {
    /* DeadZone: '<S90>/DeadZone' */
    rtb_SignPreIntegrator_idx_0 = -1.0F;
  } else if (rtb_SignPreIntegrator_0 > 0.0F) {
    /* DeadZone: '<S90>/DeadZone' */
    rtb_SignPreIntegrator_idx_0 = 1.0F;
  } else if (rtb_SignPreIntegrator_0 == 0.0F) {
    /* DeadZone: '<S90>/DeadZone' */
    rtb_SignPreIntegrator_idx_0 = 0.0F;
  } else {
    /* DeadZone: '<S90>/DeadZone' */
    rtb_SignPreIntegrator_idx_0 = (rtNaNF);
  }

  /* Gain: '<S94>/Integral Gain' */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *=
    localP->Angularvelocitycontrolloop_I[0];

  /* DeadZone: '<S90>/DeadZone' */
  if (rtb_SignPreIntegrator >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_SignPreIntegrator_0 = rtb_SignPreIntegrator -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (rtb_SignPreIntegrator >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    rtb_SignPreIntegrator_0 = 0.0F;
  } else {
    rtb_SignPreIntegrator_0 = rtb_SignPreIntegrator -
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S88>/NotEqual' incorporates:
   *  Gain: '<S88>/ZeroGain'
   */
  rtb_NotEqual_idx_1 = (localP->ZeroGain_Gain * rtb_SignPreIntegrator !=
                        rtb_SignPreIntegrator_0);

  /* Signum: '<S88>/SignPreSat' */
  if (rtb_SignPreIntegrator_0 < 0.0F) {
    rtb_SignPreIntegrator_0 = -1.0F;
  } else if (rtb_SignPreIntegrator_0 > 0.0F) {
    rtb_SignPreIntegrator_0 = 1.0F;
  } else if (rtb_SignPreIntegrator_0 == 0.0F) {
    rtb_SignPreIntegrator_0 = 0.0F;
  } else {
    rtb_SignPreIntegrator_0 = (rtNaNF);
  }

  /* Gain: '<S94>/Integral Gain' */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *=
    localP->Angularvelocitycontrolloop_I[1];

  /* DeadZone: '<S192>/DeadZone' incorporates:
   *  Gain: '<S190>/ZeroGain'
   */
  if (localB->SignPreSat[0] > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_SignPreIntegrator = localB->SignPreSat[0] -
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->SignPreSat[0] >=
             localP->Velocitycontroller_LowerSaturationLimit) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = localB->SignPreSat[0] -
      localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S190>/NotEqual' incorporates:
   *  Gain: '<S190>/ZeroGain'
   */
  rtb_NotEqual_o_idx_0 = (localP->ZeroGain_Gain_g * localB->SignPreSat[0] !=
    rtb_SignPreIntegrator);

  /* Signum: '<S190>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    /* DeadZone: '<S192>/DeadZone' */
    localB->SignPreSat[0] = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    /* DeadZone: '<S192>/DeadZone' */
    localB->SignPreSat[0] = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    /* DeadZone: '<S192>/DeadZone' */
    localB->SignPreSat[0] = 0.0F;
  } else {
    /* DeadZone: '<S192>/DeadZone' */
    localB->SignPreSat[0] = (rtNaNF);
  }

  /* Gain: '<S196>/Integral Gain' */
  localB->t_m *= localP->Velocitycontroller_I;

  /* DeadZone: '<S192>/DeadZone' incorporates:
   *  Gain: '<S190>/ZeroGain'
   */
  if (localB->SignPreSat[1] > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_SignPreIntegrator = localB->SignPreSat[1] -
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->SignPreSat[1] >=
             localP->Velocitycontroller_LowerSaturationLimit) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = localB->SignPreSat[1] -
      localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S190>/NotEqual' incorporates:
   *  Gain: '<S190>/ZeroGain'
   */
  rtb_NotEqual_o_idx_1 = (localP->ZeroGain_Gain_g * localB->SignPreSat[1] !=
    rtb_SignPreIntegrator);

  /* Signum: '<S190>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    rtb_SignPreIntegrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    rtb_SignPreIntegrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = (rtNaNF);
  }

  /* Gain: '<S196>/Integral Gain' */
  rtb_altitude = localP->Velocitycontroller_I * rtb_IntegralGain_b_idx_1;

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  Constant: '<S4>/Wait  3 Seconds'
   *  UnitDelay: '<S223>/Output'
   */
  rtb_LogicalOperator3 = (localDW->Output_DSTATE_a3 > localP->Wait3Seconds_Value);

  /* Switch: '<S227>/Switch' incorporates:
   *  Constant: '<S227>/ '
   */
  if (rtb_LogicalOperator3) {
    localB->w = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localB->scale = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->w = localP->_Value;
    localB->scale = localP->_Value;
  }

  /* End of Switch: '<S227>/Switch' */

  /* Sum: '<S227>/Add' incorporates:
   *  Constant: '<S234>/Constant'
   *  DataTypeConversion: '<S227>/   '
   *  Delay: '<S227>/Delay One Step'
   *  Product: '<S227>/  '
   *  RelationalOperator: '<S234>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->scale ==
    localP->Checkerrorcondition_const) * localDW->DelayOneStep_DSTATE + (real_T)
    (localB->w == localP->Checkerrorcondition_const);

  /* Switch: '<S227>/Switch1' incorporates:
   *  Constant: '<S227>/ Disable OF check'
   *  Constant: '<S233>/Constant'
   *  RelationalOperator: '<S233>/Compare'
   */
  if (rtb_Compare) {
    localB->w = localP->DisableOFcheck_Value;
  } else {
    localB->w = (localDW->DelayOneStep_DSTATE >
                 localP->u0continuousOFerrors_const);
  }

  /* End of Switch: '<S227>/Switch1' */

  /* DiscreteFilter: '<S245>/pressureFilter_IIR' */
  rtb_IntegralGain_b_idx_1 = (((localB->scale_g -
    localP->pressureFilter_IIR_DenCoef[1] * localDW->pressureFilter_IIR_states[0])
    - localP->pressureFilter_IIR_DenCoef[2] * localDW->
    pressureFilter_IIR_states[1]) - localP->pressureFilter_IIR_DenCoef[3] *
    localDW->pressureFilter_IIR_states[2]) / localP->pressureFilter_IIR_DenCoef
    [0];

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S216>/Abs  '
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs2'
   *  Abs: '<S4>/Abs3'
   *  Abs: '<S4>/Abs4'
   *  Abs: '<S4>/Abs5'
   *  Constant: '<S216>/0.5 meters'
   *  Constant: '<S217>/Constant'
   *  Constant: '<S218>/Constant'
   *  Constant: '<S219>/Constant'
   *  Constant: '<S220>/Constant'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S222>/Constant'
   *  Constant: '<S232>/Constant'
   *  DataTypeConversion: '<S227>/Data Type Conversion2'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Logic: '<S226>/AND'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S216>/GreaterThan  '
   *  RelationalOperator: '<S217>/Compare'
   *  RelationalOperator: '<S218>/Compare'
   *  RelationalOperator: '<S219>/Compare'
   *  RelationalOperator: '<S220>/Compare'
   *  RelationalOperator: '<S221>/Compare'
   *  RelationalOperator: '<S222>/Compare'
   *  RelationalOperator: '<S232>/Compare'
   *  Sum: '<S4>/Subtract'
   *  Sum: '<S4>/Subtract1'
   *  Switch: '<S216>/         '
   *  Switch: '<S226>/Switch'
   */
  if (((real32_T)fabs(localB->SimplyIntegrateVelocity[0]) >
       localP->CompareToConstant_const) || ((real32_T)fabs
       (localB->SimplyIntegrateVelocity[1]) > localP->CompareToConstant1_const))
  {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S224>/Action Port'
     */
    flightControlSystem_Geofencingerror(&flag_outport, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if ((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
               localP->CompareToConstant4_const) && ((real32_T)fabs
               (localP->Gain_Gain_ip *
                rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                localB->Reshapexhat_p[0]) > localP->CompareToConstant2_const)) ||
             (((real32_T)fabs(localP->Gain1_Gain_l *
                rtu_Sensors->VisionSensors.opticalFlow_data[1] -
                localB->Reshapexhat_p[1]) > localP->CompareToConstant3_const) &&
              ((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]) >
               localP->CompareToConstant5_const))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    flightControlSystem_Geofencingerror(&flag_outport,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else {
    /* DataTypeConversion: '<S227>/Data Type Conversion2' */
    localB->scale = fabs(localB->w);
    if (localB->scale < 4.503599627370496E+15) {
      if (localB->scale >= 0.5) {
        localB->w = floor(localB->w + 0.5);
      } else {
        localB->w *= 0.0;
      }
    }

    if (rtIsNaN(localB->w) || rtIsInf(localB->w)) {
      localB->w = 0.0;
    } else {
      localB->w = fmod(localB->w, 256.0);
    }

    if ((localB->w < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-localB->w :
         (int32_T)(uint8_T)localB->w) > 0) {
      /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
       *  ActionPort: '<S225>/Action Port'
       */
      flightControlSystem_Geofencingerror(&flag_outport, &localP->Noopticalflow);

      /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
    } else {
      if (rtb_LogicalOperator3) {
        /* Switch: '<S216>/         ' incorporates:
         *  DiscreteFilter: '<S245>/pressureFilter_IIR'
         *  Sum: '<S4>/Difference between  sonar and pressure'
         */
        localB->scale_g = localB->DataTypeConversion -
          (((localP->pressureFilter_IIR_NumCoef[0] * rtb_IntegralGain_b_idx_1 +
             localP->pressureFilter_IIR_NumCoef[1] *
             localDW->pressureFilter_IIR_states[0]) +
            localP->pressureFilter_IIR_NumCoef[2] *
            localDW->pressureFilter_IIR_states[1]) +
           localP->pressureFilter_IIR_NumCoef[3] *
           localDW->pressureFilter_IIR_states[2]);
      } else {
        /* Switch: '<S216>/         ' incorporates:
         *  Constant: '<S216>/    '
         */
        localB->scale_g = localP->_Value_p;
      }

      if ((real32_T)fabs(localB->scale_g) > localP->u5meters_Value) {
        /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
         *  ActionPort: '<S228>/Action Port'
         */
        flightControlSystem_Geofencingerror(&flag_outport,
          &localP->Ultrasoundimproper);

        /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
      } else {
        /* Outputs for IfAction SubSystem: '<S4>/Normal condition  and landing' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        if ((localB->DataTypeConversion >
             localP->Checkifthedroneis03maboveground_const) && rtb_Compare) {
          /* Switch: '<S226>/Switch' incorporates:
           *  Constant: '<S226>/Landed'
           *  Merge: '<S4>/Merge'
           */
          flag_outport = localP->Landed_Value;
        } else {
          /* Merge: '<S4>/Merge' incorporates:
           *  Constant: '<S226>/No_error'
           *  Switch: '<S226>/Switch'
           */
          flag_outport = localP->No_error_Value;
        }

        /* End of Outputs for SubSystem: '<S4>/Normal condition  and landing' */

        /* Update for IfAction SubSystem: '<S4>/Normal condition  and landing' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        /* Update for If: '<S4>/If' */
        srUpdateBC(localDW->Normalconditionandlanding_SubsysRanBC);

        /* End of Update for SubSystem: '<S4>/Normal condition  and landing' */
      }
    }
  }

  /* End of If: '<S4>/If' */

  /* DiscreteFilter: '<S245>/sonarFilter_IIR' incorporates:
   *  Gain: '<S239>/invertzaxisGain'
   *  SignalConversion generated from: '<S314>/Bus Selector5'
   */
  localB->w = ((((real_T)localP->invertzaxisGain_Gain *
                 rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude -
                 localP->sonarFilter_IIR_DenCoef[1] *
                 localDW->sonarFilter_IIR_states[0]) -
                localP->sonarFilter_IIR_DenCoef[2] *
                localDW->sonarFilter_IIR_states[1]) -
               localP->sonarFilter_IIR_DenCoef[3] *
               localDW->sonarFilter_IIR_states[2]) /
    localP->sonarFilter_IIR_DenCoef[0];

  /* Sum: '<S230>/FixPt Sum1' incorporates:
   *  Constant: '<S230>/FixPt Constant'
   *  UnitDelay: '<S223>/Output'
   */
  localDW->Output_DSTATE_a3 += localP->FixPtConstant_Value;

  /* Sum: '<S397>/FixPt Sum1' incorporates:
   *  Constant: '<S397>/FixPt Constant'
   *  UnitDelay: '<S396>/Output'
   */
  localDW->Output_DSTATE_a += localP->FixPtConstant_Value_d;

  /* Switch: '<S398>/FixPt Switch' */
  if (localDW->Output_DSTATE_a > localP->WrapToZero_Threshold_m) {
    /* Sum: '<S397>/FixPt Sum1' incorporates:
     *  Constant: '<S398>/Constant'
     */
    localDW->Output_DSTATE_a = localP->Constant_Value_j;
  }

  /* End of Switch: '<S398>/FixPt Switch' */
  /* Sum: '<S318>/FixPt Sum1' incorporates:
   *  Constant: '<S318>/FixPt Constant'
   *  UnitDelay: '<S316>/Output'
   */
  localDW->Output_DSTATE += localP->FixPtConstant_Value_k;

  /* Switch: '<S319>/FixPt Switch' */
  if (localDW->Output_DSTATE > localP->WrapToZero_Threshold_i) {
    /* Sum: '<S318>/FixPt Sum1' incorporates:
     *  Constant: '<S319>/Constant'
     */
    localDW->Output_DSTATE = localP->Constant_Value_d;
  }

  /* End of Switch: '<S319>/FixPt Switch' */
  /* Update for DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localB->denAccum;

  /* Update for DiscreteTransferFcn: '<S242>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localB->denAccum_c;

  /* Update for DiscreteFilter: '<S242>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->denAccum_f;

  /* Update for DiscreteFir: '<S242>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] = localB->Sum1_f[0];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localB->Sum1_f[1];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localB->Sum1_f[2];

  /* End of Update for DiscreteFir: '<S242>/FIR_IMUaccel' */

  /* Update for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[0] = localB->Reshapexhat_p[0];
  localDW->Delay1_DSTATE[1] = localB->Reshapexhat_p[1];

  /* Update for Delay: '<S239>/Delay2' */
  localDW->Delay2_DSTATE = localB->Reshapexhat[0];

  /* Update for Delay: '<S244>/MemoryX' */
  localDW->icLoad = 0U;

  /* Product: '<S267>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S244>/A'
   *  Delay: '<S244>/MemoryX'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->DataTypeConversion2_k[localB->j] = localP->A_Value[localB->j + 6] *
      localDW->MemoryX_DSTATE[2] + (localP->A_Value[localB->j + 3] *
      localDW->MemoryX_DSTATE[1] + localP->A_Value[localB->j] *
      localDW->MemoryX_DSTATE[0]);
  }

  /* End of Product: '<S267>/A[k]*xhat[k|k-1]' */

  /* Update for Delay: '<S244>/MemoryX' incorporates:
   *  Constant: '<S244>/B'
   *  Product: '<S267>/B[k]*u[k]'
   *  Product: '<S295>/Product3'
   *  Reshape: '<S244>/Reshapeu'
   *  Sum: '<S267>/Add'
   */
  localDW->MemoryX_DSTATE[0] = (localP->B_Value[0] * localB->Sum[2] +
    localB->DataTypeConversion2_k[0]) + localB->Product3[0];
  localDW->MemoryX_DSTATE[1] = (localP->B_Value[1] * localB->Sum[2] +
    localB->DataTypeConversion2_k[1]) + localB->Product3[1];
  localDW->MemoryX_DSTATE[2] = (localP->B_Value[2] * localB->Sum[2] +
    localB->DataTypeConversion2_k[2]) + localB->Product3[2];

  /* Update for Delay: '<S325>/MemoryX' */
  localDW->icLoad_h = 0U;
  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Product: '<S363>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S325>/A'
     *  Delay: '<S325>/MemoryX'
     */
    rtb_Saturation_idx_0 = localP->A_Value_i[localB->j + 12] *
      localDW->MemoryX_DSTATE_l[3] + (localP->A_Value_i[localB->j + 8] *
      localDW->MemoryX_DSTATE_l[2] + (localP->A_Value_i[localB->j + 4] *
      localDW->MemoryX_DSTATE_l[1] + localP->A_Value_i[localB->j] *
      localDW->MemoryX_DSTATE_l[0]));

    /* Product: '<S363>/B[k]*u[k]' incorporates:
     *  Constant: '<S325>/B'
     *  Reshape: '<S325>/Reshapeu'
     */
    localB->fv[localB->j] = localP->B_Value_o[localB->j + 4] * localB->Product[1]
      + localP->B_Value_o[localB->j] * localB->Product[0];

    /* Product: '<S363>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S325>/A'
     */
    localB->fv1[localB->j] = rtb_Saturation_idx_0;
  }

  /* Update for Delay: '<S325>/MemoryX' incorporates:
   *  Sum: '<S363>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localB->fv[0] + localB->fv1[0]) +
    localB->Product3_f[0];
  localDW->MemoryX_DSTATE_l[1] = (localB->fv[1] + localB->fv1[1]) +
    localB->Product3_f[1];
  localDW->MemoryX_DSTATE_l[2] = (localB->fv[2] + localB->fv1[2]) +
    localB->Product3_f[2];
  localDW->MemoryX_DSTATE_l[3] = (localB->fv[3] + localB->fv1[3]) +
    localB->Product3_f[3];
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* Update for DiscreteFilter: '<S324>/IIRgyroz' */
    localB->memOffset = localB->cff * 5;
    localDW->IIRgyroz_states[localB->memOffset + 4] = localDW->
      IIRgyroz_states[localB->memOffset + 3];
    localDW->IIRgyroz_states[localB->memOffset + 3] = localDW->
      IIRgyroz_states[localB->memOffset + 2];
    localDW->IIRgyroz_states[localB->memOffset + 2] = localDW->
      IIRgyroz_states[localB->memOffset + 1];
    localDW->IIRgyroz_states[localB->memOffset + 1] = localDW->
      IIRgyroz_states[localB->memOffset];
    localDW->IIRgyroz_states[localB->memOffset] = localB->IIRgyroz_tmp
      [localB->cff];

    /* Update for UnitDelay: '<S332>/UD' */
    localDW->UD_DSTATE[localB->cff] =
      localB->TmpSignalConversionAtIIRgyrozInport1[localB->cff];

    /* Update for Delay: '<S320>/Delay' */
    localDW->Delay_DSTATE_o[localB->cff] = localB->Reshapexhat_p[localB->cff];

    /* SignalConversion generated from: '<S321>/Product' */
    localB->Switch_c[localB->cff] = localB->Reshapexhat_p[localB->cff];
  }

  /* Product: '<S321>/Product' incorporates:
   *  Math: '<S321>/Math Function'
   *  SignalConversion generated from: '<S321>/Product'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_MathFunction_g_c[localB->j] = localB->MathFunction_g[localB->j +
      6] * localB->DataTypeConversion2 + (localB->MathFunction_g[localB->j + 3] *
      localB->Switch_c[1] + localB->MathFunction_g[localB->j] * localB->
      Switch_c[0]);
  }

  /* End of Product: '<S321>/Product' */

  /* Update for DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] +=
    localP->SimplyIntegrateVelocity_gainval * localB->rtb_MathFunction_g_c[0];
  localDW->SimplyIntegrateVelocity_DSTATE[1] +=
    localP->SimplyIntegrateVelocity_gainval * localB->rtb_MathFunction_g_c[1];
  if (localB->v > 0.0F) {
    localDW->SimplyIntegrateVelocity_PrevResetState = 1;
  } else if (localB->v < 0.0F) {
    localDW->SimplyIntegrateVelocity_PrevResetState = -1;
  } else if (localB->v == 0.0F) {
    localDW->SimplyIntegrateVelocity_PrevResetState = 0;
  } else {
    localDW->SimplyIntegrateVelocity_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S321>/SimplyIntegrateVelocity' */

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += localP->I_pr_Gain * localB->absxk_g *
    localP->DiscreteTimeIntegrator_gainval;
  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      localP->DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      localP->DiscreteTimeIntegrator_UpperSat;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <=
        localP->DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_LowerSat;
    }
  }

  if (localB->z_c > 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState = 1;
  } else if (localB->z_c < 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState = -1;
  } else if (localB->z_c == 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState = 0;
  } else {
    localDW->DiscreteTimeIntegrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/I_yaw'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_j += localP->I_yaw_Gain *
    localB->Saturation_h * localP->DiscreteTimeIntegrator_gainval_n;
  if (localB->z_c > 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState_b = 1;
  } else if (localB->z_c < 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState_b = -1;
  } else if (localB->z_c == 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevResetState_b = 0;
  } else {
    localDW->DiscreteTimeIntegrator_PrevResetState_b = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

  /* DataTypeConversion: '<S190>/DataTypeConv1' incorporates:
   *  DiscreteIntegrator: '<S199>/Integrator'
   */
  if (rtIsNaNF(localB->SignPreSat[0])) {
    rtb_Saturation_idx_0 = 0.0F;
  } else {
    rtb_Saturation_idx_0 = (real32_T)fmod(localB->SignPreSat[0], 256.0);
  }

  /* Signum: '<S190>/SignPreIntegrator' */
  if (localB->t_m < 0.0F) {
    localB->denAccum = -1.0F;
  } else if (localB->t_m > 0.0F) {
    localB->denAccum = 1.0F;
  } else if (localB->t_m == 0.0F) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (rtNaNF);
  }

  /* DataTypeConversion: '<S190>/DataTypeConv2' */
  if (rtIsNaNF(localB->denAccum)) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (real32_T)fmod(localB->denAccum, 256.0);
  }

  /* Switch: '<S190>/Switch' incorporates:
   *  Constant: '<S190>/Constant1'
   *  DataTypeConversion: '<S190>/DataTypeConv1'
   *  DataTypeConversion: '<S190>/DataTypeConv2'
   *  Logic: '<S190>/AND3'
   *  RelationalOperator: '<S190>/Equal1'
   */
  if (rtb_NotEqual_o_idx_0 && ((rtb_Saturation_idx_0 < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-rtb_Saturation_idx_0 : (int32_T)(int8_T)(uint8_T)
        rtb_Saturation_idx_0) == (localB->denAccum < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-localB->denAccum : (int32_T)(int8_T)(uint8_T)
        localB->denAccum))) {
    localB->t_m = localP->Constant1_Value_h;
  }

  /* Update for DiscreteIntegrator: '<S199>/Integrator' */
  localDW->Integrator_DSTATE[0] += localP->Integrator_gainval * localB->t_m;

  /* DataTypeConversion: '<S190>/DataTypeConv1' */
  if (rtIsNaNF(rtb_SignPreIntegrator)) {
    rtb_Saturation_idx_0 = 0.0F;
  } else {
    rtb_Saturation_idx_0 = (real32_T)fmod(rtb_SignPreIntegrator, 256.0);
  }

  /* Signum: '<S190>/SignPreIntegrator' */
  if (rtb_altitude < 0.0F) {
    localB->denAccum = -1.0F;
  } else if (rtb_altitude > 0.0F) {
    localB->denAccum = 1.0F;
  } else if (rtb_altitude == 0.0F) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (rtNaNF);
  }

  /* DataTypeConversion: '<S190>/DataTypeConv2' */
  if (rtIsNaNF(localB->denAccum)) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (real32_T)fmod(localB->denAccum, 256.0);
  }

  /* Switch: '<S190>/Switch' incorporates:
   *  Constant: '<S190>/Constant1'
   *  DataTypeConversion: '<S190>/DataTypeConv1'
   *  DataTypeConversion: '<S190>/DataTypeConv2'
   *  Logic: '<S190>/AND3'
   *  RelationalOperator: '<S190>/Equal1'
   */
  if (rtb_NotEqual_o_idx_1 && ((rtb_Saturation_idx_0 < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-rtb_Saturation_idx_0 : (int32_T)(int8_T)(uint8_T)
        rtb_Saturation_idx_0) == (localB->denAccum < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-localB->denAccum : (int32_T)(int8_T)(uint8_T)
        localB->denAccum))) {
    rtb_altitude = localP->Constant1_Value_h;
  }

  /* Update for DiscreteIntegrator: '<S199>/Integrator' */
  localDW->Integrator_DSTATE[1] += localP->Integrator_gainval * rtb_altitude;
  if (localB->v > 0.0F) {
    localDW->Integrator_PrevResetState = 1;
  } else if (localB->v < 0.0F) {
    localDW->Integrator_PrevResetState = -1;
  } else if (localB->v == 0.0F) {
    localDW->Integrator_PrevResetState = 0;
  } else {
    localDW->Integrator_PrevResetState = 2;
  }

  /* Update for DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_f;

  /* DataTypeConversion: '<S88>/DataTypeConv1' */
  if (rtIsNaNF(rtb_SignPreIntegrator_idx_0)) {
    rtb_Saturation_idx_0 = 0.0F;
  } else {
    rtb_Saturation_idx_0 = (real32_T)fmod(rtb_SignPreIntegrator_idx_0, 256.0);
  }

  /* Signum: '<S88>/SignPreIntegrator' */
  if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 < 0.0F) {
    localB->denAccum = -1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 >
             0.0F) {
    localB->denAccum = 1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 ==
             0.0F) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (rtNaNF);
  }

  /* DataTypeConversion: '<S88>/DataTypeConv2' */
  if (rtIsNaNF(localB->denAccum)) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (real32_T)fmod(localB->denAccum, 256.0);
  }

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S88>/Constant1'
   *  DataTypeConversion: '<S88>/DataTypeConv1'
   *  DataTypeConversion: '<S88>/DataTypeConv2'
   *  Logic: '<S88>/AND3'
   *  RelationalOperator: '<S88>/Equal1'
   */
  if (rtb_Compare_da && ((rtb_Saturation_idx_0 < 0.0F ? (int32_T)(int8_T)
                          -(int8_T)(uint8_T)-rtb_Saturation_idx_0 : (int32_T)
                          (int8_T)(uint8_T)rtb_Saturation_idx_0) ==
                         (localB->denAccum < 0.0F ? (int32_T)(int8_T)-(int8_T)
                          (uint8_T)-localB->denAccum : (int32_T)(int8_T)(uint8_T)
                          localB->denAccum))) {
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 =
      localP->Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' */
  localDW->Integrator_DSTATE_a[0] += localP->Integrator_gainval_d *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* Update for DiscreteTransferFcn: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    rtb_sincos_o2_idx_0_tmp;

  /* DataTypeConversion: '<S88>/DataTypeConv1' */
  if (rtIsNaNF(rtb_SignPreIntegrator_0)) {
    rtb_Saturation_idx_0 = 0.0F;
  } else {
    rtb_Saturation_idx_0 = (real32_T)fmod(rtb_SignPreIntegrator_0, 256.0);
  }

  /* Signum: '<S88>/SignPreIntegrator' */
  if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 < 0.0F) {
    localB->denAccum = -1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 >
             0.0F) {
    localB->denAccum = 1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 ==
             0.0F) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (rtNaNF);
  }

  /* DataTypeConversion: '<S88>/DataTypeConv2' */
  if (rtIsNaNF(localB->denAccum)) {
    localB->denAccum = 0.0F;
  } else {
    localB->denAccum = (real32_T)fmod(localB->denAccum, 256.0);
  }

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S88>/Constant1'
   *  DataTypeConversion: '<S88>/DataTypeConv1'
   *  DataTypeConversion: '<S88>/DataTypeConv2'
   *  Logic: '<S88>/AND3'
   *  RelationalOperator: '<S88>/Equal1'
   */
  if (rtb_NotEqual_idx_1 && ((rtb_Saturation_idx_0 < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-rtb_Saturation_idx_0 : (int32_T)(int8_T)(uint8_T)
        rtb_Saturation_idx_0) == (localB->denAccum < 0.0F ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-localB->denAccum : (int32_T)(int8_T)(uint8_T)
        localB->denAccum))) {
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 =
      localP->Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' */
  localDW->Integrator_DSTATE_a[1] += localP->Integrator_gainval_d *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1;
  if (localB->att > 0.0F) {
    localDW->Integrator_PrevResetState_p = 1;
  } else if (localB->att < 0.0F) {
    localDW->Integrator_PrevResetState_p = -1;
  } else if (localB->att == 0.0F) {
    localDW->Integrator_PrevResetState_p = 0;
  } else {
    localDW->Integrator_PrevResetState_p = 2;
  }

  /* Update for DiscreteIntegrator: '<S92>/Filter' */
  localDW->Filter_DSTATE[0] += localP->Filter_gainval *
    rtb_FilterCoefficient_idx_0;
  localDW->Filter_DSTATE[1] += localP->Filter_gainval * rtb_Switch_c_tmp;
  if (localB->att > 0.0F) {
    localDW->Filter_PrevResetState = 1;
  } else if (localB->att < 0.0F) {
    localDW->Filter_PrevResetState = -1;
  } else if (localB->att == 0.0F) {
    localDW->Filter_PrevResetState = 0;
  } else {
    localDW->Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S92>/Filter' */

  /* Switch: '<S231>/FixPt Switch' */
  if (localDW->Output_DSTATE_a3 > localP->WrapToZero_Threshold) {
    /* Sum: '<S230>/FixPt Sum1' incorporates:
     *  Constant: '<S231>/Constant'
     *  UnitDelay: '<S223>/Output'
     */
    localDW->Output_DSTATE_a3 = localP->Constant_Value_l;
  }

  /* End of Switch: '<S231>/FixPt Switch' */

  /* Update for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localDW->sonarFilter_IIR_states[1];

  /* Update for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localDW->sonarFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S245>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = rtb_IntegralGain_b_idx_1;

  /* Update for DiscreteFilter: '<S245>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localB->w;
}

static void flightControlSystem_SystemCore_step(const uint8_T varargin_1[38400],
  uint8_T varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3
  [19200])
{
  MW_Build_RGB(&varargin_1[0], &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.Normalconditionandlanding_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC_p);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC);

  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, &flightControlSystem_B.FlightControlSystem,
    &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem,
    &flightControlSystem_PrevZCX.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)flightControlSystem_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightControlSystem_M)) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightControlSystem_M->Timing.taskTime0 =
    ((time_T)(++flightControlSystem_M->Timing.clockTick0)) *
    flightControlSystem_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  flightControlSystem_SystemCore_step(imRGB,
    flightControlSystem_B.rtb_PARROTImageConversion_o1_k,
    flightControlSystem_B.rtb_PARROTImageConversion_o2_c,
    flightControlSystem_B.rtb_PARROTImageConversion_o3_m);

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */

  /* RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer[flightControlSystem_DW.RateTransition_ActiveBufIdx
    == 0] = flightControlSystem_P.Constant_Value;
  flightControlSystem_DW.RateTransition_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0);
  rtExtModeUpload(1, (real_T)((flightControlSystem_M->Timing.clockTick1) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  flightControlSystem_M->Timing.clockTick1++;
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  flightControlSystem_P.FlightControlSystem.SaturationSonar_LowerSat =
    rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, -1);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* External mode info */
  flightControlSystem_M->Sizes.checksums[0] = (1590248282U);
  flightControlSystem_M->Sizes.checksums[1] = (3690681833U);
  flightControlSystem_M->Sizes.checksums[2] = (3812461368U);
  flightControlSystem_M->Sizes.checksums[3] = (4109613091U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[39];
    flightControlSystem_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Normalconditionandlanding_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Normalconditionandlanding_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Normalconditionandlanding_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC_a;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC_p;
    systemRan[24] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC_m;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.IfActionSubsystem1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.IfActionSubsystem2_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(flightControlSystem_M->extModeInfo,
      &flightControlSystem_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightControlSystem_M->extModeInfo,
                        flightControlSystem_M->Sizes.checksums);
    rteiSetTPtr(flightControlSystem_M->extModeInfo, rtmGetTPtr
                (flightControlSystem_M));
  }

  /* block I/O */
  (void) memset(((void *) &flightControlSystem_B), 0,
                sizeof(B_flightControlSystem_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&flightControlSystem_Y, 0,
                sizeof(ExtY_flightControlSystem_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightControlSystem_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 40;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));
  flightControlSystem_PrevZCX.FlightControlSystem.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer[0] =
    flightControlSystem_P.RateTransition_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */
  flightControlSystem_FlightControlSystem_Init(flightControlSystem_M,
    &flightControlSystem_B.FlightControlSystem,
    &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem,
    &flightControlSystem_PrevZCX.FlightControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_DW.obj.isInitialized = 1;

  /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
