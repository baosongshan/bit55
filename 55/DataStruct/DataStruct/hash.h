#ifndef _HASH_H_
#define _HASH_H_

#include"common.h"

#define P 7

typedef struct HashNode
{
	DataType data;
	struct HashNode *link;
}HashNode;

typedef HashNode* HashTable[P];

int Hash(DataType key)
{
	return key % P;
}

void HashInit(HashTable *pht);
bool HashInsert(HashTable pht, DataType x);
bool HashRemove(HashTable pht, DataType key);
void HashShow(HashTable pht);

void HashInit(HashTable pht)
{
	memset(pht, 0, sizeof(HashNode*)*P);
}
bool HashInsert(HashTable pht, DataType x)
{
	int index = Hash(x);
	HashNode *node = (HashNode*)malloc(sizeof(HashNode));
	if(node == NULL)
		return false;
	node->data = x;

	node->link = pht[index];
	pht[index] = node;

	return true;
}

bool HashRemove(HashTable pht, DataType key)
{
	int index = Hash(key);
	HashNode *cur = pht[index];
	HashNode *pre = NULL;

	while(cur!=NULL && cur->data!=key)
	{
		pre = cur;
		cur = cur->link;
	}
	if(cur == NULL)
		return false;

	if(pre == NULL)
		pht[index] = cur->link;
	else
		pre->link = cur->link;
	free(cur);
	return true;

}

/*
bool HashRemove(HashTable pht, DataType key)
{
	int index = Hash(key);
	HashNode *p = pht[index];
	while(p!=NULL && p->data!=key)
		p = p->link;

}
*/

void HashShow(HashTable pht)
{
	for(int i=0; i<P; ++i)
	{
		HashNode *p = pht[i];
		printf("%d : ",i);
		while(p != NULL)
		{
			printf("%d-->", p->data);
			p = p->link;
		}
		printf("Nul.\n");
	}
}


#endif /* _HASH_H_ */