#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> edge_list;

void add_edge(int u, int v, int weight)
{
    edge_list.emplace_back(make_pair(u, v), weight);
    // edge_list.emplace_back(make_pair(v, u), weight); if the graph is undirected
}
