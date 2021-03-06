/* 
 * File:   hal_lf.h
 * Author: Vasile2kappa
 * 
 * Line follower module
 * 
 * Created on December 11, 2019, 6:16 PM
 */

#ifndef HAL_LF_H
#define	HAL_LF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general.h"
#include "mcal_gpio.h"


/**
 * Function to set the state of the line follower as input/output
 * @param The value to be set, 1 - input, 0 - output
 */
extern void HAL_vSetLineFollower(BOOL);

/**
 * Function to write a logic value to the line follower module
 * @param INPUT or OUTPUT
 */
extern void HAL_vWriteLineFollower(BOOL);

/**
 * Function to get the value of the line follower module
 * @return the value as the 6 least significant bits
 */
extern T_U8 HAL_vGetLineFollower();


#ifdef	__cplusplus
}
#endif

#endif	/* HAL_LF_H */

