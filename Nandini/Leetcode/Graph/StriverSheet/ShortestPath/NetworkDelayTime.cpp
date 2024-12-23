#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int> > adj[n+1];
        for(int i=0 ; i<times.size() ; i++)
        {
            int u = times[i][0];
            int v= times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
        pq.push({0,k});
        vector<int> time(n+1,1e9);
        time[k] = 0;
        time[0] = 0;
        while(!pq.empty())
        {
           int t=pq.top().first;
           int node = pq.top().second;
           pq.pop();
           for(auto it : adj[node])
           {
             if(time[it.first]>it.second+t)
             {
                time[it.first] = it.second+t;
                pq.push({time[it.first],it.first});
             }
           }
        }
        int ans =-1;
        for(int i=0 ;i <n+1 ; i++)
        {
            if(time[i]==1e9) return -1;
            if(time[i]>ans)
            ans = time[i];
        }
        return ans;
    }
};