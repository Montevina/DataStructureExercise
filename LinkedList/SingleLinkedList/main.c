#include <stdio.h>
#include <stdlib.h>

#include "singleLinkedList.h"

int main() {
	
	LinkList Numbers = NULL;

	Numbers = CreateList();

	printf("L = %x\n", Numbers);

	return 0;
}