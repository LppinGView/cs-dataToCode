//
// Created by 27801 on 2022/8/5.
// 双列表
//

#ifndef CS_DATATOCODE_DLINKLIST_H
#define CS_DATATOCODE_DLINKLIST_H

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L);
void TestDLinkList();

#endif //CS_DATATOCODE_DLINKLIST_H
