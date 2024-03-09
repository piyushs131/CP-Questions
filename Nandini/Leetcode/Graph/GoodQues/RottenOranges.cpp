#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
        queue<pair<pair<int,int> ,int> > q;
        int ct=0,freshCount=0;
        for(int i=0  ;i <n ;i ++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                if(grid[i][j]==1)freshCount++;
            }
        }
        
        int time =0;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        int r,c;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second; 
            q.pop();
            time = max(time,t);
            for(int i=0 ;i <4 ; i++)
            {
                r = row+delrow[i];
                c = col+delcol[i];
                if(r<n && c<m && r>=0 && c>=0 && grid[r][c]==1 && vis[r][c]==0)
                {
                    q.push({{r,c},t+1});
                    vis[r][c] = 1;
                    grid[r][c] = 2;
                    ct++;
                }
            }
            
        }
        
       if(ct!=freshCount) return -1;
        return time;
    }
};