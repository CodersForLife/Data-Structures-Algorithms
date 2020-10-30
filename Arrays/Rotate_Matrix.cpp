/*
Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
Try using it without any extra space.
Note : You just need to change in the given input itself. No need to return or print anything.
Input format :

Line 1 : Integers N
Next N lines : N integers, elements of one row (separated by space)

Output Format :

Updated matrix

Constraints :
1 <= N <= 1000
Sample Input :

3
1 2 3
4 5 6
7 8 9

Sample Output :

3  6  9 
2  5  8 
1  4  7
*/



void swap(int **input,int f_i,int f_j, int s_i,int s_j){
    int temp=input[f_i][f_j];
    input[f_i][f_j]=input[s_i][s_j];
    input[s_i][s_j]=temp;
}
void printmat(int **input,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=="<<endl;
}
void rotate(int **input, int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    int r1=0,r2=n-1;
    int c1=0,c2=n-1;
    
    int k=1;
    while(k<=n*n){
        for(int i=c1;i<=c2;i++){
            swap(input,r1,i,i,c2);
            k++;
        }
        //printmat(input,n);
        r1++;
        for(int i=r1;i<=r2;i++){
            swap(input,i,c2,r2,n-1-i);
            k++;
        }
        //printmat(input,n);
        c2--;
        for(int i=c2;i>=(c1+1);i--){
            swap(input,r2,i,i,c1);
            k++;
        }
        k++;
        //printmat(input,n);
        r2--;
        for(int i=r2;i>=r1;i--){
            k++;
        }
        c1++;
        
    }
    
}

#include<iostream>
using namespace std;
#include "Solution.h"

int main() {
    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}
