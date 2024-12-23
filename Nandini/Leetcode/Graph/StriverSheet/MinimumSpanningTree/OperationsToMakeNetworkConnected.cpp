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

    int makeConnected(int n, vector<vector<int>> &conn) {
        if (conn.size() < n - 1) {
            return -1;  
        }
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (const auto &connection : conn) {
            int u = connection[0];
            int v = connection[1];
            unionByRank(rank, u, v, parent);
        }
        
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (Ultimateparent(parent, i) == i) {
                components++;
            }
        }
        
        return components - 1;
    }
};
