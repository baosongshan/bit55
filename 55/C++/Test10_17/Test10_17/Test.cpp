#include<iostream>
using namespace std; //命名空间

int& fun(int a, int b)
{
	int value = a + b;
	return value; //cccccccc
}

int main()
{
	int &result = fun(1,2);
	fun(10,20);
	cout<<"result = "<<result<<endl; //??
	return 0;
}
/*
//int fun(int ar[], int br[], int n)
//int fun(int *ar, int *br, int n)
int& fun(int (&ar)[10], int (&br)[10], int n)
{
	int sum = 0;
	for(int i=0; i<n; ++i)
	{
		sum += ar[i] + br[i];
	}
	return sum;
}

int main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int br[10] = {10,9,8,7,6,5,4,3,2,1};
	int result = fun(ar, br, 10);
	cout<<"result = "<<result<<endl;
	return 0;
}

/*
int main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};

	int (&br)[10] = ar;

	br;

	return 0;
}


int main()
{
	int a = 10; //常量
	const int &b = a; //语义
	

	return 0;
}

/*
void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}

/*
int fun(int a, int b, int c=0, int d=0)
{
	return a + b;
}

int main()
{
	cout<<fun(10,20)<<endl;
	return 0;
}


/*
namespace myspace
{
	void fun()
	{
		cout << "Hello World" << endl;
	}
	void fun1()
	{
		cout << "Hello World 1" << endl;
	}
};
namespace youspace
{
	void fun()
	{
		cout << "Hello Bit" << endl;
	}
};

//using namespace myspace;
using myspace::fun1;
void main()
{
	myspace::fun();
	fun1();
}

/*
void fun()
{
	cout << "Hello HaHa" << endl;
}

//作用域访问符
//using namespace myspace;
void main()
{
	//myspace::fun();
	fun();
}

/*
void fun()
{
	cout<<"Hello World"<<endl;
}

void fun()
{
	cout<<"Hello Bit"<<endl;
}

void main()
{
	fun();
}


/*
#define A

#ifdef A
void fun()
{
	cout<<"Hello World"<<endl;
}
#else
void fun()
{
	cout<<"Hello Bit"<<endl;
}
#endif

void main()
{
	fun();
}

/*
extern "C" int Max(int a, int b)
{
	return a > b ? a : b;
}
extern "C" char Max(char a, char b)
{
	return a > b ? a : b;
}
void main()
{
	cout<<Max(10,20)<<endl;
	cout<<Max('A','b')<<endl;
}

/*
template<class Type>
Type Max(Type a, Type b)
{
	return a > b ? a: b;
}

void main()
{
	cout<<Max(10,20)<<endl;
	cout<<Max(1.2, 2.3)<<endl; //最优原则
	cout<<Max('a', 'b')<<endl;
	cout<<Max(10L, 20L)<<endl;
}


int Max(int a, int b)
{
	return a > b ? a : b;
}
double Max(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(10,20)<<endl;
}


/*
//参数列表
int Max(int a, int b)
{
	return a > b ? a : b;
}
char Max(char a, char b)
{
	return a > b ? a : b;
}
int Max(int a, int b, int c)
{
	return Max(Max(a, b),c);
}
int Max(int a, double b)
{
	return a > b ? a : b;
}
int Max(double a, int b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(10,20)<<endl;
	cout<<Max('a', 'b')<<endl; //最优原则
	cout<<Max(10,30,20)<<endl;
}

/*
//重载
int fun(int a, int b)
{
	return a + b;
}
double fun(double a, double b)
{
	return a + b;
}
long fun(long a, long b)
{
	return a + b;
}

int main()
{
	cout<<fun(10,20)<<endl;
	cout<<fun(12.3, 23.4)<<endl;
	cout<<fun(10L, 20L)<<endl;
	return 0;
}

/*
int main()
{
	int a = 10;
	char ch = 'A';
	double d = 12.34;
	char *str = "Hello";

	cout<<a<<endl; //printf  \n
	cout<<ch<<endl;
	cout<<d<<endl;
	cout<<str<<endl;
	return 0;
}


/*
int main()
{
	int a = 10;
	printf("%d\n", a);
	printf("%s\n", "Hello Bit.");
	cout<<"Hello Bit."<<endl;
	return 0;
}
*/