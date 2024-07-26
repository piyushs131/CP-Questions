#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> in(n);
    vector<ll> c(n);

    for (ll i = 0; i < n; i++) {
        cin >> in[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Priority queue to keep track of the maximum element
    priority_queue<pair<ll, ll>> pq;

    for (ll i = 0; i < n; i++) {
        pq.push({in[i], c[i]});
    }

    ll ans = 0;
    while (k--) {
        auto p = pq.top();
        pq.pop();

        ans += p.first;

        ll new_value = max(0LL, p.first - p.second);
        pq.push({new_value, p.second});
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
