#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n= nums.size();
       int l=0,m=0,r=n-1; 
       while(m<=r)
       {
        if(nums[m]==0)swap(nums[m++],nums[l++]);
        else if(nums[m]==2) swap(nums[m],nums[r--]);
        else m++; 
       }
    }
};