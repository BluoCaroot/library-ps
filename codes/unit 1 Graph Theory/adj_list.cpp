#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> adj_list[100];


void add_edge(int u, int v, int weight)
{
    adj_list[u].emplace_back(v, weight);
    // adj_list[v].emplace_back(u, weight); if the graph is undirected
}
