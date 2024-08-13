#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1 ; i<=n ; i++) cin >> arr[i];
    if(n==1 || n==2) return true;

    vector<bool> check(n+1,false);
    check[arr[1]] = true;
    for(int i=2 ; i<n ; i++)
    {
       int val = arr[i];
       if((val-1>=0 && check[val-1]==true) || (val+1<n+1 && check[val+1]==true))
       {
         check[val] = true;
       }
       else return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--){
        if(solve())
        cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
