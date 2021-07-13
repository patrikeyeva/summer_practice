#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    double n, k, r;
    double sum = 0;
    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        cin >> r;
        sum += r;
    }
    cout << fixed << setprecision(18);
    cout << (sum + (-3.) * (n - k)) / (double)n << ' ' << (sum + (3.) * (n - k)) / (double)n << '\n';
    return 0;
}