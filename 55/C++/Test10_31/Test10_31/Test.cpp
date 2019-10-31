#include<iostream>
#include"stack.h"
using namespace std;

void main()
{
	Stack<int> Int_st;
}

/*
template<typename Type>
class Stack
{
public:
	Stack(size_t sz = STACK_DEFAULT_SIZE);
	~Stack();
public:
	void push(const Type &x);
	void pop();
	Type top()const;
	Type& top();
public:
	bool empty()const;
	bool full()const;
private:
	enum {STACK_DEFAULT_SIZE = 20};
	Type *base;
	size_t capacity;
	size_t top;
};


void main()
{
	Stack<int> Int_st;
	Stack<int> *ps = new Stack<int>;
}

/*
template<typename Type>
class Stack
{
public:
	Stack(size_t sz = STACK_DEFAULT_SIZE)
	{
		capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
		base = new Type[capacity];
		top = 0;
	}
	~Stack()
	{
		delete []base;
		capacity = top = 0;
	}
public:
	void push(const Type &x);
	void pop();
	Type top()const;
	Type& top();
public:
	bool empty()const;
	bool full()const;
private:
	enum {STACK_DEFAULT_SIZE = 20};
	Type *base;
	size_t capacity;
	size_t top;
};

void main()
{
	Stack<int> Int_st;
}

//泛型

/*
//特化
char Max(char a, char b)
{
	return a > b ? a : b;
}
short Max(short a, short b)
{
	return a > b ? a : b;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}
*/



/*
//函数模板   -->  模板函数
class Test
{};

template<class Type1, class Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(1, 1.2)<<endl;  //char
}

/*
//不高
template<typename Type1, typename Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(1, 1.2)<<endl;  //char
}

/*
void main()
{
	cout<<Max('A', 'B')<<endl;  //char
	cout<<Max(10,20)<<endl;     //int
	cout<<Max(12.34,23.45)<<endl; //double
	cout<<Max((double)1,2.3)<<endl;
	cout<<Max(1,(int)2.3)<<endl;
	cout<<Max<int>(1, 2)<<endl;
}

/*
void main()
{
	int *p = new int[1073741824];
	cout<<p<<endl;
	return;
}


class Test
{
public:
	static Test* Instance()
	{
		if(m_instance == nullptr)
		{
			m_instance =  new Test;
		}
		return m_instance;
	}
private:
	Test(int d = 0)
	{
		m_data = d;
	}
private:
	int m_data;
	static Test * m_instance;
};

Test * Test::m_instance = nullptr;

void main()
{
	Test *pt = Test::Instance();
	Test *pt1 = Test::Instance();
	Test *pt2 = Test::Instance();
}

String& operator=(const String &s)
{
	if(this ！= &s)
	{
		delete []m_data;
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	return *this;
}


/*
//set_new_handler
//0 尽可能 满足 需求
//1 申请成功 直接返回
//2 申请不成功，设置了set_new_handler方法，有可能成功返回
//3 内存确实不足，抛出异常

void Out_Of_Memory()
{
	cout<<"new:Out Of Memory."<<endl;
	//执行内存回收
	//exit(1);
}

void main()
{
	set_new_handler(Out_Of_Memory);
	int *p = new int[536870911];//  new
	//int *p = new int[5];
	delete []p;
}

/*
void main()
{
	int *q = (int*)malloc(sizeof(int)*536870912);
	if(NULL == q)
	{
		cout<<"malloc:Out Of Memory."<<endl;
		exit(1);
	}
	int *p = new int[10];
	if(p == NULL)
	{
		cout<<"new:Out Of Memory."<<endl;
		exit(1);
	}
	delete []p;
}

/*
class Test
{
public:
	Test(int d = 0)
	{
		m_data = d;
	}
private:
	void* operator new(size_t);
private:
	int m_data;
};

void main()
{
	Test t1(10);
	Test *pt = new Test(10); //operator new
}


/*
class Test
{
	friend Test* CreateTestObject(int data);
public:
	static Test* CreateObject(int data)
	{
		return new Test(data);
	}
private:
	Test(int d = 0)
	{
		m_data = d;
	}
protected: //继承
	Test(const Test &);// = delete;
	Test& operator=(const Test &);
private:
	int m_data;
};

Test* CreateTestObject(int data)
{
	return new Test(data);
}

int main()
{
	//Test t(1);
	//Test t1(t);
	//Test t2;
	//t2 = t;
	//Test *pt = Test::CreateObject(1);
	Test *pt = CreateTestObject(1);
	return 0;
}
*/