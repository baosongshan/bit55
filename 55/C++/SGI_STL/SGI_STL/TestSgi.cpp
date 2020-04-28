#include<iostream>
#include<assert.h>
#include"stl_alloc.h"
using namespace std;

void main()
{
	//int *p = malloc(sizeof(int)*50);
	//int *p = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*50);
	//客户目的 4 内存池
	int *p1 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int));
	int *p2 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int));
	int *p3 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*32);
	int *p4 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*10);
}

/*
void* operator new(size_t sz) //1
{
	void *ptr = malloc(sz);
	return ptr;
}
void operator delete(void *ptr)
{
	free(ptr);
}

void* operator new[](size_t sz) //1 cookie
{
	void *ptr = malloc(sz);
	return ptr;
}
void operator delete[](void *ptr)
{
	free(ptr);
}

class Test
{
public:
	Test()
	{}
private:
	int m_data;
};


void main()
{
	int *pa = new int(1); //1  2
	//delete pa;

	int *pb = new int[10]; //40
	//int *pn = (int*)operator new[](sizeof(int)*10);
	delete []pb; //40

	Test *pt = new Test[10];
	//delete []pt;
}

/*
void* operator new(size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}

void* operator new[](size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}


void main()
{
	int *pa = new int(1); //1  2
	delete pa;

	int *pb = new int[10];
	//int *pn = (int*)operator new[](sizeof(int)*10);
	//delete []pb;

	Test *pt = new Test[10];
	delete []pt;
}

*/