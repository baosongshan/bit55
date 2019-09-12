#ifndef _SLIST_H_
#define _SLIST_H_

#include"common.h"

typedef struct SListNode
{
	DataType data;
	struct SListNode *next; //link
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t     size;
}SList;


SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListInit(SList* plist);
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

void SListInit(SList* plist)
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

void SListPushBack(SList *plist, DataType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	plist->last->next = s;
	plist->last = s;
	plist->size++;
}

void SListPushFront(SList *plist, DataType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;
	//判断是否插入的是第一个节点
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
}

void SListShow(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

SListNode* SListFindByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

BOOL SListEraseByVal(SList *plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p, *q;
	p = SListFindByVal(plist, key);

	if(p == NULL)
		return FALSE;

	q = plist->first;
	while (q->next != p)
		q = q->next;

	if (p == plist->last)
		plist->last = q;
	q->next = p->next;
	free(p);

	plist->size--;

	return TRUE;
}

size_t SListLength(SList *plist)
{
	return plist->size;
}

//链表要求有序
BOOL SListInsertByVal(SList *plist, DataType x)
{
	assert(plist);
	SListNode *s = _Buynode(x);
	
	SListNode *p = plist->first;
	while(p->next!=NULL && p->next->data < x)
		p = p->next;

	if (p->next == NULL) //尾部插入
		plist->last = s;
	else
		s->next = p->next;
	p->next = s;

	plist->size++;
	return TRUE;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	if (plist->size == 0)
		return;

	
	while(p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}

	plist->last = plist->first;
	plist->size = 0;
}

void SListReverse(SList *plist)
{
	SListNode *p, *q;
	p = plist->first->next;
	q = p->next;

	plist->last = p;
	plist->last->next = NULL;

	while(q != NULL)
	{
		p = q;
		q = q->next;	
		p->next = plist->first->next;
		plist->first->next = p;
	}
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}

#if 0
typedef SListNode *List;

//////////////////////////////////////////////////
void SListInit(List *head);
void SListCreate_Back(List *head);
void SListCreate_Front(List *head);
void SListCreate_Back1(List *head);
void SListShow(List head);

SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListInit(List *head)
{
	*head = _Buynode(0);
}

void SListCreate_Back(List *head)
{
	SListNode *p = *head;
	for(int i=1; i<=10; ++i)
	{
		SListNode *s = _Buynode(i);
		p->next = s;
		p = s;
	}
}

void SListCreate_Front(List *head)
{
	for (int i = 1; i <= 10; ++i)
	{
		SListNode *s = _Buynode(i);
		s->next = (*head)->next;
		(*head)->next = s;
	}
}

void SListShow(List head)
{
	SListNode *p = head->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}



void SListInit(List *head)
{
	*head = NULL;
}

void SListCreate_Back(List *head)
{
	*head = (SListNode*)malloc(sizeof(SListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;

	SListNode *p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		SListNode *s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

void SListCreate_Front(List *head)
{
	//1 创建第一个节点
	*head = (SListNode*)malloc(sizeof(SListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;

	//2 循环创建节点进行头插
	for (int i = 2; i <= 10; ++i)
	{
		SListNode *s = (SListNode*)malloc(sizeof(SListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *head;
		*head = s;
	}
}

void SListCreate_Back1(List *head)
{
	*head = (SListNode*)malloc(sizeof(SListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;
	SListNode *p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		p = p->next = (SListNode*)malloc(sizeof(SListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}
}

void SListShow(List head)
{
	SListNode *p = head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
#endif

#endif