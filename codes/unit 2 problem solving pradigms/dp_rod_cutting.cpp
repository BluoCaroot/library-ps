#include <bits/stdc++.h>
using namespace std;

int dp[100];

int rod_cutting(int n, vector<int> &price)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = n == 0 ? 0 : INT_MIN;
    if (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[n] = max(dp[n], price[i] + rod_cutting(n - i, price));
        }
    }
    return dp[n];
}

int rod_cutting_iterative(int n, vector<int> &price)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], price[j] + dp[i - j]);
        }
    }
    return dp[n];
}