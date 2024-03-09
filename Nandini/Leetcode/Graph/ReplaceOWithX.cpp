#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<char> > ans(n,vector<char> (m,'X'));
       for(int i=0 ;i<n ; i++)
       {
           for(int j=0 ; j<m ; j++)
           {
               if( (i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O' && ans[i][j]!='O')
               bfs(mat,ans,i,j);
           }
       }
       return ans;
    }
    void bfs(vector<vector<char> > &grid,vector<vector<char> > &ans,int row,int col)
    {
        ans[row][col] = 'O';
        queue<pair<int,int> > q;
        q.push({row,col});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int n = grid.size(),m = grid[0].size();
        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for(int i=0 ; i<4 ; i++)
            {
               int r = row+delrow[i];
               int c = col+delcol[i];
              if(r>=0 && c>=0 && r<n && c<m && grid[r][c]=='O' && ans[r][c]!='O')
              {
                  q.push({r,c});
                  ans[r][c] = 'O';
              }
            }
        }
        
    }
};
