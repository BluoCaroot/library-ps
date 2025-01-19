#include <bits/stdc++.h>

using namespace std;


vector<int> prime_factors(int n)
{
    vector<int> factors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

vector<int> wheel_factor(int n)
{
    vector<int> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }
    while (n % 3 == 0)
    {
        factors.push_back(3);
        n /= 3;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
        while (n % (i + 2) == 0)
        {
            factors.push_back(i + 2);
            n /= i + 2;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

vector<int> pollard_rho(int n)
{
    vector<int> factors;
    if (n % 2 == 0)
    {
        factors.push_back(2);
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }
    while (n > 1)
    {
        int x = 2, y = 2, d = 1;
        auto f = [&](int x)
        {
            return (x * x + 1) % n;
        };
        while (d == 1)
        {
            x = f(x);
            y = f(f(y));
            d = __gcd(abs(x - y), n);
        }
        if (d == n)
        {
            factors.push_back(n);
            break;
        }
        factors.push_back(d);
        while (n % d == 0)
        {
            n /= d;
        }
    }
    return factors;
}
void fermat_method(int n)
{
    int a = ceil(sqrt(n)) ; 
    
    if(a * a == n) 
    { 
        cout <<  a << " " << a;
        return; 
    } 
    int b; 
    while(true) 
    { 
        int b1 = a * a - n ; 
        b = (int)sqrt(b1) ; 
            
        if(b * b == b1) 
            break; 
        else
            a += 1; 
    } 
    cout << (a - b) << " " << (a + b); 
    return; 

}