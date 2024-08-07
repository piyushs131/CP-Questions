#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
       int ans =-1;
       int l =0,r=0;
       int n = s.size();
       unordered_map<int,int> mp;
       while(r<n)
       {
           mp[s[r]]++;
           if(mp.size()>k)
           {
               mp[s[l]]--;
               if(mp[s[l]]==0) mp.erase(s[l]);
               
               l++;
           }
           if(mp.size()==k){
               ans = max(ans,r-l+1);
           }
           r++;
       }
       return ans;
    }
};