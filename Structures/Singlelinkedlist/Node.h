#pragma once
#include<iostream>


template <typename T>
class Node
{
public:
	T data;
	Node<T>* pNext;

	Node(T data) { //constructor
		pNext = NULL;
		this->data = data;
	}
	~Node() {//destructor
		data = NULL;
		pNext = NULL;
	}

};

