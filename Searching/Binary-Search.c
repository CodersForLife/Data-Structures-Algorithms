#include <stdio.h>

int binarySearch(int arr[], int beg, int last, int element)  // returns the position of the element if the search is successfull, otherwise returns -1.
{
   if (beg<=last) //Condition to check if element is found. If found value of beg will be greater than last 
   {
        int mid = (beg+last)/2;//Statement which will keep updating value of mid in each run
        if (arr[mid] == x) //Element Found
        return mid;
        else if (arr[mid] > x)//Element present in left side of middle element 
        return binarySearch(arr,beg, mid-1, x);
         else //Element present in right side of middle element 
        return binarySearch(arr, mid+1, last, x);
   }
   return -1;
}
 
int main()
{
   int arr[] = {10, 34, 22, 4, 5};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")//Output statement which verifies presence of element
                 : printf("Element is present at index %d", result);//Output statement which verifies presence of element at the particular location
   return 0;
}
