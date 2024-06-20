#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        queue<pair<int,int> > q;
        q.push({src,0});
        vector<int> dist(n,1e9);
        vector<int> graph[n];
        for(int i=0 ;i <m ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        dist[src] =0;
        while(!q.empty())
        {
            int tp = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto it : graph[tp])
            {
                if(1+dis < dist[it])
                {
                    dist[it] = 1+dis;
                    q.push({it,1+dis});
                }
            }
        }
        for(int i=0 ; i<n ; i++)
        if(dist[i]==1e9)
        dist[i] = -1;
        
        return dist;
    }
};