#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long func_mult(int i) {
    long long answ = 1;
    while (i != 0) {
        answ *= i%10;
        i /= 10;
    }
    return answ;
}

void task1() {
    int n;
    std::cin >> n;
    long long mult = 1;
    int p = log10(n);
    int last = 0;
    int cur = 0;
    mult = func_mult(n);

    for (int i = 1; i < p + 1; ++i) {
        int m = n;
        cur = pow(10, i);
        m /= cur;
        m -= 1;
        int step = 9;
        for (int j = 1; j < i; ++j) {
            step = step*10 + 9;
        }
        m = m*cur + step;
        long long res = func_mult(m);
        if (res > mult) {
            mult = res;
        }
    }

    cout << mult << endl;
}

bool compare(int a,int b, int c, int d) {
    if (a == b && b == c && c == d) {
        return true;
    }
    return false;
}

void task2() {
    int a,b,c,d;
    int _a,_b,_c,_d;
    while (true) {
        cin >> _a >> _b >> _c >> _d;
        if (_a + _b + _c + _d == 0) {
            return;
        }
        int i = 0;
        while (!compare(_a, _b, _c, _d)) {
            a = _a; b = _b; c = _c; d = _d;
            _a = abs(a - b);
            _b = abs(b - c);
            _c = abs(c - d);
            _d = abs(d - a);
            ++i;
        }
        cout << i << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    task2();
    return 0;
}