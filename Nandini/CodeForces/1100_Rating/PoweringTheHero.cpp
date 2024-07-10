#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    priority_queue<ll> pq;
    ll power = 0;
    
    for(ll i = 0; i < n; i++) {
        if(arr[i] != 0) 
        {
            pq.push(arr[i]);
        } 
        else if(arr[i] == 0 && !pq.empty()) 
        {
            power += pq.top();
            pq.pop();
        }
    }
    
    cout << power << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
