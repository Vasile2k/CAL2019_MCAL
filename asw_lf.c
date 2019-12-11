#include "asw_lf.h"
#include "rte.h"

void ASW_vfollowLine(){
    RTE_vMotorSetDir(FORWARD);
    T_U16 lf = RTE_vGetLineFollower();
    if(lf){
        RTE_vMotorSetSpeed(0);
    }else{
        RTE_vMotorSetSpeed(35);
    }
}
