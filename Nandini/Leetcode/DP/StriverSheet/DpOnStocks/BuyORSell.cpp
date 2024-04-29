#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
   int cost =0, mini = prices[0],profit=0;
   for(int i=0 ; i<prices.size() ; i++)
   {
       cost = prices[i] - mini;
       profit = max(profit,cost);
       mini = min(mini,prices[i]);
   }

   return profit;
}