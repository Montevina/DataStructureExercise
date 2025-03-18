#include "singleLinkedListHT.h"

bool MakeNode(Link *p, ElementType e){
    *p = (Link)malloc(sizeof(struct LNode));
    if(*p == NULL){
        return false;
    }
    else{
        (*p)->data = e;
        (*p)->next = NULL;
        return true;
    }
}

void FreeNode(Link *p){
    free(*p);
}

bool InitList(LinkList *L){

    while(L == NULL){
        return false;
    }
    L->head = NULL;
    L->tail = NULL;
    L->len = 0;
    return true; 
}

bool DestroyList(LinkList **L){
    
    if(L == NULL || *L == NULL){
        return false;
    }
    ClearList(*L);
    free(*L);
    *L = NULL;
    return true;
}

bool ClearList(LinkList *L){

    if(L == NULL){
        return false;
    }
    else{
        Position p = L->head;
        while(p != NULL && p != L->tail){
            Position q = p;
            p = p->next;
            free(q);
        }
        if(p == L->tail){
            free(p);
        }   
        L->head = NULL;
        L->tail = NULL;
        L->len = 0;
    }
    return true;
}

// bool InsFirst(Link h, Link s){

// }

// bool DelFirst(Link h, Link *q){

// }

bool Append(LinkList *L, Link s){
    if(L == NULL || s == NULL){
        return false;
    }
    else{
        if(L->len == 0){
            L->head = s;
        }
        else{
            L->tail->next = s;
        }
        Position p = L->tail;
        while(p->next != NULL){
            p = p->next;
            L->len++;
        }
        L->tail = p;
        return true;
    }
}

bool Remove(LinkList *L, Link *q){
    if(L == NULL || L->len == 0){
        return false;
    }
    else{
        Position p = L->head;
        while(p->next != L->tail){
            p = p->next;
        }
        *q = p->next;
        p->next = NULL;
        L->tail = p;
        L->len--;
        return true;
    }
}

bool InsBefore(LinkList *L, Link *p, Link s){
    if(L == NULL || p == NULL || s == NULL){
        return false;
    }
    else if(*p == L->head){
        L->head = s;
    }
    else{
        Position q = L->head;
        while(q->next != *p){
            q = q->next;
        }
        q->next = s;
    }
    s->next = *p;
    L->len++;
    return true;
}

bool InsAfter(LinkList *L, Link *p, Link s){

    // 检查参数合法性
    if(L == NULL || p == NULL || s == NULL){
        return false;
    }
    // 插入操作
    else{
        if(L->len == 0){
            s->next = NULL;
            L->head = s;
        }
        else{
            s->next = (*p)->next;
            (*p)->next = s;
        }
        L->tail = s;
        L->len++;
        return true;
    }
}

bool SetCurElem(Link *p, ElementType e){
    if(p == NULL){
        return false;
    }
    else{
        (*p)->data = e;
        return true;
    }
}

ElementType GetCurElem(Link p){
    if(p == NULL){
        printf("p is NULL\n");
        return 0;
    }
    else{
        return p->data;
    }
}

bool ListEmpty(LinkList L){
    if(L.len == 0){
        return true;
    }
    else{
        return false;
    }
}

int ListLength(LinkList L){
    return L.len;
}

Position GetHead(LinkList L){
    return L.head;
}

Position GetLast(LinkList L){
    return L.tail;
}

Position PriorPos(LinkList L, Link p){
    if(L.len == 0 || p == NULL){
        return NULL;
    }
    else{
        Position q = L.head;
        while(q->next != p){
            q = q->next;
        }
        return q;
    }
}

Position NextPos(LinkList L, Link p){
    if(L.len == 0 || p == NULL){
        return NULL;
    }
    else{
        return p->next;
    }
}

bool LocatePos(LinkList L, int i, Link *p){
    if(L.len == 0 || i < 1 || i > L.len){
        return false;
    }
    else{
        Position q = L.head;
        int j = 1;
        while(j < i){
            q = q->next;
            j++;
        }
        *p = q;
        return true;
    }
}

Position LocateElem(LinkList L, ElementType e, bool (*compare)(ElementType, ElementType)){
    if(L.len == 0){
        return NULL;
    }
    else{
        Position p = L.head;
        while(p != NULL && !(*compare)(p->data, e)){
            p = p->next;
        }
        return p;
    }
}

// 相等比较函数
bool equal(ElementType a, ElementType b) {
    return a == b;
}

// 大于比较函数
bool greater(ElementType a, ElementType b) {
    return a > b;
}

// 小于比较函数
bool less(ElementType a, ElementType b) {
    return a < b;
}

bool ListTraverse(LinkList L, bool (*visit)(ElementType)){
    if(L.len == 0){
        return false;
    }
    else{
        Position p = L.head;
        while(p->next != NULL){
            (*visit)(p->data);
            p = p->next;
        }
        return true;
    }
}

// 测试函数visit，如果visit是0，则返回false，否则返回true
void visit(ElementType e){

    printf("%d-> ", e);
}
