#include <iostream>
using namespace std;


void findElement(int input[][100], int m, int n, int x) {
	int i = 0, j = n - 1;
	while(i < m && j >= 0) {
		if(input[i][j] == x) {
			cout << i << " " << j << endl;
			return;
		}
		else if(x > input[i][j]) {
			i++;
		}
		else {
			j--;
		}
	}
	cout << "-1" << endl;
}

void printArray(int input[][100], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0;  j < n; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;	
	}

}

int main() {
	int a[100][100];
	int m, n;
	
	// Rows - m
	// Cols - n
	cin >> m >> n;


	// Taking input
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int x;
	cin >> x;

	findElement(a, m, n, x);

	//printArray(a, m, n);

}

