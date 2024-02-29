#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool cmp(pair<double,Item> a,pair<double,Item> b)
    {
        return a.first>b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item> > v;
        int i;
        for( i=0 ; i<n ; i++)
        {
            double perUnitValue = (arr[i].value*1.0)/arr[i].weight; 
            pair<double,Item> p = make_pair(perUnitValue,arr[i]);
            v.push_back(p);
        }
        
        double ans=0;
        sort(v.begin(),v.end(),cmp);
        for(i=0 ;i <n ; i++)
        {
            if(W<v[i].second.weight)
            {
                //toh main siraf fraction le sakta hu
                ans+=W*(v[i].first);
                W=0;
            }
            else
            {
              ans+=v[i].second.value;     
              W = W-v[i].second.weight;  
            }
        }
        return ans;
    }
};