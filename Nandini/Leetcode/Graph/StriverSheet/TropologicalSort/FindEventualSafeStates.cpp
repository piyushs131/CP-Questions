#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
       int n = graph.size();
        vector<int> ans;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0 ; i<n ; i++)
        {
            for(auto it : graph[i])
            {
                indegree[i]++;
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0 ;i <n ;i ++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            ans.push_back(tp);
            for(auto it : adj[tp])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};