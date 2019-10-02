#include<bits/stdc++.h>
 
using namespace std;
 
int addtwo(int a,int b)
{
    int s,c;
    if (b == 0)
        return a;
    else
        s = a^b;
        c = (a&b) << 1;
    return addtwo(s,c);
}
 
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<addtwo(a,b)<<endl;
    return 0;
}
