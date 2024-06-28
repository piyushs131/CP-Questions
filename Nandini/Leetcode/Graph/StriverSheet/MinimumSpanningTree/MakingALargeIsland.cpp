#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        rank.resize(n, 0);
        size.resize(n, 1); 
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union all connected components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if (newr >= 0 && newc >= 0 && newr < n && newc < n && grid[newr][newc] == 1) {
                        int nodeNumber = n * i + j;
                        int adjnode = n * newr + newc;
                        ds.unionBySize(nodeNumber, adjnode);
                    }
                }
            }
        }

        // Step 2: Try converting each 0 to 1 and calculate the largest island
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    set<int> components;
                    for (int ind = 0; ind < 4; ind++) {
                        int newr = i + dr[ind];
                        int newc = j + dc[ind];
                        if (newr >= 0 && newc >= 0 && newr < n && newc < n && grid[newr][newc] == 1) {
                            components.insert(ds.findParent(newr * n + newc));
                        }
                    }
                    int size = 1;  // Starting with 1 because we are converting this 0 to 1
                    for (auto it : components) {
                        size += ds.size[it];
                    }
                    ans = max(ans, size);
                }
            }
        }

        // In case the entire grid is already filled with 1s
        for (int cellno = 0; cellno < n * n; cellno++) {
            ans = max(ans, ds.size[ds.findParent(cellno)]);
        }
        
        return ans;
    }
};
