#include <bits/stdc++.h>

using namespace std;

#define Max_size 10000

class Stack
{
  int Top;
  public : 
  int array[Max_size];
  Stack()
  {
    Top=-1;
  }
  void push(int d)
  {
    if(Top<=Max_size)
      array[++Top]=d;
    else
      cout<<"Stack Overflow Error";
  }
  int pop()
  {
    if(Top>=0)
      return array[Top--];
    else
    {
        cout<<"Stack Underflow Error";
        return -1;
    }    
  }
  bool isEmpty()
  {
    return Top==-1;
  }
};


int main()
{
  //Creating a stack
  Stack s;
  //Entering 3 integers to be pushed onto the stack s
  int no1,no2,no3;
  cin>>no1>>no2>>no3;
  //Pushing integers onto the stack
  s.push(no1);
  s.push(no2);
  s.push(no3);
  //Popping out and displaying the 3 numbers
  cout<<"First Number that is popped : "<<s.pop()<<"\nSecond Number that is popped : "<<s.pop()<<"\nThird Number that is popped : "<<s.pop()<<endl;
  return 0;
}
