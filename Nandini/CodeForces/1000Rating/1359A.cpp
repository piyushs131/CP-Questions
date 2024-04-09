#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n,m,k;
    while(t--)
    {
      cin >> n >> m >> k;
      int cards = n/k;
      if(cards>=m)
      {
         cout << m << endl;
      }
      else
      {
         int rem = m-cards;
         int other =ceil(1.0*rem/(k-1));
         cout << cards-other << endl;
      }
    }
}