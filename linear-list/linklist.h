#ifndef CS_DATATOCODE_LINKLIST_H
#define CS_DATATOCODE_LINKLIST_H

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitLinkList(LinkList &L);
LNode *GetElem(LinkList L, int i);      //按位查找
LNode *LocateElem(LinkList L, int &e);  //按值查找
bool IsEmpty(LinkList L);
bool LNodeBackInsert(LNode*, int const&);
bool LinkListInsert(LinkList &L, int i, int &e);
bool LNodeDelete(LNode *p, int &e);
bool InsertPriorList();//头插入

void TestLinkList();

#endif //CS_DATATOCODE_LINKLIST_H
