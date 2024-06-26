#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> parent, rank;

public:
    int ultimateParent(int u)
    {
        if (parent[u] == u) return u;
        return parent[u] = ultimateParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int pu = ultimateParent(u);
        int pv = ultimateParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // using Kruskal's algo
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = it[0];
                int w = it[1];
                int v = i;
                edges.push_back({w, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;

        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        for (auto edge : edges)
        {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (ultimateParent(u) != ultimateParent(v))
            {
                ans += wt;
                unionByRank(u, v);
            }
        }
        return ans;
    }
};
