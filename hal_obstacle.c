#include "hal_obstacle.h"

static BOOL obstacleFlag = 0;

BOOL HAL_bGetObstacle(){
    return obstacleFlag;
}

void _vSetObstacleFlag(BOOL flag){
    obstacleFlag = flag;
}
