/* 
AxBxCの直方体のケーキがある。面と平行に切断し、
全てのピースを立方体にするには最小何回切る必要があるか？

入力例
2 2 3

出力例
4
*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// r x r x rの立方体が出来る条件は、各辺がrで割り切れること
// 切る回数の最小回数 = 最も大きいr = rは最大公約数
// ユークリッドの互除法を使う

// 10^18なので、オーバーロードに注意
long long gcd(long long a, long long b){
    if( b==0 ) return a;
    return gcd(b, a % b);
}

int main() {

    // a,b,cは10^18まで
    // long long は64bit ≒ 1.8 x 10^19まで表現できる 
    long long a,b,c;
    cin >> a >> b >> c;
    long long ans;
    long long r;

    r = gcd(a, gcd(b, c));
    ans = (a / r - 1) + (b / r - 1) + (c / r - 1);
    cout << ans << endl;
    
}