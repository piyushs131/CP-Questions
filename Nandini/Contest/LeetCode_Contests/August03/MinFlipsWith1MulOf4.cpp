#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) 
    {
       int n = grid.size(), m = grid[0].size();
       int ans =0;
       for(int i=0 ; i<n/2 ; i++)
       {
        for(int j=0 ; j<m/2 ; j++)
        {
            long x = grid[i][j];
            x+= grid[n-i-1][j];
            x+=grid[n-i-1][m-j-1];
            x+=grid[i][m-j-1];
            ans+=min(x,4-x);
        }
       }

       int c =0;
       int count =0;
       // problem when no. of row or cols are odd
       if(n%2)
       {
        // applying on middle row
         for(int j=0 ; j<m/2 ; j++)
         {
            if(grid[n/2][j]!=grid[n/2][m-j-1])
            {
                ans++;
                count++;
            }
            if((grid[n/2][j]==grid[n/2][m-j-1] && grid[n/2][j]==1))
            {
                c++;
            }
         }
       }
       if(m%2)
       {
        // applying on middle col
         for(int j=0 ; j<n/2 ; j++)
         {
            if(grid[j][m/2]!=grid[n-j-1][m/2])
            {
                ans++;
                count++;
            }
            if((grid[j][m/2]==grid[n-j-1][m/2] && grid[j][m/2]==1))
            {
                c++;
            }
         }
       }

       if((c%2==1) && (count==0)) ans+=2;
       if(n%2==1 && m%2==1 && grid[n/2][m/2]==1) ans++;
       return ans;
       
    }
};