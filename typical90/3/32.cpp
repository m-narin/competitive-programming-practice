/* 
駅伝。N人走り、各選手が各コースを走る時間が与えられる。
また、選手同士隣り合うことができない組み合わせも与えられる。
ゴールする最小値を出力。ゴールできない場合は、-1

入力例
3
1 10 100
10 1 100
100 10 1
1
1 2

出力例
111

*/

#include <bits/stdc++.h>
using namespace std;

// 小さい制約(10!)なので順列全探索
// 二次元配列の初期化は。変数に値を入れてから行う

int main() {

    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> p[i][j];
        };
    };

    vector<vector<bool>> x(n, vector<bool>(2, false));
    
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        x1--, x2--;
        x[x1][x2] = true;
        x[x2][x1] = true;
    };

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        v[i] = i;
    }   

    // v の要素が順列になる
    int min_time = 100000;
    do {

        // 険悪同士が隣り合わないかチェック
        bool if_adj = false;
        for(int i = 0; i < n-1; i++){
            if(x[v[i]][v[i+1]] == true){
                if_adj = true;
            }
        };

        // timeを計測
        int time = 0;
        if(!if_adj){
            for(int i = 0; i < n; i++){
                time += p[v[i]][i];
            }

            min_time = min(min_time, time);
        };

    } while(next_permutation(v.begin(), v.end()) );

    int ans;
    if(min_time == 100000){
        ans = -1;
    }else{
        ans = min_time;
    }

    cout << ans << endl;
}