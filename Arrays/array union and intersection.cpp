#include<iostream>
using namespace std;

class Set
{
	int a[30];
	int n;
public:
	void getarr()
	{
		cout<<"\nEnter number of elements:";
		cin>>n;
	    cout<<"Enter elements:";
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	}
	void putarr()
	{
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<"  ";
	    }
	    cout<<"\n";
	}
	Set operator+(Set q);
	Set operator*(Set q);
	friend void arsort(int arr[], int n);
    friend Set unionarr(int a[],int m,int b[],int n);
    friend Set interarr(int a[],int m,int b[],int n);
};
void arsort(int arr[], int n)
{
    int i, a, j;
    for (i = 1; i < n; i++)
    {
        a = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > a)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = a;
    }
}
Set interarr(int a[],int m,int b[],int n)
{
	Set temp;
    int i,j,k;
    arsort(a,m);
    arsort(b,n);
    i=0;j=0;k=0;
    while(k<m+n&&i<m&&j<n)
    {
        if(b[j]<a[i])
        {
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            temp.a[k]=a[i];
            i++;
            j++;
            k++;
        }
    }
    temp.n=k;
    return temp;
}
Set unionarr(int a[],int m,int b[],int n)
{
    Set temp;
    int i,j,k,c;
    arsort(a,m);
    arsort(b,n);
    i=0;j=0;k=0;
    while(k<m+n&&i<m&&j<n)
    {
        if(b[j]<a[i])
        {
            temp.a[k]=b[j];
            j++;
            k++;
        }
        else if(a[i]<b[j])
        {
            temp.a[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp.a[k]=a[i];
            i++;
            j++;
            k++;
        }
    }
    if(i<m&&k<m+n)
    {
        for(c=i;c<m;c++)
        {
            temp.a[k]=a[c];
            k++;
        }
    }
    else if(j<n&&k<m+n)
    {
        for(c=j;c<n;c++)
        {
            temp.a[k]=b[c];
            k++;
        }
    }
    temp.n=k;
    return temp;
}
Set Set::operator+(Set q)
{
    Set temp;
    temp=unionarr(a,n,q.a,q.n);
    return temp;
}
Set Set::operator*(Set q)
{
    Set temp;
    temp=interarr(a,n,q.a,q.n);
    return temp;
}
int main()
{
	Set s1,s2,s3,s4;
    s1.getarr();
    s2.getarr();
    cout<<"\narrays";
    cout<<"\n";
    s1.putarr();
    s2.putarr();
    s3=s1+s2;
    s4=s1*s2;
    cout<<" \n UNION 's3 = s1 + s2'\n";
    s3.putarr();
    cout<<" INTERSECTION 's4 = s1 * s2'\n";
    s4.putarr();
    return 0;
}
