#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,k;
    cin >> n;
    int a=0,b=0,c=0;
    for(int i=0 ; i<n ; i++)
    {
        cin >> k;
        k = k%3;
        if(k==0)
        a++;
        else if(k==1)
        b++;
        else 
        c++;
    }
    if(a==b && b==c)
    {
        cout << 0 << endl;
        return;
    }
    int m =0; 
    n = n/3;
    while(c-a>1 && c!=n && a!=n)
    {
        c--,a++;
        m+=1;
    }
    while(a-b>1 && b!=n && a!=n)
    {
        a--,b++;
        m++;
    }
       while(b-c>1 && c!=n && b!=n)
    {
        b--,c++;
        m+=1;
    }
    while(b-a>1 && b!=n && a!=n)
    {
        a++;b--;
        m+=2;
    }
    while(c-b>1 && c!=n && b!=n)
    {
        b++;c--;
        m+=2;
    }
    while(a-c>1 && c!=n && a!=n)
    {
        c++;a--;
        m+=2;
    }
    
    if(a==b && b==c)
    cout << m << endl;
    else 
    cout << -1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}