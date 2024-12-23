#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    void bfs(vector<int> adj[],int start,vector<int> &ans,vector<bool> &vis)
    {
        vis[start] = true;
        ans.push_back(start);
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            for(auto it : adj[tp])
            {
                if(!vis[it])
                {
                  q.push(it);
                  ans.push_back(it);
                  vis[it] = true;
                }
               
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
       vector<int> ans ;
       vector<bool> vis(V,false);
       bfs(adj,0,ans,vis);
    //   for(int i=0 ; i<V ; i++)
    //   {
    //       if(!vis[i])
           
    //   }
       return ans;
    }
};

