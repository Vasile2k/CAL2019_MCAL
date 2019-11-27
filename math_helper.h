/* 
 * File:   math_helper.h
 * Author: Vasile2k
 *
 * Created on November 27, 2019, 6:20 PM
 */

#ifndef MATH_HELPER_H
#define	MATH_HELPER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "general.h"
    
T_F16 clamp(T_F16 val, T_F16 min, T_F16 max) __attribute__((always_inline));

#ifdef	__cplusplus
}
#endif

#endif	/* MATH_HELPER_H */

