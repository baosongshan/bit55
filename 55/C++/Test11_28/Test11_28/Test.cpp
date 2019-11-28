#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A(int a=0)
	{
		cout<<"A::A()"<<endl;
	}
	~A()
	{
		cout<<"A::~A()"<<endl;
	}
};

class B
{
public:
	B()
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
	C()
	{
		cout<<"C::C()"<<endl;
	}
	~C()
	{
		cout<<"C::~C()"<<endl;
	}
};

class D : public A, public B, public C
{
public:
	D():a(1), b(),c()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	A a;
	C c;
	B b;
};

void main()
{
	D d;
}



/*
class Base1
{
public:
	Base1()
	{
		cout<<"Base1::Base1()"<<endl;
	}
	~Base1()
	{
		cout<<"Base1::~Base1()"<<endl;
	}
};
class Base2
{
public:
	Base2()
	{
		cout<<"Base2::Base2()"<<endl;
	}
	~Base2()
	{
		cout<<"Base2::~Base2()"<<endl;
	}
};


class D : public Base2,public Base1   //1
{
public:
	D()  //3
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	Base2 b2;  //2
	Base1 b1;
};

void main()
{
	D d;
}

/*
class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
void Test()
{
	Student s1;
	s1.Print();
};

void main()
{
	Test();
}

/*
class Base
{
public:
	Base()
	{
		//cout<<"Base::Base()"<<endl;
	}
	~Base()
	{
		//cout<<"Base::~Base()"<<endl;
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int)
	{
		cout<<"Base::fun(int)"<<endl;
	}
private:
	int count = 0;
};

class D : public Base
{
public:
	D()
	{
		//cout<<"D::D()"<<endl;
	}
	~D()
	{
		//cout<<"D::~D()"<<endl;
	}
public:
	//同名隐藏
	void fun(int, int)
	{
		cout<<"D::fun(int, int)"<<endl;
	}
public:
	int data = 0;
};

/*
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};

class Student : public Person
{
public:
	int _No; // 学号
};

void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	
	
	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;
	
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;  //
	
}

void main()
{
	Test();
}

/*
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name; // 姓名
private:
	int _age; // 年龄
	string _sex;
};

//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // 学号
};

//多态

void main()
{
	Person p;
	Student s;

	//p = s;
	Person *ps = &s;
	//Person &rp = s;

	//s = p;
	Student *pst = (Student*)ps;
	//Student &rs = p;
}

/*
class Base
{
public:
	Base()
	{
		//cout<<"Base::Base()"<<endl;
	}
	~Base()
	{
		//cout<<"Base::~Base()"<<endl;
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int)
	{
		cout<<"Base::fun(int)"<<endl;
	}
private:
	int count = 0;
};

class D : public Base
{
public:
	D()
	{
		//cout<<"D::D()"<<endl;
	}
	~D()
	{
		//cout<<"D::~D()"<<endl;
	}
public:
	//同名隐藏
	void fun(int, int)
	{
		cout<<"D::fun(int, int)"<<endl;
	}
public:
	int data = 0;
};

void main()
{
	D d;
	d.Base::fun();
	d.Base::fun(1);
	d.fun(1,2);
}

/*
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name; // 姓名
private:
	int _age; // 年龄
	string _sex;
};

//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // 学号
};

//多态

void main()
{
	Person p;
	Student s;

	p = s;
	Person *ps = &s;
	Person &rp = s;

	//s = p;
	//Student *pst = &p;
	Student &rs = p;
}

/*
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
	}
	~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
private:
	int count = 0;
};

class D : public Base
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
public:
	int data = 0;
};

class A
{};
class X
{};

void main()
{
	Base b;
	Base *pb = nullptr;

	D d;
	// 赋值兼容规则
	//1 可以直接使用子类对象对父类对象进行赋值
	b = d;
	//2 可以用子类对象的地给父类指针直接赋值
	pb = &d;
	//3 可以直接使用子类对象为父类的引用初始化 
	Base &rb = d;
}


/*
int find(int ar[], int n, int x)
{
	int low = 0;
	int high = n-1;
	int mid;
	while(low <= high)
	{
		mid = (low +high) / 2;
		if(x == ar[mid])
			return mid;
		else if(x > ar[mid])
		{
			if() //???????
			{
				high = mid-1;
			}
			else
				low = mid+1;
		}
		else
		{
			if()  //???????
			{
				low = mid + 1;
			}
			else
				high = mid-1;
		}
	}
}


/*
int main()
{
    string str;
    char hash[123] = {0};
    while(cin>>str)
    {
        memset(hash, 0, 123);
        for(int i=0; i<str.size(); ++i)
        {
            if(hash[str[i]] == 0)
            {
                hash[str[i]]++;
                cout<<str[i];
            }
        }
        //str.clear();
    }
    return 0;
}

/*
class Test
{
public:
	Test(int d)
	{
		m_data = d;
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
private:
	int m_data;
};

void main()
{
	//1
	//Test t(10); //静态

	Test *pt = new Test(1); //operator new()   构造对象 //动态
	delete pt;
}

/*
class A
{
	int i;
};
class B
{
	A *p;
public:
	B()
	{
		p = new A; 
	}
	~B()
	{
		delete p;
	}
};

void sayHello(B b)  //p
{
	//
}
int main()
{
	B b; //p
	sayHello(b);
}

/*
// static  const 

class A 
{
public:
	A(int v = 0):vv(v)
	{}
public:
	//int GetValue(A * const this);
	int GetValue()
	{
		return vv;
	}
	//int GetValue(const A * const this)
	int GetValue()const
	{
		((A * const)this)->vv = 1;
		//vvv = 0;
		return vv;
	}
private:
	//mutable int vv;
	int vv;
	int vvv;
};

void main()
{
	const A a;
	A b;
	a.GetValue();
	b.GetValue();

}

/*
int fun(int a, int b)
{
	return a + b;
}

void main()
{
	fun(1,2);
	fun(2,3);
	fun(3,4);
	//.....
}



/*
class Sample
{
public:
	Sample(int x)
	{
		//________
		p = new int(x);
	}
	~Sample()
	{
		if (p) delete p;
	} 
	int show()
	{
			return *p;
	} 
private :
	int*p;
};

int main()
{
	Sample S(5);
	cout << S.show() << endl;
	return 0;
}
*/