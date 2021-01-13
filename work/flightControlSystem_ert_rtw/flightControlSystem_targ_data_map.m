  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 14;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Sensors
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Constant_Value
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.RateTransition_InitialCondition
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.outlierBelowFloor_const
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.ComparewithStoptime_const
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.Checkerrorcondition_const
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.u0continuousOFerrors_const
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.FlightControlSystem.currentEstimateVeryOffFromPressure_const
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.FlightControlSystem.currentStateVeryOffsonarflt_const
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.FlightControlSystem.outlierJump_const
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_D
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_I
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.Velocitycontroller_I
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteDerivative_ICPrevScaledInput
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_InitialConditionForFilter
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.FlightControlSystem.Velocitycontroller_InitialConditionForIntegrator
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_InitialConditionForIntegrator
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.FlightControlSystem.Positioncontroller_LowerSaturationLimit
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.FlightControlSystem.Velocitycontroller_LowerSaturationLimit
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_LowerSaturationLimit
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_N
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 12;
	
	  ;% flightControlSystem_P.FlightControlSystem.Positioncontroller_P
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.FlightControlSystem.Velocitycontroller_P
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.FlightControlSystem.Anglecontrolloop_P
	  section.data(14).logicalSrcIdx = 23;
	  section.data(14).dtTransOffset = 16;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_P
	  section.data(15).logicalSrcIdx = 24;
	  section.data(15).dtTransOffset = 17;
	
	  ;% flightControlSystem_P.FlightControlSystem.Positioncontroller_UpperSaturationLimit
	  section.data(16).logicalSrcIdx = 25;
	  section.data(16).dtTransOffset = 19;
	
	  ;% flightControlSystem_P.FlightControlSystem.Velocitycontroller_UpperSaturationLimit
	  section.data(17).logicalSrcIdx = 26;
	  section.data(17).dtTransOffset = 20;
	
	  ;% flightControlSystem_P.FlightControlSystem.Angularvelocitycontrolloop_UpperSaturationLimit
	  section.data(18).logicalSrcIdx = 27;
	  section.data(18).dtTransOffset = 21;
	
	  ;% flightControlSystem_P.FlightControlSystem.Checkifthedroneis03maboveground_const
	  section.data(19).logicalSrcIdx = 28;
	  section.data(19).dtTransOffset = 22;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxp_const
	  section.data(20).logicalSrcIdx = 29;
	  section.data(20).dtTransOffset = 23;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxq_const
	  section.data(21).logicalSrcIdx = 30;
	  section.data(21).dtTransOffset = 24;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxw1_const
	  section.data(22).logicalSrcIdx = 31;
	  section.data(22).dtTransOffset = 25;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxw2_const
	  section.data(23).logicalSrcIdx = 32;
	  section.data(23).dtTransOffset = 26;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxdw1_const
	  section.data(24).logicalSrcIdx = 33;
	  section.data(24).dtTransOffset = 27;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxdw2_const
	  section.data(25).logicalSrcIdx = 34;
	  section.data(25).dtTransOffset = 28;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxp2_const
	  section.data(26).logicalSrcIdx = 35;
	  section.data(26).dtTransOffset = 29;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxq2_const
	  section.data(27).logicalSrcIdx = 36;
	  section.data(27).dtTransOffset = 30;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxw3_const
	  section.data(28).logicalSrcIdx = 37;
	  section.data(28).dtTransOffset = 31;
	
	  ;% flightControlSystem_P.FlightControlSystem.maxw4_const
	  section.data(29).logicalSrcIdx = 38;
	  section.data(29).dtTransOffset = 32;
	
	  ;% flightControlSystem_P.FlightControlSystem.minHeightforOF_const
	  section.data(30).logicalSrcIdx = 39;
	  section.data(30).dtTransOffset = 33;
	
	  ;% flightControlSystem_P.FlightControlSystem.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
	  section.data(31).logicalSrcIdx = 40;
	  section.data(31).dtTransOffset = 34;
	
	  ;% flightControlSystem_P.FlightControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
	  section.data(32).logicalSrcIdx = 41;
	  section.data(32).dtTransOffset = 35;
	
	  ;% flightControlSystem_P.FlightControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 36;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant_const
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 37;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant1_const
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 38;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant2_const
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 39;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant4_const
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 40;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant3_const
	  section.data(38).logicalSrcIdx = 47;
	  section.data(38).dtTransOffset = 41;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant5_const
	  section.data(39).logicalSrcIdx = 48;
	  section.data(39).dtTransOffset = 42;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.WrapToZero_Threshold_m
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.WrapToZero_Threshold_i
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant_const_f
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.FlightControlSystem.CompareToConstant_const_l
	  section.data(5).logicalSrcIdx = 53;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.DisableOFcheck_Value
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem._Value
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.xValue_Value
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.yValue_Value
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.FlightControlSystem.zValue_Value
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.FlightControlSystem.Lykyhatkk1_Y0
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.FlightControlSystem.deltax_Y0
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_n
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_k
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.FlightControlSystem.Delay_InitialCondition
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.FlightControlSystem.Delay2_InitialCondition
	  section.data(12).logicalSrcIdx = 65;
	  section.data(12).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.FlightControlSystem.X0_Value
	  section.data(13).logicalSrcIdx = 66;
	  section.data(13).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.FlightControlSystem.KalmanGainM_Value
	  section.data(14).logicalSrcIdx = 67;
	  section.data(14).dtTransOffset = 18;
	
	  ;% flightControlSystem_P.FlightControlSystem.C_Value
	  section.data(15).logicalSrcIdx = 68;
	  section.data(15).dtTransOffset = 21;
	
	  ;% flightControlSystem_P.FlightControlSystem.KalmanGainM_Value_l
	  section.data(16).logicalSrcIdx = 69;
	  section.data(16).dtTransOffset = 24;
	
	  ;% flightControlSystem_P.FlightControlSystem.A_Value
	  section.data(17).logicalSrcIdx = 70;
	  section.data(17).dtTransOffset = 32;
	
	  ;% flightControlSystem_P.FlightControlSystem.KalmanGainL_Value
	  section.data(18).logicalSrcIdx = 71;
	  section.data(18).dtTransOffset = 41;
	
	  ;% flightControlSystem_P.FlightControlSystem.gravity_Value
	  section.data(19).logicalSrcIdx = 72;
	  section.data(19).dtTransOffset = 49;
	
	  ;% flightControlSystem_P.FlightControlSystem.gainaccinput1_Gain
	  section.data(20).logicalSrcIdx = 73;
	  section.data(20).dtTransOffset = 52;
	
	  ;% flightControlSystem_P.FlightControlSystem.gravity_Value_i
	  section.data(21).logicalSrcIdx = 74;
	  section.data(21).dtTransOffset = 53;
	
	  ;% flightControlSystem_P.FlightControlSystem.B_Value
	  section.data(22).logicalSrcIdx = 75;
	  section.data(22).dtTransOffset = 56;
	
	  ;% flightControlSystem_P.FlightControlSystem.D_Value
	  section.data(23).logicalSrcIdx = 76;
	  section.data(23).dtTransOffset = 59;
	
	  ;% flightControlSystem_P.FlightControlSystem.KalmanGainL_Value_b
	  section.data(24).logicalSrcIdx = 77;
	  section.data(24).dtTransOffset = 60;
	
	  ;% flightControlSystem_P.FlightControlSystem.Wait3Seconds_Value
	  section.data(25).logicalSrcIdx = 78;
	  section.data(25).dtTransOffset = 63;
	
	  ;% flightControlSystem_P.FlightControlSystem.DelayOneStep_InitialCondition
	  section.data(26).logicalSrcIdx = 79;
	  section.data(26).dtTransOffset = 64;
	
	  ;% flightControlSystem_P.FlightControlSystem.u5meters_Value
	  section.data(27).logicalSrcIdx = 80;
	  section.data(27).dtTransOffset = 65;
	
	  ;% flightControlSystem_P.FlightControlSystem.sonarFilter_IIR_NumCoef
	  section.data(28).logicalSrcIdx = 81;
	  section.data(28).dtTransOffset = 66;
	
	  ;% flightControlSystem_P.FlightControlSystem.sonarFilter_IIR_DenCoef
	  section.data(29).logicalSrcIdx = 82;
	  section.data(29).dtTransOffset = 70;
	
	  ;% flightControlSystem_P.FlightControlSystem.sonarFilter_IIR_InitialStates
	  section.data(30).logicalSrcIdx = 83;
	  section.data(30).dtTransOffset = 74;
	
	  ;% flightControlSystem_P.FlightControlSystem.SaturationSonar_LowerSat
	  section.data(31).logicalSrcIdx = 84;
	  section.data(31).dtTransOffset = 75;
	
	  ;% flightControlSystem_P.FlightControlSystem.CovarianceZ_Value
	  section.data(32).logicalSrcIdx = 85;
	  section.data(32).dtTransOffset = 76;
	
	  ;% flightControlSystem_P.FlightControlSystem.CovarianceZ_Value_c
	  section.data(33).logicalSrcIdx = 86;
	  section.data(33).dtTransOffset = 92;
	
	  ;% flightControlSystem_P.FlightControlSystem.P0_Value
	  section.data(34).logicalSrcIdx = 87;
	  section.data(34).dtTransOffset = 101;
	
	  ;% flightControlSystem_P.FlightControlSystem.G_Value
	  section.data(35).logicalSrcIdx = 88;
	  section.data(35).dtTransOffset = 110;
	
	  ;% flightControlSystem_P.FlightControlSystem.Q_Value
	  section.data(36).logicalSrcIdx = 89;
	  section.data(36).dtTransOffset = 119;
	
	  ;% flightControlSystem_P.FlightControlSystem.H_Value
	  section.data(37).logicalSrcIdx = 90;
	  section.data(37).dtTransOffset = 128;
	
	  ;% flightControlSystem_P.FlightControlSystem.N_Value
	  section.data(38).logicalSrcIdx = 91;
	  section.data(38).dtTransOffset = 131;
	
	  ;% flightControlSystem_P.FlightControlSystem.R_Value
	  section.data(39).logicalSrcIdx = 92;
	  section.data(39).dtTransOffset = 134;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 92;
      section.data(92)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Pitchcorrection_Value
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.zerocorrection_Value
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain_Gain
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant4_Value
	  section.data(4).logicalSrcIdx = 96;
	  section.data(4).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.FlightControlSystem._Value_p
	  section.data(5).logicalSrcIdx = 97;
	  section.data(5).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.FlightControlSystem.X_Y0
	  section.data(6).logicalSrcIdx = 98;
	  section.data(6).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.FlightControlSystem.Y_Y0
	  section.data(7).logicalSrcIdx = 99;
	  section.data(7).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.FlightControlSystem.Landinglookaheaddistance_Value
	  section.data(8).logicalSrcIdx = 100;
	  section.data(8).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain_Gain_i
	  section.data(9).logicalSrcIdx = 101;
	  section.data(9).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.FlightControlSystem.Out1_Y0
	  section.data(10).logicalSrcIdx = 102;
	  section.data(10).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.FlightControlSystem.Lykyhatkk1_Y0_b
	  section.data(11).logicalSrcIdx = 103;
	  section.data(11).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.FlightControlSystem.deltax_Y0_h
	  section.data(12).logicalSrcIdx = 104;
	  section.data(12).dtTransOffset = 12;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain_Gain_f
	  section.data(13).logicalSrcIdx = 105;
	  section.data(13).dtTransOffset = 13;
	
	  ;% flightControlSystem_P.FlightControlSystem.opticalFlowErrorCorrect_Gain
	  section.data(14).logicalSrcIdx = 106;
	  section.data(14).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_e
	  section.data(15).logicalSrcIdx = 107;
	  section.data(15).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.FlightControlSystem.Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
	  section.data(16).logicalSrcIdx = 108;
	  section.data(16).dtTransOffset = 18;
	
	  ;% flightControlSystem_P.FlightControlSystem.inverseIMU_gain_Gain
	  section.data(17).logicalSrcIdx = 109;
	  section.data(17).dtTransOffset = 24;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz1_NumCoef
	  section.data(18).logicalSrcIdx = 110;
	  section.data(18).dtTransOffset = 30;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz1_DenCoef
	  section.data(19).logicalSrcIdx = 111;
	  section.data(19).dtTransOffset = 32;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz1_InitialStates
	  section.data(20).logicalSrcIdx = 112;
	  section.data(20).dtTransOffset = 34;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz_NumCoef
	  section.data(21).logicalSrcIdx = 113;
	  section.data(21).dtTransOffset = 35;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz_DenCoef
	  section.data(22).logicalSrcIdx = 114;
	  section.data(22).dtTransOffset = 37;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPFFcutoff40Hz_InitialStates
	  section.data(23).logicalSrcIdx = 115;
	  section.data(23).dtTransOffset = 39;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIR_IMUgyro_r_NumCoef
	  section.data(24).logicalSrcIdx = 116;
	  section.data(24).dtTransOffset = 40;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIR_IMUgyro_r_DenCoef
	  section.data(25).logicalSrcIdx = 117;
	  section.data(25).dtTransOffset = 46;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIR_IMUgyro_r_InitialStates
	  section.data(26).logicalSrcIdx = 118;
	  section.data(26).dtTransOffset = 52;
	
	  ;% flightControlSystem_P.FlightControlSystem.FIR_IMUaccel_InitialStates
	  section.data(27).logicalSrcIdx = 119;
	  section.data(27).dtTransOffset = 53;
	
	  ;% flightControlSystem_P.FlightControlSystem.FIR_IMUaccel_Coefficients
	  section.data(28).logicalSrcIdx = 120;
	  section.data(28).dtTransOffset = 54;
	
	  ;% flightControlSystem_P.FlightControlSystem.Delay1_InitialCondition
	  section.data(29).logicalSrcIdx = 121;
	  section.data(29).dtTransOffset = 60;
	
	  ;% flightControlSystem_P.FlightControlSystem.prsToAltGain_Gain
	  section.data(30).logicalSrcIdx = 122;
	  section.data(30).dtTransOffset = 61;
	
	  ;% flightControlSystem_P.FlightControlSystem.X0_Value_b
	  section.data(31).logicalSrcIdx = 123;
	  section.data(31).dtTransOffset = 62;
	
	  ;% flightControlSystem_P.FlightControlSystem.C_Value_n
	  section.data(32).logicalSrcIdx = 124;
	  section.data(32).dtTransOffset = 66;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain1_Gain
	  section.data(33).logicalSrcIdx = 125;
	  section.data(33).dtTransOffset = 74;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIRgyroz_NumCoef
	  section.data(34).logicalSrcIdx = 126;
	  section.data(34).dtTransOffset = 75;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIRgyroz_DenCoef
	  section.data(35).logicalSrcIdx = 127;
	  section.data(35).dtTransOffset = 81;
	
	  ;% flightControlSystem_P.FlightControlSystem.IIRgyroz_InitialStates
	  section.data(36).logicalSrcIdx = 128;
	  section.data(36).dtTransOffset = 87;
	
	  ;% flightControlSystem_P.FlightControlSystem.TSamp_WtEt
	  section.data(37).logicalSrcIdx = 129;
	  section.data(37).dtTransOffset = 88;
	
	  ;% flightControlSystem_P.FlightControlSystem.Delay_InitialCondition_n
	  section.data(38).logicalSrcIdx = 130;
	  section.data(38).dtTransOffset = 89;
	
	  ;% flightControlSystem_P.FlightControlSystem.SimplyIntegrateVelocity_gainval
	  section.data(39).logicalSrcIdx = 131;
	  section.data(39).dtTransOffset = 90;
	
	  ;% flightControlSystem_P.FlightControlSystem.SimplyIntegrateVelocity_IC
	  section.data(40).logicalSrcIdx = 132;
	  section.data(40).dtTransOffset = 91;
	
	  ;% flightControlSystem_P.FlightControlSystem.TorqueTotalThrustToThrustPerMotor_Value
	  section.data(41).logicalSrcIdx = 133;
	  section.data(41).dtTransOffset = 92;
	
	  ;% flightControlSystem_P.FlightControlSystem.A_Value_i
	  section.data(42).logicalSrcIdx = 134;
	  section.data(42).dtTransOffset = 108;
	
	  ;% flightControlSystem_P.FlightControlSystem.B_Value_o
	  section.data(43).logicalSrcIdx = 135;
	  section.data(43).dtTransOffset = 124;
	
	  ;% flightControlSystem_P.FlightControlSystem.D_Value_o
	  section.data(44).logicalSrcIdx = 136;
	  section.data(44).dtTransOffset = 132;
	
	  ;% flightControlSystem_P.FlightControlSystem.w1_Value
	  section.data(45).logicalSrcIdx = 137;
	  section.data(45).dtTransOffset = 136;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_gainval
	  section.data(46).logicalSrcIdx = 138;
	  section.data(46).dtTransOffset = 137;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_IC
	  section.data(47).logicalSrcIdx = 139;
	  section.data(47).dtTransOffset = 138;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_UpperSat
	  section.data(48).logicalSrcIdx = 140;
	  section.data(48).dtTransOffset = 139;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_LowerSat
	  section.data(49).logicalSrcIdx = 141;
	  section.data(49).dtTransOffset = 140;
	
	  ;% flightControlSystem_P.FlightControlSystem.P_z1_Gain
	  section.data(50).logicalSrcIdx = 142;
	  section.data(50).dtTransOffset = 141;
	
	  ;% flightControlSystem_P.FlightControlSystem.D_z1_Gain
	  section.data(51).logicalSrcIdx = 143;
	  section.data(51).dtTransOffset = 142;
	
	  ;% flightControlSystem_P.FlightControlSystem.SaturationThrust1_UpperSat
	  section.data(52).logicalSrcIdx = 144;
	  section.data(52).dtTransOffset = 143;
	
	  ;% flightControlSystem_P.FlightControlSystem.SaturationThrust1_LowerSat
	  section.data(53).logicalSrcIdx = 145;
	  section.data(53).dtTransOffset = 144;
	
	  ;% flightControlSystem_P.FlightControlSystem.Switch_refAtt_Threshold
	  section.data(54).logicalSrcIdx = 146;
	  section.data(54).dtTransOffset = 145;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_ew
	  section.data(55).logicalSrcIdx = 147;
	  section.data(55).dtTransOffset = 146;
	
	  ;% flightControlSystem_P.FlightControlSystem.Saturation_UpperSat
	  section.data(56).logicalSrcIdx = 148;
	  section.data(56).dtTransOffset = 147;
	
	  ;% flightControlSystem_P.FlightControlSystem.Saturation_LowerSat
	  section.data(57).logicalSrcIdx = 149;
	  section.data(57).dtTransOffset = 148;
	
	  ;% flightControlSystem_P.FlightControlSystem.P_yaw_Gain
	  section.data(58).logicalSrcIdx = 150;
	  section.data(58).dtTransOffset = 149;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_gainval_n
	  section.data(59).logicalSrcIdx = 151;
	  section.data(59).dtTransOffset = 150;
	
	  ;% flightControlSystem_P.FlightControlSystem.DiscreteTimeIntegrator_IC_j
	  section.data(60).logicalSrcIdx = 152;
	  section.data(60).dtTransOffset = 151;
	
	  ;% flightControlSystem_P.FlightControlSystem.D_yaw_Gain
	  section.data(61).logicalSrcIdx = 153;
	  section.data(61).dtTransOffset = 152;
	
	  ;% flightControlSystem_P.FlightControlSystem.Integrator_gainval
	  section.data(62).logicalSrcIdx = 154;
	  section.data(62).dtTransOffset = 153;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
	  section.data(63).logicalSrcIdx = 155;
	  section.data(63).dtTransOffset = 154;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
	  section.data(64).logicalSrcIdx = 156;
	  section.data(64).dtTransOffset = 156;
	
	  ;% flightControlSystem_P.FlightControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_a
	  section.data(65).logicalSrcIdx = 157;
	  section.data(65).dtTransOffset = 158;
	
	  ;% flightControlSystem_P.FlightControlSystem.Switch_refAtt1_Threshold
	  section.data(66).logicalSrcIdx = 158;
	  section.data(66).dtTransOffset = 159;
	
	  ;% flightControlSystem_P.FlightControlSystem.Integrator_gainval_d
	  section.data(67).logicalSrcIdx = 159;
	  section.data(67).dtTransOffset = 160;
	
	  ;% flightControlSystem_P.FlightControlSystem.Filter_gainval
	  section.data(68).logicalSrcIdx = 160;
	  section.data(68).dtTransOffset = 161;
	
	  ;% flightControlSystem_P.FlightControlSystem.ThrustToMotorCommand_Gain
	  section.data(69).logicalSrcIdx = 161;
	  section.data(69).dtTransOffset = 162;
	
	  ;% flightControlSystem_P.FlightControlSystem.Saturation5_UpperSat
	  section.data(70).logicalSrcIdx = 162;
	  section.data(70).dtTransOffset = 163;
	
	  ;% flightControlSystem_P.FlightControlSystem.Saturation5_LowerSat
	  section.data(71).logicalSrcIdx = 163;
	  section.data(71).dtTransOffset = 164;
	
	  ;% flightControlSystem_P.FlightControlSystem.MotorDirections_Gain
	  section.data(72).logicalSrcIdx = 164;
	  section.data(72).dtTransOffset = 165;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain_Gain_c
	  section.data(73).logicalSrcIdx = 165;
	  section.data(73).dtTransOffset = 169;
	
	  ;% flightControlSystem_P.FlightControlSystem.ZeroGain_Gain
	  section.data(74).logicalSrcIdx = 166;
	  section.data(74).dtTransOffset = 170;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant1_Value
	  section.data(75).logicalSrcIdx = 167;
	  section.data(75).dtTransOffset = 171;
	
	  ;% flightControlSystem_P.FlightControlSystem.ZeroGain_Gain_g
	  section.data(76).logicalSrcIdx = 168;
	  section.data(76).dtTransOffset = 172;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant1_Value_h
	  section.data(77).logicalSrcIdx = 169;
	  section.data(77).dtTransOffset = 173;
	
	  ;% flightControlSystem_P.FlightControlSystem.I_yaw_Gain
	  section.data(78).logicalSrcIdx = 170;
	  section.data(78).dtTransOffset = 174;
	
	  ;% flightControlSystem_P.FlightControlSystem.I_pr_Gain
	  section.data(79).logicalSrcIdx = 171;
	  section.data(79).dtTransOffset = 175;
	
	  ;% flightControlSystem_P.FlightControlSystem.pressureFilter_IIR_NumCoef
	  section.data(80).logicalSrcIdx = 172;
	  section.data(80).dtTransOffset = 176;
	
	  ;% flightControlSystem_P.FlightControlSystem.pressureFilter_IIR_DenCoef
	  section.data(81).logicalSrcIdx = 173;
	  section.data(81).dtTransOffset = 180;
	
	  ;% flightControlSystem_P.FlightControlSystem.pressureFilter_IIR_InitialStates
	  section.data(82).logicalSrcIdx = 174;
	  section.data(82).dtTransOffset = 184;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain_Gain_ip
	  section.data(83).logicalSrcIdx = 175;
	  section.data(83).dtTransOffset = 185;
	
	  ;% flightControlSystem_P.FlightControlSystem.Gain1_Gain_l
	  section.data(84).logicalSrcIdx = 176;
	  section.data(84).dtTransOffset = 186;
	
	  ;% flightControlSystem_P.FlightControlSystem.invertzaxisGain_Gain
	  section.data(85).logicalSrcIdx = 177;
	  section.data(85).dtTransOffset = 187;
	
	  ;% flightControlSystem_P.FlightControlSystem.P0_Value_j
	  section.data(86).logicalSrcIdx = 178;
	  section.data(86).dtTransOffset = 188;
	
	  ;% flightControlSystem_P.FlightControlSystem.G_Value_a
	  section.data(87).logicalSrcIdx = 179;
	  section.data(87).dtTransOffset = 204;
	
	  ;% flightControlSystem_P.FlightControlSystem.Q_Value_i
	  section.data(88).logicalSrcIdx = 180;
	  section.data(88).dtTransOffset = 220;
	
	  ;% flightControlSystem_P.FlightControlSystem.H_Value_k
	  section.data(89).logicalSrcIdx = 181;
	  section.data(89).dtTransOffset = 236;
	
	  ;% flightControlSystem_P.FlightControlSystem.N_Value_d
	  section.data(90).logicalSrcIdx = 182;
	  section.data(90).dtTransOffset = 244;
	
	  ;% flightControlSystem_P.FlightControlSystem.R_Value_d
	  section.data(91).logicalSrcIdx = 183;
	  section.data(91).dtTransOffset = 252;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_p
	  section.data(92).logicalSrcIdx = 184;
	  section.data(92).dtTransOffset = 256;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Output_InitialCondition
	  section.data(1).logicalSrcIdx = 185;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.Output_InitialCondition_b
	  section.data(2).logicalSrcIdx = 186;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.Output_InitialCondition_c
	  section.data(3).logicalSrcIdx = 187;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 188;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_l
	  section.data(5).logicalSrcIdx = 189;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.FlightControlSystem.FixPtConstant_Value_d
	  section.data(6).logicalSrcIdx = 190;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_j
	  section.data(7).logicalSrcIdx = 191;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.FlightControlSystem.FixPtConstant_Value_k
	  section.data(8).logicalSrcIdx = 192;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.FlightControlSystem.Constant_Value_d
	  section.data(9).logicalSrcIdx = 193;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Enable_Value
	  section.data(1).logicalSrcIdx = 194;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.controlModePosVsOrient_Value
	  section.data(2).logicalSrcIdx = 195;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.SwitchControl_Value
	  section.data(3).logicalSrcIdx = 196;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 197;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.FlightControlSystem.Landed_Value
	  section.data(2).logicalSrcIdx = 198;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.FlightControlSystem.No_error_Value
	  section.data(3).logicalSrcIdx = 199;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.FlightControlSystem.Disabletemperaturecompensation_CurrentSetting
	  section.data(4).logicalSrcIdx = 200;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.FlightControlSystem.Merge_InitialOutput
	  section.data(5).logicalSrcIdx = 201;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Ultrasoundimproper.Constant_Value
	  section.data(1).logicalSrcIdx = 202;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Noopticalflow.Constant_Value
	  section.data(1).logicalSrcIdx = 203;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.estimatorOpticalflowerror.Constant_Value
	  section.data(1).logicalSrcIdx = 204;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.FlightControlSystem.Geofencingerror.Constant_Value
	  section.data(1).logicalSrcIdx = 205;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_B)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.FlightControlSystem.Sum
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product2
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 3;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product3
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.FlightControlSystem.DataTypeConversion3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.FlightControlSystem.Reshapexhat
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.FlightControlSystem.Product
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.FlightControlSystem.x
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.FlightControlSystem.y
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_B.FlightControlSystem.z
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_B.FlightControlSystem.x_c
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_B.FlightControlSystem.y_n
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_B.FlightControlSystem.z_p
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_B.FlightControlSystem.p
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_B.FlightControlSystem.q
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_B.FlightControlSystem.r
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_B.FlightControlSystem.FIR_IMUaccel
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_B.FlightControlSystem.CastToSingle
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 12;
	
	  ;% flightControlSystem_B.FlightControlSystem.DataTypeConversion2
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 15;
	
	  ;% flightControlSystem_B.FlightControlSystem.DataTypeConversion
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 16;
	
	  ;% flightControlSystem_B.FlightControlSystem.angularvelocitycompensation
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 17;
	
	  ;% flightControlSystem_B.FlightControlSystem.Reshapexhat_p
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 19;
	
	  ;% flightControlSystem_B.FlightControlSystem.SimplyIntegrateVelocity
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 23;
	
	  ;% flightControlSystem_B.FlightControlSystem.CastToSingle1
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 25;
	
	  ;% flightControlSystem_B.FlightControlSystem.TmpSignalConversionAtToWorkspaceInport1
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 29;
	
	  ;% flightControlSystem_B.FlightControlSystem.DiscreteTimeIntegrator
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 46;
	
	  ;% flightControlSystem_B.FlightControlSystem.SaturationThrust1
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 47;
	
	  ;% flightControlSystem_B.FlightControlSystem.Switch_refAtt
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 48;
	
	  ;% flightControlSystem_B.FlightControlSystem.Add
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 49;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product3_a
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 50;
	
	  ;% flightControlSystem_B.FlightControlSystem.Saturation
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 51;
	
	  ;% flightControlSystem_B.FlightControlSystem.Switch_refAtt1
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 53;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product_o
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 55;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product1
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 56;
	
	  ;% flightControlSystem_B.FlightControlSystem.Gain
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 57;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product2_n
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 60;
	
	  ;% flightControlSystem_B.FlightControlSystem.Product3_f
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 64;
	
	  ;% flightControlSystem_B.FlightControlSystem.In1
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 68;
	
	  ;% flightControlSystem_B.FlightControlSystem.y_b
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 69;
	
	  ;% flightControlSystem_B.FlightControlSystem.BufferToMakeInportVirtual_InsertedFor_X_at_inport_0
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 70;
	
	  ;% flightControlSystem_B.FlightControlSystem.BufferToMakeInportVirtual_InsertedFor_Y_at_inport_0
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 71;
	
	  ;% flightControlSystem_B.FlightControlSystem.att
	  section.data(35).logicalSrcIdx = 41;
	  section.data(35).dtTransOffset = 72;
	
	  ;% flightControlSystem_B.FlightControlSystem.z_c
	  section.data(36).logicalSrcIdx = 42;
	  section.data(36).dtTransOffset = 73;
	
	  ;% flightControlSystem_B.FlightControlSystem.v
	  section.data(37).logicalSrcIdx = 43;
	  section.data(37).dtTransOffset = 74;
	
	  ;% flightControlSystem_B.FlightControlSystem.px
	  section.data(38).logicalSrcIdx = 44;
	  section.data(38).dtTransOffset = 75;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.FlightControlSystem.Compare
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.FlightControlSystem.LogicalOperator3
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% motors_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 226;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(6) = section;
	    clear section
	  
	      
	    ;% flag_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 227;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(7) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 15;
    sectIdxOffset = 7;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition_Buffer
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition_ActiveBufIdx
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Delay2_DSTATE
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 4;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MemoryX_DSTATE
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.FlightControlSystem.DelayOneStep_DSTATE
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 8;
	
	  ;% flightControlSystem_DW.FlightControlSystem.sonarFilter_IIR_states
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.ToWorkspace1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope2_PWORK_k.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope3_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope1_PWORK_f.LoggedData
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope1_PWORK_p.LoggedData
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope11_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 10;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_hp.LoggedData
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 11;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_b.LoggedData
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 12;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope6_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 23;
	  section.data(14).dtTransOffset = 13;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope5_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 24;
	  section.data(15).dtTransOffset = 14;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope4_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 25;
	  section.data(16).dtTransOffset = 15;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope1_PWORK_k.LoggedData
	  section.data(17).logicalSrcIdx = 26;
	  section.data(17).dtTransOffset = 16;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope10_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 27;
	  section.data(18).dtTransOffset = 17;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope7_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 28;
	  section.data(19).dtTransOffset = 18;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_k.LoggedData
	  section.data(20).logicalSrcIdx = 29;
	  section.data(20).dtTransOffset = 19;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope12_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 30;
	  section.data(21).dtTransOffset = 20;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope3_PWORK_j.LoggedData
	  section.data(22).logicalSrcIdx = 31;
	  section.data(22).dtTransOffset = 21;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope8_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 32;
	  section.data(23).dtTransOffset = 22;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_bo.LoggedData
	  section.data(24).logicalSrcIdx = 33;
	  section.data(24).dtTransOffset = 23;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope9_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 34;
	  section.data(25).dtTransOffset = 24;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK_j.LoggedData
	  section.data(26).logicalSrcIdx = 35;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.LPFFcutoff40Hz1_states
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.LPFFcutoff40Hz_states
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.IIR_IMUgyro_r_states
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.FIR_IMUaccel_states
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Delay1_DSTATE
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 22;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MemoryX_DSTATE_l
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 24;
	
	  ;% flightControlSystem_DW.FlightControlSystem.IIRgyroz_states
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 28;
	
	  ;% flightControlSystem_DW.FlightControlSystem.UD_DSTATE
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 38;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Delay_DSTATE_o
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 40;
	
	  ;% flightControlSystem_DW.FlightControlSystem.SimplyIntegrateVelocity_DSTATE
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 42;
	
	  ;% flightControlSystem_DW.FlightControlSystem.DiscreteTimeIntegrator_DSTATE
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 44;
	
	  ;% flightControlSystem_DW.FlightControlSystem.DiscreteTimeIntegrator_DSTATE_j
	  section.data(12).logicalSrcIdx = 47;
	  section.data(12).dtTransOffset = 45;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Integrator_DSTATE
	  section.data(13).logicalSrcIdx = 48;
	  section.data(13).dtTransOffset = 46;
	
	  ;% flightControlSystem_DW.FlightControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
	  section.data(14).logicalSrcIdx = 49;
	  section.data(14).dtTransOffset = 48;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Integrator_DSTATE_a
	  section.data(15).logicalSrcIdx = 50;
	  section.data(15).dtTransOffset = 50;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Filter_DSTATE
	  section.data(16).logicalSrcIdx = 51;
	  section.data(16).dtTransOffset = 52;
	
	  ;% flightControlSystem_DW.FlightControlSystem.pressureFilter_IIR_states
	  section.data(17).logicalSrcIdx = 52;
	  section.data(17).dtTransOffset = 54;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.FIR_IMUaccel_circBuf
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Output_DSTATE
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Output_DSTATE_a
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Output_DSTATE_a3
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.is_c6_flightControlSystem
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.SimplyIntegrateVelocity_PrevResetState
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.DiscreteTimeIntegrator_PrevResetState
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.DiscreteTimeIntegrator_PrevResetState_b
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Integrator_PrevResetState
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Integrator_PrevResetState_p
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Filter_PrevResetState
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_DW.FlightControlSystem.IfActionSubsystem2_SubsysRanBC
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_DW.FlightControlSystem.IfActionSubsystem1_SubsysRanBC
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% flightControlSystem_DW.FlightControlSystem.IfActionSubsystem_SubsysRanBC
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
	  ;% flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_SubsysRanBC_m
	  section.data(13).logicalSrcIdx = 77;
	  section.data(13).dtTransOffset = 12;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_SubsysRanBC_p
	  section.data(14).logicalSrcIdx = 78;
	  section.data(14).dtTransOffset = 13;
	
	  ;% flightControlSystem_DW.FlightControlSystem.TriggeredSubsystem_SubsysRanBC_a
	  section.data(15).logicalSrcIdx = 79;
	  section.data(15).dtTransOffset = 14;
	
	  ;% flightControlSystem_DW.FlightControlSystem.Normalconditionandlanding_SubsysRanBC
	  section.data(16).logicalSrcIdx = 80;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.icLoad
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.icLoad_h
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.is_active_c6_flightControlSystem
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_MODE
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.FlightControlSystem.EnabledSubsystem_MODE_m
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.FlightControlSystem.MeasurementUpdate_MODE_p
	  section.data(4).logicalSrcIdx = 88;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1590248282;
  targMap.checksum1 = 3690681833;
  targMap.checksum2 = 3812461368;
  targMap.checksum3 = 4109613091;

