#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()==1) return;
        if(nums.size()==2)
        {
            swap(nums[1],nums[0]);
            return;
        }
        int n = nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1])
        i--;

        sort(nums.begin()+i+1,nums.end());
        if(i==-1) return;
        for(int j=i+1 ; j<n ; j++)
        {
            if(nums[j]>nums[i])
            {
                swap(nums[j],nums[i]);
                return;
            }
        }
    }
};