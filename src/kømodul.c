#include <stdio.h>

void addOrder(int floorA, int dir,int* orderlist){
	*orderlist = floorA;
}

void setPreviousFloor(int currentFloor,int* previousFloor){
	*previousFloor = currentFloor;
}

int getPreviousFloor(int* previousFloor){
	return *previousFloor;
}

int getOrderedFloor(int* orderlist){
	return *orderlist;
}

void setDirection(int dir, int* direction){
	*direction = dir;
}

int getDirection(int* direction){
	return *direction;
}