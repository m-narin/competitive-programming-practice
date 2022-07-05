/* 
左上のマスから右下のマスへ到達できるか
再帰関数は処理の回数が不明なときに効力を発揮する
while文の関数version

入力例
3
.##
...
##.

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

// 正しい移動かを調べる (y, x)が移動先
bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
    int N = board.size();

    // 移動先がマス目の外である場合
    if (x <= -1 || x >= N || y <= -1 || y >= N) {
        return false;
    }
    // 移動先が壁マス
    if (board.at(y).at(x) == '#') {
        return false;
    }
    // 既に調べているマスへの移動は調べないのでfalseを返す
    if (checked.at(y).at(x)) {
        return false;
    }

    // それ以外なら正しい移動
    return true;
}

// (y, x)にいる状態からゴールに到達できるか
// board: マス目の種類
// checked: そのマスを既に調べたかを持つ二次元配列
bool reachable(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
    int N = board.size();

    // ベースケース
    if (x == N - 1 && y == N - 1) {
        // ゴールにいる状態
        return true;
    }  

    // 再帰ステップ

    checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく

    // 「上」「右」「下」「左」のいずれかの移動でゴールに到達できるか？
    bool result = false;

    // 上へ移動したマスからゴールに到達できるか？
    if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
        result = true;
    }
    // 右へ移動したマスからゴールに到達できるか？
    if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) {
        result = true;
    }
    // 下へ移動したマスからゴールに到達できるか？
    if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) {
        result = true;
    }
    // 左へ移動したマスからゴールに到達できるか？
    if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) {
        result = true;
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    // マス目の状態を受け取る
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board.at(i);
    }

    // 既にそのマスを調べたかを保持する二次元配列
    vector<vector<bool>> checked(N, vector<bool>(N, false));  // false(まだ調べていない)で初期化しておく

    // (0, 0) からゴールまで到達できるか？
    if (reachable(board, checked, 0, 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}