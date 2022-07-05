/* 
N個のステージからなるゲームがある。
i番目のステージはAi分のストーリー映像と、Bi分のゲームプレイによって構成される。
初めてi番目のステージをクリアするには、ストーリー映像をゲームプレイ両方行う必要がある。
2回目以降はストーリー映像をスキップできる。
初め1番目のステージから始まり、順番にステージが解放される。
合計X回ステージをクリアするのに必要な時間の最小値を求めよ。
同じステージを複数回クリアするのも含む。

入力例
3 4
3 4
2 3
4 2

出力例
18

*/


#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

long long N,X;
long long A[1000009], B[1000009];

// 1番目から順に試していく。
// 1 ~ M (< X)番目のステージにおいて、MをX-i回プレイするものと考える。
int main() {

    cin >> N >> X;

    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    long long ans = INF, sum = 0LL;

    for(long long i = 1; i <= N; i++){
        if(i > X){
            break;
        }

        sum+=A[i]+B[i];
        ans = min(ans,sum + B[i] * (X-i));
    }
    
    cout << ans << endl;
    return 0;
}