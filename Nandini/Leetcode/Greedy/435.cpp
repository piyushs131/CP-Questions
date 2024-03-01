#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) 
    {
        sort(v.begin(),v.end());
        int rem=0, r=v[0][1];
        for(int i=1 ; i<v.size()  ; i++)
        {
          if(v[i][0]<r)
          {
           r = min(r,v[i][1]);
           rem++;
          }
          else
          {
            r = v[i][1];
          }
        }
        return rem;   
    }
};