#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(),m = grid[0].size();
	    vector<vector<int> > vis(n,vector<int> (m,0));
	    vector<vector<int> > dir(n,vector<int> (m,0));
	    queue<pair<pair<int,int>,int> > q;
	    for(int i=0 ;i<n ; i++)
	    {
	        for(int j=0 ; j<m ; j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},1});
	            }
	        }
	    }
	    
	    int delrow[] = {-1,0,1,0};
	    int delcol[] = {0,1,0,-1};
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step= q.front().second;
	        q.pop();
	        for(int i=0 ; i<4 ; i++)
	        {
	            int r = row+delrow[i];
	            int c = col+delcol[i];
	            if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0 && grid[r][c]==0)
	            {
	                vis[r][c] = 1;
	                q.push({{r,c},step+1});
	                dir[r][c] = step;
	            }
	        }
	    }
	    
	    return dir;
	}
};