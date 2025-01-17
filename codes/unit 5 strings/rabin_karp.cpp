#include <bits/stdc++.h>
using namespace std;

int rabin_karp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    int p = 31;
    int mod = 1e9 + 9;
    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    long long h_s = 0;
    for (int i = 0; i < m; i++)
    {
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    vector<int> occurences;
    for (int i = 0; i + m - 1 < n; i++)
    {
        long long cur_h = (h[i + m] + mod - h[i]) % mod;
        if (cur_h == h_s * p_pow[i] % mod)
        {
            occurences.push_back(i);
        }
    }
    return occurences.size();
}