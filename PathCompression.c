/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 20:32
*@Version
*/

#include "PathCompression.h"
/*int main () {
    initSet();
    addP(1, -1);
    addP(2, 0);
    addP(3, 1);
    addP(5, 2);
    addP(7, -1);
    addP(8, 6);
    listSetP();
    printf("%d\n", find(4));
    mergeP(5, 8);
    listSetP();
    return 0;
}*/
void initSetP() {
    for (int i = 0; i < SIZE; i++) {
        setP[i] = -1;
    }
}
void listSetP() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d %d\n", i, setP[i]);
    }
}
void addP(int data, int parent) {
    // 传入的参数经过映射成为下标
    int index = data - 1;
    setP[index] = parent;
    int root = findP(index);
    setP[root]--;
}
void delP(int data) {
    int index = data - 1;
    for (int i = 0; i < SIZE; i++) {
        if (setP[i] == index) {
            setP[i] = setP[index];
        }
    }
    int root = findP(index);
    setP[index] = -1;
    setP[root]++;
}
int findP(int index) {
    // 路径压缩
    // 传入的是映射后的下标
    if (setP[index] < 0) {
        return index;
    }
    return setP[index] = findP(setP[index]);
}
void mergeP(int data1, int data2) {
    int root1 = findP(data1 - 1);
    int root2 = findP(data2 - 1);
    // 按个数归并
    if (setP[root1] > setP[root2]) {
        setP[root2] += (setP[root1] + 1);
        setP[root1] = root2;
    } else {
        setP[root1] += (setP[root2] + 1);
        setP[root2] = root1;
    }
}
