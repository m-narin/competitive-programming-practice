/* 
子供と大人がN人いて、子供は0, 大人は1という文字で表される
体重X以上は大人、未満は子供と判定するとき、正しく判定できる人数の最大値がいくつか？

入力例
5
10101
60 50 50 50 60

出力例
4

*/


#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
string S;
int W[1000009];

int main() {

    cin >> N >> S;

    for (int i = 0; i < N; i++){
        cin >> W[i];
    }

    vector<pair<int, char>> P;

    for (int i = 0; i < N; i++){
        P.push_back({W[i],S[i]});
        if(S[i] == '1'){
            ans++;
        }
    }

    sort(P.begin(), P.end());

    // 一番左端に線をひいた場合、大人のみ正しく判定できる
    int x = ans;
    
    for(int i = 0; i < N; i++){
        if(P[i].second == '1'){
            x--;
        }else{
            x++;
        }

        // 右端以外の場合
        // 前後の体重が異なる場所だけ最大値を更新する
        if(i < (N-1)){
            if(P[i].first != P[i+1].first){
                ans = max(ans,x);
            }
        // 右端の場合
        }else{
            ans = max(ans,x);
        }
    }

    cout << ans << endl;
    return 0;
}