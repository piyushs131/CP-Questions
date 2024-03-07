#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size(),m = image[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
       dfs(sr,sc,image,vis,color,image[sr][sc]);
           return image;
    }
    void dfs(int row,int col,vector<vector<int> >&image,vector<vector<int> > &vis,int color,int ini)
    {
        vis[row][col] = 1;
        image[row][col] = color;
        int n= image.size(), m= image[0].size();
        if(row+1<n && image[row+1][col] == ini && !vis[row+1][col])
        {
            dfs(row+1,col,image,vis,color,ini);
        }
        if(col+1<m && image[row][col+1] == ini && !vis[row][col+1])
        {
            dfs(row,col+1,image,vis,color,ini);
        }
        if(row-1>=0 && image[row-1][col] == ini && !vis[row-1][col])
        {
            dfs(row-1,col,image,vis,color,ini);
        }
        if(col-1>=0 && image[row][col-1] == ini && !vis[row][col-1])
        {
            dfs(row,col-1,image,vis,color,ini);
        }
    }
};