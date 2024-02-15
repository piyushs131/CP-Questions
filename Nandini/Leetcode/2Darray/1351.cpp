#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
       int i,j,n = grid.size(),m = grid[0].size(),count=0;
        for(i=0 ;i <n; i ++)
        {
            for(j=m-1 ; j>=0 ; j--)
            {
                if(grid[i][j] <0 )
                    count ++;
                
                else 
                break;
            }
        }
        return count;
    }
};
