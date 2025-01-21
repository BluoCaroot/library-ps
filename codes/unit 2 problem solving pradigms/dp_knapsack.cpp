#include <bits/stdc++.h>
using namespace std;

int dp[100][10000];

int solve_knapsack_recursive(vector<int> &weights, vector<int> &values, int ind, int weight) {
    if (ind >= weights.size() || weight == 0)
        return 0;
    if (dp[ind][weight] != -1)
        return dp[ind][weight];
    if (weights[ind] > weight)
        return dp[ind][weight] = solve_knapsack_recursive(weights, values, ind + 1, weight);
    return dp[ind][weight] = max(solve_knapsack_recursive(weights, values, ind + 1, weight),
        solve_knapsack_recursive(weights, values, ind + 1, weight - weights[ind]) + values[ind]);
}

int solve_knapsack(vector<int> &weights, vector<int> &values, int w) {
    int n = weights.size();
    vector<vector<int>>dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = w; j >= 0; --j) {
            if (weights[i - 1] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int solve_knapsack_memory_reduction(vector<int> &weights, vector<int> &values, int w) {
    int n = weights.size();
    vector<int>dp(w + 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = w; j >= 0; --j)
            if (weights[i - 1] <= j)
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    return dp[w];
}
