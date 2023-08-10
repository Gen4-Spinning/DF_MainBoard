/*
 * BT_Machine.c
 *
 *  Created on: 25-Apr-2023
 *      Author: harsha
 */

#include "BT_Machine.h"


uint8_t BT_MC_generateSettingsMsg(machineSettingsTypeDef *m){
	  char TLV_Buffer[12];
	  uint8_t tlvSize = 0;
	  uint8_t eof_size  = 0;
	  uint8_t initLength = 0;

	  initLength = Init_TXBuf_Frame(SETTINGS_FROM_MC,SUBSTATE_NA,6);

	  generateTLV_I(TLV_Buffer,DELIVERY_M_MIN_BT,m->delivery_mMin);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_INT,initLength+tlvSize);
	  tlvSize += TLV_INT;

	  generateTLV_F(TLV_Buffer,DRAFT_BT,m->draft);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_FLOAT,initLength+tlvSize);
	  tlvSize += TLV_FLOAT;

	  generateTLV_I(TLV_Buffer,LENGTH_LIMIT_M_BT,m->lengthLimit_m);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_INT,initLength+tlvSize);
	  tlvSize += TLV_INT;

	  generateTLV_I(TLV_Buffer,RAMPUP_BT,m->rampUpTime);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_INT,initLength+tlvSize);
	  tlvSize += TLV_INT;

	  generateTLV_F(TLV_Buffer,CREEL_TENSION_FACTOR_BT,m->creelTensionFactor);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_FLOAT,initLength+tlvSize);
	  tlvSize += TLV_FLOAT;

	  generateTLV_I(TLV_Buffer,RAMPDOWN_BT,m->rampDownTime);
	  add_TLVBuf_To_TxBuf(TLV_Buffer,TLV_INT,initLength+tlvSize);
	  tlvSize += TLV_INT;

	  eof_size = addEOF(initLength+tlvSize);
	  correctLengthInFrame(initLength,tlvSize,eof_size);

	  return initLength + tlvSize + eof_size;

}

//FLYER
uint8_t BT_MC_parse_Settings(machineSettingsTypeDef *mspBT){
	//Buffer Rec index 10 onwards is TLVs till 10 + TlvsLength
	TLVStruct_TypeDef T;
	uint8_t TLV_start = 10;
	uint8_t tlvSize = 0;
	uint8_t count = 0;
	uint8_t allSettingsRecieved = 0;

    for (int i=0;i<BT.attributeCnt;i++){
    	tlvSize = parseTLV(&T,TLV_start);
    	TLV_start += tlvSize;
    	switch (T.type){
    		case DELIVERY_M_MIN_BT:
    			mspBT->delivery_mMin = T.value_int;
    			count += 1;
    			break;
    		case DRAFT_BT:
    			mspBT->draft = T.value_f;
    			count += 1;
    			break;
    		case LENGTH_LIMIT_M_BT:
    			mspBT->lengthLimit_m = T.value_int;
    			count += 1;
    			break;
    		case RAMPUP_BT:
    			mspBT->rampUpTime = T.value_int;
    			count += 1;
    			break;
    		case RAMPDOWN_BT:
    			mspBT->rampDownTime = T.value_int;
    			count += 1;
    			break;
    		case CREEL_TENSION_FACTOR_BT:
    			mspBT->creelTensionFactor = T.value_f;
    			count += 1;
    			break;
    	}
    }
    if (count == 6){
    	allSettingsRecieved = 1;
    }

    return allSettingsRecieved;
}

//FLYER
uint8_t BT_MC_Save_Settings(void){
	uint8_t fail;
	fail = WriteMachineSettingsIntoEeprom(&msp_BT);
	if (fail == 0){
		msp.delivery_mMin = msp_BT.delivery_mMin;
		msp.draft = msp_BT.draft;
		msp.lengthLimit_m = msp_BT.lengthLimit_m;
		msp.rampDownTime = msp_BT.rampDownTime;
		msp.rampUpTime = msp_BT.rampUpTime;
		msp.creelTensionFactor = msp_BT.creelTensionFactor;
		//send success msg to APP
	}
	return !fail;
}


uint8_t GetMotorID_from_BTMotor_ID(uint8_t BT_motorID){
	if (BT_motorID == BT_FR){
		return FR;
	}else if (BT_motorID == BT_BR){
		return BR;
	}else if (BT_motorID == BT_CREEL){
		return CREEL;
	}
	return 0;
}

uint8_t Get_BTMotorID_from_Motor_ID(uint8_t motorID){
	if (motorID == FR){
		return BT_FR;
	}else if (motorID == BR){
		return BT_BR;
	}else if (motorID == CREEL){
		return BT_CREEL;
	}
	return 0;
}


uint8_t GetMotorId_from_CarousalID(uint8_t carousalID){
	if (carousalID == BT_FR){
		return FR;
	}else if (carousalID == BT_BR){
		return BR;
	}
	else if (carousalID == BT_CREEL){
		return CREEL;
	}
	return 99;
}
