#include "singleLinkedList.h"

// 创建一个空的单链表
LinkList CreateList() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        return NULL;
    }
    L->next = NULL;
    return L;
}

