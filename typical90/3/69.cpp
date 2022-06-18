/* 
N個のブロックが一列に並んでいる。K種類の色でそれぞれ塗る。
2個となりのブロックは異なる色で塗るときの塗り方は何通りあるか？
答えを10^9+7で割った余りを求めよ。


入力例
2 3

出力例
6

*/

// 繰り返し二乗法を使うと、計算量をO(logn)で実行できる

#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long mod = 1000000007;

long long binpower(long long a, long long b){
    long long ans = 1;
    while(b!=0){
        if(b % 2 == 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int main() {
    cin >> N >> K;

    if(K==1){
        cout << (N == 1 ? 1 : 0) << endl;
    }else if(N==1){
        cout << K % mod << endl;
    }else if(N==2){
        cout << K * (K - 1) % mod << endl;
    }else{
        cout << K * (K - 1) % mod * binpower(K - 2, N - 2) % mod << endl;
    }

    return 0;
}