#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m= grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        priority_queue<pair<pair<int,int>,int > > pq;
        pq.push({{0,0},0});
        vector<vector<int> > dist(n,vector<int>(m,1e9));
        dist[0][0] =1;
        int drow[8] = {0,1,1,1,0,-1,-1,-1};
        int dcol[8] = {-1,-1,0,1,1,1,0,-1};
        while(!pq.empty())
        {
            int i = pq.top().first.first;
            int j = pq.top().first.second;
            int dis = pq.top().second;
            pq.pop();
            for(int k=0; k<8 ; k++)
            {
                int r = i+drow[k];
                int c = j+dcol[k];
               

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 0 && dist[r][c] > dist[i][j]+1)
                {
                    dist[r][c] = dist[i][j]+1;
                    pq.push({{r,c},dist[r][c]});
                }
            }
        }

        return dist[n-1][m-1]!=1e9?dist[n-1][m-1]:-1;
    }
};