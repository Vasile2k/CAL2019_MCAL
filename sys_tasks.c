/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "mcal_init.h"
#include "asw_com.h"

#include "light_sig.h"

#include "asw_move.h"

#include "hal_lf.h"
#include "rte.h"
#include "asw_lf.h"
#include "asw_showbattery.h"

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL ,OUTPUT);
//    ASW_moveInit();
//    ASW_dirInit();
}

void TASK_1ms()
{
    
}

void TASK_5ms()
{

}

void TASK_10ms()
{
//    if(RTE_bGetObstacle()){
//        GPIO_u8WritePortPin(PORT_A, 10, 1);
//    }else{
//        GPIO_u8WritePortPin(PORT_A, 10, 0);
//    }
//    ASW_moveUntilObstacle();
//    light_battery_low();
//    ASW_vfollowLine();
}

void TASK_100ms()
{ 
//    ASW_moveAround();
//    ASW_turnWheels();
    ASW_vShowBatteryPercentage();
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{

}