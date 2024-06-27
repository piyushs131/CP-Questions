#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int timer=0;
  void dfs(int node,int parent,vector<int>&vis,int time[],int low[],vector<int>&mark,vector<int> adj[])
  {
      vis[node] = 1;
      low[node] = time[node] = timer;
      timer++;
      int child =0;
      for(auto it: adj[node])
      {
          if(it==parent) continue;
          if(!vis[it])
          {
              dfs(it,node,vis,time,low,mark,adj);
              low[node] = min(low[it],low[node]);
              
              if(low[it]>=time[node] && parent!=-1)
              {
                  mark[node] = 1;
              }
              child++;
          }
          else 
          {
              low[node] = min(low[node],time[it]);
          }
      }
      if(child>1 && parent==-1)
      mark[0] = 1;
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
        vector<int> vis(V,0);
        int low[V];
        int time[V];
        vector<int> mark(V,0);
        for(int i=0 ; i<V ;i ++)
        {
            if(!vis[i])
            dfs(i,-1,vis,time,low,mark,adj);
        }
        vector<int> ans;
        for(int i=0 ;i <V ; i++)
        if(mark[i])
        ans.push_back(i);
        
        if(ans.size()==0) return {-1};
        return ans;
    }
};