#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    void dfs(int root,int parent,vector<vector<int> > &adj,vector<vector<int> > &dp)
    {
      int curr ;
      for(auto j : adj[root])
      {
        if(j!=parent)
        {
           dfs(j,root,adj,dp);
           // time to reach parent + time to reach child
           curr = dp[j][0]+(j%2?1:2); // j odd then 1 else 2
 
           if(curr>dp[root][0]) // set max
           dp[root][1] = dp[root][0],dp[root][0] = curr;
           else if(curr>dp[root][1])
           dp[root][1] = curr;
        }
      }
    }

    void findMax(int root,int prev,int incoming,vector<int> &ans,vector<vector<int> > &adj,vector<vector<int> > &dp){

        ans[root] = max(dp[root][0],incoming); // max for root
        int pa = (root%2?1:2);

        int curr,x;
        for(auto j:adj[root]){
            if(j!=prev)
            {
                curr = dp[j][0]+ (j%2?1:2);

                if(curr==dp[root][0]) x =dp[root][1];
                else x = dp[root][0];

                findMax(j,root,max(pa+incoming,pa+x),ans,adj,dp);
            }
        }
    }
    vector<int> timeTaken(vector<vector<int>>& edges) 
    {
       int n = edges.size()+1;
       vector<int> ans(n,0);
       // for left and right child storing
       vector<vector<int> > dp(n,vector<int>(2,0));
       vector<vector<int> > adj(n);

       // adj list
       for(auto x : edges)
       {
         adj[x[0]].push_back(x[1]);
         adj[x[1]].push_back(x[0]);
       } 

       // find max of both the childs
       dfs(0,-1,adj,dp); 
       // find max of child and parent
       findMax(0,-1,0,ans,adj,dp);

       return ans;
    }
};