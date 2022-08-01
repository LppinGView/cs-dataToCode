#ifndef CS_DATATOCODE_LINKLIST_H
#define CS_DATATOCODE_LINKLIST_H

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LNode * GetElem(LinkList L, int i);
void TestLinkList();

#endif //CS_DATATOCODE_LINKLIST_H
