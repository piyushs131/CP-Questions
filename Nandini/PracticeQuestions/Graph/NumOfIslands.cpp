#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char> > &grid,int r,int c,vector<vector<int> > &vis,int n,int m)
    {
        vis[r][c] = 1;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0 ;i<4 ; i++)
        {
            int newr = drow[i]+r;
            int newc = dcol[i] + c;
    if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]=='1' && !vis[newr][newc])
            {
               dfs(grid,newr,newc,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
       int n = grid.size();
       int m = grid[0].size();
       int count =0;
       vector<vector<int> > vis(n,vector<int> (m,0));
       for(int i=0 ;i <n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]=='1' && !vis[i][j])
            {
                dfs(grid,i,j,vis,n,m);
                count++;
            }
        }
       }

       return count; 
    }
};