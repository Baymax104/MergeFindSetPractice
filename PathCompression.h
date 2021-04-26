/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 20:32
*@Version
*/

#ifndef MERGEFINDSET_PATHCOMPRESSION_H
#define MERGEFINDSET_PATHCOMPRESSION_H

#include"stdio.h"
#define SIZE 10
int setP[SIZE]; // set中存储parent的值
void initSetP();
void addP(int data, int parent);
void delP(int data);
int findP(int data);
void listSetP();
void mergeP(int data1, int data2);

#endif //MERGEFINDSET_PATHCOMPRESSION_H
