#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    bool isSafe(int row,int col,int n,vector<string> &board)
    {
       for(int i=0 ; i<row ; i++)           //checking downwards
       { 
         if(board[i][col]=='Q')
         return false;
       }
       for(int i=row-1,j=col-1 ; i>=0 && j>=0 ; i--,j--)    //Left diagonal
       {
          if(board[i][j]=='Q')
          return false;
       }
       for(int i=row-1,j=col+1; i>=0 && j<n ; i--,j++)    // Right diagonal
       {
        if(board[i][j]=='Q')
        return false;
       }
       return true;
    }
    void placeQueens(int row,int n,vector<vector<string> > &ans, vector<string> &board)
    {
       if(row==n)
       { 
        ans.push_back(board);
        return ;
       }
       for(int col=0 ;col<n ;col++)
       {
         if(isSafe(row,col,n,board))
         {
            board[row][col]='Q';
            placeQueens(row+1,n,ans,board);
            board[row][col]='.';
         }
       }
       return ;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n);
        string dt(n,'.');
        vector<vector<string> > ans;
        for(int i=0 ; i<n ;i++)
        {
           board[i]=dt;
        }
        placeQueens(0,n,ans,board);
        return ans;
    }
};