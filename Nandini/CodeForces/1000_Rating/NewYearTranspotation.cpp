#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    int cover = 0, i = 0;
    while (i < n - 1)
    {

        if (i + 1 == t)
        {
            cout << "YES";
            return;
        }
        i = i + arr[i];
    }
    if (i + 1 == t)
    {
        cout << "YES";
        return;
    }
    cout << "NO";
}
int main()
{
    solve();
}