//written by hg398

#include <bits/stdc++.h>
using namespace std;
vector <int> adj[100000];                                            //vector to implement graph using adjacency lists (size can vary a/c to need)
bool mark[100000];                                                   //array to keep record of visited nodes
void bfs(int s)
{
    queue <int> q;                                                   // Create a queue for BFS
    mark[s] = true;                                                  // Mark the current node as visited and enqueue it
    q.push(s);
                                                
    while(!q.empty())
    {
        s = q.front();                                               // Dequeue a vertex from queue and print it
        cout << s+1 << " ";
        q.pop();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(int i = 0; i < adj[s].size(); ++i)
        {
            if(!mark[adj[s][i]])
            {
                mark[adj[s][i]] = true;
                q.push(adj[s][i]);
            }
        }
    }
}

int main() {
	int nodes,edges;                                                 //no. of nodes and edges in graph
	cin>>nodes>>edges;
	while(edges--)
	{
		int a,b;                                                     //vertices between which an edge exist
		cin>>a>>b;
		a--;b--;                                                     //0-based indexing
		adj[a].push_back(b);                                         //adding b to adjacency list of a to which it is directly connected 
		adj[b].push_back(a);                                         //adding a to adjacency list of b to which it is directly connected
	}
	memset(mark,false,sizeof(mark));                                 //marking all vertices unvisited
	int source;                                                      //source node
	cin>>source;
	bfs(source);                                                           
	return 0;
}
