class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid2[row][col] == 1) 
                {
                    bool isSubIsland = true;
                    dfs(row, col, grid1, grid2, isSubIsland);
                    if (isSubIsland) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

private:
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &isSubIsland) {
        int n = grid1.size();
        int m = grid1[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m || grid2[row][col] == 0) {
            return;
        }

        if (grid1[row][col] == 0) {
            isSubIsland = false;
        }

        grid2[row][col] = 0;

        dfs(row - 1, col, grid1, grid2, isSubIsland); 
        dfs(row + 1, col, grid1, grid2, isSubIsland); 
        dfs(row, col - 1, grid1, grid2, isSubIsland); 
        dfs(row, col + 1, grid1, grid2, isSubIsland); 
    }
};