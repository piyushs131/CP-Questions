#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, q, c, count = 0,num,result=0;
        cin >> n >> k >> q;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            v.push_back(c);
        }
        for(int i=0 ; i<n ; i++)
        {
            if(v[i]<=q)
            count++;
            else 
            {
                if(count>=k)
                {
                    num = count-k+1;
                    result += num*(num+1) /2 ;
                }
                count =0;
            }
        }
        if(count!=0 && count>=k)
        {
            num = count-k+1;
            result += num*(num+1) /2 ;
        }
        cout << result << endl;
    }
}