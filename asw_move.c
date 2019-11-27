#include "asw_move.h"
#include "rte.h"
#include "general.h"

void ASW_moveInit(void){
    RTE_vMotorInit();
}

void ASW_dirInit(void){
    RTE_vServoInit();
}

void ASW_moveAround(void){
    
    static T_U16 time = 0;
    
    if(time < 30){
        RTE_vMotorSetDir(FORWARD);
        RTE_vMotorSetSpeed(10*(time/3));
    }else if(time <= 60){
        RTE_vMotorSetDir(FORWARD);
        RTE_vMotorSetSpeed(100 - 10*((time-30)/3));
    }else if(time < 90){
        RTE_vMotorSetDir(BACKWARD);
        RTE_vMotorSetSpeed(10*((time-60)/3));
    }else if(time <= 120){
        RTE_vMotorSetDir(BACKWARD);
        RTE_vMotorSetSpeed(100 - 10*((time-90)/3));
    }else if(time < 130){
        RTE_vServoSetPosition(30);
    }else if(time < 140){
        RTE_vServoSetPosition(90);
    }else if(time < 140){
        RTE_vServoSetPosition(150);
    }else if(time < 200){
        
    }else{
        time = 0;
    }
    
    ++time;
}

void ASW_turnWheels(void){
    static T_U16 time = 0;
    
    if(time < 40){
        RTE_vServoSetPosition(50 + time * 2);
    }else if(time < 80){
        RTE_vServoSetPosition(130 - (time - 40) * 2);
    }else{
        time = 0;
    }
    
    ++time;
}
