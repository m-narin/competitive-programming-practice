/* 
A,B,C,,,をN個順に繋げて得られる文字列の先頭からX番目の文字を出力

入力例
2 12

出力例
F

*/


#include <bits/stdc++.h>
using namespace std;

int N, X;
string S;

int main() {

    cin >> N >> X;

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < N; j++){

            // charは数字として計算できる
            // 'A'から'Z'まで連番になっていることを利用
            S.push_back('A' + i);
        }
    }
    X--;

    cout << S[X] << endl;
    return 0;
}