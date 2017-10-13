#include <stdio.h>

int binarySearch(int arr[], int beg, int last, int element)  // returns the position of the element if the search is successfull, otherwise returns -1.
{
   if (beg<=last)
   {
        int mid = (beg+last)/2;
        if (arr[mid] == x) 
        return mid;
        else if (arr[mid] > x) 
        return binarySearch(arr,beg, mid-1, x);
         else
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
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
