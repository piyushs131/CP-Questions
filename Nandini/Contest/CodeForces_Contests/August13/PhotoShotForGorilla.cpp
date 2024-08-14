#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll> 
void solve()
{
    ll n,m,k,w;
    cin >> n >> m >> k >> w;
    vi a(w);
    for(auto &x: a) cin >> x;

    vi b;
    for(ll i=1 ; i<=n ; i++)
    {
        for(ll j=1 ; j<=m ; j++)
        {
          ll lx = max(1LL,i-k+1), ly = max(1LL,j-k+1);
          ll rx = min(i,n-k+1), ry = min(j,m-k+1);
          ll count = (rx-lx+1) * (ry-ly+1);
          b.push_back(count);
        }
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    ll ans =0;
    for(int i=0 ; i<w ; i++) ans+= a[i]*b[i];
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}
