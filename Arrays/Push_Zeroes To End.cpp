/*
Given a random integer array, push all the zeros that are present to end of the array. The respective order of other elements should remain same.
Change in the input array itself. You don't need to return or print elements. Don't use extra array.
Note : You need to do this in one scan of array only.
Input format :

Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)

Output Format :

Array elements (separated by space)

Constraints :
1 <= N <= 10^6
Sample Input 1:

7
2 0 4 1 3 0 28

Sample Output 1:

2 4 1 3 28 0 0

Sample Input 2:

5
0 3 0 2 0

Sample Output 2:

3 2 0 0 0


*/

// arr - input array
// n - size of array

#include <iostream>
using namespace std;

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void printarr(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void PushZeroesEnd(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to return or print the output.
     * Taking input and printing output is handled automatically.
     */
    if (n==1)
        return;
    
    int i=0,j=0;
    
    //Find first zero
    while(i<n){
        if(arr[i]==0)
            break;
        i++;
    }
    j=i+1;
    while(j<n){
        if (arr[j]==0)
            j++;
        else{
            swap(arr,i,j);
            i++;
        }           
    }
    
}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	PushZeroesEnd(input,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	
	return 0;

}
