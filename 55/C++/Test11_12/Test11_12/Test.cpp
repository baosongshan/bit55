#include<iostream>
//#include<string>
#include<assert.h>
#include<vector>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str = "") //nullptr
		{
			m_size = strlen(str);
			m_capacity = m_size; //
			m_str = new char[m_capacity+1]; //
			strcpy(m_str, str);
		}
		string(const string &s):m_str(nullptr),m_capacity(0),m_size(0)
		{
			string tmp(s.m_str);
			Swap(tmp); //*this  tmp
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				string tmp(s);
				Swap(tmp);
			}
			return *this;
		}
		~string()
		{
			if(m_str)
			{
				delete []m_str;
				m_str = nullptr;
				m_capacity = m_size = 0;
			}
		}
	public:
		typedef char* iterator; //µü´úÆ÷
		typedef const char* const_iterator; //
	public:
		iterator begin()
		{return m_str;}
		iterator end()
		{return m_str+m_size;}
		const_iterator begin()const
		{return m_str;}
		const_iterator end()const
		{return m_str+m_size;}
	public:
		size_t size()const
		{return m_size;};
		size_t capacity()const
		{return m_capacity;}
	public:
		void push_back(char ch)
		{
			if(m_size >= m_capacity)
			{
				int new_capacity = (m_capacity==0?1:m_capacity*2);
				reserve(new_capacity);
			}
			m_str[m_size++] = ch;
			m_str[m_size] = '\0';
		}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
		const char* c_str()const
		{
			return m_str;
		}
	public:
		char operator[](size_t i) //-1
		{
			assert(i<m_size); //15 14
			return m_str[i];
		}
		const char operator[](size_t i)const //-1
		{
			assert(i<m_size); //15 14
			return m_str[i];
		}
	public:
		//abcdefghij00000
		void resize(size_t new_sz, char c='\0')
		{
			if(new_sz > m_size)
			{
				if(new_sz > m_capacity)
				{
					reserve(new_sz); //	
				}
				memset(m_str+m_size, c, new_sz-m_size);
			}
			m_str[new_sz] = '\0';
			m_size = new_sz;
		}
		void reserve(size_t new_capacity)
		{
			if(new_capacity > m_capacity)
			{
				char *new_str = new char[new_capacity+1];
				m_capacity = new_capacity;
				strcpy(new_str, m_str);
				delete []m_str;
				m_str = new_str;
			}
		}
		void Swap(string &s)
		{
			swap(m_str, s.m_str);
			swap(m_capacity, s.m_capacity);
			swap(m_size, s.m_size);
		}
	private:
		char *m_str;
		size_t m_capacity;
		size_t m_size;
	};
	/////////////////////////////////////////////////////
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin()
		{return start;}
		iterator end()
		{return finish;}
	public:
		vector():start(nullptr),finish(nullptr),end_of_storage(nullptr)
		{}
		~vector()
		{
			delete []start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage - start;
		}
	public:
		T& operator[](size_t i)
		{
			assert(i < size());
			return start[i];
		}
		void push_back(const T &value)
		{
			insert(end(), value);
		}
	public:
		iterator insert(iterator pos, const T &x)
		{
			if(size() == capacity())
			{
				int new_capacity = capacity()==0 ? 1 : capacity()*2;
				reserve(new_capacity);
			}

			iterator p = finish;
			if(pos == nullptr)
				*finish = x;
			else
			{
				while(p != pos)
				{
					*p = *(p-1);
					p--;
				}
				*pos = x;
			}
			finish++;
			return pos;
		}
	public:
		void resize(size_t n, const T &value = T())
		{
			if(n < size())
			{
				finish = start+n;
				return;
			}
			if(n > capacity())
			{
				reserve(n);
			}
			
			iterator p = finish;
			finish = finish+n-size();
			while(p != finish)
			{
				*p = value;
				p++;
			}

			//int len = n - size();
			//for(int i=0; i<len; ++i)
			//{
			//	*finish++ = value; 
			//}
		}
		void reserve(size_t n)
		{
			if(n > capacity())
			{
				T *tmp = new T[n];
				int old_size = size();
				for(int i=0; i<old_size; ++i)
				{
					tmp[i] = start[i];
				}
				delete []start;
				start = tmp;
				finish = start + old_size;
				end_of_storage = start + n;
			}
		}
	public:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
};

void main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; 
	v.push_back(1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; 

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

/*
void main()
{
	bit::vector<int> v;
	v.reserve(10);

	v.insert(v.begin(), 5);
	v.insert(v.begin(), 4);
	v.insert(v.begin(), 3);
	v.push_back(2);
	v.push_back(1);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

/*
void main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; 

	v.reserve(10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; 

	v.resize(15, 1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl; 

	for(int i=0; i<v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

}

/*
ostream& bit::operator<<(ostream &out, const string &s)
{
	out<<s.m_str;
	return out;
}

void main()
{
	bit::string s("Hello Bit.");
	bit::string s1;
	s1 = s;

	for(int i=0; i<s1.size(); ++i)
		cout<<s1[i];
	cout<<endl;
}

/*
void main()
{
	bit::string s("Hello Bit.");
	char *str = (char*)s.c_str();
	*str = 'h';
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s;
	s.push_back('a');
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;  //1 a\0
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Hello Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	//bit::string::iterator it = s.begin(); //
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Hello Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	//bit::string::iterator it = s.begin(); //
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	s.reserve(20);
	cout<<"s = "<<s<<endl;  //Bit.
	cout<<"size = "<<s.size()<<endl; //4
	cout<<"capacity = "<<s.capacity()<<endl; //20

	s.resize(30,'a');
	cout<<"s = "<<s<<endl;  //Bit.
	cout<<"size = "<<s.size()<<endl; //4
	cout<<"capacity = "<<s.capacity()<<endl; //30

	s.resize(2,'a');
	cout<<"s = "<<s<<endl;  //Bi
	cout<<"size = "<<s.size()<<endl; //2
	cout<<"capacity = "<<s.capacity()<<endl; //30
}
*/