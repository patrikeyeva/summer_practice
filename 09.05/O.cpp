#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int vowel_count = 0;
    int cons_count = 0;
    for(auto& item : s) {
        if(auto it = vowels.find(item); it != vowels.end()) {
            ++vowel_count;
        } else if(item != 'y') {
            ++cons_count;
        }
    }
    if(cons_count >= vowel_count) {
        int count = 0;
        while(cons_count >= vowel_count) {
            ++count;
            --cons_count;
            ++vowel_count;
        }
        cout << count << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}