/* 
かけ算の積和が1000を超えたら終了

入力例
なし

出力例
7, 4
1015

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

int sum = 0;

// 外側のloopを抜けるか判定する変数
bool finished = false;

for (int i = 0; i < 10 ; i++) {
    for (int j = 0; j < 10 ; j++) {

        sum += i * j;

        if (sum > 1000) {
        cout << i << ", " << j << endl;
        finished = true;

        // 内側のloopを抜ける
        break;
        }
    }

    // 外側のloopを抜ける
    if (finished) {
        break;
    }
}

cout << sum << endl;
}