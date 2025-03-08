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

bool DestroyList(LinkList *L);

bool ClearList(LinkList *L);

bool InsFirst(Link h, Link s);
#endif