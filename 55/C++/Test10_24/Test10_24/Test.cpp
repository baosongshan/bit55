#include<iostream>
using namespace std;

/////////////////////////////////////////
//length()
//operator[]
//operator+
//operator+=
//operator > < >= <= == !=
/////////////////////////////////////////
class String
{
public:
	String(char *str = "")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data)+1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1("Hello"); //s1[0] ==> H
	String s2("Bit.");

	for(int i=0; i<s1.lenght(); ++i)
		cout<<s1[i];
	cout<<endl;

	String s = s1 + s2; //s = HelloBit
	String s1 += s2;    //
	if(s1 == s2)
		cout<<"s1 == s2"<<endl;
	if(s1 != s2)
		cout<<"s1 != s2"<<endl;
	if(s1 > s2)
		cout<<"s1 > s2"<<endl;
	if(s1 < s2)
		cout<<"s1 < s2"<<endl;
	if(s1 >= s2)
		cout<<"s1 >= s2"<<endl;
	if(s1 <= s2)
		cout<<"s1 <= s2"<<endl;

	return 0;
}

/*
class Int;
ostream& operator<<(ostream &out, const Int &i);

class Int
{
	friend ostream& operator<<(ostream &out, const Int &i);
public:
	Int(long i = 0) : m_i(i)
	{}
	~Int()
	{}
public:
	Int& operator++()
	{
		m_i++;
		return *this;
	}
	Int operator++(int)
	{
		Int tmp(m_i);
		++*this;
		return tmp;
	}
	Int operator--(); //
	Int operator--(int);
private:
	long m_i;
};

ostream& operator<<(ostream &out, const Int &i)
{
	out<<i.m_i;
	return out;
}

int main()
{
	Int i(1);
	Int v = i++;
	cout<<"i = "<<i<<endl;
	cout<<"v = "<<v<<endl;
	return 0;
}


/*
class Int;
ostraem& operator<<(ostream &out, const Int &i);

class Int
{
	friend ostraem& operator<<(ostream &out, const Int &i);
public:
	Int(long i = 0) : m_i(i)
	{}
public:
	Int operator+(const Int &x)
	{
		//Int tmp(m_i+x.m_i);
		//return tmp;
		return Int(m_i+x.m_i);
	}
	Int operator-(const Int &x);
	Int operator*(const Int &x);
	Int operator/(const Int &x);
	Int operator%(const Int &x);
public:
	Int& operator+=(const Int &x); // a += b;
	Int& operator-=(const Int &x);
	Int& operator*=(const Int &x);
	Int& operator/=(const Int &x);
	Int& operator%=(const Int &x);
public:
	Int operator>>(const Int &x); //a >> b
	Int operator<<(const Int &x);
	Int operator>>=(const Int &x);
	Int operator<<=(const Int &x);
public:
	bool operator==(const Int &x);
	bool operator!=(const Int &x);
public:
	Int operator++(); //
	Int operator++();
	Int operator--(); //
	Int operator--();
public:
	int GetData()const
	{return m_i;}
private:
	long m_i;
};

/*
//成员方法
//友元方法

class Complex;
Complex operator+(int x, const Complex &c);
ostream& operator<<(ostream &out, const Complex &c);

class Complex
{
	friend Complex operator+(int x, const Complex &c);
	friend ostream& operator<<(ostream &out, const Complex &c);
public:
	//Complex() : m_real(0), m_imag(0)
	//{}
	Complex(int real=0, int imag=0):m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	//c1 + c2; //c1.operator+(c2)
	Complex operator+(const Complex &c);
	Complex operator+(int x);
public:
	void PrintComplex()const
	{
		cout<<"("<<m_real<<","<<m_imag<<")"<<endl;
	}
private:
	int m_real;
	int m_imag;
};

Complex Complex::operator+(const Complex &c)
{
	Complex tmp(m_real+c.m_real, m_imag+c.m_imag);
	return tmp;
}

Complex Complex::operator+(int x)
{
	Complex tmp(m_real+x, m_imag+x);
	return tmp;
}

Complex operator+(int x, const Complex &c)
{
	Complex tmp(x+c.m_real, x+c.m_imag);
	return tmp;
}

ostream& operator<<(ostream &out, const Complex &c)
{
	out<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}

int main()
{
	Complex c;
	Complex c1(1,2);
	Complex c2(2,5);

	c = c1 + c2; // c1.operator+(c2);
	c = c1 + 10; // 10
	c = 10 + c1; // operator+(10, c1)
	//c.PrintComplex();
	cout<<c<<endl; //operator<<(cout, c);
	
	return 0;
}

/*
class Test;
void fun(Test t); 

class Test
{
	friend void fun(Test t); // 封装
public:
	Test(int d = 0) : m_data(d)
	{}
private:
	int m_data;
};

void fun(Test t)
{
	cout<<t.m_data<<endl;
}

void main()
{
	Test t(100);
	fun(t);
}

/*
//成员方法
//友元方法
class Complex
{
public:
	//Complex() : m_real(0), m_imag(0)
	//{}
	Complex(int real=0, int imag=0):m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	//c1 + c2; //c1.operator+(c2)
	Complex operator+(const Complex &c);
	Complex operator+(int x);
public:
	void PrintComplex()const
	{
		cout<<"("<<m_real<<","<<m_imag<<")"<<endl;
	}
private:
	int m_real;
	int m_imag;
};

Complex Complex::operator+(const Complex &c)
{
	Complex tmp(m_real+c.m_real, m_imag+c.m_imag);
	return tmp;
}

Complex Complex::operator+(int x)
{
	Complex tmp(m_real+x, m_imag+x);
	return tmp;
}

int main()
{
	Complex c;
	Complex c1(1,2);
	Complex c2(2,5);

	c = c1 + c2; // c1.operator+(c2);
	c = c1 + 10; // 10
	c = 10 + c1;
	c.PrintComplex();
	
	return 0;
}

/*
typedef struct Test
{
	char a : 1;
	char b : 3;
}Test;

int main()
{
	cout<<sizeof(Test)<<endl; //40  38
	return 0;
}

typedef struct Test
{
	short a;  //2 + 6
	struct
	{
		int b; //4 +4
		double c; //8
		char d; //1 +7
	};
	long e;  //4 + 4
}Test;

int main()
{
	cout<<sizeof(Test)<<endl; //40  38
	Test t;
	return 0;
}

/*
#pragma pack(1)

typedef struct Test
{
	char a;   //1 + 3
	double b; //8
	char c;   //1 + 3
}Test;

int main()
{
	cout<<sizeof(Test)<<endl; //17
	Test t;
	t.a = 'A';
	t.c = 'B';
	t.b = 12.34;
	return 0;
}

/*
typedef struct Test
{
	char a;   //1
	char c;   //1 + 6
	double b; //8
}Test;

int main()
{
	cout<<sizeof(Test)<<endl; //10
	Test t;
	t.a = 'A';
	t.c = 'B';
	t.b = 12.34;
	return 0;
}

/*
//命令行参数
//argc: argument count
//argv: argument value
int main(int argc, char *argv[])
{
	FILE *fpIn = fopen(argv[1], "r");
	if(fpIn == NULL)
		return -1;
	FILE *fpOut = fopen(argv[2],"w");
	if(fpOut == NULL)
		return -1;

	char ch;
	while(!feof(fpIn))
	{
		ch = fgetc(fpIn);
		fputc(ch, fpOut);
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}


int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	for(int i=0; i<argc; ++i)
	{
		printf("argc[%d] = %s\n", i, argv[i]);
	}

	return 0;
}
*/