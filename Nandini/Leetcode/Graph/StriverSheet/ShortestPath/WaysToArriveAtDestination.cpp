#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        
        vector<long long> time(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        time[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty())
        {
            int node = pq.top().second;
            long long curr_time = pq.top().first;
            pq.pop();

            for (auto &it : adj[node])
            {
                int neighbor = it.first;
                long long travel_time = it.second;
                
                if (curr_time + travel_time < time[neighbor])
                {
                    time[neighbor] = curr_time + travel_time;
                    ways[neighbor] = ways[node];
                    pq.push({time[neighbor], neighbor});
                }
                else if (curr_time + travel_time == time[neighbor])
                {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % 1000000007;
                }
            }
        }
        
        return ways[n - 1];
    }
};
