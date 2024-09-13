#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
       int ans =0,n = nums.size();
       int ideal = 0;
       for(int i=0 ; i<n ; i++) {
        ans = ans^nums[i];
        ideal = ideal^i;
       }
       ideal = ideal^n;
       return ideal^ans; 
    }
};