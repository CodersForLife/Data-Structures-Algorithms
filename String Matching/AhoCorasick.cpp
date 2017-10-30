// Code for problem 696 D on Codeforces, example usage of Aho Corasick
#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 210
#define ALPHA 26
#define INF 1000000000000000000ll

// Aho Corasick Algorithm
int node_cnt=0;
int sufflink[N],parent[N],Char[N];
int Link[N][ALPHA],Next[N][ALPHA];
ll score[N];//summation of required value for all suffixes of string ending at current node
vector<int> End[N];//list of patterns ending here

//extra Data structures
ll a[N];
ll mat[N][N];
ll ans[N][N];


int suff(int n);
int traverse(int cur,int c) //returns Next state for (cur,c)
{
	if(Next[cur][c]!=-1)
		return Next[cur][c];
	if(!cur)
		return Next[cur][c]=(Link[cur][c]!=-1 ? Link[cur][c] :0);
	return Next[cur][c]=(Link[cur][c]==-1 ? traverse(suff(cur),c) : Link[cur][c]);
}
int suff(int cur) //returns suffix link
{
	if(sufflink[cur]!=-1)
		return sufflink[cur];
	if(!parent[cur])
		return sufflink[cur]=0;
	return sufflink[cur]=traverse(suff(parent[cur]),Char[cur]);
}

// calculates summation over all suffixes of string ending at current node
inline ll calc(int cur)
{
	if(score[cur]!=-1)
		return score[cur];
	if(!cur)
		return score[cur]=0;
	ll ret=0;
	for(auto x:End[cur])
		ret+=a[x];
	return ret+calc(suff(cur));
}

void go(int cur)  //precomputes Next and sufflink for all states
{
	if(cur==-1)
		return;
	suff(cur);
	calc(cur);//extra problem specific calculation
	for(int i=0;i<ALPHA;i++)
	{
		traverse(cur,i);
		go(Link[cur][i]);
	}
}


//Pay attention to characters in alphabet
void add(string s,int idx)
{
	int cur=0;
	for(int i=0;i<s.length();++i)
	{
		if(Link[cur][s[i]-'a']==-1)
		{
			Link[cur][s[i]-'a']=++node_cnt;
			parent[node_cnt]=cur;
			Char[node_cnt]=s[i]-'a';
		}
		cur=Link[cur][s[i]-'a'];
	}
	End[cur].PB(idx);
}
void init()
{
	node_cnt=0;
	for(int i=0;i<N;++i)
	{
		sufflink[i]=-1;
		score[i]=-1;
		for(int j=0;j<ALPHA;++j)
		{
			Link[i][j]=-1;
			Next[i][j]=-1;
		}
	}
	sufflink[0]=parent[0]=Char[0]=0;
}


//extra problem specific functions
void mul(ll a[][N],ll b[][N],ll c[][N])
{
	int i,j,k;
	for(int i=0;i<=node_cnt;++i)
		for(int j=0;j<=node_cnt;++j)
			c[i][j]=-INF;
	for(i=0;i<=node_cnt;++i)
		for(j=0;j<=node_cnt;++j)
			for(k=0;k<=node_cnt;++k)
				c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
}
inline void copy(ll a[][N],ll b[][N])
{
	int i,j;
	for(i=0;i<=node_cnt;i++)
		for(j=0;j<=node_cnt;j++)
			b[i][j]=a[i][j];
}
void matpow(ll a[][N],ll p,ll c[][N])
{
	int i,j;
	if(p==0)
	{
		for(i=0;i<=node_cnt;++i)
			for(j=0;j<=node_cnt;++j)
				c[i][j]=-INF;
		for(i=0;i<=node_cnt;++i)
			c[i][i]=0;
		return;
	}
	ll temp[N][N];
	matpow(a,p/2,temp);
	mul(temp,temp,c);
	if(p&1)
	{
		copy(c,temp);
		mul(a,temp,c);
		return;
	}
}
int main()
{
	int n,i,j;
	ll l;
	sd(n);sl(l);

	//extra input
	for(i=0;i<n;++i)
		sl(a[i]);

	//initialize
	init();

	//add
	for(i=0;i<n;++i)
	{
		string s;
		cin>>s;
		add(s,i);
	}
	//precompute
	go(0);

	//extra problem specific code
	for(i=0;i<=node_cnt;++i)
	{
		for(j=0;j<=node_cnt;++j)
			mat[j][i]=-INF;
		for(j=0;j<ALPHA;++j)
			mat[Next[i][j]][i]=calc(Next[i][j]);
	}
	matpow(mat,l,ans);
	ll maxx=0;
	for(i=0;i<=node_cnt;++i)
		maxx=max(maxx,ans[i][0]);
	printf("%lld\n",maxx);
}