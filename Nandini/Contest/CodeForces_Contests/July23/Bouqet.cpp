#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> petals(n);
    for (int i = 0; i < n; i++) {
        cin >> petals[i];
    }

    sort(petals.begin(), petals.end());

    ll max_petals = 0;
    ll current_cost = 0;
    ll current_petals = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        current_cost += petals[right];
        current_petals += petals[right];

        while (current_cost > m || (right > left && petals[right] - petals[left] > 1)) {
            current_cost -= petals[left];
            current_petals -= petals[left];
            left++;
        }

        if (current_cost <= m) {
            max_petals = max(max_petals, current_petals);
        }
    }

    cout << max_petals << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
