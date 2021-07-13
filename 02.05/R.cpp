#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> order;
    int n, m, sender;
    cin >> n >> m;
    int current_count = 0;
    for(int i = 0; i < m; ++i) {
        ++current_count;
        cin >> sender;
        order[sender] = current_count;
        long long result = 0;
        for(const auto& item : order) {
            result += current_count - item.second;
        }
        result += current_count * (n - order.size());
        cout << result << '\n';
    }
    return 0;
}