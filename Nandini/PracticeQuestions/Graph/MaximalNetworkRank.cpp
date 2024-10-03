#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> connected(n, 0);
        for (int i = 0; i < n; i++) {
            connected[i] = adj[i].size(); 
        }
        
        int maxRank = 0;
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int rank = connected[i] + connected[j];
                for (auto& nbr : adj[i]) {
                    if (nbr == j) {
                        rank--; 
                        break;
                    }
                }
                maxRank = max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};
