/* 
 * File:   hal_encoder.h
 * Author: Vasile2kappa
 *
 * Created on March 4, 2020, 6:33 PM
 */

#ifndef HAL_ENCODER_H
#define	HAL_ENCODER_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Returns the distance passed by the car
 * @return the distance in cm
 */
extern T_F16 HAL_f16GetElapsedDistance(void);

#ifdef	__cplusplus
}
#endif

#endif	/* HAL_ENCODER_H */

