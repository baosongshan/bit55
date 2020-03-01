#include<iostream>
#include<vector>
using namespace std;

typedef enum{RED=0, BLACK}Color_Type;

template<typename Type>
class RBTree;

template<typename Type>
class RBTreeNode
{
	friend class RBTree<Type>;
public:
	RBTreeNode(const Type &val = Type())
		:data(val),left(nullptr),right(nullptr),parent(nullptr),color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode *left;
	RBTreeNode *right;
	RBTreeNode *parent;
	Color_Type color;
};

template<typename Type>
class RBTree
{
public:
	RBTree() : NIL(_Buynode())
	{
		NIL->left = NIL->right = NIL->parent = NIL;
		NIL->color = BLACK;
		root = NIL;
	}
public:
	void  insert(const Type &x)
	{
		insert(root, x);
	}
protected:
	void  insert(RBTreeNode<Type> *&t, const Type &x)
	{
		//1、根据BST的规则，找到插入位置，并把新节点进行插入
		RBTreeNode<Type> *pr = NIL;
		RBTreeNode<Type> *p = t;
		while(p != NIL)
		{
			if(x == p->data) //重复值
				return;

			pr = p;

			if(x < p->data)
				p = p->left;
			else
				p = p->right;
		}

		RBTreeNode<Type> *s = _Buynode(x);
		if(pr == NIL)
		{
			//第一次插入根节点
			t = s;
			t->parent = NIL;
		}
		else if(x < pr->data)
			pr->left = s;
		else
			pr->right = s;
		s->parent = pr;

		//2、平衡调整
		insert_fixup(t, s);
	}
protected:
	void insert_fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
	{
		//x为新插节点，s为叔伯节点，p为父节点,g为祖父节点
		while(x->parent->color == RED)
		{
			RBTreeNode<Type> *s;
			if(x->parent == x->parent->parent->left) //左分支
			{
				s = x->parent->parent->right;

				if(s->color == RED) //状况3
				{
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if(x == x->parent->right) //状况2  // <
				{
					x = x->parent;
					LeftRotate(t, x);
				}
				//状况1
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RightRotate(t, x->parent->parent);
			}
			else //右分支
			{
				s = x->parent->parent->left;
				if(s->color == RED) ////状况3
				{
					x->parent->color = BLACK;
					s->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
					continue;
				}
				else if(x == x->parent->left) //状况2  // >
				{
					x = x->parent;
					RightRotate(t, x);
				}

				//状况1
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				LeftRotate(t, x->parent->parent);
			}
		}
		t->color = BLACK;
	}

	//旋转方法都以p节点为轴点进行旋转
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
	{
		RBTreeNode<Type> *s = p->right;
		p->right = s->left;
		if(s->left != NIL)
			s->left->parent = p;
		s->parent = p->parent;
		if(p->parent == NIL)
			t = s;
		else if(p == p->parent->left)
			p->parent->left = s;
		else
			p->parent->right = s;

		s->left = p;
		p->parent = s;
	}
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p) 
	{
		RBTreeNode<Type> *s = p->left;
		p->left = s->right;
		if(s->right != NIL)
			s->right->parent = p;
		s->parent = p->parent;
		if(p->parent == NIL)
			t = s;
		else if(p == p->parent->left)
			p->parent->left = s;
		else
			p->parent->right = s;

		s->right = p;
		p->parent = s;
	}
protected:
	RBTreeNode<Type>* _Buynode(const Type &val = Type())
	{
		RBTreeNode<Type>* _S = new RBTreeNode<Type>(val);
		_S->left = _S->right = _S->parent = NIL;
		return _S;
	}
private:
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *NIL;
};

int main()
{
	vector<int> v = {10, 7, 4, 2, 8, 15 ,5, 6, 11, 13, 12};

	RBTree<int> rb;
	for(const auto &e : v)
		rb.insert(e);
	return 0;
}