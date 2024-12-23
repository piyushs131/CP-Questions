#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    pair<ll,ll> dfs(int node,vector<int> *g,vector<int> &val,ll &ans)
    {
        ll maxi = -1e18,mini = 1e18;
        for(auto nbr : g[node])
        {
            auto p = dfs(nbr,g,val,ans);
            maxi = max(maxi,val[node]-p.second); // yha ans
            mini = min(mini,val[node]-p.first);
        }
        // leaf node
        if(mini == 1e18) maxi = mini = val[node];
        
        ans = max(ans,maxi);
        return {maxi,mini};
        
    }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
       vector<int> lst[N];
       for(int i=1 ;i <P.size() ;i ++) lst[P[i]-1].push_back(i);
       
       ll ans = -1e18;
       dfs(0,lst,A,ans);
       return ans;
    }
};