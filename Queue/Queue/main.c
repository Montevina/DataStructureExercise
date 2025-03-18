#include "queue.h"

int main(){

    LinkQueue Q1;
    InitQueue(&Q1);
    QueueTraverse(Q1, visit);

    for(int i = 1; i < 10; i++){
        EnQueue(&Q1, i);
    }
    QueueTraverse(Q1, visit);
    
    for(int i = 1; i < 5; i++){
        QElemType e;
        DeQueue(&Q1, &e);
        printf("DeQueue %d <= ", e);
    }
    printf("\n");
    QueueTraverse(Q1, visit);

    // DestroyQueue(&Q1);

    return 0;
}