#include<iostream>
#include<list>
using namespace std;

void main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> lt(array, array + sizeof(array) / sizeof(array[0]));
	
	//list<int>::iterator it; 
	for(auto e : lt)
		cout<<e<<" ";
	cout<<endl;
	auto it = lt.begin();
	while (it != lt.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，
		//因此it无效，在下一次使用it时，必须先给其赋值
		it = lt.erase(it);
		//++it;
	}
	for(auto e : lt)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	list<int> list1;
	for(int i=1; i<=5; ++i) //1 2 3 4 5
		list1.push_back(i);
	list<int> list2;
	for(int i=6; i<=10; ++i) //6 7 8 9 10
		list2.push_back(i);

	list1.swap(list2);

	for(auto e : list1)
		cout<<e<<" ";
	cout<<endl;

	for(auto e : list2)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	list<int> mylist(ar, ar+10);

	mylist.clear(); 

	cout<<mylist.empty()<<endl;
	cout<<mylist.size()<<endl;
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	list<int> mylist(ar, ar+10);
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	list<int>::reverse_iterator rit = mylist.rbegin();
	while(rit != mylist.rend())
	{
		cout<<*rit<<" ";
		++rit; // --
	}
	cout<<endl;
}

/*
void main()
{
	list<int> list3(10, 2);
	for(auto e : list3) //C++11
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	list<int> list1;
	list<int> list2(10);
	list<int> list3(10, 2);
	list<int> list4(list3);

	list<int>::iterator it = list4.begin();
	while(it != list4.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	list<int> list5(list4.begin(), list4.end());
}

/*
//空间配置器

//1 空间的申请
//2 对象的构造
//3 对象的析构
//4 空间的释放

template<class _Ty> inline
_Ty* _MyAllocate(size_t _N, _Ty *)
{
	cout<<"_Ty = "<<typeid(_Ty).name()<<endl;
	if (_N < 0)
		_N = 0;
	return ((_Ty *)operator new(_N * sizeof (_Ty))); 
}

template<class _T1, class _T2> inline
void _MyConstruct(_T1  *_P, const _T2& _V)
{
	new ((void*)_P) _T1(_V); //定位 new //????????//
}

template<class _Ty> inline
void _MyDestroy(_Ty  *_P)
{
	_P->~_Ty();
}

template<class _Ty>
class myallocator 
{
public:
	typedef size_t       size_type;
	typedef size_t       difference_type;
	typedef _Ty  *       pointer;
	typedef const _Ty *  const_pointer;
	typedef _Ty    &     reference;
	typedef const _Ty &  const_reference;
	typedef _Ty          value_type;
public:
	pointer allocate(size_type _N, const void *)
	{
		return (_MyAllocate(_N, (pointer)0)); 
	}
	void deallocate(void  *_P, size_type)
	{
		operator delete(_P); 
	}
	void construct(pointer _P, const _Ty& _V)
	{
		_MyConstruct(_P, _V); 
	}
	void destroy(pointer _P)
	{
		_MyDestroy(_P); 
	}

	char* _Charalloc(size_type _N)
	{
		return (_MyAllocate(_N,(char *)0)); 
	}
};

////////////////////////////////////////////////////////

template<class _Ty, class _A=myallocator<_Ty> >
class list
{
protected:
	struct _Node;
	typedef struct _Node* _Nodeptr;
	struct _Node
	{
		_Nodeptr _Next, _Prev;
		_Ty _Value;
	};
	struct _Acc;
	struct _Acc
	{
		typedef struct _Node*& _Nodepref;
		typedef _Ty&           _Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{return ((_Nodepref)((*_P)._Next));} // _P->_Next;
		static _Nodepref _Prev(_Nodeptr _P)
		{return ((_Nodepref)((*_P)._Prev));}// _P->_Prev;
		static _Vref _Value(_Nodeptr _P)
		{return ((_Vref)(*_P)._Value);} //_P->_Value;
	};
public:
	// 萃取
	typedef size_t    size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      pointer;
	typedef _Ty&      reference;
	typedef const _Ty* const_pointer;
	typedef const _Ty& const_reference;
public:
	//class const_iterator;
	class iterator  //????
	{
	public:
		iterator()
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
		_Nodeptr _Mynode()const
		{
			return  _Ptr;
		}
	public:
		_Ty operator*()
		{
			return _Acc::_Value(_Ptr);
		}
		_Ty* operator->()
		{
			return &(_Acc::_Value(_Ptr));
		}
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return tmp;
		}
		iterator& operator--()
		{
			_Ptr = _Acc::_Prev(_Ptr);
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return tmp;
		}
	public:
		bool operator==(const iterator &it)
		{
			return _Ptr == it._Ptr;
		}
		bool operator!=(const iterator &it)
		{
			return !(*this == it);
		}
	protected:
		_Nodeptr _Ptr;
	};
	typedef iterator _It;
public:
	explicit list() : _Head(_Buynode()),_Size(0)
	{}
	explicit list(size_type _N, const _Ty& _V = _Ty())
		:_Head(_Buynode()), _Size(0)
	{
		insert(begin(), _N, _V); 
	}
	list(const _Ty *_F, const _Ty *_L)
		:_Head(_Buynode()), _Size(0)
	{
		insert(begin(), _F, _L); 
	}
	list(_It _F, _It _L)
		: _Head(_Buynode()), _Size(0)
	{
		insert(begin(), _F, _L); 
	}
	~list()
	{
		erase(begin(), end());
		_Freenode(_Head);
		_Head = 0, _Size = 0;
	}
public:
	iterator begin()
	{
		return iterator(_Acc::_Next(_Head)); 
	}
	iterator end()
	{
		return iterator(_Head);
	}
public:
	void push_back(const _Ty &_X)
	{
		insert(end(), _X);
	}
	void push_front(const _Ty &_X)
	{
		insert(begin(), _X);
	}
public:
    void pop_front();
	void pop_back();
	reference back();
	reference front();
	bool empty();
	size_type size();
public:
	void insert(iterator _P, _It _F, _It _L )
	{
		for(; _F != _L; ++_F)
			insert(_P, *_F);
	}
	void insert(iterator _P, const _Ty *_F, const _Ty *_L)
	{
		for(; _F != _L; ++_F)
			insert(_P, *_F);
	}
	void insert(iterator _P, size_type _M, const _Ty &_X)
	{
		for(; 0 < _M; --_M)
			insert(_P, _X);
	}
	iterator insert(iterator _P, const _Ty &_X=_Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next (_Acc::_Prev(_S)) = _S;

		//_Acc::_Value(_S) = _X;
		allocator.construct(&_Acc::_Value(_S), _X);

		_Size++;
		return iterator(_S);
	}
public:
	iterator erase(iterator _F, iterator _L)
	{
		while(_F != _L)
			erase(_F++);
		return _F;
	}
	iterator erase(iterator _P)
	{
		_Nodeptr _S = (_P++)._Mynode();
		_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
		_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);
		
		allocator.destroy(&_Acc::_Value(_S));

		_Freenode(_S);
		--_Size;
		return (_P);
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg=0, _Nodeptr _Parg=0)
	{
		//_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_Nodeptr _S = (_Nodeptr)allocator._Charalloc(sizeof(_Node));
		//_Nodeptr _S = (_Nodeptr)allocator.allocate(1, (_Nodeptr)0);
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		return _S;
	}
	void _Freenode(_Nodeptr _S)
	{
		allocator.deallocate(_S, 1); 
		//free(_S);
	}
private:
	_Nodeptr _Head;
	size_type _Size;
	_A allocator;
};

void main()
{
	list<int> mylist;
	mylist.push_back(1);
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(int);
	//list<int> mylist;
	//list<int> mylist(10);

	list<int> mylist(ar, ar+n);
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
	cout<<endl;

	list<int> youlist(mylist.begin(), mylist.end());
}

/*
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);

	//1 2 3 4
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
	cout<<endl;

	it = mylist.begin();
	it++;

	mylist.erase(it);

	it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
	cout<<endl;
}

/*
class Test
{
public:
	void fun()
	{
		cout<<"Test::fun()"<<endl;
	}
};

void main()
{
	list<Test> mylist;
	Test t1, t2, t3, t4;
	Test *pt = &t1;
	mylist.push_back(t1);
	mylist.push_back(t2);
	mylist.push_back(t3);
	mylist.push_back(t4);

	list<Test>::iterator it = mylist.begin();
	//(*it).fun();

	it->fun();

}


/*
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_front(3);
	mylist.push_front(4);

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
}

/*
	void push_back(const _Ty & _X)
	{
		_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
		_Acc::_Value(_S) = _X;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Acc::_Next(_S)) = _S;
		_Size++;
	}
	void push_front(const _Ty & _X)
	{}
	void push_back(const _Ty & _X)
	{
		_Nodeptr _S = _Buynode(_Head, _Head->_Prev);
		_S->_Value = _X;
		_S->_Prev->_Next = _S;
		_S->_Next->_Prev = _S;
		_Size++;
	}
	
	void push_back(const _Ty & _X)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_S->_Value = _X;
		_S->_Next = _Head;
		_S->_Prev = _Head->_Prev;
		_S->_Prev->_Next = _S;
		_Head->_Prev = _S;
		_Size++;
	}
	



/*
void main()
{
	list<int> mylist;
	list<int>::iterator p = mylist.end();
	mylist.insert(p, 1);
	mylist.insert(p, 2);
	mylist.insert(p, 3);
	mylist.insert(p, 4);

}



/*
void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
	cout<<"Over"<<endl;
}

/*
void main()
{
	int x = int();
	char ch = char();
	double d = double();
}

/*
template<typename Type, int MaxSize=100>
class Stack
{
public:
	Stack()
	{
		capacity = MaxSize;
		base = new Type[capacity];
		size = 0;
	}
private:
	Type *base;
	size_t capacity;
	size_t size;
};

void main()
{
	Stack<int, 200> st;
}

/*
template<typename Type1, typename Type2=int>
class Stack 
{
public:
	Stack()
	{
		cout<<"Stack::Stack<Type1, Type2>"<<endl;
	}
};

void main()
{
	Stack<char, double> st;
}

/*
template<typename Type1, typename Type2>
class Stack
{
public:
	Stack()
	{
		cout<<"Stack::Stack<Type1, Type2>"<<endl;
	}
};

template<typename Type>
class Stack<Type, Type>
{
public:
	Stack()
	{
		cout<<"Stack::Stack<Type, Type>"<<endl;
	}
};

void main()
{
	Stack<char, char> st1;
	Stack<int, int> st2;
	Stack<char, int> st3;

}

/*
//泛化
template<typename Type>
class Stack
{
public:
	Stack()
	{
		cout<<"Stack::Stack<Type>"<<endl;
	}
};

//特化
template<>
class Stack<int>
{
public:
	Stack()
	{
		cout<<"Stack::Stack<int>"<<endl;
	}
};

void main()
{
	Stack<char> st1;
	Stack<int> st2;

}
*/