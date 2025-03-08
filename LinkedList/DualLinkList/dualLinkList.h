#ifndef _DUALLINKLIST_H_
#define _DUALLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct DNode {
    ElementType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList *L);


#endif