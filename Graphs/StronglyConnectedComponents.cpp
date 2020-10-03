/*
  Strongly Connected Components
  Author: Johnny Villegas
  Github: Jvillegasd
*/

#include <bits/stdc++.h>

using namespace std;

int NUM_NODES = 100
vector<int> g[NUM_NODES], rg[NUM_NODES];
bool visited[NUM_NODES];
stack<int> s;

void DFS(int u) {
  visited[u] = true;
  for(auto v : g[u]) {
    if (!visited[v]) {
      DFS(v);
    }
  }
  s.push(u);
}

void DFS_inv(int u) {
  visited[u] = true;
  print("Node: %d\n", u);
  for(auto v : rg[u]) {
    if (!visited[v]) {
      DFS_inv(v);
    }
  }
}

void SCC() {
  int comp = 1;
  for (int u = 1; u <= NUM_NODES; u++) {
    if (!visited[u]) {
      DFS(u);
    }
  }
  memset(visited, 0, sizeof(visited));
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    if (visited[u]) {
      continue;
    }
    printf("Component #%d:\n", comp++);
    DFS_inv(u);
    printf("\n");
  }
}

int main() {
  //Fill the DAG and reverse DAG

  SSC();
  return 0;
}
