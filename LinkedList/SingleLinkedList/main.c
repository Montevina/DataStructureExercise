#include <stdio.h>
#include <stdlib.h>

#include "singleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	LinkList Numbers = CreateList();		// 创建一个空的单链表
	if(Numbers == NULL){					// 判断是否创建成功
		return 1;
	}

	for(int i = 1; i < 10; i++){			// 插入10个元素
		if(!ListInsert(&Numbers, i, i)){
			printf("Insert failed!\n");
			return 1;
		}
	}

	PrintList(Numbers);						// 打印全链表
	PrintNode(Numbers, 1);
	PrintNode(Numbers, 5);

	if(!DeleteNode(&Numbers, 5)){			// 删除第5个元素
		printf("Delete failed!\n");
		return 1;
	}
	PrintList(Numbers);

	return 0;
}