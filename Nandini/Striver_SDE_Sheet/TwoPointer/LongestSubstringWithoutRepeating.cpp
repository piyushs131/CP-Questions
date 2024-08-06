#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0,len=0;
        int n = s.size();
        map<int, int> mp;
        while (r < n) 
        {
            if (mp.find(s[r]) != mp.end()) {
                if (mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
             }
            }
             len = r-l+1;
            ans = max(ans,len);
            mp[s[r]] = r;
                r++;
        }
        return ans;
    }
};