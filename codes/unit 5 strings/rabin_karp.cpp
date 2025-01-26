#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
int rabin_karp(string text, string pattern)
{
    int n = text.length(), m = pattern.length();
    const int p = 31;
    const int MOD = 1e9 + 9;
    int i = 0, j = m - 1;
    int h = 0, h_t = 0;
    while (i < m)
    {
        h_t = (h_t * p + text[i]) % MOD;
        h = (h * p + pattern[i]) % MOD;
        i++;
    }
    i = 0;
    int ans = 0;
    while (i + m <= n)
    {
        if (j != i + m - 1)
        {
            h_t = (h_t * p + text[j + 1]) % MOD;
            j++;
        }
        if (h_t == h)
            ans++;
        h_t = (h_t - text[i] * modpow(p, m - 1, MOD) % MOD + MOD) % MOD;
        i++;
    }
    return ans;
}
