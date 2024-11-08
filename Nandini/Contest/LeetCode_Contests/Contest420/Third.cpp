#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
       int n = nums.size(),ans=0;
       for(int i=n-2 ; i>=0 ; i--)
       {
         int next = nums[i+1];
         if(next>=nums[i]) continue;
         for(int j=2 ; j*j<=nums[i] ; j++)
         {
            if(nums[i]%j==0)
            {
                nums[i] = j;
                ans++;
                break;
            }
         }
         if(nums[i]>next) return -1;
       }
       return ans; 
    }
};