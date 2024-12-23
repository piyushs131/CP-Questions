#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs1(int node, vector<vector<int> > &adj, stack<int> &st, vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(it, adj, st, vis);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<int> rev[], vector<int> &vis) {
        vis[node] = 1;
        for (auto it : rev[node]) {
            if (!vis[it]) {
                dfs2(it, rev, vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> vis(V, 0);

        // Step 1: Perform DFS to fill the stack with finish times
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, st, vis);
            }
        }

        // Step 2: Reverse the graph
        vector<int> rev[V];
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                rev[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the reversed graph using the order in the stack
        fill(vis.begin(), vis.end(), 0);
        int count = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                count++;
                dfs2(node, rev, vis);
            }
        }

        return count;
    }
};
