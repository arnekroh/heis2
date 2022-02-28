#ifndef elevio
#define elevio
#include "driver/elevio.h"
#endif

static MotorDirection lastDir;
static MotorDirection currentDir;

static int lastKnownFloor;
static int currentFloor;

static int stopOrders[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //[Down 0-3, Up 4-7, CAB 8-11]

void shouldStop();

void checkLastKnownFloor();

void setDir();

void checkForOrder();