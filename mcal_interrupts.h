/* 
 * File:   mcal_interrupts.h
 * Author: uia94881
 *
 * Created on August 3, 2018, 11:17 AM
 */

#ifndef MCAL_INTERRUPTS_H
#define	MCAL_INTERRUPTS_H

#include "general.h"
#include "hal_obstacle.h" // For global obstacle flag

/* Defines of Remappable Pins(RPx) that will be set as INT1, INT2 sources */
/* RPx from 0 to 25 (RP0...RP25). Set 31 for Input to be tied to Vss (GND) */
#define INT1Pin 31
#define INT2Pin 22

/* Interrupt initialization function declarations  */
void INT_vInit(void);    
void INT0_vInit(T_U8);
void INT1_vInit(T_U8);
void INT2_vInit(T_U8);

/* Interrupt Service Routine Declarations */
void __attribute__((__interrupt__, no_auto_psv)) _INT0Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _INT1Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _INT2Interrupt(void);


#endif	/* MCAL_INTERRUPTS_H */

