#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int countA = 0, countB = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A') {
                countA++;
            }
            if (colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B') {
                countB++;
            }
        }
        return countA > countB;
    }
};
