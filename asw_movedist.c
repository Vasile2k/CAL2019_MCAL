#include "asw_movedist.h"
#include "general.h"
#include "rte.h"

void ASW_moveForDistance(T_F16 dist){
    static T_F16 elapsedDistance = 0.0F;
    elapsedDistance += RTE_f16GetElapsedDistance();
    RTE_vMotorSetDir((elapsedDistance < dist) ? FORWARD : BACKWARD);
    RTE_vMotorSetSpeed((elapsedDistance < dist) ? 65 : 0);
}
