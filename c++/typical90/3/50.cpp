/* 
N段の階段を上る。1歩で1段かL段上ることができる。
0段目から出発し、N段目にたどり着く方法は何通りか？
10^9+7で割った余りを求めよ。

入力例
3 2

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

// 漸化式を立て、DP
// i段目に到達するまでの移動方法をdp[i]とする
// dp[i] = 0 (i=0)
// dp[i] = dp[i-1] (1<=i<L)
// dp[i] = dp[i-1] + dp[i-L] (i>=L)

// 10^18超えるオーバーフローの可能性があるので、余りで計算しておく

int mod = 1000000007;
int N, L;
long long dp[1000009];

int main() {
    cin >> N >> L;
    dp[0] = 1;
    for (int i = 1; i <= N; i++){
        if(i<L){
            dp[i] = dp[i - 1];
        }else{
            dp[i] = (dp[i - 1] + dp[i - L]) % mod;
        }
    }

    cout << dp[N] << endl;
}