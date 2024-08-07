#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void eraseMiddleNodes(set<int> &s,int l,int r)
    {
        auto start = s.lower_bound(l);
        auto end  = s.upper_bound(r);
        s.erase(start,end);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
       set<int> s;
       for(int i=0 ; i<n ; i++)
       s.insert(i);

       vector<int> ans;
       for(auto it: queries)
       {
        int x = it[0],y = it[1];
        eraseMiddleNodes(s,x+1,y-1);
        ans.push_back(s.size()-1);
       } 
       return ans;
    }
};