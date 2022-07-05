/* 
座標平面上をT分で一周する観覧車。
0分後 (0,0,0)
T/4分後 (0, -L/2, L/2)
T/2分後 (0, 0, L)
3T/4分後 (0,L/2, L/2)

像が(X,Y,0)にある
E分後における観覧車から見た像の俯角を度数法で出力
相対誤差は10^-7以下のとき

入力例
4
2 1 1
4
0
1
2
3

出力例
0.000000000000
24.094842552111
54.735610317245
45.000000000000

*/

#include <bits/stdc++.h>
using namespace std;

// 三角関数
// atan2(A,B)→長さA,Bの直角線同士のなす角をラジアンで返す関数

int Q;
long double T,L,X,Y,E;
long double PI = 3.14159265358979;

long double query(long double I){

    // 各座標
    long double cx = 0;
    long double cy = -(L/2) * sin(I/T * 2.0 * PI);
    long double cz = (L/2) - (L/2) * cos(I/T * 2.0 * PI);
    
    // 座標同士の水平、垂直距離
    long double d1 = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));
    long double d2 = cz;

    // 角(ラジアン)
    long double kaku = atan2(d2, d1);

    // 度数法で出力
    return kaku * 180.0L / PI;
}

int main() {

    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;

    for (int i = 1; i <= Q; i++){
        cin >> E;
          // 小数点以下8桁まで出力
        cout << fixed << setprecision(8);
        cout << query(E) << endl;
    }
}