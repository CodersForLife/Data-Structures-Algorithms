#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Node
{
public: T data;
		Node<T> *pNext;
		Node<T> *pPrev;

		Node() {
			data = 0;
			pNext = NULL;
			pPrev = NULL;
		}
		~Node() {
			data = 0;
			pNext = NULL;
			pPrev = NULL;
		}
		Node(T data) {
			this->data = data;
			pNext = NULL;
			pPrev = NULL;
		}
};

template <typename T>
class Doublelinkedlist
{
public:
	Node<T> *pHead;
	Node<T> *pTail;

	Doublelinkedlist()
	{
		pHead = NULL;
		pTail = NULL;
	}
	~Doublelinkedlist()
	{
		pHead = NULL;
		pTail = NULL;
	}

	void Insert(T data) 
	{
		Node<T> *newnode = new Node(data);
		
		if (pHead == NULL)
		{
			pHead = newnode;
			pTail = newnode;
			return;
		}
		else {
			Node<T> *walker = pHead;
			while (walker->pNext != NULL) {
				walker = walker->pNext;
			}
			walker->pNext = newnode;
			newnode->pPrev = walker;
			newnode = pTail;
			return;
		}
	}

	void Delete(T data) 
	{
		if (pHead == NULL) return;
		Node<T> *walker = pHead;
		while (walker != NULL)
		{
			if (walker->data == data)
			{
				if (walker == pHead)
				{
					walker->pNext->pPrev = walker->pPrev;
					pHead = walker->pNext;
					delete walker;
					return;
				}
				else if (walker == pTail) {
					walker->pPrev->pNext = walker->pNext;
					pTail = walker->pPrev;
					delete walker;
				}
				else {
					walker->pPrev->pNext = walker->pNext;
					walker->pNext->pPrev = walker->pPrev;
					delete walker;
				}
			}
			walker = walker->pNext;
		}
	}

	void Print()
	{
		if (pHead == NULL)return;
		Node<T>* walker = pHead;
		while (walker != NULL) {
			cout << walker->data << " ";
		}
		cout << endl;
	}

};

