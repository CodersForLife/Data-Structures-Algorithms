//This Code all prints all the prime number till input n 

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,count=0; 
	cin>>n;
	for(i=2;i<n;i++)
	{

		j=2;
		count=0;
		while( j<1005 && j<i)
		{
			if( i%j ==0 && j<i)
				count++;
			j++;
		}
		if( count == 0)
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
