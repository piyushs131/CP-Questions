#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    vector<int> v;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    int i = 0, j = n / 2;
    vector<int> ans;
    while (i < n / 2 && j < n)
    {
        ans.push_back(v[j]);
        j++;
        ans.push_back(v[i]);
        i++;
    }
    while (j < n)
        ans.push_back(v[j++]);
    while (i < n / 2)
        ans.push_back(v[i++]);
    if (n % 2 == 0)
        cout << n / 2 << endl;
    else
        cout << (n - 1) / 2 << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}