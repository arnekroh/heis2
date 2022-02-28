#include "ControllModule.h"
#include "StatemachineModule.h"

//Denne funksjonen sjekker hvilken etasje du er i/sist befant deg i
void checkLastKnownFloor(){

    int floor = elevio_floorSensor();
    if (floor != -1)
    {
        lastKnownFloor = floor;
    }
}


//Setter nytt pådrag likt det heisen hadde før stop
void setDir() {
    switch (lastDir)
    {
    case DIRN_DOWN:
        elevio_motorDirection(DIRN_DOWN);
        currentDir = DIRN_DOWN;
        break;
    case DIRN_UP:
        elevio_motorDirection(DIRN_UP);
        currentDir = DIRN_UP;
        break;
    default:
        break;
    }
}


//Sjekker om heisen skal stoppe i etasje på bakgrunn av heisens retning og om det er et stopkall i etasjen den passerer 
void shouldStop() {
    switch (currentDir)
    {
    case DIRN_DOWN:

        // currentfloor definering og test ikke lik -1 kan evt settes utenfor shouldstop for å unngå å gå inn i funskjonen hver gang
        currentFloor = elevio_floorSensor();

        if(currentFloor != -1){
            if(stopOrders[currentFloor] == 1 || stopOrders[currentFloor + 2*N_FLOORS] == 1){
                elevio_motorDirection(DIRN_STOP);
            }
        }
       
        break;

    case DIRN_UP:

        currentFloor = elevio_floorSensor();

        if(currentFloor != -1){
            if(stopOrders[currentFloor + N_FLOORS] == 1 || stopOrders[currentFloor + 2*N_FLOORS] == 1){
                elevio_motorDirection(DIRN_STOP); //Her stoppes motoren, skal den stoppes et annet sted?
            }
        }

        break;
    
    default:
        break;
    }
}

void checkForOrder() {

    int sum = 0;

    for (int i = 0; sizeof(stopOrders); i++)
    {
        sum += stopOrders[i];
    }
    
    if (sum != 0)
    {
        currentState = MOVING;
    }
    
}
