#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll s = 1, e = 1e9, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        ll sum =0;
        for(int i=0 ; i<n ; i++){
            sum+=(v[i]+2*mid) * (v[i]+2*mid);
            if(sum>c)break;
        }
        if(sum==c) {
            cout << mid << endl;
            return;
        }
        else if(sum<c) s = mid+1;
        else e = mid;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
