#include<bits/stdc++.h>
using namespace std;
#define N 100

int visited[N];

void dfs_iterative(vector<int> graph[], int node){
  stack<int> stack_dfs;
  stack_dfs.push(node);
  visited[node] = 1;
  
  int cur_node;
  while(!stack_dfs.empty()){
    cur_node = stack_dfs.top();
    stack_dfs.pop();
    cout<<cur_node<<" ";
    for(int i = 0; i<graph[cur_node].size(); i++){
      if(visited[graph[cur_node][i]] == 0){
        visited[graph[cur_node][i]] = 1;
        stack_dfs.push(graph[cur_node][i]);
      }
    }
  } 
}

void dfs(vector<int> graph[], int node) {
  if(visited[node] == 1)
    return;

  // Else
  visited[node]=1;
  cout<<node<<" ";
  for(int i=0;i<graph[node].size();i++) {
    dfs(graph, graph[node][i]);
  }
}

void initialize() {
  for(int i=1;i<=5;i++)
    visited[i]=0;
}

int main() {

  // Making a graph(number of nodes = 5) using adjacency list
  vector<int> graph[6];
  graph[1].push_back(2);
  graph[1].push_back(4);
  graph[2].push_back(1);
  graph[2].push_back(3);
  graph[2].push_back(5);
  graph[3].push_back(2);
  graph[3].push_back(5);
  graph[4].push_back(1);
  graph[5].push_back(2);
  graph[5].push_back(3);

  // Initially no node is visited
  initialize();

  dfs(graph,1);

  return 0;
}
