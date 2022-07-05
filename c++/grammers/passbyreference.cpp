// 値渡しは変数が関数内にコピーされるので計算量が増える
// 参照渡しはコピーせずに変数のメモリ番地を直接渡すので、
// 計算量を抑えられる。

#include <bits/stdc++.h>
using namespace std;

// 配列の先頭100要素の値の合計を計算する (参照渡し)
int sum100(vector<int> &a) {
    int result = 0;
    for (int i = 0; i < 100; i++) {
    result += a.at(i);
    }
    return result;
}

int main() {
    vector<int> vec(10000000, 1);  // すべての要素が1の配列

    // sum100 を500回呼び出す
    for (int i = 0; i < 500; i++) {
        cout << sum100(vec) << endl;  // 参照渡しなので配列のコピーは生じない
    }
}


/*
参照を使えば配列の値を簡単に書き換えることができる

vector<int> a = {1, 3, 2, 5};
for (int x : a) {
  x = x * 2;
}
// aは{1, 3, 2, 5}のまま

vector<int> a = {1, 3, 2, 5};
for (int &x : a) {
  x = x * 2;
}
// aは{2, 6, 4, 10}となる

*/