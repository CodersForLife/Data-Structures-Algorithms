/*
This program uses sparse matrix for general matrix operations
like multiplication, addition, transpose and display*/
#include<iostream>
using namespace std;
//The basic structure of sparse matrix
struct sparse_matrix
{
    int row;
    int col;
    int val;
};
//This function displays the given sparse matrix in normal matrix form
void sparsemat_output(sparse_matrix b[])
{
    int k=1;
    /*here we check for each row and column whether that no.
    is zero or not since sparse matrix has only non-zero
    elements and then display it accordingly*/
    for(int i=0;i<b[0].row;i++)
    {
        for(int j=0;j<b[0].col;j++)
        {
            if(i==b[k].row&&j==b[k].col)
            {
                cout<<b[k].val<<" ";
                k++;
            }
            else
            {
                cout<<0<<" ";
            }
        }
        if(i!=b[0].row-1)
        cout<<endl;
    }
}
//This function accepts the matrix input and stores it as a sparse matrix
void sparsemat_input(sparse_matrix b[],int m,int n)
{
    int cnt2=0;
    b[0].row=m;
    b[0].col=n;
    /*Here we simply add the non zero elements to sparse matrix row-wise*/
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            if(x!=0)
            {
                cnt2++;
                b[cnt2].row=i;
                b[cnt2].col=j;
                b[cnt2].val=x;
            }
        }
    }
    b[0].val=cnt2;
    //cout<<b[0].val<<endl;
}
//This function computes the sum of two sparse matrix
void sparsemat_sum(sparse_matrix a[],sparse_matrix b[],sparse_matrix sum[])
{
    int i=1,j=1,k=1;
    //cout<<a[0].val<<" "<<b[0].val;
    /* for performing addition operation we take two sparse matrices and
    perform a merge operation on them.*/
    while(i<=a[0].val&&j<=b[0].val)
    {
        if((a[i].row==b[j].row)&&(a[i].col==b[j].col))
        {
            sum[k].row=a[i].row;
            sum[k].col=a[i].col;
            sum[k].val=a[i].val+b[j].val;
            i++;j++;k++;
            //cout<<1<<" ";
        }
        else if((a[i].row<b[j].row)||((a[i].row==b[j].row)&&(a[i].col<b[j].col)))
        {
            sum[k].row=a[i].row;
            sum[k].col=a[i].col;
            sum[k].val=a[i].val;
            k++;
            i++;
            //cout<<2<<" ";
        }
        else
        {
            sum[k].row=b[j].row;
            sum[k].col=b[j].col;
            sum[k].val=b[j].val;
            k++;
            j++;
            //cout<<3<<" ";
        }
    }
    while(i<=a[0].val)
    {
        sum[k].row=a[i].row;
        sum[k].col=a[i].col;
        sum[k].val=a[i].val;
        k++;i++;
    }
    while(j<=b[0].val)
    {
        sum[k].row=a[j].row;
        sum[k].col=a[j].col;
        sum[k].val=a[j].val;
        k++;j++;
    }
    sum[0].row=a[0].row;
    sum[0].col=a[0].col;
    sum[0].val=k-1;
}

//This function is used to perform transpose operation on the given matrix
void sparsemat_transpose(sparse_matrix a[100])
{
    //here we have used counting sort to transpose the given matrix
    sparse_matrix b[100];
    int c[100],d[100];
    for(int i=0;i<a[0].col;i++)//Time complexity- O(n)
        c[i]=0;
    for(int i=1;i<=a[0].val;i++)//Time complexity- O(val)
    {
        c[a[i].col]++;
    }
    d[0]=0;
    for(int i=1;i<a[0].col;i++)//Time complexity- O(n)
    {
        d[i]=c[i-1]+d[i-1];
    }
    //using the counting sort we have sorted the elements of sparse matrix according to column and then interchanged the row and column
    for(int i=1;i<=a[0].val;i++)//Time complexity- O(val)
    {
        //here we have added 1 after d[a[i].col] because first position of the
        //structure is occupied
        b[d[a[i].col]+1].col=a[i].row;
        b[d[a[i].col]+1].row=a[i].col;
        b[d[a[i].col]+1].val=a[i].val;
        //cout<<d[a[i].col]<<" "<<a[i].val<<endl;
        d[a[i].col]++;
    }
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    b[0].val=a[0].val;
    //Finally we make the changes made to a temporary sparse matrix on the
    //original sparse matrix.
    for(int i=0;i<=a[0].val;i++)
    {
        a[i].col=b[i].col;
        a[i].row=b[i].row;
        a[i].val=b[i].val;
    }
}
//Used to multiply two sparse matrices(if the can be multiplied)
int sparsemat_mul(sparse_matrix a[],sparse_matrix b[],sparse_matrix mul[])
{
    if(a[0].col!=b[0].row)
    {
        cout<<"Wrong input";
        return 0;
    }
    mul[0].row=a[0].row;
    mul[0].col=b[0].col;
    sparsemat_transpose(b);
    int i=1,j=1,k=1;
    while(i!=a[0].val+1)
    {
        //cout<<i<<" ";
        int x,y;
        x=a[i].row;
        y=b[j].row;
        int m=0,sum=0;
        int ptr1=i,ptr2=j;
        while(a[ptr1].row==x&&b[ptr2].row==y)
        {
            if(a[ptr1].col<b[ptr2].col)
                ptr1++;
            else if(a[ptr1].col>b[ptr2].col)
                ptr2++;
            else
            {
                sum+=(a[ptr1].val*b[ptr2].val);
                ptr1++;
                ptr2++;
            }
        }
        if(sum!=0)
        {
            mul[k].row=x;
            mul[k].col=y;
            mul[k].val=sum;
           // cout<<x<<" "<<y<<" "<<sum<<endl;
            k++;
        }
        //added this while loop for the ptr2 pointer and changed its conditions
        while(b[ptr2].row==y&&ptr2!=b[0].val+1)
        {
            ptr2++;
        }
        j=ptr2;
        if(j==b[0].val+1)
        {
            //changed some conditions in the while loop conditions
            while(a[ptr1].row==x&&ptr1!=a[0].val+1)
            {
                ptr1++;
            }

            i=ptr1;
            j=1;
        }
    }
    mul[0].val=k-1;
    return 1;
}
int main()
{
    int m,n;
    sparse_matrix a[100],b[100],sum[100],mul[100];
    cout<<"Enter the dimensions of matrix 1:";
    cin>>m>>n;
    sparsemat_input(a,m,n);
    cout<<"Enter the dimensions of matrix 2:";
    cin>>m>>n;
    sparsemat_input(b,m,n);
    if(sparsemat_mul(a,b,mul))
    {
        cout<<"The required result is->"<<endl;
        sparsemat_output(mul);
    }
    return 0;
}
