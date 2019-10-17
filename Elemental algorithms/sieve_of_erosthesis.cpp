#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=300;
    vector<bool> isPrime(n+1,true);
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        if(isPrime[i]==true)
            cout<<i<<" ";
    }
    return 0;
}
