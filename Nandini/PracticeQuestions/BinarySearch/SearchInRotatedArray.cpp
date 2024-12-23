#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int t) 
    {
       int n = nums.size();
       int l =0, u = n-1,mid;
       while(l<=u)
       {
          mid = l+(u-l)/2;
          if(nums[mid]==t) return mid;
          else if(nums[l]<=nums[mid])
          {
            if(nums[mid]>t && t>=nums[l]) u = mid-1;
            else l = mid+1;
          }
          else {
            if(nums[mid]<t && t<=nums[u]) l = mid+1;
            else u = mid-1;
          }
       }
       return -1;
    }
};