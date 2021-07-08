#include <vector>
#include <stdio.h>

int linearSearch(const std::vector<int> arr, int value)
{
  for (unsigned int i = 0; i < arr.size(); ++i)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }
   return -1;
}
 
int main()
{
   std::vector<int> arr = {10, 34, 22, 4, 5};
   int x = 10;
   int result = linearSearch(arr, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
