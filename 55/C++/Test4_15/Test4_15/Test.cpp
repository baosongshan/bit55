#include<iostream>
#include<string>
#include<memory>
#include<vld.h>
using namespace std;

#include<boost/smart_ptr.hpp>

void main()
{
	int *p = new int(10); 
	boost::shared_ptr<int> sptr(p);
	cout<<"use_count = "<<sptr.use_count()<<endl;

	boost::weak_ptr<int> wptr(sptr);
	boost::weak_ptr<int> wptr1(wptr);
	cout<<"use_count = "<<sptr.use_count()<<endl;

}

/*
void main()
{
	int *p = new int(10); 
	boost::shared_ptr<int> sptr(p);
	cout<<*p<<endl;

	cout<<"use_count = "<<sptr.use_count()<<endl;

	{
		boost::shared_ptr<int> sptr1(sptr);
		cout<<"use_count = "<<sptr.use_count()<<endl;
	}
	cout<<"use_count = "<<sptr.use_count()<<endl;
	boost::shared_ptr<int> sptr2;
	sptr2 = sptr;
	cout<<"use_count = "<<sptr.use_count()<<endl;
}

/*
void main()
{
	int *pa = new int[10]{1,2,3,4,5,6,7,8,9,10};
	boost::scoped_array<int> sptr(pa);
	for(int i=0; i<10; ++i)
		cout<<sptr[i]<<" ";
	cout<<endl;

	//boost::scoped_array<int> sptr1(sptr);
}

/*
void main()
{
	int *p = new int(10); 
	boost::scoped_ptr<int> sptr(p);  //貔貅
	cout<<*sptr<<endl;

	//boost::scoped_ptr<int> sptr1;
	//sptr1 = sptr;
}

/*
namespace bit
{
	//vs2013 缺点:不能管理数组对象
	template<class _Ty>
	class auto_ptr   //smart_ptr
	{
		typedef auto_ptr<_Ty> _Myt;
	public:
		explicit auto_ptr(_Ty *_Ptr = 0): _Myptr(_Ptr)
		{}
		auto_ptr(_Myt& _Right)	: _Myptr(_Right.release())
		{}
		_Myt& operator=(_Myt& _Right)
		{	
			reset(_Right.release());
			return (*this);
		}
		~auto_ptr()
		{
			delete []_Myptr;   //_Myptr==nullptr  delete nullptr;
		}
	public:
		_Ty& operator*() const
		{
			return (*get());
		}
		_Ty *operator->() const
		{
			return (get());
		}
		_Ty *get() const 
		{	
			return (_Myptr);
		}
		_Ty *release()
		{
			_Ty *_Tmp = _Myptr;
			_Myptr = 0;
			return (_Tmp);
		}
		void reset(_Ty *_Ptr = 0)
		{	
			if (_Ptr != _Myptr)
				delete _Myptr;
			_Myptr = _Ptr;
		}
	private:
		_Ty *_Myptr;
	};
};

void main()
{
	int *p = new int(10);    //单个对象
	bit::auto_ptr<int> aptr1(p);
	cout<<"*aptr1 = "<<*aptr1<<endl;

	//int *q = new int(20);
	int *&q = p;

	aptr1.reset(q);
}

/*
void main()
{
	int *p = new int(10);    //单个对象
	bit::auto_ptr<int> aptr1(p);
	cout<<"*aptr1 = "<<*aptr1<<endl;

	//C++语法 
	bit::auto_ptr<int> aptr2(aptr1);
	cout<<"*aptr2 = "<<*aptr2<<endl;
	//cout<<"*aptr1 = "<<*aptr1<<endl;

	bit::auto_ptr<int> aptr3;
	aptr3 = aptr2;
}

/*
namespace bit
{
	//vc6.0  
	//缺点:不能管理数组对象  拥有权转义不彻底
	template<class _Ty>
	class auto_ptr 
	{
	public:
		explicit auto_ptr(_Ty *_P=0):_Owns(_P!=0), _Ptr(_P)
		{}
		auto_ptr(auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
		{}
		auto_ptr<_Ty>& operator=( auto_ptr<_Ty> &_Y)
		{
			if(this != &_Y)
			{
				if (_Ptr != _Y._Ptr)
				{
					if (_Owns)
						delete _Ptr;
					_Owns = _Y._Owns;
				}
				else if (_Y._Owns)
					_Owns = true;
				_Ptr = _Y.release();
			}
			return *this;
		}

		~auto_ptr()
		{
			if(_Owns)
			{
				delete _Ptr; //delete[]_Ptr;
				_Ptr = NULL;
			}
		}
	public:
		_Ty& operator*()const
		{
			return *_Ptr;
		}
		_Ty* operator->()const
		{
			return _Ptr;
		}
		_Ty *release()
		{
			this->_Owns = false;
			return (_Ptr); 
		}
	private:
		bool _Owns;
		_Ty *_Ptr;
	};
};

void main()
{
	int *p = new int(10);    //单个对象
	bit::auto_ptr<int> aptr1(p);
	cout<<"*aptr1 = "<<*aptr1<<endl;

	//C++语法 
	bit::auto_ptr<int> aptr2(aptr1);
	cout<<"*aptr2 = "<<*aptr2<<endl;
	cout<<"*aptr1 = "<<*aptr1<<endl;

	int *q = new int(20);
	bit::auto_ptr<int> aptr3(q);  //

	aptr3 = aptr2;

	bit::auto_ptr<int> aptr4(p);
	aptr4 = aptr2;
}

/*
void main()
{
	bit::auto_ptr<int> aptr; //空智能指针
	int *p = new int(10);    //单个对象
	bit::auto_ptr<int> aptr1(p);
	cout<<"*aptr1 = "<<*aptr1<<endl;

	//.......

	bit::auto_ptr<string> aptr2(new string("HelloBit"));
	cout<<"sptr2 size = "<<aptr2->size()<<endl;
}

/*
//智能指针  指针的本质是一个对象 *ptr  ptr->
//          


/*
class Test
{
public:
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	int *p = new int(1); 
	cout<<*p<<endl;

	//自动指针
	auto_ptr<int> aptr(p);
	cout<<*aptr<<endl;
	*aptr = 100;

	Test *pt = new Test;
	auto_ptr<Test> aptr1(pt);
	aptr1->fun();

}

/*
#define DefaultArraySize 10

template<typename elemType>
class Array
{
private:
	int  size;	
	elemType * ia;
public:
	explicit Array(int sz=DefaultArraySize)
	{
		size=sz;
		ia=new elemType [size];
	}
	~ Array()
	{
		delete [] ia;
	}
	elemType & operator[](int ix) const
	{ 
		if(ix<0||ix>=size)
		{
			string eObj="out_of_range error in Array<elemType >::operator[]()";
			throw out_of_range(eObj);	
			//throw range_error(eObj);
			//throw bad_alloc(eObj);
		}
		return  ia[ix];
	}
};

void main()
{
	//int br[10];   br[12];
	Array<int> ar;
	for(int i=1; i<=10; ++i)
	{
		ar[i-1] = i;
	}

	try
	{
		for(int i=0; i<=10; ++i)
		{
			cout<<ar[i]<<" ";
		}
		cout<<endl;
	}
	catch(const out_of_range &e)
	{
		cout<<e.what()<<endl;
		return;
	}
}


/*
void main()
{
	try
	{
		int *p = new int[500000000];
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
		return;
	}
	cout<<"new OK."<<endl;
}
*/