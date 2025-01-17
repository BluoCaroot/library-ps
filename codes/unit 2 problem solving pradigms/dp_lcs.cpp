#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs_recursive(string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + lcs_recursive(s1, s2, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(lcs_recursive(s1, s2, n - 1, m), lcs_recursive(s1, s2, n, m - 1));
    }
}

int lcs(string &s1, string &s2, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}