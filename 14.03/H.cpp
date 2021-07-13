    #include <iostream>
    #include <vector>
    #include <set>
    #include <cmath>
     
    using namespace std;
     
    vector<int> digits(int n) {
        vector<int> res;
        int counter = 0;
        while(n) {
            res.push_back((n % 10) * pow(10, counter));
            ++counter;
            n /= 10;
        }
        return res;
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t, x, y;
        cin >> t;
        for(int i = 0; i < t; ++i) {
            cin >> x >> y;
            auto v1 = digits(x);
            auto v2 = digits(y);
            for(int j = 0; j < v1.size(); ++j) {
                for(int k = 0; k < v2.size(); ++k) {
                    if(v1[j] && v2[k]) {
                        cout << v1[j] << " x " << v2[k];
                        if(!(j == v1.size() - 1 && k == v2.size() - 1)) {
                            cout << " + ";
                        }
                    }
                }
            }
            cout << '\n';
        }
        return 0;
    }