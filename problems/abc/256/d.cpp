/* 
L以上R未満からなる実数の集合を[L,R)とする。
N個の右半開区間が与えられる。
それらの和集合を最小の右半開区間の和集合で表せ。
[X,Y)のXの昇順で記述する。

入力例
3
10 20
20 30
40 50

出力例
10 30
40 50

*/


#include <bits/stdc++.h>
using namespace std;

int N;

int main() {

    cin >> N;
    vector<pair<int, int>> LR(N);

    int max_r = 0;
    for (int i = 0; i < N; i++){
        int l, r;
        cin >> l >> r;
        LR[i] = make_pair(l, r);
        max_r = max(max_r, r);
    }
    sort(LR.begin(), LR.end());

    int l_mae = LR[0].first;
    int r_mae = LR[0].second;

    for(int i = 0; i < N; i++){

        if(i < N-1){
            if(r_mae < LR[i+1].first){
                if(LR[i].second < LR[i+1].first){
                    cout << l_mae << " " << LR[i].second << endl;
                    l_mae = LR[i + 1].first;
                    r_mae = LR[i].second;
                }
            }
        }else if(i == N-1){
            cout << l_mae << " " << max_r  << endl;
        }

    }

    return 0;
}