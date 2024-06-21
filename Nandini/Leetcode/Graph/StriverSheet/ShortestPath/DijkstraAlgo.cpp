#include <bits/stdc++.h>
using namespace std;

class SolutionWithPq
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
//better
class SolutionWithSet
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int > ans;
        //min heap
        set<pair<int,int> > st;
        vector<int> dist(n,1e9);
        dist[s] = 0;
        st.insert({0,s});
        while(!st.empty())
        {
            auto it  = *(st.begin());
            int node = it.second;
            int dis= it.first;
            st.erase(it);
            for(auto it : adj[node])
            {
                if(dist[it[0]] > dis+ it[1])
                {
                    if(dist[it[0]]!=1e9)
                    {
                        st.erase({dist[it[0]],it[1]});
                    }
                    dist[it[0]] = dis+it[1];
                    st.insert({dis+it[1],it[0]});
                }
            }
        }

        return dist;
    }
};