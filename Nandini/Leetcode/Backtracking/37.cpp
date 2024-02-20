#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9) // base condition
            return true;

        if (board[row][col] == '.')
        {
            for (char ch = '1'; ch <= '9'; ch++)
            {
                if (isValid(row, col, ch, board))
                {
                    board[row][col] = ch;
                    if (col < 8)
                    {
                        if (solve(board, row, col + 1))
                            return true;
                    }
                    else
                    {
                        if (solve(board, row + 1, 0))
                            return true;
                    }
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            if (col < 8)
            {
                if (solve(board, row, col + 1))
                    return true;
            }
            else
            {
                if (solve(board, row + 1, 0))
                    return true;
            }
        }

        return false;   // backtracking
    }
    bool isValid(int row, int col, char ch, vector<vector<char>> &board)
    {
        int start_grid_row = row / 3 * 3;  //for grid check present or not
        int start_grid_col = col / 3 * 3;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch)        //in col check present or not
                return false;
            if (board[row][i] == ch)        //in row check present or not
                return false;
            if (board[i / 3 + start_grid_row][i % 3 + start_grid_col] == ch)
                return false;
        }
        return true;
    }
};