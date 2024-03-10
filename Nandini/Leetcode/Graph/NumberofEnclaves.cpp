#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int> >vis(n,vector<int> (m,0));
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if( ( i==0 || j==0 || i==n-1 || j==m-1 ) && grid[i][j]==1 && vis[i][j]!=1)
                {
                    bfs(grid,vis,i,j);
                }
            }
        }
        
        int count =0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]!=vis[i][j])
                count++;
            }
        }
        return count;
    }
    
    void bfs(vector<vector<int> > &grid,vector<vector<int> > &vis,int row,int col)
    {
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vis[row][col]=1;
        int n = grid.size(),m = grid[0].size();
        queue<pair<int,int> > q;
        q.push({row,col});
        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0 ; i<4 ; i++)
            {
                int r = delrow[i] + row;
                int c = delcol[i] + col;
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && vis[r][c]!=1)
                {
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
    }
};
