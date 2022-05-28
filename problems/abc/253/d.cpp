/* 
1~Nの整数でAの倍数でもBの倍数でもないものの総和

入力例
10 3 5

出力例
22

*/

#include <bits/stdc++.h>
using namespace std;

// 1≦N≦10^9 はO(N)がTLEとなる(1秒間に10^8が限度)ので、
// 包除原理を使う
// 求める総和 =
// N以下の総和 - Aの倍数の総和 - Bの倍数の総和 + A,Bの最小公倍数の総和
// 等差数列の和の公式に帰着できる
// 項数 * (初項+末項) / 2

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
    long long n, a, b;
    cin >> n >> a >> b;

    long long sum = n*(n+1)/2;

    sum -= (n / a) * (a + a * (n / a))/2;

    sum -= (n / b) * (b + b * (n / b))/2;

    sum += (n / lcm(a,b)) * (lcm(a,b) + lcm(a,b) * (n / lcm(a,b)))/2;

    cout << sum << endl;
}