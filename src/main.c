// REPLACE THIS FILE WITH YOUR OWN CODE.
// READ ELEV.H FOR INFORMATION ON HOW TO USE THE ELEVATOR FUNCTIONS.

#include "elev.h"
#include "channels.h"
#include "io.h"
#include <stdio.h>

#define     speed       300
#define     stop_coef   300


int main()
{
    // Initialize hardware
    if (!elev_init()) {
        printf(__FILE__ ": Unable to initialize elevator hardware\n");
        return 1;
    }
    
    //printf("Press STOP button to stop elevator and exit program.\n");
    elev_set_speed(speed);

    while(1){
    if(elev_get_floor_sensor_signal() == 2 && io_read_analog(TACO)-2070 > stop_coef){
        elev_set_speed(-speed);
      }
    else if(elev_get_floor_sensor_signal() == 2 && io_read_analog(TACO)-2070 <= stop_coef)
        elev_set_speed(0);
    }

    return 0;
}

