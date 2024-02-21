#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m, n, ans = 0;

    vector<vector<int>> dir = 
    {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
void solve(int row, int col, vector<vector<int>>& grid, int count){
        
        if(row>=m || col>= n|| row<0 || col<0 || grid[row][col] == -1){
            return ;
        }
        
        if(grid[row][col] == 2){
            if(count == 0) ans+=1;
            return ;
        }

        grid[row][col] = -1;
        for(int i=0;i<4;i++){
            solve(row+dir[i][0], col+dir[i][1], grid, count-1);
        }
        grid[row][col] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow, startCol, noc = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    startRow = i;
                    startCol = j;
                }

                if(grid[i][j] != -1) noc++;
            }
        }    

        solve(startRow, startCol, grid, noc-1);
        return ans;
    }
};