/* 
 * File:   hal_servo.h
 * Author: Vasile2k
 *
 * Created on November 20, 2019, 7:15 PM
 */

#ifndef HAL_SERVO_H
#define	HAL_SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general.h"

/**
 * Initializes PWM1 if not already init
 */
extern void HAL_vServoInit(void);

/**
 * Sets the servo position accordingly
 * @param position servo position between 10 and 170
 */
extern void HAL_vServoSetPosition(T_F16 position);

#ifdef	__cplusplus
}
#endif

#endif	/* HAL_SERVO_H */

