    #include <iostream>
    #include <map>
    #include <set>
    #include <queue>
    #include <vector>
     
    using namespace std;
     
    using Graph = vector<set<int>>;
     
    long long bfs(const Graph& g) {
        vector<bool> used(g.size(), false);
        queue<pair<int, int>> q;
        map<int, int> heights;
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            auto [node, height] = q.front();
            q.pop();
            if(used[node]) {
                continue;
            }
            used[node] = true;
            for(const auto& item : g[node]) {
                q.push(make_pair(item, height + 1));
            }
            ++heights[height];
        }
        long long res = 0;
        for(const auto& item : heights) {
            res += item.second % 2;
        }
        return res;
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, u, v;
        cin >> n;
        vector<bool> used(n, false);
        set<int> heights;
        Graph g(n);
        for(int i = 0; i < n - 1; ++i) {
            cin >> u;
            --u;
            g[i + 1].insert(u);
            g[u].insert(i + 1);
        }
        cout << bfs(g) << '\n';
        return 0;
    }