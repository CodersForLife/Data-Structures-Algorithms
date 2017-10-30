#include <bits/stdc++.h> //including all the libraries of cpp
using namespace std;

int main() 
{
	int N;
	cout<<"Enter the number of elements to sort"<<endl;
	cin>>N;  //to enter the number of elements to sort
	int a[N];  //array to store all the elements
	cout<<"Start entering the numbers"<<endl;
	for (int i = 0; i < N; ++i)  //loop to take input of the elements
	{
		cin>>a[i];
	}
	int min,max;  //variables to store the max and min values
	min=max=a[0];
	for(int i=0;i<N;i++)  //loop to find the max and min values 
	{
		if(a[i]<min)
			min=a[i];
		else if(a[i]>max)
			max=a[i];
	}
	int sort[max-min+1];  //array to count the frequency of all elements
	for(int i=min;i<=max;i++)  //initialising all frequencies to zero
	{
		sort[i]=0;
	}
	for(int i=0;i<N;i++) //increasing the count of each element
	{
		sort[a[i]-min]++;
	}
	cout<<"Sorted array using counting sort:"<<endl; 
	for(int i=min;i<=max;i++)  //loop to print the elements in increasing order
	{
		for(int j=0;j<sort[i];j++) //loop to print each element equal to the times of it's occurence
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}//end