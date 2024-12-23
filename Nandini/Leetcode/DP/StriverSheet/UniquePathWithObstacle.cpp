#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9+7);
int findAll(int n,int m,vector<vector<int> > &mat,vector<vector<int> > &dp)
{
    if(n>=0 && m>=0 && mat[n][m]==-1) return 0;
    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

        int f1=0,f2=0;
        f2 = findAll(n-1,m,mat,dp);
        f1 = findAll(n,m-1,mat,dp);
        return dp[n][m] = (f1+f2)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) 
{
    vector<vector<int> > dp(n,vector<int> (m,-1));
    return findAll(n-1,m-1,mat,dp);
}