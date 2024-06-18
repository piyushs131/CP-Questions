#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int> > &board,vector<vector<bool>> &vis,vector<vector<int>> &ans,int i,int j)
    {
        vis[i][j] = true;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
         ans[i][j] = 1;
        for(int k=0 ;k <4 ; k++)
        {
            int r = drow[k]+i;
            int c = dcol[k]+j;
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]==1 && !vis[r][c])
            {
              dfs(board,vis,ans,r,c);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) 
    {
       int n= board.size(),m = board[0].size();
        vector<vector<bool> > vis(n,vector<bool> (m,false)); 
        vector<vector<int> > ans(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]==1 && (i==n-1 || j==m-1 || i==0 || j==0))
                {
                    dfs(board,vis,ans,i,j);
                }
            }
        }
        int count =0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]==1 && ans[i][j]!=1)
                    count++;
            }
        }
        return count;
    }
};