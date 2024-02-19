#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        generateCombinations(result, path, n, k, 1); 
        return result;
    }

    void generateCombinations(vector<vector<int>>& result, vector<int>& path, int n, int k, int start) 
    {
        if (k == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n - k + 1; ++i) 
        {
            path.push_back(i);
            generateCombinations(result, path, n, k - 1, i + 1);
            path.pop_back();
        }
    }
};
