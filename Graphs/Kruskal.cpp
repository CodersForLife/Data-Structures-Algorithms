#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int sort(int*,int*,int*,int,int);
int merge(int*,int*,int*,int,int,int);

int make_set(int p[],int r[],int i)
{
    p[i]=i;
    r[i]=0;
return 0;    
}
int find(int p[],int i)
{
    if(p[i]!=i)
    {
        p[i]=find(p,p[i]);
    }
return p[i];    
}    
int Union(int p[],int r[],int i,int j)
{
    int x=find(p,i);
    int y=find(p,j);
    if(x!=y)
    {
        if(r[x]>r[y])
        {
            p[y]=x;
        }    
        else
        {
            p[x]=y;
            if(r[x]==r[y])
            {
                r[j]+=1;
            }    
        }
        return 1;
    }
return 0;    
}    
int main()
{
    int n,m;
    cin>>n>>m;
    int U[m],V[m],W[m];
    int p[n+1];
    int r[n+1];
    for(int i=0;i<m;i++)
    {
         cin>>U[i]>>V[i]>>W[i];
    }
    int s;
    cin>>s;
    sort(U,V,W,0,m-1);
    for(int i=1;i<=n;i++)
    {
        make_set(p,r,i);
    }
    int sum=0;
    for(int i=0;i<m;i++)
    {
       
       int x=Union(p,r,U[i],V[i]);
       if(x==1)
       {
           sum+=W[i];
       }
    } 
    cout<<sum<<endl;
return 0;    
}
int sort(int U[],int V[],int W[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        sort(U,V,W,p,q);
        sort(U,V,W,q+1,r);
        merge(U,V,W,p,q,r);
    }
return 0;    
}    
int merge(int U[],int V[],int W[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int left[n1],right[n2];
    int leftu[n1],rightu[n2];
    int leftv[n1],rightv[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=W[i+p];
        leftu[i]=U[i+p];
        leftv[i]=V[i+p];
    }    
    for(int i=0;i<n2;i++)
    {
        right[i]=W[i+q+1];
        rightu[i]=U[i+q+1];
        rightv[i]=V[i+q+1];
    }
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])
        {
            W[k+p]=left[i];
            U[k+p]=leftu[i];
            V[k+p]=leftv[i];
            i++;
            k++;
        }    
        else
        {
            W[k+p]=right[j];
            U[k+p]=rightu[j];
            V[k+p]=rightv[j];
            j++;
            k++;
        }    
    }    
    while(i<n1)
    {
        W[k+p]=left[i];
        U[k+p]=leftu[i];
        V[k+p]=leftv[i];
        k++;
        i++;
    }    
    while(i<n2)
    {
        W[k+p]=right[j];
        U[k+p]=rightu[j];
        V[k+p]=rightv[j];
        j++;
        k++;
    }    
return 0;
}