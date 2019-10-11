#include <iostream>
using namespace std; 
int main()
{
  int No_of_elements, swap;
 
 cout<<"Enter the no of elements : ";
 cin>>No_of_elements;
 
 int Array[No_of_elements];
 cout<<"Enter the elements of array";
 
  for (int i = 0; i < No_of_elements; i++)
    cin>>Array[i];
 
  for (int first_iterator = 0 ; first_iterator < ( No_of_elements - 1 ); first_iterator++)
  {
    for (int second_iterator = 0 ; second_iterator < No_of_elements - first_iterator - 1; second_iterator++)
    {
      if (Array[second_iterator] > Array[second_iterator+1]) /* For decreasing order use < */
      {
        swap                     = Array[second_iterator];
        Array[second_iterator]   = Array[second_iterator+1];
        Array[second_iterator+1] = swap;
      }
    }
  }
 
  cout<<"Sorted List in Ascending Order"<<endl;
 
  for ( int i = 0 ; i < No_of_elements ; i++ )
     cout<<Array[i]<<" ";
 
  return 0;
}
