/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/13 18:57
*@Version
*/

#include "MergeByNumber.h"
/*int main() {
    initSetN();
    addN(3, -1);
    addN(4, 0);
    addN(5, 1);
    addN(6, 2);
    addN(7, -1);
    addN(8, 4);
    listSetN();
    printf("%d\n", find(5));
    mergeN(4, 8);
    listSetN();
    return 0;
}*/
void listSetN() {
    for (int i = 0; i <= tree.count; i++) {
        printf("%d %d\n", tree.set[i].data, tree.set[i].parent);
    }
}
void initSetN() {
    for (int i = 0; i < SIZE; i++) {
        tree.set[i].data = -1;
        tree.set[i].parent = -1;
    }
    tree.count = -1;
}
void addN(int data, int parent) {
    tree.count++;
    tree.set[tree.count].data = data;
    tree.set[tree.count].parent = parent;
    int root = findN(data);
    tree.set[root].parent--;
}
void delN(int data) {
    int delIndex;
    for (int i = 0; i <= tree.count; i++) {
        if (tree.set[i].data == data) {
            delIndex = i;
            break;
        }
    }
    for (int i = 0; i <= tree.count; i++) {
        if (tree.set[i].parent == delIndex) {
            tree.set[i].parent = tree.set[delIndex].parent;
        }
    }
    int root = findN(data);
    tree.set[delIndex].parent = -1;
    tree.set[root].parent++;
    tree.count--;
}
int findN(int data) {
    int i;
    for (i = 0; i <= tree.count; i++) {
        if (tree.set[i].data == data) {
            break;
        }
    }
    if (i > tree.count) {
        return -1;
    }
    while (tree.set[i].parent >= 0) {
        i = tree.set[i].parent;
    }
    return i;
}
void mergeN(int data1, int data2) {
    int root1 = findN(data1);
    int root2 = findN(data2);
    // 按个数归并
    if (tree.set[root1].parent > tree.set[root2].parent) {
        tree.set[root2].parent += (tree.set[root1].parent + 1);
        tree.set[root1].parent = root2;
    } else {
        tree.set[root1].parent += (tree.set[root2].parent + 1);
        tree.set[root2].parent = root1;
    }
}
