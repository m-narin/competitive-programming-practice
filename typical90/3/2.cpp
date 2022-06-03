/* 
長さNの正しいカッコ列を全て辞書順に出力
存在しない場合は何も出力しない

入力例
4

出力例
(())
()()

*/

#include <bits/stdc++.h>
using namespace std;

// 2^20で済むので、bit全探索OK
// カッコ列が正しい必要十分条件
// １． "(" と")"の数が同じ
// ２． 全てのi(1<=i<=N)について、左からi文字までの
// "("の数が、")"の数以上である
// O(2^N * N)で解ける

bool hantei(string S){
    int dep = 0;

    // ()
    for (int i = 0; i < S.size(); i++) {
        if(S[i] == '('){
            dep++;
        }
        if(S[i] == ')'){
            dep--;
        }
        // ２．の条件
        if (dep < 0) {
            return false;
        };
    }
    // １．の条件
    if(dep == 0){
        return true;
    }

    return false;
}

int main() {

    int N;
	cin >> N;

    // 1をNbit左シフトする = 2のN乗回ループ
    // N = 8のとき、0 ~ 100000000
    for (int i = 0; i < (1 << N); i++) {
        string Candidate = "";
        
        // 0→'(' 1→')'の文字列を生成する
        // i の j ビット目（2^j の位）が 0 であるための条件。
        // 例えば、i = 1100100, j = 1000のとき
        // 1100100 & 0001000 = 0000000なので4桁目は0となる
        for (int j = N - 1; j >= 0; j--){
            if((i & (1 << j)) == 0){
                Candidate += "(";
            }else{
                Candidate += ")";
            }
        }
        bool I = hantei(Candidate);
        if(I){
            cout << Candidate << endl;
        }
    }
}