#include "stack.h"

bool InitStack(Stack *S){

    S->base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
    if(!S->base)
        return false;
    else{
        S->top = S->base;
        S->stacksize = STACK_INIT_SIZE;
        return true;
    }
}

bool DestroyStack(Stack *S){
    
    if(S->base == NULL){
        return false;
    }
    else{
        free(S->base);
        S->base = NULL;
        S->top = NULL;
        S->stacksize = 0;
        return true;
    }
}

bool ClearStack(Stack *S){

    if(S->base == NULL){
        return false;
    }
    else{
        S->top = S->base;
        return true;  
    }
}

bool StackEmpty(Stack S){
    if(S.base == S.top){
        return true;
    }
    else{
        return false;
    }
}

int StackLength(Stack S){

    int length = S.top - S.base;
    return length;
}

bool GetTop(Stack S, SElemType *e){
    if(S.base == S.top){
        return false;
    }
    else{
        *e = *(S.top - 1);
        return true;
    }
}

bool Push(Stack *S, SElemType e){
    if(S->top - S->base >= S->stacksize){
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!S->base){
            return false;
        }
        else{
            S->top = S->base + S->stacksize;
            S->stacksize += STACKINCREMENT;
        }
    }
    else{
        *(S->top) = e;
        S->top++;
    }
    return true;
}

bool Pop(Stack *S, SElemType *e){
    if(S->base == S->top){
        return false;
    }
    else{
        *e = *(S->top - 1);
        S->top--;
        return true;
    }
}

bool StackTraverse(Stack S, void (*visit)(SElemType)){
    if(S.base == S.top){
        return false;
    }
    else{
        SElemType *p = S.base;
        while(p != S.top){
            visit(*p);
            p++;
        }
        return true;
    }
}

void visit(SElemType e){
    printf("%d - ", e);
}