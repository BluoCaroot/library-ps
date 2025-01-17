#include <bits/stdc++.h>
using namespace std;


vector<int> state;

void backtrack(int n, int k)
{
    if (state.size() == k)
    {
        // check if valid state
        return;
    }

    int start = state.empty() ? 1 : state.back() + 1;
    for (int i = start; i <= n; i++)
    {
        state.push_back(i);
        backtrack(n, k);
        state.pop_back();
    }
}