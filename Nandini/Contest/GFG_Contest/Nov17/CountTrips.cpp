#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

class Solution {
public:
    vector<int> findCommon(int a, int b) {
        int g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        return {a, b};
    }

    int countTrips(vector<vector<int>> &loc) {
        set<pair<int, int>> directions;

        for (auto &it : loc) {
            if (it[0] == 0 && it[1] == 0) continue;

            auto itt = findCommon(it[0], it[1]);
            // cout << it[0] << " " << it[1] << endl;
            directions.insert({itt[0], itt[1]});
        }

        return directions.size(); 
    }
};