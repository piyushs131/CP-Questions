#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) 
    {
        std::map<int, int> frequencyMap;
        for (const auto& num : arr) {
            frequencyMap[num]++;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (auto it : frequencyMap) {
            int freq = it.second;
            minHeap.push(freq);
        }

        while (k > 0 && !minHeap.empty()) {
            k -= minHeap.top();
            if (k >= 0) {
                minHeap.pop();
            }
        }

        return minHeap.size();
    }
};
