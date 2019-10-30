#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	string n;
	cin>>s>>n;
	int z=s.length()-n.length();
	for(int i=0;i<=z;i++)
	{
		int count=0;
		for(int j=0;j<n.length();j++)
		{
			if(s[i+j]==s[j])
			{
				count++;
			}
		}
		if(count==n.length())
		{
			cout<<"Pattern Found at index "<<i<<"\n";
		}
	}
}
