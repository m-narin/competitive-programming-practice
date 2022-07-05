// DP問題
// 問題を部分問題の総和として考える
// dp[i]が決まっているときに、dp[i+1]を考える
// つまり、a[i]を選ぶか選ばないか
// 参考
// https://qiita.com/drken/items/a5e6fe22863b7992efdb
// https://o-treetree.hatenablog.com/entry/DPL1B

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 入力
int n, W;
int weight[110], value[110];

// DPテーブル
int dp[110][10010];

// O(N W)
int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) cin >> value[i] >> weight[i];

    // DP初期条件: dp[0][w] = 0
    for (int w = 0; w <= W; ++w) dp[0][w] = 0;

    // DPループ
    for (int i = 0; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // 追加する品物以下の内、重さ制限で最適に詰めたものに
            // 新たな品物を追加するか判断する
            if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
            else dp[i+1][w] = dp[i][w];
        }
    }

    cout << dp[n][W] << endl;
}