/* 
 * File:   hal_obstacle.h
 * Author: Vasile2kappa
 *
 * Created on February 26, 2020, 6:40 PM
 */

#ifndef HAL_OBSTACLE_H
#define	HAL_OBSTACLE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general.h"

/*
 * Returns true if there's any obstacle in front of the car
 */
extern BOOL HAL_bGetObstacle();

/*
 * Sets the flag
 * @param flag - the value of flag to set
 */
extern void _vSetObstacleFlag(BOOL flag);

#ifdef	__cplusplus
}
#endif

#endif	/* HAL_OBSTACLE_H */

