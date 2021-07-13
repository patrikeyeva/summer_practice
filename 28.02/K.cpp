#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const long long MOD = 998244353;

long long bin_pow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) {
            res = (res *  a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    long long ans = 0;
    for(long long i = s.size() - 1; i >= 0; --i) {
        ans = (ans % MOD + (s[i] - '0') * bin_pow(10, s.size() - 1 - i) % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}