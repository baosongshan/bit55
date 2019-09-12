#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define NULL_DATA -1

typedef struct SeqList
{
	DataType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

//内部方法
static BOOL _Inc(SeqList *psl);

BOOL SeqListIsFull(SeqList *psl);
BOOL SeqListIsEmpty(SeqList *psl);
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListPushBack(SeqList* psl, DataType x);
void SeqListShow(SeqList *psl);

void SeqListPopBack(SeqList* psl);
void SeqListPopFront(SeqList* psl);
size_t SeqListLength(SeqList *psl);
void SeqListClear(SeqList *psl);
DataType SeqListFindByPos(SeqList *psl, int pos);
int SeqListFindByVal(SeqList *psl, DataType key);

BOOL SeqListEraseByVal(SeqList *psl, DataType key);
BOOL SeqListEraseByPos(SeqList *psl, int pos);
BOOL SeqListInsertByPos(SeqList *psl, int pos, DataType x);
void SeqListReverse(SeqList *psl);

void SeqListRemoveAll(SeqList* psl, DataType x);
void SeqListSort(SeqList *psl);
void SeqListDestroy(SeqList *psl);

BOOL _Inc(SeqList *psl)
{
	DataType *new_base = 
		(DataType *)malloc(sizeof(DataType)*(psl->capacity + INC_SIZE));
	if (new_base == NULL)
		return FALSE;
	
	memcpy(new_base, psl->base, sizeof(DataType)*psl->capacity);
	free(psl->base);

	psl->base = new_base;
	psl->capacity += INC_SIZE;
	return TRUE;
}

BOOL SeqListIsFull(SeqList *psl)
{
	if (psl->size >= psl->capacity)
		return TRUE;
	return FALSE;
}
BOOL SeqListIsEmpty(SeqList *psl)
{
	if (psl->size == 0)
		return TRUE;
	return FALSE;
}

////////////////////////////////////////////////////////////
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->base = (DataType*)malloc(sizeof(DataType)*capacity);
	assert(psl->base != NULL);
	psl->capacity = capacity;
	psl->size = 0;
}

void SeqListPushBack(SeqList* psl, DataType x)
{
	if (SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return;
	}
	psl->base[psl->size++] = x;
}
void SeqListPushFront(SeqList* psl, DataType x)
{
	if (SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return;
	}

	for (int i = psl->size; i > 0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
}

void SeqListShow(SeqList *psl)
{
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList* psl)
{
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}
	psl->size--;
}

void SeqListPopFront(SeqList* psl)
{
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}
	for (int i = 0; i<psl->size-1; ++i)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
}

size_t SeqListLength(SeqList *psl)
{
	return psl->size;
}

void SeqListClear(SeqList *psl)
{
	psl->size = 0;
}

DataType SeqListFindByPos(SeqList *psl, int pos)
{
	//assert(pos >= 0 && pos < psl->size);
	if (pos < 0 || pos >= psl->size)
	{
		printf("查询的位置无效.\n");
		return NULL_DATA;
	}
	return psl->base[pos];
}

int SeqListFindByVal(SeqList *psl, DataType key)
{
	for (int i = 0; i < psl->size; ++i)
	{
		if (key == psl->base[i])
			return i;
	}
	return -1;
}

BOOL SeqListEraseByPos(SeqList *psl, int pos)
{
	if (pos < 0 || pos >= psl->size)
		return FALSE;
	for (int i = pos; i < psl->size - 1; ++i)
		psl->base[i] = psl->base[i + 1];
	psl->size--;
	return TRUE;
}

BOOL SeqListEraseByVal(SeqList *psl, DataType key)
{
	int index = SeqListFindByVal(psl, key);
	if (index == -1)
		return FALSE;
	return SeqListEraseByPos(psl, index);
}

BOOL SeqListInsertByPos(SeqList *psl, int pos, DataType x)
{
	if (pos<0 || pos>psl->size)
		return FALSE;
	if (SeqListIsFull(psl) && !_Inc(psl))
	{
		printf("顺序表空间已满,%d不能插入.\n", x);
		return FALSE;
	}
	for (int i = psl->size; i > pos; --i)
		psl->base[i] = psl->base[i - 1];
	psl->base[pos] = x;
	psl->size++;
	return TRUE;
}

void SeqListReverse(SeqList *psl)
{
	if (psl->size >= 2)
	{
		int begin = 0;
		int end = psl->size - 1;
		while (begin < end)
		{
			Swap(&(psl->base[begin]), &(psl->base[end]));
			begin++;
			end--;
		}
	}
}

void SeqListRemoveAll(SeqList* psl, DataType x)
{
	for (int i = 0; i < psl->size; ++i)
	{
		if (x == psl->base[i])
		{
			for (int j = i; j < psl->size-1; ++j)
				psl->base[j] = psl->base[j + 1];
			psl->size--;
			i--;
		}
	}
}
void SeqListSort(SeqList *psl)
{
	for (int i = 0; i < psl->size - 1; ++i)
	{
		for (int j = 0; j < psl->size - i - 1; ++j)
		{
			if (psl->base[j] > psl->base[j + 1])
			{
				Swap(&(psl->base[j]), &(psl->base[j + 1]));
			}
		}
	}
}

void SeqListDestroy(SeqList *psl)
{
	free(psl->base);
	psl->base = NULL;
	psl->capacity = psl->size = 0;
}

/*
BOOL SeqListEraseByVal(SeqList *psl, DataType key)
{
	int index = SeqListFindByVal(psl, key);
	if (index == -1)
	return FALSE;

	for (int i = index; i < psl->size - 1; ++i)
	psl->base[i] = psl->base[i + 1];
	psl->size--;
	return TRUE;
}
*/

#endif /* _SEQLIST_H_ */