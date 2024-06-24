#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    ll sum =0;
    for(int i=0 ;i<n ; i++)
    {
        if(a[i]-'0'+b[i]-'0'==1)
        {
           sum+= 2;
        }
        else if(a[i]-'0'+b[i]-'0'==0)
        {
            if(i+1<n && a[i+1]-'0'==1 && b[i+1]-'0'==1)
            {
               sum+= 2;
               i++;
            }
            else if(i+1<n && a[i+1]-'0'+b[i+1]-'0'==1)
            {
                sum+=3;
                i++;
            }
            else if(i+1<n && a[i+1]-'0'+b[i+1]-'0'==0)
            {
                sum+=1;
            }
            else if(i+1>=n)
            {
                sum+=1;
            }
            else 
            {
                sum+=2;
            }
        }
        else if(a[i]-'0'==1 && b[i]-'0'==1)
        {
            if(i+1<n && (a[i+1]-'0'+b[i+1]-'0'==0 || a[i+1]-'0'+b[i+1]-'0'==1))
            {
                sum+=2;
                i++;
            }
            else
            {
                sum+=0;
            }
        }
        else if(a[i]-'0'+b[i]-'0'==4 || a[i]-'0'+b[i]-'0'==3)
        sum+=0;
        else if((a[i]-'0'==2 && b[i]-'0'==0) || (a[i]-'0'==0 && b[i]-'0'==2))
        {
          sum+=1;
        }
        else
        sum+=0;
    }
    cout << sum << endl;
    
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