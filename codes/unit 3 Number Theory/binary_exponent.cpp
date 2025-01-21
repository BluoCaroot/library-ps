#include <bits/stdc++.h>
using namespace std;

int binary_exponentiation_recursive(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    int result = binary_exponentiation_recursive(base, power / 2);
    if (power % 2 == 0)
    {
        return result * result;
    }
    else
    {
        return result * result * base;
    }
}

int binary_exponentiation_iterative(int base, int power)
{
    int result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = result * base; 
        }
        base = base * base;
        power = power / 2;
    }
    return result;
}
