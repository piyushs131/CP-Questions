#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) 
    {
       vector<vector<int> > ans;
        vector<int> v;
        findComb(ans,v,target,cand,0,0);
        return ans;
    }
    void findComb(vector<vector<int> > &ans,vector<int> &v,int tar,vector<int> card,int sum,int i)
    {
        if(sum== tar)
        {
            ans.push_back(v);
            return ;
        }
        if(sum > tar || i>=card.size()) return ;
        
            sum+= card[i];
            v.push_back(card[i]);
            findComb(ans,v,tar,card,sum,i);
            v.pop_back();
            sum-= card[i];
            findComb(ans,v,tar,card,sum,i+1);
    }
};