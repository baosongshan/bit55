#include<iostream>
#include<thread>
using namespace std;

//void thread_fun(int &x)
//void thread_fun(int *x)
void thread_fun(int x)
{
	x += 100;
	cout<<"This is thread fun."<<endl;
}

void main()
{
	int a = 10;
	cout<<"a = "<<a<<endl;
	thread th1(thread_fun, ref(a));
	th1.join();
	cout<<"a = "<<a<<endl;
}

/*
void thread_fun1()
{
	cout<<"This is thread fun1."<<endl;
}
void thread_fun2()
{
	cout<<"This is thread fun2."<<endl;
}

struct thread_fun_obj
{
	void operator()()
	{
		cout<<"This is thread fun4."<<endl;
	}
};

void main()
{
	thread th1(thread_fun1); 
	thread th2 = move(th1);
	//th1.join();
	th2.join();
}

/*
//fork(); //vfork()
void main()
{
	thread th1(thread_fun1);  //马仔
	thread th2(thread_fun2);

	cout<<"th1 id = "<<th1.get_id()<<endl;
	cout<<"th2 id = "<<th2.get_id()<<endl;
	th1.join();
	th2.join();

	thread th3([]{cout<<"This is thread fun3."<<endl;});
	th3.join();

	thread_fun_obj obj;
	thread th4(obj);
	th4.join();
}

/*
void thread_fun(int n, int m)
{
	for(int i=0; i<n; ++i)
		cout<<"This is Child Thread."<<endl;
}

void main()
{
	int n = 5;
	int m = 10;
	thread th(thread_fun, n, m);
	//th.detach();
	
	for(int i=0; i<10; ++i)
		cout<<"This is Main Thread."<<endl;

	th.join();  //阻塞等待
	cout<<"Main End."<<endl;

}

/*
void main()
{
	thread th;
	cout<<th.get_id()<<endl;
	cout<<th.joinable()<<endl;
}

/*
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}
void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}
void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}
void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}

template<typename T>
void PerfectForward(T &&t)
{
	Fun(std::forward<T>(t));   //
	//Fun(t);
}

int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref


	return 0;
}

/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)	: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	
	//右值引用
	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}
	
	//s3 = s2 = s1;  //s2.operator=(s1);
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	//String s = s1 + s2;
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	~String()
	{
		if (_str) 			
			delete[] _str;   //delete nullptr
	}
private:
	char* _str;
};

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	String _name;
	String _sex;
	int    _age;
};

Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}
int main()
{
	Person p(GetTempPerson());
	return 0;
}

/*
void main()
{
	String s1 = "Hello";
	//String s2 = s1;
	String s2 = move(s1);    //初始化
}


/*
void main()
{	String s1 = "Hello";
	String s2 = "Bit.";
	String str = s1 + s2;

}

/*
class String
{
public:
	String(const char *str = "");
	String(const String &s);
	String& operator=(const String &s);  //效率
	~String();
private:
	char *m_data;
};

void main()
{
	int a = 10;
	int &b = a;

	const int &c = 100;
	const int &d = c;
	//&   &&
}

/*
int Add(int a, int b)
{
	int val =  a + b;  //const
	return val;
}

void main()
{
	Add(10,20) = 100;
	int &&res = Add(10,20);
}

/*
void main()
{
	int a = 10;
	int *pa = &a;

	const int x = 1;
	//x = 100;
	const int *px = &x;

	int &b = a;
}


/*
void main()
{
	int a = 10;
	int &b = a;

	const int &c = 10;
	int &&d = 10;
}
/*
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};

void main()
{
	Rate rt(2.5);
	cout<<rt(1000,2)<<endl;  //rt(1000,2) ==> rt.operator()(1000, 2);

	double rate = 2.5;
	auto rt1 = [=](int money, int year)->double{return money*year*rate;};
	cout<<typeid(rt1).name()<<endl;
	cout<<rt1(1000,2)<<endl;
}

/*
void(*pfun)();

void main()
{
	auto f1 = []{cout<<"Hello C++."<<endl;};
	auto f2 = []{cout<<"Hello Linux."<<endl;};

	//f1 = f2;
	auto f3 = f1;   //拷贝构造
	f3();

	pfun = f1;
	pfun();
}

/*
int z = 0;

void main()
{
	int a = 10;
	cout<<"a = "<<a<<endl;

	//[]  [=]   [&]  [a]  [&a]  [a, &b]  [this]

	auto fun = [&a](int x)->int
	{
		a = 100;
		return x + a + z;
	};
	
	cout<<"a = "<<a<<endl;
	int res = fun(5);
	cout<<"res = "<<res<<endl;
}

/*
void main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	//auto fun = [=](int x)->int

	cout<<"a = "<<a<<endl;

	auto fun = [a](int x)mutable->int    //const
	{
		a = 100;
		return x + a;
	};
	
	cout<<"a = "<<a<<endl;
	int res = fun(5);
	cout<<"res = "<<res<<endl;
}


/*
//闭包
void main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	//auto fun = [=](int x)->int
	auto fun = [a](int x)->int
	{
		return x + a + b + c + d;
	};
	

	int res = fun(5);
	cout<<"res = "<<res<<endl;
}



/*
auto fun = []{cout<<"Hello Lambda."<<endl;};

void main()
{
	fun();  //函数
}

/*
class Test
{
public:
	Test(int a = 0) : m_a(a)
	{}
public:
	void fun(int a)const
	{
		m_a = a;
	}
private:
	mutable int m_a;
};

void main()
{
	Test t(100);
	t.fun(1);
}

/*
auto fun = []()mutable->void{cout<<"Hello Lambda."<<endl;};

void main()
{
	fun();
}
*/