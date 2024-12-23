#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
     void dfs(vector<pair<int,int> > edges[],stack<int> &st,vector<int> &vis,int node)
     {
         vis[node]  = 1;
         for(auto it : edges[node])
         {
             if(!vis[it.first])
             {
                 dfs(edges,st,vis,it.first);
             }
         }
         st.push(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
     {
       vector<pair<int,int> >adj[n];
       for(int i=0 ; i<m ; i++)
       {
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v,wt});
       }
       
       stack<int> st;
       vector<int> vis(n,0);
       for(int i=0 ; i<n ; i++)
       {
           if(!vis[i])
           dfs(adj,st,vis,i);
       }
       
       vector<int> dist(n,1e9);
       dist[0]=0;
       while(!st.empty())
       {
           int node = st.top(); st.pop();
           for(auto it : adj[node])
           {
               int v =  it.first;
               int wt = it.second;
               if(wt+dist[node] < dist[v])
               {
                   dist[v] = wt+dist[node] ;
               }
           }
       }
       for (int i = 0; i < n; ++i) {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
       
       return dist;
     }
};