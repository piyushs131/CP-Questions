#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int winnerTeam(int N, vector<int> &x, vector<int> &y, vector<int> &z) {
        int ind1 = 0, ind2 = 0, ind3 = 0; 
        int lastWinner = -1; 
        
        while (ind1 < N && ind2 < N && ind3 < N) {
            int a = x[ind1], b = y[ind2], c = z[ind3];

            if ((a >= b && a >= c) || (a == b && a > c) || (a == c && a > b)) {
                lastWinner = 0; 
                ind2++;
                ind3++;
            } else if ((b > a && b >= c) || (b == c && b > a)) {
                lastWinner = 1; 
                ind1++;
                ind3++;
            } else {
                lastWinner = 2; 
                ind1++;
                ind2++;
            }
        }
        
        //cout << "Ind1=" << ind1 << ",ind2=" << ind2<< ",ind3=" << ind3 << endl;
        if (ind1 == N && ind2 == N) return 2; 
        if (ind1 == N && ind3 == N) return 1;
        if (ind2 == N && ind3 == N) return 0;  
        if (ind1 == N) 
        {
            while(ind2!=N && ind3!=N)
            {
               int b = y[ind2],c = z[ind3];
               if(b>=c) ind3++;
               else ind2++;
            }
            if(ind2==N) return 2;
            else return 1;
        }
        if (ind2 == N) {
            while(ind1!=N && ind3!=N)
            {
               int b = x[ind1],c = z[ind3];
               if(b>=c) ind3++;
               else ind1++;
            }
            if(ind1==N) return 2;
            else return 0;
        }
        if (ind3 == N) {
            while(ind2!=N && ind1!=N)
            {
               int b = x[ind1],c = y[ind2];
               if(b>=c) ind2++;
               else ind1++;
            }
            if(ind2==N) return 0;
            else return 1;
        }

        return lastWinner; 
    }
};