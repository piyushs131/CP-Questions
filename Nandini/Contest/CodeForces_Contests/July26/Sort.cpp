#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefixA(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefixB(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < 26; ++j) {
            prefixA[i + 1][j] = prefixA[i][j];
            prefixB[i + 1][j] = prefixB[i][j];
        }
        prefixA[i + 1][a[i] - 'a']++;
        prefixB[i + 1][b[i] - 'a']++;
    }

    while (q--) {
        int a1, a2;
        cin >> a1 >> a2;
        a1--, a2--;

        vector<int> freqA(26, 0), freqB(26, 0);

        // Get the frequency of each character in the range [a1, a2]
        for (int i = 0; i < 26; ++i) {
            freqA[i] = prefixA[a2 + 1][i] - prefixA[a1][i];
            freqB[i] = prefixB[a2 + 1][i] - prefixB[a1][i];
        }

        int operations = 0;
        for (int i = 0; i < 26; ++i) {
            operations += abs(freqA[i] - freqB[i]);
        }

        cout << operations / 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
