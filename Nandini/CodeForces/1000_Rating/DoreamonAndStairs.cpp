#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m;
    cin >> n >> m;
    if(n<m)
    {
        cout << -1 ;
        return 0;
    }
    int k ;
    if(n%2==0)
    {
        k = n/2;
        while(k%m!=0)
        {
            k++;
        }
        cout << k;
    }
    else 
    {
        k = n/2 +1;
        while(k%m!=0)
        {
            k++;
        }
        cout << k;
    }
}