#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int countArrangement(int n) {
        int count = 0;
        vector<bool> used(n + 1, false); 
        countArrangementHelper(n, 1, used, count);
        return count;
    }
    
    void countArrangementHelper(int n, int pos, std::vector<bool>& used, int& count) {
        if (pos > n) {
            count++;
            return;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true; 
                countArrangementHelper(n, pos + 1, used, count);
                used[i] = false; 
            }
        }
    }
};
