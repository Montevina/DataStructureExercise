#ifndef _SINGLE_LINKED_LIST_HT_H_
#define _SINGLE_LINKED_LIST_HT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct LNode {
    ElementType data;
    struct LNode *next;
} *Link, *Position;

typedef struct{
    Link head, tail;
    int len;
}LinkList;

bool MakeNode(Link *p, ElementType e);

void FreeNode(Link *p);

bool InitList(LinkList *L);

bool DestroyList(LinkList **L);

bool ClearList(LinkList *L);

// bool InsFirst(Link h, Link s);

// bool DelFirst(Link h, Link *q);

bool Append(LinkList *L, Link s);

bool Remove(LinkList *L, Link *q);

bool InsBefore(LinkList *L, Link *p, Link s);

bool InsAfter(LinkList *L, Link *p, Link s);

bool SetCurElem(Link *p, ElementType e);

ElementType GetCurElem(Link p);

bool ListEmpty(LinkList L);

int ListLength(LinkList L);

Position GetHead(LinkList L);

Position GetLast(LinkList L);

Position PriorPos(LinkList L, Link p);

Position NextPos(LinkList L, Link p);

bool LocatePos(LinkList L, int i, Link *p);

Position LocateElem(LinkList L, ElementType e, bool (*compare)(ElementType, ElementType));

// 比较函数，用于LocateElem函数
bool equal(ElementType a, ElementType b);
bool greater(ElementType a, ElementType b);
bool less(ElementType a, ElementType b);

bool ListTraverse(LinkList L, bool (*visit)(ElementType));
bool visit(ElementType e);

//
void printLinkList(LinkList L);

#endif