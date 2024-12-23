#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    bool bfs(int node,vector<vector<int> > &graph,vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] =0;
        while(!q.empty())
        {
            int tp = q.front() ; q.pop();
            int cl = color[tp];
            for(auto it : graph[tp])
            {
                if(color[it]==-1)
                {
                    color[it] = !cl;
                    q.push(it);
                }
                else 
                {
                    if(color[it]==cl)
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
         int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0 ; i< n ; i++)
        {
            if(color[i]==-1)
                if(bfs(i,graph,color)==false)return false;
        }
       return true;
    }
};
class Solution2 {
public:
    bool dfs(int node,vector<vector<int> > &graph,vector<int> &color,int clr)
    {
        color[node] = clr;
        for(auto it : graph[node])
        {
            if(color[it]==-1)
            {
               if(dfs(it,graph,color,!clr)==false) return false;   
            }
            else if(color[it]==clr)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
         int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0 ; i< n ; i++)
        {
            if(color[i]==-1)
                if(dfs(i,graph,color,0)==false)return false;
        }
       return true;
    }
};