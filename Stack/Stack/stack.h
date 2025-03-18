#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SElemType;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct Stack {
    SElemType *base;
    SElemType *top;
    int stacksize;
} Stack;

bool InitStack(Stack *S);

bool DestroyStack(Stack *S);

bool ClearStack(Stack *S);

bool StackEmpty(Stack S);

int StackLength(Stack S);

bool GetTop(Stack S, SElemType *e);

bool Push(Stack *S, SElemType e);

bool Pop(Stack *S, SElemType *e);

bool StackTraverse(Stack S, void (*visit)(SElemType));
void visit(SElemType e);

#endif

