#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; //Maximum number of vertices in the graph
vector<int>graph[MAXN];
bool isVisited[MAXN];
int edges;
int vertex1, vertex2;
void DepthFirstSearch(int node)
{
	if(isVisited[node]) return; //if the node has already been visited return.
	isVisited[node] = true; //set the node as visited;
	cout<<node<<" ";
	for(int child = 0; child < graph[node].size(); child++){
		DepthFirstSearch(graph[node][child]);
	}
}
int main()
{

	//cout<<"Enter the number of edges"<<endl;
	cin>>edges;
	for(int i=0; i<edges; i++){
		cin>>vertex1>>vertex2;
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1); // Undirected graph.
	}
	int source;
	cin>>source;
	DepthFirstSearch(source);
	cout<<endl;
	return 0;
}