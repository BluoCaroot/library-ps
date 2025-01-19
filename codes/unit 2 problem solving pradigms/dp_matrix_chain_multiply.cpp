#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrix_chain_multiply(vector<int> &arr, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrix_chain_multiply(arr, i, k) + matrix_chain_multiply(arr, k, j) + arr[i] * arr[k] * arr[j]);
    }
    return dp[i][j];
}
