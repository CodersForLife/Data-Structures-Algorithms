#include<iostream>
#include<cmath>
using namespace std;
void merge(int A[],int p,int q,int r)
{
	int i,j,x,y;
	int n1=q-p+1;int n2=r-q;
	int B[n1],C[n2];
	for(i=0;i<n1;i++)
	{
		B[i]=A[p+i];
	}
	for(x=0;x<n2;x++)
	{
		C[x]=A[q+1+x];
	}int k;
	i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = p; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        A[k] = B[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        A[k] = C[j];
        j++;
        k++;
    }
}



void mergesort(int A[],int p,int r)
{int q;
	if(p>=r)
	{
		return;
	}
	else
	{
	     q=(p+r)/2;
		 mergesort(A,p,q);
		 mergesort(A,q+1,r);
		 merge(A,p,q,r);
	}
}

int main()
{
	int A[5],a;
	for(a=0;a<5;a++)
	cin>>A[a];
	mergesort(A,0,4);
	for(a=0;a<5;a++)
	cout<<A[a]<<" ";
	
}
