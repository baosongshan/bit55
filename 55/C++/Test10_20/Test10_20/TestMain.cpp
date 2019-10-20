#include<iostream>
#include"Test.h"
using namespace std;

void main(int argc, char *argv[])
{}

/*
class Int
{
public:
	Int Add(const int v);
private:
	int m_i;
};

void main()
{
	Int i, j; //  int i;
	i = 0;
	Int v = i.Add(j);
	Int v = i.Sub(j);
	//Int v = i++;
	//v = ++i;
}



class SeqList
{
public:
	SeqList(int sz=DEFAULT_SEQLSIT_SIZE)
	{
		capacity = sz > DEFAULT_SEQLSIT_SIZE ? sz : DEFAULT_SEQLSIT_SIZE;
		base = (int *)malloc(sizeof(int) * capacity);
		size = 0;
	}
	~SeqList()
	{
		free(base);
		base = NULL;
		capacity = size = 0;
	}
private:
	enum{DEFAULT_SEQLSIT_SIZE=10};
	int *base;
	int  capacity;
	int  size;
};

void main()
{
	SeqList mylist;

}

/*
class Test
{
public:
	Test(int d) : m_data(d) //初始化
	{
		//m_data = d; //赋值
	}
private:
	int m_data;
};

void main()
{
	Test t(100);
}

/*
class Time
{
public:
	Time(int h, int m, int s)
	{
		cout<<"Time::Time()"<<endl;
		hour = h;
		minute = m;
		second = s;
	}
private:
	int hour;
	int minute;
	int second;
};

class Date
{
public:
	Date(int y, int m, int d) : t(20,44,30)
	{
		cout<<"Date::Date()"<<endl;
		year = y;
		month = m;
		day = d;
	}
private:
	int year;
	int month;
	int day;

	Time t;
};

void main()
{
	Date d(2019,10,20);
}

/*
class Test
{
public:
	Test()
	{}
	Test(int d = 0)
	{
		m_data = d;
	}
public:
	// int GetData(Test * const this)
	int GetData()
	{
		//m_data = 100;
		return m_data;
	}
	//int GetData(const Test * const this)
	int GetData()const
	{
		//m_data = 200;
		return m_data;
	}
private:
	int m_data;
};

void main()
{
	Test t1;
	Test t(10);
	cout<<t.GetData()<<endl;
}

/*
class Test
{
public:
	//1
	Test()
	{}
	//2
	Test(const Test &t)
	{m_data = t.m_data;}
	//3
	Test& operator=(const Test &t)
	{
		m_data = t.m_data;
		return *this;
	}
	//4
	~Test()
	{}
	/*
	//5
	Test* operator&()
	{
		return this;
	}
	//6
	const Test* operator&()const
	{
		return this;
	}
	
private:
	int m_data;
};

void main()
{
	Test t;
	Test t1(t);
	Test t2;
	t2 = t1;

	Test *pt = &t;

	const Test ct;
	const Test *pt1 = &ct;
}

/*
class Test
{
public:
	//Test t;
	//Test t(1)
	//Test t();//
	//1 构造对象 2 初始化 3 类型转换
	Test(int d = 0)
	{
		cout<<"Create Test Object : "<<this<<endl;
		m_data = d;
	}
	//拷贝构造函数
	// Test t2(t1);
	Test(const Test &t) //语义 语法
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		m_data = t.m_data;
	}
	//
	Test& operator=(const Test &t)
	//void operator=( Test t) // 赋值语句
	{
		cout<<"Assign :"<<this<<" : "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		//return *this;
	}
	//
	~Test()
	{
		cout<<"Free Test Object : "<<this<<endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
	void SetData(Test &t)
	{
		this->m_data = t.m_data;
	}
private:
	int m_data;
};

Test fun(Test x)
{
	//cout<<"x.data = "<<x.GetData()<<endl;
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}

void main()
{
	Test t1(10);
	Test t2(t1); 
	//fun(t1);
	Test t3;
	t3 = t2; //t3.operator=(t2);
}

/*
void main()
{
	Test t1(10);
	Test t2(t1);   //
	Test t3 = t2;  //初始化

	Test t4;
	t4 = t3; //赋值
}

/*
class Test
{
public:
	//构造函数
	Test()
	{
		cout<<"Create Test Object : "<<this<<endl;
		m_data = 0;
	}
	Test(int d)
	{
		m_data = d;
	}
private:
	int m_data;
};
void main()
{
	Test t; //自动  RAII
}

/*
class Test
{
public:
	//void SetData(Test *const this, int data, int value);
	void SetData(int m_data, int m_value)
	{
		this->m_data = m_data;
		this->m_value = m_value;
	}
	//int GetData( Test * const this)
	int GetData()
	{
		this->m_data = 100;
		return m_data;
	}
	int GetValue()
	{
		return this->m_value;
	}
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
private:
	int m_data;
	int m_value;
};


void main()
{
	Test t1, t2;
	t1.SetData(10,20);//SetData(&t1, 10, 20)
	t2.SetData(30,40);//SetData(&t2, 30, 40)
	//cout<<sizeof(t1)<<endl;
	                 // GetData(&t1);
	cout<<"t1.data = "<<t1.GetData()<<endl;
	                 // GetData(&t2);
	cout<<"t2.data = "<<t2.GetData()<<endl;
}

/*
struct Student
{
	int id;
	int age;
	int height;
};

void StudentInit(Student *_this, int i, int a, int h)
{
	_this->id = i;
	_this->age = a;
	_this->height = h;
}

void main()
{
	Student s1, s2;
	StudentInit(&s1,1000, 20, 165);
	StudentInit(&s2,2000, 20, 175);

}

//
/*
class Test
{
public:
	void SetData(int data, int value)
	{
		m_data = data;
		m_value = value;
	}
	int GetData()
	{
		return m_data;
	}
	int GetValue()
	{
		return m_value;
	}
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
private:
	int m_data;
	int m_value;
};
void main()
{
	Test t1, t2;
	t1.SetData(10,20);
	t2.SetData(30,40);
	//cout<<sizeof(t1)<<endl;
	cout<<"t1.data = "<<t1.GetData()<<endl;
	cout<<"t2.data = "<<t2.GetData()<<endl;
}

/*
class CGoods
{
public:
	void RegisterGoods(char *n, float p, int c)
	{
		strcpy(name, n);
		price = p;
		count = c;
	}
	char* GetName()
	{
		return name;
	}
	int   GetCount()
	{
		return count;
	}
	float GetTotalPrice()
	{
		return count * price;
	}
private:
	char name[100];
	float price;
	int count;
	float total_price;
};

int main()
{
	CGoods g1, g2;
	g1.RegisterGoods("C++", 52.3, 20);
	g2.RegisterGoods("Java",40, 30);
	return 0;
}


/*
class CGoods
{
public:
	void RegisterGoods(char *n, float p, int c)
	{
		strcpy(name, n);
		price = p;
		count = c;
	}
	char* GetName()
	{
		return name;
	}
	int   GetCount()
	{
		return count;
	}
	float GetTotalPrice()
	{
		return count * price;
	}
private:
	char name[100];
	float price;
	int count;
	float total_price;
};

int main()
{
	CGoods g1, g2;
	g1.RegisterGoods("C++", 52.3, 20);
	g2.RegisterGoods("Java",40, 30);
	return 0;
}

/*
class Test
{
public:
	int m_data;
	int m_value;
};
int main()
{
	Test t;
	t.m_data = 10;
	return 0;
}

/*
//类
class Student
{
public:
	//成员方法 -->接口
	void SetStudent(char *n, char *s, int a)
	{
		strcpy(name, n);
		strcpy(sex, s);
		age = a;
	}
protected:
	void fun()
	{
		cout<<"This is Student::fun()"<<endl;
	}
private:
	//数据成员
	char name[10];
	char sex[3];
	int age;
};

void main()
{
	Student s1; //实例化 对象
	s1.SetStudent("杨致远","男", 20);
	s1.fun();
}


/*
struct Student
{
	char name[10];
	char sex[3];
	int age;
};
void SetStudent(Student *pst, char *n, char *s, int a)
{
	strcpy(pst->name, n);
	strcpy(pst->sex, s);
	pst->age = a;
}

void main()
{
	Student s1;
	//s1.SetStudent("杨致远","男", 20);
	SetStudent(&s1, "杨致远","男", 20);
}

/*
//封装
struct Student
{
	void SetStudent(char *n, char *s, int a)
	{
		strcpy(name, n);
		strcpy(sex, s);
		age = a;
	}
	char name[10];
	char sex[3];
	int age;
};

void main()
{
	Student s1;
	s1.SetStudent("杨致远","男", 20);
}


/*
void fun(int)
{
	cout<<"This is fun 1."<<endl;
	//cout<<a<<endl;
}
void fun(int *p)
{
	cout<<"This is fun 2."<<endl;
}

void fun(nullptr_t nul)
{
	cout<<"This is fun 2."<<endl;
}

int  main()
{
	int a = 10;
	fun(a);
	int *p = NULL;
	fun(p);

	int c = NULL; // 0
	fun((int*)c);

	int *q = nullptr;
	fun(q);

	cout<<sizeof(nullptr)<<endl;

	return 0;
}

/*
//内联  只是一种建议

//void fun(int *ar)
void fun(int ar[5])
{
	//for(auto e : ar)
	//	cout<<e<<" ";
	cout<<endl;
}

int main()
{
	int ar[] = {1,2,3,4,5};
	int n = sizeof(ar) / sizeof(int);
	for(int i=0; i<n; ++i)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;

	for(auto &e : ar) //
	{
		//cout<<e<<" ";
		e *= 2;
	}
	cout<<endl;

	//fun(ar);

	for(auto &e : ar) //
	{
		cout<<e<<" ";
		//e *= 2;
	}
	cout<<endl;

	return 0;
}

/*
void fun(auto p)
{}

int main()
{
	auto ar[] = {1,2,3,4,5};
	int a = 10;
	auto x = &a;
	auto *y = &a; //int *y = &a;
	auto &z = a;
	cout<<typeid(x).name()<<endl;
	cout<<typeid(y).name()<<endl;
	cout<<typeid(z).name()<<endl;

	fun(a);
	return 0;
}

/*
struct Test
{};

int main()
{
	int a = 10;
	double b = 12.34;
	int ar[] = {1,2,3,4,5};
	Test t;
	auto x = t;
	cout<<typeid(a).name()<<endl; //string
	cout<<typeid(b).name()<<endl;
	cout<<typeid(ar).name()<<endl;
	cout<<typeid(t).name()<<endl;

	cout<<typeid(x).name()<<endl;

	//typeid(a).name() y;
	decltype(t) y;
	cout<<typeid(y).name()<<endl;

	auto c = y;;

	return 0;
}

/*
int main()
{
	int a = 10;
	int b = 20;
	int &r = a;

	r++;

	int *p = &a;
	p++;

	return 0;
}

/*
struct Test
{
	char a;    //1 + 7
	double b;  //8
	int c;     //4 + 4
};

Test& fun(Test &tmp)
{
	cout<<"This is fun()"<<endl;
	tmp.a = 'X';
	tmp.b = 23.45;
	tmp.c = 200;
	return tmp;
}

int main()
{
	int a = 10;
	int &b = a;

	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int (&br)[10] = ar;

	int *p = &a;
	int* &q = p;

	Test t={'A', 12.34, 100};
	Test b = fun(t);

	return 0;
}

/*
int value;
int& fun(int a, int b)
{
	value = a + b;
	return value;
}
int main()
{
	int &val = fun(1,2);
	fun(10,20);
	cout<<"val = "<<val<<endl; //????
	return 0;
}

/*
struct Test
{
	char a;    //1 + 7
	double b;  //8
	int c;     //4 + 4
};

Test& fun(Test &tmp)
{
	cout<<"This is fun()"<<endl;
	tmp.a = 'X';
	tmp.b = 23.45;
	tmp.c = 200;
}

int main()
{
	int a = 10;
	int &b = a;

	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int (&br)[10] = ar;

	int *p = &a;
	int* &q = p;

	Test t={'A', 12.34, 100};
	fun(t);

	return 0;
}
*/