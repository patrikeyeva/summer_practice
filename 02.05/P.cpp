#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s = "";
    std::vector<int> v;
    for (int i = 1; i <= n; ++i) {
        s += std::to_string(i);
        if (i >= 10) {
            v.push_back(i);
            v.push_back(i);
        } else {
            v.push_back(i);
        }
    }
    std::string tmp;
    std::cin >> tmp;
    for (int i = 0; i < s.size(); ++i) {
        if (tmp[i] != s[i] or tmp.size() == i) {
            std::cout << v[i] << '\n';
            return 0;
        }
    }
    return 0;
}