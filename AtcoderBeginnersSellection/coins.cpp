/* 
500円玉A枚、100円玉B枚、50円玉C枚。
合計金額をX円にする選び方は何通りあるか？

入力例
2
2
2
100

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int count = 0;
    for (int i = 0; i <= a; i++){
        for (int j = 0; j <= b; j++){
            for (int k = 0; k <= c; k++){
                if(500*i + 100*j + 50*k == x){
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}