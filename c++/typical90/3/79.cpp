/* 
H x Wの2次元配列Aが与えられる。
(x,y)(x+1,y)(x,y+1)(x+1,y+1)の値を+-1する操作を自由に行う。
これをBに一致させることができるか？
可能なら操作の最小回数も答えよ。

入力例
3 3
0 0 0
0 0 0
0 0 0
1 1 0
1 1 0
0 0 0

出力例
Yes
1

*/


#include <bits/stdc++.h>
using namespace std;

int printDimentionalElements(vector<vector<int>> v, int H, int W){
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
};

int H,W;

// 最大10^5 x 10^5で10^10の値になる可能性があるのでlong long型で定義する
long long ans = 0;

int main() {

    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));

    for (int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B[i][j];
        }
    }

    // 操作順序によらない、計算量が小さめなので、
    // 左上から一致するように値を更新していく

    for (int i = 0; i < H-1; i++){
        for (int j = 0; j < W-1; j++){
            int d = B[i][j] - A[i][j];
            A[i][j] += d;
            A[i][j+1] += d;
            A[i+1][j] += d;
            A[i+1][j+1] += d;
            ans += abs(d);
        }
    }

    // printElements(A,H,W);
    // printElements(B,H,W);

    // 同値比較する際は、二つの配列に余分なものを入れないようにする
    if(A == B){
        cout << "Yes" << endl;
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}