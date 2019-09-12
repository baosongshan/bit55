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