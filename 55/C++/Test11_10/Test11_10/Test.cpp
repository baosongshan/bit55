#include<iostream>
//#include<string>
#include<assert.h>
#include<vector>
#include<list>
using namespace std;

// _Fun
// it

void main()
{
	//2 2 2 2 2  1
	vector<int> v(5,2);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; //5

	vector<int>:: iterator it = v.begin();
	cout<<*it<<endl;

	//v.push_back(1);  //
	//it = v.begin();
	//v.insert();

	cout<<*it<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar, ar+10);
	vector<int>::iterator pos;

	pos = find(v.begin(), v.end(), 4);
	pos = v.erase(pos);  //

	cout<<*pos<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int ar1[] = {11,22,33,44,55,66,77,88,99,100};
	vector<int> v(ar, ar+10);
	vector<int> v1(ar1, ar1+10);

	v.swap(v1);

	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0; i<v1.size(); ++i)
		cout<<v1[i]<<" ";
	cout<<endl;
}

/*

void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int ar1[] = {11,22,33,44,55,66,77,88,99,100};
	vector<int> v(ar, ar+10);
	vector<int>::iterator pos;

	pos = find(v.begin(), v.end(), 4);
	//v.insert(pos, 100);
	v.erase(pos);   //erase  remove

	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.reserve(100);

	for(int i=1; i<=100; ++i)
	{
		v.push_back(i);
		cout<<i<<" size = "<<v.size()<<endl;
		cout<<i<<" capacity = "<<v.capacity()<<endl;
	}

}

/*
void main()
{
	vector<int> v(10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.reserve(100);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.reserve(50);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
void main()
{
	vector<int> v(100,1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.resize(10, 2);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	
	vector<int> v(10, 2);
	//vector<int> v1(10, 1);
	//vector<int> v1 = v;
	//vector<int> v1(v.begin(), v.end());
	vector<int> v1(ar, ar+sizeof(ar)/sizeof(int));

	for(int i=0; i<v1.size(); ++i)
		cout<<v1[i]<<" ";
	cout<<endl;

	for(int i=0; i<v1.size(); ++i)
		cout<<v1.at(i)<<" ";
	cout<<endl;

	vector<int>::iterator it = v1.begin();
	while(it != v1.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	for(auto e : v1)
		cout<<e<<" ";
	cout<<endl;

	vector<int>::reverse_iterator rit = v1.rbegin();
	while(rit != v1.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;

}

/*
void main()
{
	vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(2);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(3);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(4);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(5);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(6);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(7);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str) //
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)	: _str(nullptr)
	{
		//_str = new char[strlen(s._str)+1];
		//strcpy(_str, s._str);

		String strTmp(s._str);
		swap(_str, strTmp._str);
	}
	// 对比下和上面的赋值那个实现比较好？
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			String Tmp(s._str); //
			char *tmp = _str;
			_str = Tmp._str;
			Tmp._str = tmp;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void main()
{
	String s; //
}


/*
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1]; 
		strcpy(_str, str);
	}
	String(const String &s) : _str(new char[strlen(s._str)+1])
	{
		//_str = new char[strlen(s._str)+1];
		strcpy(_str, s._str);
	}
	String& operator=(const String &s)
	{
		if(this == &s)
			return *this;
		//异常不安全
		delete []_str;
		_str = new char[strlen(s._str)+1];
		strcpy(_str, s._str);

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

ostream& operator<<(ostream &out, const String &s)
{
	out<<s._str;
	return out;
}

void main()
{
	String s("Hello");
	cout<<s<<endl;
	String s1;
	s1 = s;
}

/*
void main()
{
	string num("123456789");
	cout<<num<<endl;
	reverse(num.begin(), num.end());
	cout<<num<<endl;
}
*/