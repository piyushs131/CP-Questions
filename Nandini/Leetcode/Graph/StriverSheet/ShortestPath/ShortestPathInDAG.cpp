#include <bits/stdc++.h>
using namespace std;
// Topo sort then keep taking from stack and comparing dist if small then push
class Solution {
  public:
     void dfs(int node,vector<pair<int,int> > edges[],vector<bool> &vis,stack<int> &st)
     {
         vis[node] = true;
         for(auto it : edges[node])
         {
             if(!vis[it.first])
             dfs(it.first,edges,vis,st);
         }
         st.push(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
     {
        vector<int> dist(n,1e9);
        stack<int> st;
        vector<bool> vis(n,false);
        vector<pair<int,int> > graph[n];
        for(int i=0 ;i <m;i ++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v,wt});
        }
        
        
        for(int i=0 ; i<n ; i++)
        if(!vis[i])
        dfs(i,graph,vis,st);
        
        dist[0] = 0;
        while(!st.empty())
        {
            int tp = st.top();
            st.pop();
            for(auto it : graph[tp])
            {
                int v= it.first,wt = it.second;
                if(wt+dist[tp] < dist[v])
                dist[v] = dist[tp]+wt;
            }
        }
        
        for(int i=0 ;i <n ;i++)
        if(dist[i]==1e9)
        dist[i] = -1;
        
        return dist;
     }
};
