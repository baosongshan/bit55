#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Singleton
{
public:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;

Singleton::Singleton()
{
	cout << "Singleton...." << endl;
}
Singleton* Singleton::Instance()
{
	if (_instance == 0)
	{
		_instance = new Singleton();
	}
	return _instance;
}

int main(int argc, char* argv[])
{
	Singleton* sgn0 = Singleton::Instance();
	Singleton* sgn1 = Singleton::Instance();
	Singleton* sgn2 = Singleton::Instance();
	Singleton* sgn3 = Singleton::Instance();
	return 0;
}

/*
class Base
{
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual ~Base()
	{}
};

class D : public Base
{
public:
	void show()
	{
		cout<<"D::show()"<<endl;
		//m_a = 10;
	}
public:
	//int m_a;
};

void Active(Base *pa)
{
	pa->fun();

	//D *pd = (D*)pa;
	D *pd = dynamic_cast<D*>(pa);
	if(pd == nullptr)
	{
		cout<<"转换无效.不能操作子类对象....."<<endl;
	}
	else
		pd->show();
}

void main()
{
	Base b;
	//Base *pb = new D;
	Base *pb = &b;
	Active(pb);
}

/*
class Test
{
public:
	Test(int d = 0) :m_data(d)
	{}
	~Test()
	{}
private:
	int m_data;
};

void* operator new(size_t sz)
{
	void *ptr = malloc(sz);
	return ptr;
}

void* operator new[](size_t sz)
{
	void *ptr = malloc(sz);
	return ptr;
}

void main()
{
	//int *p = new int[10];
	Test *pt = new Test[10];  //new[]
	delete []pt;
}

/*
//#define PCHAR char*
typedef char* PCHAR;
void main()
{
	char ch = 'A';
	PCHAR pa, pb;  //char *pa, pb;

	pa = &ch;
	pb = &ch;
}

/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;        // 39  38
	printf("%x\n", a.k);  //39 38   38 39
}


/*
void main()
{
	vector<char> cv = {'b','a','c'};
	sort(cv.begin(), cv.end());

	do
	{
		cout<<cv[0]<<" "<<cv[1]<<" "<<cv[2]<<endl;
	}while(next_permutation(cv.begin(), cv.end()));

	cout<<"============================="<<endl;

	sort(cv.begin(), cv.end(), greater<char>());
	do
	{
		cout<<cv[0]<<" "<<cv[1]<<" "<<cv[2]<<endl;
	}while(prev_permutation(cv.begin(), cv.end()));
}
*/