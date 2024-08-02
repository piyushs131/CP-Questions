#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto it : freq) 
        {
            int count = it.first ;
            char charr = it.second;
            maxHeap.push({count, charr});
        }

        string result = "";

        pair<int, char> prev = {0, ' '};

        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            char charr = maxHeap.top().second;
            maxHeap.pop();

            result += charr;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {count - 1, charr};
        }

        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};
