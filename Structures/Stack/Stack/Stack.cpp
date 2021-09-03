#pragma once
#include"Stackusinglinkedlist.h"

void main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(3);
	stack.push(7);
	stack.push(4);
	stack.pop();
	stack.show();

}