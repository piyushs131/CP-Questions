#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), j ;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++) 
        {
            mp[nums[i]]++;
        }
        
        for(j=1; j <= n+1; j++) 
        {
            if(mp.find(j) == mp.end()) 
            {
                return j;
            }
        }
        
        return j;
    }
};
