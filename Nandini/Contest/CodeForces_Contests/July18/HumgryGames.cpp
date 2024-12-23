#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

void solve()
{
  ll n,x;
  cin >> n >> x;
  vector<ll> v(n+1,0),prefix(n+1,0),dp(n+3,0);
  for(ll i=1 ; i<=n ; i++)
  {
     cin >> v[i];
     prefix[i] = v[i];
     prefix[i]+= prefix[i-1];
  }

  for(ll i=n ; i>=1 ; i--)
  {
    if(v[i]>x)
    dp[i] += dp[i+1]; // 0 kr diya
    else 
    {
      ll l = i;
      ll r = n;
      ll index = i;
      while(l<=r)
      {
        ll mid = (l+r)/2;
        ll curSum = prefix[mid]-prefix[i-1];
        if(curSum<=x)
        {
          index = mid;
          l = mid+1;
        }
        else 
        {
          r =mid-1;
        }
      }
      dp[i] = index-i+1;
      dp[i] += dp[index+2];
    }
  }

  ll ans =0;
  for(int i=1 ;i <=n ; i++) 
  ans += dp[i];

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
