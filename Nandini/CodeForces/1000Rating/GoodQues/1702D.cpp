#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int p;
        cin >> str >> p;
        int total = 0;
        vector<vector<int>> indices(26); 
        
        for (int i = 0; i < str.size(); i++) {
            total += str[i] - 'a' + 1;
            indices[str[i] - 'a'].push_back(i);
        }

        if (total <= p) {
            cout << str << endl;
            continue;
        }

        vector<pair<int, char>> cost;
        for (int i = 0; i < 26; i++) {
            if (!indices[i].empty()) {
                cost.push_back({i + 1, i + 'a'});
            }
        }
        sort(cost.rbegin(), cost.rend()); 

        string result(str.size(), '\0');
        for (auto it: cost) 
        {
            char ch = it.second;
            int value = it.first;
            for (int idx : indices[ch - 'a']) {
                if (total <= p) {
                    break;
                }
                total -= value;
                str[idx] = '\0'; 
            }
            if (total <= p) {
                break;
            }
        }

        for (char c : str) {
            if (c != '\0') {
                cout << c;
            }
        }
        cout << endl;
    }
}
