#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) 
    {
       sort(inv.begin(),inv.end());
       vector<vector<int> > ans; 
       if(inv.size()==0) return ans;
       ans.push_back(inv[0]);
       int n = inv.size();
       for(int i=1 ; i<n ; i++)
       {
          int a = ans.back()[0], b = ans.back()[1];
          int c = inv[i][0] , d = inv[i][1];
          if(b>=c && b>=d)
          {
            ans.pop_back();
            ans.push_back({a,b});
          }
          else if(b>=c && b<d)
          {
            ans.pop_back();
            ans.push_back({a,d});
          }
          else 
          {
            ans.push_back({c,d});
          }
       }
       return ans; 
    }
};