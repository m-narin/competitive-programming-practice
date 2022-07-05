/* 
a+b+cの結果と文字列sを並べて表示

入力例
1
2 3
test

出力例
6 test

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string s;
    cin >> s;

    cout << a + b + c << " " << s << endl;
    return 0;
}