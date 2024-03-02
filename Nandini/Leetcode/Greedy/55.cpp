#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
    int numsSize = nums.size();
    int max=0;
    for(int i=0;i<numsSize;i++)
    {
       if(i>max)
       {
           return false;
       }
       if(i+nums[i]>max){
           max=i+nums[i];
       }
   }
   if(max>=numsSize-1){
       return true;
   }
   return false;
    }
    
};