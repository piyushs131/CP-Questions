#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(vector<int> adj[],int st,vector<int> &color)
    {
        queue<int> q;
	    q.push(st);
	    color[st] = 0;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        for(auto nbr: adj[node])
	        {
	            if(color[nbr]==-1)
	            {
	                color[nbr] = !color[node];  
	                q.push(nbr);
	            }
	            else if(color[node]==color[nbr])
	                {
	                    return false;
	                }
	         }
	    }
	    return true;
    }
	bool isBipartite(int n, vector<int>adj[])
	{
	    vector<int> color(n,-1);
	    for(int i=0 ; i<n ; i++)
	    {
	        if(color[i]==-1)
	        if(bfs(adj,i,color)==false)
	        return false;
	    }
	    return true;
	}

};


//DFS

class Solution1 {
public:
    bool dfs(vector<int> adj[],int st,int col,vector<int> &color)
    {
        color[st] = col;
        for(auto nbr : adj[st])
        {
            if(color[nbr]==-1)
            {
              if(dfs(adj,nbr,!col,color)==false)
              return false;
            }
            
            else if(color[nbr]==col)
            return false;
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[])
	{
	    vector<int> color(n,-1);
	    for(int i=0 ; i<n ; i++)
	    {
	        if(color[i]==-1)
	        if(dfs(adj,i,0,color)==false)
	        return false;
	    }
	    return true;
	}

};

