#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n,k;
    cin >> n >> k;
    int ans =0;
    if(n-k > k-1)
    {
       int nbr = 2*(k-1) + n-k; 
       int pick = n;
       int fankna = n+1;
       cout << nbr+pick+fankna ;
    }
    else 
    {
       int nbr = 2*(n-k) + k-1; 
       int pick = n;
       int fankna = n+1;
       cout << nbr+pick+fankna ;
    }
}

int main()
{
   solve();
}
