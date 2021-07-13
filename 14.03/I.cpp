    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <string>
    #include <unordered_set>
     
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t, n, m, k;
        string s1, s2;
        cin >> t;
        unordered_map<char, unordered_set<char>> substrs;
        unordered_map<char, int> cnts;
        long long counter;
        for(int i = 0; i < t; ++i) {
            cin >> n >> m >> k;
            cin >> s1 >> s2;
            counter = 0;
            substrs.clear();
            cnts.clear();
            for(int j = 0; j < s1.size(); ++j) {
                if(j + k - 1 < s1.size()) {
                    substrs[s1[j + k - 1]].insert(s1[j]);
                } else {
                    break;
                }
            }
            for(const auto& item : s2) {
                ++cnts[item];
                for(const auto& ch : substrs[item]) {
                    counter += cnts[ch];
                }
            }
            cout << counter << '\n';
        }
        return 0;
    }