#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

pair<int,int> minmax(int x,int y)
{
    pair<int,int> ret;
    if(x<y)
        ret=make_pair(x,y);
    else
        ret=make_pair(y,x);
    
    return ret;
}

void dfs(int vertex,int vistime,vector<vector<int> >& adjList,
    vector<pair<int,int> >& bridges, vector<int>& parent,
    vector<bool>& visited, vector<int>& low, vector<int>& discoveryTime)
{
    visited[vertex]=1;
    discoveryTime[vertex]=low[vertex]=vistime;
    int child=0;
    for(int i=0;i<(int)adjList[vertex].size();i++)
        if(!visited[adjList[vertex][i]])
        {
            child++;
            parent[adjList[vertex][i]]=vertex;
            dfs(adjList[vertex][i],vistime+1,adjList,bridges,parent,visited,low,discoveryTime);
            low[vertex]=min(low[vertex],low[adjList[vertex][i]]);
            if(parent[vertex]==-1)
                bridges.push_back(minmax(vertex,adjList[vertex][i]));
            else if(low[adjList[vertex][i]]>discoveryTime[vertex])
                bridges.push_back(minmax(vertex,adjList[vertex][i]));
            
        }
        else if(parent[vertex]!=adjList[vertex][i])
            low[vertex]=min(low[vertex],discoveryTime[adjList[vertex][i]]);
            
}


int main()
{
    int n,m,x,y;
    
    cin >> n >> m; // n: number of vertex , m: number of edges

    vector<vector<int> > adjList(n);

    for(int i=0;i<m;i++){
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    vector<pair<int,int> > bridges;
    vector<int> parent(n,-1);
    vector<bool> visited(n,0);
    vector<int> low(n),discoveryTime(n);

    dfs(0,0,adjList,bridges,parent,visited,low,discoveryTime);

    sort(bridges.begin(),bridges.end());

    cout << bridges.size() << endl;
    for(int i=0;i<bridges.size();i++)
        cout << bridges[i].first << " " << bridges[i].second << endl;
    
    return 0;
}

