#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void solveNum(unordered_map<int,vector<int>>& adj,int node,unordered_set<int>& st,vector<int>& ans)
{
    st.insert(node);
    ans.push_back(node);
    for(auto it:adj[node])
    {
        if(st.find(it)==st.end())
        {
            solveNum(adj,it,st,ans);
        }
    }
}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        int n=adjacentPairs.size();
       unordered_map<int,vector<int>> adj;
       unordered_map<int,int> x;
        for(auto it:adjacentPairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            x[it[0]]++;
            x[it[1]]++;
        }
        int head;
        for(auto it:x)
        {
            if(it.second==1){
                head=it.first;
                break;
            }
        }
        unordered_set<int> st;
        vector<int> ans;
        solveNum(adj,head,st,ans);
        return ans;
    }
};