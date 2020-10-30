/*
You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
You need to change in the given array itself. So no need to return or print anything.
Input format :

Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)

Output Format :

Updated array elements (separated by space)

Constraints :
1 <= n <= 10^6
Sample Input:

7
0 1 2 0 2 0 1

Sample Output:

0 0 0 1 1 2 2 


*/

// arr - input array
// n - size of array

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void sort012(int arr[], int n)  {  
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
    int i=0;
    int j=n-1;
    
    while ((i<n && arr[i]==0) || (j>-1 && arr[j]==2)){
        if(arr[i]==0)
            i++;
        if(arr[j]==2)
            j--;
    }
    if(i==n || j==-1)
        return;
    int k=i;
    while(k<=j && i<=j){
        if(arr[k]!=1){
            if(arr[k]==0){
                swap(arr,i,k);
                i++;
                if(i>k)
                    k=i;
            }
            else{
                swap(arr,k,j);
                j--;
            }
        }
        else
            k++;
    }

}

#include <iostream>
#include <algorithm>
#include "solution.h"
using namespace std;


int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}
