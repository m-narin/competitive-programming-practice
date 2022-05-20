/* 
長さNの数列において、
各数字は1以上M以下で、和はk以下
のものは何通りあるか？
それを998244353で割った余りを出力

入力例
2 3 4

出力例
6

*/

#include <bits/stdc++.h>
#include <functional>
using namespace std;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}


int main() {

    int n, m, k;
    cin >> n >> m >> k;

    // m以下の数字からn個選ぶ。mCn
    // 和がk以下のものの順列の個数を加算
    // しかし実行時間overに
    long long count = 0;

    foreach_comb(m, n, [&](int *indexes){

        long long sum = 0;
        for (int i = 0; i < n; i++){
            sum += indexes[i];
        }

        if(sum <= k){
            long long perm = 1;
            for(int i=1;i<=n;i++){
                perm = perm * i;
            }
            count += perm;
        }
        
    });

    long long ans = count % 998244353;

    cout << ans << endl;
}