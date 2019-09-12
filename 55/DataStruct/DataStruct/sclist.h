#ifndef _SCLIST_H_
#define _SCLIST_H_

#include"common.h"

typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next; //link
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t     size;
}SCList;

SCListNode* _Buynode(DataType x)
{
	SCListNode *s = (SCListNode *)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SCListInit(SCList* plist);

void SCListInit(SCList* plist)
{
	SCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
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


#endif /*_SCLIST_H_*/