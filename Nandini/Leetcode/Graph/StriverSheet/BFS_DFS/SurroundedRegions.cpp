#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char> > &board,vector<vector<bool>> &vis,vector<vector<char>> &ans,int i,int j)
    {
        vis[i][j] = true;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
         ans[i][j] = 'O';
        for(int k=0 ;k <4 ; k++)
        {
            int r = drow[k]+i;
            int c = dcol[k]+j;
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]=='O' && !vis[r][c])
            {
              dfs(board,vis,ans,r,c);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n= board.size(),m = board[0].size();
        vector<vector<bool> > vis(n,vector<bool> (m,false)); 
        vector<vector<char> > ans(n,vector<char>(m,'X'));
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]=='O' && (i==n-1 || j==m-1 || i==0 || j==0))
                {
                    dfs(board,vis,ans,i,j);
                }
            }
        }
        
        board = ans;
    }
};