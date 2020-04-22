#include<iostream>
using namespace std;

//#define __THROW_BAD_ALLOC  cerr << "out of memory" << endl; exit(1)
#define __THROW_BAD_ALLOC throw bad_alloc

template <int inst>
class __malloc_alloc_template 
{
private:
	static void *oom_malloc(size_t);
	static void *oom_realloc(void *, size_t);
	static void (* __malloc_alloc_oom_handler)();

public:
	static void * allocate(size_t n)
	{
		void *result = malloc(n);
		if (0 == result) 
			result = oom_malloc(n);  //out of memory malloc
		return result;
	}
	static void deallocate(void *p, size_t /* n */)
	{
		free(p);
	}
	static void * reallocate(void *p, size_t /* old_sz */, size_t new_sz)
	{
		void * result = realloc(p, new_sz);
		if (0 == result) 
			result = oom_realloc(p, new_sz);
		return result;
	}
public:
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return(old);
	}
};

template<int inst>
void (* __malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void *__malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (* my_malloc_handler)();
    void *result;

    for (;;) 
	{
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == my_malloc_handler) 
		{
			__THROW_BAD_ALLOC(); //throw bad_alloc();
		}
        (*my_malloc_handler)();
        result = malloc(n);
        if (result) 
			return(result);
    }
}

template<int inst>
void *__malloc_alloc_template<inst>::oom_realloc(void *ptr, size_t)
{
	void (* my_malloc_handler)();
    void *result;

    for (;;) 
	{
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == my_malloc_handler) 
		{
			__THROW_BAD_ALLOC; 
		}
        (*my_malloc_handler)();
        result = realloc(p, n);
        if (result) 
			return(result);
    }
}
	
void Out_Of_Memory()
{
	cout<<"Out Of Memory."<<endl;
	//GC
	exit(1);
}
void main()
{
	//set_new_handler;
	__malloc_alloc_template<0>::set_malloc_handler(Out_Of_Memory);
	try
	{
		int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int)*536870911); //malloc(sizeof(int));
	}
	catch(const bad_alloc &e)
	{
		cout<<"bad_alloc catched"<<endl;
		return;
	}
	
	//int * p = (int *)malloc(sizeof(int) * );
}

/*
void main()
{
	int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int)); //malloc(sizeof(int));
	
	__malloc_alloc_template<0>::reallocate(p, sizeof(int), sizeof(int)*10);//realloc
	
	__malloc_alloc_template<0>::deallocate(p, sizeof(int)); //free(p)
}

/*
namespace bit
{
	template<class T>
	T* _allocate(size_t size, T *)
	{
		set_new_handler(0);
		T *tmp = (T*)(::operator new(size * sizeof(T)));
		if(tmp == 0)
		{
			cerr<<"Out Of Memory"<<endl;
			exit(1);
		}
		return tmp;
	}

	template<class T>
	void _deallocate(T *buffer)
	{
		::operator delete(buffer);
	}

	template<class T1, class T2>
	void _construct(T1 *p, const T2 &value)
	{
		new(p) T1(value);  //定位new
	}

	template<class T>
	void _destroy(T *ptr)
	{
		ptr->~T();
	}

	template<class T>
	class allocator
	{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef size_t size_type;
	public:
		pointer allocate(size_type n, const void *hint=0)
		{
			return _allocate(n, (pointer)0);
		}
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
		void construct(pointer p, const T &value)
		{
			_construct(p, value);
		}
		void destroy(pointer p)
		{
			_destroy(p);
		}
	};
};

void main()
{
	list<int, bit::allocator<int>> mylist; 
}

/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"This is Base::fun()"<<endl;
	}
};

class D : public Base
{
public:
	void show()
	{
		cout<<"This is D::show()"<<endl;
	}
};

void Fun(Base *pb)
{
	//pb->fun();
	//D *pd = (D *)pb;  //向下转换
	D *pd = dynamic_cast<D*>(pb);
	if(pd != nullptr)
		pd->show();       //Error
	else
		cout<<"转换错误."<<endl;
}
void main()
{
	D d;
	Base b;

	//Fun(&d);
	Fun(&b);
}

/*
void main()
{
	D d;
	Base b;
	b = d;           //向上转换
	Base *pb = &d;
	Base &prb = d;
}

/*
class A
{
private:
	int a = 0;
};
class B
{
private:
	int b = 0;
};

class C : public A, public B
{

};

void main()
{
	C c;
	printf("%p, %p, %p\n", &c, reinterpret_cast<B*>(&c), static_cast<B*>(&c));
}

/*
void main()
{
	int a = 0;
	char *str = "This is a string.";

	//a = static_cast<int>(str);
	a = reinterpret_cast<int>(str);  //不安全
}

/*
void main()
{
	const int a = 10;
	int *pa = const_cast<int*>(&a); //v
	volatile int b = 20;
	int *pb = const_cast<int*>(&b);
}

void main()
{
	double d = 12.34;
	//int a = d;   //可以发生隐示转换  C
	
	int a = static_cast<int>(d);

	int *pa = static_cast<int*>(&d);
}

/*
void main()
{
	double d = 12.34;
	int a = (int)d;   //隐示转换
	int *pa = (int*)&d;  //d  忽略类型
}


/*
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if(m_instance == nullptr)
		{
			mtx.lock();
			if(m_instance == nullptr)  //双检锁
			{
				m_instance = new Singleton;
			}
			mtx.unlock();
		}
		return m_instance;
	}
private:
	Singleton()
	{}
private:
	static Singleton *m_instance;
	static mutex     mtx;
};

Singleton * Singleton::m_instance = nullptr;
mutex     Singleton::mtx;

void thread_func(int n)
{
	for(int i=0; i<n; ++i)
		cout<< Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(thread_func, 10);
	thread t2(thread_func, 10);
	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}

/*
void main()
{
	Singleton *pst1 = Singleton::GetInstance();
	Singleton *pst2 = Singleton::GetInstance();
	Singleton *pst3 = Singleton::GetInstance();
}

/*
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton(){};

	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	// or
	// C++11
	//Singleton(Singleton const&) = delete;
	//Singleton& operator=(Singleton const&) = delete;

private:
	static Singleton m_instance;
};

Singleton Singleton::m_instance;

void main()
{
	Singleton *pst1 = Singleton::GetInstance();
	Singleton *pst2 = Singleton::GetInstance();
	Singleton *pst3 = Singleton::GetInstance();
	Singleton *pst4 = Singleton::GetInstance();

	//5000

	//
}
*/
