#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (auto& pre : prerequisites) 
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);
        
        int count = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;
            
            for (int neighbor : adj[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return count == n;
    }
};
