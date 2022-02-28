#include "OrderModule.h"
#include "QueueModule.h"
#include "ElevatorModule.h"
#include "ControllModule.h"
#include "StatemachineModule.h"




//LYS HOW THE FUCK. KNAPP OG ETASJELYS, DØR ÅPEN LYS
//DEFINE ELLER CONST VARIABLE


//Registrerer ordre fra knapp og sender til activeOrders array
void setActiveOrders(void){
 
    for(int i = 0; i <=3; i++){
        if(elevio_callButton(i, BUTTON_CAB)){
            stopOrders[i+ 2*N_FLOORS] = 1;
            elevio_buttonLamp(i, BUTTON_CAB, 1);
        }
        else if (elevio_callButton(i, BUTTON_HALL_DOWN)) 
        {
            stopOrders[i] = 1;
            elevio_buttonLamp(i, BUTTON_HALL_DOWN, 1);
        }
        else if (elevio_callButton(i, BUTTON_HALL_UP))
        {
           stopOrders[i+N_FLOORS] = 1;
           elevio_buttonLamp(i, BUTTON_HALL_UP, 1);
        }
    }

}



/**
 * @brief Registrer knappetrykk og oppretter tilvsvarende @c ORDER structs som brukes til køsystem senere. 
 * 
 * 
 * @return Order 
 */

/*

Order taImot(void){
    for(int i = 1; i <= 3; i++){
            if(elevio_callButton(i, BUTTON_HALL_DOWN)){
                Order downOrder;
                downOrder.desiredFloor = i;
                downOrder.wanted_direction = DIRN_DOWN;
                
                g_DownOrders[i] == 1;
                
                return downOrder;
            }
        }

        for(int i = 0; i <=2; i++){
            if(elevio_callButton(i, BUTTON_HALL_UP)){
                Order upOrder;
                upOrder.desiredFloor = i;
                upOrder.wanted_direction = DIRN_UP;
                
            
                g_UpOrders[i] == 1;

                return upOrder;

                
            }
        }


        for(int i = 0; i <=3; i++){
            if(elevio_callButton(i, BUTTON_CAB)){
                Order cabOrder;
                cabOrder.desiredFloor = i;
                if(i < elevio_floorSensor()){
                    cabOrder.wanted_direction = DIRN_DOWN;
                    
                    g_DownOrders[i] == 1;

                }else if(i > elevio_floorSensor()){
                    cabOrder.wanted_direction = DIRN_UP;

                    g_UpOrders[i] == 1;

                }else{
                    cabOrder.wanted_direction = DIRN_STOP;
                }
                cabOrder.wanted_direction = DIRN_UP;
                

                return cabOrder;

                


            }
        }

        Order emptyOrder;
        emptyOrder.desiredFloor = -6;
        emptyOrder.wanted_direction = DIRN_STOP;
        return emptyOrder;
    
}
*/





/**
 * @file 
 * @brief 
 * En ordre modul. Tar inn forskjellige parametre fra bruker; etasjen ordren kommer fra, ønsket destinasjon og skiller mellom innenfra. utenfra. opp og ned. Basert på disse lages en generell ordre som kan plasseres i køsystemet.  
 */


//gammel, debug funksjon for å kjøre
/*
void receiveOrders(void){
    struct timespec tim, tim2;
    tim.tv_sec  = 0;
    tim.tv_nsec = 5000000000L;

    for(int i = 1; i <= 3; i++){
            if(elevio_callButton(i, BUTTON_HALL_DOWN)){
                printf("button pressed down: %d\n", i+1);
                nanosleep(&tim , &tim2);
                system("clear");
            }
        }

        for(int i = 0; i <=2; i++){
            if(elevio_callButton(i, BUTTON_HALL_UP)){
                printf("button pressed up: %d\n", i+1);
                nanosleep(&tim , &tim2);
                system("clear");
            }
        }


        for(int i = 0; i <=3; i++){
            if(elevio_callButton(i, BUTTON_CAB)){
                printf("button pressed in cab: %d\n", i+1);
                nanosleep(&tim , &tim2);
                system("clear");
            }
        }

        
        if(elevio_stopButton()){
            printf("Stop pressed\n");
            nanosleep(&tim , &tim2);
            system("clear");
        }

        if(elevio_obstruction()){
            printf("Obstruction ON");
            nanosleep(&tim , &tim2);
            system("clear");
        }
}

*/

