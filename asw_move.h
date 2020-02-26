/* 
 * File:   asw_move.h
 * Author: Vasile2k
 *
 * Created on November 20, 2019, 6:39 PM
 */

#ifndef ASW_MOVE_H
#define	ASW_MOVE_H

#ifdef	__cplusplus
extern "C" {
#endif

// every 100 ms
extern void ASW_moveInit(void);
extern void ASW_dirInit(void);
extern void ASW_moveAround(void);
extern void ASW_moveUntilObstacle(void);
extern void ASW_turnWheels(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ASW_MOVE_H */

