/* 
長さNの整数列A,B,Cが与えられる
Ai+Bj+Ckが46の倍数となる選び方の総数を出力する

入力例
3
10 13 93
5 27 35
55 28 52

出力例
3

*/

// 同じ意味のもので代用する
// 余りのみに注目すれば良い
// 46^3の余りで全探索できる
// 各あまりになるものの個数を探索
// →46の倍数になる余りの組み合わせの個数をかけ算で求める

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n), b(n), c(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    // 各要素0で初期化されるので、index→余り、要素→個数と置ける
    // ansがN^3 = 10^15まで可能性があるのでlong long型を使う
    vector<long long> am(46), bm(46), cm(46);

    for (int i = 0; i < n; i++){
        ++am[a[i] % 46];
        ++bm[b[i] % 46];
        ++cm[c[i] % 46];
    }

    long long ans = 0;
    for (int i = 0; i < 46; i++){
        for (int j = 0; j < 46; j++){
            for (int k = 0; k < 46; k++){
                if((i+j+k) % 46 == 0){
                    ans += am[i] * bm[j] * cm[k];
                }
            }
        }
    }

    cout << ans << endl;
}