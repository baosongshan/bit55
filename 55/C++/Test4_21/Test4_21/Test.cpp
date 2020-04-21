#include<iostream>
#include<memory>
#include<vld.h>
#include<string>
#include<thread>
#include<mutex>
#include<assert.h>
using namespace std;


class Test
{
public:
	static Test* CreateInstance()
	{
		if(instance == nullptr)
		{
			instance = new Test;
		}
		return instance;
	}
private:
	Test()
	{}
private:
	static Test *instance;
};

Test* Test::instance = nullptr;

void main()
{

	Test *pt1 = Test::CreateInstance();
	Test *pt2 = Test::CreateInstance();
	Test *pt3 = Test::CreateInstance();
	Test *pt4 = Test::CreateInstance();
	Test *pt5 = Test::CreateInstance();
	Test *pt6 = Test::CreateInstance();
	Test *pt7 = Test::CreateInstance();
}
/*
class mynoncopyable
{
protected:
	mynoncopyable() {}
	~mynoncopyable() {}
private: 
	mynoncopyable(const mynoncopyable&);
	const mynoncopyable& operator=(const mynoncopyable&);
};

class Test : public mynoncopyable
{

};
void main()
{
	Test t;
	Test t1 = t;
}

/*
class Test
{
public:
	static Test CreateInstance()
	{
		return Test();
	}
	//Test(const Test &) = delete;
private:
	Test()
	{
		//
	}
	Test(const Test &);
private:
	int a = 0;
	int b = 0;
};

void main()
{
	Test t = Test::CreateInstance();
	Test *pt = new Test;  //Heap
}


/*
class Test
{
public:
	Test()
	{
		//
	}
private:
	void* operator new(size_t sz);
private:
	int a = 0;
	int b = 0;
};

void main()
{
	Test t;
	//Test *pt = new Test;  //Heap
}

/*
class Test
{
public:
	static Test* CreateObject()
	{
		return new Test;
	}
private:
	Test()
	{
		//
	}
	int a = 0;
	int b = 0;
};

void main()
{
	Test *pt = Test::CreateObject(); //
	Test *pt1 = Test::CreateObject(); //

	new Test;
}

/*
template<class T>
struct FreeFun
{
	void operator()(T *ptr)
	{
		cout<<"free ptr : "<<ptr<<endl;
		//free(ptr);
		fclose(ptr);  //close(socket);
	}
};

void main()
{
	FILE *fp = fopen("Test.txt", "w");
	assert(fp != NULL);

	//shared_ptr<int> sp1(p, FreeFun<int>());                //delete  仿函数
	shared_ptr<FILE> sp(fp, FreeFun<FILE>());


	//fclose(fp);
}

/*
void main()
{
	int *p = (int *)malloc(sizeof(int));   //malloc  free
	cout<<"p = "<<p<<endl;

	shared_ptr<int> sp1(p, FreeFun<int>());                //delete  仿函数
}

/*
void main()
{
	int *p = new int(1);
	shared_ptr<int> sp1(p);
	shared_ptr<int> sp2 = sp1;
	shared_ptr<int> sp3;
	sp3 = sp1;

	cout<<sp1.use_count()<<endl;

	weak_ptr<int> wp1 = sp3;
	cout<<"wp1 use_count = "<<wp1.use_count()<<endl;
	
	//cout<<sp1.use_count()<<endl;

	shared_ptr<int> sp4 = sp1;
	cout<<"wp1 use_count = "<<wp1.use_count()<<endl;

}

/*
template<class T>
struct ListNode
{
public:
	~ListNode()
	{
		cout<<"~ListNode()"<<endl;
	}
	T data;
	//shared_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;
	//shared_ptr<ListNode<T>> m_next;   //ListNode *m_next;
	weak_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;  //弱指针 * ->
	weak_ptr<ListNode<T>> m_next;   //ListNode *m_next;
};

void main()
{
	shared_ptr<ListNode<int>> node1(new ListNode<int>);
	shared_ptr<ListNode<int>> node2(new ListNode<int>);
	cout<<"use_count 1 = "<<node1.use_count()<<endl;
	cout<<"use_count 2 = "<<node2.use_count()<<endl;

	node1->m_next = node2;
	node2->m_prev = node1;

	cout<<"use_count 1 = "<<node1.use_count()<<endl;  //2
	cout<<"use_count 2 = "<<node2.use_count()<<endl;  //2

}

/*
class Test
{
public:
	int count = 0;
};

void thread_fun(shared_ptr<Test> &sp, int n)
{
	
	for(int i=0; i<n; ++i)
	{
		shared_ptr<Test> sp1 = sp;
		sp1->count++; //2n
	}
}

void main()
{
	shared_ptr<Test> sp(new Test);

	const int n = 10;
	thread th1(thread_fun, sp, n);
	thread th2(thread_fun, sp, n);

	th1.join();
	th2.join();

	cout<<"Test::count = "<<sp->count<<endl;
}


/*
template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~SharedPtr() { Release(); }
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	// sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }
	void AddRefCount()
	{
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		// 引用计数减1，如果减到0，则释放资源
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针
	mutex* _pMutex; // 互斥锁
};

class Test
{
public:
	int count = 0;
};

mutex mt;

void thread_fun(SharedPtr<Test> &sp, int n)
{
	
	for(int i=0; i<n; ++i)
	{
		SharedPtr<Test> sp1(sp);
		mt.lock();
		sp1->count++; //2n
		mt.unlock();
	}
}

void main()
{
	SharedPtr<Test> sp(new Test);

	const int n = 100000;
	thread th1(thread_fun, sp, n);
	thread th2(thread_fun, sp, n);

	th1.join();
	th2.join();

	cout<<"Test::count = "<<sp->count<<endl;
}

/*
template<class T>
class Shared_Ptr
{
	typedef Shared_Ptr<T> _Myt;
public:
	Shared_Ptr(T *ptr = nullptr) : m_Ptr(ptr), m_pMutex(new mutex)
	{
		if(m_Ptr)
			m_pRefCount = new int(1);
		else
			m_pRefCount = new int(0);
	}
	Shared_Ptr(const _Myt &sp):m_Ptr(sp.m_Ptr),m_pRefCount(sp.m_pRefCount),m_pMutex(sp.m_pMutex)
	{
		Increment();
	}
	_Myt& operator=(const _Myt &sp)
	{
		if(this != &sp)
		{
			Release();
			m_Ptr = sp.m_Ptr;
			m_pRefCount = sp.m_pRefCount;
			Increment();
		}
		return *this;
	}
	~Shared_Ptr()
	{
		Release(); //释放拥有权
	}
public:
	int use_count()const
	{
		return *m_pRefCount;
	}

public:
	T& operator*()const
	{
		return *m_Ptr;
	}
	T* operator->()const
	{
		return m_Ptr;
	}
	T* get()const
	{
		return m_Ptr;
	}
protected:
	void Increment()
	{
		m_pMutex->lock();
		++(*m_pRefCount);
		m_pMutex->unlock();
	}
	void Release()
	{
		bool mutex_delete_flag = false;

		m_pMutex->lock();
		if(--(*m_pRefCount) == 0)
		{
			delete m_Ptr;
			delete m_pRefCount;
			mutex_delete_flag = true;
		}
		m_pMutex->unlock();

		if(mutex_delete_flag)
			delete m_pMutex;
	}
private:
	T   *m_Ptr;
	int *m_pRefCount;
	mutex *m_pMutex;
};

class Test
{
public:
	int count = 0;
};

void thread_fun(Shared_Ptr<Test> &sp, int n)
{
	Shared_Ptr<Test> sp1 = sp;
	for(int i=0; i<n; ++i)
	{
		sp1->count++; //2n
	}
}

void main()
{
	Shared_Ptr<Test> sp(new Test);

	const int n = 100000;
	thread th1(thread_fun, sp, n);
	thread th2(thread_fun, sp, n);

	th1.join();
	th2.join();

	cout<<"Test::count = "<<sp->count<<endl;
}

/*
void main()
{
	int *p = new int(10);
	//int *p = (int *)malloc(sizeof(int));//删除器

	Shared_Ptr<int> sp(p);  
	cout<<*sp<<endl;
	cout<<"use_count = "<<sp.use_count()<<endl;

	Shared_Ptr<int> sp1 = sp;
	cout<<"use_count = "<<sp.use_count()<<endl;

	Shared_Ptr<int> sp2;
	sp2 = sp1;
	cout<<"use_count = "<<sp.use_count()<<endl;

}


/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	shared_ptr<int> sp1(p);
	cout<<*sp1<<endl;
	cout<<"use_count = "<<sp1.use_count()<<endl;

	{
		shared_ptr<int> sp2 = sp1;
		cout<<"use_count = "<<sp1.use_count()<<endl;
	}
	cout<<"use_count = "<<sp1.use_count()<<endl;

	sp1.reset(q);
	cout<<*sp1<<endl;

}

/*
void main()
{
	int *p = new int(10);
	unique_ptr<int> uptr(p);

	cout<<*uptr<<endl;

	unique_ptr<string> usptr(new string("abc"));
	cout<<usptr->size()<<endl;

	//unique_ptr<int> uptr1(uptr);  //拥有权不能转义  scoped_ptr

}
*/