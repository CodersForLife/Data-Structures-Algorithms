#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,s,e) for(ll i=s;i<=e;i++)
#define aspro ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define pii pair<int,int>
#define si(a) scanf("%d",&a)
#define INF 1000000000
#define MOD 1000000007
#define N 1000000
#define test int t;cin>>t;while(t--)
int arr[10000],lazy[10000],tree[100000];
/*lazy of same size of tree,intially all elements of lazy will be 0,
If there is non-zero element lazy[k] then this element needs to update
node k in the segment tree before making any query operation.*/
void build(int node,int lo,int hi)
{
    if(hi==lo)
    {
        tree[node]=arr[lo];
        return ;
    }
    int mid = (lo+hi)/2;
    build(2*node,lo,mid);
    build(2*node+1,mid+1,hi);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void refresh( int node,int st,int en)
{
    if(lazy[node])
    {
        if (lazy[node]) tree[node]=(en-st+1)*lazy[node];
        else  tree[node] = 0;
        if (st!=en)
        {
            lazy[2*node]  = lazy[node];
            lazy[2*node+1]= lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int node,int st,int en,int l,int r,int val )
{
    if ( st > en || st > r || en < l )
    {
        refresh( node, st, en );
        return;
    }
    if ( st >= l && en <= r )
    {
        lazy[ node ] = val;
        refresh( node, st, en );
        return;
    }
    refresh( node, st, en );
    int mid=(st+en)/2;
    update( 2*node,st, mid,l,r,val );
    update( 2*node+1,mid+1,en,l,r,val );
    if ( st != en )
    {
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query( int node, int st, int en, int l, int r )
{
    if ( st > en || st > r || en < l )
    {
        return 0;
    }
    refresh( node, st, en );
    if(st>=l&&en<=r)  return tree[node];
    int mid=(st+en)/2;
    int x=query(2*node,st,mid,l,r);
    int y=query(2*node+1,mid+1,en,l,r);
    return x+y;
}
int main()
{
    int n,m,x,y,type,v,ans;
    cin>>n;
    f(i,1,n) cin>>arr[i];
    build(1,1,n);
    f(i,1,2*n-1) cout<<tree[i]<<" ";cout<<endl;
    cin>>m;
    while(m--)
    {
        f(j,1,n) cout<<arr[j]<<" ";cout<<endl;
        f(j,1,80) cout<<seg[j]<<" ";cout<<endl;
        f(j,1,80) cout<<lazy[j]<<" ";cout<<endl;
        cin>>type>>x>>y;
        if(type)
        {
            //ans=query(1,1,n,x,y);
            ans=query(1,1,n,x,y);
            printf("%d\n",ans);
        }
        else
        {
            cin>>v;
            update(1,1,n,x,y,v);//incrase every value by v.
        }
    }
}


