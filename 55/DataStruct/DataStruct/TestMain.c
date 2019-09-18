#include"common.h"
#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dlist.h"
#include"dclist.h"


int main(int argc, char *argv[])
{
	//SeqList mylist;

	DCListNode *p = NULL;
	DCList mylist; //ջ
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
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
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
			printf("������Ҫ��ѯ��λ��:>");
			scanf("%d", &pos);
			//printf("Ҫ��ѯ������:%d\n", SeqListFindByPos(&mylist, pos));
			break;
		case 7:
			printf("������Ҫ��ѯ������:>");
			scanf("%d", &item);
			//index = SeqListFindByVal(&mylist, item);
			p = DCListFindByVal(&mylist, item);
			if (p==NULL)
				printf("Ҫ��ѯ������%d������.\n", item);
			break;
		case 8:
			//printf("������Ҫ�����λ��:>");
			//scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			///flag = SListInsertByVal(&mylist, item);
			if (flag)
				printf("����ɹ�.\n");
			else
				printf("����ʧ��.\n");
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			//flag = SeqListEraseByVal(&mylist, item);
			DCListEraseByVal(&mylist, item);
			break;
		case 10:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//flag = SeqListEraseByPos(&mylist, pos);
			if (flag)
				printf("ɾ���ɹ�.\n");
			else
				printf("ɾ��ʧ��.\n");
			break;
		case 11:
			printf("SeqList Length = %d\n", DCListLength(&mylist));
			break;
		case 12:
			printf("������Ҫɾ��������:>");
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
