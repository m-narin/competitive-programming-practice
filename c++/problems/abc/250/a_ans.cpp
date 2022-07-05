/* 
H x W のあるマスの隣接するマスの個数

入力例
3 4
2 2

出力例
4

*/

#include <bits/stdc++.h>
using namespace std;

// 方針は上下左右にマスがある方向の数を数える
// 
int main() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;

    int res = 0;

    // 上
    if(r != 1)
        res++;
    
    // 下
    if(r != h)
        res++;

    // 左 
    if(c != 1)
        res++;

    // 右
    if(c != w)
        res++;
    
    cout << res << endl;
}