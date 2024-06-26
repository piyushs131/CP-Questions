#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
       vector<vector<int> > g(n,vector<int>(n,1e9));
        for(int i=0 ;i <edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            g[u][v] = wt;
            g[v][u] = wt;
        }
        for(int i=0 ; i<n ; i++)
            g[i][i] =0;
        
        for(int k=0 ; k<n ;k++)
        {
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        int ans=INT_MAX,final=0,ct;
        for(int i=0 ;i <n ; i++)
        {
            ct=0;
            for(int j=0 ; j<n ; j++)
            {
                if(g[i][j]<=distanceThreshold)
                    ct++;
            }
            if(ct<=ans)
            {
                ans = ct;
                final = i;
            }
        }
        return final;
    }
};