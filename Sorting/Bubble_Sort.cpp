#include<iostream>
using namespace std;
template <class X>          //defining template X for data types in Swapping function
void swapping(X &number1,X &number2)
{
    X temp;
    temp=number1;
    number1=number2;
    number2=temp;
}

template<class T>               ////defining template Y for data types in BubbleSort function
void BubbleSort(T numbers[],int elements)           //defining BubbleSort function
{
    for(int count1=0; count1<=elements-1; count1++)         //running loop1
    {
        for(int count2=elements-1; count1<count2; count2--)     //running loop2
        {
            if(numbers[count2]<numbers[count2-1])
            {
                swapping(numbers[count2],numbers[count2-1]);        //calling "swapping" function to swap two consecutive values according to the condition
            }
        }
    }
}




int main()
{
    int array1[5]= {10,40,50,20,30};            //creating first array with data type as int i.e X=int
    float array2[5]= {5.5,2.2,1.1,4.4,3.3};     //creating second array with data type as float i.e Y=float
    int counter;                                //display input array
    cout<<"Arrays before Soring"<<endl;
    cout<<"Array 1:"<<endl;
    for(counter=0; counter<5; counter++)
    {
        cout<<array1[counter]<<" "<<endl;
    }
    cout<<"Array 2:"<<endl;
    for(counter=0; counter<5; counter++)
    {
        cout<<array2[counter]<<" "<<endl;
    }

    BubbleSort(array1,5);
    BubbleSort(array2,5);

    cout<<"Sorted arrays are"<<endl;            //displaying Arrays after Bubble sorting
    cout<<"Array 1:"<<endl;
    for(counter=0; counter<5; counter++)
    {
        cout<<array1[counter]<<" "<<endl;
    }
    cout<<"Array 2:"<<endl;
    for(counter=0; counter<5; counter++)
    {
        cout<<array2[counter]<<" "<<endl;
    }
    return 0;
}

