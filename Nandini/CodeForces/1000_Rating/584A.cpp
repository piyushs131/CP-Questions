#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string ans = "";
    if(b/10==0)
    {
        for(int i=0 ; i<a ; i++)
        {
            ans+=to_string(b);
        }
    }
    else 
    {
        if(a>1)
        {
            ans+="1";
            for(int i=0 ; i<a-1 ; i++)
            {
                ans+="0";
            }
        }
        else 
        {
            cout << -1 ;
            return 0;
        }
    }
    cout << ans ;
    return 0;
}
