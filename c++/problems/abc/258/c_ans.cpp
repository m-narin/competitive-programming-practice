/* 
長さNの英小文字からなる文字列Sがある。以下のクエリをQ個処理せよ
1 x : Sの末尾を削除し、先頭に挿入する
2 x : Sのx番目を出力する

入力例
3 3
abc
2 2
1 1
2 2

出力例
b
a

*/


#include <bits/stdc++.h>
using namespace std;

int N, Q;
string S;

int main() {

    cin >> N >> Q >> S;

    // 変化量を記録
    int p = 0;
    for(int i = 0; i < Q; i++){
        int t,x;
        cin >> t >> x;
        if(t == 1){

            // ずれた分の整数値
            // どこスタートになるか？を管理
            p = (p-x+N) % N;
        }else if(t == 2){
            cout << S[(p+x-1)%N] << '\n';
        }
    }

    return 0;
}