#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[100];

vector<int> bellman_ford(int start, int end)
{
    vector<int> dist(100, INT_MAX);
    dist[start] = 0;
    for (int i = 0; i < 100 - 1; i++)
    {
        for (int node = 0; node < 100; node++)
        {
            for (auto &[next_node, edge_weight] : adj_list[node])
            {
                if (dist[node] + edge_weight < dist[next_node])
                {
                    dist[next_node] = dist[node] + edge_weight;
                }
            }
        }
    }
    return dist;
}