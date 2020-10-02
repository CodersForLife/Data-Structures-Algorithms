/*
  Check for cycle
  Author: Johnny Villegas
  Github: Jvillegasd
*/

#include <bits/stdc++.h>

using namespace std;

int NUM_NODES = 100
vector<int> g[NUM_NODES];
int visited[NUM_NODES];

bool DFS(int u) {
  visited[u] = 1;
  for(auto v : g[u]) {
    if (!visited[v]) {
      if (DFS(v)) {
        return true;
      }
    } else if (visited[v] == 1) {
      printf("Cycle detected, starting from %d and ending in %d", u, v);
      return true;
    }
  }
  visited[u] = 2;
  return false;
}

void find_cycle() {
  bool has_cycle = false;
  memset(visited, 0, sizeof(visited));
  for (int u = 1; u <= NUM_NODES; u++) {
    if (visited[u] == 0 && DFS(u)) {
      has_cycle = true;
      break;
    }
  }
  if (has_cycle) {
    printf("The graph has a cycle!");
  } else {
    printf("The graph has not a cycle!");
  }
}

int main() {
  find_cycle();
  return 0;
} 