#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int tag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1] && s[i] != '?')
        {
           cout << -1 << endl;
           return;
        }
        else if (s[i] == '?')
        {
            if (s[i - 1] != 'a' && s[i + 1] != 'a')
            {
                s[i] = 'a';
            }
            else if (s[i - 1] != 'b' && s[i + 1] != 'b')
            {
                s[i] = 'b';
            }
            else
            {
                s[i] = 'c';
            }
        }
    }
        cout << s<< endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}