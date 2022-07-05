/* 
8進数を10進数、9進数、2進数に変換する

入力例
1330

出力例
888

*/

#include <bits/stdc++.h>
using namespace std;

// 8進数(文字列)を10進数に変換する
long long base8_to_base10(string N){
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

// 10進数を9進数(文字列)に変換する
string base10_to_base9(long long N){
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

// 10進数を2進数(文字列)に変換する
string base10_to_base2(long long N){
    if(N==0){
        return "0";
    }

    string res;
    while(N > 0){
        // 数値→charに変換(シリアル文字コードを利用)
        res = char(N % 2 + '0') + res;
        N /= 2;
    }
    return res;
}

int main() {

    // max20桁なので文字列型で受け取る
    string N;
    cin >> N;

    long long base10_ans = base8_to_base10(N);
    string base9_ans = base10_to_base9(base8_to_base10(N));
    string base2_ans = base10_to_base2(base8_to_base10(N));
    cout << base10_ans << endl;
    cout << base9_ans << endl;
    cout << base2_ans << endl;
}