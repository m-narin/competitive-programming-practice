/* 
AからBまでの総和を求める関数
A+(A+1)+..+(B-1)の総和 + B
に分解できることを利用

「a~(b-1)の総和」+ b
→「a~(b-2)の総和」+ (b-1) + b
...
→「a~aの総和」
大元の関数から、内側の関数を呼び出し続ける。

行きつく先はベースケースのA~Aの総和 = Aとなる
このとき最も内側の関数が終了し、徐々に上へと上がっていく

入力例

出力例

*/

#include <bits/stdc++.h>
using namespace std;

// a ~ bの総和を計算する (a ≦ b)という前提
int sum_range(int a, int b) {

    // ベースケース
    // 満たしたとき、returnで終了となる
    if (a == b) {
        return a;
    }
    // 再帰ステップ
    //「a~bの総和」=「a~(b-1)の総和」+ b
    return sum_range(a, b - 1) + b;  
}

int main() {
    cout << sum_range(0, 4) << endl; // 0 + 1 + 2 + 3 + 4 = 10
    cout << sum_range(5, 8) << endl; // 5 + 6 + 7 + 8 = 26
}