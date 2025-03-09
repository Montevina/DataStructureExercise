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
    L = malloc(sizeof(LinkList));
    L->head = NULL;
    L->tail = NULL;
    L->len = 0;
}

bool DestroyList(LinkList *L){
    
    if(L == NULL){
        return false;
    }

    Position p = L->head;
    while(p != NULL && p != L->tail){
        Position q = p;
        p = p->next;
        free(q);
    }
    if(p == L->tail){
        free(p);
    }
    free(L);
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

bool InsFirst(Link h, Link s){
    if(h == NULL || s == NULL || h->next == NULL){
        return false;
    }
    else{
        s->next = h->next;
        h->next = s;
        return true;
    }
}

bool DelFirst(Link h, Link *q){
    if(h == NULL || h->next == NULL){
        return false;
    }
    else{
        *q = h->next;
        h->next = (*q)->next;
        return true;
    }
}

bool Append(LinkList *L, Link s){
    if(L == NULL || s == NULL){
        return false;
    }
    else{
        if(L->len = 0){
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
        free(p);
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
        free(p);
        return true;
    }
}

bool InsBefore(LinkList *L, Link *p, Link s){
    if(L == NULL || L->next == NULL || p == NULL || s == NULL){
        return false;
    }
    else{
        Position q = L->head;
        while(q->next != p){
            q = q->next;
        }
        s->next = q->next;
        q->next = s;
        return true;
    }
}

bool InsAfter(LinkList *L, Link *p, Link s){
    if(L == NULL || L->next == NULL || p == NULL || s == NULL){
        return false;
    }
    else{
        if(p == L->tail){
            s->next = NULL;
            L->tail = s;
        }
        else{
            s->next = p->next;
        }
        p->next = s;
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
        return NULL;
    }
    else{
        return p->data;
    }
}

bool ListEmpty(LinkList L){
    if(L == NULL || L->len == 0){
        return true;
    }
    else{
        return false;
    }
}

int ListLength(LinkList L){
    return L->len;
}

Position GetHead(LinkList L){
    return L->head;
}

Position GetLast(LinkList L){
    return L->tail;
}

Position PriorPos(LinkList L, Link p){
    if(L == NULL || L->len == 0 || p == NULL){
        return NULL;
    }
    else{
        Position q = L->head;
        while(q->next != p){
            q = q->next;
        }
        return q;
    }
}

Position NextPos(LinkList L, Link p){
    if(L == NULL || L->len == 0 || p == NULL){
        return NULL;
    }
    else{
        return p->next;
    }
}

bool LocatePos(LinkList L, int i, Link *p);{
    if(L == NULL || L->len == 0 || i < 1 || i > L->len){
        return false;
    }
    else{
        Position q = L->head;
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
    if(L == NULL || L->len == 0){
        return NULL;
    }
    else{
        Position p = L->head;
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

bool ListTraverse(LinkList L, void (*visit)(ElementType)){
    if(L == NULL || L->head == NULL || L->len == 0){
        return false;
    }
    else{
        Position p = L->head;
        while(p->next != NULL && (*visit)(p->data)){
            p = p->next;
        }
        return true;
    }
}

// 测试函数visit，如果visit是0，则返回false，否则返回true
bool visit(ElementType e){
    if(e == 0){
        return false;
    }
    else{
        return true;
    }
}