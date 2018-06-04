#pragma once
#include"Node.h"
using namespace std;

template <typename T>
class Stack
{
public:
	Node<T>* pHead;

	Stack() {
		pHead = NULL;
	}
	~Stack() {
		pHead = NULL;
	}

	void push(T data) {
		Node<T>* newnode = new Node<T>(data);

		if (pHead == NULL) //if pHead ==NULL set the newnode as the pHead;
		{
			pHead = newnode;
			return;
		}
		else { //if not set newnode's next
			Node<T>* walker = pHead;
			newnode->pNext = walker;
			pHead = newnode;
			return;
		}
		return;
	}

	void pop() {
		if (pHead == NULL)
		{
			cout << "There is no data in stack" << endl;
			return;
		}
		else {
			Node<T>* walker = pHead;
			pHead = walker->pNext;
			cout << walker->data << " is popped !" << endl;
			delete walker;
		}
		return;
	}

	void show() {
		if (pHead == NULL) {
			cout << "There is no data in stack" << endl;
			return;
		}
		else {
			Node<T>* walker = pHead;
			cout << "*****SHOW ALL NODE*****" << endl;

			while (walker != NULL) {
				cout << walker->data << " ";
				walker = walker->pNext;
			}
			cout << endl;
		}
	}
};

