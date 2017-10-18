/*author: Tanvi2698
date: 15/10/2017*/

#include<iostream>
using namespace std;
#define MAX 6                   //defining MAX as 6

void selectionSort(int numbers[]);      //declaration of function selection sort
void swapping(int*, int*);                  //declaration of swap function
int main()
{
    int counter;
    int numbers[MAX];   //creation of array

    cout<<"Enter elements for array"<<endl;
    for(counter=0;counter<MAX;counter++)       //input of numbers
    {
        cin>>numbers[counter];
    }
    cout<<"Displaying input array"<<endl;
    for(counter=0;counter<MAX;counter++)      //display of array
    {
        cout<<numbers[counter]<<endl;
    }
    cout<<"performing selection sort";
    selectionSort(numbers);              //call by reference selectionSort function,
    for(counter=0;counter<MAX;counter++)        //displaying sorted array
    {
        cout<<numbers[counter]<<endl;
    }
        return 0;
}

void selectionSort(int numbers[])               //definition of selectionSort function
{
    int count1,count2;                          //declaration of counters for loops
    int minimum;
    for(count1=0;count1<MAX;count1++)
    {
        minimum=count1;                         //selecting minimum index
        for(count2=count1+1;count2<=MAX;count2++)
        {
            if(numbers[count2]<numbers[minimum])
            {
                minimum=count2;                 //updating minimum index if the new number is smaller
            }
        }
        swapping(&numbers[count1], &numbers[minimum]);      //swapping the minimum number and the current index
    }
}

void swapping(int *number1,int *number2)        //definition of swap function
{
   int temp;
   temp=*number1;
   *number1=*number2;
   *number2=temp;
}
