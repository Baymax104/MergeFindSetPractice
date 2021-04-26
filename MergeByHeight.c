/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 21:23
*@Version
*/

#include "MergeByHeight.h"
int main () {
    initSetH();
    addH(1, -1);
    addH(2, 0);
    addH(3, 1);
    addH(5, 2);
    addH(7, -1);
    addH(8, 6);
    addH(9, 7);
    addH(10, 8);
    listSetH();
    printf("%d\n", findH(5));
    mergeH(5, 8);
    listSetH();
    return 0;
}
void initSetH() {
    for (int i = 0; i < SIZE; i++) {
        setH[i] = -1;
    }
}
void listSetH() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d %d\n", i, setH[i]);
    }
}
void addH(int data, int parent) {
    int index = data - 1;
    setH[index] = parent;
    int root = data - 1;
    int height = 1;
    while (setH[root] >= 0) {
        root = setH[root];
        height++;
    }
    if (height > -setH[root]) {
        setH[root] = -height;
    }
}
int findH(int data) {
    int index = data - 1;
    while (setH[index] >= 0) {
        index = setH[index];
    }
    return index;
}
void mergeH(int data1, int data2) {
    // 按高度合并
    int root1 = findH(data1);
    int root2 = findH(data2);
    if (setH[root1] > setH[root2]) { // 若root1高度小于root2
        setH[root1] = root2;
    } else {
        if (setH[root1] == setH[root2]) {
            setH[root1]--;
        }
        setH[root2] = root1;
    }
}
