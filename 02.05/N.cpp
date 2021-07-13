#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <bitset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    string s;
    cin >> n >> k;
    int max_count = 0;
    vector<bitset<10>> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> s;
        for(int j = 0; j < s.size(); ++j) {
            if(s[j] == 'T') {
                v[i][j] = true;
            }
        }
    }
    for(int i = 0; i <= pow(2, k); ++i) {
        bitset<10> b(i);
        int m = 11;
        for(const auto& item : v) {
            m = min(m, (int)(k - (item ^ b).count()));
        }
        max_count = max(max_count, m);
    }
    cout << max_count << '\n';
    return 0;
}