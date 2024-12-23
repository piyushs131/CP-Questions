#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());
    
    int alice = 0, bob = 0;
    bool flag = true;
    
    for (int i = 0; i < n; i++) {
        if (flag) 
            alice += v[i];
        else 
            bob += v[i];
        flag = !flag;
    }

    int ans = alice - bob;
    
    if (ans == 0 || ans <= k) {
        cout << 0 << endl;
    } else {
        cout << ans - k << endl; 
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
