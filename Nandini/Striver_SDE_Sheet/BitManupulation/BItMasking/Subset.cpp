// bit masking
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
       vector<vector<int> > ans;
       int n = nums.size();
       // 2^n value in num
       int num = 1 << n; //8 in first case
       for(int i=0 ; i<num ; i++)
       {
         vector<int> v;
         // 0 to 3 loop
         for(int ind =0 ; ind<n ; ind++)
         {
            // checking indth bit set or not
            // if i=1 then 1 push back only as i= 0 0 1 so first index bit is set 
            if(i &(1<<ind))
            {
                v.push_back(nums[ind]);
            }
         }
         ans.push_back(v);
       }
       return ans;
    }
};