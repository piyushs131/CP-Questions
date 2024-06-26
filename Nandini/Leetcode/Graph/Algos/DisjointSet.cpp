#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent,rank,size;
    public :
    DisjointSet(int n)
    {
        // n+1 because starting with 1
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0 ;i <=n ; i++)
        parent[i] = i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[pv] = pu;
        }
        else 
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv])
        {
            size[pv]+=size[pu];
            parent[pu] = pv;
        }
        else 
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main()
{
    DisjointSet s(7);
    s.unionByRank(1,2);
    s.unionByRank(2,3);
    s.unionByRank(4,5);
    s.unionByRank(6,7);
    s.unionByRank(5,6);

    if(s.findParent(3) == s.findParent(7))
    cout << "Same parent ";
    else 
    cout << "Not same";

    s.unionByRank(3,7);

}