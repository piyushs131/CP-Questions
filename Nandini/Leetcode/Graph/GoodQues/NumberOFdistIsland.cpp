#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int> > vec;
                    dfs(grid,vis,vec,i,j,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
    
    void dfs(vector<vector<int> > &grid,vector<vector<int> >&vis,vector<pair<int,int> >&ans,
    int row,int col,int row0,int col0)
    {
        vis[row][col] = 1;
        ans.push_back({row-row0,col-col0});
        
        if(row+1<grid.size() && grid[row+1][col]==1 && vis[row+1][col]==0)
        dfs(grid,vis,ans,row+1,col,row0,col0);
        
        if(col-1>=0 && grid[row][col-1]==1 && vis[row][col-1]==0)
        dfs(grid,vis,ans,row,col-1,row0,col0);
        
        if(row-1>=0 && grid[row-1][col]==1 && vis[row-1][col]==0)
        dfs(grid,vis,ans,row-1,col,row0,col0);
        
        if(col+1<grid[0].size() && grid[row][col+1]==1 && vis[row][col+1]==0)
        dfs(grid,vis,ans,row,col+1,row0,col0);
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}