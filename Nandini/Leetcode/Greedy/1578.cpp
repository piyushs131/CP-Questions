#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& time) 
    {
        int ans =0;
        int n = time.size(),i,prev=0;
        for(i=0 ; i<n ; i++)
        {
            if(i>0 && colors[i]!=colors[i-1])
            {
                prev =0;
            }
            int curr = time[i];
            ans+= min(curr,prev);
            prev = max(prev,curr);
        }
        return ans;
    }
    
};