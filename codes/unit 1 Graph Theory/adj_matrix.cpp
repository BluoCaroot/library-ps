#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_matrix(100, vector<int>(100, 0));

void add_edge(int u, int v, int weight = 1)
{
    adj_matrix[u][v] = weight;
    // adj_matrix[v][u] = weight; if the graph is undirected
}
