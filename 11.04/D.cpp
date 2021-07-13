    #include <iostream>
    #include <string>
    #include <set>
    #include <algorithm>
     
    int main() {
        std::set<char> v = {'a','e','i','o','u','y'}, co= {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n'
        , 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
        std::string s;
        int n;
        int pair = 0;
        std::cin >> n;
        std::cin >> s;
     
     
        for (int i = 1; i < s.size(); ++i) {
            if (v.find(s[i]) != v.end()) {
                if (co.find(s[i - 1]) != co.end()) {
                    ++pair;
                    ++i;
                }
            } else if (co.find(s[i]) != co.end()) {
                if (v.find(s[i - 1]) != v.end()) {
                    ++pair;
                    ++i;
                }
            }
        }
        std::cout << pair << '\n';
        return 0;
    }