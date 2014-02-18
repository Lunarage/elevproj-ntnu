// REPLACE THIS FILE WITH YOUR OWN CODE.
// READ ELEV.H FOR INFORMATION ON HOW TO USE THE ELEVATOR FUNCTIONS.

#include "elev.h"
#include "channels.h"
#include "io.h"
#include "eventManager.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    // Initialize hardware
    if (!elev_init()) {
        printf(__FILE__ ": Unable to initialize elevator hardware\n");
        return 1;
    }

    int *orderlist = malloc(sizeof(int));
    int *previousFloor = malloc(sizeof(int));
    int *direction = malloc(sizeof(int));
    int *state = malloc(sizeof(int));
    time_t *timer = malloc(sizeof(time_t));

    initEventManager(orderlist, previousFloor, direction, state, timer);

    return 0;
}

