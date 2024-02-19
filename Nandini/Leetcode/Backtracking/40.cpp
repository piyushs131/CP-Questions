#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        findCombinations(result, path, candidates, target, 0);
        return result;
    }

    void findCombinations(vector<vector<int>>& result, vector<int>& path, const vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i == start || candidates[i] != candidates[i - 1]) 
            { 
                path.push_back(candidates[i]);
                findCombinations(result, path, candidates, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }
};
