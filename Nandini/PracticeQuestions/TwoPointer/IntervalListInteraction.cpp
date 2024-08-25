#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) 
    {
       vector<vector<int> > ans;
       int i=0,j=0;
       int n = first.size(),m = second.size();
       while(i<n && j<m)
       {
          int s1 =first[i][0],e1 = first[i][1];
          int s2 = second[j][0],e2 = second[j][1] ;
          if(e1>=s2 && e2>=s1)
          {
            int st = max(s1,s2);
            int end = min(e1,e2);
            ans.push_back({st,end});
          }

          if(e1<e2) i++;
          else j++;
          
       } 
       return ans;
    }
};