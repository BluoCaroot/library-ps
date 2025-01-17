#include <bits/stdc++.h>
using namespace std;

int binary_search_on_answer(int l, int r)
{
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (/* condition */)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int binary_search_on_array(vector<int>&arr, int target)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}