#include<iostream>
#include<assert.h>
#include<time.h>
using namespace std;

int main()
{
	time_t te;
	time(&te);
	//printf("%s\n", ctime(&te));

	struct tm *ptm = localtime(&te);
	return 0;
}

/*
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
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
public:
	int length()const
	{
		return strlen(m_data);
	}
public:
	char operator[](int i)
	{
		assert(i>=0 && i<length());
		return m_data[i];
	}
	String operator+(const String &s)
	{
		int total_size = length() + s.length() + 1;
		char *tmp = new char[total_size];
		strcpy(tmp, m_data);
		strcat(tmp, s.m_data);

		String tmps(tmp);
		delete []tmp;
		return tmps;		
	}
	String& operator+=(const String &s)
	{
		int new_size = length() + s.length()+1;
		char *tmp = new char[new_size];
		strcpy(tmp, m_data);
		strcat(tmp, s.m_data);

		delete []m_data;
		m_data = tmp;
		return *this;
	}
public:
	bool operator==(const String &s)
	{
		if(strcmp(m_data, s.m_data) == 0)
			return true;
		return false;
	}
	bool operator!=(const String &s)
	{
		return !(*this==s);
	}
	bool operator>(const String &s)
	{
		if(strcmp(m_data, s.m_data) == 1)
			return true;
		return false;
	}
	bool operator<(const String &s)
	{
		if(strcmp(m_data, s.m_data) == -1)
			return true;
		return false;
	}
	bool operator>=(const String &s)
	{
		return !(*this < s);
	}
	bool operator<=(const String &s)
	{
		return !(*this > s);
	}
private:
	char *m_data;
};

ostream& operator<<(ostream &out, const String &s)
{
	out<<s.m_data;
	return out;
}


int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");

	for(int i=0; i<s1.length(); ++i)
		cout<<s1[i];
	cout<<endl;

	String s = s1 + s2; //s = HelloBit
	cout<<s1<<endl;
	//s1 += s2;  
	//cout<<s1<<endl;//
	/*if(s1 == s2)
		cout<<"s1 == s2"<<endl;
	if(s1 != s2)
		cout<<"s1 != s2"<<endl;
	if(s1 > s2)
		cout<<"s1 > s2"<<endl;
	if(s1 < s2)
		cout<<"s1 < s2"<<endl;
	if(s1 >= s2)
		cout<<"s1 >= s2"<<endl;
	if(s1 <= s2)
		cout<<"s1 <= s2"<<endl;
		

	return 0;
}


/*
class Test
{
public:
	Test(int d = 0) :m_data(d)
	{}
public:
	class Tmp //�ڲ���
	{
	public:
		Tmp(int a , int b) : x(a), y(b)
		{}
	public:
		int GetX()
		{return x;}
	public:
		int x;  //
		int y;  //�Ƴ�Ա
	};
public:
	int m_data;
};
void main()
{
	Test::Tmp tp(1,2);

}

/*
class List;

class ListNode
{
	friend class List;
public:
	ListNode(int data=0) : m_data(data), next(nullptr)
	{}
	ListNode(int data, ListNode *n)
		: m_data(data), next(n)
	{}
	~ListNode()
	{}
public:
	ListNode*& GetNext()
	{
		return next;
	}
private:
	int m_data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		first = last = new ListNode;
		size = 0;
	}
	~List()
	{}
public:
	void push_back(int x)
	{
		ListNode *s = new ListNode(x);
		last->next = s;
		last = s;
		size++;
	}
	void push_front(int x)
	{
		ListNode *s = new ListNode(x);
		s->next = first->next;
		first->next = s;
		size++;
	}
private:
	ListNode *first;
	ListNode *last;
	size_t    size;
};

void main()
{
	List mylist;
	mylist.push_back(1);
}

/*
///class SmallInt;
//ostream &operator<<(ostream&os, const SmallInt &si);
//istream &operator>>(istream &is, SmallInt &si);

//SmallInt si(1000);

class SmallInt
{
public:
	SmallInt(int i = 0);
	//���ز���ͳ�ȡ�����
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);

	//�������������
	SmallInt operator+(const SmallInt &si)
	{ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si)
	{ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si)
	{ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si)
	{ return SmallInt(val / si.val); }
	//���رȽ������
	bool operator==(const SmallInt &si)
	{ return (val == si.val); }

public:
	//s1 += s2
	SmallInt& operator+=(const SmallInt &si)
	{                //200
		SmallInt tmp(val + si.val);
		*this = tmp;
		return *this;
	}
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}
 
ostream &operator<<(ostream &os,const SmallInt &si)
{
	os << (int)si.val;
	return os;
}
 
istream &operator>>(istream &is,SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}

void main()
{
	SmallInt si;
	cout<<si<<endl;
}

/*
class SmallInt
{
public:
	SmallInt(int i = 0);
	//���ز���ͳ�ȡ�����
public:
	ostream& operator<<(ostream &out);
public:
	//�������������
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//���رȽ������
	bool operator==(const SmallInt &si){ return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}

ostream& SmallInt::operator<<(ostream &out)
{
	out<<(int)val;
	return out;
}
void main()
{
	SmallInt s1(1000);
	//cout<<s1;
	s1<<cout<<endl;
	//s1.operator<<(cout)
}

/*
//����ĳ�������һ���򵥵�SmallInt�࣬
//������ʾ��-128��127֮���������
//���Ψһ�����ݳ�Աval���һ��-128��127
//������-128��127����������֮���������Ϊ�˷��㣬
//��SmallInt��������һЩ�������
//�Ķ�SmallInt�Ķ��壬�ش���Ŀ��������⡣

class SmallInt;
ostream &operator<<(ostream&os, const SmallInt &si);
istream &operator>>(istream &is, SmallInt &si);

//SmallInt si(1000);

class SmallInt
{
public:
	SmallInt(int i = 0);
	//���ز���ͳ�ȡ�����
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);

	//�������������
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//���رȽ������
	bool operator==(const SmallInt &si){ return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}
 
ostream &operator<<(ostream &os,const SmallInt &si)
{
	os << (int)si.val;
	return os;
}
 
istream &operator>>(istream &is,SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}
//����1������С��4�֣�������ඨ���У�
//���صĲ���������ͳ�ȡ�����������Ϊ�����Ԫ������
//�ܲ��ܽ����������������Ϊ��ĳ�Ա������//����
//����ܣ�д������ԭ�ͣ�������ܣ�˵�����ɡ�

void main()
{
	SmallInt si(1000);
	cout<<si<<endl;
	SmallInt si1;
	cin>>si1;
	cout<<si1<<endl;
}



/*
class Test;
void fun(const Test &t);

class Test
{
	friend void fun(const Test &t);
public:
	Test() : m_data(10)
	{}
public:
	int GetData()const
	{
		return m_data;
	}
	int GetData(const Test &t)const
	{
		return t.m_data;
	}
private:
	int m_data = 1;
};

//int GetData(const Test &t)const
void fun(const Test &t)
{
	cout<<t.m_data<<endl;
}

void print(const Test &t)
{
	//cout<<t.m_data<<endl;
}

int main()
{
	Test t, t1;
	fun(t);

	int value = t.GetData(t1);
	return 0;
}

/*
class Test
{
public:
	//���� ��ʾ
	explicit Test(int d = 0) : m_data(d)
	{
		m_count++;
	}
	~Test()
	{
		m_count--;
	}
public:
	int GetData()const
	{return this->m_data;}
public:
	operator int() //ǿ��ת��
	{
		return this->m_data;
	}
public:
	void list()
	{
		fun();
	}
	static void fun()
	{
		m_count = 10;
		cout<<"Test::fun() static"<<endl;
	}

public:
	
private:
	int m_data;
	static int m_count;
};

int Test::m_count = 0; //

int main()
{
	Test t1;
	t1.m_count;
	cout<<"m_count = "<<Test::m_count<<endl;
	{
		Test t2;
		cout<<"m_count = "<<Test::m_count<<endl;
	}
	cout<<"m_count = "<<Test::m_count<<endl;
}


/*
class Test;
ostream& operator<<(ostream &out, const Test &t);
istream& operator>>(istream &in,  Test &t);

class A
{
public:
	A(int a, int b, int c)
	{
		cout<<"A::A()"<<endl;
		x = a;
		y = b;
		z = c;
	}
private:
	int x;
	int y;
	int z;
};

class B
{
public:
	B(int a, int b, int c)
	{
		cout<<"B::B()"<<endl;
		x = a;
		y = b;
		z = c;
	}
private:
	int x;
	int y;
	int z;
};

class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
	friend istream& operator>>(istream &in,  Test &t);
public:
	//1 ���ٿռ�
	//2 ��ʼ��
	//3 �������
	Test(int d, int ref):m_b(4,5,6),m_a(1,2,3) 
	{
		//
	}
	~Test()
	{}
public:
	//void fun(Test * const this)
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
		print();
	}
	//*this
	//void print(const Test * const this)
	void print()const
	{
		//fun();
		cout<<"This is Test::print()const"<<endl;
	}
private:
	int m_data;
	//int &m_ref;
	//const int m_const;
	B   m_b;
	A   m_a;
};

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}
istream& operator>>(istream &in,  Test &t)
{
	in>>t.m_data;
	return in;
}

int main()
{
	Test t(10,100);
	return 0;
}
*/