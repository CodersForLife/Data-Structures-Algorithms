#include <iostream>
using namespace std;

int main() {
	int a[5] = {1, 2, 3};

	char b[] = "abcd";

	//cin >> b;
	
	
	cin.getline(b, 40, 'o'); //This is for taking string inputs for space in between

	cout << b << endl;

	/*
	cout << a << endl;

	b[1] = '\0';
	cout << b << endl;
	*/
	}