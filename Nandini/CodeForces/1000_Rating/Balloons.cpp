#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int, int>& a,pair<int, int>& b)
{
    return a.first < b.first;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i=0 ;i <n ; i++)
    {
        int k;cin >> k;
        v.push_back({k,i+1});
    }
    sort(v.begin(), v.end(), cmp); 
    if(v.size()==1)
    {
        cout << -1 ;
    }
    else if(v.size()==2 && v[0].first==v[1].first)
    {
        cout << -1 ;
    }
    else 
    {
        int count =0;
        vector<int> ans;
        cout << v.size()-1 << endl;
        for(auto it : v)
        {
          if(count==0)
          {
            count++;
            continue;
          }
          else 
          {
            ans.push_back(it.second);
          } 
        }
        sort(ans.begin(),ans.end());
        for(auto it : ans)
        cout << it << " ";
    }
}

int main()
{
    solve();
}
