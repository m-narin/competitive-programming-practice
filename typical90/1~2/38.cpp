/* 
Aとbの最小公倍数を求める。
答えが10^18を超えたらLargeを出力

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


// 10^18を超えるオーバーフローに注意
// 10^18を超えない数字を使って、10^18未満である条件を導く

int main() {
    long long a,b, pow18 = 1000000000000000000LL;
    cin >> a >> b;

    long long r = b / gcd(a, b);

    // 10の18乗
    if(r > pow18 / a){
        cout << "Large" << endl;
    }else{
        cout << r*a << endl;
    }
}