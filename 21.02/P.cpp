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


int main() {
    task1();
    return 0;
}