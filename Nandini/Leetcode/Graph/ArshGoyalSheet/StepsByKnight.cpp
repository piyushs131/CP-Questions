#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
	int minStepToReachTarget(vector<int>&start,vector<int>&end,int n)
	{
	    queue<pair<pair<int,int>,int> > q;
	    q.push({{start[0]-1,start[1]-1},0});
	    int drow[8] = {2,-2,2,-2,-1,-1,1,1};
	    int dcol[8] = {1,1,-1,-1,2,-2,2,-2};
	    
	    if(start[0]-1==end[0]-1 && start[1]-1 == end[1]-1) return 0;

		vector<vector<bool> > vis(n,vector<bool> (n,false));
		vis[start[0]-1][start[1]-1] = true;
	    while(!q.empty())
	    {
	       int r = q.front().first.first;
	       int c= q.front().first.second;
	       int s = q.front().second;
	       q.pop();
	       for(int i=0 ; i<8 ; i++)
	       {
	           int newr = drow[i]+r;
	           int newc = dcol[i]+c;
	           if(newr>=0 && newc>=0 && newr<n && newc<n && !vis[newr][newc])
	           {
	               if(end[0]-1==newr && end[1]-1 ==newc)
	               return s+1;
	               
	               vis[newr][newc] = true;
	               q.push({{newr,newc},s+1});
	           }
	       }
	    }
	    
	    return 0;
	}
};
int main()
{
	Solution obj;
	vector<int> a = {4,5};
	vector<int> b = {1,1};
	cout << "ans=" << obj.minStepToReachTarget(a,b,6);
}