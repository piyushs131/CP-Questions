#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void dfs(stack<int> &st,vector<bool> &vis,vector<int> adj[],int node)
	{
	    vis[node] = true;
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(st,vis,adj,it);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> st;
	    vector<bool> vis(V,false);
	    for(int i=0 ; i<V ; i++)
	    {
	        if(!vis[i])
	        dfs(st,vis,adj,i);
	    }
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;

	}
};