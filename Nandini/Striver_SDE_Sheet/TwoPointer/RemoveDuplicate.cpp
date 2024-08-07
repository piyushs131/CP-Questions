#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
       int l =1,r=1,n = nums.size();
       while(r<n) {
        if(nums[r]==nums[r-1])r++;
        else {
            nums[l] = nums[r];
            l++;
            r++;
        }
       }

       return l;
    }
};