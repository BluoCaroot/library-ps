#include <bits/stdc++.h>
using namespace std;

int lcp(string a, string b)
{
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return i;
        }
    }
    return n;
}

int lcp (vector<string>v)
{
    sort(v.begin(), v.end());
    int res = lcp(v[0], v[v.size() - 1]);
    return res;
}