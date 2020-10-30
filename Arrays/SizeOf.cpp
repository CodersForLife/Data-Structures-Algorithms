#include <iostream>
using namespace std;

void test(int a, int b[]) {
	cout << a << endl;
	cout << b[0] << endl;
}

void printArray(int input[], int n) {

	cout << "Function : " << sizeof(input) << endl;

	
	//int size = sizeof(input) / sizeof(int);
	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	
	
	}

int main() {
	int input[] = {1, 2, 3};
	cout << "Main : " << sizeof(input) << endl;
	/*
	int n;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	*/

	int a = 6;

	test(a, input);

	printArray(input, 3);
}
