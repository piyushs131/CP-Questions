#include<bits/stdc++.h>
using namespace std;
class Solution 
{
  public:
    bool isCycle(int n, vector<int> adj[]) 
    {
        int vis[n] = {0};
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i]==0)
            if(dfs(adj,vis,i,-1))
            return true;
        }
        return false;
    }
    bool dfs(vector<int> adj[],int vis[],int node,int p)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,vis,it,node))
                return true;
            }
            else if(vis[it]==1 && p!=it) 
            return true;
        }
        return false;
    }
};
