#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(vector<int> adj[],int st,vector<int> &ans,vector<bool> &vis)
    {
        vis[st] = true;
        ans.push_back(st);
        for(auto it : adj[st])
        {
            if(!vis[it])
            {
                dfs(adj,it,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> ans;
        vector<bool> vis(V,false);
        dfs(adj,0,ans,vis);
        return ans;
    }
};