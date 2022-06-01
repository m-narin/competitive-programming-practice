/* 
8進法の整数に以下の操作をK回行う
9進法に直し、8を5に書き直す→この数は8進法とみなす
最終的に出来る数を8進法で出力

入力例
21 1

出力例
15

*/

#include <bits/stdc++.h>
using namespace std;

// 8進数(文字列)を10進数に直す
long long base8_to_long(string N){
    long long res = 0;

    // べき乗の計算
    // max8^20なので、long long型にする
    long long x = 1;

    for (int i = N.size()-1; i >= 0; --i){

        // char → 数値に変換(シリアル文字コードを利用)
        // long long型で計算
        res += 1LL * x * int(N[i] - '0');
        x *= 8LL;
    }
    return res;
}

// 10進数を9進数(文字列)に直す
string long_to_base9(long long N){
    if(N==0){
        return "0";
    }

    string res;
    while(N > 0){
        // 数値→charに変換(シリアル文字コードを利用)
        res = char(N % 9 + '0') + res;
        N /= 9;
    }
    return res;
}

int main() {

    // max20桁なので文字列型で受け取る
    string N;
    int K;
    cin >> N >> K;

    for (int i = 0; i < K; i++){
        N = long_to_base9(base8_to_long(N));
        for (int j = 0; j < N.size(); j++){
            if(N[j] == '8'){
                N[j] = '5';
            }
        }
    }

    cout << N << endl;
}