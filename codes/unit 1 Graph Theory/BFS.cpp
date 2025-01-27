#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];

void bfs(int start_node) {
    queue<int> q;
    vector<bool> visited(100, false);
    vector<int>dist(100, 1e9);
    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // process node
        for (auto &next_node : adj_list[node])
        {
            if (!visited[next_node])
            {
                q.push(next_node);
                dist[next_node] = dist[node] + 1;
                visited[next_node] = true;
            }
        }
    }
}