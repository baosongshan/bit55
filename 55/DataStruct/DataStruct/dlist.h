#ifndef _DLIST_H_
#define _DLIST_H_

#include"common.h"

typedef struct DListNode
{
	DataType data;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t     size;
}DList;

DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode *)malloc(sizeof(DListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}

void DListInit(DList* plist);
void DListInit(DList* plist)
{
	plist->first = plist->last = _Buynode(0);
	plist->size = 0;
}

/*

void SListPushBack(SList *plist, DataType x);
void SListPushFront(SList *plist, DataType x);
void SListShow(SList *plist);

SListNode* SListFindByVal(SList *plist, DataType key);
BOOL SListEraseByVal(SList *plist, DataType key);
size_t SListLength(SList *plist);
BOOL SListInsertByVal(SList *plist, DataType x);

void SListClear(SList *plist);
void SListReverse(SList *plist);
void SListDestroy(SList *plist);
*/

#endif /*_DLIST_H_*/