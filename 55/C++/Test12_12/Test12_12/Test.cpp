#include<iostream>
using namespace std;

class B 
{};

class D : public B
{};

void main()
{
	D d;
	B b;
}

/*
//
class B
{
public:
	B* GetInstanct()
	{
		return new B;
	}
private:
	B()
	{}
};

class D : public B
{};

void main()
{
	D d;
	B b;
}
/*
class Base
{
public:
	virtual Base* fun(int)
	{
		cout<<"1111111111111"<<endl;
		return this;
	}
	Base()
	{
		cout<<"Base::Base()"<<endl;
	}
	virtual ~Base()  ///
	{
		cout<<"Base::~Base()"<<endl;
	}
};

class D : public Base
{
public:
	virtual D* fun(int)
	{
		cout<<"22222222222"<<endl;
		//return 0;
		return this;
	}
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
	//D d;
	Base *pd = new D;
	delete pd;
}

/*

void main()
{
	Base *pb = new D;
	pb->fun(1);
}
/*
class Base
{
public:
	virtual void f()
	{
		cout<<"This is Base::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"This is Base::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"This is Base::h()"<<endl;
	}
};

class Base1
{
public:
	virtual void f()
	{
		cout<<"This is Base1::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"This is Base1::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"This is Base1::h()"<<endl;
	}
};

class Base2
{
public:
	virtual void f()
	{
		cout<<"This is Base2::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"This is Base2::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"This is Base2::h()"<<endl;
	}
};

class D : public Base, public Base1, public Base2
{
public:
	virtual void f()
	{
		cout<<"This is D::f1()"<<endl;
	}
	virtual void g1()
	{
		cout<<"This is D::g1()"<<endl;
	}
	virtual void h1()
	{
		cout<<"This is D::h()"<<endl;
	}
};

void main()
{
	D d;
	Base2 *pb = &d;
	pb->f();
}


/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"This is Base::fun()"<<endl;
	}
	void fun(int a, int b)
	{}
	virtual void show()
	{
		cout<<"This is Base;;show()"<<endl;
	}
	void fun1()
	{
		cout<<"This is Base::fun1()"<<endl;
	}
private:
	int base_data;
};

class D : public Base
{
public:
	void fun()
	{
		cout<<"This is D::fun()"<<endl;
	}
	void show()
	{
		cout<<"This is D::show()"<<endl;
	}
	virtual void print()
	{
		cout<<"This is D::print()"<<endl;
	}

private:
	int d_data;
};

void main()
{
	D d;
	memset(&d, 0, sizeof(D));
	Base *pb = &d;
	pb->fun();    //  
}

/*
class Base
{
public:
	Base()
	{
		base_data = 0;
	}
public:
	virtual void fun()
	{
		cout<<"This is Base::fun()"<<endl;
	}
	virtual void show()
	{
		cout<<"This is Base;;show()"<<endl;
	}
	void fun1()
	{
		cout<<"This is Base::fun1()"<<endl;
	}
private:
	int base_data;
};

class D : public Base
{
public:
	D()
	{
		d_data = 0;
	}
public:
	void fun()
	{
		cout<<"This is D::fun()"<<endl;
	}
	void show()
	{
		cout<<"This is D::show()"<<endl;
	}
	virtual void print()
	{
		cout<<"This is D::print()"<<endl;
	}

private:
	int d_data;
};

typedef void(*vfptr_type)();
void PrintVTable(vfptr_type vtable[])
{
	cout<<"Ðé±íµØÖ·:>"<<vtable<<endl;
	for(int i=0; vtable[i]!=nullptr; ++i)
	{
		vtable[i](); //(vtable+1)();
	}
}
void main()
{
	//Base b;
	D d;
	vfptr_type *vtable = (vfptr_type*)(*(int*)&d);
	PrintVTable(vtable);
}

/*
class D : public Base
{
public:
	D()
	{
		d_data = 0;
	}
public:
	void fun()
	{
		cout<<"This is D::fun()"<<endl;
	}
	void show()
	{
		cout<<"This is D::show()"<<endl;
	}
	virtual void print()
	{
		cout<<"This is D::print()"<<endl;
	}

private:
	int d_data;
};

void main()
{
	D d;
}

/*
void main()
{
	cout<<sizeof(Base)<<endl;
	D d;
	Base *pb = &d;
	pb->fun();
	pb->show();
	//pb->print();
}

/*
class C : public Base
{
public:
	C()
	{
		c_data = 0;
	}
public:
	void fun()  //¸²¸Ç
	{
		cout<<"This is C::fun()"<<endl;
	}
private:
	int c_data;
};
void main()
{
	D d;
	C c;
	Base *pb = &c;

	////////////////////////////////////////
	pb->fun();    //
	
}

/*
void main()
{
	Base b;
	b.fun();

	D d;
	d.fun();
}
*/