#include<bits/stdc++.h>
using namespace std;
bool checkSub(vector<int> &arr,int ind,int k,vector<vector<int>> &dp)
{
    if(0==k) return true;
    if(ind==0) return arr[0]==k;
    if(dp[ind][k]!=-1) return dp[ind][k];

    int notTake = checkSub(arr,ind-1,k,dp);
    int take = false;
    if(k>=arr[ind])
    take = checkSub(arr,ind-1,k-arr[ind],dp);

    return dp[ind][k]= take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int> > dp(n+1,vector<int> (k+1,-1));

    return checkSub(arr,n-1,k,dp);
}