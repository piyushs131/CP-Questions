#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    int check = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            check = 1;
        }
    }

    int val = arr[1];
    for (int i = 2; i <= n; i++) {
        val = gcd(val, arr[i]);
    }

    if (check == 1 || val == 1) {
        cout << 0;
        return;
    }

    int cost = n;

    for (int i = n; i > 0; i--) {
        int x = gcd(i, arr[i]);
        int y = gcd(x, val);
        if (y == 1) {
            cost = n - i + 1;
            break;
        }
    }

    vector<int> g(n+1);
    for (int i = 1; i <= n; i++) {
        g[i] = gcd(i, arr[i]);
    }

    reverse(g.begin() + 1, g.end());

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x1 = gcd(g[i], g[j]);
            if (x1 == 1) {
                cost = min(cost, i + j);
            }
        }
    }

    cout << cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}
