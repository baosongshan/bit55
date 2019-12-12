#include<iostream>
using namespace std;

//重载  隐藏  覆盖  //

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
	virtual void fun()
	{
		cout<<"This is D::fun()"<<endl;
	}
};

class C : public Base
{
public:
	virtual void fun()
	{
		cout<<"This is C::fun()"<<endl;
	}
};

class Z : public D
{
public:
	void fun()
	{
		cout<<"This is Z::fun()"<<endl;
	}
};

void main()
{
	D *pd = new Z;
	pd->fun();
}

/*
void main()
{
	//Base *pb = new D;
	Base *pb = new C;
	pb->fun();
}

/*
void main()
{
	Base *pb;   //指针
	D d;

	pb = &d;

	//b.fun();
	pb->fun();

	Base &rb = d; //引用
	rb.fun();
}


/*
class A
{
public:
	virtual void Eat()
	{
		cout<<"A::Eat()"<<endl; //??????
	}
	virtual void Foot()
	{
		cout<<"A::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"A::Sleep()"<<endl;
	}
};
class Person : public A
{
public:
	void Eat()
	{
		cout<<"Person::Eat()"<<endl; //??????
	}
	void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
};
class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog::Eat()"<<endl; //??????
	}
	void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}
};

//////////////////////////////////////////
class XLQ : public A
{
	void Eat()
	{
		cout<<"XLQ::Eat()"<<endl; //??????
	}
	void Foot()
	{
		cout<<"XLQ::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"XLQ::Sleep()"<<endl;
	}
};




///////////////////////////////////////////////////

void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

void main()
{
	Person p;
	Dog d;
	XLQ xlq;

	Active(&xlq);
}
/*
class Base
{
public:
	//重载
	virtual void fun()
	{
		cout<<"This is Base::fun()"<<endl;
	}
	void fun(int a)
	{
		cout<<"This is Base::fun(int)"<<endl;
	}
};

class D : public Base
{
public:
	void list()
	{
		cout<<"This is D::list()"<<endl;
	}
	//同名隐藏
	void fun()
	{
		cout<<"This is D::fun()"<<endl;
	}
	void fun(int a)
	{
		cout<<"This is D::fun(int)"<<endl;
	}
};

void main()
{
	D d;
	Base *pb = &d;
	pb->fun();

}

/*
void main()
{
	Base *pb;
	D *pd;
	D d;
	pb = &d; //

	pd = &d;

	//静态绑定
	pb->fun();
	//pb->list();

	pd->list();

	//d.fun();
}

/*
void main()
{
	D d;
	d.fun();
	d.fun(1);
}

/*
//is_a 是一种 继承
//has_a 是一部分 组合
class A
{
public:
	void Eat()
	{}
	void Foot()
	{}
	void Sleep()
	{}
};

class Person : public A
{};
class Dog : public A
{};


class E
{};
class D
{};
class T
{};

class Car
{
public:
	E e;
	D d[2];
	T t[4];
};


/*
class Base
{
public:
	int base_data;
};

class A : virtual public Base
{
public:
	int a_data;
};

class B : virtual public Base
{
public:
	int b_data;
};

class D :public A, public B  //多继承
{
public:
	int d_data;
};

void main()
{
	cout<<sizeof(D)<<endl;
	D d;
	d.a_data = 1;
	d.b_data = 2;
	d.d_data = 3;
	d.A::base_data = 5;
	d.B::base_data = 6;
	//d.base_data = 0;

	cout<<&(d.A::base_data)<<endl;
	cout<<&(d.B::base_data)<<endl;
}

/*
class Base
{
public:
	Base()
	{
		object_count++;
	}
public:
	static int object_count;
};
int Base::object_count = 0;

class A : public Base
{};

class B : public Base
{};

void main()
{
	A a;
	cout<<a.object_count<<endl;
	B b;
	cout<<a.object_count<<endl;
	cout<<b.object_count<<endl;
}

/*
class D;
class A
{
	friend ostream& operator<<(ostream &out, const D &d);
public:
	A(int a)
	{
		cout<<"A::A()"<<endl;
	}
	A(const A &a)
	{
		cout<<"A::A(const A&)"<<endl;
	}
	A& operator=(const A &a)
	{
		cout<<"A& A::operator=(const A&)"<<endl;
		return *this;
	}
	~A()
	{
		cout<<"A::~A()"<<endl;
	}
private:
	int a_data = 1; //C++11
};

class D : public A
{
	friend ostream& operator<<(ostream &out, const D &d);
public:
	D() : A(0)
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	int d_data = 2;
};

ostream& operator<<(ostream &out, const D &d)
{
	cout<<d.a_data;
	cout<<d.d_data;
	return out;
}

void main()
{
	D d;
	cout<<d<<endl;
}

/*
class B
{
public:
	B(int b)
	{
		cout<<"B::B()"<<endl;
	}
	~B()
	{
		cout<<"B::~B()"<<endl;
	}
};

class C
{
public:
	C(int c)
	{
		cout<<"C::C()"<<endl;
	}
	~C()
	{
		cout<<"C::~C()"<<endl;
	}
};

class D : public C, public A, public B
{
public:
	D(): B(2),_b(0),A(1),C(3),_a(0),_c(0)
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	C _c;
	A _a;
	B _b;
	
};

void main()
{
	D d;
}

/*
class D : public A
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
};

void main()
{
	D d;
}
*/