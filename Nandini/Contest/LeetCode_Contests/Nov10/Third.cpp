#include <bits/stdc++.h>
using namespace std;
#define all(n) n.begin(),n.end()
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOp) 
    {
        int n= nums.size();
        unordered_map<int,int> freq;
        // calculating freq of all elements
        for(auto x : nums) ++freq[x];

       int ans =0,j=0;
       sort(all(nums)); // sorting the array
       for(int i=0 ; i<n ; i++) 
       {
         // nums[i]-k to nums[i]+k sab nums[i] me convert ho jayege
         int numbersCanConvert = upper_bound(all(nums),nums[i]+k) - lower_bound(all(nums),nums[i]-k);
         // agr numOp me hai toh convert all numbersCanConvert else (numOpeartions + freq[nums[i]] ) jitne ho sakte hai
         ans = max(ans,min(numbersCanConvert,numOp+freq[nums[i]]));
         // for the inbetween elements of nums[i] to nums[j+1](or nums[i+1])
         while(j+1<n && nums[j+1]-nums[i]<=2*k)j++;
         // freq of inbetween elements is 0 
         ans = max(ans,min(j-i+1,numOp));
       }
       return ans;  
    }
};