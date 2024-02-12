#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> > ans;
        vector<int> v;
        int n = nums.size();
        unordered_map<int,bool> vis;
        findAll(ans,v,vis,nums,n);
        return ans;
    }
    void findAll(vector<vector<int> > &ans,vector<int> v,unordered_map<int,bool> &vis,vector<int> &nums,int &n)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return ;
        }
        int i;
        for( i=0 ; i<n ; i++)
        {
            if(!vis[nums[i]])
            {
                vis[nums[i]] = true;
                v.push_back(nums[i]);
                findAll(ans,v,vis,nums,n);
                v.pop_back();
                vis[nums[i]] = false;
            }
        }
    }
};