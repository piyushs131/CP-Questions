#include<bits/stdc++.h>
using namespace std;
class UsingPQ
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

class UsingSet
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int> > st;
        vector<int> dist(n,1e9);
        st.insert({0,S});
        dist[S] = 0;
        while(!st.empty())
        {
            auto it  = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it : adj[node])
            {
                if(it[1]+dis<dist[it[0]])
                {
                    //erase if existed
                    if(dist[it[0]]!=1e9)
                    {
                        st.erase({dist[it[0]],it[0]});
                    }
                    dist[it[0]] = dis+it[1];
                    st.insert({dist[it[0]],it[0]});
                }
            }
        }
        
        return dist;
    }
};