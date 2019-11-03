#include<iostream>
//#include<list>
using namespace std;

template<class _Ty>
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
	typedef size_t size_type;
	typedef size_type difference_type;
	typedef _Ty       value_type;
	typedef _Ty*      pointer;
	typedef _Ty&      reference;
	typedef const _Ty* const_pointer;
	typedef const _Ty& const_reference;
public:
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
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
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
public:
	explicit list() : _Head(_Buynode()),_Size(0)
	{}
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
	*/
	void push_back(const _Ty &_X)
	{
		insert(end(), _X);
	}
	void push_front(const _Ty &_X)
	{
		insert(begin(), _X);
	}
public:
	iterator insert(iterator _P, const _Ty &_X=_Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next (_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		_Size++;
		return iterator(_S);
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg=0, _Nodeptr _Parg=0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
		return _S;
	}
private:
	_Nodeptr _Head;
	size_type _Size;
};

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
		++it;
	}
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