#ifndef CS_DATATOCODE_SQLIST_H
#define CS_DATATOCODE_SQLIST_H

#define MaxSize 10

//构造一个 静态顺序表
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L);
bool ListInsert(SqList &L, int i, int e);
bool ListInsert(SqList &L, int e);
bool IsFull(SqList &L);
bool IsEmpty(SqList &L);

#endif //CS_DATATOCODE_SQLIST_H
