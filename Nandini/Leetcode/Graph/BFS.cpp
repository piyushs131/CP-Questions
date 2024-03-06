#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfsOfGraph(int n, vector<int> adj[]) 
    {
       int vis[n]= {0};
       vis[0] = 1;
       queue<int> q;
       vector<int> ans;
       q.push(0);
       while(!q.empty())
       {
           int node = q.front(); q.pop();
           ans.push_back(node);
           for(auto v : adj[node])
           {
               if(!vis[v])
               {
                   vis[v] = 1;
                   q.push(v);
               }
           }
       }
       
       return ans;
    }
};
