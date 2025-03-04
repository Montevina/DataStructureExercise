#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        // bool in c99

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    struct LNode *next;     
}LNode, *LinkList;

/* 等价写法
struct LNode{
    ElementType data;
    struct LNode *next;      // 这里不可以用LinkList代替, 因为LinkList是未定义的
};

typedef struct LNode LNode;  // LNode 作为 struct LNode 的别名
typedef LNode *LinkList;     // LinkList 作为 LNode * 的别名, 即 LinkList 是指向 LNode 的指针
                             // 这样做法是区分了 LNode 和 LinkList 两个类型, 提高代码可读性
*/

// 创建一个空的单链表，
LinkList CreateList();

// 创建一个新的节点
LNode *CreateNode(ElementType data);

// 打印全链表
void PrintList(LinkList L);

// 打印链表中第i个节点
void PrintNode(LinkList L, int i);

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
bool ListInsert(LinkList *L, int i, ElementType e);

// 删除链表中第i个节点
bool DeleteNode(LinkList *L, int i);


#endif