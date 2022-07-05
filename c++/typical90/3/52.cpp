/* 
N面のサイコロ。得点は各サイコロの出目の総積。
その得点の総和を10^9+7で割った余りを求めよ。

入力例
2
1 2 3 5 7 11
4 6 8 9 10 12

出力例
1421

*/

// 因数分解

#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long N, A[109][8], Answer = 1;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= 6; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        Answer *= (A[i][1] + A[i][2] + A[i][3] + A[i][4] + A[i][5] + A[i][6]);
        Answer %= mod;
    }

    cout << Answer << endl;

    return 0;
}