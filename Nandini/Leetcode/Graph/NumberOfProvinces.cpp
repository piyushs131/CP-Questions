#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void makeList(vector<int> list[],vector<vector<int> > &adj,int n)
  {
      for(int i=0 ; i<n ;i ++)
      {
          for(int j=0 ; j<adj[i].size() ; j++)
          {
              if(adj[i][j]==1 && i!=j)
              {
                  list[i].push_back(j);
                  list[j].push_back(i);
              }
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int n) 
    {
        vector<int> list[n];
        makeList(list,adj,n);
        int vis[n] = {0};
        int count =0;
        for(int i=0 ;i <n ; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(list,vis,i);
            }
        }
        return count;
    }
    
    void dfs(vector<int> list[],int vis[],int node)
    {
        vis[node] = 1;
        for(auto it : list[node])
        {
            if(!vis[it])
            dfs(list,vis,it);
        }
        
    }
};