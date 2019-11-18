#include<iostream>
#include"temp.h"
#include<list>
using namespace std;

void main()
{
	int item;
	while(cin>>item, item!=-1)
	{

	}
}

/*
void main()
{
	FILE *fp = fopen("Test.txt", "w");
	fprintf(fp, "%s\n", "abc");
	fprintf(fp, "%s\n", "xyz");
	fclose(fp);
}

/*
void main()
{
	int a = 100;
	cout<<a<<endl;  //缓冲区
	cerr<<a<<endl;  //  xxxxxxxx
	clog<<a<<endl;
}

/*
void main()
{
	char *str = "Hello";
	strlen(str);
	list<int> mylist;
	cout<<Add(10,20)<<endl;
}

/*
class String
{
public:
	String(const char *str = "")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s) :m_data(nullptr)
	{
		String tmp(s.m_data);
		swap(m_data, tmp.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			String tmp(s);
			swap(m_data, tmp.m_data);
		}
		return *this;
	}
	~String()
	{
		if(m_data)
		{
			delete []m_data;
			m_data = NULL;
		}
	}
private:
	char *m_data;
};

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{}
private:
	int m_data;
};

////////////////////////////////////////////////////////////

bool IsPODType(const char *type)
{
	const char* type_ar[] = {
								"bool",
								"short",
								"int",
								"float",
								"long",
								"double"
							};
	int n = sizeof(type_ar) / sizeof(const char*);
	for(int i=0; i<n; ++i)
	{
		if(strcmp(type, type_ar[i]) == 0)
			return true;
	}
	return false;
}

struct __true_type
{};
struct __false_type
{};
template<class T>
struct type_traits
{
	typedef __false_type IsPODType;  //类型的萃取
};
template<>
struct type_traits<int>
{
	typedef __true_type IsPODType; //
};

template<>
struct type_traits<Test>
{
	typedef __true_type IsPODType; //
};

////////////////////////////////////////////////////////////////
template<typename T>
void _Copy(T *dst, const T *src, size_t sz, __true_type)
{
	memcpy(dst, src, sizeof(T)*sz);
}
template<typename T>
void _Copy(T *dst, const T *src, size_t sz, __false_type)
{
	for(int i=0; i<sz; ++i)
	{
		dst[i] = src[i];
	}
}

//通用
template<typename T>
void Copy(T *dst, const T *src, size_t sz)
{
	//类型萃取
	typename typedef type_traits<T>::IsPODType IsPOD;  //

	//typedef type_traits<int>::IsPODType IsPOD;
	//__true_type IsPOD;

	_Copy(dst, src, sz, IsPOD());  //__true_type()
}


void main()
{
	int ar1[5] = {11,22,33,44,55};
	int ar2[5];
	Copy(ar2, ar1, 5);

	String sa1[3] = {"aa", "bb", "cc"};
	String sa2[3];
	Copy(sa2, sa1, 3);

	Test st1[3] = {10,20,30};
	Test st2[3];
	Copy(st2, st1, 3);
}


/*
//通用
template<typename T>
void Copy(T *dst, const T *src, size_t sz, bool IsPOD)
{
	//cout<<typeid(T).name()<<endl;
	//bool IsPOD = IsPODType(typeid(T).name());
	if(IsPOD)
		memcpy(dst, src, sizeof(T)*sz);
	else
	{
		for(int i=0; i<sz; ++i)
		{
			dst[i] = src[i];
		}
	}
}

bool IsPODType(const char *type)
{
	const char* type_ar[] = {
								"bool",
								"short",
								"int",
								"float",
								"long",
								"double"
							};
	int n = sizeof(type_ar) / sizeof(const char*);
	for(int i=0; i<n; ++i)
	{
		if(strcmp(type, type_ar[i]) == 0)
			return true;
	}
	return false;
}

void main()
{
	int ar1[5] = {11,22,33,44,55};
	int ar2[5];
	Copy(ar2, ar1, 5, IsPODType("int"));

	String sa1[3] = {"aa", "bb", "cc"};
	String sa2[3];
	Copy(sa2, sa1, 3, IsPODType("String"));
}


/*
template<class T1, class T2>
class Data
{
public:
	Data() 
	{
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data() 
	{
		cout << "Data<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};


template<>
class Data<int, int>
{
public:
	Data() 
	{
		cout << "Data<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};

template<class T1>
class Data<T1, int>
{
public:
	Data() 
	{
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T1 _d1;
	int _d2;
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() 
	{
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T1 _d1;
	T2 _d2;
};

template<class T>
class Data<T*, T*>
{
public:
	Data() 
	{
		cout << "Data<T1, T2>" << endl; 
	}
private:
	T _d1;
	T _d2;
};


void main()
{
	Data<int*, double*> d1;
	Data<int*, int*> d2;
}

/*
void main()
{
	Data<int, int> d1;
	Data<char, int> d2;
	Data<int, char> d3;
	Data<double, int> d4;
}

/*
class Student
{
public:
	Student(int i, char *n, char *s)
	{
		id = i;
		strcpy(name, n);
		strcpy(sex, s);
	}
public:
	bool operator==(const Student &s)
	{
		if(id==s.id && !strcmp(name, s.name) && !(strcmp(sex,s.sex)))
			return true;
		return false;
	}
private:
	int id;
	char name[10];
	char sex[3];
};

//泛化
template<typename Type>
bool IsEqual(Type &left, Type &right)
{
	return left == right;
}
//特化
template<>
bool IsEqual<char*>( char* &left, char* &right)
{
	if(strcmp(left, right) == 0)
		return true;
	return false;
}

template<>
bool IsEqual<Student>(Student &left, Student &right)
{
	return left == right;
}


void main()
{
	char *s1 = "Hello";
	char *s2 = "Hello";
	//char s1[] = "Hello";
	//char s2[] = "Hello";
	int a = 20;
	int b = 20;
	bool flag = IsEqual(a, b);
	cout<<"flag = "<<flag<<endl;
	flag = IsEqual(s1, s2);
	cout<<"flag = "<<flag<<endl;

	Student stu1(10000, "附近阿里","男");
	Student stu2(10001, "漏发了","女");

	flag = IsEqual(stu1, stu2);
	cout<<"flag = "<<flag<<endl;

	//cout<<strcmp(s1, s2)<<endl;
}

/*
//类型参数
template<typename Type>
Type Max(Type a, Type b)
{
	return a > b ? a : b;
}

//非类型参数
template<typename Type, int N>
class Array
{
public:
	Array()
	{
		memset(ar, 0, sizeof(Type)*N);
	}
private:
	Type ar[N];
};

void main()
{
	//Max<int>(10,20);
	Array<int, 10> a;
	//Array<int> a;
}
*/