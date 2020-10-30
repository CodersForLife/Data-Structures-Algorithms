/*
Given an N*M 2D array, print it in spiral form. That is, first you need to print the 1st row, then last column, then last row and then first column and so on.
Print every element only once.
Input format :

Line 1 : N and M, No. of rows & No. of columns (separated by space) followed by N*M  elements in row wise fashion.

Sample Input :

 4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Sample Output :

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


*/

#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
    int k=1;
    int r1=0,r2=row-1;
    int c1=0,c2=col-1;
    while(k<=row*col){
        for(int i=c1;i<=c2;i++){
            cout<<input[r1][i]<<" ";
            k++;
        }
        r1++;
        for(int i=r1;i<=r2;i++){
            cout<<input[i][c2]<<" ";
            k++;
        }
        c2--;
        for(int i=c2;i>=c1;i--){
            cout<<input[r2][i]<<" ";
            k++;
        }
        r2--;
        for(int i=r2;i>=r1;i--){
            cout<<input[i][c1]<<" ";
            k++;
        }
        c1++;
    }

}


#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    spiralPrint(input, row, col);
}