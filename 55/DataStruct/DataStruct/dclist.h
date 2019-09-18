#ifndef _DCLIST_H_
#define _DCLIST_H_

#include"common.h"

typedef struct DCListNode
{
	DataType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef struct DCList
{
	DCListNode *first;
	DCListNode *last;
	size_t     size;
}DCList;

DCListNode* _Buynode(DataType x)
{
	DCListNode *s = (DCListNode *)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}

void DCListInit(DCList* plist);
void DCListPushBack(DCList *plist, DataType x);
void DCListShow(DCList *plist);
void DCListPushFront(DCList *plist, DataType x);
void DCListPopBack(DCList *plist);
void DCListPopFront(DCList *plist);
DCListNode* DCListFindByVal(DCList *plist, DataType key);

BOOL DCListEraseByVal(DCList *plist, DataType key);
size_t DCListLength(DCList *plist);
void DCListClear(DCList *plist);
void DCListDestroy(DCList *plist);

void DCListSort(DCList *plist);

void DCListReverse(DCList *plist);

void DCListInit(DCList* plist)
{
	DCList *s =  _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList *plist, DataType x)
{
	assert(plist != NULL);
	DCListNode *s = _Buynode(x);
	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	plist->size++;
}

void DCListShow(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPushFront(DCList *plist, DataType x)
{
	DCListNode *s = _Buynode(x);
	s->next = plist->first->next;
	s->next->prev = s;
	s->prev = plist->first;
	plist->first->next = s;

	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void DCListPopBack(DCList *plist)
{
	DCListNode *p = plist->last;
	plist->last = p->prev;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;
}

void DCListPopFront(DCList *plist)
{
	DCListNode *p = plist->first->next;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	if (p == plist->last)
		plist->last = plist ->first;
	free(p);
	plist->size--;
}

DCListNode* DCListFindByVal(DCList *plist, DataType key)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
}

BOOL DCListEraseByVal(DCList *plist, DataType key)
{
	DCListNode *p = DCListFindByVal(plist, key);
	if (p == NULL)
		return FALSE;

	if (p == plist->last)
		plist->last = plist->last->prev;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;

	return TRUE;
}

size_t DCListLength(DCList *plist)
{
	return plist->size;
}

void DCListClear(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}

void DCListSort(DCList *plist)
{
	DCListNode *p = plist->first->next;
	DCListNode *q = p->next;
	//断开链表
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	DCListNode *cur;
	while (q != plist->first)
	{
		p = q;
		q = q->next;

		cur = plist->first->next;
		while (cur != plist->first && cur->data < p->data)
			cur = cur->next;
		if (cur == plist->first) //尾部插入
		{
			p->prev = plist->last;
			plist->last->next = p;
			plist->last = p;
			plist->last->next = plist->first;
			plist->first->prev = plist->last;
			continue;
		}

		p->next = cur;
		p->prev = cur->prev;
		p->prev->next = p;
		cur->prev = p;
	}
}

void DCListReverse(DCList *plist)
{
	DCListNode *p = plist->first->next;
	DCListNode *q = p->next;
	if (plist->size <= 1)
		return;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;

	while (q != plist->first)
	{
		p = q;
		q = q->next;

		p->next = plist->first->next;
		p->prev = plist->first;
		p->prev->next = p;
		p->next->prev = p;
	}
}

/*





SListNode* SListFindByVal(SList *plist, DataType key);
BOOL SListEraseByVal(SList *plist, DataType key);
size_t SListLength(SList *plist);
BOOL SListInsertByVal(SList *plist, DataType x);

void SListClear(SList *plist);
void SListReverse(SList *plist);
void SListDestroy(SList *plist);
*/

#endif/*_DCLIST_H_*/