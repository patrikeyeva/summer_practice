#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

int main(){

int a, b;
cin >> a >> b;
int c = 180 - a - b;
if ( c < 0 ) cout << "0";
else cout << ceil((float)c/(float)a);

return 0;
}