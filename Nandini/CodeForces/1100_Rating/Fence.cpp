#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int i = 0, mini = INT_MAX, ans, ind = 0, sum = 0, num,j;
    if (i + k - 1 < n)
    {
        for ( j = 0; j < k; j++)
            sum += h[j];

         i = j;   
    }
    while (i <= n)
    {
        if (mini > sum)
        {
            mini = sum;
            ans = ind + 1;
        }
        if(i>=n) break;
        sum += h[i];
        sum -=h[ind];
        i++,ind++;
    }
    cout << ans;
}