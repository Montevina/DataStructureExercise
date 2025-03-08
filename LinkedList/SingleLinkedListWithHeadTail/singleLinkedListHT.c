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
        
    }
}