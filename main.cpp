//
// Created by 27801 on 2022/8/1.
//
#include <stdio.h>
#include "linear-list/sqlist.h"

int main() {
    SqList L;
    InitList(L);
    //...��������
    ListInsert(L, 1);
    ListInsert(L, 2);
    ListInsert(L, 3);
    ListInsert(L, 4);
    ListInsert(L, 5);
    ListInsert(L, 6);
    ListInsert(L, 7);
    ListInsert(L, 8);
    ListInsert(L, 9);

    ListInsert(L, 8, 4);
    for (int j = 0; j < L.length; j++) {
        printf("˳���ȡֵ����%d������ֵΪ��%d\n", j+1, L.data[j]);
    }
    printf("hello,world~");
}
