#include<bits/stdc++.h>
using namespace std;
vector<int> MinimumCoins(int n)
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    for(int i=coins.size()-1 ; i>=0 ; i--)
    {
        if(coins[i]>n)continue;
        else{
            n = n-coins[i];
            ans.push_back(coins[i]);
            i++;
        }
    }
    return ans;
}