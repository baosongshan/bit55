#include<iostream>
#include<array>
#include<forward_list>
#include<deque>
#include<list>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	// 因为next_permutation函数是按照大于字典序获取下一个排列组合的
	// 因此在排序时必须保证序列是升序的
	vector<int> v = { 4, 1, 2, 3 };

	sort(v.begin(), v.end(), greater<int>());
	do
	{
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	} while (prev_permutation(v.begin(), v.end()));
}

/*
void Perm(int list[], int k, int m)
{
	if(m == k)
	{
		for(int i=0; i<=m; ++i)
			cout<<list[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=k; i<=m; ++i)
		{
			swap(list[k], list[i]);
			Perm(list, k+1, m);
			swap(list[k], list[i]);
		}
	}
}

void main()
{
	int ar[] = {1,2,3,4,5};
	Perm(ar, 0, 4);
}

/*
void main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	
	v.erase(it, v.end());

	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
	vector<int> v{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;
	//sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
int main()
{
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	reverse(v.begin(), v.end());

	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}

/*
bool IsOdd(int i)
{
	return (i % 2) == 0;
}
int main()
{
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// 将区间中元素分割成奇数和偶数两部分
	auto div = partition(v.begin(), v.end(), IsOdd);
	// 打印[begin, div)的元素
	for (auto it = v.begin(); it != div; ++it)
		cout << *it << " ";
	cout << endl;

	// 打印[div, end)的元素
	for (auto it = div; it != v.end(); ++it)
		cout << " " << *it;
	cout << endl;
	return 0;
}

/*
void main()
{
	vector<int> v{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v.begin(), v.begin()+4, v.end());

	vector<int> v1{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	sort(v1.begin(), v1.begin()+4);
}

/*
void main()
{
	vector<int> v{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };

	auto pos = find(v.begin(), v.end(), 5);

	sort(v.begin(), pos+1);
	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v{ 2, 6, 5, 8 };
	list<int>   L{ 9, 3, 0, 5, 7 };

	sort(v.begin(), v.end());
	L.sort();

	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	for(const auto &e : L)
		cout<<e<<" ";
	cout<<endl;

	vector<int> ret(v.size() + L.size());
	merge(v.begin(), v.end(), L.begin(), L.end(), ret.begin());

	for(const auto &e : ret)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	cout<<max(10,20)<<endl;
	cout<<min(10,20)<<endl;
}

/*
struct greater10
{
	bool operator()(int x)
	{
		return x > 10;
	}
};

void main()
{
	vector<int> v1{ 10, 9,8,6,15,20, 30, 30, 20, 10,40, 50,15, 10, 20 ,10,10};

	auto it = find(v1.begin(), v1.end(), 20);
	if(it == v1.end())
		cout<<"要查询的值不存在"<<endl;
	else
		cout<<*it<<endl;

	auto it1 = find_if(v1.begin(), v1.end(), greater10());
	cout<<*it1<<endl;
}

/*
bool greater20(int x)
{
	return x > 15;
}

struct greater10
{
	bool operator()(int x)
	{
		return x > 10;
	}
};
void main()
{
	vector<int> v1{ 10, 20, 30, 30, 20, 10,40,50,15, 10, 20 ,10,10};
	//cout<<count(v1.begin(), v1.end(), 10)<<endl;

	//cout<<count_if(v1.begin(), v1.end(), greater20)<<endl;
	cout<<count_if(v1.begin(), v1.end(), greater10())<<endl;
}

/*
struct mul2
{
	int operator()(int x, int y)
	{
		return x + 2+y;
	}
};

void main()
{
	vector<int> iv{ 20, 10, 30 };
	int result = accumulate(iv.begin(), iv.end(), 0);
	cout << "result = " << result << endl;

	result = accumulate(iv.begin(), iv.end(), 100, mul2());
	cout << "result = " << result << endl;
}

/*
void main()
{
	vector<int> iv{ 20, 10, 30 };
	int result = accumulate(iv.begin(), iv.end(), 100);
	cout << "result = " << result << endl;

	list<int> mylist{ 10, 50, 80 };
	result = accumulate(mylist.begin(), mylist.end(), 0);
	cout << "result = " << result << endl;
}

/*
void main()
{
	int ar[] = {5,8,9,3,0,7,2,1,4};
	list<int> mylist{5,8,9,3,0,7,2,1,4};
	for(const auto &e : mylist)
		cout<<e<<" ";
	cout<<endl;

	mylist.sort();  // -
	//sort(mylist.begin(), mylist.end());

	for(const auto &e : mylist)
		cout<<e<<" ";
	cout<<endl;

	vector<int> iv{5,8,9,3,0,7,2,1,4};
	sort(iv.begin(), iv.end());
	for(const auto &e : iv)
		cout<<e<<" ";
	cout<<endl;

	sort(ar, ar+9);

}

/*
void main()
{
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_front(3);
	de.push_front(4);

	for(const auto &e : de)
		cout<<e<< " ";
	cout<<endl;

}

/*
void main()
{
	forward_list<int> mylist;
	mylist.push_front(1);
	mylist.push_front(2);
	mylist.push_front(3);

	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<"Over."<<endl;
}

/*
void main()
{
	//int ar[100] = {0};  //数组

	array<int, 10> ar1;//  ={1,2,3,4,5}; //数组容器

	ar1.fill(3);

	for(const auto &e : ar1)
		cout<<e<<" ";
	cout<<endl;

	cout<<ar1[4]<<endl;
}
*/