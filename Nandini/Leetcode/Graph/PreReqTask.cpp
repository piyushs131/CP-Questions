#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPossible(int n,int P, vector<pair<int, int> >& pre) 
	{
	    vector<int> adj[n];
	    for(auto it : pre)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    queue<int> q;
	    vector<int> ans;
	    vector<int> indegree(n,0);
	    for(int i=0 ; i<n ; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0 ; i<n ;i ++){
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
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    
	    if(ans.size()==n) return true;
	    return false;   
	}
};
