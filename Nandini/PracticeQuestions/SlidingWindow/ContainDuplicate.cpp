#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
       if(k==0) return false;
       int i=0,j=0;
       int n = nums.size();
       unordered_set<int> st;
       while(j<n)
       {
         if(j-i>k) {
            st.erase(nums[i]);
            i++;
         }

         if(st.find(nums[j])!=st.end()) return true;
         st.insert(nums[j]);
         j++;
       }
       return false; 
    }
};