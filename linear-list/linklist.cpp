#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include "linklist.h"

/**
 * 获取位序为i的结点
 * @param L 代表单链表
 * @param i
 * @return 返回一个结点，可能为空
 */
LNode * GetElem(LinkList L, int i) {
    if(i<0){
        return NULL;
    }
    if(i==0){
        return L;
    }
    int j=1;
    LNode *p=L->next;
    while (p!=NULL && j<i) {
        p=p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找某结点
 * @param L
 * @param e
 * @return 返回相同值的结点，如果没找到，则为NULL
 */
LNode * LocateElem(LinkList L, int &e) {
    int j=1;
    LNode *p=L->next;
    while (p!=NULL && p->data != e) {
        p=p->next;
        j++;
    }
    return p;
}

/**
 * 在位序为i处，插入一个结点，结点值为e
 * @param L 单链表
 * @param i 位序
 * @param e 插入的结点值
 * @return 返回是否插入成功
 */
bool LinkListInsert(LinkList &L, int i, int &e) {
    //查找i结点的前一个结点
    LNode *p = GetElem(L, i-1);
    return LNodeBackInsert(p, e);
}

/**
 * 删除位序为i的结点
 * @param L
 * @param i
 * @param e
 * @return 是否删除成功
 */
bool LinkListDelete(LinkList &L, int i, int &e) {
    //先找到位序为i的结点
    LNode *p=GetElem(L, i);
    return LNodeDelete(p, e);
}

/**
 * 删除指定的结点
 * @param p
 * @param e
 * @return
 */
bool LNodeDelete(LNode *p, int &e) {
    if(p==NULL) {
        return false;
    }
    e=p->data;
    LNode *m=p->next;
    if(m==NULL){
        return false;
    }
    p->data=m->data;
    p->next=m->next;
    free(m);
    return true;
}

/**
 * 结点之后插入一个结点
 * @param p
 * @param e
 * @return
 */
bool LNodeBackInsert(LNode *p, const int &e) {
    if(p == NULL) {
        return false;
    }
    LNode *m = (LNode *)malloc(sizeof(LNode));
    m->data=e;
    m->next=p->next;
    p->next=m;
    return true;
}

/**
 * 结点之前插入一个结点
 * @param p
 * @param e
 * @return
 */
bool LNodePriorInsert(LNode *p, const int &e) {
    if(p == NULL) {
        return false;
    }
    LNode *m = (LNode *)malloc(sizeof(LNode));
    m->data=p->data;
    m->next=p->next;
    p->next=m;
    p->data=e;
    return true;
}

/**
 * 初始化单链表 带头结点
 * @param L
 */
bool InitLinkList(LinkList &L) {
   L=(LNode *)malloc(sizeof(LNode));
   if(L==NULL) {
       return false;
   }
   L->data=NULL;
   L->next=NULL;
   return true;
}

/**
 * 判断单链表是否为空
 * @param L
 * @return
 */
bool IsEmpty(LinkList L) {
    if(L==NULL) {
        return true;
    }
    return L->next==NULL;
}

void TestLinkList() {
    LinkList L;
    InitLinkList(L);
    printf(IsEmpty(L)? "LinkList is null\n" : "LinkList is not null\n");

    int insert = 11;
    LinkListInsert(L, 1, insert);
    LinkListInsert(L, 2, insert);
    LinkListInsert(L, 3, insert);
    LinkListInsert(L, 4, insert);
    LinkListInsert(L, 6, insert); //不会被插入
    printf(IsEmpty(L)? "LinkList is null\n" : "LinkList is not null\n");
    LNode *P=L;
    while (!IsEmpty(L) && P !=NULL){
        printf("LinkList data is:%d\n", P->data);
        P=P->next;
    }
    int del = -1;
    LinkListDelete(L, 1, del);
    LinkListDelete(L, 1, del);
    LinkListDelete(L, 1, del);
    LinkListDelete(L, 1, del);
    P=L; //结点重新指向头结点
    while (!IsEmpty(L) && P !=NULL){
        printf("LinkList data is:%d\n", P->data);
        P=P->next;
    }
}