#include "elev.h"
#include "channels.h"
#include "kømodul.h"
#include "io.h"
#include <stdio.h>

void findFloor(int* previousFloor){
    if(elev_get_floor_sensor_signal() == -1){
        int speed = 300;
        elev_set_speed(-speed);

        while(1){
            if(elev_get_floor_sensor_signal() >= 0){
                elev_set_floor_indicator(elev_get_floor_sensor_signal());
            }
            if(elev_get_floor_sensor_signal() != -1 && io_read_analog(TACO)-analog_speed > stop_coef){
                elev_set_speed(speed);
            }
            else if(elev_get_floor_sensor_signal() != -1 && io_read_analog(TACO)-analog_speed <= stop_coef){
                elev_set_speed(0);
                setPreviousFloor(elev_get_floor_sensor_signal(),previousFloor);
                printf("%s\n","Found floor");
                break;
            }
        }
    }
    else{
        setPreviousFloor(elev_get_floor_sensor_signal(),previousFloor);
        printf("%s\n","Found floor");
    }
}

void evInput(int* orderlist,int* previousFloor, int* direction, int* state){
    int speed = 300;
    int prev;
    int ordr;

    switch(*state)
    {
        case 0:
            findFloor(previousFloor);
            *state = 1;
        case 1:
            prev = getPreviousFloor(previousFloor);
            ordr = getOrderedFloor(orderlist);
            if(prev != ordr){
                *state = 2;
            }
            else{
                *state = 3;
            }
            break;
        case 2:
            prev = getPreviousFloor(previousFloor);
            ordr = getOrderedFloor(orderlist);
            if(prev > ordr){
                setDirection(-1,direction);
                elev_set_speed(speed * getDirection(direction));
            }
            else if (prev < ordr){
                setDirection(1,direction);
                elev_set_speed(speed * getDirection(direction));
            }
            else if(prev == ordr){
                *state = 3;
            }
            break;
        case 3:
            elev_set_speed(0);
            elev_set_door_open_lamp(1);
            break;
        case 4:

        case 5:

        case 6:

        case 7:

        case 8:

        default:
            break;
    }
}