#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<functional>

#include<unordered_map>
#include<unordered_set>
#include<hash_set>
#include<hash_map>
using namespace std;

void main()
{
	pair<string, string> val[] = 
	{
		{"111", "abc"}, 
		{"555","xyz"},
		{"222", "opq"},
		{"222", "opq"},
		{"333", "opq"},
		{"444", "opq"},
		{"888", "opq"}
	};

	hash_map<string,string> hmap;
	hash_multimap<string,string> hmulmap;
	for(int i=0; i<7; ++i)
	{
		hmap.insert(val[i]);
		hmulmap.insert(val[i]);
	}

	//map["444"] = "fgh";

	for(const auto &e : hmap)
		cout<<e.first<<" : "<<e.second<<endl;

	cout<<"===================="<<endl;
	for(const auto &e : hmulmap)
		cout<<e.first<<" : "<<e.second<<endl;
}


/*
void main()
{
	vector<int> v = {4,5,7,6,4,2,2,3,5,6,4,32,2};
	hash_set<int> hset;
	hash_multiset<int> hmulset;
	for(const auto &e : v)
	{
		hset.insert(e);
		hmulset.insert(e);
	}

	for(const auto &e : hset)
		cout<<e<<" ";
	cout<<endl<<"=================="<<endl;
	for(const auto &e : hmulset)
		cout<<e<<" ";
	cout<<endl;
}

/*
typedef unordered_map<string, string> ssUnMap;   //hashTable
typedef unordered_multimap<string, string> ssMulUnMap;

typedef unordered_set<int> intUnSet;
typedef unordered_multiset<int> intMulUnSet;
 
void main()
{
	vector<int> v = {4,5,7,6,4,2,2,3,5,6,4,32,2};
	intUnSet set;
	intMulUnSet mulset;
	for(const auto &e : v)
	{
		set.insert(e);
		mulset.insert(e);
	}

	for(const auto &e : set)
		cout<<e<<" ";
	cout<<endl<<"=================="<<endl;
	for(const auto &e : mulset)
		cout<<e<<" ";
	cout<<endl;

}

/*
//size_t bucket_count()const        返回哈希桶中桶的总个数
//size_t bucket_size(size_t n)const 返回n号桶中有效元素的总个数
//size_t bucket(const K& key)

/*
void main()
{
	ssUnMap map;
	map["111"] = "aaa";
	map["222"] = "bbb";
	map["444"] = "ccc";
	map["555"] = "ddd";
	map["333"] = "xxx";
	map["666"] = "ccc";
	map["777"] = "ddd";
	map["888"] = "xxx";
	map["999"] = "ddd";

	cout<<map.bucket("888")<<endl;

	cout<<map.bucket_count()<<endl;
	for(int i=0; i<map.bucket_count(); ++i)
	{
		cout<<i<<" : "<<map.bucket_size(i)<<endl;
	}


}

/*
void main()
{
	pair<string, string> val[] = 
	{
		{"111", "abc"}, 
		{"555","xyz"},
		{"222", "opq"},
		{"222", "opq"},
		{"222", "opq"}
	};

	ssUnMap map;
	ssMulUnMap multimap;
	for(int i=0; i<5; ++i)
	{
		map.insert(val[i]);
		multimap.insert(val[i]);
	}

	map["444"] = "fgh";

	for(const auto &e : map)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"size = "<<map.size()<<endl;
	cout<<"===================="<<endl;
	for(const auto &e : multimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"size = "<<multimap.size()<<endl;
}

/*
void main()
{
	pair<string, string> val[] = 
	{
		{"111", "abc"}, 
		{"555","xyz"},
		{"222", "opq"},
		{"222", "opq"},
		{"222", "opq"}
	};

	ssUnMap map;
	ssMulUnMap multimap;
	for(int i=0; i<5; ++i)
	{
		map.insert(val[i]);
		multimap.insert(val[i]);
	}

	unordered_map<string, string>::const_iterator it = map.cbegin();
	while(it != map.end())
	{
		//it->second = "fnaflajfl";
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}
	cout<<"size = "<<map.size()<<endl;
	cout<<"===================="<<endl;
	for(const auto &e : multimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"size = "<<multimap.size()<<endl;
}

/*
void main()
{
	pair<string, string> val[] = 
	{
		{"111", "abc"}, 
		{"555","xyz"},
		{"222", "opq"},
		{"222", "opq"},
		{"222", "opq"}
	};

	ssUnMap map;
	ssMulUnMap multimap;
	for(int i=0; i<5; ++i)
	{
		map.insert(val[i]);
		multimap.insert(val[i]);
	}

	for(const auto &e : map)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"size = "<<map.size()<<endl;
	cout<<"===================="<<endl;
	for(const auto &e : multimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"size = "<<multimap.size()<<endl;
}

/*
//1 苹果 
//2 桃子
//3 菠萝
//4 西瓜
//5 榴莲

void GetFavoriteFruit(const vector<int> &fruits, size_t k)
{
	set<int> set;
	multiset<int> mulset;
	for(const auto &e : fruits)
	{
		set.insert(e);  //用于统计水果的种类  1 2 3 4 5
		mulset.insert(e);//统计次数
	}
	for(const auto &e : mulset)
		cout<<e<<" ";
	cout<<endl;

	map<int, int ,greater<int>> mp;  

	for(const auto &e : set)
		mp[mulset.count(e)] = e; 

	auto it = mp.begin();
	for(int i=0; i<k; ++i)
	{
		cout<<it->second<<" : "<<it->first<<endl;
		++it;
	}
}
void main()
{
	const vector<int> fruits = {4,3,2,4,5,1,1,3,4,5,2,3,4,1,2,3,4,5,3,2,1,3,3,4};
	int k = 2;
	GetFavoriteFruit(fruits, k);
}

/*
void GetFavoriteFruit(const vector<int> &fruits, size_t k)
{
	set<int> set;
	multiset<int> mulset;
	for(const auto &e : fruits)
	{
		set.insert(e);  //用于统计水果的种类  1 2 3 4 5
		mulset.insert(e);//统计次数
	}
	for(const auto &e : mulset)
		cout<<e<<" ";
	cout<<endl;

	map<int, int> mp;  
	map<int, int, greater<int>> mp1;// -> 升序

	for(const auto &e : set)
		//mp[e] = mulset.count(e);   //1 -> count  map
		mp[mulset.count(e)] = e; 

	for(const auto &e : mp)
		mp1[e.second] = e.first;

	auto it = mp1.begin();
	for(int i=0; i<k; ++i)
	{
		cout<<it->second<<" : "<<it->first<<endl;
		++it;
	}
}
void main()
{
	const vector<int> fruits = {4,3,2,4,5,1,1,3,4,5,2,3,4,1,2,3,4,5,3,2,1,3,3,4};
	int k = 2;
	GetFavoriteFruit(fruits, k);
}

/*
typedef map<string, string> ssMap;
typedef map<int, string>    ismap;

//csdn  123456789  sqsf1wl*Lahmy1c

void main()
{
	ssMap sm;
	sm.insert(pair<string,string>("1", "bss"));

}

/*
void main()
{
	map<int, string> intstrMap;	

	//1 pair
	pair<int,string> p1(5, "asd");  //key <-> value
	pair<int,string> p2(3, "opq");
	pair<int,string> p3(9, "bmn");
	intstrMap.insert(p1);
	intstrMap.insert(p2);
	intstrMap.insert(p3);
	intstrMap.insert(p3);
	intstrMap.insert(p3);
	intstrMap.insert(p3);

	for(const auto &e : intstrMap)
		cout<<e.first<<" : "<<e.second<<endl;
}


/*
void main()
{
	map<int, string> intstrMap;	

	//1 pair
	intstrMap[5] = "abc";
	intstrMap[2] = "xyz";
	intstrMap[4] = "mkl";

	cout<<"count = "<<intstrMap.count(5)<<endl;

	cout<<intstrMap[7]<<endl;  //不做检查    //pair(7,\0)
	//cout<<intstrMap.at(7)<<endl;  //对边界做检查

	cout<<"count = "<<intstrMap.count(5)<<endl;

	for(const auto &e : intstrMap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	map<int, string> intstrMap;	

	//1 pair
	pair<int,string> p1(5, "asd");  //key <-> value
	pair<int,string> p2(3, "opq");
	pair<int,string> p3(9, "bmn");
	intstrMap.insert(p1);
	intstrMap.insert(p2);
	intstrMap.insert(p3);

	//intstrMap[3] = "xyz";

	auto it = intstrMap.begin();
	//it->first = 10;
	intstrMap.erase(it);

	for(const auto &e : intstrMap)
		cout<<e.first<<" : "<<e.second<<endl;

}

/*
void main()
{
	vector<int> v = {5,7,9,3,6,2,7,7,7,9,1,0,4};
	set<int> myset;

	for(const auto &e : v)
		myset.insert(e);

	for(const auto &e : myset)
		cout<<e<<" ";
	cout<<endl;

	multiset<int> multimyset;
	for(const auto &e : v)
		multimyset.insert(e);

	for(const auto &e : multimyset)
		cout<<e<<" ";
	cout<<endl;


}
*/