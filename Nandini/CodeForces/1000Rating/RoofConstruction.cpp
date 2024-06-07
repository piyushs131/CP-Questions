#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    ll x = log2(n-1);
    x = pow(2,x);
    for(int i= x-1 ; i>=0 ; i--)
    cout << i << " ";
    for(int i=x ; i<n ; i++)
    cout << i << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}
