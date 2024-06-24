#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   int n,m;
   cin >> n >> m;
   vector<vector<char> > v(n,vector<char>(m,'0'));
   for(int i=0 ;i <n ;i ++)
   for(int j=0 ; j<m ; j++)
   cin >> v[i][j];

   if(n==1)
   {
     if(v[0][0]==v[n-1][m-1])
     cout << "YES" << endl;
     else 
     cout << "NO" << endl;
     return;
   }
   
   if(v[0][0]==v[n-1][m-1] || v[0][m-1]== v[n-1][0])
   {
    cout << "YES" << endl;
    return;
   }
   int f1=0,f2=0,f3=0,f4=0;
   for(int i=0 ; i<m ;i++)
   {
     if(v[0][i]!=v[0][0])f1=1;
     if(v[0][i]!=v[0][m-1])f2 = 1;
     if(v[n-1][i]!=v[n-1][0]) f3=1;
     if(v[n-1][i]!=v[n-1][m-1]) f4 =1;
   }

   for(int i=0 ;i <n ; i++)
   {
     if(v[i][0]!=v[0][0] && f1==1) f1++;
     if(v[i][0]!=v[n-1][0] && f3==1) f3++;
     if(v[i][m-1]!=v[0][m-1] && f2==1) f2++;
     if(v[i][m-1]!=v[n-1][m-1] && f4==1) f4++;
   } 

   if(f1>=2 || f2>=2 || f3>=2 || f4>=2)
   {
    cout << "YES" << endl;
   }
   else 
   cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
