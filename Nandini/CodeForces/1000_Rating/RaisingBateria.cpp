#include <bits/stdc++.h>
using namespace std;
int fun(int x)
{
    int i = 1;
    while (i <= x)
    {
        i = i * 2;
    }
    return x - (i / 2);
}
int main()
{
    int x;
    cin >> x;
    int ans =0;
    while (x != 0)
    {
        x = fun(x);
        ans++;
    }
    cout << ans ;
}