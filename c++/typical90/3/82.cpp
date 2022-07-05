/* 
x = L,L+1,,,Rの順に黒板に整数xをx回書く
黒板に書かれている文字の個数を10^9+7で割った余を求めよ

入力例
3 5

出力例
12

*/


#include <bits/stdc++.h>
using namespace std;

// ACしない

// 10進数の桁数を求める
long long getDigits(long long N){
    long long count = 0;

    while(N > 0){
        /* 各桁の数字を取りたい時は、N%10 */
        N /= 10;
        count++;
    }
    return count;
}

long long L,R;
long long mod = 1000000007;

int main() {

    cin >> L >> R;

    long long ans = 0;
    for(long long x = L; x <= R; x++){
        ans += (getDigits(x)* x) % mod;
    }

    ans %= mod;

    cout << ans << endl;
    return 0;
}