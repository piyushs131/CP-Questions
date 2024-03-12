#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public :
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
  int maxActivities(vector<pair<int,int> > &v)
  {
     int ans =1;
     sort(v.begin(),v.end(),cmp);
     for(int i=0 ; i<v.size()-1 ; i++)
     {
        if(v[i].second<v[i+1].first)
        ans++;
     }
     return ans;
  }
};
int main()
{
    vector<pair<int,int> > v{{3,4},{6,8},{1,2},{4,9},{10,12},{8,12}};
    Solution obj;
    cout << "Max number of acitivites : " << obj.maxActivities(v);
}