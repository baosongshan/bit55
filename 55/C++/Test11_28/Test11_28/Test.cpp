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
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
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
	//ͬ������
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
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};

class Student : public Person
{
public:
	int _No; // ѧ��
};

void Test()
{
	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	
	
	//2.��������ܸ�ֵ�����������
	//sobj = pobj;
	
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj;
	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
	string _name; // ����
private:
	int _age; // ����
	string _sex;
};

//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // ѧ��
};

//��̬

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
	//ͬ������
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
	string _name; // ����
private:
	int _age; // ����
	string _sex;
};

//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // ѧ��
};

//��̬

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
	// ��ֵ���ݹ���
	//1 ����ֱ��ʹ���������Ը��������и�ֵ
	b = d;
	//2 �������������ĵظ�����ָ��ֱ�Ӹ�ֵ
	pb = &d;
	//3 ����ֱ��ʹ���������Ϊ��������ó�ʼ�� 
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
	//Test t(10); //��̬

	Test *pt = new Test(1); //operator new()   ������� //��̬
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