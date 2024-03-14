#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(vector<int> adj[],int vis[],int check[],int pathvis[],int n,int st)
    {
        vis[st] = 1;
        pathvis[st] = 1;
        check[st]= 0;
        for(auto it : adj[st])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,check,pathvis,n,it))
                return true;
            }
            else if(pathvis[it])
            return true;
        }
        check[st] = 1;
        pathvis[st] = 0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) 
    {
        int vis[n] = {0};
        int pathvis[n] = {0};
        vector<int> path;
        int check[n] =  {0};
        for(int i=0 ;i <n ; i++)
        {
            if(!vis[i])
            dfs(adj,vis,check,pathvis,n,i);
        }
        for(int i=0 ; i<n ; i++)
        {
            if(check[i]==1) path.push_back(i);
        }
        return path;
    }
};

class SolutionWithTropoSort {
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) 
    {
            vector<int> adjRev[n];
            int indegree[n] = {0};
            for(int i=0 ; i<n ; i++)
            {
                //i->it
                //it->i
                for(auto it : adj[i])
                {
                    adjRev[it].push_back(i);
                    indegree[i]++;
                }
            }
            
            queue<int> q;
            for(int i=0 ; i<n ; i++)
            {
                if(indegree[i]==0)
                q.push(i);
            }
            
            vector<int> ans;
            while(!q.empty())
            {
                int node = q.front(); q.pop();
                ans.push_back(node);
                for(auto it : adjRev[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
            
            sort(ans.begin(),ans.end());
            return ans;
    }
};
