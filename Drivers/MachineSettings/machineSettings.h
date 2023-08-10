/*
 * machineSettings.h
 *
 *  Created on: Apr 11, 2023
 *      Author: harsha
 */

#ifndef MACHINESETTINGS_H_
#define MACHINESETTINGS_H_

#include "stdio.h"
#include "FDCAN.h"

//all Structs with arrays have to follow this Form
#define FR 0
#define BR 1
#define CREEL 2


#define FR_DIA_MM 40
#define BR_DIA_MM 30
#define FR_TO_FRMOTOR_GEAR_RATIO 1
#define BR_TO_BRMOTOR_GEAR_RATIO 6.91
#define BR_TO_SR_BREAK_DRAFT 1.5
#define CREEL_PULLEY_DIA 55
#define SLIVER_WIDTH 14

typedef struct machineSettings_Struct{
    int delivery_mMin;
    float draft;
    int lengthLimit_m;
    int rampUpTime;
    int rampDownTime;
    float creelTensionFactor;

}machineSettingsTypeDef;

typedef struct machineParamaters_Struct{
    uint16_t FR_MotorRPM;
    uint16_t BR_MotorRPM;
    uint16_t Creel_MotorRPM;

    float reqDraft_FR_TO_SR;

    float FR_SurfaceSpeed;
    float SR_SurfaceSpeed;
    float req_BR_SurfaceSpeed;
    float req_Creel_SurfaceSpeed;

    float usedCreelDia;

    float FR_RPM;
	float BR_RPM;

	float currentMtrsRun;
	float totalPower;
}machineParamsTypeDef;

extern machineSettingsTypeDef msp;
extern machineSettingsTypeDef msp_BT;
extern machineParamsTypeDef mcParams;

// Eeprom MachineSettings
void ReadMachineSettingsFromEeprom(machineSettingsTypeDef *m);
uint8_t WriteMachineSettingsIntoEeprom(machineSettingsTypeDef *m);
uint8_t CheckMachineSettings(machineSettingsTypeDef* m);
void LoadDefaultMachineSettings(machineSettingsTypeDef* m);

//otherFns
void InitializeMachineSettings(machineSettingsTypeDef *ms);
void CalculateMachineParameters(machineSettingsTypeDef *ms,machineParamsTypeDef *mp);

uint8_t getMotorCANAddress(uint8_t motor);
uint8_t GetMotorID_from_CANAddress(uint8_t canAddress);


#endif /* MACHINESETTINGS_H_ */
