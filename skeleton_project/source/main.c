#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "ElevatorModule.h"
#include "StatemachineModule.h"
#include "ControllModule.h"
#include "OrderModule.h"



int main(){
    
    //Initiliserer
    elevio_init();
    initElevator();

    //Heisens operasjonsområde
    while (1)
    {
        
        setState(currentState); //Setter tilstanden på bakgrunn av static variabel currentState        
        setActiveOrders(); //Tar i mot en ordre

    }
    

    return 0;
}
