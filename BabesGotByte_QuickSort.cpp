#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
    if(low>=high){
        return 0;
    }
    int pivot=arr[high];
    int index=low;
    while(low<high){
        if(arr[low]<pivot){
            swap(arr[low],arr[index]);
            index++;
        }
        low++;
    }
    swap(arr[index],arr[high]);
    return index;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[1000],n,T,i;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        quickSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}



