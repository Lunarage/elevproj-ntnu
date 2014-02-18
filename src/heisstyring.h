#ifndef __INCLUDE_HEISSTYRING_H__
#define __INCLUDE_HEISSTYRING_H__

void findFloor(int* previousFloor);

/*
States:
0: find floor
1: idle
2: move
3: at floor
4: stop
5: obsr
6: stoped obstr
7: stoped idle
8: door obstr
*/
void evInput(int* orderlist,int* previousFloor, int* direction, int* state);

void evStop();

void evStopOff();

void evObstr();

void evObstrOff();

void evTimerOut();

#endif //#ifndef __INCLUDE_HEISSTYRING_H__