
typedef enum {
    IDLE, DOOR_OPEN, MOVING, STOP
} States;

States currentState;

void setState();

void setStateIdle();
void setStateDoorOpen();
void setStateMoving();
void setStateStop();


