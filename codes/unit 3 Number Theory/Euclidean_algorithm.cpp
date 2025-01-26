#include <bits/stdc++.h>
using namespace std;


int gcd_recursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_recursive(b, a % b);
}
int gcd_iterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int extended_euclidean_algorithm(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean_algorithm(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


