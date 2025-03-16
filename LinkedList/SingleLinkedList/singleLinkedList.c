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

// 创建一个新的节点
LNode *CreateNode(ElementType e){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL){
        printf("malloc error, out of memory!\n");
        return NULL;
    }
    p->data = e;
    p->next = NULL;
    return p;
}


// 打印全链表
void PrintList(LinkList L){
    LNode *p = L->next;
    while(p != NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL \n");
}

// 打印链表中第i个节点
void PrintNode(LinkList L, int i){
    LNode *p = L->next;
    while(p != NULL && i > 1){
        p = p->next;
        i--;
    }
    printf("%d\n", p->data);
}

// 在指定位置后插入一个节点
bool ListInsert(LinkList* L, int i, ElementType data){

    // 判断参数合法性（表头是否为空，插入位置是否合法）
    if(L == NULL || i < 1){
        return false;
    }
    // 找到插入位置的前一个节点（如果插入位置为1，则前一个节点为头节点
    else{

        // 如果i=1，则插入位置为头节点
        if(i == 1){
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            if(newNode == NULL){
                printf("malloc error, out of memory!\n");
                return false;
            }
            else{
                newNode->data = data;
                newNode->next = NULL;
                (*L)->next = newNode;
            }
        }
        // 如果i>1，则插入位置为其他节点
        if(i > 1){
            LNode *p = *L;
            while(p != NULL && i > 1){
                p = p->next;
                i--;
            }
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            if(newNode == NULL){
                printf("malloc error, out of memory!\n");
                return false;
            }
            else{
                newNode->data = data;
                newNode->next = p->next;
                p->next = newNode;
            }
            // free(p);
        }
        return true;
    }
}

// 删除链表中第i个节点
bool DeleteNode(LinkList *L, int i){
    // 判断参数合法性（表头是否为空，插入位置是否合法）
    if(L == NULL || i < 1){
        printf("illegal operation!\n");
        return false;
    }
    else{
        LNode *p = *L;
        while(p->next != NULL && i > 1){      // 找到插入位置的前一个节点
            p = p->next;
            i--;
        }
<<<<<<< HEAD
        if(p->next == NULL){                   // 如果插入位置为表尾
            printf("illegal operation!\n");
            return false;
        }
        else{
            LNode *q = p->next;
            p->next = q->next;
            free(q);
            return true;
        }
=======
>>>>>>> 7097f6f6d07edcba0af0d4bf427527351e3ca7a6
    }
}