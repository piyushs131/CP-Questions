#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
       int n = nums.size();
       int l=0,u=n-1;
       while(l<u)
       {
         while(l<nums.size() && nums[l]%2==0) l++;
         while(u>=0 && nums[u]%2!=0) u--;

         if(l<u)
         swap(nums[l],nums[u]);
       } 
       return nums;
    }
};