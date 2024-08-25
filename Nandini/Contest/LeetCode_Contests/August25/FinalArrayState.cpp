#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int x) 
    {
       int i,n = nums.size();
       while(k--)
       {
          int min_ele_index = min_element(nums.begin(),nums.end())-nums.begin();
          nums[min_ele_index] = x*nums[min_ele_index];
       }  
       return nums;
    }
};