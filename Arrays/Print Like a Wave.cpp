/*
Given a two dimensional n*m array, print the array in a sine wave order. i.e. print the first column top to bottom, next column bottom to top and so on.
Note : Print the elements separated by space.
Input format :

n, m, array elements (separated by space)

Sample Input :

3 4 1  2  3  4 5  6  7  8 9 10 11 12

Sample Output :

1 5 9 10 6 2 3 7 11 12 8 4


*/
#include <iostream>
using namespace std;

void wavePrint(int input[][1000], int row, int col){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
    int flagdown=1;
    int k=1;
    int r1=0;
    while(k<=row*col){
        if(flagdown){
            for(int i=0;i<row;i++){
                k++;
                cout<<input[i][r1]<<" ";
            }
            flagdown=0;
            r1++;
        }
        else{
            for(int i=row-1;i>=0;i--){
                k++;
                cout<<input[i][r1]<<" ";
            }
            flagdown=1;
            r1++;
        }
    }

}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    wavePrint(input, row, col);
}