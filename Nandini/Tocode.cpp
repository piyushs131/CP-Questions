#include <bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers
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

    // Reading the array elements
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            check = 1;
        }
    }

    // Calculate the GCD of the entire array
    int val = arr[1];
    for (int i = 2; i <= n; i++) {
        val = gcd(val, arr[i]);
    }

    // If there's a 1 in the array or the GCD of the entire array is 1, the cost is 0
    if (check == 1 || val == 1) {
        cout << 0;
        return;
    }

    int cost = n;

    // Check the minimum cost by iterating from the end of the array
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
