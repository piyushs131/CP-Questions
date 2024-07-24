#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> petals(n);
    vector<ll> quan(n);
    for (ll i = 0; i < n; i++) {
        cin >> petals[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> quan[i];
    }

    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++) {
        v.push_back({petals[i], quan[i]});
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p = v[i].first, q = min(m / p, v[i].second);
        ans = max(ans, p * q);
    }

    for (int i = 0; i < n - 1; i++) {
        ll p1 = v[i].first, q1 = v[i].second;
        ll p2 = v[i + 1].first, q2 = v[i + 1].second;

        if (p2 - p1 > 1) continue;

        if (p1 * q1 <= m) {
            const ll lef = m - p1 * q1;
            const ll q = min(q2, lef / p2);
            ans = max(ans, p1 * q1 + q * p2);
        }

        if (p2 * q2 <= m) {
            const ll lef = m - p2 * q2;
            const ll q = min(q1, lef / p1);
            ans = max(ans, p2 * q2 + q * p1);
        }

        const ll sumIJ = min({m / p1, (m + q1) / p2, q1 + q2});
        const ll minVal = p1 * sumIJ + max(0LL, sumIJ - q1);
        const ll maxVal = p2 * sumIJ - max(0LL, sumIJ - q2);
        if (minVal > m) continue;
        if (maxVal <= m) ans = max(ans, maxVal);
        else ans = max(ans, m);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
