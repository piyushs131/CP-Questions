#include <bits/stdc++.h>
using namespace std;
int f(int ind,int prev,int arr[],int n,vector<vector<int> > &dp)
{
    if(ind==n) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

    int len = 0+f(ind+1,prev,arr,n,dp);
    if(prev==-1 || arr[ind]>arr[prev])
    len = max(len,1+f(ind+1,ind,arr,n,dp));

    return dp[ind][prev+1] = len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int> > dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}
int longestIncreasingSubsequence2_spaceOptimised(int arr[], int n)
{
    vector<int> next(n+1,0),curr(n+1,0);
    int len;
    int prev;
    for(int ind=n-1 ; ind>=0 ; ind--)
    {
        for( prev = ind-1 ; prev>=-1 ; prev--)
        {
            //                                +1 because can't be -1
              len = 0+next[prev+1];
             if(prev==-1 || arr[ind]>arr[prev])
             len = max(len,1+next[ind+1]);

             curr[prev+1] = len;
        }
        next = curr;
    }
    return next[-1+1];
}
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0 ; i<n ; i++)
    {
        for(int prev = 0 ; prev<i ; prev++)
        {
            if(arr[prev]<arr[i])
            {
                dp[i] = max(dp[i],1+dp[prev]);
            }
        }

        maxi = max(maxi,dp[i]);
    }
    return maxi;
    }
};

int longestIncreasingSubsequence_best(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1 ; i<n ; i++)
    {
        if(arr[i]>temp.back())
        temp.push_back(arr[i]);
        else 
        {
             auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            *it = arr[i];
        }
    }
    return temp.size();
}
