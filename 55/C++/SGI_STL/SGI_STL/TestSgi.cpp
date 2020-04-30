//#define __USE_MALLOC

#include<iostream>
#include<assert.h>
//#include"stl_alloc.h"
#include"stl_vector.h"
using namespace std;




/*
class String
{
private:
	char *m_data;
};

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout<<"Test::Test(int d)."<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Test::Test(const Test &t)."<<endl;
		m_data = t.m_data;
	}
	//operator= 无关紧要
private:
	int m_data;
};

void main()
{
	vector<int> iv(2, 5);  //2 0
	vector<Test> iv1(2, Test());
}

/*
void main()
{
	Test t1(100);
	Test t2(200);
	t1 = t2;
}

/*
void main()
{
	vector<int> iv(2, 5);  //2 0
}

/*
void main()
{
	//int *p = malloc(sizeof(int)*50);
	//int *p = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*50);
	//客户目的 4 内存池
	int *p1 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)); //4 8

	int *p2 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int));
	int *p3 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*32);
	int *p4 = (int*)__default_alloc_template<0, 0>::allocate(sizeof(int)*10);

	__default_alloc_template<0,0>::deallocate(p1, sizeof(int));
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