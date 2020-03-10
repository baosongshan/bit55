#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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

/*
////////////////////////////////////////
template <class Value, class Key>
struct __hashtable_iterator 
{
	node* cur;
	hashtable* ht;

	__hashtable_iterator(node* n, hashtable* tab) 
		: cur(n), ht(tab) 
	{}
	__hashtable_iterator() 
	{}
	reference operator*() const 
	{ 
		return cur->val; 
	}
	pointer operator->() const
	{ 
		return &(operator*());
	}
	iterator& operator++()
	{
		const node* old = cur;
		cur = cur->next;
		if (!cur) 
		{
			size_type bucket = ht->bkt_num(old->val);
			while (!cur && ++bucket < ht->buckets.size())
				cur = ht->buckets[bucket];
		}
		return *this;
	}
	iterator operator++(int);
	bool operator==(const iterator& it) const
	{ 
		return cur == it.cur; 
	}
	bool operator!=(const iterator& it) const 
	{ 
		return cur != it.cur; 
	}
};
*/
//set  map
template <class Key, class Value>
class hashtable 
{
public:
	typedef size_t size_type;
	typedef Key    key_type;
	typedef Value  value_type;
	typedef __hashtable_node<Value> node; //Hash节点
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
	//iterator begin();
	//iterator end();
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
	size_type bkt_num(const value_type& obj) const
	{
		return bkt_num_key(obj);
	}
	size_type bkt_num(const value_type& obj, size_t n) const
	{
		return bkt_num_key(obj, n);
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
};

int main()
{
	int ar[] = {4,6,8,3,13,6,8,6,8,6,4,1,2,9};
	int n = sizeof(ar) / sizeof(int);
	hashtable<int,int> ht(53);  //Test
	for(int i=0; i<n; ++i)
	{
		//ht.insert_unique(ar[i]);
		ht.insert_equal_noresize(ar[i]);
	}
	ht.insert_equal_noresize(59);
	ht.insert_equal_noresize(6);
	ht.show_hashtable();

	//unordered_set;  //insert_unique_noresize();
	//unordered_multiset;//insert_equal_noresize();

	return 0;
}

/////////////////////////////////////////////////////////////////////////
/*
static const int num_primes = 32;
static const unsigned long prime_list[num_primes] =
{
  3, 7, 13, 19,
  53,         97,           193,         389,       769,
  1543,       3079,         6151,        12289,     24593,
  49157,      98317,        196613,      393241,    786433,
  1572869,    3145739,      6291469,     12582917,  25165843,
  50331653,   100663319,    201326611,   402653189, 805306457, 
  1610612741, 3221225473ul, 4294967291ul
};

unsigned long GetNextPrime(size_t num)
{
	for(int i=0; i<num_primes; ++i)
	{
		if(prime_list[i] > num)
			return prime_list[i];
	}
	return prime_list[num_primes-1];
}

//////////////////////////////////////////////////////////
enum State{EMPTY, EXIST, DELETE};
template<class K, class V>  //Key-Value
class HashTable
{
public:
	struct Elem
	{
		pair<K, V> _val;
		State      _state;
	};
public:
	HashTable(size_t capacity = 3) : _ht(capacity), _size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
public:
	bool Insert(const pair<K, V>& val)
	{
		// 检测哈希表底层空间是否充足
		_CheckCapacity();

		K key = val.first;

		size_t hashAddr = HashFunc(key);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if(_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return false;
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// 转一圈也没有找到，注意：动态哈希表，该种情况可以不用考虑，哈希表中元素个数
			到达一定的数量，哈希冲突概率会增大，需要扩容来降低哈希冲突，因此哈希表中元素是不会存满的
			if(hashAddr == startAddr)
			return false;
			
		}
		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const K& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return hashAddr;
			hashAddr++;
		}
		return hashAddr;
	}
	bool Erase(const K& key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
public:
	void Swap(HashTable<K, V> &ht)
	{
		std::swap(_ht, ht._ht);
		std::swap(_size, ht._size);
	}
protected:
	size_t HashFunc(const K &key)
	{
		return key % (_ht.capacity());
	}
	void _CheckCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)  //0.7
		{
			HashTable<K, V> newHt(GetNextPrime(_ht.capacity()));
			for (size_t i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHt.Insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}
private:
	vector<Elem> _ht;
	size_t       _size;  //1
};

void main()
{
	int ar[] = {4,6,8,3,13,1,2,9};
	int n = sizeof(ar) / sizeof(int);
	HashTable<int,string>  ht;
	for(int i=0; i<n; ++i)
	{
		ht.Insert(pair<int,string>(ar[i],"aaaa"));
	}
}
*/