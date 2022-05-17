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

int main() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;

    int res;

    // 角は2
    // 角以外の辺上は3
    // それ以外は4
    if((r == 1 && c == 1) || (h == r && w == c) || (h == 1 && w == c) || (h == r && w == 1)){
        res = 2;
    }else if (r == 1 || c == 1 || h == r || w == c){
        res = 3;
    }else{
        res = 4;
    }
    

    cout << res << endl;
}