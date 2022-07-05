/* 
N行N列のマス目があり、上下左右繋がっているものとする。
あるマスから、上下左右斜めの8方向へ、N-1回移動するとき、
通った順番に左から並べた整数としてあり得るものの最大値を求めよ。

入力例
4
1161
1119
7111
1811

出力例
9786

*/


#include <bits/stdc++.h>
using namespace std;

int N;

int main() {

    cin >> N;

    vector<vector<long long>> A(N, vector<long long>(N)); 

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }

    long long ans = 0;

    // 方向
    vector<int> p={1,1,1,0,0,-1,-1,-1},q={1,0,-1,1,-1,1,0,-1};
    
    // 各マス始点
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for(int k = 0; k < 8; k++){
                long long now = 0;
                long long x=i, y=j;
                for(int l = 0; l < N; l++){
                    now = now * 10 + A[x][y];
                    x+=p[k];
                    y+=q[k];

                    // x,yが負の場合も考える
                    // 負の数のあまりは負で計算されてしまうので修正する
                    x = (x+N) % N;
                    y = (y+N) % N;

                }
                ans = max(ans,now);
            }

        }
    }

    cout << ans << endl;

    return 0;
}