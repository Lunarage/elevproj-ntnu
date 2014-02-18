#ifndef __INCLUDE_KOEMODUL_H__
#define __INCLUDE_KOEMODUL_H__

int getPreviousFloor();

int getOrderedFloor();

void addOrder(int floorA, int dir,int* orderlist);

void deleteOrder();

void setPreviousFloor(int currentFloor,int* previousFloor);

void deleteAllOrders();

//returns direction, 1 is up and -1 is down
int getDirection(int* direction);

//sets direction, 1 is up and -1 is down
void setDirection(int dir, int* direction);

#endif //#ifndef __INCLUDE_KOEMODUL_H__