#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "common.h"

#include "queue.h"
#include "stack.h"

//  ABC##DE##F##G#H##
typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

void BinTreeInit(BinTree *pbt);
void CreateBinTree(BinTree *pbt);
void CreateBinTree_1(BinTreeNode **t);
BinTreeNode* CreateBinTree_2();

void CreateBinTreeByStr(BinTree *pbt, char *str);
void CreateBinTree_3(BinTreeNode **t, char *str);

void PreOrder(BinTree *pbt);
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *pbt);
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *pbt);
void PostOrder_1(BinTreeNode *t);
void LevelOrder(BinTree *pbt);
void LevelOrder_1(BinTreeNode *t);

size_t Size(BinTree *pbt);
size_t Size_1(BinTreeNode *t);
size_t Height(BinTree *pbt);
size_t Height_1(BinTreeNode *t);
BinTreeNode* Find(BinTree *pbt, DataType key);
BinTreeNode* Find_1(BinTreeNode *t, DataType key);
BinTreeNode* Parent(BinTree *pbt, BinTreeNode *key);
BinTreeNode* Parent_1(BinTreeNode *t, BinTreeNode *key);
void Copy(BinTree *bt1, BinTree *bt2); //bt1 ==> bt2
void Copy_1(BinTreeNode *t1, BinTreeNode **t2);
bool Equal(BinTree *bt1, BinTree *bt2);
bool Equal_1(BinTreeNode *t1, BinTreeNode *t2);

///////////////////////////////////////////////////////////
void PreOrderNoR(BinTree *pbt);
void PreOrderNoR_1(BinTreeNode *t);
void InOrderNoR(BinTree *pbt);
void InOrderNoR_1(BinTreeNode *t);
void PostOrderNoR(BinTree *pbt);
void PostOrderNoR_1(BinTreeNode *t);

void PreOrderNoR(BinTree *pbt)
{
	PreOrderNoR_1(pbt->root);
}
void PreOrderNoR_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode *p;
		Stack st; //BinTreeNode*
		StackInit(&st, 100);
		StackPush(&st, t);
		while (!StackIsEmpty(&st))
		{
			p = StackTop(&st);
			StackPop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				StackPush(&st, p->rightChild);
			if (p->leftChild != NULL)
				StackPush(&st, p->leftChild);
		}
	}
}

void InOrderNoR(BinTree *pbt)
{
	InOrderNoR_1(pbt->root);
}
void InOrderNoR_1(BinTreeNode *t)
{
	//??????????????????
}
void PostOrderNoR(BinTree *pbt)
{
	PostOrderNoR_1(pbt->root);
}
void PostOrderNoR_1(BinTreeNode *t)
{
	//???????????????????
}


////////////////////////////////////////////////////////////
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}

void CreateBinTree(BinTree *pbt)
{
	//CreateBinTree_1(&pbt->root);
	pbt->root= CreateBinTree_2();
	//CreateBinTree_3(&pbt->root,);
}

void CreateBinTree_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		CreateBinTree_1(&(*t)->leftChild);
		CreateBinTree_1(&(*t)->rightChild);
	}
}

BinTreeNode* CreateBinTree_2()
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode *t  = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = CreateBinTree_2();
		t->rightChild = CreateBinTree_2();
		return t;
	}
}

void CreateBinTreeByStr(BinTree *pbt, char *str)
{
	CreateBinTree_3(&pbt->root, str);
}
void CreateBinTree_3(BinTreeNode **t, char *s)
{
	static char *str = "ABC##DE##F##G#H##";
	if (*str == '\0')
		return;
	if (*str == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = *str;
		CreateBinTree_3(&(*t)->leftChild, ++str);
		CreateBinTree_3(&(*t)->rightChild, ++str);
	}
}

size_t Size(BinTree *pbt)
{
	return Size_1(pbt->root);
}
size_t Size_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
		return Size_1(t->leftChild) + Size_1(t->rightChild) + 1;
}

size_t Height(BinTree *pbt)
{
	return Height_1(pbt->root);
}
size_t Height_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		size_t left_h = Height_1(t->leftChild);
		size_t right_h = Height_1(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}

BinTreeNode* Find(BinTree *pbt, DataType key)
{
	return Find_1(pbt->root, key);
}
BinTreeNode* Find_1(BinTreeNode *t, DataType key)
{
	BinTreeNode *p;
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
	p = Find_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return Find_1(t->rightChild, key);
}

BinTreeNode* Parent(BinTree *pbt, BinTreeNode *key)
{
	return Parent_1(pbt->root, key);
}
BinTreeNode* Parent_1(BinTreeNode *t, BinTreeNode *key)
{
	BinTreeNode *p;
	if (t==NULL || t==key)
		return NULL;
	if (t->leftChild == key || t->rightChild == key)
		return t;
	p = Parent_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return Parent_1(t->rightChild, key);
}

void Copy(BinTree *bt1, BinTree *bt2)
{
	Copy_1(bt1->root, &bt2->root);
}
void Copy_1(BinTreeNode *t1, BinTreeNode **t2)
{
	if (t1 == NULL)
		*t2 = NULL;
	else
	{
		*t2 = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t2 != NULL);
		(*t2)->data = t1->data;
		Copy_1(t1->leftChild, &(*t2)->leftChild);
		Copy_1(t1->rightChild, &(*t2)->rightChild);
	}
}

bool Equal(BinTree *bt1, BinTree *bt2)
{
	return Equal_1(bt1->root, bt2->root);
}
bool Equal_1(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 != NULL&&t2 != NULL
		&& t1->data == t2->data
		&& Equal_1(t1->leftChild, t2->leftChild)
		&& Equal_1(t1->rightChild, t2->rightChild))
		return true;
	return false;
}

/////////////////////////////////////////////////////////


void PreOrder(BinTree *pbt)
{
	PreOrder_1(pbt->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}
void InOrder(BinTree *pbt)
{
	InOrder_1(pbt->root);
}
void InOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c ", t->data);
		InOrder_1(t->rightChild);
	}
}

void PostOrder(BinTree *pbt)
{
	PostOrder_1(pbt->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c ", t->data);
	}
}

void LevelOrder(BinTree *pbt)
{
	LevelOrder_1(pbt->root);
}
void LevelOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		Queue Q;
		QueueInit(&Q, 10);
		QueuePush(&Q, t);
		BinTreeNode *p;
		while (!QueueIsEmpty(&Q))
		{
			p = QueueFront(&Q);
			QueuePop(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				QueuePush(&Q, p->leftChild);
			if (p->rightChild != NULL)
				QueuePush(&Q, p->rightChild);
		}
	}
}

#endif /*_BINTREE_H_*/