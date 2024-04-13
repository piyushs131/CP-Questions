#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s,t;
        int count =0;
        cin >> s >> t;
        int n = s.size(),m = t.size();
        if(m==1)
        {
            if(t[0]=='a')
            cout << 1 << endl;
            else 
            {
                cout << n*2 << endl;
            }
        }
        else 
        {
            for(int i=0 ;i <m ; i++)
            if(t[i]=='a')
            count++;

            if(count>0)
            {
                cout << -1 << endl;
            }
            else 
            {
                cout << 2*n << endl; 
            }
        }
    }
}