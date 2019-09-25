#ifndef _BST_H_
#define _BST_H_

#include"common.h"
#define  BSTDataType int

typedef struct BSTNode
{
	BSTDataType data;
	struct BSTNode *leftChild;
	struct BSTNode *rightChild;
}BSTNode;

typedef struct BSTree
{
	BSTNode *root;
}BSTree;

void BSTreeInit(BSTree *pbst);
bool BSTreeInsert(BSTree *pbst, BSTDataType x);
bool BSTreeInsert_1(BSTNode **t, BSTDataType x);
BSTNode* BSTreeMin(BSTree *pbst);
BSTNode* BSTreeMin_1(BSTNode *t);
BSTNode* BSTreeMax(BSTree *pbst);
BSTNode* BSTreeMax_1(BSTNode *t);
BSTNode* BSTreeFind(BSTree *pbst, BSTDataType key);
BSTNode* BSTreeFind_1(BSTNode *t, BSTDataType key);

bool BSTreeErase(BSTree *pbst, BSTDataType key);
bool BSTreeErase_1(BSTNode **t, BSTDataType key);



void BSTreeInit(BSTree *pbst)
{
	pbst->root = NULL;
}

bool BSTreeInsert(BSTree *pbst, BSTDataType x)
{
	return BSTreeInsert_1(&pbst->root, x);
}
bool BSTreeInsert_1(BSTNode **t, BSTDataType x)
{
	if(*t == NULL)
	{
		*t = (BSTNode*)malloc(sizeof(BSTNode));
		(*t)->data = x;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		return true;
	}
	else if(x < (*t)->data)
	{
		BSTreeInsert_1(&(*t)->leftChild, x);
	}
	else if(x > (*t)->data)
	{
		BSTreeInsert_1(&(*t)->rightChild, x);
	}
	else
		return false;
}

BSTNode* BSTreeMin(BSTree *pbst)
{
	return BSTreeMin_1(pbst->root);
}
BSTNode* BSTreeMin_1(BSTNode *t)
{
	if(t == NULL)
		return t;
	while(t->leftChild != NULL)
	{
		t = t->leftChild;
	}
	return t;
}

BSTNode* BSTreeMax(BSTree *pbst)
{
	return BSTreeMax_1(pbst->root);
}
BSTNode* BSTreeMax_1(BSTNode *t)
{
	if(t == NULL)
		return t;
	while(t->rightChild != NULL)
	{
		t = t->rightChild;
	}
	return t;
}

BSTNode* BSTreeFind(BSTree *pbst, BSTDataType key)
{
	return BSTreeFind_1(pbst->root, key);
}
BSTNode* BSTreeFind_1(BSTNode *t, BSTDataType key)
{
	if(t == NULL)
		return NULL;
	if(t->data == key)
		return t;
	else if(key < t->data)
	{
		return BSTreeFind_1(t->leftChild, key);
	}
	else
		return BSTreeFind_1(t->rightChild, key);
}

bool BSTreeErase(BSTree *pbst, BSTDataType key)
{
	return BSTreeErase_1(&pbst->root, key);
}

bool BSTreeErase_1(BSTNode **t, BSTDataType key)
{
	if(*t == NULL)
		return false;
	if(key < (*t)->data)
		BSTreeErase_1(&(*t)->leftChild, key);
	else if(key > (*t)->data)
		BSTreeErase_1(&(*t)->rightChild, key);
	else
	{
		BSTNode *p = *t;
		if(p->leftChild!=NULL && p->rightChild!=NULL)
		{
			//
		}
		else
		{
		}
	}
	return true;
}

/*
bool BSTreeErase_1(BSTNode **t, BSTDataType key)
{
	if(*t == NULL)
		return false;
	if(key < (*t)->data)
		BSTreeErase_1(&(*t)->leftChild, key);
	else if(key > (*t)->data)
		BSTreeErase_1(&(*t)->rightChild, key);
	else
	{
		BSTNode *p = *t;
		if(p->leftChild==NULL && p->rightChild==NULL)
		{
			free(p);//free(*t);
			*t = NULL;
		}
		else if(p->leftChild!=NULL && p->rightChild==NULL)
		{
			*t = (*t)->leftChild;
			free(p);
		}
		else if(p->leftChild==NULL && p->rightChild!=NULL)
		{
			*t = (*t)->rightChild;
			free(p);
		}
		else
		{
			BSTNode *q = p->leftChild;
			while(q->rightChild != NULL)
				q = q->rightChild;
			p->data = q->data;
			BSTreeErase_1(&(*t)->leftChild, p->data);
		}
	}
	return true;
}
*/

#endif /*_BST_H_*/