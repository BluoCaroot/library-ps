#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>&a, vector<int>&b){
    vector<int> res;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }else{
            res.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()){
        res.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        res.push_back(b[j]);
        j++;
    }
    return res;
}
void merge_sort(vector<int>&a){
    if(a.size() == 1){
        return;
    }
    vector<int> left(a.begin(), a.begin() + a.size()/2);
    vector<int> right(a.begin() + a.size()/2, a.end());
    merge_sort(left);
    merge_sort(right);
    a = merge(left, right);
}