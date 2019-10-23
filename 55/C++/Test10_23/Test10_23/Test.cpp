#include<iostream>
#include<vld.h>
using namespace std;

class Int
{
public:
	Int(long i = 0) : m_i(i)
	{}
public:
	Int operator+(const Int &x)
	{
		//Int tmp(m_i+x.m_i);
		//return tmp;
		return Int(m_i+x.m_i);
	}
	Int operator-(const Int &x);
	Int operator*(const Int &x);
	Int operator/(const Int &x);
	Int operator%(const Int &x);
public:
	Int& operator+=(const Int &x); // a += b;
	Int& operator-=(const Int &x);
	Int& operator*=(const Int &x);
	Int& operator/=(const Int &x);
	Int& operator%=(const Int &x);
public:
	Int operator>>(const Int &x); //a >> b
	Int operator<<(const Int &x);
	Int operator>>=(const Int &x);
	Int operator<<=(const Int &x);
public:
	bool operator==(const Int &x);
	bool operator!=(const Int &x);
public:
	Int operator++(); //
	Int operator++();
	Int operator--(); //
	Int operator--();
public:
	int GetData()const
	{return m_i;}
private:
	long m_i;
};

int main()
{
	Int a(1);  //int a = 1;  a++  ++a  a-- --a
	Int b(2);

	cout<<"a = "<<a.GetData()<<endl;
	cout<<"b = "<<b.GetData()<<endl;

	Int result;
	result = a + b; //result = 1 + 2;
	cout<<"result = "<<result.GetData()<<endl;

	result = ++a;

	return 0;
}


/*
class String
{
public:
	String(char *str = "")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data)+1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}

/*
class Test
{
public:
	Test(int d = 0):m_data(d)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
public:
	void SetData(int data)
	{m_data = data;}
	int GetData()const
	{return m_data;}
private:
	int m_data;
};

void TestMallocFree()
{
	Test *pt = (Test *)malloc(sizeof(Test));
	//pt->SetData(10);
	//cout<<pt->GetData()<<endl;
	free(pt);
}
void TestNewDelete()
{
	Test *pt = new Test; //1 开辟空间 2 调动构造函数
	delete pt;           //1 调动析构函数 2 释放空间
}

void TestMallocFreeArray()
{
	Test *pt = (Test *)malloc(sizeof(Test) * 10);
	free(pt);
}

void TestNewDeleteArray()
{
	Test *pt = new Test[10];
	delete []pt;
}

int main()
{
	TestNewDeleteArray();
	return 0;
}

/*
//malloc calloc realloc free
int main()
{
	int *pi = (int *)malloc(sizeof(int));
	free(pi);
	int *pa = (int *)malloc(sizeof(int) * 10);
	free(pa);

	int *pi1 = new int;
	*pi1 = 1;
	delete pi1;

	int *pa1 = new int[10]; //数组
	for(int i=0; i<10; ++i)
	{
		pa1[i] = i+1;
	}
	for(int i=0; i<10; ++i)
	{
		cout<<pa1[i]<<" ";
	}
	cout<<endl;
	delete []pa1;

	int *pa2 = new int(10); //初始化
	delete pa2;
	return 0;
}

/*
class String
{
public:
	String(char *str = "")
	{
		m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data)+1));
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			free(m_data);
			m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data) + 1));
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}


/*
String(char *str = nullptr)
	{
		if(str == nullptr)
		{
			m_data = (char*)malloc(sizeof(char));
			m_data[0] = '\0';
		}
		else
		{
			m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(m_data, str);
		}
	}

String& operator=(const String &s)
	{
		if(this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data)+1));
		strcpy(m_data, s.m_data);

		return *this;
	}

class Test
{
public:
	Test(int d = 0):m_data(d)
	{}
public:
	int GetData()const
	{return m_data;}
private:
	int m_data;
};

void main()
{
	Test t1(10);
	//cout<<"t1 = "<<t1<<endl;
	cout<<"t1 = "<<t1.GetData()<<endl;
	Test t2 = t1;
	cout<<"t2 = "<<t2.GetData()<<endl;
	Test t3;
	t3 = t2;
	cout<<"t3 = "<<t3.GetData()<<endl;

}


/*
class Test;
ostream& operator<<(ostream &out, const Test &t);

class Test
{
	//友元
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int d = 0) : m_data(d)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	//Test t1 = t;
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test &t)
	{
		cout<<"Assign: "<<this<<" = "<<&t<<endl;
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
	int SetData(int data)
	{m_data = data;}
private:
	int m_data;
};

Test fun(Test t)
{
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
	         //t2.operator=(t1); //

	cout<<"t1 = "<<t1<<endl;

	return 0;
}

/*
class Student
{
public:
	Student(char *name, int age, int height)
		: m_age(age), m_height(height)
	{
		strcpy(m_name, name);
	}
	~Student()
	{}
public:
	bool operator==(const Student &s)
	{
		return m_age == s.m_age;
	}
private:
	char m_name[10];
	int m_age;
	int m_height;
};

void main()
{
	Student s1("杨致远",21, 170);
	Student s2("王珂",21, 180);
	if(s1 == s2)
		cout<<"s1 == s2"<<endl;
}

/*
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{}
	~Test()
	{}
public:
	//运算符的重载 ==
	bool operator==(const Test &t)
	{
		return this->m_data != t.m_data;
	}
	bool operator!=(const Test &t)
	{
		//return m_data != t.m_data;
		return !(*this==t);
	}
private:
	int m_data;
};

void main()
{
	Test t1(10);
	Test t2(20);

	if(t1 == t2) //t1.operator==(t2);
		cout<<"t1 == t2"<<endl;
	if(t1 != t2)
		cout<<"t1 != t2"<<endl;
}

/*
int main()
{
	int a = 10;
	int b = 20;
	// > < == != >= <= 
	if(a > b)
	{}
	if(a == b)
	{}
	if(a != b)
	{}
	if(a < b)
	{}
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
	//Test t1 = t;
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test &t)
	{
		cout<<"Assign: "<<this<<" = "<<&t<<endl;
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
	int SetData(int data)
	{m_data = data;}
private:
	int m_data;
};

Test fun(Test t)
{
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

int main()
{
	Test t(100);
	Test t1 = t; //Test t1(t)
	//fun(t1);
	Test t2;
	t2 = t1;
	return 0;
}
*/