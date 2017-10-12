#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <climits>
#include <algorithm>
using namespace std;
class Graph{
    int V;
    int *key;
    int *index;
    vector<int> heap;
    list< pair<int,int> > *adj;
    public:
    Graph(int v)
    {
        V=v;
        adj=new list< pair<int,int> >[v+1];
        key=new int[v+1];
        index=new int[v+1];
    }
    void addEdge(int u,int v,int w)
    {
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
    }
    int Display();
    int Dijkstra(int s);
    int Minheapify(int s);
    int insert(int ,int);
    int extract_min();
    int parent(int i)
    {
        return (i-1)/2;
    }    
};
int Graph::Display()
{
   for(int i=1;i<=V;i++)
   {
       list< pair<int,int> >::iterator k=adj[i].begin();
       cout<<i<<" -> ";
       while(k!=adj[i].end())
       {
           cout<<k->first<<" ";
           k++;
       }    
       cout<<endl;
   }
 return 0;   
}
int Graph::Dijkstra(int s)
{
    bool* visited=new bool[V+1];
    for(int i=1;i<=V;i++)
    {
        index[i]=-1;
        visited[i]=false;
        key[i]=-1;
    }
    visited[s]=true;
    key[s]=0;
    list<pair<int,int> >::iterator k=adj[s].begin();
    while(k!=adj[s].end())
    {
        insert(k->first,k->second+key[s]);
        k++;
    }
    while(!heap.empty())
    {
       int num=extract_min();
       visited[num]=true; 
       list<pair<int ,int> >::iterator k=adj[num].begin();
       while(k!=adj[num].end())
       {
            if(visited[k->first]==false)
              insert(k->first,k->second+key[num]);
           k++;
       }
    }
    for(int i=1;i<=V;i++)
    {
        if(s!=i)
            printf("%d ",key[i]);
    }    
    printf("\n");
return 0;    
}
int Graph::Minheapify(int i)
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
int Graph::extract_min()
{
    int root=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.resize(heap.size()-1);
    Minheapify(0);
return root; 
}    
int Graph::insert(int n,int dis)
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
int main() {
    
    int nodes,edges;
    scanf("%d",&nodes);
    scanf("%d",&edges);
    Graph g(nodes);
    while(edges--)
    {
        int u,v,w;
        scanf("%d",&u);
        scanf("%d",&v);
        scanf("%d",&w);
        g.addEdge(u,v,w);
    }
    int source;
    cin>>source;    
    g.Dijkstra(source);
    return 0;
}
