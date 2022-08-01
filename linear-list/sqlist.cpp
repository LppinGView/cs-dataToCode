#include "sqlist.h"

void InitList(SqList &L) {
    L.length=0;
}

/**
 * 往顺序表中依次添加一个数据元素，如果顺序表已满，则插入失败
 * @param L
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int e) {
    if(IsFull(L)) {
        return false;
    }
    //顺序表尾插入一条数据
    L.data[L.length]=e;
    L.length++;
    return true;
}

/**
 * 在位序i插入一个数据元素，i的范围为：1 ~ length+1
 * 为了保证顺序表 连续 不能有空位
 * @param L
 * @param i 范围应该为: 1 ~ length+1，另外位序i和数组下标关系为 位序i = 数组下标 + 1
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, int e) {
    //位序从1开始 不能超过顺序表长度
    if(i<1 || i> L.length + 1) {
        return false;
    }
    //顺序表已满，则插入失败
    if(IsFull(L)) {
        return false;
    }
    //从末尾开始 依次移动数据元素，直到第i位
    for(int j=L.length; j>=i; j--) {
        //最好情况 插入位置为：length + 1 不需要移位 O(1)
        //最坏情况 插入第一个位置，n个元素全部往后移动一位，O(n)
        //平均情况 可能情况为1/(n+1)   (1+2+...+n)*1/(n+1)=n/2   O(n)
        L.data[j]=L.data[j-1];
    }
    //位序转换为数组下标要减一
    L.data[i-1]=e;
    L.length++;
    return true;
}

/**
 * 删除顺序表 位序为i的数据元素e
 * @param L
 * @param i 范围应该为: 1 ~ length
 * @param e
 * @return
 */
bool ListDelete(SqList &L, int i, int &e) {
    if(i<1 || i>L.length) { //判断i的范围是否有效
        return false;
    }
    //将被删除的元素赋值给e
    e=L.data[i-1];
    for (int j = i; j < L.length; j++) {
        //将i之后的元素依次向前移动一位
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

/**
 * 按位序查找
 * @param L
 * @return
 */
int GetElem(SqList L, int i) {
    if (i<1 || i>L.length) {
        return -1; //会有歧义
    }
    return L.data[i-1];
}

/**
 * 按值查找，并返回该值的位序
 */
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if(L.data[i] == e) {
            return i+1;
        }
    }
    return 0;
}

bool IsEmpty(SqList &L) {
    return L.length == 0;
}

bool IsFull(SqList &L) {
    return L.length >= MaxSize;
}

void TestList() {
    SqList L;
    InitList(L);
    //...插入数据
    ListInsert(L, 1);
    ListInsert(L, 2);
    ListInsert(L, 3);
    ListInsert(L, 4);
    ListInsert(L, 5);
    ListInsert(L, 6);
    ListInsert(L, 7);
    ListInsert(L, 8);
//    ListInsert(L, 9);

    ListInsert(L, 9, 4);
    for (int j = 0; j < L.length; j++) {
        printf("顺序表取值，第%d个数据值为：%d\n", j+1, L.data[j]);
    }
    int a = -1;
    ListDelete(L, 8, a);
    printf("a value is:%d\n", a);
    for (int j = 0; j < L.length; j++) {
        printf("删除后，顺序表取值，第%d个数据值为：%d\n", j+1, L.data[j]);
    }
    printf("按位查找，第%d个元素为:%d\n", 8, GetElem(L, 8));
    printf("按值查找，该值%d位于第%d\n", 7, LocateElem(L, 7));
    printf("hello,world~");
}