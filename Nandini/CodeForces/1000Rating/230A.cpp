#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    int s, n, a, b;
    cin >> s >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        p.push_back({a, b});
    }

    sort(p.begin(), p.end(), cmp);
    int i=0;
    while (!p.empty())
    {
        if (s >= p[i].first)
        {
            s += p[i].second;
            p.erase(p.begin() + i-1);
            if(i>0)
            i=-1;
        }
        else
        i++;
        if(i>=n) break;
    }
    if(p.empty()) cout << "YES";
    else 
    cout << "NO";
}