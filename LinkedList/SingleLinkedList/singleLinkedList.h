#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    struct LNode *next;     // next: node address; *next: node
}LNode, *LinkList;

// create a single linked list
bool CreateList(LinkList &L);

// destory a single linked list
bool DestoryList(LinkList &L);

// clear List
bool ClearList(LinkList &L);

// return length of a single linked list
int ListLength(LinkList L);

// List is empty or not?
bool ListEmpty(LinkList L);

// Get the ith element
ElementType GetElemUnSafe(LinkList L, int i);       // not safe
bool GetElem(LinkList L, int i, ElementType &e);

// find the element
LNode *LocateElem(LinkList L, ElementType e);

// insert a Node
bool ListInsert(LinkList &L, int i, ElementType e);

// delete a Node
bool ListDelete(LinkList &L, int i, ElementType &e);



#endif