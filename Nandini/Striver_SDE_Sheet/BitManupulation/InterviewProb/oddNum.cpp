#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
      int XOR =0,n = nums.size();
      for(int i=0 ; i<n ; i++) XOR^=nums[i];
      return XOR;  
    }
};