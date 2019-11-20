/* 
 * File:   rte.h
 * Author: Vasile2k
 *
 * Created on November 20, 2019, 6:18 PM
 */

#ifndef RTE_H
#define	RTE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "hal_dc.h"
#include "hal_servo.h"
    
#define RTE_vMotorInit HAL_vMotorInit
#define RTE_vMotorSetDir HAL_vMotorSetDir
#define RTE_vMotorSetSpeed HAL_vMotorSetSpeed

#define RTE_vServoInit HAL_vServoInit
#define RTE_vServoSetPosition HAL_vServoSetPosition

#ifdef	__cplusplus
}
#endif

#endif	/* RTE_H */

