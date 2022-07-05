/* 
o と xからなる長さNの文字列Sがある。
lからr文字目の区間にo と x両方含まれる整数の組(l,r)の個数を求めよ。

入力例
4
ooxo

出力例
5

*/

#include <bits/stdc++.h>
using namespace std;

// 問題を直接求めるのは困難なので、余事象を使う
// 全体の組み合わせ数 - oしか含まれない区間数 - xしか含まれない区間数
// 区間情報をランレングス圧縮する
// [{"o",2}, {"x",1}, {"o",1}]

// 答えは、最大10^6 * 10^6くらいになるのでlong long型を使う
long long N;
string S;
vector<pair<char, long long>> vec;

int main() {

    cin >> N >> S;

    long long cnt = 0;
    for(int i = 0; i < S.size(); i++){
        cnt++;
        if(S[i] != S[i+1] || i == (int)S.size() - 1){
            vec.push_back({S[i], cnt});
            cnt = 0;
        }
    }

    long long ret = 0;
    for(int i = 0; i < vec.size(); i++){
        ret += 1LL * vec[i].second * (vec[i].second - 1LL ) / 2LL;
    }

    cout << N * (N - 1) / 2LL - ret << endl;

    return 0;
}