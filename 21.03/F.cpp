    #include <iostream>
    #include <map>
    #include <set>
    #include <queue>
    #include <unordered_map>
    #include <vector>
     
    using namespace std;
     
    using Graph = unordered_map<int, vector<int>>;
     
    void dfs(int node, const Graph& g, vector<bool>& used) {
        if(used[node]) {
            return;
        }
        used[node] = true;
        for(const auto& item : g.at(node)) {
            dfs(item, g, used);
        }
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n);
        Graph graph;
        for(auto& item : v) {
            item.resize(m);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)  {
                if(v[i][j] == '#') {
                    if(j < m - 1 && v[i][j + 1] == '#') {
                        graph[m * i + j].push_back(m * i + j + 1);
                        graph[m * i + j + 1].push_back(m * i + j);
                    }
                    if(i < n - 1 && v[i + 1][j] == '#') {
                        graph[m * i + j].push_back(m * (i + 1) + j);
                        graph[m * (i + 1) + j].push_back(m * i + j);
                    }
                }
            }
        }
        if(graph.size() < 3) {
            cout << "-1" << '\n';
            return 0;
        }
        for(const auto& item : graph) {
            if(item.second.size() == 1) {
                cout << '1' << '\n';
                return 0;
            }
        }
        vector<bool> used(m * n);
        for(const auto& item : graph) {
            used.assign(m * n, false);
            used[item.first] = true;
            dfs(item.second[0], graph, used);
            for(const auto& xd : graph) {
                if(!used[xd.first]) {
                    cout << '1' << '\n';
                    return 0;
                }
            }
        }
        cout << '2' << '\n';
        return 0;
    }