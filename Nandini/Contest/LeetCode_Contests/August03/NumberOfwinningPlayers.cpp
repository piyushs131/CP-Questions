#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) 
    {
       map<pair<int,int> ,int> mp;
       for(auto it : pick)
       {
         mp[{it[0],it[1]}]++;
       }
       map<int,int> ans;
       for(auto it : mp)
       {
        // cout << it.first.first << " "<< it.first.second << " " << it.second << endl;
          if(it.first.first+1<=it.second)
          ans[it.first.first]++;
       }
       return ans.size();
    }
};