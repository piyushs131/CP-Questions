#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int p1 = 0, p2 = n - 1,ans =0;
    int num = arr[p2];
    while (p1 < p2)
    {
        
        num = num + arr[p2];
        p1++;
        if (d >= num)
            continue;
        else
        {
            ans++;
            p2--;
            num = arr[p2];
        }
    }
    cout << ans;
}
int main()
{
        solve();
}