#include <bits/stdc++.h>
using namespace std;
#define all(n) n.begin(),n.end()
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOp) 
    {
       int maxi = *max_element(all(nums));
       int mini = *min_element(all(nums));
       vector<int> freq(maxi+1,0);
       int n = nums.size();
       sort(nums.begin(),nums.end());
       for(int i=0 ;i<n ; i++) freq[nums[i]]++;

       int ans =0;
       for(int i=mini ; i<=maxi ; i++) 
       {
         int op = upper_bound(all(nums),i+k) - lower_bound(all(nums),i-k);
         ans = max(ans,min(op,numOp+freq[i]));
       }
       return ans;
    }
};