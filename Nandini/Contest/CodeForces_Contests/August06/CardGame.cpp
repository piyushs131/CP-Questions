#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
   int a1,a2,b1,b2;
   cin >> a1 >> a2 >> b1 >> b2;
   int count=0;
   int arr1[2] = {a1,a2};
   int arr2[2] ={b1,b2};
   for(int i=0 ; i<2 ; i++){
    for(int j=0 ; j<2 ; j++){
        int sr =0,lr=0;
        if(arr1[i]>arr2[j]) sr++;
        else if(arr1[i]<arr2[j])lr++;

        if(arr1[1-i] >arr2[1-j]) sr++;
        else if(arr1[1-i]<arr2[1-j])lr++;

        if(sr>lr) count++;
    }
   }

   cout << count << endl;
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
