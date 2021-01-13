/*
 * flightControlSystem_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_eF5OUT33sX0T9pzS8027m),
  sizeof(struct_FIfaVnupBjYAxo1EdNiDlF),
  sizeof(struct_eFnp8sKFNJLN84XLbLzaFF),
  sizeof(struct_8SSZ93PxvPkADZcA4gG8MD),
  sizeof(CommandBus),
  sizeof(extraSensorData_t),
  sizeof(HAL_acc_SI_t),
  sizeof(HAL_gyro_SI_t),
  sizeof(HAL_fifo_gyro_SI_t),
  sizeof(HAL_magn_mG_t),
  sizeof(HAL_pressure_SI_t),
  sizeof(HAL_echo_t),
  sizeof(HAL_list_echo_t),
  sizeof(HAL_ultrasound_SI_t),
  sizeof(HAL_vbat_SI_t),
  sizeof(HAL_acquisition_t),
  sizeof(SensorsBus),
  sizeof(struct_eAf0NJvzCY9HYTXF7bLNgB),
  sizeof(struct_XRMsui9C07VjBvdq1msujB),
  sizeof(struct_hxsmtt0xTZOLDNa2Rz7GAF),
  sizeof(struct_IZWOW0zYvpphl7qLgSfN7E),
  sizeof(struct_q6UUpnZ4gTjFvULFx6Rxa),
  sizeof(struct_OMRgDnJcZuQneKEj9vdTyD),
  sizeof(struct_p3FXZIgqtjF2uqDpmYjb6C),
  sizeof(struct_OSJpyIZcrpXqReVWwh9iuG),
  sizeof(parrot_ImageProcess_flightControlSystem_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_eF5OUT33sX0T9pzS8027m",
  "struct_FIfaVnupBjYAxo1EdNiDlF",
  "struct_eFnp8sKFNJLN84XLbLzaFF",
  "struct_8SSZ93PxvPkADZcA4gG8MD",
  "CommandBus",
  "extraSensorData_t",
  "HAL_acc_SI_t",
  "HAL_gyro_SI_t",
  "HAL_fifo_gyro_SI_t",
  "HAL_magn_mG_t",
  "HAL_pressure_SI_t",
  "HAL_echo_t",
  "HAL_list_echo_t",
  "HAL_ultrasound_SI_t",
  "HAL_vbat_SI_t",
  "HAL_acquisition_t",
  "SensorsBus",
  "struct_eAf0NJvzCY9HYTXF7bLNgB",
  "struct_XRMsui9C07VjBvdq1msujB",
  "struct_hxsmtt0xTZOLDNa2Rz7GAF",
  "struct_IZWOW0zYvpphl7qLgSfN7E",
  "struct_q6UUpnZ4gTjFvULFx6Rxa",
  "struct_OMRgDnJcZuQneKEj9vdTyD",
  "struct_p3FXZIgqtjF2uqDpmYjb6C",
  "struct_OSJpyIZcrpXqReVWwh9iuG",
  "parrot_ImageProcess_flightControlSystem_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&flightControlSystem_B.FlightControlSystem.Sum[0]), 0, 0, 9 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.DataTypeConversion3),
    0, 0, 4 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.Product[0]), 1, 0, 2 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.x), 1, 0, 76 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.Compare), 8, 0, 2 }
  ,

  { (char_T *)(&motors_outport[0]), 1, 0, 4 }
  ,

  { (char_T *)(&flag_outport), 3, 0, 1 }
  ,

  { (char_T *)(&flightControlSystem_DW.obj), 39, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.RateTransition_Buffer[0]), 0, 0, 2 },

  { (char_T *)(&flightControlSystem_DW.RateTransition_ActiveBufIdx), 2, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.Delay_DSTATE[0]), 0,
    0, 12 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Scope_PWORK.LoggedData), 11, 0,
    26 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.LPFFcutoff40Hz1_states), 1, 0,
    57 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.FIR_IMUaccel_circBuf),
    6, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.Output_DSTATE), 7, 0,
    4 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.SimplyIntegrateVelocity_PrevResetState),
    2, 0, 16 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.icLoad), 3, 0, 4 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_MODE),
    8, 0, 4 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&flightControlSystem_P.Sensors), 17, 0, 1 },

  { (char_T *)(&flightControlSystem_P.Constant_Value), 0, 0, 2 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.outlierBelowFloor_const), 0, 0,
    7 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_D[0]),
    1, 0, 43 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.WrapToZero_Threshold),
    7, 0, 5 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.DisableOFcheck_Value),
    0, 0, 135 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.Pitchcorrection_Value),
    1, 0, 257 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Output_InitialCondition), 7, 0,
    9 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.Enable_Value), 8, 0, 3
  },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.ManualSwitch_CurrentSetting), 3,
    0, 5 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Ultrasoundimproper.Constant_Value),
    3, 0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Noopticalflow.Constant_Value), 3,
    0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.estimatorOpticalflowerror.Constant_Value),
    3, 0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Geofencingerror.Constant_Value),
    3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  14U,
  rtPTransitions
};

/* [EOF] flightControlSystem_dt.h */
