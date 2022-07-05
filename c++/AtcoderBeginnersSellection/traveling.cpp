/* 
(0,0)から時刻tに(xt,yt)に移動する計画は実現可能か

入力例
2
3 1 2
6 1 1

出力例
YES

*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// 距離と偶奇(パリティ)の二つの条件がある
// 1. dist = abs(xの変化)+abs(yの変化) <= dt
// 2. dtが偶数なら(xi+yi)は必ず偶数。逆も然り。
int main() {
    int N;
    int t[110000], x[110000], y[110000];

    cin >> N;

    // 初期状態
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i <= N; i++){
        cin >> t[i] >> x[i] >> y[i];
    }

    bool can = true;
    
    for (int i = 0; i < N; i++){

        int dt = t[i + 1] - t[i];
        int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);

        if(dt < dist){
            can = false;
        }

        if(dist % 2 != dt % 2){
            can = false;
        }
    }

    if(can){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}