#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int,int> > adj[n];
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int dis = flights[i][2];
            adj[u].push_back({v,dis});
        }
        queue<pair<int, vector<int>>> pq;
        pq.push({0, {src}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        pq.push({-1,{-1}});
        while (!pq.empty())
        {
            int dis = pq.front().first;
            vector<int> path = pq.front().second;
            int node = path[path.size()-1];
            pq.pop();
            if(node==-1)
            {
                pq.push({-1,{-1}});
                k--;
                if(k<0) break;
                continue;
            }
            for (auto it :adj[node])
            {
                if(dist[it.first]>dis+it.second)
                {
                    dist[it.first] = dis+it.second;
                    path.push_back(it.first);
                    pq.push({dist[it.first],path});
                }
            }
        }
        if(dist[dst]!=1e9)
        return dist[dst];
        else return -1;
    }
};