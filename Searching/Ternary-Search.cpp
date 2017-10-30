#include <bits/stdc++.h>
using namespace std;

int ternary_search(int array[],int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(array[mid1] == x)
            return mid1;
        if(array[mid2] == x)
            return mid2;
        if(x<array[mid1])
            return ternary_search(array,l,mid1-1,x);
        else if(x>array[mid2])
            return ternary_search(array,mid2+1,r,x);
        else
            return ternary_search(array,mid1+1,mid2-1,x);

    }
    return -1;
}
int main() {

    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    int val;
    cin>>val;
    cout<<ternary_search(array,0,size-1,val)<<endl;
return 0;
}
