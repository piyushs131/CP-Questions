#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& v) {
        int n = arr.size();
        vector<vector<int>> ans;
        
        int i = 0;
        while (i < n && arr[i][1] < v[0]) {
            ans.push_back(arr[i]);
            i++;
        }
        
        while (i < n && arr[i][0] <= v[1]) {
            v[0] = min(v[0], arr[i][0]);
            v[1] = max(v[1], arr[i][1]);
            i++;
        }
        ans.push_back(v);
        
        while (i < n) {
            ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
    }
};