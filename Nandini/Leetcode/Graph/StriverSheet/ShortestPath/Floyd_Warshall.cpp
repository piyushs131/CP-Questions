#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&cost)
	{
	    int n = cost.size();
	    
	    for(int i=0 ;i <n; i++)
	    {
	        for(int j=0 ; j<n ; j++)
	        {
	            if(cost[i][j]==-1)
	            cost[i][j] = 1e9;
	            
	            if(i==j)cost[i][j]=0;
	        }
	        
	    }
	    for(int k=0 ; k<n ;k++)
	    {
	        for(int i=0 ; i<n ; i++)
	        {
	            for(int j=0 ; j<n ;j++)
	            {
	                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
	            }
	        }
	    }
	    
	   // for(int i=0 ; i<n ; i++)
	   // {
	   //     if(cost[i][i]<0) 
	   //     return;
	        
	   // }
	    
	       for(int i=0 ;i <n; i++)
	    {
	        for(int j=0 ; j<n ; j++)
	        {
	            if(cost[i][j]==1e9)
	            cost[i][j] = -1;
	        }
	        
	    }
	}
};