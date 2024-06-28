#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r, int c, queue<pair<int, int>>& q, vector<vector<int>>& dir,
             vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
            vis[r][c] || grid[r][c] == 0)
            return;
        vis[r][c] = true;
        q.push({r, c});
        for (auto it : dir) {
            dfs(r + it[0], c + it[1], q, dir, grid, vis);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, q, dirs, grid, vis);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) 
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (auto it : dirs) {
                    int newr = r + it[0], newc = c + it[1];
                    if (newr >= 0 && newc >= 0 && newr < n && newc < m &&
                        !vis[newr][newc]) {
                        if (grid[newr][newc] == 1)
                            return step;
                        q.push({newr, newc});
                        vis[newr][newc] = true;
                    }
                }
            }
            step++;
        }
        return step;
    }
};