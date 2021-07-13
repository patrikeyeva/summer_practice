#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> hubs(m);
    int counter = 0;
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
        cin >> hubs[i].first;
        hubs[i].second = i;
    }
    sort(hubs.rbegin(), hubs.rend());
    for(const auto& hub : hubs) {
        ans.push_back(hub.second);
        ++counter;
        if(n - hub.first < 1) {
            n = 1;
            break;
        } else {
            n -= hub.first - 2;
        }
    }
    if(n == 1) {
        cout << counter << '\n';
        for(const auto& item : ans) {
            cout << item + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "Epic fail" << '\n';
    }
    return 0;
}