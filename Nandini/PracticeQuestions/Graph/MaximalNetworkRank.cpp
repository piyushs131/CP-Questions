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
class Solution2 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
      vector<int> degree(n,0);
      vector<vector<int> > connected(n,vector<int>(n,0));
      for(auto it : roads)
      {
        degree[it[0]]++;
        degree[it[1]]++;
        connected[it[0]][it[1]] = 1;
        connected[it[1]][it[0]] = 1;
      }  

      int final =0,ans=0;
      for(int i=0 ;i <n ;i ++)
      {
        for(int j=i+1 ; j<n ; j++)
        {
            ans = degree[i]+degree[j];
            if(connected[i][j]==1)ans--;
            final = max(ans,final);
        }
      }
      return final;
    }
};
