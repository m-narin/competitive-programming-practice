/* 
文字列Sを繰り返して長さ6のものを出力する

入力例
abc

出力例
abcabc

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    // 文字列の長さ
    int L = S.size();

    // 繰り返し数
    int repeat_num = 6 / L;

    // 答え
    string res;

    for (int i = 0; i < repeat_num; i++){
        res += S;
    }

    cout << res << endl;
}