#include <iostream>
using namespace std;
#include "solution.h"


// arr - input array
// size - size of array

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int sum=(size*(size-1))/2;
    
    int calsum=0;
    for(int i=0;i<size;i++)
        calsum+=arr[i];
    int k=sum-calsum;
    return size-1-k;
    

}


int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;
}
