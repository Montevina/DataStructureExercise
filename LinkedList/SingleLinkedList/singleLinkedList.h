#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        // bool in c99

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    struct LNode *next;     // next: node address; *next: node
}LNode, *LinkList;

// 创建一个空的单链表，
LinkList CreateList();

// destory a single linked list
// bool DestoryList(LinkList &L);

// clear List
// bool ClearList(LinkList &L);

// return length of a single linked list
// int ListLength(LinkList L);

// List is empty or not?
// bool ListEmpty(LinkList L);

// Get the ith element
// bool GetElem(LinkList L, int i, ElementType &e);

// find the element
// LNode *LocateElem(LinkList L, ElementType e);

// insert a Node
// bool ListInsert(LinkList L, int i, ElementType e);

// delete a Node
// bool ListDelete(LinkList &L, int i, ElementType &e);


#endif