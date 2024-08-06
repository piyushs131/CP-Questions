#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       int p1 = nums[nums[0]], p2 = nums[nums[nums[0]]];
       int s=p1,f=p2;
       while(s!=f)
       {
         s = nums[s];
         f = nums[nums[f]];
       }
       f = nums[0];
       while(s!=f)
       {
         f = nums[f];
         s = nums[s];
       }
       return s;
    }
};