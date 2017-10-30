#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Minheap{
    public:
    vector<int> heap;
    int *key;
    int intialise(int v)
    {
       key=new int[v+1];
       for(int i=0;i<=v;i++)
       {
           key[i]=-1;
       }
      return 0;  
    }    
    int Minheapify(int);
    int parent(int i)
    {
        return (i-1)/2;
    }   
    int extract_min();
    int insert(int n,int dis);
};
int Minheap::extract_min()
{
    int root=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.resize(heap.size()-1);
    Minheapify(0);
return root;    
}    
int Minheap::insert(int n,int dis)
{
    int i;
    if(key[n]==-1)
    {
        key[n]=dis;
        heap.push_back(n);
        i=heap.size()-1;
    }
    else if(key[n]>dis)
    {
        key[n]=dis;
        for(int j=0;j<heap.size();j++)
        {
            if(heap[j]==n)
            {
                i=j;
                break;
            }    
        }    
    }
    else
    {
        return 0;
    }
    while(i!=0&&key[heap[i]]<key[heap[parent(i)]])
    {
        int temp=heap[i];
        heap[i]=heap[parent(i)];
        heap[parent(i)]=temp;
        i=parent(i);
    }
return 0;    
}    
int Minheap::Minheapify(int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int min;
    if(l<heap.size()&&key[heap[i]]>key[heap[l]])
        min=l;    
    else
        min=i;
    if(r<heap.size()&&key[heap[r]]<key[heap[min]])
        min=r;
    if(min!=i)
    {
        int temp=heap[i];
        heap[i]=heap[min];
        heap[min]=temp;
        Minheapify(min);
    }
return 0;    
}
class Graph: public Minheap{
    int V;
    list<pair<int,int> > *adj;
    public:
    Graph(int v)
    {
        V=v;
        adj=new list< pair<int,int> >[v+1];
        intialise(v);
    }    
    void addEdge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void Display();
    int MST(int );
};
void Graph::Display()
{
    for(int i=1;i<=V;i++)
    {
        cout<<i<<" -> ";
        list< pair<int,int> >::iterator k=adj[i].begin();
        while(k!=adj[i].end())
        {
            cout<<k->first<<" "<<k->second<<"  ";
            k++;
        } 
        cout<<endl;
    }
 return ;   
}
int Graph::MST(int s)
{
    bool* visited=new bool[V+1];
    for(int i=0;i<=V;i++)
    {
        visited[i]=false;
    }    
    key[s]=0;
    visited[s]=true;
    list<pair<int,int> >::iterator k=adj[s].begin();
    while(k!=adj[s].end())
    {
        insert(k->first,k->second+key[s]);
        k++;
    }
   /*for(int i=0;i<heap.size();i++)
        cout<<heap[i]<<" ";
    cout<<endl;*/
    //cout<<extract_min()<<endl;
    int sum=0;
    while(!heap.empty())
    {
        int num=extract_min();
        sum+=key[num];
        visited[num]=true;
        list<pair<int,int> >::iterator k=adj[num].begin();
        while(k!=adj[num].end())
        {
            if(visited[k->first]==false)
            {
                insert(k->first,k->second);   
            }   
            k++;
        }
    }
return sum;    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    scanf("%d %d",&n,&m);
    Graph g(n);
    while(m--)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g.addEdge(u,v,w);
    } 
    //g.Display();
    int s;
    cin>>s;
    cout<<g.MST(s)<<endl;;
    return 0;
}
