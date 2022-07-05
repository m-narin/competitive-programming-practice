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

long long N, Q;
deque<char> deq;

int main() {

    cin >> N >> Q;

    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        deq.push_back(c);
    }

    // 変化量を記録
    long long x_sum = 0;
    for(int i = 0; i < Q; i++){
        long long t,x;
        cin >> t >> x;
        if(t == 1){
            x_sum+=x;
        }else if(t == 2){
            x_sum = x_sum % N;
            cout << deq[(x-x_sum-1+N) % N] << endl;
        }
    }

    return 0;
}