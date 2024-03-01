#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> minPartition(int N)
    {
       vector<int> coins{1,2,5,10,20,50,100,200,500,2000};
       vector<int> ans;
       for(int i=coins.size()-1 ; i>=0 ; i--)
       {
           if(coins[i]>N)
           continue;
           
           else 
           {
               ans.push_back(coins[i]);
               N = N-coins[i];
               i++;
           }
       }
       
       return ans;
    }
};