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

// print a single linked list
void PrintList(LinkList L){
    LNode *p = L->next;
    while(p != NULL){
        printf("%d\tab ", p->data);
        p = p->next;
    }
    printf("\n");
}

// print ith node of a single linked list
void PrintNode(LinkList L, int i){
    LNode *p = L->next;
    while(p != NULL && i > 0){
        p = p->next;
        i--;
    }
    printf("%d\n", p->data);
}

bool ListInsert(LinkList L, int i, ElementType e){
    if(L->next == NULL){
        return false;
    }
    else{
        LNode *p = L->next;
        while(p->next != NULL && i > 1){
            p = p->next;
            i--;
        }
        if(i == 1){
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        }
        else{
            return false;
        }
    }
}

