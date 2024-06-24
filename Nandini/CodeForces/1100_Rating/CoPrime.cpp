#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll a, ll b) {
    return __gcd(a, b) == 1;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    unordered_map<ll, ll> last_occurrence;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        last_occurrence[arr[i]] = i;
    }

    ll result = -1;

    for (const auto &pair1 : last_occurrence) {
        for (const auto &pair2 : last_occurrence) {
            if (check(pair1.first, pair2.first)) {
                result = max(result, pair1.second + pair2.second + 2);
            }
        }
    }

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
