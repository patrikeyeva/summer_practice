#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k1, k2;

    cin >> k1 >> k2;

    unordered_map<string, int> first_set;
    unordered_map<string, int> second_set;
    unordered_map<string, int> ans;


    const unordered_map<string, int> number_of_figures = {
            {"pawn", 8},
            {"king", 1},
            {"queen", 1},
            {"bishop", 2},
            {"knight", 2},
            {"rook", 2},
    };

    string figure;

    getline(std::cin, figure);

    for(int i = 0; i < k1; ++i) {
        getline(std::cin, figure);
        ++first_set[move(figure)];
    }

    for(int i = 0; i < k2; ++i) {
        getline(std::cin, figure);
        ++second_set[move(figure)];
    }

    if(k1 + k2 < 32) {
        cout << "impossible" << '\n';
        return 0;
    }

    const vector<string> colors = {"white", "black"};

    for(const auto& fig : number_of_figures) {
        for(const auto& color : colors) {
            auto f = color + " " + fig.first;
            if(first_set[f] != fig.second) {
                if(second_set[f] < fig.second - first_set[f]) {
                    cout << "impossible" << '\n';
                    return 0;
                } else {
                    ans[f] = fig.second - first_set[f];
                }
            }
        }
    }

    for(const auto& item : ans) {
        for(int i = 0; i < item.second; ++i) {
            cout << item.first << '\n';
        }
    }

    return 0;
}