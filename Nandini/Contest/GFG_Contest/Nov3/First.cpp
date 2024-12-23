#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getOperations(string s) 
    {
        int n = s.size();
        unordered_map<int,int> mp;
        for(int i=0 ;i <n ; i++)
        {
            mp[s[i]]++;
        }
        int ans =0;
        
        for(auto it : mp)
        {
            while(it.second>=3)
            {
                ans++;
                it.second-=3;
            }
        }
        return ans;
    }
};