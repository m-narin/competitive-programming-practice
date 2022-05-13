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