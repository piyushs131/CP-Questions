#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        mp[words[i]]++;
    }

    string ans;
    for (const string& s : words)
    {
        bool found = false;
        int len = s.size();

        for (int i = 1; i < len; i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (mp.count(left) > 0 && mp.count(right) > 0)
            {
                found = true;
                break;
            }
        }

        ans += (found ? "1" : "0");
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
