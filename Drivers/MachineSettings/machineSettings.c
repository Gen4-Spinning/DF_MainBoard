/*
 * machineSettings.c
 *
 *  Created on: Apr 11, 2023
 *      Author: harsha
 */

#include "machineSettings.h"

void InitializeMachineSettings(machineSettingsTypeDef *ms){
    ms->delivery_mMin = 80;
    ms->draft = 8;
    ms->lengthLimit_m = 1.1;
    ms->rampDownTime = 5;
    ms->rampDownTime = 5;
}

void CalculateMachineParameters(machineSettingsTypeDef *ms,machineParamsTypeDef *mp){
	float FR_circumference = FR_DIA_MM * 3.14;
	mp->FR_RPM = ms->delivery_mMin * 1000/FR_circumference;
	mp->FR_MotorRPM = mp->FR_RPM * FR_TO_FRMOTOR_GEAR_RATIO;

	float req_BR_surfaceSpeed =  (ms->delivery_mMin*1000)/ms->draft;
	mp->BR_RPM = req_BR_surfaceSpeed/(3.14 * BR_DIA_MM);
	mp->BR_MotorRPM = mp->BR_RPM * BR_TO_BRMOTOR_GEAR_RATIO;

	//TODO Get the roller dias and calculate later
	mp->Creel_MotorRPM = 50;
	mp->currentMtrsRun = 0;
}


uint8_t getMotorCANAddress(uint8_t motor){
	if (motor == FR){
		return 2;
	}else if (motor == BR){
		return 3;
	}else if (motor == CREEL){
		return 4;
	}else{
		return 0;
	}
}

uint8_t GetMotorID_from_CANAddress(uint8_t canAddress){
	if (canAddress == FRONTROLLER_ADDRESS){
		return FR;
	}else if (canAddress == BACKROLLER_ADDRESS){
		return BR;
	}else if (canAddress == CREEL_ADDRESS){
		return CREEL;
	}
	return 6; // return
}
