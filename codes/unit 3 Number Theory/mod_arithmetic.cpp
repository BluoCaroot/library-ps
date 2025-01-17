#include <bits/stdc++.h>
using namespace std;

int bin_pow(int base, int power, int mod)
{
    int result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}

int inv_mod(int a, int m)
{
    return bin_pow(a, m - 2, m);
}
int add(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
int sub(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    return (a - b + mod) % mod;
}
int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

int div(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    assert(gcd(b, mod) == 1);
    return (a * inv_mod(b, mod)) % mod;
}