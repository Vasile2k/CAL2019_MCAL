/* 
 * File:   asw_movedist.h
 * Author: Vasile2kappa
 *
 * Created on March 4, 2020, 6:45 PM
 */

#ifndef ASW_MOVEDIST_H
#define	ASW_MOVEDIST_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general_types.h"

/*
 * Moves for specified distance
 * The motor has to be initialized before
 * @param dist distance in cm
 */
extern void ASW_moveForDistance(T_F16 dist);

#ifdef	__cplusplus
}
#endif

#endif	/* ASW_MOVEDIST_H */

