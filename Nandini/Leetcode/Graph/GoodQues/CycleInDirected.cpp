#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &pathvis,int node)
    {
        vis[node] =1;
        pathvis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it]==-1)
            {
                if(dfs(adj,vis,pathvis,it))
                {
                    return true;
                }
            }
            else if(pathvis[it]==1)
            {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) 
    {
        vector<int> vis(n,-1);
        vector<int> pathvis(n,-1);
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(adj,vis,pathvis,i))
                return true;
            }
        }
        return false;
    }
};
