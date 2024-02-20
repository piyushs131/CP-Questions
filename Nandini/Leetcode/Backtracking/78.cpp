#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
       vector<vector<int> > ans;
        vector<int> v;
        sort(ans.begin(),ans.end());
        unordered_map<int,bool> vis;
        findAll(ans,v,nums,vis,0);
        return ans;
    }
    void findAll(vector<vector<int> > &ans,vector<int> &v,vector<int> &nums,unordered_map<int,bool> &vis,int ind)
    {
        ans.push_back(v);
        for(int i=ind ; i<nums.size() ; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                v.push_back(nums[i]);
                findAll(ans,v,nums,vis,i+1);
                v.pop_back();
                vis[i] = false;
            }
        }
    }
};