#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(vector<int> adj[],vector<bool> &vis,vector<int> &parent,int st)
    {
        vis[st] = true;
        for(auto it : adj[st])
        {
            if(!vis[it])
            {
                parent[it] = st;
                if(dfs(adj,vis,parent,it))
                return true;
            }
            else if(parent[st]!=it)
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,false);
        vector<int> parent(V,-1);
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,parent,i))
                {
                  return true;    
                }
                
            }
        }
        return false;
    }
};