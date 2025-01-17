#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> activities;

void activity_selection(vector<pair<int, int>> &activities)
{
    sort(activities.begin(), activities.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });
    int n = activities.size();
    int i = 0;
    cout << "Selected activities are: ";
    cout << "(" << activities[i].first << ", " << activities[i].second << ") ";
    for (int j = 1; j < n; j++)
    {
        if (activities[j].first >= activities[i].second)
        {
            cout << "(" << activities[j].first << ", " << activities[j].second << ") ";
            i = j;
        }
    }
}
