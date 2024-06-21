#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int > ans;
        //min heap
        priority_queue<pair<int,int >,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        vector<int> dist(n,1e9);
        dist[s] = 0;
        pq.push({0,s});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dis= pq.top().first;
            pq.pop();
            for(auto it : adj[node])
            {
                if(dist[it[0]] > dis+ it[1])
                {
                    dist[it[0]] = dis+it[1];
                    pq.push({dis+it[1],it[0]});
                }
            }
        }

        return dist;
    }
};
