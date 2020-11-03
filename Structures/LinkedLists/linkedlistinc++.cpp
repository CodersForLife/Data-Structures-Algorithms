#include<bits/stdc++.h>
using namespace std;
//structure for a node template
struct node{
  int data;
  struct node *next;
} *head=NULL,*lst=head;
//function to insert an element in the front of linked list
void insertfront(int data)
{
  struct node *newnode = new node();
  //struct node *temp;
  newnode->data=data;



     newnode->next=head;
     head=newnode;
     return;

   //cout<<head->data<<" ";
}

//function to insert a node at the end of list
void insertend(int data)
{
  struct node *newnode=new node();
  lst=head;
  newnode->data=data;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    return;
  }
  else
  {
    while(lst->next!=NULL)
    {
      lst=lst->next;
    }
    lst->next=newnode;
    return;
  }
  //cout<<newnode->data<<" ";
}
//to insert an element at any random position
void insertrand(int data,int aft)
{
  struct node *newnode=new node();
  lst=head;
  newnode->data=data;
  while(lst->next!=NULL)
  {
    if(lst->data==aft)
    {
      newnode->next=lst->next;
      lst->next=newnode;
      break;
    }
    else{
      lst=lst->next;
    }
  } return;
  //cout<<newnode->data<<" ";

}
//function to delete a given node
void del(int data)
{
  //struct node *temp;
  struct node *temp=head;
  struct node *prev=NULL;
  if(temp!=NULL&&temp->data==data)
  { head=temp->next; return;}
  while(temp!=NULL&&temp->data!=data)
  {
     prev=temp;
     temp=temp->next;
  }
   prev->next=temp->next;
   free(temp);
}
//function to display the list
void disp()
{ lst=head;
  //cout<<"kk";
  while(lst!=NULL)
  {
    cout<<lst->data<<" ";
    //cout<<"dd"<<" ";
    lst=lst->next;
  }
}
//change the main function accordingly to see the desired output
int main()
{ //disp();
  cout<<"list"<<endl;
  insertend(3);
  insertfront(2);

  del(3);
  insertfront(1);
  insertend(3);
  insertrand(4,2);
  disp();
}
