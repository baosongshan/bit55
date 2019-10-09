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

void ShellSort(int *ar, int left, int right)
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

void TestSort(int *ar, int left, int right)
{
	//InsertSort_1(ar, left, right);
	//BinInsertSort(ar, left, right);
	ShellSort(ar, left, right);
	//TwoWayInsertSort(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSortPerForMance()
{
	int n = 100000;
	int *a1 = (int *)malloc(sizeof(int)*n);
	int *a2 = (int *)malloc(sizeof(int)*n);
	int *a3 = (int *)malloc(sizeof(int)*n);
	int *a4 = (int *)malloc(sizeof(int)*n);
	int *a5 = (int *)malloc(sizeof(int)*n);

	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
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

	free(a1);
}


#endif /*_SORT_H_*/