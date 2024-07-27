	#include <bits/stdc++.h>
	using namespace std;
	#define ll long long

	void solve() {
		ll n, k;
		cin >> n >> k;
		vector<ll> in(n);
		vector<ll> c(n);

		for (ll i = 0; i < n; i++) {
			cin >> in[i];
		}

		for (ll i = 0; i < n; i++) {
			cin >> c[i];
		}

		// Priority queue to keep track of the maximum element
		priority_queue<pair<ll, ll>> pq;

		for (ll i = 0; i < n; i++) {
			pq.push({in[i], i});
		}

		ll ans = 0;
		while (k--) {
			auto p = pq.top();
			pq.pop();
			ll value = p.first;
			ll index = p.second;

			ans += value;

			ll new_value = max(0LL, in[index] - c[index]);
			in[index] = new_value;

			pq.push({new_value, index});
		}

		cout << ans << endl;
	}

	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);

		int t;
		cin >> t;
		while (t--)
			solve();

		return 0;
	}
