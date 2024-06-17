#include<bits/stdc++.h>
using namespace std;
class Solution1
{
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) 
    {
        vector<vector<int> > ans(V);
        for(int i=0 ;i <edges.size() ; i++)
        {
            ans[edges[i].first].push_back(edges[i].second);
            ans[edges[i].second].push_back(edges[i].first);
        }
        return ans;
    }
};
int main()
{
    vector<pair<int,int> > edges{{0,1},{0,4},{4,1},{4,3}};
    Solution1 obj;
    vector<vector<int> > ans = obj.printGraph(5,edges);
}