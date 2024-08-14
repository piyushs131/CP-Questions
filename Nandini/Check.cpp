#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((int)(x).size())
#define endl "\n"

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;

const ll INF = 0xFFFFFFFFFFFFFFFLL;

bool check_validity(const string &s, const vi &arr, int n) {
    map<char, ll> char_to_int;
    map<ll, char> int_to_char;

    FOR(j, n) {
        char c = s[j];
        ll v = arr[j];
        if (char_to_int.count(c) && char_to_int[c] != v) return false;
        if (int_to_char.count(v) && int_to_char[v] != c) return false;
        char_to_int[c] = v;
        int_to_char[v] = c;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vi arr(n);
        FOR(i, n) cin >> arr[i];

        ll m;
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            if (SIZE(s) != n) {
                cout << "NO" << endl;
                continue;
            }
            cout << (check_validity(s, arr, n) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
