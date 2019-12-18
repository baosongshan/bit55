#include<iostream>
#include<assert.h>
#include<vld.h>
using namespace std;

template<typename Type>
class BSTree;

template<typename Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type>*left=nullptr,BSTNode<Type>*right=nullptr)
		: data(d),leftChild(left),rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type> *leftChild;
	BSTNode<Type> *rightChild;
};

template<typename Type>
class BSTree
{
public:
	BSTree() : root(nullptr)
	{}
	BSTree(Type ar[], int n) : root(nullptr)
	{
		for(int i=0; i<n; ++i)
		{
			Insert(ar[i]);
		}
	}
	~BSTree()
	{
		Clear();
	}
public:
	Type Max()const;
	Type Min()const;
	bool Insert(const Type &x);
	void Order()const;
	BSTNode<Type>* Find(const Type &key);
	void Clear();
	bool Remove(const Type &key);
protected:
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if(t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if(x < t->data)
			return Insert(t->leftChild, x);
		else if(x > t->data)
			return Insert(t->rightChild, x);
		return false;
	}
	Type Max(BSTNode<Type> *t)const
	{
		assert(t != nullptr);
		while(t->rightChild != nullptr)
			t = t->rightChild;
		return t->data;
	}
	void Order(BSTNode<Type> *t)const
	{
		if(t != nullptr)
		{
			Order(t->leftChild);
			cout<<t->data<<" ";
			Order(t->rightChild);
		}
	}
	BSTNode<Type>* Find(BSTNode<Type> *t, const Type &key)
	{
		if(t==nullptr || key==t->data)
			return t;
		if(key < t->data)
			return Find(t->leftChild, key);
		else if(key > t->data)
			return Find(t->rightChild, key);
	}
	void Clear(BSTNode<Type> *&t)
	{
		if(t != nullptr)
		{
			Clear(t->leftChild);
			Clear(t->rightChild);
			delete t;
			t = nullptr;
		}
	}
	bool Remove(BSTNode<Type> *&t, const Type &key)
	{
		if(t == nullptr)
			return false;
		if(key < t->data)
			return Remove(t->leftChild, key);
		else if(key >t->data)
			return Remove(t->rightChild, key);
		else
		{
			//
			if(t->leftChild==nullptr &&t->rightChild==nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if(t->leftChild!=nullptr &&t->rightChild==nullptr)
			{
				BSTNode<Type> *p = t;
				t = p->leftChild;
				delete p;
			}
			else if(t->leftChild==nullptr &&t->rightChild!=nullptr)
			{
				BSTNode<Type> *p = t;
				t = p->rightChild;
				delete p;
			}
			else
			{
				BSTNode<Type> *p = t->leftChild;
				while(p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, p->data);
			}

			return true;
		}
	}
private:
	BSTNode<Type> *root;
};

template<typename Type>
bool BSTree<Type>::Insert(const Type &x)
{
	return Insert(root, x);
}
template<typename Type>
Type BSTree<Type>::Max()const
{
	return Max(root);
}
template<typename Type>
void BSTree<Type>::Order()const
{
	Order(root);
}
template<typename Type>
BSTNode<Type>* BSTree<Type>::Find(const Type &key)
{
	return Find(root, key);
}
template<typename Type>
void BSTree<Type>::Clear()
{
	Clear(root);
}
template<typename Type>
bool BSTree<Type>::Remove(const Type &key)
{
	return Remove(root, key);
}

int main()
{
	int ar[] = {5,3,4,1,7,8,2,6,0,9};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst(ar, n);
	bst.Remove(5);
}

/*
int main()
{
	int ar[] = {5,3,4,1,7,8,2,6,0,9};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst(ar, n);

	cout<<"Max Value = "<<bst.Max()<<endl;
	cout<<"Order:";
	bst.Order();
	cout<<endl;

	BSTNode<int> *p = bst.Find(80);

	return 0;
}

/*
int main()
{
	int ar[] = {5,3,4,1,7,8,2,6,0,9};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst;
	for(int i=0; i<n; ++i)
	{
		bst.Insert(ar[i]);
	}

	cout<<"Max Value = "<<bst.Max()<<endl;
	cout<<"Order:";
	bst.Order();
	cout<<endl;

	BSTNode<int> *p = bst.Find(80);

	return 0;
}

/*
class A
{
public:
	virtual void func(int val = 1)
	{ 
		std::cout << "A->" << val << std::endl; 
	}
	virtual void test()
	{
		//A *pa
		this->func();
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;  //B->1
	}
};

int main(int argc, char* argv[])
{
	B *p = new B;
	p->test();
	return 0;
}

/*
class Base1 { public: int _b1; };
class Base2 { public: int _b2; };

class Derive : public Base1, public Base2 { public: int _d; };

int main()
{
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}

/*
class A{
public:
	A(char *s) { cout << s << endl; }  //1
	~A(){}
};
class B :virtual public A
{
public:
	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; } //2
};
class C :virtual public A
{
public:
	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
};
class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main() 
{
	D *p = new D("class A", "class B", "class C", "class D");
	//class A class B
	delete p;
	return 0;
}


/*
//抽象类 --> 定义接口
class A
{
public:
	//纯虚函数
	virtual void Eat() = 0
	{
		cout<<"A::Eat()"<<endl;
	}
	virtual void Foot() = 0;
	virtual void Sleep() = 0;
};

class Person : public A
{
public:
	virtual void Eat()
	{
		cout<<"Person::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
};

class Dog : public A
{
public:
	virtual void Eat()
	{
		cout<<"Dog::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}

};

class Bird : public A
{
public:
	virtual void Eat()
	{
		cout<<"Bird::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"Bird::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"Bird::Sleep()"<<endl;
	}
public:
	virtual void Fly()
	{
		cout<<"Bird::Fly()"<<endl;
	}
};

class TN : public Bird
{
public:
	virtual void Eat()
	{
		cout<<"TN::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"TN::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"TN::Sleep()"<<endl;
	}
private:
	virtual void Fly();
};

//动态绑定
void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

///////////////////////////////////////////

void main()
{
	Person p;
	Dog dog;
	Active(&dog);

	Bird b;
	//b.Fly();

}

/*
//final关键字
//用在类的后面 表示类不能被继承
//用在虚函数的后面，表示虚函数不能被重写
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
	}
	virtual ~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
public:
	virtual void fun()final
	{
		cout<<"Base::fun()"<<endl;
	}
public:
	virtual void print()
	{
		cout<<"Base::print()"<<endl;
	}
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
public:
	virtual void fun(int a)
	{
		cout<<"D::fun(int a)"<<endl;
	}
public:
	void print()override
	{
		cout<<"D::print()"<<endl;
	}
};

void main()
{
	Base *pb = new D;
	pb->fun();
	pb->print();
	delete pb;
}

/*
class Base final
{
public:

};

class D : public Base
{};

void main()
{
	D d;
}
*/