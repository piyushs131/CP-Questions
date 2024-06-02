#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n-1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        vector<long long> ans;
        ans.push_back(1000);
        for (int i = 1; i < n ; i++)
        {
            ans.push_back(arr[i-1]+ans[i-1]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";

        cout << endl;
    }
}