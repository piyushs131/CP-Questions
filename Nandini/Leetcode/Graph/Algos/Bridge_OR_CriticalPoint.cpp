#include <bits/stdc++.h>
using namespace std;
class Solution {
    int timer = 1;
    void dfs(int node,int parent,vector<bool> &vis,vector<int> adj[],vector<int> &low,vector<int> &time,vector<vector<int> > &bridge)
    {
        vis[node] = true;
        time[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node])
        {
            if(it==parent)continue;
            if(vis[it]==false)
            {
               dfs(it,node,vis,adj,low,time,bridge);
               low[node] = min(low[node],low[it]);

               if(low[it]>time[node])
               {
                  bridge.push_back({it,node});
               }
            }
            else 
            {
                low[node] = min(low[node],low[it]);   
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) 
    {
        vector<int> adj[n];
        for(int i=0 ; i<conn.size() ; i++)
        {
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        vector<int> time(n);
        vector<int> low(n);
        vector<bool> vis(n,false);
        vector<vector<int> > bridges;
        dfs(0,-1,vis,adj,low,time,bridges);
        return bridges;
    }
};