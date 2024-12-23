#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n)
{
    for(int i=2 ; i<n ; i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
void solve()
{
    ll d,n,prev = -1,count=0;
    cin >> d;
    int x = d+1,ans1=0,ans2=0;
    while(true)
    {
        if(isPrime(x))
        {
            ans1 = x;
            break;
        }
        x++;
    }
    x+=d;
     while(true)
    {
        if(isPrime(x))
        {
            ans2 = x;
            break;
        }
        x++;
    }
    cout << ans1*ans2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}