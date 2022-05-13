/* 
最頻値とその出現回数を求める

入力例
5
1 4 4 2 3

出力例
4 2

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    // 連想配列
    map<int, int> cnt;
    for (int x : A) {
        if (cnt.count(x)) {
            // 既に含まれているならインクリメント
            cnt.at(x)++;
        } else {
            // 含まれていないなら、1を追加
            cnt[x] = 1;
        }
    }

    int max_cnt = 0;  // 出現回数の最大値を保持
    int ans = -1;     // 出現回数が最大になる値を保持
    for (int x : A) {
        // 今見ているxの出現回数が、その時点の最大よりも大きければ更新
        if (max_cnt < cnt.at(x)) {
            max_cnt = cnt.at(x);
            ans = x;
        }
    }

    cout << ans << " " << max_cnt << endl;
}
