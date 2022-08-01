#include <cstddef>
#include "linklist.h"

/**
 * 获取位序为i的结点
 * @param L 代表单链表
 * @param i
 * @return 返回一个结点
 */
LNode * GetElem(LinkList L, int i) {
    int j=1;
    LNode *p=L->next;
    if(i==0){
        return L;
    }
    if(i<1){
        return NULL;
    }
    while (p!=NULL && j<i) {
        p=p->next;
        j++;
    }
    return p;
}

void TestLinkList() {

}