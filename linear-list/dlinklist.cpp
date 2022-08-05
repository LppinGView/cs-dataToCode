//
// Created by 27801 on 2022/8/5.
//
#include "dlinklist.h"
#include "stdlib.h"
#include "stdio.h"

bool InitDLinkList(DLinkList &L) {
    L=(DNode *)malloc(sizeof(DNode)); //分配一个头结点
    if(L==NULL){
        return false; //内存分配失败
    }
    L->data=NULL;
    L->prior=NULL;
    L->next=NULL;
    return true;
}

/**
 * 双链表判空操作
 * @param L
 * @return
 */
bool IsEmpty(DLinkList L) {
    return L==NULL||L->next==NULL;
}

bool InsertNextDNode(DNode *p, int &e) {
    if(p==NULL) {
        return false; //当前结点为空
    }
    DNode *m=(DNode *)malloc(sizeof(DNode));
    m->next=p->next;
    if(p->next!=NULL) {
        m=p->next->prior;
    }
    p=m->prior;
    p->next=m;
    return true;
}

void TestDLinkList() {
    DLinkList L;//声明一个头指针
    InitDLinkList(L); //初始化双链表，分配一个头结点
    printf(IsEmpty(L)?"DLinkList is null":"DLinkList is not null");
//    int a=-1;
//    InsertNextDNode(L, a);
//    printf(IsEmpty(L)?"DLinkList is null":"DLinkList is not null");
}

/**
* 总结一下，新增结点，删除结点，查找结点，构建线性表
 *
 * 【新增结点】：在位序i插入一个结点 -> 1.查找到位序i-1，之后采取当前结点 后插方式新增结点 O(n)
 *         结点后插操作: 内存分配一个结点m,  m.next=p.next  p.next=m      O(1)
 *         结点前插操作: 主要思路为将值和当前结点进行置换。
 *
 * 【查找结点】：查找位序为i的结点：依次遍历列表
 *
 * 【删除结点】：删除当前结点的后继结点
 *            删除当前结点结点
 *
 * 【创建链表】：通过位序i的方式创建单链表，当有n个元素时，需要 1+2+...+n ~ O(n^2)
 *            尾插法：可以通过使用一个指针，每次插入时，移动指针到链表尾部
 *            头插法：在头结点后插入新结点
*/