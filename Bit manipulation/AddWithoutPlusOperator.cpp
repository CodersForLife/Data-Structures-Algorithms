#include<bits/stdc++.h>

using namespace std;

int addtwo(int FirstNo,int SecondNo)
{
    int sum,carry;
    if (SecondNo == 0)
        return FirstNo;
    else
        sum = FirstNo^SecondNo;
        carry = (FirstNo&SecondNo) << 1;
    return addtwo(sum,carry);
}

int main()
{
    int t;
    cin>>t;
    while(t)
    {
        int FirstNo,SecondNo;
        cin>>FirstNo>>SecondNo;
        cout<<addtwo(FirstNo,SecondNo)<<endl;
        --t;
    }
    return 0;
}
