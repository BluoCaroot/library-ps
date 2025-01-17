#include <bits/stdc++.h>
using namespace std;

int prime[100001];

void sieve()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * 2 /*i * i for optimizing*/; j <= 100000; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}