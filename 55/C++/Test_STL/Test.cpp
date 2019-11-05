#include<iostream>
#include<list>
using namespace std;

void main()
{
	list<int> mylist;
	mylist.push_back(1);
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(int);
	//list<int> mylist;
	//list<int> mylist(10);

	list<int> mylist(ar, ar+n);
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		it++;
	}
	cout<<endl;

	list<int> youlist(mylist.begin(), mylist.end());

}
*/