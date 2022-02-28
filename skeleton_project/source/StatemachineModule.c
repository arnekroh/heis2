#include "StatemachineModule.h"
#include "ControllModule.h"


void setState() {
    switch (currentState)
    {
    case IDLE:
        setStateIdle();
        //checkForOrder();
        break;

    case DOOR_OPEN:
        setStateDoorOpen();
        break;

    case MOVING:
        setStateMoving();
        //shouldStop();
        break;

    case STOP:
        setStateStop();
        break;

    default:
        break;
    };
}

void setStateIdle(){
    // lastDir = currentDir; dette vil ikke funke. whilen looper mange ganger gjennom
    if (elevio_floorSensor() != -1){
        elevio_motorDirection(DIRN_STOP);
        currentDir = DIRN_STOP;
        elevio_doorOpenLamp(0);
    }
    
}

void setStateDoorOpen() {
    if (elevio_floorSensor() != -1){
        if (currentDir == DIRN_STOP){
            elevio_doorOpenLamp(1);
        }    
    }
}

void setStateMoving(){
    elevio_doorOpenLamp(0);
    setDir();
}

void setStateStop(){
    //clearOrders()
    elevio_doorOpenLamp(0);
    elevio_motorDirection(DIRN_STOP);
}