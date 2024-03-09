#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCycle(int n, vector<int> adj[]) 
    {
        vector<int> vis(n,0);
        for(int i=0 ; i<n ;i++)
        {
            if(vis[i]==0)
            if(bfs(adj,vis,n,i))
            return true;
        }
        return false;
    }
    bool bfs(vector<int> adj[],vector<int> &vis,int n,int node)
    {
        queue<pair<int,int> > q;
        q.push({node,-1});
        vis[node] = true;
        int p;
        while(!q.empty())
        {
            node = q.front().first;
            p = q.front().second;
            q.pop();
            for(auto it : adj[node])
            {
                if(vis[it]==1 && it!=p)
                return true;
                else if(vis[it]==0)
                {
                    q.push({it,node});
                    vis[it] = 1;
                }
            }
        }
        return false;
    }
};