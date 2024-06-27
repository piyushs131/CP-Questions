#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Ultimateparent(vector<int> &parent, int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = Ultimateparent(parent, parent[u]);
    }

    void unionByRank(vector<int> &rank, int u, int v, vector<int> &parent) {
        int pu = Ultimateparent(parent, u);
        int pv = Ultimateparent(parent, v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxi_row = INT_MIN, maxi_col = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxi_row = max(maxi_row, stones[i][0]);
            maxi_col = max(maxi_col, stones[i][1]);
        }

        vector<pair<int,int>> adj;
        for(int i = 0; i < n; i++) {
            adj.push_back({stones[i][0], stones[i][1] + maxi_row + 1});
        }

        vector<int> parent(maxi_row + maxi_col + 2);
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        vector<int> rank(maxi_row + maxi_col + 2, 0);

        for(int i = 0; i < n; i++) {
            int u = adj[i].first;
            int v = adj[i].second;
            unionByRank(rank, u, v, parent);
        }

        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int p = Ultimateparent(parent, adj[i].first);
            mp[p]++;
        }

        int components = mp.size();
        return n - components;
    }
};
