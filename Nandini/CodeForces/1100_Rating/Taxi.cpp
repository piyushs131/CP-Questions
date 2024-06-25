#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mp[k]++;
    }

    int ans = 0;
    ans += mp[4];
    mp[4] = 0;
    ans += mp[3];
    if (mp[1] >= mp[3]) {
        mp[1] -= mp[3];
    } else {
        mp[1] = 0;
    }
    mp[3] = 0;

    ans += mp[2] / 2;
    mp[2] %= 2;
    if (mp[2] > 0) {
        ans++;
        if (mp[1] >= 2) {
            mp[1] -= 2;
        } else {
            mp[1] = 0;
        }
        mp[2] = 0;
    }

    ans += (mp[1] + 3) / 4;

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
