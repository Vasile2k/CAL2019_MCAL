#include "hal_servo.h"
#include "mcal_pwm.h"

void HAL_vServoInit(void){
    
}

void HAL_vServoSetPosition(T_F16 position){
    PWM1_vSetDuty(5 + position/20, 1);
}
