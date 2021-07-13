#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int ArabicToRoman(int arabic) {
    const map<int, int> roman_numbers = {
            {1, 1},
            {4, 2},
            {5, 1},
            {9, 2},
            {10, 1},
            {40, 2},
            {50, 1},
            {90, 2},
            {100, 1},
            {400, 2},
            {500, 1},
            {900, 2},
            {1000, 1}
    };
    auto it = roman_numbers.begin();
    while(it != roman_numbers.end() && it->first <= arabic) {
        ++it;
    }
    if(it != roman_numbers.begin()) {
        --it;
    }
    if(it->first == arabic) {
        return it->second;
    } else {
        return it->second + ArabicToRoman(arabic - it->first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string range, first_number, second_number;
    int n1, n2;
    cin >> range;
    auto it = range.find('-');
    first_number = string(range.begin(), next(range.begin(), it));
    second_number = string(next(range.begin(), it + 1), range.end());
    n1 = stoi(first_number.substr(0, first_number.size() - 2));
    if(first_number.substr(first_number.size() - 2, 2) == "AD") {
        n1 += 753;
    } else {
        n1 = 753 - n1 + 1;
    }
    n2 = stoi(second_number.substr(0, second_number.size() - 2));
    if(second_number.substr(second_number.size() - 2, 2) == "AD") {
        n2 += 753;
    } else {
        n2 = 753 - n2 + 1;
    }
    int ans = 0;
    for(int i = n1; i <= n2; ++i) {
        ans = max(ans, ArabicToRoman(i));
    }
    cout << ans << '\n';
    return 0;
}