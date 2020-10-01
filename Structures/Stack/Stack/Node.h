#pragma once
#include <iostream>

template<typename T>
class Node
{
public:
	T data;
	Node<T>* pNext;

	Node(T data) {
		this->data = data;
		pNext = NULL;
	}
	~Node() {
		this->data = NULL;
		pNext = NULL;
	}
};

