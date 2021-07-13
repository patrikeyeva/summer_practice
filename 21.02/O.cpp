#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    long long dist;
    pair<int, int> ids;
};

struct Vertex {
    long long x, y;
};

long long dist(const Vertex& lhs, const Vertex& rhs) {
    return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

bool operator<(const Pair& lhs, const Pair& rhs) {
    if(lhs.dist != rhs.dist) {
        return lhs.dist < rhs.dist;
    }
    return lhs.ids < rhs.ids;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Vertex> v;
    vector<Pair> p;
    vector<pair<int, int>> result;
    int n;
    cin >> n;
    vector<bool> used(n, false);
    long long x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            p.push_back({dist(v[i], v[j]), {i, j}});
        }
    }
    sort(p.begin(), p.end());
    int counter = 0;
    while(counter != n) {
        for(const auto& item : p) {
            if(!used[item.ids.first] && !used[item.ids.second]) {
                used[item.ids.first] = true;
                used[item.ids.second] = true;
                result.emplace_back(item.ids.first, item.ids.second);
                counter += 2;
            }
        }
    }
    sort(result.begin(), result.end());
    for(const auto& item : result) {
        cout << item.first + 1 << ' ' << item.second + 1 << '\n';
    }
    return 0;
}