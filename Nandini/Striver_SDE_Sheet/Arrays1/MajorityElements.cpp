#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        int val = floor(n/3.0);
        map<int,int> mp;
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            if(it.second>val)
            ans.push_back(it.first);
        }
        return ans;
    }
};