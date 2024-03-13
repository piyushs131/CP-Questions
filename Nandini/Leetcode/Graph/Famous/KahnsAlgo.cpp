#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(n,0);
	    vector<int> ans;
	    for(int i=0 ; i<n ; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0 ; i <n ; i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front(); q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    
	    return ans;
	}
};