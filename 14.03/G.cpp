    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
     
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t, n, x, y;
        cin >> t;
        for(int i = 0; i < t; ++i) {
            cin >> n >> x >> y;
            if(n / 2 <= y && n / 2 + 1 <= x) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
        return 0;
    }