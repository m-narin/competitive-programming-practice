/* 
log2a < blog2cかどうか

入力例
4 3 2

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

// 誤差に注意
// logやpow関数は浮動小数点で誤差の可能性がある
// なのでオーバーフローしない整数同士で比較する
int main() {

    long long a, b, c;
    cin >> a >> b >> c;
    long long d = 1;

    for (int i = 1; i <= b; i++){
        d *= c;
    }

    if (a < d){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}