    #include <iostream>
    #include <set>
    #include <vector>
     
    using namespace std;
     
    using Graph = vector<set<int>>;
     
    void dfs(int node, const Graph& g, vector<bool>& used, bool left, vector<vector<int>>& parts) {
        if(used[node]) {
            return;
        }
        used[node] = true;
        if(left) {
            parts[0].push_back(node);
        } else {
            parts[1].push_back(node);
        }
        for(const auto& neighbor : g[node]) {
            dfs(neighbor, g, used, !left, parts);
        }
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, u, v;
        long long counter = 0;
        cin >> n;
        vector<set<int>> graph(n);
        vector<vector<int>> parts(2);
        vector<bool> used(n, false);
        for(int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            --u;--v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        dfs(0, graph, used, true, parts);
        for(const auto& item : parts[0]) {
            counter += parts[1].size() - graph[item].size();
        }
        cout << counter << '\n';
        return 0;
    }