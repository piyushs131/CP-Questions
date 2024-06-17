#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<int > adj[],vector<bool> &vis,int st)
    {
        vis[st] = true;
        for(auto it : adj[st])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) 
    {
       int ans =0;
        vector<bool> vis(adj.size(),false);
        vector<int> mat[adj.size()];
        for(int i=0 ; i<adj.size() ; i++)
        {
            for(int j=0 ; j<adj[i].size() ; j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    mat[i].push_back(j);
                }
            }
        }
        for(int i=0 ; i<adj.size() ; i++)
        {
            if(!vis[i])
            {
                dfs(mat,vis,i);
                ans++;
            }
        }
        return ans;
    }
};