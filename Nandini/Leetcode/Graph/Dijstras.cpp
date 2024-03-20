#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,S});
        vector<int> temp(n,1e9);
        temp[S] =0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if(temp[adjNode] > edgeWeight+dis)
                {
                    temp[adjNode] = edgeWeight+dis;
                    pq.push({edgeWeight +dis,adjNode});
                }
            }
        }
        return temp;
    }
};