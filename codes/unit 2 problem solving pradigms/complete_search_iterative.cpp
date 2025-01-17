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

void bitmasking_complete_search(vector<int>&a)
{
    for (int mask = 0; mask < (1 << a.size()); mask++)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (mask & (1 << i))
            {
                // do something
            }
        }
    }
}
