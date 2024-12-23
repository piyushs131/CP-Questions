#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

void solve()
{
  int n,k;
  cin >> n >> k;
  if(n==1)
  {
    cout << k << endl;
    return;
  }
  vector<int> v(n*2-1,0);
  for(int i=0  ; i<n ; i++)
  {
    for(int j=0 ; j<n ;j ++)
    {
       v[i+j]++;
    }
    // cout << endl;
  }
  sort(v.begin(),v.end(),greater<int>());
  int i=0;
  int ans =0;
  // for(int i=0 ;i <v.size() ; i++)
  // cout << v[i] << " ";

  // cout << endl;
  while(k>0)
  {
    // cout << "v=" << v[i] << ",k=" << k << endl;
    if(v[i]<k)
    {
      k -= v[i];
      i++;
      ans++;
    }
    else 
    {
       k=0;
       ans++;
    }
  }
  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
