#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s = {126, 153, 688, 1206, 1435, 1503, 11844, 11848, 12006, 12060, 12384, 13950, 21375, 21586, 21753, 21870, 25105, 25375, 25474, 25510, 28476, 29632, 31590, 33655, 33696, 36855, 37840, 37845,39784,41665, 42898,44676,71199, 78975,105295, 105723,105750,123894,129640,129775,129955,139500,139824,150435,150624, 150826,152271, 152406,152460, 152608, 152685, 192375, 192685, 194229,197428,226876, 227448, 229648,251050, 260338,261378,263736, 297463,297832,304717,307183,312475, 352966,355995, 361989,375615,378418, 378450, 381429, 390847, 392566, 397840, 399784, 404932, 404968, 416650, 449955, 450688,451768, 456840, 719199, 794088, 798682, 809919, 809937,809964, 815958,829696,841995,859968,899019, 936985,939658,960988,1000255
    };
    int n;
    while(cin >> n) {
        if(!n) {
            break;
        }
        cout << *s.lower_bound(n) << '\n';
    }
    return 0;
}