#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
       sort(candies,candies+n);
       int mini =0;
       int buy = 0;
       int free = n-1;
       while(buy<=free)
       {
           mini = mini+ candies[buy];
           free =free -k;
           buy++;
       }
       
       int maxi =0;
       buy =n-1;
       free =0;
       while(free<=buy)
       {
           maxi =maxi+candies[buy];
           free = free+k;
           buy--;
       }
       vector<int> ans;
       ans.push_back(mini);
       ans.push_back(maxi);
       return ans;
    }
};