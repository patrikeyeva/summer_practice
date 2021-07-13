#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for(char& c : s) {
        if(v[c - 'a'] != 0) {
            cout << 0 << '\n';
            return  0;
        }
        ++v[c - 'a'];
    }
    cout << 1 << '\n';
    return 0;
}