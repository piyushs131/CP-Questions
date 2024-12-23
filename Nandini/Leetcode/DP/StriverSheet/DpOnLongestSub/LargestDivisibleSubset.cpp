#include <bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
     vector<int> dp(n,1);
     vector<int> hash(n);
     int maxi = 1,lastIndex = 0;
     sort(arr.begin(),arr.end());
     for(int i=0 ; i<n ; i++)
     {
       hash[i] = i;
       for(int j=0 ;j<i ; j++)
       {
          if(arr[i] % arr[j]==0 && dp[i] < dp[j]+1)
          {
             dp[i] = dp[j]+1;
             hash[i] = j;
          }
       }
       if(maxi<dp[i])
       {
           maxi = dp[i];
           lastIndex = i;
       }
     }

     vector<int> temp;
     temp.push_back(arr[lastIndex]);
     while(hash[lastIndex]!=lastIndex)
     {
         lastIndex = hash[lastIndex];
         temp.push_back(arr[lastIndex]);
     }

     reverse(temp.begin(),temp.end());
     return temp;
}