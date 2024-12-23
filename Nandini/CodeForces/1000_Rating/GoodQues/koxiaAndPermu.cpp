#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int maxi = n, mini = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << maxi << " ";
            maxi--;
        }
        else
        {
            cout << mini << " ";
            mini++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}