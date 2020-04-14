#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<string>
using namespace std;

//异常类

//栈满异常声明
template<typename T>
class pushOnFull
{ 
private:
	T _value;
public:
	pushOnFull(T i)
	{
		_value=i;
	}
	T value()const
	{
		return _value;
	}
	void print()
	{
		cerr<<"栈满，"<<value()<<"未压入栈"<<endl;
	}
};

//栈空异常声明
template<typename T>
class popOnEmpty
{
public:
	void print()
	{
		cerr<<"栈已空，无法出栈"<<endl;
	}
};

template<typename T>
class Stack
{
private:
	int top;                                    //栈顶指针（下标）
	T *elements;                               //动态建立的数值
	int maxSize;                               //栈最大允纳的元素个数
public:
	Stack(int default_size=20)
	{
		maxSize = default_size;
		elements = new T[maxSize];
		top = -1;
	}
	~Stack()
	{
		delete[] elements;
	}
	////////////////////////////////////////////////////////////////
	void Push(const T &data) throw(pushOnFull<T>)
	{
		if(IsFull())
			throw pushOnFull<T>(data);
		elements[++top] = data;
	}
	T Pop() throw(popOnEmpty<T>)
	{
		if(IsEmpty())
			throw popOnEmpty<T>();

		T data = elements[top];
		top--;
		return data;
	}
	/////////////////////////////////////////////////////////////////
	bool IsEmpty() const
	{
		return top== -1;
	}
	bool IsFull() const
	{
		return top==maxSize-1;
	}  
	void PrintStack()
	{
		for(int i=top; i>=0; --i)
			cout<<elements[i]<<" ";
		cout<<endl;
	}
};


void main()
{
	Stack<int> st(10);

	try
	{
		for(int i=1; i<=10; ++i)
		{
			st.Push(i);
		}
	}
	catch(pushOnFull<int> &e)
	{
		e.print();
		return;
	}
	st.PrintStack();

	try
	{
		for(int i=0; i<=10; ++i)
			st.Pop();
	}
	catch(popOnEmpty<int> &e)
	{
		e.print();
		return;
	}

	cout<<"Main End."<<endl;
}


/*
class Exception
{
public:
	Exception(const char *str = "") : _errmsg(str)
	{}
public:
	void what()const
	{
		cout<<_errmsg<<endl;
	}
protected:
	string _errmsg;
};
class SqlException : public Exception
{
public:
	SqlException(const char *str) : Exception(str)
	{}
};
class CacheException : public Exception
{
public:
	CacheException(const char *str) : Exception(str)
	{}
};

void Start()
{
	//.......
	//某个条件不满足时抛出异常
	throw SqlException("sql error....");
	//......
}

int main()
{
	try
	{
		Start();
	}
	catch (const Exception& e) // 这里捕获父类对象就可以
	{
		e.what();
		return -1;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}

/*
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;  //重新抛出
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}

/*
//到底发生了什么，哪怕是发生错误

struct Test
{};

//try throw catch  异常规范
//左边返回值         右边也有返回值 异常     
int Div(int a, int b)  //代表可以抛出一切异常
//int Div(int a, int b)throw()  //代表可以不可以抛出异常
//int Div(int a, int b)throw(int,char,double, Test)  //代表可以不可以抛出异常
{
	float d = 0.0;
	if(b == 0)
		throw d;    //抛出的是类型，不是值

	cout<<"aaaaaaaaaaaaaaaaaaa"<<endl;
	return a / b;
}

void main()
{
	int result = 0;
	try  //测试块
	{
		result = Div(10,0);
		cout<<"bbbbbbbbbbbbbbbb"<<endl;
	}
	
	catch(int)  //按照类型来捕获
	{
		cout<<"Div Error 1: b == 0."<<endl;
		return;
	}
	catch(double)
	{
		cout<<"Div Error 2: b == 0."<<endl;
		return;
	}

	printf("result = %d\n", result);
}

/*
int Div(int a, int b)
{
	//assert(b != 0);
	if(b == 0)
		exit(1); // 异常结束
	int result = a / b;
	printf("aaaaaaaaaaaaaaaa\n");
	return result;
}

void main()
{
	cout<<Div(10,2)<<endl;
}

/*
int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		//lock_guard<mutex> lck(g_lock);
		unique_lock<mutex> lck(g_lock);
		++number;
		cout << "thread 1 :" << number << endl;
		//g_lock.unlock();
	}
	return 0;
}

int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		//lock_guard<mutex> lck(g_lock);
		unique_lock<mutex> lck(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
		//g_lock.unlock();
	}
	return 0;
}


int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);

	t1.join();
	t2.join();

	cout << "number:" << number << endl;   // 0 -1 -2 1 2
	system("pause");
	return 0;
}

/*
mutex mt;
unsigned long sum = 0L;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		mt.lock();
		sum++;       //原子操作
		//return
		//throw
		mt.unlock();
	}
}

int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);   //1000 0000
	thread t2(fun, 10000000);   //2000 0000

	t1.join();
	t2.join();

	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
void main()
{
	atomic<int> atm(0);

	atomic<int> atm1 = atm;

}

/*
atomic_long sum = {0};

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++;
}

int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);   //1000 0000
	thread t2(fun, 10000000);   //2000 0000

	t1.join();
	t2.join();

	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
mutex mt;

unsigned long sum = 0L;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		mt.lock();
		sum++;       //原子操作
		mt.unlock();
	}
}

int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);   //1000 0000
	thread t2(fun, 10000000);   //2000 0000

	t1.join();
	t2.join();

	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
class mythread
{
public:
	mythread(thread &th) : m_th(th)
	{}
	~mythread()
	{
		if(m_th.joinable())
			m_th.join();
	}
private:
	thread &m_th;
};

void ThreadFunc()
{
	for(;;)
		cout << "ThreadFunc()" << endl;
}
bool DoSomething()
{
	return false;
}
int main()
{
	std::thread t(ThreadFunc);
	t.detach();
	
	//mythread myth(t);  //代理思想
	//this->join()

	if (!DoSomething())
		return -1;

	return 0;
}

/*
class Test
{
public:
	void fun()
	{
		for(int i=0; i<100000; ++i)
		{}
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	Test t;
	thread th(&Test::fun, &t);
	th.join();  //回收资源
	//th.join();
}

/*
void thread_fun1(int &a)
{
	a = 100;
	printf("thread fun1 a = %d\n", a);
}

void thread_fun2(int *a)
{
	*a = 100;
	printf("thread fun1 a = %d\n", *a);
}

void main()
{
	int a = 10;
	thread th(thread_fun1, ref(a));  //多线程
	//thread th(thread_fun2, &a);
	th.join();  //主线程阻塞等待
	printf("a = %d\n", a);
	
	
}

/*
void func(int &a)
{}

void main()
{
	int a = 10;
	int b = 20;
	auto fun = [&a]()->void
	{
		a = 100;
		//b = 200;
		printf("lambda a = %d\n", a);
	};

	fun();

	printf("a = %d\n", a);
}
*/