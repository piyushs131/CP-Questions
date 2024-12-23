#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
       queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int n = image.size(),m = image[0].size();
        int cl = image[sr][sc];
        vector<vector<bool> > vis(n,vector<bool> (m,false));
        while(!q.empty())
        {
            int i= q.front().first,j = q.front().second;
            q.pop();
            image[i][j] = color;
            vis[i][j] = true;
            for(int k=0 ; k<4 ; k++)
            {
                int r = i+drow[k];
                int c = j+dcol[k];
                if(r>=0 && r<n && c>=0 && c<m && image[r][c]==cl && !vis[r][c])
                {
                    vis[r][c] = true;
                    image[r][c] = color;
                    q.push(make_pair(r,c));
                }
            }
        }
        return image;
    }
};