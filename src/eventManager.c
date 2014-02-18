#include "elev.h"
#include "channels.h"
#include "io.h"
#include "kømodul.h"
#include "heisstyring.h"
#include "timer.h"
#include <stdio.h>
#include <time.h>

int checkButtons(int* orderlist){
	if(elev_get_button_signal(BUTTON_CALL_UP, 0)){
		addOrder(0,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_UP, 0, 1);
		return 1;
	}
	if(elev_get_button_signal(BUTTON_CALL_UP, 1)){
		addOrder(1,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_UP, 1, 1);
		return 1;
	}
	if(elev_get_button_signal(BUTTON_CALL_UP, 2)){
		addOrder(2,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_UP, 2, 1);
		return 1;
	}
	if(elev_get_button_signal(BUTTON_CALL_DOWN, 1)){
		addOrder(1,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_DOWN, 1, 1);
		return 1;
	}
	if(elev_get_button_signal(BUTTON_CALL_DOWN, 2)){
		addOrder(2,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_DOWN, 2, 1);
		return 1;
	}
	if(elev_get_button_signal(BUTTON_CALL_DOWN, 3)){
		addOrder(3,0,orderlist);
		elev_set_button_lamp(BUTTON_CALL_DOWN, 3, 1);
		return 1;
	}
	return 0;
}

int checkSensors(){
	if(elev_get_floor_sensor_signal() != -1){
		elev_set_floor_indicator(elev_get_floor_sensor_signal());
		return 1;
	}
	else{
		return 0;
	}
}


void initEventManager(int* orderlist,int* previousFloor,int* direction,int* state, time_t* timer){
	*state = 0;
	timer = NULL;

	evInput(orderlist, previousFloor,direction ,state);

	while(1){

		//check order buttons for new input
		if (checkButtons(orderlist)){
			evInput(orderlist, previousFloor,direction ,state);
		}

		//check sensors for new floor
		if(checkSensors()){
			evInput(orderlist, previousFloor,direction ,state);
			setPreviousFloor(elev_get_floor_sensor_signal(),previousFloor);
		}

		//check timer
		if((*timer - checkTimer()) >= 3){
			//evTimerOut();
		}
	}
}