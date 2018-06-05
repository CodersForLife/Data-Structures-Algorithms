#pragma once
#include"Node.h"

template <typename T>
class Linkedlist
{
private:
	Node<T>* pHead;
	int size;

public:
	Linkedlist() {
		pHead = NULL;
		size = 0;
	}
	~Linkedlist() {
		pHead = NULL;
		size = 0;
	}

	void insertdata(T data) {
		Node<T>* pNode = new Node<T>(data);
		if (pHead == NULL)
		{
			pHead = pNode;
			size++;
			return;
		}
		else {
			Node<T>* walker = pHead;

			while (walker->pNext != NULL)
			{
				if (walker->data == data) return;
				walker = walker->pNext;
			}
			
			if (walker->data == data) return;
			walker->pNext = pNode;
			size++;
			return;
		}
	}

	void deletedata(T data)
	{
		Node<T>* pNode = new Node<T>(data);

		if (pHead == NULL)
		{
			cout << "There is no node to delete" << endl;
			return;
		}
		else {
			Node<T>* walker = pHead;
			Node<T>* pwalker = NULL;


			while (walker != NULL)
			{
				pwalker = walker;

				if (data == walker->data)
				{
					if (walker == pHead) {
						pHead = walker->pNext;
						delete walker;
						size--;
						return;
					}
					else {
						pwalker->pNext = walker->pNext;
						delete walker;
						size--;
						return;
					}
				}
			}

			if (walker == NULL)
			{
				cout << "There is no node with the same data to delete " << endl;
			}
		}
		return;
	}

	void searchdata(T data)
	{
		Node<T>* walker = pHead;
		int seq = 1;

		cout << "*********SEARCH DATA************" << endl;
		
		while (walker != NULL)
		{
			if (data == walker->data)
			{
				cout << "The Node " << seq << "'s value is " << walker->data << endl;
				return;
			}
			walker = walker->pNext;
		}

		if (walker == NULL)
		{
			cout << "There is no node with the same data to search" << endl;
		}
		return;
	}

	void sortdata()
	{
		if (pHead == NULL)
		{
			cout << "There is no node to sort" << endl;
			return;
		}

		Node<T>* pwalker;
		Node<T>* walker;
		//Bubble Sort using data of node
		for (pwalker = pHead; pwalker; pwalker = pwalker->pNext)
		{
			for (walker = pHead; walker->pNext; walker = walker->pNext)
			{
				if (pwalker->data < walker->data)
				{//if need to change, change data
					int temp = pwalker->data;
					pwalker->data = walker->data;
					walker->data = temp;
				}
			}
		}
		return;
	}

	void showdata()
	{
		int seq = 1;

		if (pHead == NULL)
		{
			cout << "There is no node to show" << endl;
			return;
		}
		Node<T>* walker = pHead;
		cout << "*********SHOW DATA************" << endl;
		while (walker != NULL)
		{
			cout << "The Node " << seq << "'s value is " << walker->data << endl;
			seq++;
			walker = walker->pNext;
		}
		return;
	}
};

