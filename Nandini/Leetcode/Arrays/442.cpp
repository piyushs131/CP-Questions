// https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        int i;
        int n = nums.size();
        for(i=0 ; i<n ;i ++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] == 2)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};