#include <bits/stdc++.h>
using namespace std;

int hashes[100];
int powers[100];

int hash_string(string s)
{
    int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash += (s[i] - 'a' + 1) * powers[i];
    }
    return hash;
}

void pre()
{
    powers[0] = 1;
    for (int i = 1; i < 100; i++)
    {
        powers[i] = powers[i - 1] * 31;
    }
}

void hash(string s)
{
    hashes[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i)
    {
        hashes[i] = hashes[i - 1] + (s[i] - 'a' + 1) * powers[i];
    }
}

int get_hash(int l, int r)
{
    if (l == 0)
    {
        return hashes[r];
    }
    return (hashes[r] - hashes[l - 1]) / powers[l];
}