#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        if (n == 1)
        {
            cout << "0\n";
            continue;
        }

        vector<int> distinct_from_start(n, 0), distinct_from_end(n, 0);
        unordered_map<char, int> freq_start, freq_end;

        for (int i = 0; i < n; ++i)
        {
            freq_start[s[i]]++;
            distinct_from_start[i] = freq_start.size();
        }

        for (int i = n - 1; i >= 0; --i)
        {
            freq_end[s[i]]++;
            distinct_from_end[i] = freq_end.size();
        }

        int max_f = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            max_f = max(max_f, distinct_from_start[i] + distinct_from_end[i + 1]);
        }

        cout << max_f << endl;
    }
    return 0;
}
