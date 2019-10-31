#include<iostream>
#include<vld.h>
using namespace std;

//new
void* operator new(size_t sz, int *ptr, int pos)
{
	return (ptr+pos);
}
void main()
{
	int ar[10];
	new(ar,0) int(1); //定位new
	new(ar,3) int(100);
	new(ar,5) int(200);

	int *p = new int;
}


/*
class Test
{
public:
	Test(int d=0) : m_data(d)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		m_data = t.m_data;
	}
	Test& operator=(const Test &t)
	{
		cout<<"Assign:"<<this<<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object : "<<this<<endl;
	}
public:
	void TestInit(int d = 0)
	{
		m_data = d;
	}
	void TestDestroy()
	{
		m_data = 0;
	}
public:
	int GetData()const
	{return m_data;}
public:
	void* operator new(size_t sz) //1
	{
		void *ptr = malloc(sz);
		return ptr;
	}
	void operator delete(void *ptr)
	{
		free(ptr);
	}
private:
	int m_data;
};

void* operator new(size_t sz) //1
{
	void *ptr = malloc(sz);
	return ptr;
}
void operator delete(void *ptr)
{
	free(ptr);
}

void* operator new[](size_t sz) //1
{
	void *ptr = malloc(sz);
	return ptr;
}
void operator delete[](void *ptr)
{
	free(ptr);
}

void main()
{
	//operator new 
	Test *pt = new Test(10);//1 2
	delete pt;              //1 2
	//Test *pt = (Test*)operator new(sizeof(Test)); //申请空间malloc

	Test *pt1 = new Test[10];//40
}

/*
void UseMallocFree()
{
	Test *pt = (Test*)malloc(sizeof(Test)); //1
	pt->TestInit(10);  //2

	pt->TestDestroy();
	free(pt);
}

void UseNewDelete()
{
	Test *pt = new Test;
	delete pt;
}

void main()
{
	//UseMallocFree();
	UseNewDelete();
}



/*
void main()
{
	//malloc calloc
	int *p = (int *)malloc(sizeof(int) * 10);
	int *p1 = (int *)calloc(10, sizeof(int));
	int *p2 = (int*)realloc(p1, sizeof(int)*100);

	free(p);
	//free(p1);
	free(p2);

	int *p3 = (int*)_alloca(sizeof(int)*10);
	free(p3);
}

/*
int main()
{
	int a = 10;
	int b = 20;

	int *p1 = (int*)malloc(sizeof(int));
	int *p2 = (int*)malloc(sizeof(int));
	return 0;
}

/*
class Complex
{
	friend ostream& operator<<(ostream &out, const Complex &c);
public:
	Complex(int real, int imag) : m_real(real), m_imag(imag)
	{}
	~Complex()
	{}
public:
	Complex operator+(const Complex &c);
private:
	int m_real;
	int m_imag;
};

ostream& operator<<(ostream &out, const Complex &c)
{
	out<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}
Complex Complex::operator+(const Complex &c)
{
	return Complex(m_real+c.m_real, m_imag+c.m_imag);
}

int main()
{
	Complex c1(1,2), c2(2,3);
	Complex c = c1 + c2;
	cout<<"c = "<<c<<endl;
	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		m_data = t.m_data;
	}
	Test& operator=(const Test &t)
	{
		cout<<"Assign:"<<this<<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object : "<<this<<endl;
	}
public:
	int GetData()const
	{return m_data;}
private:
	int m_data;
};

Test fun(Test &x)
{
	int value = x.GetData();
	return Test(value);
}
int main()
{
	Test t(10);
	Test t1 = fun(t); //创建t1对象
	return 0;
}


Test fun(Test x)
{
	int value = x.GetData();
	return Test(value);
}
int main()
{
	Test t(10);
	Test t1 = fun(t); //创建t1对象
	return 0;
}

/*
Test fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}
int main()
{
	Test t(10);
	Test t1 = fun(t);
	return 0;
}

/*
Test& fun(Test &x)
{
	return x;
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	cout<<t1.GetData()<<endl;
	return 0;
}


Test& fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	cout<<t1.GetData()<<endl;
	return 0;
}

/*
Test fun(Test &x)
{
	int value = x.GetData();
	return Test(value); //临时对象的语法
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	return 0;
}

/*
Test fun(Test x)
{
	int value = x.GetData();
	return Test(value); //临时对象的语法
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	return 0;
}

/*
Test fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	return 0;
}


void fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
}

int main()
{
	Test t(10);
	fun(t);
	return 0;
}

/*
void fun(Test x)
{
	int value = x.GetData();
}

int main()
{
	Test t(10);
	fun(t);
	return 0;
}
*/