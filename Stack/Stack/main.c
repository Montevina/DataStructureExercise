#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int main()
{
    
    Stack s1;
    InitStack(&s1);

    printf("isEmpty: %d\n", StackEmpty(s1));

    for(int i = 0; i < 100; i++){
        Push(&s1, i);
    }

    printf("StackLength: %d\n", StackLength(s1));
    StackTraverse(s1, visit);

    for(int i = 100; i < 110; i++){
        Push(&s1, i);
    }
    StackTraverse(s1, visit);

    for(int i = 100; i > 0; i--){
        int e;
        Pop(&s1, &e);
        printf("Pop: %d\t", e);
    }
    StackTraverse(s1, visit);

    ClearStack(&s1);
    DestroyStack(&s1);
    
    printf("stack implementation in C\n");


}