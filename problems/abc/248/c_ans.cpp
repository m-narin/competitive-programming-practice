#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

/* 
長さNの数列において、
各数字は1以上M以下で、和はk以下
のものは何通りあるか？
それを998244353で割った余りを出力

入力例
2 3 4

出力例
6

*/

// 方針DP(動的計画法)
// dp[i][j]:=数列の先頭から i 項まで決めた際に、
// 総和が j であるような数列の決め方の総数
// dp[N][1]+dp[N][2]+…+dp[N][K]

int main() {
	int n, m, K;
	cin >> n >> m >> K;
    // dp[n][k] = 累積和となる
	vector dp(n + 1, vector(K + 1, mint(0)));

	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < K; j++) {
			for(int k = 1; k <= m; k++) {
				if(j + k <= K) dp[i + 1][j + k] += dp[i][j];
			}
		}
	}
	mint res = 0;
	for(int i = 1; i <= K; i++) {
		res += dp.back()[i];
	}
	cout << res.val() << endl;
}