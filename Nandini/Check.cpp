#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x), end(x)
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.rbegin(), v.rend());
    ll ans =0;
     for (int i = 0; i < n; i++) {
       if(i&1) ans-=v[i]; 
       else ans+=v[i];
    }

    vector<ll> b;
    for(int i=1 ; i<n ; i+=2)
    {
        b.push_back(v[i-1]-v[i]);
    }
    
    ans-=min(k,accumulate(all(b),0LL));
    cout << abs(ans) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
