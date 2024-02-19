#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end()); 
        generateSubsets(result, subset, nums, 0);
        return result;
    }

    void generateSubsets(vector<vector<int>>& result, vector<int>& subset, const vector<int>& nums, int start) 
    {
        result.push_back(subset); 
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            
            subset.push_back(nums[i]);
            generateSubsets(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};
