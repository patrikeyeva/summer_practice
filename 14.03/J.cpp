    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
     
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t, m, k, n, a;
        vector<bool> v;
        int max_test;
        int counter;
        char c;
        cin >> t;
        for(int i = 0; i < t; ++i) {
            cin >> n >> m >> k;
            v.assign(n, false);
            for(int j = 0; j < n; ++j) {
                cin >> c;
                if(c == 'S') {
                    v[j] = true;
                }
            }
            max_test = k;
            counter = 0;
            for(int j = 0; j < m; ++j) {
                cin >> c;
                if(c == 'W') {
                    cin >> a;
                } else {
                    max_test = n;
                    continue;
                }
                if(a <= max_test && v[a - 1]) {
                    ++counter;
                }
                if(a > max_test) {
                    max_test = a;
                }
            }
            cout << counter << '\n';
        }
        return 0;
    }