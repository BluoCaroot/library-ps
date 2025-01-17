#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];

void dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    // Pre-order process 
    for (auto &next_node : adj_list[node])
    {
        if (!visited[next_node])
        {
            dfs(next_node, visited);
            // in-order process
        }
    }
    // post-order process
}