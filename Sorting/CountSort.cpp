#include <bits/stdc++.h>
using namespace std;
#define MAX_RANGE 100000
int countSort(int a[],int size)
{
    int count[MAX_RANGE];
    memset(count,0,sizeof(count));
    for(int i=0;i<size;i++)
    {
        count[a[i]]+=1;
    }
    int j=0;
    for(int i=0;i<MAX_RANGE;i++)
    {
        if(count[i]>0)
        {
            int x=count[i];
            while(x>0)
            {
                a[j]=i;
                j++;
                x--;
            }
        }
    }
return 0;    
}
int main() {

    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    countSort(array,size);
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    } 
    cout<<endl;
return 0;
}
