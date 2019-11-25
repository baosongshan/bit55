#include<iostream>
#include<string>
using namespace std;
class Base
{
public:
	void print()
	{
		cout<<"Base::print()"<<endl;
	}
public:
	void SetA(int  n)
	{
		a = n;
	}
protected:
	int b;   //
private:
	int a;
};

//////////////////////////////////////////////////////

class D :  public Base    //单继承
{
public:
	void list()
	{
		cout<<"D::list()"<<endl;
		print();
		b = 10;
	}
protected:
	void show()
	{
		cout<<"D::show()"<<endl;
	}
//////////////////////////////////////////////////
//////////////////////////////////////////////////

private:
	int x;
};

class E : public D, public Base    //多继承
{
public:
	void fun()
	{
		cout<<"E::fun()"<<endl;
		list();
		//print();
	}

};

//1 从对象的角度去观察
//2 从派生类的角度去观察父类

void main()
{
	E d;  //
	d.fun();
}

/*
class Base
{
public:
	void print()
	{
		cout<<"Base::print()"<<endl;
	}
public:
	void SetA(int  n)
	{
		a = n;
	}
protected:
	int b;   //
private:
	int a;
};

//////////////////////////////////////////////////////

class D : protected Base
{
public:
	void list()
	{
		cout<<"D::list()"<<endl;
		print();
		b = 10;
	}
protected:
	void show()
	{
		cout<<"D::show()"<<endl;
	}
//////////////////////////////////////////////////
//////////////////////////////////////////////////

private:
	int x;
};

void main()
{
	D d;
	d.print();
}

/*
class Base
{
public:
	void print()
	{
		cout<<"Base::print()"<<endl;
	}
public:
	void SetA(int  n)
	{
		a = n;
	}
protected:
	int b;   //
private:
	int a;
};

//////////////////////////////////////////////////////

class D : public Base
{
public:
	void list()
	{
		cout<<"D::list()"<<endl;
		x = 10;
		//a = 100;
		SetA(100);
		b = 10;
	}
protected:
	void show()
	{
		cout<<"D::show()"<<endl;
	}
//////////////////////////////////////////////////

//////////////////////////////////////////////////

private:
	int x;
};

void main()
{
	D d;
	//d.list();
	//d.b = 10;
}

/*
//#define DISPLAY

//
class Base
{
public:
	Base()
	{
#ifdef DISPLAY
		cout<<"Base::Base()"<<endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout<<"Base::~Base()"<<endl;
#endif
	}
public:
	void print()
	{
		cout<<"Base::print()"<<endl;
	}
private:
	int a;
};

//////////////////////////////////////////////////////

class D : public Base
{
public:
	D()
	{
#ifdef DISPLAY
		cout<<"D::D()"<<endl;
#endif
	}
	~D()
	{
#ifdef DISPLAY
		cout<<"D::~D()"<<endl;
#endif
	}
public:
	void list()
	{
		cout<<"D::list()"<<endl;
		print()
	}
protected:
	void show()
	{
		cout<<"D::show()"<<endl;
	}

private:
	int x;
};

void main()
{
	D d;
}


/*
class Person
{
private:
	string _name = "tony";
};

//继承
class Student : public Person
{
private:
	int _stuid;
};

class Teacher : public Person
{
private:
	int _jobid;
};

void main()
{
	cout<<sizeof(Student)<<endl;
	Student s;
}
*/