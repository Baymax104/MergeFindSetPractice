/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 21:23
*@Version
*/

#ifndef MERGEFINDSET_MERGEBYHEIGHT_H
#define MERGEFINDSET_MERGEBYHEIGHT_H

#include"stdio.h"
#define SIZE 10
int setH[SIZE];
void initSetH();
void addH(int data, int parent);
int findH(int data);
void mergeH(int data1, int data2);
void listSetH();

#endif //MERGEFINDSET_MERGEBYHEIGHT_H
