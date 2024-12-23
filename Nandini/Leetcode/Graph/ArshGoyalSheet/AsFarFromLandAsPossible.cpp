#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n= grid.size(),m =grid[0].size();
       vector<vector<int> > vis(n,vector<int>(m,0));
       queue<pair<pair<int,int>,int> > q;
       for(int i=0 ; i<n ; i++)
       {
         for(int j=0 ; j<m ; j++)
         {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
         }
       }

       int ans =-1;
       int drow[4] = {-1,0,1,0};
       int dcol[4] = {0,1,0,-1};
       while(!q.empty())
       {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(d==0)
        ans = -1;
        else 
        ans = max(ans,d);
        for(int i=0 ; i<4 ; i++)
        {
            int new_r = r+drow[i];
            int new_c = c+dcol[i];
            if(new_r>=0 && new_c>=0 && new_r<n && new_c<m && !vis[new_r][new_c] && grid[new_r][new_c]==0)
            {
                q.push({{new_r,new_c},d+1});
                vis[new_r][new_c] = 1;
            }
        }
       }
       return ans; 
    }
};