#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> indegree(V,0);
	    for(int i=0 ; i<V ; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0 ; i<indegree.size() ; i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int tp = q.front();
	        q.pop();
	        ans.push_back(tp);
	        for(auto it : adj[tp])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return ans;

	}
};