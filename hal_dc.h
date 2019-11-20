/* 
 * File:   hal_dc.h
 * Author: Vasile2k
 *
 * Created on November 20, 2019, 6:13 PM
 */

#ifndef HAL_DC_H
#define	HAL_DC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general.h"
    
typedef enum _MotorDir { FORWARD = 0, BACKWARD = 1 } MotorDir;

extern void HAL_vMotorInit(void);
extern void HAL_vMotorSetDir(MotorDir dir);
extern void HAL_vMotorSetSpeed(T_F16 speed);

#ifdef	__cplusplus
}
#endif

#endif	/* HAL_DC_H */

