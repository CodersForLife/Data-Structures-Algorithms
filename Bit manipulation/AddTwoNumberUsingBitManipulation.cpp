#include<bits/stdc++.h>
 
using namespace std;
 
int addtwo(int Number1,int Number2)
{
    int sum ,carry;
    if (Number2 == 0)
        return Number1;
    else
        sum = Number1^Number2;
        carry = (Number1&Number2) << 1;
    return addtwo(sum ,carry);
}
 
int main()
{
    int Number1,Number2;
    cin>>Number1>>Number2;
    cout<<addtwo(Number1,Number2)<<endl;
    return 0;
}
