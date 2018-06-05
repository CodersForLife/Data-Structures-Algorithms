#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <iostream>
#include <stack>
using namespace std;

class AVLNode
{
private:
	AVLNode*			pRight;
	AVLNode*			pLeft;
	int					data;
	int					mBF;


public:
	AVLNode() {
		pRight = NULL;
		pLeft = NULL;
		data = 0;
		mBF = 0;
	};
	~AVLNode() {};

	void setRight(AVLNode* SN) { pRight = SN; }
	void setLeft(AVLNode* SN) { pLeft = SN; }
	void setdata(int pdata) { data = pdata; }
	void setBF(int a) { mBF = a; }
	AVLNode*	getRight() { return pRight; }
	AVLNode*	getLeft() { return pLeft; }
	int				getBF() { return mBF; }
	int				getdata() { return data; }
};

class AVLTree {
private:
	AVLNode*	root;
	

public:

	AVLTree() {
		root = NULL;
	}
	~AVLTree() {};
	bool		Insert(int data);
	void		Print();
	AVLNode*		search(int data);
	AVLNode* Getroot() { return root; };
};

bool AVLTree::Insert(int data) {

	if (root == NULL)
	{
		AVLNode* avlnode = new AVLNode();
		avlnode->setdata(data);
		root = avlnode;
		return true;
	}

	AVLNode* walker = root;//a
	AVLNode* pwalker = NULL;//pa
	AVLNode* pre = root;//pd
	AVLNode* prepre = NULL;//pp
	AVLNode* subroot = NULL;

	while (pre != NULL) //move the pre and prepre
	{
		if (pre->getBF() != 0)
		{
			walker = pre;
			pwalker = prepre;
		}

		if (data > pre->getdata())
		{
			prepre = pre;
			pre = pre->getRight();
		}
		else if (data< pre->getdata())
		{
			prepre = pre;
			pre = pre->getLeft();
		}
		else {
			return false;
		}
	}

	AVLNode* y = new AVLNode(); //make avlnode
	y->setdata(data);
	if (data < prepre->getdata()) prepre->setLeft(y); //set the node location
	else prepre->setRight(y);

	int d;
	AVLNode* b;
	AVLNode* c;

	if (data > walker->getdata()) //swt the d if right insert d=-1 if not d=1
	{
		b = pre = walker->getRight(); d = -1;
	}
	else {
		b = pre = walker->getLeft(); d = 1;
	}

	while (pre != y)
	{
		if (data > pre->getdata()) //set the Balance factor under the pre
		{
			pre->setBF(-1);
			pre = pre->getRight();
		}
		else {
			pre->setBF(1);
			pre = pre->getLeft();
		}
	}

	if (walker->getBF() == 0 || walker->getBF() + d == 0) //balanced?
	{
		walker->setBF(walker->getBF() + d);
		return true;
	}

	if (d == 1)
	{
		if (b->getBF() == 1) //LL -> 
		{
			walker->setLeft(b->getRight());
			b->setRight(walker);
			walker->setBF(0);
			b->setBF(0);
			subroot = b;
		}
		else { //LR
			c = b->getRight();
			b->setRight(c->getLeft());
			walker->setLeft(c->getRight());
			c->setLeft(b);
			c->setRight(walker);
			switch (c->getBF()) //set the balance factor 
			{
			case 0:
				b->setBF(0);
				walker->setBF(0);
				break;
			case 1:
				walker->setBF(-1);
				b->setBF(0);
				break;
			case -1:
				walker->setBF(0);
				b->setBF(1);
				break;
			}
			c->setBF(0);
			subroot = c;
		}
	}
	else {
		if (b->getBF() == -1) //RR -> 
		{
			walker->setRight(b->getLeft());
			b->setLeft(walker);
			walker->setBF(0);
			b->setBF(0);
			subroot = b;
		}
		else { //RL
			c = b->getLeft();
			b->setLeft(c->getRight());
			walker->setRight(c->getLeft());
			c->setLeft(walker);
			c->setRight(b);
			switch (c->getBF()) //set the balance factor
			{
			case 0:
				b->setBF(0);
				walker->setBF(0);
				break;
			case 1:
				walker->setBF(0);
				b->setBF(-1);
				break;
			case -1:
				walker->setBF(1);
				b->setBF(0);
				break;
			}
			c->setBF(0);
			subroot = c;
		}
	}

	if (pwalker == NULL) //if walker=root set the root
	{
		root = subroot;
	}
	else if (walker == pwalker->getLeft()) //if not set the root
	{
		pwalker->setLeft(subroot);
	}
	else {
		pwalker->setRight(subroot);
	}

	return true; // no duplication
}

void AVLTree::Print()
{
	AVLNode* walker = root;
	stack<AVLNode*> s;

	while (s.empty())
	{
		while (walker)
		{
			s.push(walker);
			walker = walker->getLeft();
		}
		if (s.empty()) return;
		walker = s.top();
		cout << walker->getdata() << " ";
		s.pop();
		walker = walker->getRight();
	}

	return;
}

AVLNode* AVLTree::search(int data)
{
	AVLNode* walker = root;

	while (walker != NULL) //search the walker
	{
		if (walker->getdata() < data) //if id is bigger than walker's id go right
		{
			walker = walker->getRight();
		}
		else if (walker->getdata() > data) //if not go left
		{
			walker = walker->getLeft();
		}
		else if (walker->getdata() == data) //if same return
		{
			return walker;
		}
	}
	return walker;
}


#endif

