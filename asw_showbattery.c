#include "asw_showbattery.h"
#include "rte.h"

void lightOff(){
    GPIO_u8WritePortPin(PORT_A, 10, 0);
}

void lightOn(){
    GPIO_u8WritePortPin(PORT_A, 10, 1);
}

#define PERCENT_REFRESH_CYCLES 500

void ASW_vShowBatteryPercentage(){
    static T_U16 cycles = 0;
    static T_U8 percent = 4;
    
    if(cycles < PERCENT_REFRESH_CYCLES){
        if(cycles % 2 == 0){
            if(percent > 0){
                lightOn();
                percent--;
            }
        }else{
            lightOff();
        }
        ++cycles;
    }else{
        percent = 4;
        cycles = 0;
    }
}
