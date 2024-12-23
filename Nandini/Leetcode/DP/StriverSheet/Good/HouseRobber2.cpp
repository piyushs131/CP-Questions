#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) 
    {
      vector<int> temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0 ; i<n ; i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(findNum(temp1),findNum(temp2));
    }
    int findNum(vector<int> &v)
    {
        vector<int> dp(v.size()+1,-1);
        int prev1 = v[0],prev2 = 0;
        for(int i=1 ;i<v.size() ;i++)
        {
            int take = v[i];
            int notTake = prev1;
            if(i>1)
            {
                take+=prev2;
            }
            int curr = max(take,notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};