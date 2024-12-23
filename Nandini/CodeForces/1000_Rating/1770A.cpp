#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m,k;
        ll sum =0;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        priority_queue<ll,vector<ll> ,greater<ll> > pq;
        for (int i = 0; i < n; i++) {
            cin >> k;
            pq.push(k);
        }
        for (int i = 0; i < m; i++) {
            pq.pop();
            cin >> k;
            pq.push(k);
        }
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        cout << sum << endl;
        
    }
    return 0;
}
