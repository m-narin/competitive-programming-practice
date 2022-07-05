/* 
AとBの最大公約数と最小公倍数を求める

入力例
12 18

出力例
6 36

*/

#include <bits/stdc++.h>
using namespace std;

// 最大公約数を返す関数
// ユークリッドの互除法
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// 最小公倍数を返す関数
long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}

int main() {
    long long A,B;
    cin >> A >> B;

    cout << gcd(A, B) << " " << lcm(A, B) << endl;
}