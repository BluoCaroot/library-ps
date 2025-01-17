#include <bits/stdc++.h>
using namespace std;

int dp[100];

int lis(vector<int> &arr, int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[n])
        {
            dp[n] = max(dp[n], 1 + lis(arr, i));
        }
    }
    return dp[n];
}
int lis_iterative(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int lis_binary_search(vector<int> &arr, int n)
{
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }
    }
    return dp.size();
}