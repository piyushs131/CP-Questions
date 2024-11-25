#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minTime(int k, vector<int> &pos) 
    {
       sort(pos.begin(),pos.end());    
       int s=0,e=k-1,n = pos.size(),ans=0,final = INT_MAX;
       while(e<n)
       {
           if(pos[e]<=0) ans = abs(pos[s]);
           else if(pos[s]>=0) ans = abs(pos[e]);
           else ans = 2*min(abs(pos[s]),pos[e]) + max(-pos[s],pos[e]);
           
           e++;
           s++;
           final = min(final,ans);
          // cout <<" ans=" << ans << endl;
       }
       return final;
    }
};