/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem_data.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.469
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jan 12 23:49:58 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"

/* Block parameters (default storage) */
P_flightControlSystem_T flightControlSystem_P = {
  /* Variable: Sensors
   * Referenced by:
   *   '<S245>/SaturationSonar'
   *   '<S298>/Constant'
   */
  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,
    1.0
  },

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Start of '<Root>/Flight Control System' */
  {
    /* Mask Parameter: outlierBelowFloor_const
     * Referenced by: '<S247>/Constant'
     */
    0.0,

    /* Mask Parameter: ComparewithStoptime_const
     * Referenced by: '<S237>/Constant'
     */
    5.0,

    /* Mask Parameter: Checkerrorcondition_const
     * Referenced by: '<S234>/Constant'
     */
    -1.0,

    /* Mask Parameter: u0continuousOFerrors_const
     * Referenced by: '<S233>/Constant'
     */
    50.0,

    /* Mask Parameter: currentEstimateVeryOffFromPressure_const
     * Referenced by: '<S299>/Constant'
     */
    0.8,

    /* Mask Parameter: currentStateVeryOffsonarflt_const
     * Referenced by: '<S300>/Constant'
     */
    0.4,

    /* Mask Parameter: outlierJump_const
     * Referenced by: '<S301>/Constant'
     */
    0.1,

    /* Mask Parameter: Angularvelocitycontrolloop_D
     * Referenced by: '<S91>/Derivative Gain'
     */
    { 0.00012F, 9.72E-5F },

    /* Mask Parameter: Angularvelocitycontrolloop_I
     * Referenced by: '<S94>/Integral Gain'
     */
    { 0.006F, 0.00486F },

    /* Mask Parameter: Velocitycontroller_I
     * Referenced by: '<S196>/Integral Gain'
     */
    0.1F,

    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
     * Referenced by: '<S332>/UD'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForFilter
     * Referenced by: '<S92>/Filter'
     */
    0.0F,

    /* Mask Parameter: Velocitycontroller_InitialConditionForIntegrator
     * Referenced by: '<S199>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForIntegrator
     * Referenced by: '<S97>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Positioncontroller_LowerSaturationLimit
     * Referenced by: '<S156>/Saturation'
     */
    -0.5F,

    /* Mask Parameter: Velocitycontroller_LowerSaturationLimit
     * Referenced by:
     *   '<S206>/Saturation'
     *   '<S192>/DeadZone'
     */
    -0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_LowerSaturationLimit
     * Referenced by:
     *   '<S104>/Saturation'
     *   '<S90>/DeadZone'
     */
    -0.02F,

    /* Mask Parameter: Angularvelocitycontrolloop_N
     * Referenced by: '<S100>/Filter Coefficient'
     */
    { 70.0F, 70.0F },

    /* Mask Parameter: Positioncontroller_P
     * Referenced by: '<S154>/Proportional Gain'
     */
    0.7F,

    /* Mask Parameter: Velocitycontroller_P
     * Referenced by: '<S204>/Proportional Gain'
     */
    0.2F,

    /* Mask Parameter: Anglecontrolloop_P
     * Referenced by: '<S52>/Proportional Gain'
     */
    4.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_P
     * Referenced by: '<S102>/Proportional Gain'
     */
    { 0.003F, 0.00243F },

    /* Mask Parameter: Positioncontroller_UpperSaturationLimit
     * Referenced by: '<S156>/Saturation'
     */
    0.5F,

    /* Mask Parameter: Velocitycontroller_UpperSaturationLimit
     * Referenced by:
     *   '<S206>/Saturation'
     *   '<S192>/DeadZone'
     */
    0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_UpperSaturationLimit
     * Referenced by:
     *   '<S104>/Saturation'
     *   '<S90>/DeadZone'
     */
    0.02F,

    /* Mask Parameter: Checkifthedroneis03maboveground_const
     * Referenced by: '<S232>/Constant'
     */
    -0.3F,

    /* Mask Parameter: maxp_const
     * Referenced by: '<S335>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxq_const
     * Referenced by: '<S337>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxw1_const
     * Referenced by: '<S339>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxw2_const
     * Referenced by: '<S340>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxdw1_const
     * Referenced by: '<S333>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxdw2_const
     * Referenced by: '<S334>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxp2_const
     * Referenced by: '<S336>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxq2_const
     * Referenced by: '<S338>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxw3_const
     * Referenced by: '<S341>/Constant'
     */
    5.0F,

    /* Mask Parameter: maxw4_const
     * Referenced by: '<S342>/Constant'
     */
    5.0F,

    /* Mask Parameter: minHeightforOF_const
     * Referenced by: '<S343>/Constant'
     */
    -0.4F,

    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S327>/Constant'
     */
    -0.4F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
     * Referenced by: '<S329>/Constant'
     */
    0.0F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
     * Referenced by: '<S330>/Constant'
     */
    0.0F,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S217>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S218>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S219>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S221>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S220>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S222>/Constant'
     */
    0.01F,

    /* Mask Parameter: WrapToZero_Threshold
     * Referenced by: '<S231>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_m
     * Referenced by: '<S398>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_i
     * Referenced by: '<S319>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: CompareToConstant_const_f
     * Referenced by: '<S315>/Constant'
     */
    1U,

    /* Mask Parameter: CompareToConstant_const_l
     * Referenced by: '<S395>/Constant'
     */
    800U,

    /* Expression: 0
     * Referenced by: '<S227>/ Disable OF check'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S227>/ '
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S5>/xValue'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S5>/yValue'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S5>/zValue'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S295>/L*(y[k]-yhat[k|k-1])'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S297>/deltax'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S308>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S309>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S313>/Constant'
     */
    0.0,

    /* Expression: [1 0 0 0]'
     * Referenced by: '<S240>/Delay'
     */
    { 1.0, 0.0, 0.0, 0.0 },

    /* Expression: 0
     * Referenced by: '<S239>/Delay2'
     */
    0.0,

    /* Expression: pInitialization.X0
     * Referenced by: '<S244>/X0'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: pInitialization.M
     * Referenced by: '<S248>/KalmanGainM'
     */
    { 0.011998506869004999, 0.012010894156776782, -0.0049699132113421689 },

    /* Expression: pInitialization.C
     * Referenced by: '<S244>/C'
     */
    { 1.0, 0.0, 0.0 },

    /* Expression: pInitialization.M
     * Referenced by: '<S344>/KalmanGainM'
     */
    { 0.066408162001371535, 0.0, -0.021605460397771489, 0.0, 0.0,
      0.066408162001371535, 0.0, -0.021605460397771493 },

    /* Expression: pInitialization.A
     * Referenced by: '<S244>/A'
     */
    { 1.0, 0.0, 0.0, 0.005, 1.0, 0.0, 0.0, -0.005, 1.0 },

    /* Expression: pInitialization.L
     * Referenced by: '<S344>/KalmanGainL'
     */
    { 0.066516189303360354, 5.23402355848703E-19, -0.021605460397771867,
      -4.8628553107267881E-19, 4.3622439914025292E-18, 0.066516189303360354,
      -4.5659075919712689E-17, -0.021605460397771864 },

    /* Expression: [0 0 -g]
     * Referenced by: '<S322>/gravity'
     */
    { 0.0, 0.0, -9.81 },

    /* Expression: 1
     * Referenced by: '<S322>/gainaccinput1'
     */
    1.0,

    /* Expression: [0 0 g]
     * Referenced by: '<S239>/gravity'
     */
    { 0.0, 0.0, 9.81 },

    /* Expression: pInitialization.B
     * Referenced by: '<S244>/B'
     */
    { 0.0, 0.005, 0.0 },

    /* Expression: pInitialization.D
     * Referenced by: '<S244>/D'
     */
    0.0,

    /* Expression: pInitialization.L
     * Referenced by: '<S248>/KalmanGainL'
     */
    { 0.012058561339788885, 0.01203574372283348, -0.0049699132113421645 },

    /* Expression: 200*3
     * Referenced by: '<S4>/Wait  3 Seconds'
     */
    600.0,

    /* Expression: 0.0
     * Referenced by: '<S227>/Delay One Step'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S216>/0.5 meters'
     */
    0.5,

    /* Expression: Estimator.alt.filterSonarNum
     * Referenced by: '<S245>/sonarFilter_IIR'
     */
    { 3.7568380197861018E-6, 1.1270514059358305E-5, 1.1270514059358305E-5,
      3.7568380197861018E-6 },

    /* Expression: Estimator.alt.filterSonarDen
     * Referenced by: '<S245>/sonarFilter_IIR'
     */
    { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

    /* Expression: 0
     * Referenced by: '<S245>/sonarFilter_IIR'
     */
    0.0,

    /* Expression: -inf
     * Referenced by: '<S245>/SaturationSonar'
     */
    0.0,

    /* Expression: pInitialization.Z
     * Referenced by: '<S344>/CovarianceZ'
     */
    { 1.3281632400274306, 0.0, -0.43210920795542973, 0.0, 0.0,
      1.3281632400274306, 0.0, -0.43210920795542984, -0.43210920795542979, 0.0,
      6.14734986237778, 0.0, 0.0, -0.43210920795542984, 0.0, 6.14734986237778 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S248>/CovarianceZ'
     */
    { 1.1998506869005, 1.2010894156776784, -0.4969913211342169,
      1.2010894156776781, 2.4142317762761745, -1.2071143256205068,
      -0.4969913211342169, -1.2071143256205068, 1.2083605533963118 },

    /* Expression: pInitialization.P0
     * Referenced by: '<S244>/P0'
     */
    { 1.2144219368516851, 1.2156757090228716, -0.50302689276231982,
      1.2156757090228716, 2.4288331285462128, -1.2131561283874874,
      -0.50302689276231982, -1.2131561283874874, 1.2108605533963117 },

    /* Expression: pInitialization.G
     * Referenced by: '<S244>/G'
     */
    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: pInitialization.Q
     * Referenced by: '<S244>/Q'
     */
    { 0.0025, 0.0, 0.0, 0.0, 0.0025, 0.0, 0.0, 0.0, 0.0025 },

    /* Expression: pInitialization.H
     * Referenced by: '<S244>/H'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: pInitialization.N
     * Referenced by: '<S244>/N'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: pInitialization.R
     * Referenced by: '<S244>/R'
     */
    100.0,

    /* Computed Parameter: Pitchcorrection_Value
     * Referenced by: '<S10>/Pitch correction'
     */
    0.002F,

    /* Computed Parameter: zerocorrection_Value
     * Referenced by: '<S10>/zero correction'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain
     * Referenced by: '<S11>/Gain'
     */
    { -1.0F, 1.0F },

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S3>/Constant4'
     */
    -0.61803F,

    /* Computed Parameter: _Value_p
     * Referenced by: '<S216>/    '
     */
    0.0F,

    /* Computed Parameter: X_Y0
     * Referenced by: '<S238>/X'
     */
    0.0F,

    /* Computed Parameter: Y_Y0
     * Referenced by: '<S238>/Y'
     */
    0.0F,

    /* Computed Parameter: Landinglookaheaddistance_Value
     * Referenced by: '<S236>/Landing look-ahead distance'
     */
    0.2F,

    /* Computed Parameter: Gain_Gain_i
     * Referenced by: '<S313>/Gain'
     */
    0.00228F,

    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S317>/Out1'
     */
    0.0F,

    /* Computed Parameter: Lykyhatkk1_Y0_b
     * Referenced by: '<S392>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F,

    /* Computed Parameter: deltax_Y0_h
     * Referenced by: '<S394>/deltax'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_f
     * Referenced by: '<S326>/Gain'
     */
    -1.0F,

    /* Computed Parameter: opticalFlowErrorCorrect_Gain
     * Referenced by: '<S326>/opticalFlowErrorCorrect'
     */
    1.15F,

    /* Computed Parameter: Constant_Value_e
     * Referenced by: '<S242>/Constant'
     */
    { 0.1065F, -0.0065F, 0.9369F },

    /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
     * Referenced by: '<S242>/Assuming that the  preflight calibration was done at level orientation'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: inverseIMU_gain_Gain
     * Referenced by: '<S242>/inverseIMU_gain'
     */
    { 0.994075298F, 0.996184587F, 1.00549F, 1.00139189F, 0.993601203F, 1.00003F
    },

    /* Computed Parameter: LPFFcutoff40Hz1_NumCoef
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz1_DenCoef
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz1_InitialStates
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz1'
     */
    0.0F,

    /* Computed Parameter: LPFFcutoff40Hz_NumCoef
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz_DenCoef
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz_InitialStates
     * Referenced by: '<S242>/LPF Fcutoff = 40Hz'
     */
    0.0F,

    /* Computed Parameter: IIR_IMUgyro_r_NumCoef
     * Referenced by: '<S242>/IIR_IMUgyro_r'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIR_IMUgyro_r_DenCoef
     * Referenced by: '<S242>/IIR_IMUgyro_r'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIR_IMUgyro_r_InitialStates
     * Referenced by: '<S242>/IIR_IMUgyro_r'
     */
    0.0F,

    /* Computed Parameter: FIR_IMUaccel_InitialStates
     * Referenced by: '<S242>/FIR_IMUaccel'
     */
    0.0F,

    /* Computed Parameter: FIR_IMUaccel_Coefficients
     * Referenced by: '<S242>/FIR_IMUaccel'
     */
    { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
      0.0264077242F },

    /* Computed Parameter: Delay1_InitialCondition
     * Referenced by: '<S6>/Delay1'
     */
    0.0F,

    /* Computed Parameter: prsToAltGain_Gain
     * Referenced by: '<S239>/prsToAltGain'
     */
    0.0832137167F,

    /* Computed Parameter: X0_Value_b
     * Referenced by: '<S325>/X0'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: C_Value_n
     * Referenced by: '<S325>/C'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Gain1_Gain
     * Referenced by: '<S323>/Gain1'
     */
    -1.0F,

    /* Computed Parameter: IIRgyroz_NumCoef
     * Referenced by: '<S324>/IIRgyroz'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIRgyroz_DenCoef
     * Referenced by: '<S324>/IIRgyroz'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIRgyroz_InitialStates
     * Referenced by: '<S324>/IIRgyroz'
     */
    0.0F,

    /* Computed Parameter: TSamp_WtEt
     * Referenced by: '<S332>/TSamp'
     */
    200.0F,

    /* Computed Parameter: Delay_InitialCondition_n
     * Referenced by: '<S320>/Delay'
     */
    0.0F,

    /* Computed Parameter: SimplyIntegrateVelocity_gainval
     * Referenced by: '<S321>/SimplyIntegrateVelocity'
     */
    0.005F,

    /* Computed Parameter: SimplyIntegrateVelocity_IC
     * Referenced by: '<S321>/SimplyIntegrateVelocity'
     */
    0.0F,

    /* Expression: Controller.Q2Ts
     * Referenced by: '<S10>/TorqueTotalThrustToThrustPerMotor'
     */
    { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
      -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F,
      5.66592F, 5.66592F, -5.66592F },

    /* Computed Parameter: A_Value_i
     * Referenced by: '<S325>/A'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.005F, 0.0F, 1.0F, 0.0F,
      0.0F, -0.005F, 0.0F, 1.0F },

    /* Computed Parameter: B_Value_o
     * Referenced by: '<S325>/B'
     */
    { 0.005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005F, 0.0F, 0.0F },

    /* Computed Parameter: D_Value_o
     * Referenced by: '<S325>/D'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: w1_Value
     * Referenced by: '<S7>/w1'
     */
    -0.61803F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    2.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    -2.0F,

    /* Computed Parameter: P_z1_Gain
     * Referenced by: '<S7>/P_z1'
     */
    0.8F,

    /* Computed Parameter: D_z1_Gain
     * Referenced by: '<S7>/D_z1'
     */
    0.5F,

    /* Computed Parameter: SaturationThrust1_UpperSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    1.20204329F,

    /* Computed Parameter: SaturationThrust1_LowerSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    -1.20204329F,

    /* Computed Parameter: Switch_refAtt_Threshold
     * Referenced by: '<S3>/Switch_refAtt'
     */
    0.0F,

    /* Computed Parameter: Constant_Value_ew
     * Referenced by: '<S3>/Constant'
     */
    -0.0523F,

    /* Computed Parameter: Saturation_UpperSat
     * Referenced by: '<S12>/Saturation'
     */
    0.52359879F,

    /* Computed Parameter: Saturation_LowerSat
     * Referenced by: '<S12>/Saturation'
     */
    -0.52359879F,

    /* Computed Parameter: P_yaw_Gain
     * Referenced by: '<S12>/P_yaw'
     */
    0.004F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
     * Referenced by: '<S12>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_j
     * Referenced by: '<S12>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: D_yaw_Gain
     * Referenced by: '<S12>/D_yaw'
     */
    0.0012F,

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S199>/Integrator'
     */
    0.005F,

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
     * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
     * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 8.95774746F, -6.95774698F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a
     * Referenced by: '<S11>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    0.0F,

    /* Computed Parameter: Switch_refAtt1_Threshold
     * Referenced by: '<S3>/Switch_refAtt1'
     */
    0.0F,

    /* Computed Parameter: Integrator_gainval_d
     * Referenced by: '<S97>/Integrator'
     */
    0.005F,

    /* Computed Parameter: Filter_gainval
     * Referenced by: '<S92>/Filter'
     */
    0.005F,

    /* Computed Parameter: ThrustToMotorCommand_Gain
     * Referenced by: '<S13>/ThrustToMotorCommand'
     */
    -1530.72681F,

    /* Expression: Vehicle.Motor.maxLimit
     * Referenced by: '<S13>/Saturation5'
     */
    500.0F,

    /* Expression: Vehicle.Motor.minLimit
     * Referenced by: '<S13>/Saturation5'
     */
    10.0F,

    /* Computed Parameter: MotorDirections_Gain
     * Referenced by: '<S13>/MotorDirections'
     */
    { 1.0F, -1.0F, 1.0F, -1.0F },

    /* Computed Parameter: Gain_Gain_c
     * Referenced by: '<S240>/Gain'
     */
    57.2957802F,

    /* Computed Parameter: ZeroGain_Gain
     * Referenced by: '<S88>/ZeroGain'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S88>/Constant1'
     */
    0.0F,

    /* Computed Parameter: ZeroGain_Gain_g
     * Referenced by: '<S190>/ZeroGain'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value_h
     * Referenced by: '<S190>/Constant1'
     */
    0.0F,

    /* Computed Parameter: I_yaw_Gain
     * Referenced by: '<S12>/I_yaw'
     */
    0.004F,

    /* Computed Parameter: I_pr_Gain
     * Referenced by: '<S7>/I_pr'
     */
    0.24F,

    /* Computed Parameter: pressureFilter_IIR_NumCoef
     * Referenced by: '<S245>/pressureFilter_IIR'
     */
    { 3.75683794E-6F, 1.12705138E-5F, 1.12705138E-5F, 3.75683794E-6F },

    /* Computed Parameter: pressureFilter_IIR_DenCoef
     * Referenced by: '<S245>/pressureFilter_IIR'
     */
    { 1.0F, -2.93717074F, 2.87629962F, -0.939098954F },

    /* Computed Parameter: pressureFilter_IIR_InitialStates
     * Referenced by: '<S245>/pressureFilter_IIR'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_ip
     * Referenced by: '<S4>/Gain'
     */
    1.0F,

    /* Computed Parameter: Gain1_Gain_l
     * Referenced by: '<S4>/Gain1'
     */
    1.0F,

    /* Computed Parameter: invertzaxisGain_Gain
     * Referenced by: '<S239>/invertzaxisGain'
     */
    -1.0F,

    /* Computed Parameter: P0_Value_j
     * Referenced by: '<S325>/P0'
     */
    { 1.42263806F, 0.0F, -0.462845951F, 0.0F, 0.0F, 1.42263806F, 0.0F,
      -0.462845951F, -0.462845951F, 0.0F, 6.15735F, 0.0F, 0.0F, -0.462845951F,
      0.0F, 6.15735F },

    /* Computed Parameter: G_Value_a
     * Referenced by: '<S325>/G'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_i
     * Referenced by: '<S325>/Q'
     */
    { 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.01F },

    /* Computed Parameter: H_Value_k
     * Referenced by: '<S325>/H'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: N_Value_d
     * Referenced by: '<S325>/N'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: R_Value_d
     * Referenced by: '<S325>/R'
     */
    { 20.0F, 0.0F, 0.0F, 20.0F },

    /* Computed Parameter: Constant_Value_p
     * Referenced by: '<S240>/Constant'
     */
    0.0F,

    /* Computed Parameter: Output_InitialCondition
     * Referenced by: '<S316>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_b
     * Referenced by: '<S396>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_c
     * Referenced by: '<S223>/Output'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value
     * Referenced by: '<S230>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_l
     * Referenced by: '<S231>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_d
     * Referenced by: '<S397>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S398>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_k
     * Referenced by: '<S318>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_d
     * Referenced by: '<S319>/Constant'
     */
    0U,

    /* Expression: true()
     * Referenced by: '<S244>/Enable'
     */
    1,

    /* Computed Parameter: controlModePosVsOrient_Value
     * Referenced by: '<S1>/controlModePosVsOrient'
     */
    1,

    /* Expression: switch_mode
     * Referenced by: '<S114>/Switch Control'
     */
    0,

    /* Computed Parameter: ManualSwitch_CurrentSetting
     * Referenced by: '<S10>/Manual Switch'
     */
    0U,

    /* Computed Parameter: Landed_Value
     * Referenced by: '<S226>/Landed'
     */
    255U,

    /* Computed Parameter: No_error_Value
     * Referenced by: '<S226>/No_error'
     */
    0U,

    /* Computed Parameter: Disabletemperaturecompensation_CurrentSetting
     * Referenced by: '<S313>/Disable temperature compensation'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S4>/Merge'
     */
    0U,

    /* Start of '<S4>/Ultrasound improper' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S228>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Ultrasound improper' */

    /* Start of '<S4>/No optical flow ' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S225>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/No optical flow ' */

    /* Start of '<S4>/estimator//Optical flow error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S229>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/estimator//Optical flow error' */

    /* Start of '<S4>/Geofencing error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S224>/Constant'
       */
      0U
    }
    /* End of '<S4>/Geofencing error' */
  }
  /* End of '<Root>/Flight Control System' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
