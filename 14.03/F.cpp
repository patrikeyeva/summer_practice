    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
     
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t, n;
        cin >> t;
        string s1, s2;
        string s3;
        vector<size_t> v;
        for(int i = 0; i < t; ++i) {
            v.clear();
            cin >> n;
            cin >> s1 >> s2;
            s3 = s2;
            for(int j = 0; j < n; ++j) {
                if(s1[j] != s2[j]) {
                    v.push_back(j);
                }
            }
            for(int j = 0; j < v.size(); ++j) {
                s3[v[(j + 1) % v.size()]] = s2[v[j]];
            }
            if(s3 == s1) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
        return 0;
    }