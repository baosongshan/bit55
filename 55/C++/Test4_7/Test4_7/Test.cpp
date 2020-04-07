#include<iostream>
#include<vector>
#include<set>
#include<array>
#include<list>  //双向循环链表
#include<forward_list> //单向不循环链表
#include<functional>
using namespace std;

void main()
{
	forward_list<int> mylist2;
}

/*
//Lambda表达式  匿名函数
//[] 捕获快  [] [=] [&] [this]  [a, &b]
//() 参数列表
//->type 返回值
//{}表达式体
auto fun = [](int a, int b)->int{cout<<"Hello Lambda."<<endl; return a+b;};  //[]()->void{};

int fun1(int a, int b)
{
	cout<<"Hello Lambda."<<endl;
	return a + b;
}

auto fun2 = []{};

void  main()
{
	fun2();
}

/*
void main()
{
	int res = fun(10,20);
	cout<<"res = "<<res<<endl;
}

/*
void main()
{
	fun();
	cout<<typeid(fun).name()<<endl;
	fun1();
	cout<<typeid(fun1).name()<<endl;
}

/*
struct Student
{
	char name[10];
	int  weight;
};

struct StuComp
{
	bool operator()(const Student &s1, const Student &s2)
	{
		return s1.weight < s2.weight;
		//return strcmp(s1.name, s2.name) >= 0;
	}
};

void main()
{
	Student stu[] = {{"附近阿里", 45}, {"解封了", 40},{"即可",60},{"就发",55}};
	int n = sizeof(stu) / sizeof(stu[0]);
	//sort(stu, stu+4, StuComp());
	sort(stu, stu+4, [](const Student &s1, const Student &s2)->bool{return s1.weight < s2.weight;});
}

/*
void main()
{
	int array[] = {4,1,8,5,3,7,0,9,2,6};
	int n = sizeof(array) / sizeof(array[0]);
	sort(array, array+n, less<int>());
	//sort(array, array+n, greater<int>());
	for(int i=0; i<n; ++i)
	{
		cout<<array[i]<< " ";
	}
	cout<<endl;
}

/*
//Lambda表达式
auto fun = []{cout<<"Hello Lambda."<<endl;};  //[]()->void{};
void main()
{
	fun();
}

/*
class Test
{
public:
	Test() = delete;
	Test(int data) : m_data(data)
	{}
	Test(const Test &) = delete;
private:
	int m_data;
};

void main()
{
	//Test t0;
	Test t(0);
	//Test t1 = t;
}

/*
void main()
{
	list<int> mylist1;
	mylist1.push_back(1);
	mylist1.push_front(2);

	auto it = mylist1.begin();
	it++;
	--it;

	forward_list<int> mylist2;
	mylist2.push_front(1);
	mylist2.push_front(2);
	mylist2.push_front(3);
	mylist2.push_front(4);
	mylist2.push_front(5);
	mylist2.push_front(6);

	//6 5 4 3 2 1
	auto pos = find(mylist2.begin(), mylist2.end(), 1);
	mylist2.insert_after(pos, 8);

	forward_list<int>::iterator it1 = mylist2.begin();
	//--it1;
	while(it1 != mylist2.end())
	{
		cout<<*it1<<"-->";
		++it1;
	}
	cout<<"Over"<<endl;
}


/*
void main()
{
	//原生态的数组类型
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	//ar[0];
	//*(ar+offset)
	int n = sizeof(ar) / sizeof(ar[0]);

	array<int, 10> br = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i<11; ++i)
		cout<<br[i]<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	//being() end()  ++it;

	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
void* GetMemory(size_t size)
{
	cout<<"aaaaaaaaaaaa"<<endl;
	return malloc(size);
}

int main()
{
	// 如果没有带参数，推导函数的类型
	cout << typeid(decltype(GetMemory)).name() << endl;

	// 如果带参数列表，推导的是函数返回值的类型,注意：此处只是推演，不会执行函数
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}

/*
void fun(auto x=0)
{}

void main()
{
	auto a = 10;
	cout<<typeid(a).name()<<endl;
}

/*
void main()
{
	short a = 32670;
	short b = 32670;

	auto x = a + b; // int
	cout<<typeid(x).name()<<endl;

	decltype(x) y;
	cout<<typeid(y).name()<<endl;
}

/*
void main()
{
	set<int> s={3,6,9,3,2,1,5,8};
	//set<int>::iterator it = s.begin();
	//set<int>::reverse_iterator it = s.rbegin();
	auto it = s.rbegin();
	while(it != s.rend())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	short a = 32670;
	short b = 32670;

	short c = a + b;
	cout<<c<<endl;
	cout<<typeid(c).name()<<endl;

	auto x = a + b;
	cout<<x<<endl;
	cout<<typeid(x).name()<<endl;

}

/*
template<class Type>
class SeqList
{
public:
	SeqList(size_t sz) : capacity(sz),size(0)
	{
		base = new Type[capacity];
	}
	SeqList(initializer_list<Type> list) : capacity(list.size()),size(0)
	{
		base = new Type[capacity];
		for(const auto &e : list)
			base[size++] = e;
	}
	~SeqList()
	{
		if(base != nullptr)
			delete []base;
		base = nullptr;
		capacity = size = 0;
	}
private:
	Type *base;
	size_t capacity;
	size_t size;
};

void main()
{
	SeqList<int> sq{1,2,3,4,5,6,7,8,9,10};
}

/*
class Point
{
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

int main()
{
	Point p{1,2};
	Point p1(2,3);
	return 0;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7};
	vector<int> v {1,2,3,4,5,6,7};

	int a =  10;
	int a1{20};

	int *pa = new int[5]{1,2,3,4,5};
}
*/