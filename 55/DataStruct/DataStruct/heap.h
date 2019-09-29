#ifndef  _HEAP_H_
#define  _HEAP_H_
#include"common.h"

#define DEFAULT_HEAP_SIZE 15

typedef struct Heap
{
	DataType *base;
	size_t    capacity;
	size_t    size;
}Heap;

bool HeapIsFull(Heap *php)
{return php->size >= php->capacity;}
bool HeapIsEmpty(Heap *php)
{return php->size == 0;}

void HeapInit(Heap *php, int sz);
bool HeapPush(Heap *php, DataType x);
bool HeapPop(Heap *php);
void _AdjustUp(Heap *php, int start);
void _AdjustDown(Heap *php, int end);
void HeapShow(Heap *php);
bool HeapTop(Heap *php, DataType *ret);
void HeapSort(Heap *php);
///////////////////////////////////////////////
void HeapInit(Heap *php, int sz)
{
	php->capacity = sz > DEFAULT_HEAP_SIZE ? sz : DEFAULT_HEAP_SIZE;
	php->base = (DataType *)malloc(sizeof(DataType)*(php->capacity));
	php->size = 0;
}

bool HeapPush(Heap *php, DataType x)
{
	if(HeapIsFull(php))
		return false;
	
	php->base[php->size] = x;
	//µ÷Õû
	_AdjustUp(php, php->size);
	php->size++;
	return true;
}

bool HeapPop(Heap *php)
{
	if(HeapIsEmpty(php))
		return false;

	php->size--;
	php->base[0] = php->base[php->size];
	_AdjustDown(php, php->size-1);
	

	return true;
}

void HeapDestroy(Heap *php)
{
	free(php->base);
	php->base = NULL;
	php->capacity = php->size = 0;
}

void HeapShow(Heap *php)
{
	for(int i=0; i<php->size; ++i)
	{
		printf("%d ", php->base[i]);
	}
	printf("\n");
}

bool HeapTop(Heap *php, DataType *ret)
{
	if(HeapIsEmpty(php))
		return false;
	*ret = php->base[0];
	return true;
}

void HeapSort(Heap *php)
{
	int ret;
	while(!HeapIsEmpty(php))
	{
		HeapTop(php, &ret);
		printf("%d ", ret);
		HeapPop(php);
	}
}


void _AdjustUp(Heap *php, int start)
{
	int j = start;
	int i = (j-1) / 2;

	DataType tmp = php->base[j];

	while(j > 0)
	{
		if(tmp < php->base[i])
		{
			php->base[j] = php->base[i];
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
	php->base[j] = tmp;
}
void _AdjustDown(Heap *php, int end)
{
	int i = 0;
	int j = 2*i+1; //left

	while(j <= end)
	{
		if(j<=end-1 && php->base[j]>php->base[j+1])
			j = j+1;
		if(php->base[i] > php->base[j])
		{
			Swap(&(php->base[i]), &php->base[j]);
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
}

/*
void _AdjustUp(Heap *php, int start)
{
	int j = start;
	int i = (j-1) / 2;

	while(i >= 0)
	{
		if(php->base[j] < php->base[i])
		{
			Swap(&(php->base[j]), &php->base[i]);
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
}
*/

#endif /*_HEAP_H_*/