/* 
h行w列のマスの同じ行または、同じ列にあるマスに書かれている整数を
全て合計したものを、全てのマスに対して出力

入力例
3 3
1 1 1
1 1 1
1 1 1

出力例
5 5 5
5 5 5
5 5 5

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;

    // 入力テーブル
    vector<vector<int>> table(h, vector<int>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> table[h][w];
        }
    }

    // 各マス全てを計算すると、O(HW(H+W))で10^9超える
    // 問題の前処理としてを行、列ごとの和に分割(包除原理)
    // 計算量をO(HW)にできる

    vector<int> rows(h);
    vector<int> columns(w);

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            rows[i] += table[i][j];
            columns[j] += table[i][j];
        }
    }

    // 答えの計算
    vector<vector<int>> answers(h, vector<int>(w));

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            answers[i][j] = rows[i] + columns[j] - table[i][j];
        }
    }

    // 出力
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(j >= 1){
                cout << " ";
            }
            answers[i][j];
        }
        cout << endl;
    }
}