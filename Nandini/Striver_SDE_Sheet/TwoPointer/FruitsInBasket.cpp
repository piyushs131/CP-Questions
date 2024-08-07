#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int ans =0;
        int n = arr.size();
        int l =0,r =0;
        unordered_map<int,int> mp;
        while(r<n)
        {
            mp[arr[r]]++;
            while(mp.size()>2)
            {
                mp[arr[l]]--;
                if(mp[arr[l]]==0)mp.erase(arr[l]);
                
                l++;
            }
            if(mp.size()<=2)
            {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};