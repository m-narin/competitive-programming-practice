/* 
A円硬貨、B円硬貨、C円硬貨をそれぞれ0枚以上使ってちょうどN円はらう
使う硬貨の枚数の最小値を求める

入力例
227
21 47 56

出力例
5

*/

#include <bits/stdc++.h>
using namespace std;

// 工夫して全探索
// N=9999なので、2重ループまでOK
// A*i等が(10^9 * 10^4)で10^9超えるのでlong long型に統一

int main() {

    long long N,A,B,C,L;
	cin >> N >> A >> B >> C;
    L = 9999;

    long long ans = 10000;

    // for文もlong long型で統一できると便利
    // int i = 0でやると、各係数に1LLをかける必要が出てくる
    for (long long i = 0; i <= L; i++){
        for (long long j = 0; j <= L-i; j++){

            long long V = N - i * A - j * B;
			long long R = i + j + V / C;

            // 以下は除く
            // CでちょうどNにできない場合
            // 残り金額が0より小さい場合
            if (V % C != 0 || V < 0) continue;
			ans = min(ans, R);
        }
        
    }

    cout << ans << endl;
}