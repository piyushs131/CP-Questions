#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        for (auto it : t)
            mp[it]++;

        int n = s.size();
        int ind = -1, minLen = INT_MAX;
        int count =0;
        while (r < n) 
        {
            if (mp[s[r]] > 0)
                count++;
           
            mp[s[r]]--;

            while (count == t.size()) 
            {
                if(r-l+1<minLen)
                {
                    minLen = r-l+1;
                    ind = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    count--;
                l++;
            }

            r++;
        }
        return ind==-1?"":s.substr(ind,minLen);
    }
};