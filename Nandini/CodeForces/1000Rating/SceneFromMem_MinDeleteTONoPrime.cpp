#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool notPrime(int n)
{
    for(int i=2 ; i<n/2 ; i++)
    {
       if(n%i==0)
       return true;
    }
    return false;
}
void solve()
{
    int n,k;
    cin >> n;
    string a;
    cin >> a ;
    for(int i=0 ; i<n ; i++)
    {
        if(a[i]!='2' && a[i]!='3' && a[i]!='5' && a[i]!='7')
        {
            cout << 1 << endl;
            cout << a[i] << endl;
            return;
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            k = a[i]-'0';
            k*=10;
            k+=(a[j]-'0');
            if(notPrime(k))
            {
                cout << 2 << endl;
                cout << k << endl;
                break;
            }
        }
        if(notPrime(k))
        break;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}