/* 
H x Wのイルミネーション
2 x 2の領域の内、点灯しているものが2つ以上存在するものが無いとき
点灯しているLEDの個数であり得る最大値

入力例
2 3

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;


// コーナーケース(1)に注意
int main() {

    int H,W;
    cin >> H >> W;

    int ans = 0;
    
    if(H == 1 || W == 1){
        ans = H * W;
    }else{
        ans = ((H + 1) / 2) * ((W + 1) / 2);
    }

    cout << ans << endl;
}