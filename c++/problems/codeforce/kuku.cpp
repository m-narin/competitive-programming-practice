/* 
99の表を修正、採点する

入力例
1 2 3 4 5 6 7 8 9
2 4 6 8 10 37 14 79 18
3 6 9 12 15 18 21 24 39
4 8 12 16 20 24 28 32 36
5 10 15 20 25 30 35 40 41
6 67 18 24 50 36 42 10 9
7 14 21 28 35 42 49 56 63
8 16 24 32 40 48 56 64 14
9 18 27 36 45 54 63 72 81

出力例
1 2 3 4 5 6 7 8 9
2 4 6 8 10 12 14 16 18
3 6 9 12 15 18 21 24 27
4 8 12 16 20 24 28 32 36
5 10 15 20 25 30 35 40 45
6 12 18 24 30 36 42 48 54
7 14 21 28 35 42 49 56 63
8 16 24 32 40 48 56 64 72
9 18 27 36 45 54 63 72 81
72
9

*/

#include <bits/stdc++.h>
using namespace std;

// 参照渡しを用いて、呼び出し側の変数の値を変更する
void saiten(vector<vector<int>> &A, int &correct_count, int &wrong_count) {
    // 呼び出し側のAの各マスを正しい値に修正する
    // Aのうち、正しい値の書かれたマスの個数を correct_count に入れる
    // Aのうち、誤った値の書かれたマスの個数を wrong_count に入れる

    for (int i = 0; i < A.at(0).size(); i++){
        for(int j = 0; j < A.size(); j++){
            if(A.at(i).at(j) != (i + 1) * (j + 1)){
                A.at(i).at(j) = (i + 1) * (j + 1);
                wrong_count++;
            }else{
                correct_count++;
            }
        }
    }
}

int main() {
    // A君の回答を受け取る
    vector<vector<int>> A(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A.at(i).at(j);
        }
    }

    int correct_count = 0; // ここに正しい値のマスの個数を入れる
    int wrong_count = 0;   // ここに誤った値のマスの個数を入れる

    // A, correct_count, wrong_countを参照渡し
    saiten(A, correct_count, wrong_count);

    // 正しく修正した表を出力
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << A.at(i).at(j);
            if (j < 8) cout << " ";
            else cout << endl;
        }
    }
    // 正しいマスの個数を出力
    cout << correct_count << endl;
    // 誤っているマスの個数を出力
    cout << wrong_count << endl;
}