#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> result;
        set<int> current;

        for (int num : arr) {
            set<int> newCurrent;
            newCurrent.insert(num);
            for (int prev : current) {
                newCurrent.insert(prev | num);
            }
            current = newCurrent;
            result.insert(current.begin(), current.end());
        }

        return result.size();
    }
};
