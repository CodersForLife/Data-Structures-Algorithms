# Implementation of stack using linked list
# c++

#include <iostream.h>
#include <stdio.h>
#include <conio.h>

struct Node
{ int data;
struct Node *next;
}*top;

void push(int);
void display();
void pop();

void main()
{
clrscr();
int choice, value;
cout<<"\n stack implementation using linked list ";
cout<<"\n MENU ";
cout<<"\n 1.push "<<"\n 2.display "<<"\n 3.pop";
cout<<"\n enter your choice ";
cin>>choice;
switch(choice)
{
case 1:cout<<"\n enter the value to be inserted:";
cin>>value;
push(value);
break;

case 2:display();
break;

case 3:pop():
break;

default: cout<<"\nwrong selection";

}

}



void push(int value)
{
struct node *newnode;
newnode-> data = value;
newnode-> next = null;
if(top!=null)
newnode-> next = top;
top = newnode;
cout<<"\nsuccess";
}

void display()
{
if(front == null)
cout<<"\n stack is empty";
else
{
struct Node *temp = top;
while(temp->next != null)
{
cout<<temp -> data<<endl;
temp = temp -> next;
}
cout<<"\nsuccess";
}
}

void pop()
{
if(top == null )
cout<<"\n stack is empty ";
else
{
struct Node *temp = top;
top = top -> next;
cout<<"\n deleted element "<< temp -> data;
delete temp;
}
