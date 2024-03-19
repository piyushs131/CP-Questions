#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        vector<int> dist(n,1e9);
        vector<int> adj[n];
        for(int i=0 ;i <m ; i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        bfs(adj,dist,src,n);
        for(int i=0 ; i<n ;i++)
        {
            if(dist[i]==1e9)
            dist[i] = -1;
        }
        return dist;
    }
    
    void bfs(vector<int> adj[],vector<int> &dist,int src,int n)
    {
        dist[src] = 0;
        queue<pair<int,int> > q;
        q.push({src,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto it : adj[node])
            {
                if(dist[it] > 1+dis)
                {
                    dist[it] = 1+dis;
                    q.push({it,1+dis});
                }
            }
        }
        
        
    }
};