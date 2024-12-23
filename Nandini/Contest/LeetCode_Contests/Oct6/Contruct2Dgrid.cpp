#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        int first =min_element(indegree.begin(), indegree.end()) - indegree.begin();
        vector<int> row = {first};
        vector<int> vis(n, 0);
        vis[first] = 1;
        for (int i = 0; i < row.size(); i++) {
            int node = row[i];
            // if we are at last-> break
            if (i > 0 && indegree[node] == indegree[first])
                break;

            // nhi toh uss node ka min vala age use karege
            sort(adj[node].begin(), adj[node].end(),
                 [&](int x, int y) { return indegree[x] < indegree[y]; });

            for (auto nbr : adj[node]) {
                if (!vis[nbr] && indegree[nbr] + 1 >= indegree[node]) {
                    vis[nbr] = 1;
                    row.push_back(nbr);
                    break;
                }
            }
        }
        // we got the first row or col size
        int col_size = row.size();
        int row_size = n / col_size;
        vector<vector<int>> ans(row_size, vector<int>(col_size));
        ans[0] = row;
        for (int i = 0; i < row_size - 1; i++) {
            for (int j = 0; j < col_size; j++) {
                for (auto nbr : adj[ans[i][j]]) {
                    if (!vis[nbr]) {
                        ans[i + 1][j] = nbr;
                        vis[nbr] = 1;
                    }
                }
            }
        }

        return ans;
    }
};