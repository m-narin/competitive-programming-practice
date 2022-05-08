/* 
試合結果の表を作成する
入力例の1行目は、N人、2試合
2行目は1が2に勝ったことを表す

入力例
3 2
1 2
3 1

出力例
- o x
x - -
o - -

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    // 2次元配列の宣言
    vector<vector<char>> table(N, vector<char>(N, '-'));

    // 試合結果テーブルの要素を勝敗に更新
    for (int i = 0; i < M; i++){

        // 配列の添え字に合わせる
        A.at(i)--;
        B.at(i)--;

        table.at(A.at(i)).at(B.at(i)) = 'o';
        table.at(B.at(i)).at(A.at(i)) = 'x';
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            // 行末尾かどうかで分岐して出力
            cout << table.at(i).at(j);
            if(j == N - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
}