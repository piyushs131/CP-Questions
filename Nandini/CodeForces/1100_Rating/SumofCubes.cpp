#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    ll left = 1, right = cbrt(n);

    while (left <= right) {
        ll a = left * left * left;
        ll b = right * right * right;

        if (a + b == n) {
            cout << "YES" << endl;
            return;
        }
        else if (a + b < n) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
