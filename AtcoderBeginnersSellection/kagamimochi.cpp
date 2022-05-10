/* 
N枚の円形の餅を、直径の大きい順に積み上げていく
このとき真下の餅より直径は小さくなる
最大で何段重ねの餅を作れるか

入力例
4
10
8
8
6

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; i++){
        cin >> m.at(i);
    }

    // setを使う(=keyだけのmapみたいなもの)
    // 重複を取り除く & 小さい順に並べられる
    set<int> values;
    for (int i = 0; i < n; i++){
        values.insert(m.at(i));
    }

    cout << values.size() << endl;
}


// 別解。バケット法
// 1つ以上存在するものを集計できる

/*
int main() {
    int N;
    int d[110];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> d[i];

    int num[110] = {0};  // バケット
    for (int i = 0; i < N; ++i) {
        num[d[i]]++;  // d[i] が 1 個増える
    }

    int res = 0;  // 答えを格納
    for (int i = 1; i <= 100; ++i) {  // 1 <= d[i] <= 100 なので 1 から 100 まで探索
        if (num[i]) {  // 0 より大きかったら
            ++res;
        }
    }
    cout << res << endl;
}
*/