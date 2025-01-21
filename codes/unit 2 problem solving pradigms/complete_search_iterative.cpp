#include <bits/stdc++.h>
using namespace std;

void complete_search(vector<int>&a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            // add more nested loops if needed.
            // do something
        }
    }
}
bool bit_set(int i, int n)
{
    return (n & (1 << i));
}
void bitmasking_complete_search(vector<int>&a)
{
    for (int mask = 0; mask < (1 << a.size()); mask++)
    {
        vector<int>temp;
        for (int i = 0; i < a.size(); i++)
        {
            if (bit_set(i, mask))
            {
                temp.push_back(a[i]);
                // do something
            }
        }
        for (auto &i : temp)
            cout << i << ' ';
    }
}
