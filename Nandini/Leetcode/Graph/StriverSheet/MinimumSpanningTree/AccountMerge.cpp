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
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) 
    {
       int n =  acc.size(); 
        unordered_map<string,int> mp;
        DisjointSet ds(n);

        // storing mails at the index
        for(int i=0 ;i <n ;i ++)
        {
            for(int j=1 ; j<acc[i].size() ; j++)
            {
                string mail = acc[i][j];
                if(mp.find(mail)!=mp.end())
                {
                   int oldI= mp[mail];
                   ds.unionByRank(oldI,i);
                }
                else 
                mp[mail]= i;
            }
        }


        //merging the mails
        vector<string> v[n];
        for(auto it : mp)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            v[node].push_back(mail);
        }

        //sorting ans storing name and mail in ans
        vector<vector<string> > ans;
        for(int i=0 ; i<n ;i ++)
        {
            if(v[i].size()==0) continue;
            sort(v[i].begin(),v[i].end());
            vector<string> temp;
            temp.push_back(acc[i][0]);
            for(auto it : v[i])
            temp.push_back(it);
            
            ans.push_back(temp);
        }
        return ans;
    }
};