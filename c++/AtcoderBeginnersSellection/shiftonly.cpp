/* 
整数が全て偶数のとき、2で何回割れるか

入力例
3
8 12 40

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a.at(i);
    }

    // 操作回数
    int res = 0;

    // 奇数が一個でもあったらbreak
    // 条件を満たす間、処理を続けるのでwhile文を使う
    while(true){

        // 奇数があるか判定
        bool exist_odd = false;
        for(int x : a){
            if(x % 2 != 0){
                exist_odd = true;

                // for文を抜ける
                break;
            }
        }

        if(exist_odd)
        // while文を抜ける
            break;

        // 配列の各要素を更新できる
        for (int i = 0; i < n; i++){
            a.at(i) /= 2;
        }

        // 途中結果出力用
        // for (int i = 0; i < n; i++){
        //     cout << a.at(i) << " ";
        // }
        // cout << endl;

        res++;
    }

    cout << res << endl;
}