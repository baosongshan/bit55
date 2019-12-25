#include<iostream>
#include<stack>
using namespace std;

template<typename Type>
class AVLTree;

template<typename Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d=Type(), AVLNode<Type>*left=nullptr, AVLNode<Type>*right=nullptr)
		: data(d),leftChild(left),rightChild(right),bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode<Type> *leftChild;
	AVLNode<Type> *rightChild;
	int bf; //平衡因子
};

template<typename Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type &x);  //接口
	bool Remove(const Type &key);
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x); //
	bool Remove(AVLNode<Type> *&t, const Type &key); //
protected:
	void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	}
	void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightChild;
		ptr = subR->leftChild;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;
	}
	void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr->leftChild;
		AVLNode<Type> *subR = ptr;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf;
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;
		
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf;
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}
private:
	AVLNode<Type> *root;
};

//////////////////////////////////////////////////////
template<typename Type>
bool AVLTree<Type>::Insert(const Type &x)
{
	return Insert(root, x);
}
template<typename Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	stack<AVLNode<Type> *> st;
	//1 插入数据
	AVLNode<Type> *p = t;
	AVLNode<Type> *pr = nullptr;
	while(p != nullptr)
	{
		if(x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if(x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);
	
	if(pr == nullptr)
	{
		t = p;
		return true;
	}

	//链接节点
	if(x < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;


	//2 平衡调整
	while(!st.empty())
	{
		pr = st.top();
		st.pop();

		if(pr->leftChild == p)
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0)  //在矮子树上插入节点
			break;
		if(pr->bf==1 || pr->bf==-1) //增加了子树的高度
			p = pr;
		else   // |bf| == 2 需要平衡调整
		{
			if(pr->bf > 0)
			{
				if(p->bf > 0)    //    \ 
				{
					//cout<<"RotateL"<<endl;
					RotateL(pr);
				}	
				else             //      >
				{
					//cout<<"RotateRL"<<endl;
					RotateRL(pr);
				}
			}
			else
			{
				if(p->bf < 0)    //      /
				{
					//cout<<"RotateR"<<endl;
					RotateR(pr);
				}
				else             //     <
				{
					//cout<<"RotateLR"<<endl;
					RotateLR(pr);
				}
			}
			break;
		}
	}
	if(st.empty())
	{
		t = pr;
	}
	else
	{
		AVLNode<Type> *q = st.top();
		if(pr->data < q->data)
			q->leftChild = pr;
		else
			q->rightChild = pr;
	}

	return true;
}

template<typename Type>
bool AVLTree<Type>::Remove(const Type &key)
{
	return Remove(root, key);
}
template<typename Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	stack<AVLNode<Type>*> st;
	//查找节点
	AVLNode<Type> *p = t, *pr = nullptr;
	while(p != nullptr)
	{
		if(key == p->data)
			break;

		pr = p;
		st.push(pr);

		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if(p == nullptr)
		return false;

	AVLNode<Type> *q;
	if(p->leftChild!=nullptr &&p->rightChild!=nullptr)
	{
		pr = p;
		st.push(pr);
		q = p->leftChild;
		
		while(q->rightChild != nullptr)
		{
			pr = q;
			st.push(pr);
			q = q->rightChild;
		}
		p->data = q->data;
		p = q;
	}

	if(p->leftChild != nullptr)
		q = p->leftChild;
	else
		q = p->rightChild;

	if(pr == nullptr)
	{
		t = q;
	}
	else
	{
		//删除节点
		if(pr->leftChild == p)
			pr->leftChild = q;
		else
			pr->rightChild = q;

		//调整bf
		while(!st.empty())
		{
			if(pr->leftChild == q)
				pr->bf++;
			else
				pr->bf--;

			if(pr->bf==1 ||pr->bf==-1)
				break;
			if(pr->bf == 0)
				q = pr;
			else
			{
				//旋转调整平衡
				if(pr->bf > 0)
					q = pr->rightChild;
				else
					q = pr->leftChild;

				//1 bf==0
				if(q->bf == 0) //   /  \  >  <
				{}
				//2 bf符号相同

				//3 bf符号不同
				
			}

		}

	}
	
	delete p;
	return true;
}


int main()
{
	int ar[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	//int ar[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	//int ar[] = {16, 8, 10};
	int n = sizeof(ar) / sizeof(int);

	AVLTree<int> avl;
	for(int i=0; i<n; ++i)
	{
		avl.Insert(ar[i]);
	}
	avl.Remove(11);
	return 0;
}