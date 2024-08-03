#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) 
    {
       int r = grid.size(), c= grid[0].size();
       int ans = INT_MAX;
       int rowsPal =0,colPal =0;
       for(int i=0 ;i <r ; i++)
       {
          int lb = 0, ub = c-1;
          while(lb<=ub)
          {
            if(grid[i][lb]!=grid[i][ub])
            {
                rowsPal++;
            }
            lb++,ub--;
          } 
       } 
       for(int j=0 ;j <c ; j++)
       {
          int lb = 0, ub = r-1;
          while(lb<=ub)
          {
            if(grid[lb][j]!=grid[ub][j])
            {
                colPal++;
            }
            lb++,ub--;
          } 
       }

       return min(rowsPal,colPal); 
    }
};