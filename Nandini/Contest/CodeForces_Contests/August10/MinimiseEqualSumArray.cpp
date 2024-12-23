#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i=1 ; i<n ; i++) cout << arr[i] << " ";
    cout << arr[0] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
