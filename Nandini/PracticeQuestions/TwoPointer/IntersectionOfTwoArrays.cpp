#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());

       int p1=0,p2=0;
       int n1 = nums1.size(),n2 = nums2.size();
       vector<int> ans ;
       while(p1<n1 && p2<n2)
       {
          if(nums1[p1]==nums2[p2]) 
          {
            if(find(ans.begin(),ans.end(),nums1[p1])==ans.end())
            ans.push_back(nums1[p1]);
            p1++;
            p2++;
          }
          else if(nums1[p1] > nums2[p2]) p2++;
          else p1++;
       }
       return ans;
    }
};