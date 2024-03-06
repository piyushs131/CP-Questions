#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dfsOfGraph(int n, vector<int> adj[]) 
    {
        vector<bool> vis(n,false);
        vector<int> ans;
        dfs(adj,n,vis,ans,0);
        return ans;
    }
    
    void dfs(vector<int> adj[],int n,vector<bool> &vis,vector<int> &ans,int node)
    {
        vis[node] = true;
        ans.push_back(node);
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,n,vis,ans,it);
            }
        }
    }
};