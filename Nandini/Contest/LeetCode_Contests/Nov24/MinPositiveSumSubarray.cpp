#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) 
    {
       int n = nums.size(),ans=1e9,sum;
       for(int len =l ; len<=r ; len++)
       {
        sum=0;
        for(int i=0 ; i<n ; i++)
        {
            sum+= nums[i];
            if(i>=len-1)
            {
                if(sum>0) ans = min(ans,sum);
                sum-=nums[i-len+1];
            }
        }
       } 
       return ans==1e9?-1:ans;
    }
};