#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    public :
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++)
        parent[i] = i;
    }
    int getParent(int u)
    {
        if(parent[u]==u) return u;
        return parent[u] = getParent(parent[u]);
    }
    void unionByRank(int u,int v)
    {
        int pu = getParent(u);
        int pv = getParent(v);
        if(pu==pv) return;

        if(rank[pu]<rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv] = pu;
        }
        else 
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n= edges.size(),m = edges[0].size();
        DisjointSet ds(n);
        vector<int> ans;
        for(int i=0 ; i<n ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.getParent(u)==ds.getParent(v))
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            ds.unionByRank(u,v);
        }

        return ans;
    }
};