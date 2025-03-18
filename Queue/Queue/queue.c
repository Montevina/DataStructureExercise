#include "queue.h"

bool InitQueue(LinkQueue *Q){

    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if(!Q->front){
        return false;
    }
    else{
        Q->front->next = NULL;
        return true;
    }
}

bool DestroyQueue(LinkQueue *Q){

    while(Q->front){
        Q->rear = Q->front;
        free(Q->front);
        Q->front = Q->rear;
    }
    return true;
}

bool EnQueue(LinkQueue *Q, QElemType e){
    QNode *p = (QNode *)malloc(sizeof(QNode));
    if(!p){
        return false;
    }
    else{
        // printf("EnQueue: %d\n", e);
        p->data = e;
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = p;
        return true;
    }
}

bool DeQueue(LinkQueue *Q, QElemType *e){
    if(Q->front == Q->rear){
        return false;
    }
    else{
        QueuePtr p = Q->front->next;
        *e = p->data;
        Q->front->next = p->next;
        if(Q->rear == p){
            Q->rear = Q->front;
        }
        free(p);
    }
    return true;
}

bool QueueTraverse(LinkQueue Q, void (*visit)(QElemType)){
    
    if(!Q.front){
        return false;
    }
    else if(Q.front == Q.rear){
        printf("Empty Queue!");
    }
    else{
        QueuePtr p = Q.front->next;
        while(p){
            visit(p->data);
            p = p->next;
        }
    }
    printf("\n");
    return true;
}

void visit(QElemType e){
    printf("<-%d  ", e);
}