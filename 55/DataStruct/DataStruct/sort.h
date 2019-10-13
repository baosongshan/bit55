#ifndef _SORT_H_
#define _SORT_H_

#include"common.h"

void PrintArray(int *ar, int left, int right)
{
	for(int i=left; i<=right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

//直接插入排序 调用Swap
void InsertSort_1(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		int end = i-1;
		while(end>=left && ar[end+1]<ar[end])
		{
			Swap(&ar[end+1], &ar[end]);
			end--;
		}
	}
}
//直接插入排序 数据覆盖
void InsertSort_2(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		int key = ar[i];
		int end = i-1;
		while(end>=left && key<ar[end])
		{
			ar[end+1] = ar[end];
			end--;
		}
		ar[end+1] = key;
	}
}
//直接插入排序 哨兵位
void InsertSort_3(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		//哨兵位
		ar[0] = ar[i];
		int end = i-1;
		while(ar[0] < ar[end]) //
		{
			ar[end+1] = ar[end];
			end--;
		}
		ar[end+1] = ar[0];
	}
}

void BinInsertSort(int *ar, int left, int right)
{
	int low, high, mid;
	int tmp, j;
	for(int i=left+1; i<=right; ++i)
	{
		low = left;
		high = i-1;
		tmp = ar[i];
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(tmp < ar[mid])
				high = mid-1;
			if(tmp >= ar[mid])
				low = mid+1;
		}
		for(j=i; j>low; --j)
		{
			ar[j] = ar[j-1];
		}
		ar[low] = tmp;
	}
}

void TwoWayInsertSort(int *ar, int left, int right)
{
	int n = right-left+1;
	int *tmp = (int *)malloc(sizeof(int) * n);

	tmp[0] = ar[left];
	int start, final;
	start = final = 0;

	int key;
	for(int i=left+1; i<=right; ++i)
	{
		key = ar[i];
		if(key < tmp[start])
		{
			start = (start-1+n) % n;
			tmp[start] = key;
		}
		else if(key > tmp[final])
		{
			final++;
			tmp[final] = key;
		}
		else
		{
			int end = final;
			final++;
			while(key < tmp[end])
			{
				tmp[(end+1)%n] = tmp[end];
				end = (end-1+n) % n;
			}
			tmp[(end+1)%n] = key;
		}
	}

	for(int i=0; i<n; ++i)
	{
		ar[i] = tmp[start];
		start = (start+1) % n;
	}
	free(tmp);
}

void ShellSort(int *ar, int left, int right)//
{
	int gap = right-left+1;
	while(gap > 1)
	{
		gap = gap/3+1;
		for(int i=left; i<=right-gap; ++i)
		{
			int end = i;
			int tmp = ar[end+gap];
			while(end>=left && tmp<ar[end])
			{
				ar[end+gap] = ar[end];
				end -= gap;
			}
			ar[end+gap] = tmp;
		}
	}
}

