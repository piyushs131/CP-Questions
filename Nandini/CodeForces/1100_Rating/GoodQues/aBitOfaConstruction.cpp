#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxPowerofTwo(ll n)
{
  ll x= log2(n);
  return pow(2,x);
}
void solve()
{
   ll n,k;
   cin >> n >> k;
   if(n==1)
   {
    cout << k << endl;
    return;
   }
   vector<ll> ans;
   ll x = maxPowerofTwo(k+1);
   x--; // value of 2^x - 1 which contains max 1's
   cout << x << " ";
   cout << k-x << " ";
   for(int i=0 ; i<n-2 ; i++)
   cout << 0 << " ";
   cout << endl;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();
    return 0;
}
