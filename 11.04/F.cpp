    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector<int> v(n);
        bool ans = true;
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if(n == 1) {
            cout << "YES\n";
            return 0;
        }
        vector<int> borders(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            if(v[i] == 2) {
                borders[i] = 1;
                borders[i + 1] = 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(v[i] == 1) {
                if(borders[i] == 1 || borders[i + 1] == 1) {
                    continue;
                } else {
                    if(i == 0) {
                        int counter = 0;
                        bool is_two = false;
                        for(int j = 1; j < n; ++j) {
                            if(v[j] != 1) {
                                if(v[j] == 2) {
                                    is_two = true;
                                }
                                break;
                            }
                            ++counter;
                        }
                        if(v[i + 1] == 0 || (i + 2 < n && borders[i + 2] == 1) || (is_two && counter % 2 == 1) || (!is_two && !(counter % 2))) {
                            borders[i] = 1;
                        } else {
                            borders[i + 1] = 1;
                        }
                    } else if(i == n - 1) {
                        if(v[i - 1] == 0 || borders[i - 1] == 1) {
                            borders[i + 1] = 1;
                        } else {
                            borders[i] = 1;
                        }
                    } else {
                        if(v[i - 1] == 1) {
                            if(borders[i - 1] == 1) {
                                borders[i + 1] = 1;
                            } else {
                                borders[i] = 1;
                            }
                        } else if(!v[i - 1]) {
                            borders[i + 1] = 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            ans = ans && (v[i] == borders[i] + borders[i + 1]);
        }
        if(ans) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return 0;
    }