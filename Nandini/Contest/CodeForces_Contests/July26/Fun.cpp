#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n,x,ans=0;
    cin >> n >> x;
	    unordered_map<int, int> pair_sums;

    // Iterate over possible values of a
    for (int a = 1; a <= x - 2; ++a) {
        // Iterate over possible values of b
        for (int b = 1; b <= x - 1 - a; ++b) {
            int sum_ab = a * b;
            if (sum_ab >= n) continue;

            int max_c1 = n / (a + b) - 1; // Ensure that ab + ac + bc <= n
            int max_c2 = x - a - b;       // Ensure that a + b + c <= x
            int max_c = min(max_c1, max_c2);

            if (max_c > 0) {
                // Add max_c valid triplets for this pair (a, b)
                ans += max_c;
            }
        }
    }

	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
