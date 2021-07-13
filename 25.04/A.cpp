#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, t, r;
    map<int, int> score;
    cin >> n >> l;
    for(int i = 0; i < n; ++i) {
        cin >> t >> r;
        if(r == -1) {
            score[t] += 1;
        } else if(r < l) {
            score[t] += 2;
        } else {
            score[t] += 3;
        }
    }
    cout << score[1] << ":" << score[2] << '\n';
    return 0;
}
