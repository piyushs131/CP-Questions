#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s, int k) 
    {
       int l=0,ans=0;
       unordered_map<char,int> mp;
       for(auto c : s)
       {
         mp[c]++;
         while(mp[c]==k){
            mp[s[l]]--;l++;
         }
         ans+=l;
       }
       return ans;
    }
};