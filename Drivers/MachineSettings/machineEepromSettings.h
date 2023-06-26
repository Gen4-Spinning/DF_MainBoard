/*
 * EepromSettings.h
 *
 *  Created on: 06-Mar-2023
 *      Author: harsha
 */

#ifndef INC_EEPROMSETTINGS_H_
#define INC_EEPROMSETTINGS_H_

//Addresses
//Dont let a address go across address 32 and its multiples. Thats one page.
#define DF_DELIVERY_M_MIN_ADDR 0X02 //int
#define DF_DRAFT_ADDR 0X06 // float
#define DF_LENGTH_LIMIT_M 0X0A //int
#define RAMPUP_TIME_ADDR 0X0C //int
#define RAMPDOWN_TIME_ADDR 0X0E // int

//DEFAULTS
#define DEFAULT_DELIVERY_M_MIN 80
#define DEFAULT_DRAFT 8
#define DEFAULT_LENGTHLIMIT 800
#define DEFAULT_RAMPUP_TIME 6		// in sec
#define DEFAULT_RAMPDOWN_TIME 6	// in sec


#endif /* INC_EEPROMSETTINGS_H_ */
