#include <time.h>
#include <string.h>

time_t startTimer(time_t* timer){
	time_t now = time(timer);
	return now;
}

time_t checkTimer(){
	time_t current_time = time(NULL);
	return current_time;
}