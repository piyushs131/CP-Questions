#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
       int l=0,r=0,n = nums.size(),count =0;
       while(r<n)
       {
         if(nums[l]!=val) l++,r++;
         else 
         {
            while(r<n && nums[r]==val) r++;
            if(r>=n) return l;

            swap(nums[l],nums[r]);
            l++;
         }
       }
       return l; 
    }
};
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[ind] = nums[i];
                ind++;
            }
        }
        return ind;
    }
};