#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
      queue<pair<int,int> > q;
      int n= grid.size(),m= grid[0].size(),ct =0;
      for(int i=0 ; i<n ; i++)
      {
          for(int j=0 ; j<m ; j++)
          {
              if(grid[i][j]==2)
              {
                  q.push(make_pair(i,j));
              }
              if(grid[i][j]==1)
                  ct++;
          }
      }
        q.push(make_pair(-1,-1));
        if(ct==0)
        return 0;
        
        int pos[4] = {-1,0,1};
        int t =0;
        while(!q.empty())
        {
            int i = q.front().first,j = q.front().second;
            q.pop();
            if(i==-1 && j==-1)
            {
                t++;
                if(!q.empty())
                {
                  q.push(make_pair(-1,-1));
                      
                }
                continue;
              
            }
            
            
            if(i-1>=0 && grid[i-1][j]==1)
            {
                grid[i-1][j] = 2;
                q.push({i-1,j});
            }
            if(j-1>=0 && grid[i][j-1]==1)
            {
                grid[i][j-1] = 2;
                q.push({i,j-1});
            }
            if(i+1<n && grid[i+1][j]==1)
            {
                grid[i+1][j] = 2;
                q.push({i+1,j});
            }
            if(j+1<m && grid[i][j+1]==1)
            {
                grid[i][j+1] = 2;
                q.push({i,j+1});
            }
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return t-1;
    }
};