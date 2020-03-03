#include<iostream>
#include<string>
#include<set>
#include<functional>
using namespace std;

void main()
{
	multiset<int> multise = {1,7,5,6,7,7,9,4,1,5,5,5,5,5,5,3,4,0,2};   //自动排序 //不能修改键值

	int num = multise.count(5);
	cout<<"num = "<<num<<endl;

	int num1 = multise.erase(5);
	cout<<"num1 = "<<num1<<endl;

	auto rit = multise.rbegin();
	while(rit != multise.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	set<int> se = {1,7,5,6,9,3,4,0,2};   //自动排序 //不能修改键值

	//auto pos = find(se.begin(), se.end(), 5);
	//se.erase(pos);

	//se.erase(5);

	int num = se.count(5);

	auto rit = se.rbegin();
	while(rit != se.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}
/*
void main()
{
	set<int, greater<int>> se = {1,7,5,6,9,3,4,0,2};   //自动排序 //不能修改键值

	int ar[] = {1,7,5,6,9,3,4,0,2};
	int n = sizeof(ar) / sizeof(int);
	set<int> se1(ar, ar+n);
	
	auto p = se.begin();
	//*p = 100;

	//se.insert(100);
	//se.erase(p);

	for(const auto &e : se)
		cout<<e<<" ";
	cout<<endl;
}


/*
void main()
{
	set<int> se = {1,7,5,6,9,3,4,0,2};   //自动排序
	//cout<<"empty = "<<se.empty()<<endl;
	//cout<<"size = "<<se.size()<<endl;

	auto it = se.begin();
	while(it != se.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	pair<string, string> pa("1-1", "元旦节");  //值对
	cout<<pa.first<<" : "<<pa.second<<endl;

}
*/