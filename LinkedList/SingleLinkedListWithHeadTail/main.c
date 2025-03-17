#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "singleLinkedListHT.h"

int main(){

    LinkList L1;

    // 
    InitList(&L1);

    printf("List is empty? %d\n", ListEmpty(L1));

    //
    Link p;
    MakeNode(&p, 1);

    //
    InsAfter(&L1, &L1.head, p);
    printf("List is empty? %d\n", ListEmpty(L1));
    
    for(int i = 2; i <= 10; i++){
        MakeNode(&p, i);
        InsAfter(&L1, &L1.tail, p);
    }

    printf("L1: ");
    printf("Length: %d\n", ListLength(L1));
    printLinkList(L1);

    MakeNode(&p, 0);
    InsBefore(&L1, &L1.tail, p);
    printLinkList(L1);

    printf("head data: %d\n", GetCurElem(L1.head));
    printf("tail data: %d\n", GetCurElem(L1.tail));

    long address = (long)LocateElem(L1, 10, equal);
    printf("10 is at %lx\n", address);

    bool hasZero = ListTraverse(L1, visit);
    printf("Zero in the list: %d\n", hasZero);

    LinkList L2;
    InitList(&L2);
    MakeNode(&p, 11);
    InsAfter(&L2, &L2.head, p);
    for(int i = 12; i < 20; i++){
        MakeNode(&p, i);
        InsAfter(&L2, &L2.tail, p);
    }
    printf("L2: ");
    printLinkList(L2);

    Append(&L1, L2.head);
    printf("L1: ");
    printf("Length: %d\n", ListLength(L1));
    printLinkList(L1);

    Link x;
    Remove(&L1, &x);
    printf("L1 removed tail: ");
    printLinkList(L1);
    printf("x: %d\n", x->data);

    FreeNode(&x);
    printf("x: %d\n", x->data);

    ClearList(&L1);
    printf("L1 cleared: %d\n", ListEmpty(L1));
    printf("L1: ");
    printLinkList(L1);


    LinkList L3;
    InitList(&L3);
    MakeNode(&p, 1);
    InsAfter(&L3, &L3.head, p);
    for(int i = 2; i < 40; i++){
        MakeNode(&p, i);
        InsAfter(&L3, &L3.tail, p);
    }
    printf("L3: ");
    printLinkList(L3);
    DestroyList(&L3);
    printf("L3.len = %d\n", L3.len);
    
    return 0;
}