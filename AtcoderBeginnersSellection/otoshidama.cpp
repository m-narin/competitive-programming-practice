/* 
10000円札、5000円札、1000円札N枚でY円はあり得るか？
あり得る場合それぞれの枚数、あり得ない場合、-1 -1 -1を出力

入力例
9 45000

出力例
4 0 5

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    // あり得るかどうか
    bool if_possible = false;

    // 10000円札i枚、5000円札n-i枚、1000円札n-i-j枚と考え2重ループ
    // パターンが一つでも見つかったらループ終了
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n-i; j++){
            if(10000*i + 5000*j + 1000*(n-i-j) == y){
                cout << i << " " << j << " " << n - i - j << endl;
                if_possible = true;

                // 内側のループ終了
                break;
            }
        }

        // もしif_possibleがtrueだったら外側のループ終了
        if(if_possible){
            break;
        }
    }

    // もしif_possibleがfalseのままだったら、
    if(!if_possible){
        cout << -1 << " " << -1 << " " << -1 << endl;
    }

}