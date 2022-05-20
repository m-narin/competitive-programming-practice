/* 
Aのスライムは叫ぶたびにK倍に増殖
B以上になるには何回叫ぶ必要があるか?

入力例
1 4 2

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // A*Kは、32bitに収まらない可能性があるがある
    // オーバーフローに気を付ける
    long long A, B, K;
    cin >> A >> B >> K;

    long long slime_number = A;
    int count = 0;
    while(slime_number < B){
        slime_number *= K;
        count++;
    }

    cout << count << endl;
}