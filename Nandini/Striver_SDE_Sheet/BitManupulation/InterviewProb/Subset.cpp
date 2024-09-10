#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
       vector<vector<int> > ans;
       int n = nums.size();
       // 2^n value in num
       int num = 1 << n; 
       for(int i=0 ; i<num ; i++)
       {
         vector<int> v;
         for(int ind =0 ; ind<n ; ind++)
         {
            // checking indth bit set or not
            if( i &(1<<ind))
            {
                v.push_back(nums[ind]);
            }
         }
         ans.push_back(v);
       }
       return ans;
    }
};