#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<int> pref(n,0);
        pref[0] = nums[0];
        
        for(int i=1 ; i<n ; i++) pref[i]+=pref[i-1]+nums[i];

        // if both sides having equal sum-> can move in both directions
        // if diff of sum is 1 then in 1 dir only

        for(int i=0 ; i<n ; i++)
            {
                if(nums[i]==0)
                {
                    if(pref[i]-(pref[n-1]-pref[i])==0) ans+=2;
                    else if(abs(pref[n-1]-pref[i]-pref[i])==1) ans+=1;
                }
            }
        return ans;
    }
};