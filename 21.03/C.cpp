    #include <iostream>
    #include <set>
    #include <vector>
     
    using namespace std;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, u, v;
        int counter = 0;
        cin >> n;
        vector<set<int>> graph(n);
        set<int> leaves;
        for(int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            --u;--v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        for(int i = 1; i < n; ++i) {
            if(graph[i].size() == 1) {
                leaves.insert(i);
            }
        }
        bool found;
        for(int i = 1; i < n; ++i) {
            found = false;
            if(graph[i].size() == 2) {
                for(const auto& item : graph[i]) {
                    if(auto it = leaves.find(item); it != leaves.end()) {
                        found = true;
                    }
                }
            }
            if(found) {
                ++counter;
            }
        }
        cout << counter << '\n';
        return 0;
    }