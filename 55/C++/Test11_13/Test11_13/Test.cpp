#include<iostream>
#include<functional>
#include<queue>
#include<list>
using namespace std;

void main()
{
	int ar[] = {3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar+n);
	
	mylist.sort();

	for(auto e : mylist)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	int ar[] = {3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
	int n = sizeof(ar) / sizeof(int);
	//priority_queue<int> q;
	//priority_queue<int> q(ar, ar+n); //´ó¶Ñ
	priority_queue<int,vector<int>, greater<int> > q(ar, ar+n);
	
	cout<<"size = "<<q.size()<<endl;
	cout<<"top = "<<q.top()<<endl;
	q.pop();
	cout<<"top = "<<q.top()<<endl;

}

/*
class Date
{
public:
	Date(int year, int month, int day)
		: m_year(year), m_month(month), m_day(day)
	{}
	~Date()
	{}
public:
	bool operator<(const Date &d)const
	{
		if(m_year < d.m_year)
			return true;
		else if(m_year > d.m_year)
			return false;

		if(m_month < d.m_month)
			return true;
		else if(m_month > d.m_month)
			return false;

		if(m_day < d.m_day)
			return true;
		else if(m_day > d.m_day)
			return false;
		return false;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

void main()
{
	priority_queue<Date> q;
	q.push(Date(2015,11,13));
	q.push(Date(2019,3,5));
}


/*
template<class _Ty = void>
struct Plus
{
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	
		return (_Left + _Right);
	}
};

void main()
{
	plus<int> pl;
	cout<<pl(1,2)<<endl;
	cout<<pl.operator()(1,2)<<endl;
}

/*
void main()
{
	int ar[] = {3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
	int n = sizeof(ar) / sizeof(int);
	//priority_queue<int> q;
	//priority_queue<int> q(ar, ar+n); //´ó¶Ñ
	priority_queue<int,vector<int>, greater<int> > q(ar, ar+n);
	
	cout<<"size = "<<q.size()<<endl;
	cout<<"top = "<<q.top()<<endl;
	q.pop();
	cout<<"top = "<<q.top()<<endl;

}


/*
void main()
{
	queue<int, vector<int> >q;
	q.push(1);
	//q.pop();

}

/*
void main()
{
	//stack<int> st; //deque
	//stack<int, vector<int> > st; // 
	stack<int, list<int> >st;
	for(int i=1; i<=5; ++i)
		st.push(i);
	cout<<"size = "<<st.size()<<endl;

	int value;
	while(!st.empty())
	{
		value = st.top();
		st.pop();
		cout<<value<<" ";
	}
	cout<<endl;
}

/*
void main()
{
	queue<int> q;
	for(int i=1; i<=10; ++i)
		q.push(i);
	cout<<"size = "<<q.size()<<endl;
	cout<<"front = "<<q.front()<<endl;
	cout<<"back = "<<q.back()<<endl;

	int value;
	while(!q.empty())
	{
		value = q.front();
		q.pop();
		cout<<value<<" ";
	}
	cout<<endl;
}

/*
//stack<int> st;
template<class _Ty, class _Container = deque<_Ty> >
class stack
{
public:
	stack()	: c()
	{}
	void push(value_type&& _Val)
	{	
		c.push_back(val);
	}

	bool empty() const
	{	// test if stack is empty
		return (c.empty());
	}

	size_type size() const
	{	// test length of stack
		return (c.size());
	}

	reference top()
	{	// return last element of mutable stack
		return (c.back());
	}

	const_reference top() const
	{	// return last element of nonmutable stack
		return (c.back());
	}

	void pop()
	{	// erase last element
		c.pop_back();
	}
protected:
	_Container c;	// the underlying container
};


void main()
{
	stack<int> st;
	for(int i=1; i<=5; ++i)
		st.push(i);
	cout<<"size = "<<st.size()<<endl;

	int value;
	while(!st.empty())
	{
		value = st.top();
		st.pop();
		cout<<value<<" ";
	}
	cout<<endl;
}


/*
void main()
{
	//5 4 1 2 3
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_back(3);
	de.push_front(4);
	de.push_front(5);  //4

	deque<int>::iterator pos = de.begin();
	pos++;
	de.insert(pos, 10);

	pos = find(de.begin(), de.end(), 1);
	de.erase(pos);

	deque<int>::iterator it = de.begin();
	while(it != de.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}
/*
void main()
{
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_back(3);
	de.push_front(4);
	de.push_front(5);  //4

	//cout<<de[4]<<endl;

	//de.pop_front();
	//de.pop_back();
	//de.resize(3);
	//cout<<"size = "<<de.size()<<endl;

	deque<int>::iterator it = de.begin();
	while(it != de.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	//cout<<de.front()<<endl;
	//cout<<de.back()<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	deque<int> de2(ar, ar+sizeof(ar)/sizeof(int));
	deque<int>::const_iterator it = de2.cbegin();

	while(it != de2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	deque<int> de2(ar, ar+sizeof(ar)/sizeof(int));
	deque<int>::iterator it = de2.begin();

	*it = 100;
	while(it != de2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	deque<int> de2(ar, ar+sizeof(ar)/sizeof(int));

	deque<int>::iterator it = de2.begin();
	while(it != de2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	deque<int>::reverse_iterator rit = de2.rbegin();
	while(rit != de2.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	//string s;
	//vector<int> v;
	//list<int>;
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	deque<int> de;
	deque<int> de1(10, 2);
	deque<int> de2(ar, ar+sizeof(ar)/sizeof(int));
	deque<int> de3 = de2;  //deque<int> de3(de2);

	deque<int>::iterator it = de2.begin();
	while(it != de2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	//string s;
	//vector<int> v;
	//list<int>;
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	deque<int> de;
	deque<int> de1(10, 2);
	deque<int> de2(ar, ar+sizeof(ar)/sizeof(int));

	deque<int>::iterator it = de1.begin();
	while(it != de1.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	for(auto e : de1)
		cout<<e<<" ";
	cout<<endl;

	for(int i=0; i<de1.size(); ++i)
		cout<<de1[i]<<" ";
	cout<<endl;

}
*/
