#include<vld.h>
#include"common.h"
//#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include"stack.h"
//#include"queue.h"
//#include"bintree.h"
//#include"bst.h"
//#include"heap.h"
#include"sort.h"


int main()
{
	//int ar[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
	//int ar[] = {8, 6, 3, 5, 4};
	//int ar[] = {10,6,7,1,3,9,4,2};
	int ar[] = {332, 633, 589, 232,8132, 4, 664, 179, 457, 825, 405,361};
	int n = sizeof(ar) / sizeof(int);
	
	//MyShelloSort(ar, 0, n-1);
	//PrintArray(ar, 0, n-1);

	TestSort(ar, 0, n-1);
	TestSortPerForMance();

	return 0;
}

#if 0
int main()
{
	int ar[] = {27,15,19,18,28,34,65,49,25,37};
	int n = sizeof(ar) / sizeof(int);
	Heap hp;
	DataType ret;
	HeapInit(&hp, DEFAULT_HEAP_SIZE);

	for(int i=0; i<n; ++i)
	{
		HeapPush(&hp, ar[i]);
	}
	HeapShow(&hp);
	HeapTop(&hp, &ret);
	printf("Heap Top = %d\n", ret);

	//HeapPop(&hp);

	HeapShow(&hp);
	HeapTop(&hp, &ret);
	printf("Heap Top = %d\n", ret);

	HeapSort(&hp);

	HeapDestroy(&hp);
	return 0;
}



int main()
{
	int ar[] = {54,23,76,25,34,3,7,8,9,5,1,70};
	int n = sizeof(ar) / sizeof(int);
	BSTree bst;
	BSTreeInit(&bst);

	for(int i=0; i<n; ++i)
	{
		BSTreeInsert(&bst, ar[i]);
	}

	BSTNode *p = BSTreeMin(&bst);
	p = BSTreeFind(&bst, 250);

	BSTreeErase(&bst, 23);
	return 0;
}



//ABC##DE##F##G#H##
int main()
{
	char *VLR = "ABCDEFGH";
	char *LVR = "CBEDFAGH";
	char *LRV = "CEFDBHGA";

	char *str = "ABC##DE##F##G#H##";
	BinTree bt, bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);

	//CreateBinTree(&bt);
	//CreateBinTreeByStr(&bt, str);
	int n = strlen(LVR);
	CreateBinTree_VLR_LVR(&bt, VLR, LVR, n);

	printf("VLR : "); //A B C D E F G H
	//PreOrder(&bt);
	PreOrderNoR(&bt);
	printf("\n");
	printf("LVR : "); // C B E D F A G H
	//InOrder(&bt);
	InOrderNoR(&bt);
	printf("\n");
	printf("LRV : "); // C E F D B H G A
	//PostOrder(&bt);
	PostOrderNoR(&bt);
	printf("\n");
	printf("Level : "); // C E F D B H G A
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", Size(&bt));
	printf("Height = %d\n", Height(&bt));
	BinTreeNode *p = Find(&bt, 'E');
	BinTreeNode *pr = Parent(&bt, p);

	Copy(&bt, &bt1);

	bool flag = Equal(&bt, &bt1);


	return 0;
}


int main()
{
	CircleQueue Q;
	CircleQueueInit(&Q, 8);

	CircleQueuePush(&Q, 1);
	CircleQueuePush(&Q, 2);
	CircleQueuePush(&Q, 3);
	CircleQueuePush(&Q, 4);
	CircleQueuePush(&Q, 5);
	CircleQueuePush(&Q, 6);
	CircleQueuePush(&Q, 7);
	CircleQueuePush(&Q, 8);
	CircleQueueShow(&Q);
	CircleQueuePop(&Q);
	CircleQueueShow(&Q);

	CircleQueuePush(&Q, 8);
	CircleQueueShow(&Q);

	CircleQueuePop(&Q);
	CircleQueueShow(&Q);

	CircleQueuePush(&Q, 9);
	CircleQueueShow(&Q);


	return 0;
}


int main()
{
	ListQueue Q;
	ListQueueInit(&Q);
	ListQueuePush(&Q, 1);
	ListQueuePush(&Q, 2);
	ListQueuePush(&Q, 3);
	ListQueuePush(&Q, 14);
	ListQueuePush(&Q, 5);

	ListQueueShow(&Q);

	ListQueuePop(&Q);

	ListQueueShow(&Q);

	return 0;
}


int main()
{
	Queue Q;
	QueueInit(&Q, 10);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueuePush(&Q, 5);
	QueuePush(&Q, 6);

	QueueShow(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
	QueueShow(&Q);


	QueuePush(&Q, 10);
	QueuePush(&Q, 20);
	QueuePush(&Q, 30);
	QueuePush(&Q, 40);
	QueuePush(&Q, 50);
	QueuePush(&Q, 60);

	QueueShow(&Q);
	return 0;
}


int main(int argc, char *argv[])
{
	Stack st;
	//void StackInit(Stack *pst, size_t sz)
	StackInit(&st, 10);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackShow(&st);
	printf("----------------\n");
	//DataType val = StackTop(&st);
	StackPop(&st);
	StackPop(&st);

	StackShow(&st);

	StackDestroy(&st);
	return  0;
}


int main(int argc, char *argv[])
{
	//SeqList mylist;

	DCListNode *p = NULL;
	DCList mylist; //栈
	DCListInit(&mylist);

	DataType item;
	int pos, index;
	BOOL flag;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_val    [9] delete_val *\n");
		printf("* [10] delete_pos   [11]length     *\n");
		printf("* [12] remove_all   [13] reverse   *\n");
		printf("* [14] sort         [15] clear     *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要查询的位置:>");
			scanf("%d", &pos);
			//printf("要查询的数据:%d\n", SeqListFindByPos(&mylist, pos));
			break;
		case 7:
			printf("请输入要查询的数据:>");
			scanf("%d", &item);
			//index = SeqListFindByVal(&mylist, item);
			p = DCListFindByVal(&mylist, item);
			if (p==NULL)
				printf("要查询的数据%d不存在.\n", item);
			break;
		case 8:
			//printf("请输入要插入的位置:>");
			//scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			///flag = SListInsertByVal(&mylist, item);
			if (flag)
				printf("插入成功.\n");
			else
				printf("插入失败.\n");
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			//flag = SeqListEraseByVal(&mylist, item);
			DCListEraseByVal(&mylist, item);
			break;
		case 10:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//flag = SeqListEraseByPos(&mylist, pos);
			if (flag)
				printf("删除成功.\n");
			else
				printf("删除失败.\n");
			break;
		case 11:
			printf("SeqList Length = %d\n", DCListLength(&mylist));
			break;
		case 12:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			//SeqListRemoveAll(&mylist, item);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			DCListSort(&mylist);
			break;
		case 15:
			DCListClear(&mylist);
			break;
		}
	}

	DCListDestroy(&mylist);
	return 0; 
}
#endif