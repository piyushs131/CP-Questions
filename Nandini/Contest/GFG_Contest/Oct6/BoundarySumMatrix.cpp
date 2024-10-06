#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> boundarySum(int n, vector<vector<int>> &matrix) 
    {
        int loops = n%2? (n+1)/2: n/2;
        vector<int> final;
        
        int flag =0;
        vector<vector<bool> > vis(n,vector<bool> (n,false));
        for(int m=0; m<loops ; m++)
        {
            int i1=flag;
            int i2=n-1-flag;
            int ans =0;
            for(int j=0+flag ; j<n-flag ; j++)
            {
                // cout << "i1=" << i1 << ",i2=" << i2 << ",j=" << j << endl;
                if(vis[i1][j]==false)
                {
                    ans+= matrix[i1][j];
                    vis[i1][j] = true;
                }
                if(!vis[i2][j])
                ans+= matrix[i2][j];
                vis[i2][j] = true;
            }
            //  cout << "ans=" << ans << endl;
            
            int j1=flag;
            int j2=n-1-flag;
            for(int i=0+flag ; i<n-flag ; i++)
            {
                // cout << "j1=" << j1 << ",j2=" << j2 << ",i=" << i << endl;
                if(vis[i][j1]==false)
                {
                    vis[i][j1] = true;
                    ans+=matrix[i][j1];
                }
                
                if(vis[i][j2]==false)
                ans+=matrix[i][j2];
                vis[i][j2] = true;
                
            }
            // cout << "ans=" << ans << endl;
            final.push_back(ans);
            flag++;
        }
        return final;
    }
};