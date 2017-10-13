#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max,i,n,j;
    printf("Enter the size of array");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
       {    
           {if(a[i]<a[j])
               {max=a[i];
                a[i]=a[j];
                a[j]=max;
                }
               }
       }
    }
   for(i=0;i<n;i++)
       printf("%d ",a[i]);
    return 0;
}
