/* 
長さNの整数列に以下のクエリが与えられる。
T=1のとき、x項とy項を入れ替える
T=2のとき、右方向にシフトする
T=3のとき、x項を出力

入力例
8 5
6 17 2 4 17 19 1 7
2 0 0
1 7 2
1 2 6
1 4 5
3 4 0

出力例
4

*/

#include <bits/stdc++.h>
using namespace std;


// 見かけ上の変化をメモ
// 回転は実際に計算すると、O(N^2)の計算量がかかりTLE
// 変化量を記録して操作できれば、O(N+Q)で計算できる
// 変化は周回するので、剰余系が利用できる

// int printElements(auto v){
//     for (auto item : v) {
//         cout << item << " ";
//     }
//     cout << endl;
//     return 0;
// };

int main() {

    int n,q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int shifts = 0;

    for (int i = 0; i < q; i++){
        int t,x,y;
        cin >> t >> x >> y;

        if(t==1){
            x--;
            y--;
            swap(a[(x+shifts) % n], a[(y+shifts) % n]);
        }else if(t==2){

            // k回シフトしているということは、
            // 元の実際に操作する配列にアクセスするとき、
            // indexを"左"にshift分修正しないといけない
            // shiftsをnの剰余系でマイナス方向に一つ動かす
            // 実際に操作する配列→[1,2,3,4,5]
            // 1シフトした配列   →[5,1,2,3,4]
            shifts = (shifts + n - 1) % n;
        }else if(t==3){
            x--;
            cout << a[(x+shifts) % n] << endl;
        }
    }
}