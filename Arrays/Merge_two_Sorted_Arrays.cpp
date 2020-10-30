/*
Given two sorted arrays of Size M and N respectively, merge them into a third array such that the third array is also sorted.
Input Format :
 Line 1 : Size of first array i.e. M
 Line 2 : M elements of first array separated by space
 Line 3 : Size of second array i.e. N
 Line 2 : N elements of second array separated by space

 Output Format :
M + N integers i.e. elements of third sorted array separated by spaces.

Constraints :
1 <= M, N <= 10^6
Sample Input :
5
1 3 4 7 11
4
2 4 6 13

Sample Output :
1 2 3 4 4 6 7 11 13 
*/

#include<iostream>
#include "Solution.h"
using namespace std;


void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){
    
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Save the merged array in ans[] array passed as argument.
     * Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */
    int i=0,j=0;
    int k=0;
    while (i<size1 && j<size2){
        if(arr1[i]<=arr2[j])
            ans[k]=arr1[i++];
        else
            ans[k]=arr2[j++];
        k++;
    }
    
    if (i==size1){
        while (j<size2)
            ans[k++]=arr2[j++];
    }
    else{
        while(i<size1)
            ans[k++]=arr1[i++];
    }
 
}


int main(){
  int size1;  
  cin >> size1;
  int* arr1 = new int[size1];
  for(int i = 0; i < size1; i++){
    cin >> arr1[i];
  } 
  int size2;  
  cin >> size2;
  int* arr2 = new int[size2];
  for(int i = 0; i < size2; i++){
    cin >> arr2[i];
  } 
	
  int* ans = new int[size1 + size2];
	
  merge(arr1, size1, arr2, size2, ans);

  for(int i = 0; i < size1 + size2; i++){
			cout << ans[i] <<  " ";
		}
  delete arr1;
  delete arr2;
  delete ans;
}


