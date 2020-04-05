#include<iostream>
#include<bitset>  //位图
#include<vector>
#include<string>
using namespace std;

template<size_t _N>
class BitSet
{
public:
	BitSet():_bit(_N/32+1),_bitCount(_N)
	{}
public:
	void Set(size_t pos)
	{
		if(pos >= _bitCount)
			return;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		_bit[index] |= (1<<offset);
	}
	bool Test(size_t pos)
	{
		if(pos >= _bitCount)
			return false;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		return _bit[index] & (1<<offset);
	}
	//编程之美
	size_t Count()const
	{
		//v=0 0
		//v=1 0000 0001  1
		//v=2 0000 0010  1
		//v=3 0000 0011  2
		//char 0000 0000  0 ~ 255 0~ 255  1111 1111
		int bitCnttable[256] = 
		{
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 
		};
		size_t size = _bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			int value = _bit[i];
			int j = 0;
			while (j < sizeof(_bit[0]))
			{
				unsigned char c = value;
				count += bitCnttable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}
	size_t size()const
	{
		return _bitCount;
	}
private:
	vector<int> _bit; //
	size_t      _bitCount;//
};

///////////////////////////////////////////////////////////////////////
struct StrToInt1
{
	size_t BKDRHash(const char *str)  
	{  
		register size_t hash = 0;  
		while (size_t ch = (size_t)*str++)  
		{         
			hash = hash * 131 + ch;     
		}  
		return hash;  
	} 
	size_t operator()(const string &s)
	{
		return BKDRHash(s.c_str());
	}
};

struct StrToInt2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}
	size_t operator()(const string &s)
	{
		return SDBMHash(s.c_str());
	}
};
 
struct StrToInt3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
	size_t operator()(const string &s)
	{
		return RSHash(s.c_str());
	}
};
 


//误判率 多大
#define _N 1000

template<class K, class HashFunc1=StrToInt1, 
				  class HashFunc2=StrToInt2,
				  class HashFunc3=StrToInt3>
class BloomFilter
{
public:
	BloomFilter():_size(0)
	{}
public:
	void Insert(const string &key)
	{
		size_t bitCount = _bmp.size();
		size_t index1 = HashFunc1()(key) % bitCount;
		_bmp.Set(index1);
		size_t index2 = HashFunc2()(key) % bitCount;
		_bmp.Set(index2);
		size_t index3 = HashFunc3()(key) % bitCount;
		_bmp.Set(index3);
		_size++;
	}
	bool Test(const string &key)
	{
		size_t bitCount = _bmp.size();
		size_t index1 = HashFunc1()(key) % bitCount;
		if(!_bmp.Test(index1))
			return false;
		size_t index2 = HashFunc2()(key) % bitCount;
		if(!_bmp.Test(index2))
			return false;
		size_t index3 = HashFunc3()(key) % bitCount;
		if(!_bmp.Test(index3))
			return false;
		return true; // key  可能存在
	}
private:
	BitSet<_N*5> _bmp;
	size_t       _size;
};

void main()
{
	string url1 = "www.baidu.com";
	string url2 = "www.taobao.com";
	BloomFilter<string> bf;
	bf.Insert(url1);
	bf.Insert(url2);
	cout<<bf.Test(url1)<<endl;
	cout<<bf.Test(url2)<<endl;
	cout<<bf.Test("www.taobao.cnm")<<endl;
}

/*
void main()
{
	BitSet<100> bt;  //00 0000 0000
	bt.Set(35);      //00 0000 1000
	bt.Set(30);
	cout<<bt.Test(35)<<endl;
	cout<<bt.Test(28)<<endl;

	cout<<bt.Count()<<endl;
	
}

/*
_Words = (ptrdiff_t)(_Bits == 0	? 0 : (_Bits - 1) / 32)};  //99/32=3  32 33
int _Array[_Words + 1];	// the set of bits
int _Array[1];
int _Array[4]; //128

void main()
{
	bitset<100> bt;   //00 0000 0000
	cout<<bt<<endl;
	bt.set();
	cout<<bt<<endl;  //00 0000 1000

	bt<<=2;
	cout<<bt<<endl; //1111 1111 00

	cout<<bt.count()<<endl; //用于统计1的个数

	cout<<bt.to_ulong()<<endl;

	cout<<bt.to_string()<<endl;
}

/*
void main()
{
	bitset<10> bt;   //00 0000 0000
	cout<<bt<<endl;
	bt.set(3);
	cout<<bt<<endl;  //00 0000 1000
	//cout<<bt.test(5)<<endl;
	//bt.reset();
	//cout<<bt<<endl;

	cout<<bt[3]<<endl; //bt.test(3) // bt.at(3)
	cout<<bt.at(3)<<endl;

	bt.flip();
	cout<<bt<<endl;
}
*/