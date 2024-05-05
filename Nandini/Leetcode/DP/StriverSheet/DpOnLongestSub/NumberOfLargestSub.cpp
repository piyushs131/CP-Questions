#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    int n= arr.size();
    vector<int> dp(n,1),count(n,1);
    int i,j,maxi = 1;
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<i  ; j++)
        {
            if(arr[i] > arr[j] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                count[i] = count[j];
            }
            else if(arr[i] > arr[j] && dp[j]+1 == dp[i])
            count[i]+= count[j];
        }
        maxi = max(maxi,dp[i]);
    }
    int ans =0;
   for( i=0 ; i<n ; i++)
   {
       if(dp[i]==maxi) ans+= count[i];
   }
   return ans;
}