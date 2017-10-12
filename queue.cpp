# Impementation of a quene using linked list
# c++

#include <iostream.h>
#include <stdio.h>
#include <conio.h>

struct Node
{ int data;
 struct Node *next;
 }*front,*rear;
 
 void insert(int);
 void display();
 void delete();
 
 void main()
 {
 clrscr();
 int choice, value;
 cout<<"\n queue implementation using linked list ";
 cout<<"\n MENU ";
 cout<<"\n 1.insert "<<"\n 2.display "<<"\n 3.delete";
 cout<<"\n enter your choice ";
 cin>>choice;
 switch(choice)
 {
 case 1:cout<<"\n enter the value to be inserted:";
        cin>>value;
        insert(value);
        break;
 case 2:display();
        break;
 case 3:delete():
        break;
 default: cout<<"\nwrong selection";
 }
 }
 
 void insert(int value)
 {
 struct Node *newnode;
 newnode-> data = value;
 newnode-> next = null;
 if(front == null)
    front = rear = newnode;
    else
    {
    rear -> next = newnode;
    rear = newnode;
    }
    cout<<"\nsuccess";
    }
    
    void display()
    {
    if(front == null)
    cout<<"\n queue is empty";
    else
    {
    struct Node *temo = front;
    while(temp->next != null)
    {
    cout<<temp -> data<<endl;
    temp = temp -> next;
    }
    cout<<"\nsuccess";
    }
    }
    
    void delete()
    {
    if(front == null )
    cout<<"\n queue is empty ";
    else
    {
    struct Node *temp = front;
    front = front -> next;
    cout<<"\n deleted element "<< temp -> data;
    delete temp;
}
