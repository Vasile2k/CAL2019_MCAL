#include "hal_dc.h"
#include "mcal_pwm.h"

void HAL_vMotorInit(void){
    PWM1_vInit();
    GPIO_u8SetPortPin(PORT_A, 9, DIGITAL, OUTPUT);
}

void HAL_vMotorSetDir(MotorDir dir){
    GPIO_u8WritePortPin(PORT_A, 9, dir);
}

void HAL_vMotorSetSpeed(T_F16 speed){
    PWM1_vSetDuty(speed, 2);
}
