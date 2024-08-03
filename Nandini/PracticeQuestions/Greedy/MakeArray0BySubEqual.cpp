#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
      int ans =0;
      int sub =0;
      for(int i=0 ; i<nums.size() ;i ++)
      {
        // cout << "sub=" << abs(nums[i]-sub) << endl;
        if(abs(nums[i]-sub)<=0) continue;
        else 
        {
            ans++;
            sub +=  abs(nums[i]-sub);
        }
      }
      return ans;  
    }
};