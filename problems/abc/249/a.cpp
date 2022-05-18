/* 
X秒後ジョギングでどちらが長い距離を進んだか

入力例
4 3 3 6 2 5 10

出力例
Takahashi

*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// 周期性があるので、各周期で条件を満たすときに移動距離を加算
int main() {
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;

    string res;

    // 高橋君の移動時間
    int takahashi_dis = 0;

    // 青木君の移動時間
    int aoki_dis = 0;

    for (int i = 0; i < x; i++){
        if(i % (a+c) < a){
            takahashi_dis += b;
        }

        if(i % (d+f) < d){
            aoki_dis += e;
        }
    }

    if(takahashi_dis > aoki_dis){
        cout << "Takahashi" << endl;
    }else if (takahashi_dis < aoki_dis)
    {
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
    
}