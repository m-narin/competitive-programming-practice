#include <bits/stdc++.h>
using namespace std;

// 中央値となる条件
// a <= b <= c or a >= b >= c
// a+b+c-max({a,b,c})-min({a,b,c}) == b

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a <= b and b <= c) or (a >= b and b >= c)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}