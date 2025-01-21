#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[100];

vector<int> dijkstra(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(100, INT_MAX);
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int node_dist = -pq.top().first;
        pq.pop();
        if (node_dist > dist[node])
            continue;
        for (auto &[next_node, edge_weight] : adj_list[node])
        {
            int next_dist = node_dist + edge_weight;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    return dist;
}