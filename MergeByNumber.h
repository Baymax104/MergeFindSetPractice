/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 18:57
*@Version
*/

#ifndef MERGEFINDSET_MERGEBYNUMBER_H
#define MERGEFINDSET_MERGEBYNUMBER_H

#include <stdio.h>
#define SIZE 10
typedef struct node {
    int data;
    int parent;
}Set;
typedef struct tree {
    Set set[SIZE];
    int count;
}Tree;
Tree tree;
void initSetN();
void addN(int data, int parent);
void delN(int data);
int findN(int data);
void mergeN(int data1, int data2);
void listSetN();

#endif //MERGEFINDSET_MERGEBYNUMBER_H
