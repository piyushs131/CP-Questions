#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<int>&vis,stack<int> &st,int node)
	{
	    vis[node] = 1;
	    for(auto it : adj[node])
	    {
	        if(vis[it]==-1)
	        {
	            dfs(adj,vis,st,it);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> vis(n,-1);
	    vector<int> ans;
	    for(int i=0 ; i<n ; i++)
	    {
	        if(vis[i]==-1)
	        dfs(adj,vis,st,i);
	    }
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
