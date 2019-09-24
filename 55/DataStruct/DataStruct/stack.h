#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

struct BinTreeNode;
#define StackDataType  struct BinTreeNode*

typedef struct Stack
{
	StackDataType *base;
	size_t    capacity;
	size_t    top;
}Stack;

#define DEFAULT_STACK_SIZE 100

void StackInit(Stack *pst, size_t sz);
void StackPush(Stack *pst, StackDataType x);
void StackPop(Stack *pst);
void StackClear(Stack *pst);
void StackDestroy(Stack *pst);
StackDataType StackTop(Stack *pst);
void StackShow(Stack *pst);
BOOL StackIsFull(Stack *pst)
{return pst->top >= pst->capacity;}
BOOL StackIsEmpty(Stack *pst)
{return pst->top == 0;}
///////////////////////////////////////////////////////
void StackInit(Stack *pst, size_t sz)
{
	pst->capacity = sz > DEFAULT_STACK_SIZE ? sz : DEFAULT_STACK_SIZE;
	pst->base = (StackDataType*)malloc(sizeof(DataType)*(pst->capacity));
	assert(pst->base != NULL);
	pst->top = 0;
}

void StackPush(Stack *pst, StackDataType x)
{
	if (StackIsFull(pst))
	{
		printf("栈空间已满，%d 不能入栈.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void StackPop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈空间已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

StackDataType StackTop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈空间已空，不能取栈顶元素.\n");
		return;
	}
	return pst->base[pst->top-1];//
}

void StackClear(Stack *pst)
{
	pst->top = 0;
}

void StackDestroy(Stack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

void StackShow(Stack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
}




#endif /*_STACK_H_*/