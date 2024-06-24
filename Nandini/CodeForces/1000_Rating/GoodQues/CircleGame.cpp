#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ;i <n ; i++)
    cin >> arr[i];

    if(n%2!=0)
    cout << "Mike" << endl;
    else 
    {
        int sm = INT_MAX,ind,i;
        for(i=0 ; i<n ; i++)
        {
            if(arr[i]<sm){
            sm = arr[i];
            ind = i;}
        }
        if(ind%2==0)
        cout << "Joe" << endl;
        else 
        cout << "Mike" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}