#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int, int>& a,pair<int, int>& b)
{
    return a.first < b.first;
}
void solve()
{
    int n;
    cin >> n;
    if(n==1)
    {
        cout << 'a';
        return;
    }
    else if(n==2)
    {
        cout <<"aa" ;
        return;
    }
    int flag = 0;
    for(int i=0 ; i<n ;i ++)
    {
        if(flag%4==0 || flag%4==1)
        {
            cout << 'a' ;
            flag++;
        }
        else 
        {
            cout << 'b';
            flag++;
        }
    }

}

int main()
{
    solve();
}
