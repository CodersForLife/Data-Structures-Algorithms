#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of numbers  :");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("\n");
    printf("Enter the numbers :");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        {
              if(arr[i]<arr[j])
              {
                  arr[i]^=arr[j];
                  arr[j]^=arr[i];
                  arr[i]^=arr[j];
              }
        }
    printf("\nSorted Array  :");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
