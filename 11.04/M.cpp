    #include <iostream>
    #include <map>
    #include <set>
    #include <queue>
    #include <unordered_set>
    #include <vector>
     
    using namespace std;
     
    const long long MOD = 1e9 + 7;
     
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
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long long q, i1, i2, j1, j2;
        long long i_sum, j_sum;
        cin >> q;
        for(int i = 0; i < q; ++i) {
            cin >> i1 >> i2 >> j1 >> j2;
            i_sum = (bin_pow(2, i2 + 1) - bin_pow(2, i1));
            if(i_sum < 0) {
                i_sum = MOD + i_sum;
            }
            j_sum = (bin_pow(3, j2 + 1) - bin_pow(3, j1));
            if(j_sum < 0) {
                j_sum = MOD + j_sum;
            }
            cout << (((i_sum * j_sum) % MOD) * 500000004) % MOD  << '\n';
        }
        return 0;
    }