//直接选择排序
int GetMinIndex(int *ar, int left, int right)
{
	int index = left;
	int min = ar[left];
	for(int i=left+1; i<=right; ++i)
	{
		if(min > ar[i])
		{
			min = ar[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *ar, int left, int right)
{
	for(int i=left; i<right; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if(index != i)
			Swap(&ar[index], &ar[i]);
	}
}

void AdjustDown(int *ar, int n, int start)
{
	int i = start;
	int j = 2*i+1;
	while(j < n)
	{
		if(j+1<n && ar[j]<ar[j+1])
			j++;
		if(ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
}

void HeapSort(int *ar, int left, int right)
{
	int n = right-left+1;
	int cur = (n-1) / 2;
	while(cur > left)
	{
		AdjustDown(ar, n, cur);
		cur--;
	}
	//PrintArray(ar, left, right);
	//Sort
	int end = right;
	while(end >= left)
	{
		Swap(&ar[left], &ar[end]);
		AdjustDown(ar, end-left, 0);
		end--;
	}

}

//交换排序
void BubbleSort(int *ar, int left, int right)
{
	for(int i=left; i<right; ++i)
	{
		bool isswap = false;
		for(int j=left; j<right-i; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				Swap(&ar[j], &ar[j+1]);
				isswap = true;
			}
		}
		if(!isswap)
			break;
	}
}

//快速排序
int GetMidIndex(int *ar, int left, int right)
{
	int mid = (left + right) / 2;
	if(ar[left]>ar[mid] && ar[left]<ar[right])
		return left;
	if(ar[mid]>ar[left] && ar[mid]<ar[right])
		return mid;
	return right;
}

int Partition1(int *ar, int left, int right)
{
	int key = ar[left];
	while(left < right)
	{
		while(left<right && ar[right]>=key)
			right--;
		Swap(&ar[left], &ar[right]);
		while(left<right && ar[left]<key)
			left++;
		Swap(&ar[left], &ar[right]);
	}
	return left;
}

int Partition2(int *ar, int left, int right)
{
	int key = ar[left];
	while(left < right)
	{
		while(left<right && ar[right]>=key)
			right--;
		//Swap(&ar[left], &ar[right]);
		ar[left] = ar[right];
		while(left<right && ar[left]<key)
			left++;
		//Swap(&ar[left], &ar[right]);
		ar[right] = ar[left];
	}
	ar[left] = key;
	return left;
}

int Partition3(int *ar, int left, int right)
{
	int mid = GetMidIndex(ar, left, right);
	if(mid != left)
		Swap(&ar[left], &ar[mid]);

	int key = ar[left];
	int pos = left;
	for(int i=left+1; i<=right; ++i)
	{
		if(ar[i] < key)
		{
			pos++;
			if(pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

#define M 3
void QuickSort(int *ar, int left, int right)
{
	if(left >= right)
		return;

	if(right -left+1 <= M)
		InsertSort_2(ar, left, right);
	else
	{
		int pos = Partition3(ar, left, right);
		QuickSort(ar, left, pos-1);
		QuickSort(ar, pos+1, right);
	}
}

//归并排序
void _MergeSort(int *ar, int left, int right, int *tmp)
{
	if(left >= right)
		return;
	int mid = (left+right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid+1, right, tmp);

	int begin1 = left; //左区间 [left,mid]
	int end1 = mid;
	int begin2 = mid+1;//右区间[mid+1, right]
	int end2 = right;

	int i = left;
	while(begin1<=end1 && begin2<=end2)
	{
		if(ar[begin1] < ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}

	while(begin1 <= end1)
		tmp[i++] = ar[begin1++];
	while(begin2 <= end2)
		tmp[i++] = ar[begin2++];

	memcpy(ar+left, tmp+left, sizeof(int)*(right-left+1));
}

void MergeSort(int *ar, int left, int right)
{
	int n = right-left+1;
	int *tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(ar, left, right, tmp);

	free(tmp);
}

//基数排序
#include"slist.h"
#define K 4
SList list[10];

int GetKeyOfValue(int value, int k)
{
	int key;
	while(k>=0) //232  k=1
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int *ar, int left, int right, int k)
{
	int key;
	for(int i=0; i<10; ++i)
	{
		SListClear(&list[i]);
	}
	for(int i=left; i<=right; ++i)
	{
		key = GetKeyOfValue(ar[i], k);
		SListPushBack(&list[key], ar[i]);
	}
}
void Collect(int *ar, int left, int right)
{
	int k = left;
	SListNode *p;
	for(int i=0; i<10; ++i)
	{
		p = list[i].first->next;
		while(p != NULL)
		{
			ar[k++] = p->data;
			p = p->next;
		}
	}
}
void RadixSort(int *ar, int left, int right)
{
	for(int i=0; i<10; ++i)
	{
		SListInit(&list[i]);
	}
	for(int i=0; i<K; ++i)
	{
		Distribute(ar, left, right, i);
		Collect(ar, left, right);
	}
}
void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);
	//BinInsertSort(ar, left, right);
	//ShellSort(ar, left, right);
	//TwoWayInsertSort(ar, left, right);
	//SelectSort(ar, left, right);
	//HeapSort(ar, left, right);
	//BubbleSort(ar, left, right);
	//QuickSort(ar, left, right);
	//MergeSort(ar, left, right);
	RadixSort(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSortPerForMance()
{
	int n = 1000;
	int *a1 = (int *)malloc(sizeof(int)*n);
	int *a2 = (int *)malloc(sizeof(int)*n);
	int *a3 = (int *)malloc(sizeof(int)*n);
	int *a4 = (int *)malloc(sizeof(int)*n);
	int *a5 = (int *)malloc(sizeof(int)*n);
	int *a6 = (int *)malloc(sizeof(int)*n);
	int *a7 = (int *)malloc(sizeof(int)*n);
	int *a8 = (int *)malloc(sizeof(int)*n);
	int *a9 = (int *)malloc(sizeof(int)*n);

	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}

	size_t begin1 = clock();
	InsertSort_1(a1, 0, n-1);
	size_t end1 = clock();
	printf("InsertSort_1 time: %u\n", end1-begin1);

	size_t begin2 = clock();
	InsertSort_2(a2, 0, n-1);
	size_t end2 = clock();
	printf("InsertSort_1 time: %u\n", end2-begin2);

	size_t begin3 = clock();
	BinInsertSort(a3, 0, n-1);
	size_t end3 = clock();
	printf("BinInsertSort time: %u\n", end3-begin3);

	size_t begin4 = clock();
	TwoWayInsertSort(a4, 0, n-1);
	size_t end4 = clock();
	printf("TwoWayInsertSort time: %u\n", end4-begin4);

	size_t begin5 = clock();
	ShellSort(a5, 0, n-1);
	size_t end5 = clock();
	printf("ShellInsertSort time: %u\n", end5-begin5);

	size_t begin6 = clock();
	SelectSort(a6, 0, n-1);
	size_t end6 = clock();
	printf("SelectInsertSort time: %u\n", end6-begin6);

	size_t begin7 = clock();
	HeapSort(a7, 0, n-1);
	size_t end7 = clock();
	printf("HeapSort time: %u\n", end7-begin7);

	size_t begin8 = clock();
	BubbleSort(a8, 0, n-1);
	size_t end8 = clock();
	printf("BubbleInsertSort time: %u\n", end8-begin8);

	size_t begin9 = clock();
	QuickSort(a9, 0, n-1);
	size_t end9 = clock();
	printf("QuickSort time: %u\n", end9-begin9);

	free(a1);
}

/*
void _ShellSort(int *ar, int left, int right, int gap)
{
	for(int i=left+gap; i<=right; ++i)
	{
		if(ar[i] < ar[i-gap])
		{
			int tmp = ar[i];
			int end = i-gap;
			for(;end>=left&&tmp<ar[end];end-=gap)
			{
				ar[end+gap] = ar[end];
			}
			ar[end+gap] = tmp;
		}
	}
}

void MyShelloSort(int *ar, int left, int right)
{
	int dk[] = {5,3,2,1}; //???????
	int n = sizeof(dk) / sizeof(int);

	for(int i=0; i<n; ++i)
	{
		_ShellSort(ar, left, right, dk[i]);
	}
}

*/


#endif /*_SORT_H_*/