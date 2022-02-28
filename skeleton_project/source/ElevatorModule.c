#include "ElevatorModule.h"
#include "OrderModule.h"
#include "QueueModule.h"
#include "ControllModule.h"
#include "StatemachineModule.h"



/**
* @brief Multiply all the elements in @p p_buffer,
* @p size with the supplied @p factor.
*
* @param[in,out] p_buffer Buffer of integers to be
* with @p factor.
*
* @param[in] factor Factor to multiply each of the
* elements in @p p_buffer with.
*
* @param[in] size Size of @p p_buffer.
*
* @warning If @p p_buffer is @c NULL, the function
* abruptly terminate the program with exit code @c
*/


//Denne funksjonen initilialiserer heisen
void initElevator(void){
    int floor = elevio_floorSensor();
    if (floor != 0) {

        MotorDirection dir = DIRN_DOWN;

            while(floor != 0){
                floor = elevio_floorSensor();
                elevio_motorDirection(dir);
            }
        
        elevio_motorDirection(DIRN_STOP);

    }

    lastDir = DIRN_UP;
    currentState = IDLE;
    
    
}

void driveElevator() {
    setDir();
}


//Denne funksjonen kjører til ønsket etasje
/*
void heis(){
    struct timespec tim, tim2;
    tim.tv_sec  = 3;
    tim.tv_nsec = 0;

    int floor = elevio_floorSensor();
    int input = 0;

    while(1){
        floor = elevio_floorSensor();
 
    //Midlertidlig styrt direkte av knapper, skal kontrolleres av køsystem
        input = receiveOrder();

        if(input == 0){
            continue;
        }

        MotorDirection dir = (floor-(input-1)>0) ? DIRN_DOWN : DIRN_UP; //Setter dir til motoren
        currentDir = dir; //Oppdaterer currentDir

            while(floor != input-1){
                floor = elevio_floorSensor();
                elevio_motorDirection(dir);
                /*if(receiveOrder() == 6){
                    printf("stopped %d", floor);
                    break;
                }
            }

        elevio_motorDirection(DIRN_STOP);

    //Denne funksjonen skrur på etasjelys i 3 sek. (Må erstattes med bedre funksjon)
    //Må implementeres i en løkke som sjekker om du befinner deg i en etasje
    
        if (elevio_floorSensor() != -1)
        {
            elevio_doorOpenLamp(1);
            nanosleep(&tim , &tim2);
            elevio_doorOpenLamp(0);
        }
    
    }
        
}
*/




    