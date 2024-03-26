#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        set<pair<int, int>> pq; 
        vector<int> parent;
        for(int i = 0; i <= n; i++)
            parent.push_back(i);

        vector<pair<int,int> > adj[n+1];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int> dis(n+1, 1e9);
        dis[1] = 0;
        pq.insert({0, 1});
        while(!pq.empty())
        {
            int node = pq.begin()->second;
            int distance = pq.begin()->first;
            pq.erase(pq.begin());
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edis = it.second;
                if(dis[adjNode] > distance + edis)
                {
                    pq.erase({dis[adjNode], adjNode});
                    dis[adjNode] = distance + edis;
                    pq.insert({dis[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if(dis[n] == 1e9) return {-1};
        int node = n;
        vector<int> ans;
        ans.push_back(n);
        while(parent[node] != node)
        {
            ans.push_back(parent[node]);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
