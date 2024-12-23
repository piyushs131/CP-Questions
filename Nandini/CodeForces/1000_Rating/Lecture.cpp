#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    set<pair<string, string>> s;
    for(int i = 0; i < m; i++)
    {
        cin >> s1 >> s2;
        s.insert({s1, s2});
    }
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(const auto &p : s)
        {
            if(p.first == str)
            {
                if(p.first.size() <= p.second.size())
                cout << p.first << " ";
                else 
                cout << p.second << " ";

                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
