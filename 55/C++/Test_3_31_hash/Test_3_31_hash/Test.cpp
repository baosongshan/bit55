#include<iostream>
#include<vector>
#include<algorithm>

#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;


void main()
{
	bitset<10> bt;
	cout<<bt<<endl;

	cout<<"size = "<<bt.size()<<endl;

	bt.set(2);
	bt.set(6);
	cout<<bt<<endl;

	cout<<"count = "<<bt.count()<<endl;
	cout<<bt[1]<<endl;
	cout<<bt[6]<<endl;

	bt.reset();
	cout<<bt<<endl;

	bt.flip(3);    //00 0000 1000
	cout<<bt<<endl;

	cout<<bt.to_ulong()<<endl;
}

/*
#define BUCKETS 10033

template<class T>  
size_t BKDRHash(const T *str)  
{  
    size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {         
        hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..   
		//???????  --> 减少冲突
    }  
    return hash;  
} 

template<class T>  
size_t SDBMHash(const T *str)  
{  
    register size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash = 65599 * hash + ch;         
        //hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
    }  
    return hash;  
} 

void main()
{
	char* keywords[] = 
	{
		"asm", "do", "if", "return", "try", "continue",
		"auto", "double", "inline", "short", "typedef", "for",
		"bool", "dynamic_cast", "int", "signed", "typeid", "public",
		"break", "else", "long", "sizeof", "typename", "throw",
		"case", "enum", "mutable", "static", "union", "wchar_t",
		"catch", "explicit", "namespace", "static_cast", "unsigned", "default",
		"char", "export", "new", "struct", "using", "friend",
		"class", "extern", "operator", "switch", "virtual", "register",
		"const", "false", "private", "template", "void", "true",
		"const_cast", "float", "protected", "this", "volatile", "while",
		"delete", "goto", "reinterpret_cast"
	};

	//try  private  互为同义词

	int n = sizeof(keywords) / sizeof(keywords[0]);

	int count[BUCKETS] = {0}; 
	for(int i=0; i<n; ++i)
	{
		size_t index = BKDRHash(keywords[i]) % BUCKETS;
		count[index]++;
	}

	for(int i=0; i<n; ++i)
	{
		size_t index = BKDRHash(keywords[i]) % BUCKETS;
		printf("%-20s : %04d  %d\n", keywords[i], index, count[index]);
	}

}

/*
void main()
{
	char *str1 = "abc";
	char *str2 = "abd";
	char *str3 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	//0x00 00 00 00 ~ 0xFF FF FF FF = 4294967295  = 4G

	size_t index1 = BKDRHash(str1) % BUCKETS;
	cout<<"index1 = "<<index1<<endl;

	size_t index2 = BKDRHash(str2) % BUCKETS;
	cout<<"index2 = "<<index2<<endl;

	size_t index3 = BKDRHash(str3) % BUCKETS;
	cout<<"index3 = "<<index3<<endl;
}


//////////////////////////////////////////////////////////////////////////////////////
/*
static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
  53,         97,           193,         389,       769,
  1543,       3079,         6151,        12289,     24593,
  49157,      98317,        196613,      393241,    786433,
  1572869,    3145739,      6291469,     12582917,  25165843,
  50331653,   100663319,    201326611,   402653189, 805306457, 
  1610612741, 3221225473ul, 4294967291ul
};

inline unsigned long __stl_next_prime(unsigned long n)
{
  const unsigned long* first = __stl_prime_list;
  const unsigned long* last = __stl_prime_list + __stl_num_primes;
  const unsigned long* pos = lower_bound(first, last, n);
  return pos == last ? *(last - 1) : *pos;
}

template <class Value>
struct __hashtable_node
{
	__hashtable_node* next;
	Value val;
};

/////////////////////////////////////////////////////////////
//iterator

template <class Key, class Value, class ExtractKey>
class hashtable;

template<class Key, class Value, class ExtractKey>
class __hashtable_iterator
{
public:
	typedef __hashtable_node<Value> node;
	typedef Value                   value_type;

	typedef hashtable<Key, Value, ExtractKey> hashtable;
	typedef __hashtable_iterator<Key, Value, ExtractKey>  iterator;
public:
	__hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab) 
	{}
	value_type& operator*()
	{
		return cur->val;
	}
	iterator& operator++()
	{
		const node* old = cur;
		cur = cur->next;
		if (!cur) 
		{
			size_t bucket = ht->bkt_num(old->val);
			while (!cur && ++bucket < ht->buckets.size())
				cur = ht->buckets[bucket];
		}
		return *this;
	}
	iterator operator++(int)
	{
		iterator tmp = *this;
		++(*this);
		return tmp;
	}
	bool operator==(const iterator& it) const 
	{
		return cur == it.cur; 
	}
	bool operator!=(const iterator& it) const 
	{
		return cur != it.cur; 
	}
public:
	node *cur;
	hashtable *ht;
};

//set  map
//multi_set   multi_map
template <class Key, class Value, class ExtractKey>
class hashtable 
{
	friend class __hashtable_iterator<Key, Value, ExtractKey>;
public:
	typedef size_t size_type;
	typedef Key    key_type;
	typedef Value  value_type;
	typedef __hashtable_node<Value> node; //Hash节点

	typedef __hashtable_iterator<Key, Value, ExtractKey> iterator;
public:
	hashtable(size_type n) : num_elements(0)
	{
		initialize_buckets(n);
	}
public:
	 size_type size() const 
	 {
		 return num_elements; 
	 }
	 bool empty() const
	 { 
		 return size() == 0; 
	 }
public:
	iterator begin()
	{
		for(size_type n=0; n<buckets.size(); ++n)
		{
			if(buckets[n])
			{
				return iterator(buckets[n], this);
			}
		}
		return end();
	}
	iterator end()
	{
		return iterator(0, this);
	}
public:
	void resize(size_type num_elements_hint)
	{
		const size_type old_n = buckets.size();  //53

		if (num_elements_hint > old_n) 
		{
			const size_type n = next_size(num_elements_hint);
			if (n > old_n) 
			{
				vector<node*> tmp(n, (node*)0);
				
				for (size_type bucket = 0; bucket < old_n; ++bucket)
				{
					node* first = buckets[bucket];
					while (first)
					{
						size_type new_bucket = bkt_num(first->val, n);
						buckets[bucket] = first->next;
						first->next = tmp[new_bucket];
						tmp[new_bucket] = first;
						first = buckets[bucket];
					}
				}
				buckets.swap(tmp);
			}
		}
	}
	bool insert_unique(const value_type& obj)
	{
		resize(num_elements + 1);
		return insert_unique_noresize(obj);
	}
	bool insert_equal(const value_type& obj)
	{
		resize(num_elements + 1);
		return insert_equal_noresize(obj);
	}
	void show_hashtable()
	{
		for(int i=0; i<buckets.size(); ++i)
		{
			cout<<i<<":";
			node *p = buckets[i];
			while(p != 0)
			{
				cout<<p->val<<"->";
				p = p->next;
			}
			cout<<endl;
		}
	}
public:
	node* new_node(const value_type& obj)
	{
		node* n = (node*)malloc(sizeof(node));
		n->next = 0;
		n->val = obj;
		return n;
	}
public:
	size_type bkt_num_key(const key_type& key, size_t n) const
	{
		return key % n;
	}
	size_type bkt_num_key(const key_type& key) const
	{
		return bkt_num_key(key, buckets.size());
	}
	size_type bkt_num(const value_type& obj) const   //int  pair key
	{
		return bkt_num_key(get_key(obj));
	}
	size_type bkt_num(const value_type& obj, size_t n) const
	{
		return bkt_num_key(get_key(obj), n);
	}
	bool insert_unique_noresize(const value_type& obj)
	{
		//计算index
		const size_type n = bkt_num(obj);  //obj % buckets.size();

		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		{
			if (cur->val == obj)
				return false;
		}

		node* tmp = new_node(obj); 
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}

	bool insert_equal_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
		{
			//把相等值插在一起
			if (cur->val == obj)
			{
				node* tmp = new_node(obj);
				tmp->next = cur->next;
				cur->next = tmp;
				++num_elements;
				return true;
			}
		}
		//头插
		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}
private:
	size_type next_size(size_type n) const 
	{
		return __stl_next_prime(n); 
	}
	void initialize_buckets(size_type n)
	{
		const size_type n_buckets = next_size(n);
		buckets.reserve(n_buckets);
		buckets.insert(buckets.end(), n_buckets, (node*)0);
		num_elements = 0;
	}
private:
	vector<node*> buckets;
	size_type num_elements;
	ExtractKey   get_key;     //仿函数
};

template<class Key>
class unordered_myset
{
public:
	struct KeyOfValue
	{
		const Key& operator()(const Key &data)const
		{
			return data;
		}
	};
	typedef typename hashtable<Key, Key, KeyOfValue>::iterator iterator;
public:
	unordered_myset() : _ht(53)
	{}
public:
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	void insert(const Key &v)
	{
		_ht.insert_unique(v);
	}
private:
	hashtable<Key, Key, KeyOfValue> _ht;
};

template<class Key>
class unordered_multimyset
{
public:
	struct KeyOfValue
	{
		const Key& operator()(const Key &data)const
		{
			return data;
		}
	};
	typedef typename hashtable<Key, Key, KeyOfValue>::iterator iterator;
public:
	unordered_multimyset() : _ht(53)
	{}
public:
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	void insert(const Key &v)
	{
		_ht.insert_equal(v);
	}
private:
	hashtable<Key, Key, KeyOfValue> _ht;
};

///////////////////////////////////////////////////////////////
template<class Key, class Value>
class unordered_mymap
{
public:
	struct KeyOfValue
	{
		const Key& operator()(const pair<Key, Value> &data)const
		{
			return data.first;
		}
	};
	typedef typename hashtable<Key, pair<Key, Value>, KeyOfValue>::iterator iterator;

public:
	unordered_mymap() : _ht(53)
	{}
public:
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	void insert(const pair<Key, Value> &v)
	{
		_ht.insert_unique(v);
	}
private:
	hashtable<Key, pair<Key,Value>, KeyOfValue> _ht;
};

template<class Key, class Value>
class unordered_multimymap
{
public:
	struct KeyOfValue
	{
		const Key& operator()(const pair<Key, Value> &data)const
		{
			return data.first;
		}
	};
	typedef typename hashtable<Key, pair<Key, Value>, KeyOfValue>::iterator iterator;

public:
	unordered_multimymap() : _ht(53)
	{}
public:
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	void insert(const pair<Key, Value> &v)
	{
		_ht.insert_equal(v);
	}
private:
	hashtable<Key, pair<Key,Value>, KeyOfValue> _ht;
};

void Test_Set()
{
	int ar[] = {4,6,8,3,13,6,8,6,8,6,4,1,2,9};
	int n = sizeof(ar) / sizeof(int);
	unordered_set<int> unset;
	for(int i=0; i<n; ++i)
		unset.insert(ar[i]);
	for(const auto &e : unset)
		cout<<e<<" ";
	cout<<endl;

	unordered_myset<int> unmyset;
	for(int i=0; i<n; ++i)
		unmyset.insert(ar[i]);
	for(const auto &e : unmyset)
		cout<<e<<" ";
	cout<<endl;

	cout<<"==========================="<<endl;

	unordered_multiset<int> unmultiset;
	for(int i=0; i<n; ++i)
		unmultiset.insert(ar[i]);
	for(const auto &e : unmultiset)
		cout<<e<<" ";
	cout<<endl;

	unordered_multimyset<int> unmultimyset;
	for(int i=0; i<n; ++i)
		unmultimyset.insert(ar[i]);
	for(const auto &e : unmultimyset)
		cout<<e<<" ";
	cout<<endl;
}

void Test_Map()
{
	pair<int, int> v[] = {{3,333}, {2,222}, {5,555}, {1,111}, {4,444},{1,111},{5,555},{5,555}};
	int n = sizeof(v) / sizeof(v[0]);

	unordered_map<int, int> unmap;
	for(int i=0; i<n; ++i)
		unmap.insert(v[i]);
	for(const auto &e : unmap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"=========="<<endl;

	unordered_mymap<int, int> unmymap;
	for(int i=0; i<n; ++i)
		unmymap.insert(v[i]);
	for(const auto &e : unmymap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"=========="<<endl;

	unordered_multimap<int, int> unmultimap;
	for(int i=0; i<n; ++i)
		unmultimap.insert(v[i]);
	for(const auto &e : unmultimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<"=========="<<endl;
	unordered_multimap<int, int> unmultimymap;
	for(int i=0; i<n; ++i)
		unmultimymap.insert(v[i]);
	for(const auto &e : unmultimymap)
		cout<<e.first<<" : "<<e.second<<endl;
}

void main()
{
	Test_Set();
	Test_Map();
}




/*
void main()
{
	int ar[] = {4,6,8,3,13,6,8,6,8,6,4,1,2,9};
	int n = sizeof(ar) / sizeof(int);
	unordered_set<int> unset;
	for(int i=0; i<n; ++i)
		unset.insert(ar[i]);
	for(const auto &e : unset)
		cout<<e<<" ";
	cout<<endl;

	unordered_myset<int> unmyset;
	for(int i=0; i<n; ++i)
		unmyset.insert(ar[i]);
	for(const auto &e : unmyset)
		cout<<e<<" ";
	cout<<endl;

	cout<<"==========================="<<endl;

	unordered_multiset<int> unmultiset;
	for(int i=0; i<n; ++i)
		unmultiset.insert(ar[i]);
	for(const auto &e : unmultiset)
		cout<<e<<" ";
	cout<<endl;

	unordered_multimyset<int> unmultimyset;
	for(int i=0; i<n; ++i)
		unmultimyset.insert(ar[i]);
	for(const auto &e : unmultimyset)
		cout<<e<<" ";
	cout<<endl;
}

/*
int main()
{
	int ar[] = {4,6,8,3,13,6,8,6,8,6,4,1,2,9};
	int n = sizeof(ar) / sizeof(int);
	hashtable<int,int> ht(53);  //Test
	for(int i=0; i<n; ++i)
	{
		ht.insert_unique(ar[i]);
		//ht.insert_equal_noresize(ar[i]);
	}
	
	ht.insert_unique(53);
	//ht.show_hashtable();
	auto it = ht.begin();
	while(it != ht.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;

	return 0;
}
*/
