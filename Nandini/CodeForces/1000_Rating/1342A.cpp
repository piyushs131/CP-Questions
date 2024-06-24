#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,x,y,sum=0;
        cin >> x >> y;
        cin >> a >> b;
        if(a+a<=b)
        {
            cout << (x+y)*a << endl;
        }
        else 
        {
            sum+= min(x,y)*b;
            int t1=min(x,y);
            x-=t1;
            y-=t1;
            sum+= (x+y)*a;
            cout << sum << endl;
        }
    }
}