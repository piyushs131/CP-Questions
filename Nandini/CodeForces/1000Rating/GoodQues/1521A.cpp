#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b;
        cin >> a >> b;
        if(b!=1)
        {
            cout << "YES" << endl;
            cout << a*b << " " << a << " " << a*b+a << endl;    
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
