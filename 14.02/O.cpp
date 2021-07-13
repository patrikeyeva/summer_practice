#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& v, pair<int,int> pos, vector<vector<bool>>& position, int& counter) {
    if (position[pos.first][pos.second]) {
        return;
    }
    ++counter;
    position[pos.first][pos.second] = true;
    if (pos.first - 1 >= 0 && v[pos.first - 1][pos.second] == 1) {
        dfs(v,{pos.first - 1, pos.second}, position, counter);
    }
    if (pos.first + 1 < v.size() && v[pos.first + 1][pos.second] == 1) {
        dfs(v,{pos.first + 1, pos.second}, position, counter);
    }
    if (pos.second - 1 >= 0 && v[pos.first][pos.second - 1] == 1) {
        dfs(v,{pos.first, pos.second - 1}, position, counter);
    }
    if (pos.second + 1 < v[0].size() && v[pos.first][pos.second + 1] == 1) {
        dfs(v,{pos.first, pos.second + 1}, position, counter);
    }
}



void task1() {
    vector<vector<int>> v;
    vector<vector<bool>> position;
    int m, n;
    string cur;
    cin >> m >> n;
    v.resize(m);
    position.resize(m);
    for (int i = 0; i < m; ++i) {
        v[i].resize(n);
        position[i].resize(n);
    }
    for (int i = 0; i < m; ++i) {
        cin >> cur;
        for (int j = 0; j < n; ++j) {
            v[i][j] = cur[j] - '0';
            if (cur[j] == '1') {
                position[i][j] = false;
            } else {
                position[i][j] = true;
            }
        }
    }
    int counter = 0;
    int global_max = 0;
    int cur_max = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!position[i][j]) {
                counter++;
                cur_max = 0;
                dfs(v,{i,j},position,cur_max);
                global_max = max(cur_max, global_max);
            }
        }

    }
    cout << counter << ' ' << global_max << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    task1();
    return 0;
}