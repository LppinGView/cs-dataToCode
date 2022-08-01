#include "sqlist.h"

void InitList(SqList &L) {
    L.length=0;
}

/**
 * 在顺序表尾插入一个数据元素，如果顺序表已满，则插入失败
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
}

/**
 * 按位序插入一个数据元素
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, int e) {
    //位序从1开始 不能超过顺序表长度
    if(i<1 || i> L.length) {
        return false;
    }
    //顺序表已满，则插入失败
    if(IsFull(L)) {
        return false;
    }
    //从末尾开始 依次移动数据元素，直到第i位
    for(int j=L.length; j>=i; j--) {
        L.data[j]=L.data[j-1];
    }
    //位序转换为数组下标要减一
    L.data[i-1]=e;
    L.length++;
}

/**
 * 按值查找
 * @param L
 * @return
 */
void getElem(SqList L, int &e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            e =
        }
    }
}

/**
 * 按位序查找
 */
void locateElem(SqList L, int i) {

}


bool IsEmpty(SqList &L) {
    return L.length == 0;
}

bool IsFull(SqList &L) {
    return L.length >= MaxSize;
}