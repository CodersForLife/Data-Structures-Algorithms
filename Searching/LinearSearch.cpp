#include <iostream> 
using namespace std; 

int main() 
{ 
    int n, i, srch, index = -1;
    cout<<"\t\tLinear Search Demonstration";
    cout<<endl<<"Enter number of elements you want to enter: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of the array now: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Enter the element to be searched: ";
    cin>>srch;

    for(i = 0; i < n; i++) 
    {
        if (arr[i] == srch) 
            index = i+1; 
    }
     
    if(index == -1)
        cout<<"Element "<<srch<<" is not present in the array."; 
    else
        cout<<"Element "<<srch<<" is present in the array at index "<<index; 
    
    return 0; 
} 
