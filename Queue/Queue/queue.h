#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QElemType;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q);

bool DestroyQueue(LinkQueue *Q);

// bool ClearQueue(LinkQueue *Q);

// bool QueueEmpty(LinkQueue Q);

// int QueueLength(LinkQueue Q);

// bool GetHead(LinkQueue Q, QElemType *e);

bool EnQueue(LinkQueue *Q, QElemType e);

bool DeQueue(LinkQueue *Q, QElemType *e);

bool QueueTraverse(LinkQueue Q, void (*visit)(QElemType));
void visit(QElemType e);

#endif