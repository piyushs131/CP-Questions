#include <bits/stdc++.h>
using namespace std;
bool isPal(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string s,vector<int> &dp)
{
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];

    int mini =1e9;
    for(int j=i; j<n ;j++)
    {
        if(isPal(i,j,s))
        {
            int cost = 1+ f(j+1,n,s,dp);
            mini = min(cost,mini);
        }
        
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n,-1);
    return f(0,n,str,dp)-1;
}
